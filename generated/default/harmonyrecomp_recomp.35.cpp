#include "harmonyrecomp_funcs.35.h"

DEFINE_REX_FUNC(sub_82213AF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82213AF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x82213210
	ctx.lr = 0x82213B04;
	sub_82213210(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r29,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// bge cr6,0x82213c00
	if (!ctx.cr6.lt) goto loc_82213C00;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r5,136
	ctx.r5.s64 = 136;
	// stb r30,66(r3)
	REX_STORE_U8(ctx.r3.u32 + 66, ctx.r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,19492
	ctx.r3.s64 = ctx.r3.s64 + 19492;
	// stb r30,19278(r31)
	REX_STORE_U8(ctx.r31.u32 + 19278, ctx.r30.u8);
	// stb r30,19279(r31)
	REX_STORE_U8(ctx.r31.u32 + 19279, ctx.r30.u8);
	// stb r30,4039(r31)
	REX_STORE_U8(ctx.r31.u32 + 4039, ctx.r30.u8);
	// bl 0x8273a590
	ctx.lr = 0x82213B38;
	sub_8273A590(ctx, base);
	// li r5,136
	ctx.r5.s64 = 136;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,19628
	ctx.r3.s64 = ctx.r31.s64 + 19628;
	// bl 0x8273a590
	ctx.lr = 0x82213B48;
	sub_8273A590(ctx, base);
	// stw r30,19764(r31)
	REX_STORE_U32(ctx.r31.u32 + 19764, ctx.r30.u32);
	// stw r30,19768(r31)
	REX_STORE_U32(ctx.r31.u32 + 19768, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,19772(r31)
	REX_STORE_U32(ctx.r31.u32 + 19772, ctx.r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82639c90
	ctx.lr = 0x82213B64;
	sub_82639C90(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82213b90
	if (!ctx.cr0.eq) goto loc_82213B90;
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// ld r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// ld r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// ld r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r10.u32 + 8);
	// std r9,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r9.u64);
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// std r10,24(r31)
	REX_STORE_U64(ctx.r31.u32 + 24, ctx.r10.u64);
	// b 0x82213ba4
	goto loc_82213BA4;
loc_82213B90:
	// std r30,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r30.u64);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x82639688
	ctx.lr = 0x82213BA4;
	sub_82639688(ctx, base);
loc_82213BA4:
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82639c90
	ctx.lr = 0x82213BB4;
	sub_82639C90(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82213be0
	if (!ctx.cr0.eq) goto loc_82213BE0;
	// addi r10,r1,152
	ctx.r10.s64 = ctx.r1.s64 + 152;
	// ld r9,128(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// addi r11,r31,40
	ctx.r11.s64 = ctx.r31.s64 + 40;
	// ld r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// ld r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r10.u32 + 8);
	// std r9,32(r31)
	REX_STORE_U64(ctx.r31.u32 + 32, ctx.r9.u64);
	// std r11,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r11.u64);
	// std r10,48(r31)
	REX_STORE_U64(ctx.r31.u32 + 48, ctx.r10.u64);
	// b 0x82213bf4
	goto loc_82213BF4;
loc_82213BE0:
	// std r30,32(r31)
	REX_STORE_U64(ctx.r31.u32 + 32, ctx.r30.u64);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// bl 0x82639688
	ctx.lr = 0x82213BF4;
	sub_82639688(ctx, base);
loc_82213BF4:
	// stw r30,19776(r31)
	REX_STORE_U32(ctx.r31.u32 + 19776, ctx.r30.u32);
	// stb r30,19281(r31)
	REX_STORE_U8(ctx.r31.u32 + 19281, ctx.r30.u8);
	// stb r30,19278(r31)
	REX_STORE_U8(ctx.r31.u32 + 19278, ctx.r30.u8);
loc_82213C00:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82221F90) {
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
	// lbz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 140);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82221fcc
	if (ctx.cr0.eq) goto loc_82221FCC;
	// bl 0x82224700
	ctx.lr = 0x82221FB4;
	sub_82224700(ctx, base);
	// lwz r9,144(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// subfc r11,r11,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// subfze r11,r10
	temp.u8 = ~ctx.r10.u32 + ctx.xer.ca < ~ctx.r10.u32;
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,141(r31)
	REX_STORE_U8(ctx.r31.u32 + 141, ctx.r11.u8);
loc_82221FCC:
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

DEFINE_REX_FUNC(sub_82223AD0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// stw r4,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r4.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r4,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r4.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82224700) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82224708;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,93(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 93);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822247cc
	if (!ctx.cr0.eq) goto loc_822247CC;
	// lwz r11,100(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// addi r30,r3,100
	ctx.r30.s64 = ctx.r3.s64 + 100;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82224734;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8222474c
	if (ctx.cr0.eq) goto loc_8222474C;
	// lbz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 124);
	// li r29,1
	ctx.r29.s64 = 1;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82224750
	if (!ctx.cr0.eq) goto loc_82224750;
loc_8222474C:
	// li r29,0
	ctx.r29.s64 = 0;
loc_82224750:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82224770
	if (ctx.cr6.eq) goto loc_82224770;
	// lwz r4,60(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82224770
	if (ctx.cr6.eq) goto loc_82224770;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822240f8
	ctx.lr = 0x82224770;
	sub_822240F8(ctx, base);
loc_82224770:
	// lbz r11,93(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 93);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82224790
	if (!ctx.cr0.eq) goto loc_82224790;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82224790;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82224790:
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822247cc
	if (ctx.cr0.eq) goto loc_822247CC;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x822247cc
	if (!ctx.cr6.gt) goto loc_822247CC;
	// addi r5,r31,16
	ctx.r5.s64 = ctx.r31.s64 + 16;
	// lhz r9,88(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 88);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f1,40(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f1.f64 = double(temp.f32);
	// lbz r7,90(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 90);
	// lwz r6,84(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lhz r4,96(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 96);
	// bl 0x822244b0
	ctx.lr = 0x822247CC;
	sub_822244B0(ctx, base);
loc_822247CC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8222C8C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8222C8C8;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r23,r8
	ctx.r23.u64 = ctx.r8.u64;
	// mr r27,r9
	ctx.r27.u64 = ctx.r9.u64;
	// li r25,1
	ctx.r25.s64 = 1;
	// cmplwi cr6,r6,10
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 10, ctx.xer);
	// bgt cr6,0x8222c928
	if (ctx.cr6.gt) goto loc_8222C928;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-6096
	ctx.r12.s64 = ctx.r12.s64 + -6096;
	// lbzx r0,r12,r24
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r24.u32);
	// lis r12,-32221
	ctx.r12.s64 = -2111635456;
	// nop 
	// addi r12,r12,-14048
	ctx.r12.s64 = ctx.r12.s64 + -14048;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r24.u32) {
	case 0:
		goto loc_8222C928;
	case 1:
		goto loc_8222C920;
	case 2:
		goto loc_8222C928;
	case 3:
		goto loc_8222C928;
	case 4:
		goto loc_8222C920;
	case 5:
		goto loc_8222C928;
	case 6:
		goto loc_8222C920;
	case 7:
		goto loc_8222C928;
	case 8:
		goto loc_8222C928;
	case 9:
		goto loc_8222C920;
	case 10:
		goto loc_8222C928;
	case 11:
		goto loc_8222C920;
	case 12:
		goto loc_8222C920;
	case 13:
		goto loc_8222C920;
	case 14:
		goto loc_8222C920;
	case 15:
		goto loc_8222C920;
	case 16:
		goto loc_8222C920;
	case 17:
		goto loc_8222C924;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8222C920:
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
loc_8222C924:
	// b 0x8222c92c
	goto loc_8222C92C;
loc_8222C928:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8222C92C:
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x8222C938;
	sub_825F8D38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8222c970
	if (ctx.cr0.eq) goto loc_8222C970;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b88
	ctx.lr = 0x8222C948;
	sub_825F8B88(ctx, base);
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// li r10,448
	ctx.r10.s64 = 448;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// and r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 & ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x8222C96C;
	sub_825F8BF8(ctx, base);
	// b 0x8222c974
	goto loc_8222C974;
loc_8222C970:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8222C974:
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// clrlwi. r30,r30,24
	ctx.r30.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// beq 0x8222c990
	if (ctx.cr0.eq) goto loc_8222C990;
	// rlwinm r11,r11,0,26,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFE3F;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
loc_8222C990:
	// stfs f31,412(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// beq cr6,0x8222c9f8
	if (ctx.cr6.eq) goto loc_8222C9F8;
	// lwz r3,-27096(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -27096);
	// bl 0x8245a220
	ctx.lr = 0x8222C9A8;
	sub_8245A220(ctx, base);
	// clrlwi. r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r3,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// beq 0x8222c9ec
	if (ctx.cr0.eq) goto loc_8222C9EC;
	// lwz r3,4(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x825fa250
	ctx.lr = 0x8222C9BC;
	sub_825FA250(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8222c9ec
	if (ctx.cr0.eq) goto loc_8222C9EC;
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
	ctx.lr = 0x8222C9EC;
	sub_825F9CF8(ctx, base);
loc_8222C9EC:
	// stw r26,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r26.u32);
	// stb r25,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r25.u8);
	// b 0x8222ca10
	goto loc_8222CA10;
loc_8222C9F8:
	// addi r11,r11,-27096
	ctx.r11.s64 = ctx.r11.s64 + -27096;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8245a220
	ctx.lr = 0x8222CA04;
	sub_8245A220(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// stb r11,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r11.u8);
loc_8222CA10:
	// vspltisw v12,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,408(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// vupkd3d128 v59,v12,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v12.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v12.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v59 = vTemp;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// cmplwi cr6,r24,7
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 7, ctx.xer);
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// stw r10,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r10.u32);
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// lwz r10,3596(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 3596);
	// vpermwi128 v60,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// lfs f12,-232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f12.f64 = double(temp.f32);
	// stw r10,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r10.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8222ca88
	if (ctx.cr6.lt) goto loc_8222CA88;
	// cmplwi cr6,r24,10
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 10, ctx.xer);
	// bgt cr6,0x8222ca88
	if (ctx.cr6.gt) goto loc_8222CA88;
	// lfs f0,0(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8222cbf0
	goto loc_8222CBF0;
loc_8222CA88:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r10,-12872(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12872);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8222caa0
	if (ctx.cr6.eq) goto loc_8222CAA0;
	// lfs f0,664(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 664);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8222caa4
	goto loc_8222CAA4;
loc_8222CAA0:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
loc_8222CAA4:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// vor128 v58,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// fdivs f13,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// li r8,-232
	ctx.r8.s64 = -232;
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// li r7,4
	ctx.r7.s64 = 4;
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vor128 v0,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v58.u8));
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// lwz r10,-15432(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -15432);
	// vspltw128 v54,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vspltw128 v6,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// rlwinm r6,r10,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r10,-15444(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + -15444);
	// lvlx128 v53,r11,r8
	temp.u32 = ctx.r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v4,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// vrlimi128 v53,v58,7,0
	simde_mm_store_ps(ctx.v53.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v53.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v58.f32), 228), 7));
	// lvlx128 v58,r11,r7
	temp.u32 = ctx.r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v2,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// vmulfp128 v5,v57,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v53.f32)));
	// vrlimi128 v0,v58,4,3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v58.f32), 57), 4));
	// vmulfp128 v3,v56,v53
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v53.f32)));
	// vspltw128 v31,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// vmulfp128 v1,v55,v53
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v53.f32)));
	// vrlimi128 v12,v58,2,2
	simde_mm_store_ps(ctx.v12.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v58.f32), 78), 2));
	// vmulfp128 v30,v54,v53
	simde_mm_store_ps(ctx.v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v53.f32)));
	// vspltw128 v29,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vspltw128 v28,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// fcfid f0,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(ctx.f0.s64);
	// vmaddfp v6,v6,v0,v5
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vspltw128 v27,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// vmaddfp v5,v4,v0,v3
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vspltw128 v7,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vmaddfp v4,v2,v0,v1
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vpermwi128 v13,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// vmaddfp v0,v31,v0,v30
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// fcfid f11,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(ctx.f11.s64);
	// vspltw128 v8,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// frsp f10,f0
	ctx.f10.f64 = double(float(ctx.f0.f64));
	// vspltw128 v9,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// vspltw128 v10,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vor128 v63,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vspltw128 v11,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vor128 v62,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vor128 v61,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vor128 v60,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// vmaddfp v6,v29,v12,v6
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v5,v28,v12,v5
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// frsp f11,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// vmaddfp v4,v27,v12,v4
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v0,v7,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// fmuls f0,f11,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// vmaddcfp128 v63,v8,v63,v6
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v63.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// fmuls f13,f10,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// vmaddcfp128 v62,v9,v62,v5
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v62.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddcfp128 v61,v10,v61,v4
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v61.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddcfp128 v60,v11,v60,v0
	simde_mm_store_ps(ctx.v60.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v60.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8222cbdc
	if (ctx.cr6.eq) goto loc_8222CBDC;
	// fdivs f0,f0,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fmr f13,f12
	ctx.f13.f64 = ctx.f12.f64;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// b 0x8222cbf0
	goto loc_8222CBF0;
loc_8222CBDC:
	// lfs f11,4(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f11,0(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
loc_8222CBF0:
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vspltw128 v54,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vmulfp128 v29,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vpermwi128 v0,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vmulfp128 v31,v56,v58
	simde_mm_store_ps(ctx.v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v28,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmulfp128 v2,v55,v58
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v30,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vmulfp128 v4,v54,v58
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v1,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vspltw128 v3,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// stfs f12,92(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vpermwi128 v13,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// vspltw128 v5,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// vspltw128 v6,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// vspltw128 v7,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// vspltw128 v8,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// vspltw128 v9,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// li r5,64
	ctx.r5.s64 = 64;
	// vspltw128 v10,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// vmaddfp v29,v28,v0,v29
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vspltw128 v11,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vmaddfp v31,v30,v0,v31
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vspltw128 v12,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v2,v1,v0,v2
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v4,v3,v0,v4
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v5,v5,v13,v29
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v6,v6,v13,v31
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v7,v7,v13,v2
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v8,v8,v13,v4
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v9,v9,v0,v5
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v10,v10,v0,v6
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v9,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v13,v11,v0,v7
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v0,v12,v0,v8
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
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
	ctx.lr = 0x8222CCC8;
	sub_8273A030(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82459d08
	ctx.lr = 0x8222CCD8;
	sub_82459D08(ctx, base);
	// lwz r3,424(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8226FC40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8226FC48;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 65536;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r31,r31,-2228
	ctx.r31.s64 = ctx.r31.s64 + -2228;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r27,-1
	ctx.r27.s64 = -1;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8226fcd0
	if (ctx.cr6.eq) goto loc_8226FCD0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x824443c8
	ctx.lr = 0x8226FC74;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8226fc98
	if (ctx.cr0.eq) goto loc_8226FC98;
	// lbz r11,2364(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2364);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8226fc98
	if (ctx.cr0.eq) goto loc_8226FC98;
	// stb r30,2364(r3)
	REX_STORE_U8(ctx.r3.u32 + 2364, ctx.r30.u8);
	// stw r30,2368(r3)
	REX_STORE_U32(ctx.r3.u32 + 2368, ctx.r30.u32);
	// stw r30,2372(r3)
	REX_STORE_U32(ctx.r3.u32 + 2372, ctx.r30.u32);
	// stb r30,2704(r3)
	REX_STORE_U8(ctx.r3.u32 + 2704, ctx.r30.u8);
loc_8226FC98:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8226fcbc
	if (ctx.cr6.eq) goto loc_8226FCBC;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x8226FCB4;
	sub_82222BB0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r27,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r27.u32);
loc_8226FCBC:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8226fccc
	if (ctx.cr6.eq) goto loc_8226FCCC;
	// bl 0x825e0378
	ctx.lr = 0x8226FCCC;
	sub_825E0378(ctx, base);
loc_8226FCCC:
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
loc_8226FCD0:
	// addis r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 65536;
	// addi r31,r31,-2224
	ctx.r31.s64 = ctx.r31.s64 + -2224;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8226fcfc
	if (ctx.cr6.eq) goto loc_8226FCFC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226FCF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
loc_8226FCFC:
	// addis r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 65536;
	// addi r28,r28,-2232
	ctx.r28.s64 = ctx.r28.s64 + -2232;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8226fdb0
	if (ctx.cr6.eq) goto loc_8226FDB0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8226fdb0
	if (ctx.cr0.eq) goto loc_8226FDB0;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_8226FD1C:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8226fda8
	if (ctx.cr6.eq) goto loc_8226FDA8;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,63300
	ctx.r11.u64 = ctx.r11.u64 | 63300;
	// lwzx r11,r29,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r31,8(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8226fda8
	if (ctx.cr6.eq) goto loc_8226FDA8;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8226fd60
	if (ctx.cr6.eq) goto loc_8226FD60;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x8226FD5C;
	sub_82222BB0(ctx, base);
	// stw r27,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
loc_8226FD60:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8226FD68;
	sub_825E0378(ctx, base);
	// addis r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 65536;
	// addi r31,r31,-2240
	ctx.r31.s64 = ctx.r31.s64 + -2240;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8226fda8
	if (ctx.cr6.eq) goto loc_8226FDA8;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bl 0x825e0378
	ctx.lr = 0x8226FD9C;
	sub_825E0378(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_8226FDA8:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8226fd1c
	if (!ctx.cr0.eq) goto loc_8226FD1C;
loc_8226FDB0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8227C2D8) {
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
	// lis r4,1
	ctx.r4.s64 = 65536;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,464
	ctx.r4.u64 = ctx.r4.u64 | 464;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8227C300;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8227c310
	if (ctx.cr0.eq) goto loc_8227C310;
	// bl 0x8227bc08
	ctx.lr = 0x8227C30C;
	sub_8227BC08(ctx, base);
	// b 0x8227c314
	goto loc_8227C314;
loc_8227C310:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8227C314:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8227D9B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8227D9B8;
	__savegprlr_24(ctx, base);
	// stfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f29.u64);
	// stfd f30,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r27,r3,1
	ctx.r27.s64 = ctx.r3.s64 + 65536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r27,r27,-3048
	ctx.r27.s64 = ctx.r27.s64 + -3048;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8227e140
	if (ctx.cr6.eq) goto loc_8227E140;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8227e140
	if (!ctx.cr6.eq) goto loc_8227E140;
	// bl 0x82232628
	ctx.lr = 0x8227D9F0;
	sub_82232628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8227e140
	if (!ctx.cr0.eq) goto loc_8227E140;
	// addis r24,r30,1
	ctx.r24.s64 = ctx.r30.s64 + 65536;
	// addi r24,r24,-3044
	ctx.r24.s64 = ctx.r24.s64 + -3044;
	// lbz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8227db18
	if (ctx.cr0.eq) goto loc_8227DB18;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,88(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 88);
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
	// addi r31,r1,96
	ctx.r31.s64 = ctx.r1.s64 + 96;
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
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r29,r1,112
	ctx.r29.s64 = ctx.r1.s64 + 112;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
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
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
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
	// lfs f12,92(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
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
	ctx.lr = 0x8227DB04;
	sub_823BA820(ctx, base);
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8227db18
	if (!ctx.cr6.eq) goto loc_8227DB18;
	// bl 0x823bb888
	ctx.lr = 0x8227DB18;
	sub_823BB888(ctx, base);
loc_8227DB18:
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8227db38
	if (!ctx.cr6.eq) goto loc_8227DB38;
	// lbz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 20);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8227db38
	if (ctx.cr0.eq) goto loc_8227DB38;
	// bl 0x823bba60
	ctx.lr = 0x8227DB38;
	sub_823BBA60(ctx, base);
loc_8227DB38:
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
	// beq 0x8227db90
	if (ctx.cr0.eq) goto loc_8227DB90;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8227DB58:
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DB70;
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
	// blt cr6,0x8227db58
	if (ctx.cr6.lt) goto loc_8227DB58;
loc_8227DB90:
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// li r29,4
	ctx.r29.s64 = 4;
	// addi r31,r31,-2320
	ctx.r31.s64 = ctx.r31.s64 + -2320;
loc_8227DB9C:
	// lbz r11,-8(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + -8);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8227dc24
	if (ctx.cr0.eq) goto loc_8227DC24;
	// lbz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// li r4,39
	ctx.r4.s64 = 39;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bne 0x8227dbd0
	if (!ctx.cr0.eq) goto loc_8227DBD0;
	// li r4,37
	ctx.r4.s64 = 37;
loc_8227DBD0:
	// bctrl 
	ctx.lr = 0x8227DBD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DBF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// addi r4,r31,-32
	ctx.r4.s64 = ctx.r31.s64 + -32;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DC0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DC24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227DC24:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,40
	ctx.r31.s64 = ctx.r31.s64 + 40;
	// bne 0x8227db9c
	if (!ctx.cr0.eq) goto loc_8227DB9C;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,63172
	ctx.r11.u64 = ctx.r11.u64 | 63172;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8227dc98
	if (ctx.cr0.eq) goto loc_8227DC98;
	// lwz r10,248(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r4,r11,60
	ctx.r4.s64 = ctx.r11.s64 + 60;
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DC64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r4,r11,60
	ctx.r4.s64 = ctx.r11.s64 + 60;
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DC84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,160(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DC98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227DC98:
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r31,r31,-3028
	ctx.r31.s64 = ctx.r31.s64 + -3028;
	// addi r25,r11,-30128
	ctx.r25.s64 = ctx.r11.s64 + -30128;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8227dff0
	if (ctx.cr6.eq) goto loc_8227DFF0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DCC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8227dff0
	if (!ctx.cr0.eq) goto loc_8227DFF0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// ori r10,r10,62372
	ctx.r10.u64 = ctx.r10.u64 | 62372;
	// addi r11,r11,14376
	ctx.r11.s64 = ctx.r11.s64 + 14376;
	// lwzx r10,r30,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// lfs f30,-1908(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1908);
	ctx.f30.f64 = double(temp.f32);
	// cmplwi cr6,r10,10
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 10, ctx.xer);
	// bne cr6,0x8227de7c
	if (!ctx.cr6.eq) goto loc_8227DE7C;
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r27,0
	ctx.r27.s64 = 0;
	// fmr f31,f30
	ctx.f31.f64 = ctx.f30.f64;
	// lwz r11,204(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 204);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,24504(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24504);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// lwz r10,120(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 120);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lfs f12,96(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f1,f0,f13,f12
	ctx.f1.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
	// bctrl 
	ctx.lr = 0x8227DD30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r29,r30,1
	ctx.r29.s64 = ctx.r30.s64 + 65536;
	// li r28,16
	ctx.r28.s64 = 16;
	// addi r29,r29,-2160
	ctx.r29.s64 = ctx.r29.s64 + -2160;
loc_8227DD3C:
	// lbz r11,-12(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -12);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8227de50
	if (ctx.cr0.eq) goto loc_8227DE50;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r27,1
	ctx.r27.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DD60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8227dd80
	if (!ctx.cr0.eq) goto loc_8227DD80;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DD80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227DD80:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DD94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,6(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 6);
	// lfs f0,21484(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 21484);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// fmadds f0,f13,f0,f1
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f1.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x8227DDD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DDEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r29,-24
	ctx.r4.s64 = ctx.r29.s64 + -24;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DE04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f1,12(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DE1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DE30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DE48;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,21484(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 21484);
	ctx.f0.f64 = double(temp.f32);
	// fadds f31,f31,f0
	ctx.f31.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
loc_8227DE50:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,52
	ctx.r29.s64 = ctx.r29.s64 + 52;
	// bne 0x8227dd3c
	if (!ctx.cr0.eq) goto loc_8227DD3C;
	// clrlwi. r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8227de7c
	if (!ctx.cr0.eq) goto loc_8227DE7C;
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
	ctx.lr = 0x8227DE7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227DE7C:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f30.f64;
	// addis r29,r30,1
	ctx.r29.s64 = ctx.r30.s64 + 65536;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r29,r29,-1320
	ctx.r29.s64 = ctx.r29.s64 + -1320;
	// li r28,32
	ctx.r28.s64 = 32;
	// lfs f30,-30652(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30652);
	ctx.f30.f64 = double(temp.f32);
	// lis r26,-32112
	ctx.r26.s64 = -2104492032;
loc_8227DE9C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f1,-5140(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -5140);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DEB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,-12(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + -12);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8227dfc4
	if (ctx.cr0.eq) goto loc_8227DFC4;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r27,1
	ctx.r27.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DED8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8227def8
	if (!ctx.cr0.eq) goto loc_8227DEF8;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DEF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227DEF8:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DF0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,6(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 6);
	// lfs f0,21484(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 21484);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// fmadds f0,f13,f0,f1
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f1.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x8227DF48;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DF64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r29,-40
	ctx.r4.s64 = ctx.r29.s64 + -40;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DF7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f1,-24(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -24);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DF94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DFA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227DFC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fadds f31,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f31.f64 + ctx.f30.f64));
loc_8227DFC4:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,48
	ctx.r29.s64 = ctx.r29.s64 + 48;
	// bne 0x8227de9c
	if (!ctx.cr0.eq) goto loc_8227DE9C;
	// clrlwi. r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8227dff0
	if (!ctx.cr0.eq) goto loc_8227DFF0;
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
	ctx.lr = 0x8227DFF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227DFF0:
	// addis r29,r30,1
	ctx.r29.s64 = ctx.r30.s64 + 65536;
	// addi r29,r29,-3024
	ctx.r29.s64 = ctx.r29.s64 + -3024;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8227e140
	if (ctx.cr6.eq) goto loc_8227E140;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227E018;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8227e140
	if (!ctx.cr0.eq) goto loc_8227E140;
	// lbz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8227e140
	if (ctx.cr0.eq) goto loc_8227E140;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62402
	ctx.r11.u64 = ctx.r11.u64 | 62402;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8227e140
	if (ctx.cr0.eq) goto loc_8227E140;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227E054;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8227e140
	if (ctx.cr0.eq) goto loc_8227E140;
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// lfs f31,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r31,r31,192
	ctx.r31.s64 = ctx.r31.s64 + 192;
	// li r30,4
	ctx.r30.s64 = 4;
loc_8227E070:
	// lbz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 4);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8227e114
	if (ctx.cr0.eq) goto loc_8227E114;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r28,1
	ctx.r28.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227E094;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8227e0b4
	if (!ctx.cr0.eq) goto loc_8227E0B4;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227E0B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227E0B4:
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227E0D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r4,r31,-16
	ctx.r4.s64 = ctx.r31.s64 + -16;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227E0E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227E100;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227E114;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227E114:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,28
	ctx.r31.s64 = ctx.r31.s64 + 28;
	// bne 0x8227e070
	if (!ctx.cr0.eq) goto loc_8227E070;
	// clrlwi. r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8227e140
	if (!ctx.cr0.eq) goto loc_8227E140;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227E140;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8227E140:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
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

DEFINE_REX_FUNC(sub_822C0188) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x822C0190;
	__savegprlr_28(ctx, base);
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x822c03c0
	if (ctx.cr6.eq) goto loc_822C03C0;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x822c0678
	if (!ctx.cr6.eq) goto loc_822C0678;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,-3107
	ctx.r11.s64 = ctx.r11.s64 + -3107;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x822c0678
	if (ctx.cr0.eq) goto loc_822C0678;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C01F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// bne 0x822c0208
	if (!ctx.cr0.eq) goto loc_822C0208;
	// lfs f30,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// b 0x822c020c
	goto loc_822C020C;
loc_822C0208:
	// lfs f30,-232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f30.f64 = double(temp.f32);
loc_822C020C:
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// addi r10,r10,32720
	ctx.r10.s64 = ctx.r10.s64 + 32720;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x822C025C;
	sub_8222FF78(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
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
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32226
	ctx.r6.s64 = -2111963136;
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r6,r6,-4080
	ctx.r6.s64 = ctx.r6.s64 + -4080;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,2496(r6)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r6.u32 + 2496);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x82738be0
	ctx.lr = 0x822C0310;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x822C032C;
	sub_82738CC0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r31,r11,22072
	ctx.r31.s64 = ctx.r11.s64 + 22072;
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_822C037C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// li r4,348
	ctx.r4.s64 = 348;
	// bl 0x825e02a0
	ctx.lr = 0x822C038C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822c03b0
	if (ctx.cr0.eq) goto loc_822C03B0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,4(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// bl 0x824bac30
	ctx.lr = 0x822C03B0;
	sub_824BAC30(ctx, base);
loc_822C03B0:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 3, ctx.xer);
	// blt cr6,0x822c037c
	if (ctx.cr6.lt) goto loc_822C037C;
	// b 0x822c0678
	goto loc_822C0678;
loc_822C03C0:
	// addis r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 65536;
	// addi r11,r11,-3106
	ctx.r11.s64 = ctx.r11.s64 + -3106;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x822c0678
	if (ctx.cr0.eq) goto loc_822C0678;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,264(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 264);
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C03F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r28,r11,12468
	ctx.r28.s64 = ctx.r11.s64 + 12468;
	// bne 0x822c040c
	if (!ctx.cr0.eq) goto loc_822C040C;
	// lfs f30,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// b 0x822c0410
	goto loc_822C0410;
loc_822C040C:
	// lfs f30,-232(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -232);
	ctx.f30.f64 = double(temp.f32);
loc_822C0410:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x8222ff78
	ctx.lr = 0x822C0424;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x822C0440;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r3,65
	ctx.r3.s64 = 65;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82240a58
	ctx.lr = 0x822C0468;
	sub_82240A58(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r9,r9,-32688
	ctx.r9.s64 = ctx.r9.s64 + -32688;
	// lfs f0,4436(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4436);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// fmuls f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x822C04BC;
	sub_8222FF78(ctx, base);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lfs f12,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,172(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lfs f11,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r7,-4080
	ctx.r7.s64 = ctx.r7.s64 + -4080;
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfd f31,2504(r7)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r7.u32 + 2504);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// bl 0x82738be0
	ctx.lr = 0x822C0568;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x822C0584;
	sub_82738CC0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r7,22072
	ctx.r10.s64 = ctx.r7.s64 + 22072;
	// li r4,336
	ctx.r4.s64 = 336;
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lwz r3,44(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x822C05E4;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x822c0658
	if (ctx.cr0.eq) goto loc_822C0658;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r5,4(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,4096
	ctx.r4.s64 = ctx.r11.s64 + 4096;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824689b0
	ctx.lr = 0x822C0604;
	sub_824689B0(ctx, base);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stw r30,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r30.u32);
	// addi r8,r11,-18008
	ctx.r8.s64 = ctx.r11.s64 + -18008;
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stw r30,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r30.u32);
	// stfs f0,320(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// std r10,288(r31)
	REX_STORE_U64(ctx.r31.u32 + 288, ctx.r10.u64);
	// std r9,296(r31)
	REX_STORE_U64(ctx.r31.u32 + 296, ctx.r9.u64);
	// stb r30,324(r31)
	REX_STORE_U8(ctx.r31.u32 + 324, ctx.r30.u8);
	// stw r30,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r30.u32);
	// stb r30,332(r31)
	REX_STORE_U8(ctx.r31.u32 + 332, ctx.r30.u8);
	// std r10,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r10.u64);
	// b 0x822c065c
	goto loc_822C065C;
loc_822C0658:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_822C065C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822c0678
	if (ctx.cr6.eq) goto loc_822C0678;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,168(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,196(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 196, temp.u32);
	// ori r11,r10,62424
	ctx.r11.u64 = ctx.r10.u64 | 62424;
	// stbx r30,r29,r11
	REX_STORE_U8(ctx.r29.u32 + ctx.r11.u32, ctx.r30.u8);
loc_822C0678:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822EE5B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x822EE5C0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addis r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,13880
	ctx.r11.s64 = ctx.r11.s64 + 13880;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// addi r31,r31,-2672
	ctx.r31.s64 = ctx.r31.s64 + -2672;
	// li r30,20
	ctx.r30.s64 = 20;
	// li r28,0
	ctx.r28.s64 = 0;
loc_822EE5E8:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822ee608
	if (ctx.cr6.eq) goto loc_822EE608;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822EE608;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822EE608:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stwu r28,4(r31)
	ea = 4 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r31.u32 = ea;
	// bne 0x822ee5e8
	if (!ctx.cr0.eq) goto loc_822EE5E8;
	// addis r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 65536;
	// addi r31,r31,-2880
	ctx.r31.s64 = ctx.r31.s64 + -2880;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822ee640
	if (ctx.cr6.eq) goto loc_822EE640;
	// bl 0x823bb108
	ctx.lr = 0x822EE62C;
	sub_823BB108(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822ee63c
	if (ctx.cr6.eq) goto loc_822EE63C;
	// bl 0x8227c728
	ctx.lr = 0x822EE63C;
	sub_8227C728(ctx, base);
loc_822EE63C:
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
loc_822EE640:
	// addis r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 65536;
	// li r30,7
	ctx.r30.s64 = 7;
	// addi r31,r31,-2928
	ctx.r31.s64 = ctx.r31.s64 + -2928;
loc_822EE64C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822ee660
	if (ctx.cr6.eq) goto loc_822EE660;
	// bl 0x82231d48
	ctx.lr = 0x822EE65C;
	sub_82231D48(ctx, base);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
loc_822EE660:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x822ee64c
	if (!ctx.cr0.eq) goto loc_822EE64C;
	// addis r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 65536;
	// addi r11,r11,-2800
	ctx.r11.s64 = ctx.r11.s64 + -2800;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x822ee684
	if (ctx.cr0.eq) goto loc_822EE684;
	// stb r28,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r28.u8);
loc_822EE684:
	// bl 0x825e04c0
	ctx.lr = 0x822EE688;
	sub_825E04C0(ctx, base);
	// addis r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 65536;
	// addi r31,r31,-2900
	ctx.r31.s64 = ctx.r31.s64 + -2900;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822ee6a0
	if (ctx.cr6.eq) goto loc_822EE6A0;
	// bl 0x825e0378
	ctx.lr = 0x822EE6A0;
	sub_825E0378(ctx, base);
loc_822EE6A0:
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// stw r28,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// bl 0x82231c80
	ctx.lr = 0x822EE6B4;
	sub_82231C80(ctx, base);
	// clrlwi. r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822ee6c4
	if (ctx.cr0.eq) goto loc_822EE6C4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825e0378
	ctx.lr = 0x822EE6C4;
	sub_825E0378(ctx, base);
loc_822EE6C4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822F6D80) {
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
	// lfs f0,104(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// lfs f11,100(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lfs f0,140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,36(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// lfs f13,144(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
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
	// bctrl 
	ctx.lr = 0x822F6DE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822F6E08;
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

DEFINE_REX_FUNC(sub_822FB760) {
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
	// bl 0x822fb7b8
	ctx.lr = 0x822FB780;
	sub_822FB7B8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822fb798
	if (ctx.cr0.eq) goto loc_822FB798;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822fb798
	if (ctx.cr6.eq) goto loc_822FB798;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x822FB798;
	sub_825E0378(ctx, base);
loc_822FB798:
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

DEFINE_REX_FUNC(sub_822FC4C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x822FC4D0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// clrlwi. r11,r4,31
	ctx.r11.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822fc4fc
	if (ctx.cr0.eq) goto loc_822FC4FC;
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r9,r9,62528
	ctx.r9.u64 = ctx.r9.u64 | 62528;
	// lwz r10,16(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// stwx r10,r3,r9
	REX_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.r10.u32);
loc_822FC4FC:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822fc57c
	if (ctx.cr6.eq) goto loc_822FC57C;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822fc57c
	if (ctx.cr0.eq) goto loc_822FC57C;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// li r30,1
	ctx.r30.s64 = 1;
	// addi r4,r4,-3056
	ctx.r4.s64 = ctx.r4.s64 + -3056;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_822FC530:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822fc550
	if (ctx.cr6.eq) goto loc_822FC550;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// blt cr6,0x822fc530
	if (ctx.cr6.lt) goto loc_822FC530;
	// b 0x822fc554
	goto loc_822FC554;
loc_822FC550:
	// li r9,0
	ctx.r9.s64 = 0;
loc_822FC554:
	// clrlwi. r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822fc57c
	if (ctx.cr0.eq) goto loc_822FC57C;
	// addi r5,r31,500
	ctx.r5.s64 = ctx.r31.s64 + 500;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8223e550
	ctx.lr = 0x822FC568;
	sub_8223E550(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822fc57c
	if (!ctx.cr0.eq) goto loc_822FC57C;
	// stb r30,12(r29)
	REX_STORE_U8(ctx.r29.u32 + 12, ctx.r30.u8);
	// stb r30,13(r29)
	REX_STORE_U8(ctx.r29.u32 + 13, ctx.r30.u8);
	// b 0x822fc5a8
	goto loc_822FC5A8;
loc_822FC57C:
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822fc5a8
	if (!ctx.cr0.eq) goto loc_822FC5A8;
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
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82236c80
	ctx.lr = 0x822FC5A8;
	sub_82236C80(ctx, base);
loc_822FC5A8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82301230) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// ble cr6,0x8230126c
	if (!ctx.cr6.gt) goto loc_8230126C;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,13600(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13600);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fneg f13,f0
	ctx.f13.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// b 0x8230128c
	goto loc_8230128C;
loc_8230126C:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,13600(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13600);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_8230128C:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 208);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
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
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82304838) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82304840;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 65536;
	// ld r10,96(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 96);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r9,r9,-3204
	ctx.r9.s64 = ctx.r9.s64 + -3204;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// ld r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r9.u32 + 0);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fctiwz f11,f13
	ctx.f11.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r25,r11,-30128
	ctx.r25.s64 = ctx.r11.s64 + -30128;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fctiwz f12,f12
	ctx.f12.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,0
	ctx.r3.s64 = 0;
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
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
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// stfd f11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lwz r26,100(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lfs f13,-5224(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -5224);
	ctx.f13.f64 = double(temp.f32);
	// stfd f12,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// lwz r30,100(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x82304a80
	if (ctx.cr6.gt) goto loc_82304A80;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r31,-13032(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8230492c
	if (ctx.cr6.eq) goto loc_8230492C;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aefa8
	ctx.lr = 0x8230492C;
	sub_823AEFA8(ctx, base);
loc_8230492C:
	// clrlwi r29,r3,24
	ctx.r29.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8230494c
	if (ctx.cr6.eq) goto loc_8230494C;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823aefa8
	ctx.lr = 0x8230494C;
	sub_823AEFA8(ctx, base);
loc_8230494C:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r29,16
	ctx.r10.u64 = ctx.r29.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82304964
	if (ctx.cr6.eq) goto loc_82304964;
loc_8230495C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82304a80
	goto loc_82304A80;
loc_82304964:
	// li r29,0
	ctx.r29.s64 = 0;
	// li r28,20
	ctx.r28.s64 = 20;
loc_8230496C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8230499c
	if (ctx.cr6.eq) goto loc_8230499C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x823aebd8
	ctx.lr = 0x82304988;
	sub_823AEBD8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8230499c
	if (!ctx.cr0.lt) goto loc_8230499C;
	// add r30,r3,r30
	ctx.r30.u64 = ctx.r3.u64 + ctx.r30.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// b 0x823049a0
	goto loc_823049A0;
loc_8230499C:
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
loc_823049A0:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x8230496c
	if (!ctx.cr0.eq) goto loc_8230496C;
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// beq 0x82304a80
	if (ctx.cr0.eq) goto loc_82304A80;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823049cc
	if (ctx.cr6.eq) goto loc_823049CC;
	// addi r5,r30,1
	ctx.r5.s64 = ctx.r30.s64 + 1;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823af008
	ctx.lr = 0x823049CC;
	sub_823AF008(ctx, base);
loc_823049CC:
	// rlwinm. r10,r3,0,24,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xC0;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// bne 0x8230495c
	if (!ctx.cr0.eq) goto loc_8230495C;
	// clrlwi. r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8230495c
	if (ctx.cr0.eq) goto loc_8230495C;
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// ld r10,88(r27)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r27.u32 + 88);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f12,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfs f13,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bgt cr6,0x8230495c
	if (ctx.cr6.gt) goto loc_8230495C;
	// extsw r11,r26
	ctx.r11.s64 = ctx.r26.s32;
	// lis r10,0
	ctx.r10.s64 = 0;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r10,r10,62524
	ctx.r10.u64 = ctx.r10.u64 | 62524;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// ori r11,r11,62528
	ctx.r11.u64 = ctx.r11.u64 | 62528;
	// li r3,1
	ctx.r3.s64 = 1;
	// stfsx f13,r27,r10
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r27.u32 + ctx.r10.u32, temp.u32);
	// stfsx f0,r27,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + ctx.r11.u32, temp.u32);
loc_82304A80:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82313F38) {
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
	// addi r11,r11,15392
	ctx.r11.s64 = ctx.r11.s64 + 15392;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82231c80
	ctx.lr = 0x82313F64;
	sub_82231C80(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82313f74
	if (ctx.cr0.eq) goto loc_82313F74;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82313F74;
	sub_825E0378(ctx, base);
loc_82313F74:
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

DEFINE_REX_FUNC(sub_82315D60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x82315D68;
	__savegprlr_20(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82230b40
	ctx.lr = 0x82315D74;
	sub_82230B40(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62432
	ctx.r11.u64 = ctx.r11.u64 | 62432;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823161ac
	if (ctx.cr0.eq) goto loc_823161AC;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62504
	ctx.r11.u64 = ctx.r11.u64 | 62504;
	// ori r10,r10,62460
	ctx.r10.u64 = ctx.r10.u64 | 62460;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82315db0
	if (ctx.cr0.eq) goto loc_82315DB0;
	// lbzx r9,r31,r10
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r10.u32);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x823161ac
	if (!ctx.cr0.eq) goto loc_823161AC;
loc_82315DB0:
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// ori r30,r9,62496
	ctx.r30.u64 = ctx.r9.u64 | 62496;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82315de4
	if (ctx.cr6.eq) goto loc_82315DE4;
	// lbzx r11,r31,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r10.u32);
	// add r8,r31,r10
	ctx.r8.u64 = ctx.r31.u64 + ctx.r10.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82315de4
	if (!ctx.cr0.eq) goto loc_82315DE4;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r31,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// bl 0x823af140
	ctx.lr = 0x82315DE0;
	sub_823AF140(ctx, base);
	// stb r26,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r26.u8);
loc_82315DE4:
	// addis r24,r31,1
	ctx.r24.s64 = ctx.r31.s64 + 65536;
	// addi r24,r24,-3068
	ctx.r24.s64 = ctx.r24.s64 + -3068;
	// lbz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82316054
	if (ctx.cr0.eq) goto loc_82316054;
	// lwzx r10,r31,r30
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// add r25,r31,r30
	ctx.r25.u64 = ctx.r31.u64 + ctx.r30.u64;
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x82316054
	if (!ctx.cr6.eq) goto loc_82316054;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r30,r30,-3056
	ctx.r30.s64 = ctx.r30.s64 + -3056;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r28,r28,-3064
	ctx.r28.s64 = ctx.r28.s64 + -3064;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// ori r9,r9,62476
	ctx.r9.u64 = ctx.r9.u64 | 62476;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ori r8,r8,62484
	ctx.r8.u64 = ctx.r8.u64 | 62484;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32225
	ctx.r5.s64 = -2111897600;
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r5,r5,32256
	ctx.r5.s64 = ctx.r5.s64 + 32256;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r23,r1,144
	ctx.r23.s64 = ctx.r1.s64 + 144;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,-13032(r4)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r4.u32 + -13032);
	// lfsx f0,r31,r9
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r31,r8
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v60,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vmulfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v61,v61,v60
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82315f08
	if (ctx.cr6.eq) goto loc_82315F08;
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x82315F04;
	sub_823AEFA8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_82315F08:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r11,r11,32496
	ctx.r11.s64 = ctx.r11.s64 + 32496;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r22,r1,128
	ctx.r22.s64 = ctx.r1.s64 + 128;
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r7,32720
	ctx.r7.s64 = ctx.r7.s64 + 32720;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,96
	ctx.r30.s64 = ctx.r1.s64 + 96;
	// addi r21,r1,144
	ctx.r21.s64 = ctx.r1.s64 + 144;
	// stw r26,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r26.u32);
	// addi r20,r1,144
	ctx.r20.s64 = ctx.r1.s64 + 144;
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r1,112
	ctx.r23.s64 = ctx.r1.s64 + 112;
	// lfs f11,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lis r4,-32111
	ctx.r4.s64 = -2104426496;
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r10,r11,2688
	ctx.r10.s64 = ctx.r11.s64 + 2688;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// ld r11,3128(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 3128);
	// stvx128 v61,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// std r11,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r11.u64);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stw r10,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r10.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v61,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82316024;
	sub_8255F918(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,-1
	ctx.r3.s64 = -1;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// std r11,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r11.u64);
	// beq cr6,0x8231604c
	if (ctx.cr6.eq) goto loc_8231604C;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823afdf0
	ctx.lr = 0x8231604C;
	sub_823AFDF0(ctx, base);
loc_8231604C:
	// stw r3,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r3.u32);
	// b 0x823161a4
	goto loc_823161A4;
loc_82316054:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823161ac
	if (ctx.cr6.eq) goto loc_823161AC;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r26,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r26.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,32496
	ctx.r11.s64 = ctx.r11.s64 + 32496;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r29,r1,144
	ctx.r29.s64 = ctx.r1.s64 + 144;
	// addi r26,r1,144
	ctx.r26.s64 = ctx.r1.s64 + 144;
	// addi r23,r1,144
	ctx.r23.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r7,32720
	ctx.r7.s64 = ctx.r7.s64 + 32720;
	// addi r9,r9,-3056
	ctx.r9.s64 = ctx.r9.s64 + -3056;
	// lfs f11,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r1,128
	ctx.r27.s64 = ctx.r1.s64 + 128;
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r28,r1,112
	ctx.r28.s64 = ctx.r1.s64 + 112;
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// addi r25,r1,112
	ctx.r25.s64 = ctx.r1.s64 + 112;
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r6,-32226
	ctx.r6.s64 = -2111963136;
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r6,2688
	ctx.r10.s64 = ctx.r6.s64 + 2688;
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f10,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// ld r11,3128(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 3128);
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r4,r4,-3064
	ctx.r4.s64 = ctx.r4.s64 + -3064;
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r10,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r10.u32);
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v60,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r11.u64);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f13,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v61,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stvx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
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
	// std r11,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82316180;
	sub_8255F918(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// std r10,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r10.u64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823161a4
	if (ctx.cr6.eq) goto loc_823161A4;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwzx r3,r31,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// bl 0x823aff18
	ctx.lr = 0x823161A4;
	sub_823AFF18(ctx, base);
loc_823161A4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r24)
	REX_STORE_U8(ctx.r24.u32 + 0, ctx.r11.u8);
loc_823161AC:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82342D08) {
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
	// bl 0x82342d60
	ctx.lr = 0x82342D28;
	sub_82342D60(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82342d40
	if (ctx.cr0.eq) goto loc_82342D40;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82342d40
	if (ctx.cr6.eq) goto loc_82342D40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82342D40;
	sub_825E0378(ctx, base);
loc_82342D40:
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

DEFINE_REX_FUNC(sub_82347048) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82347050;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,4104
	ctx.r4.s64 = ctx.r11.s64 + 4104;
	// bl 0x8222fa58
	ctx.lr = 0x82347068;
	sub_8222FA58(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r5,-32240
	ctx.r5.s64 = -2112880640;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lfs f31,12468(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stfsx f31,r31,r11
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lis r4,-32226
	ctx.r4.s64 = -2111963136;
	// ori r10,r10,62376
	ctx.r10.u64 = ctx.r10.u64 | 62376;
	// ori r9,r9,62380
	ctx.r9.u64 = ctx.r9.u64 | 62380;
	// ori r8,r8,62384
	ctx.r8.u64 = ctx.r8.u64 | 62384;
	// ori r7,r7,62388
	ctx.r7.u64 = ctx.r7.u64 | 62388;
	// ori r6,r6,62392
	ctx.r6.u64 = ctx.r6.u64 | 62392;
	// addi r11,r4,18776
	ctx.r11.s64 = ctx.r4.s64 + 18776;
	// li r30,0
	ctx.r30.s64 = 0;
	// stfsx f31,r31,r9
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// stfsx f31,r31,r8
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stfsx f31,r31,r7
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// stfsx f31,r31,r6
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r3,r3,-3140
	ctx.r3.s64 = ctx.r3.s64 + -3140;
	// bl 0x82301c00
	ctx.lr = 0x823470D4;
	sub_82301C00(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r10,r10,62408
	ctx.r10.u64 = ctx.r10.u64 | 62408;
	// ori r8,r8,62416
	ctx.r8.u64 = ctx.r8.u64 | 62416;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,0
	ctx.r5.s64 = 0;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// ori r11,r6,62424
	ctx.r11.u64 = ctx.r6.u64 | 62424;
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// ori r9,r9,62412
	ctx.r9.u64 = ctx.r9.u64 | 62412;
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// ori r6,r5,62428
	ctx.r6.u64 = ctx.r5.u64 | 62428;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r28,0
	ctx.r28.s64 = 0;
	// stwx r30,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u32);
	// ori r5,r4,62432
	ctx.r5.u64 = ctx.r4.u64 | 62432;
	// stwx r30,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u32);
	// ori r10,r3,62436
	ctx.r10.u64 = ctx.r3.u64 | 62436;
	// stwx r30,r31,r6
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u32);
	// ori r8,r28,62448
	ctx.r8.u64 = ctx.r28.u64 | 62448;
	// lis r29,0
	ctx.r29.s64 = 0;
	// lis r27,0
	ctx.r27.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// stwx r30,r31,r5
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r30.u32);
	// lis r26,0
	ctx.r26.s64 = 0;
	// stwx r30,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u32);
	// ori r9,r29,62444
	ctx.r9.u64 = ctx.r29.u64 | 62444;
	// stfsx f31,r31,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// ori r11,r27,62452
	ctx.r11.u64 = ctx.r27.u64 | 62452;
	// addi r25,r1,80
	ctx.r25.s64 = ctx.r1.s64 + 80;
	// addi r24,r1,96
	ctx.r24.s64 = ctx.r1.s64 + 96;
	// ori r7,r7,62420
	ctx.r7.u64 = ctx.r7.u64 | 62420;
	// ori r6,r26,62456
	ctx.r6.u64 = ctx.r26.u64 | 62456;
	// stbx r30,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u8);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,-1
	ctx.r8.s64 = -1;
	// stvx128 v62,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,0
	ctx.r9.s64 = 0;
	// stfsx f31,r31,r6
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// ori r11,r5,62453
	ctx.r11.u64 = ctx.r5.u64 | 62453;
	// ori r10,r10,62454
	ctx.r10.u64 = ctx.r10.u64 | 62454;
	// stwx r8,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r8.u32);
	// ori r9,r9,62460
	ctx.r9.u64 = ctx.r9.u64 | 62460;
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// stbx r30,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u8);
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// ori r9,r8,62472
	ctx.r9.u64 = ctx.r8.u64 | 62472;
	// addi r10,r10,-3072
	ctx.r10.s64 = ctx.r10.s64 + -3072;
	// ori r8,r7,62476
	ctx.r8.u64 = ctx.r7.u64 | 62476;
	// ori r7,r11,62480
	ctx.r7.u64 = ctx.r11.u64 | 62480;
	// lwz r11,-12860(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12860);
	// stfs f0,4(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// stfsx f31,r31,r9
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// stfsx f31,r31,r7
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// beq cr6,0x82347224
	if (ctx.cr6.eq) goto loc_82347224;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-13340
	ctx.r3.s64 = ctx.r11.s64 + -13340;
	// bl 0x8246d8f0
	ctx.lr = 0x82347208;
	sub_8246D8F0(ctx, base);
	// lwz r11,-12860(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82347224
	if (ctx.cr6.eq) goto loc_82347224;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,21936
	ctx.r3.s64 = ctx.r11.s64 + 21936;
	// bl 0x8246d8f0
	ctx.lr = 0x82347224;
	sub_8246D8F0(ctx, base);
loc_82347224:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823510D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x823510E0;
	__savegprlr_20(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8222fa58
	ctx.lr = 0x823510F0;
	sub_8222FA58(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// addi r10,r10,19288
	ctx.r10.s64 = ctx.r10.s64 + 19288;
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addis r3,r30,1
	ctx.r3.s64 = ctx.r30.s64 + 65536;
	// stwx r31,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r31.u32);
	// addi r3,r3,-3160
	ctx.r3.s64 = ctx.r3.s64 + -3160;
	// bl 0x82301c00
	ctx.lr = 0x82351118;
	sub_82301C00(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// addi r22,r1,80
	ctx.r22.s64 = ctx.r1.s64 + 80;
	// addi r21,r1,96
	ctx.r21.s64 = ctx.r1.s64 + 96;
	// addi r20,r1,112
	ctx.r20.s64 = ctx.r1.s64 + 112;
	// lfs f13,12236(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12236);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r10,12236
	ctx.r10.s64 = ctx.r10.s64 + 12236;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,0
	ctx.r4.s64 = 0;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stvx128 v63,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r29,0
	ctx.r29.s64 = 0;
	// lfs f0,232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// ori r10,r4,62404
	ctx.r10.u64 = ctx.r4.u64 | 62404;
	// stvx128 v62,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r28,0
	ctx.r28.s64 = 0;
	// stvx128 v61,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r26,0
	ctx.r26.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r27,0
	ctx.r27.s64 = 0;
	// ori r4,r3,62408
	ctx.r4.u64 = ctx.r3.u64 | 62408;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r24,0
	ctx.r24.s64 = 0;
	// ori r3,r29,62412
	ctx.r3.u64 = ctx.r29.u64 | 62412;
	// ori r11,r26,62424
	ctx.r11.u64 = ctx.r26.u64 | 62424;
	// ori r29,r28,62416
	ctx.r29.u64 = ctx.r28.u64 | 62416;
	// stwx r31,r30,r4
	REX_STORE_U32(ctx.r30.u32 + ctx.r4.u32, ctx.r31.u32);
	// ori r8,r8,62392
	ctx.r8.u64 = ctx.r8.u64 | 62392;
	// ori r28,r27,62420
	ctx.r28.u64 = ctx.r27.u64 | 62420;
	// lis r25,0
	ctx.r25.s64 = 0;
	// ori r9,r9,62388
	ctx.r9.u64 = ctx.r9.u64 | 62388;
	// stfsx f0,r30,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, temp.u32);
	// ori r26,r24,62432
	ctx.r26.u64 = ctx.r24.u64 | 62432;
	// stwx r31,r30,r29
	REX_STORE_U32(ctx.r30.u32 + ctx.r29.u32, ctx.r31.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stfsx f13,r30,r8
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r8.u32, temp.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stfsx f0,r30,r28
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r28.u32, temp.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lis r23,0
	ctx.r23.s64 = 0;
	// stfsx f0,r30,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r9.u32, temp.u32);
	// ori r27,r25,62428
	ctx.r27.u64 = ctx.r25.u64 | 62428;
	// stfsx f0,r30,r26
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r26.u32, temp.u32);
	// ori r7,r7,62396
	ctx.r7.u64 = ctx.r7.u64 | 62396;
	// lfs f11,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// ori r6,r6,62400
	ctx.r6.u64 = ctx.r6.u64 | 62400;
	// lfs f10,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// ori r5,r5,62401
	ctx.r5.u64 = ctx.r5.u64 | 62401;
	// ori r25,r23,62436
	ctx.r25.u64 = ctx.r23.u64 | 62436;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stfsx f0,r30,r27
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r27.u32, temp.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r28,1
	ctx.r28.s64 = 1;
	// stwx r8,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r8.u32);
	// addis r26,r30,1
	ctx.r26.s64 = ctx.r30.s64 + 65536;
	// stwx r9,r30,r7
	REX_STORE_U32(ctx.r30.u32 + ctx.r7.u32, ctx.r9.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfsx f0,r30,r25
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r25.u32, temp.u32);
	// addi r27,r1,112
	ctx.r27.s64 = ctx.r1.s64 + 112;
	// stbx r31,r30,r6
	REX_STORE_U8(ctx.r30.u32 + ctx.r6.u32, ctx.r31.u8);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stbx r31,r30,r5
	REX_STORE_U8(ctx.r30.u32 + ctx.r5.u32, ctx.r31.u8);
	// addi r26,r26,-3096
	ctx.r26.s64 = ctx.r26.s64 + -3096;
	// stbx r28,r30,r3
	REX_STORE_U8(ctx.r30.u32 + ctx.r3.u32, ctx.r28.u8);
	// stvx128 v62,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r5,r30,1
	ctx.r5.s64 = ctx.r30.s64 + 65536;
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addis r4,r30,1
	ctx.r4.s64 = ctx.r30.s64 + 65536;
	// stfs f12,4(r26)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r26.u32 + 4, temp.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,0
	ctx.r8.s64 = 0;
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stfs f11,0(r26)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lfs f11,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r5,-3088
	ctx.r5.s64 = ctx.r5.s64 + -3088;
	// addi r4,r4,-3080
	ctx.r4.s64 = ctx.r4.s64 + -3080;
	// ori r9,r9,62464
	ctx.r9.u64 = ctx.r9.u64 | 62464;
	// ori r8,r8,62468
	ctx.r8.u64 = ctx.r8.u64 | 62468;
	// ori r11,r11,62469
	ctx.r11.u64 = ctx.r11.u64 | 62469;
	// ori r7,r7,62472
	ctx.r7.u64 = ctx.r7.u64 | 62472;
	// stfs f10,4(r5)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// ori r10,r10,62476
	ctx.r10.u64 = ctx.r10.u64 | 62476;
	// stfs f11,0(r5)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// ori r6,r6,62480
	ctx.r6.u64 = ctx.r6.u64 | 62480;
	// stfs f13,0(r4)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stfs f12,4(r4)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// stbx r31,r30,r8
	REX_STORE_U8(ctx.r30.u32 + ctx.r8.u32, ctx.r31.u8);
	// stfsx f0,r30,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r9.u32, temp.u32);
	// stbx r31,r30,r11
	REX_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r31.u8);
	// stfsx f0,r30,r7
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r7.u32, temp.u32);
	// stwx r31,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stwx r31,r30,r6
	REX_STORE_U32(ctx.r30.u32 + ctx.r6.u32, ctx.r31.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8235EAD8) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8235ec48
	ctx.lr = 0x8235EB00;
	sub_8235EC48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8235eb28
	ctx.lr = 0x8235EB0C;
	sub_8235EB28(ctx, base);
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

DEFINE_REX_FUNC(sub_8235F428) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8235F430;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x825a17c0
	ctx.lr = 0x8235F44C;
	sub_825A17C0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stw r30,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r11,r11,20208
	ctx.r11.s64 = ctx.r11.s64 + 20208;
	// addi r10,r10,22072
	ctx.r10.s64 = ctx.r10.s64 + 22072;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r29,r31,48
	ctx.r29.s64 = ctx.r31.s64 + 48;
	// lwz r3,44(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8235F478;
	sub_825E02A0(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8235f48c
	if (ctx.cr0.eq) goto loc_8235F48C;
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8235f490
	goto loc_8235F490;
loc_8235F48C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8235F490:
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// addi r3,r31,96
	ctx.r3.s64 = ctx.r31.s64 + 96;
	// stw r30,16(r29)
	REX_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
	// stw r30,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stw r30,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r30.u32);
	// stw r30,28(r29)
	REX_STORE_U32(ctx.r29.u32 + 28, ctx.r30.u32);
	// stw r30,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// stw r30,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// stw r30,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
	// bl 0x822131a0
	ctx.lr = 0x8235F4B8;
	sub_822131A0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r28,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r28.u32);
	// addi r3,r31,164
	ctx.r3.s64 = ctx.r31.s64 + 164;
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// stw r30,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);
	// stw r30,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// stw r30,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r30.u32);
	// stw r30,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r30.u32);
	// bl 0x822230e8
	ctx.lr = 0x8235F4E0;
	sub_822230E8(ctx, base);
	// addi r3,r31,176
	ctx.r3.s64 = ctx.r31.s64 + 176;
	// bl 0x822131a0
	ctx.lr = 0x8235F4E8;
	sub_822131A0(ctx, base);
	// stw r30,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r30.u32);
	// stw r30,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r30.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stw r30,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r30.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82363CF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82363CF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r30,-13060(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -13060);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82363d84
	if (ctx.cr6.eq) goto loc_82363D84;
	// lwz r31,20(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r29,24(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// b 0x82363d38
	goto loc_82363D38;
loc_82363D18:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82363D2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82363d84
	if (ctx.cr0.eq) goto loc_82363D84;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_82363D38:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82363d18
	if (!ctx.cr6.eq) goto loc_82363D18;
	// lwz r8,284(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 284);
	// lwz r7,288(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 288);
	// b 0x82363d60
	goto loc_82363D60;
loc_82363D4C:
	// lwz r3,0(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// bl 0x8245d130
	ctx.lr = 0x82363D54;
	sub_8245D130(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82363d7c
	if (!ctx.cr0.eq) goto loc_82363D7C;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
loc_82363D60:
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x82363d4c
	if (!ctx.cr6.eq) goto loc_82363D4C;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82363D6C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// b 0x82363d88
	goto loc_82363D88;
loc_82363D7C:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82363d6c
	goto loc_82363D6C;
loc_82363D84:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82363D88:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823669B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823669C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,20520
	ctx.r11.s64 = ctx.r11.s64 + 20520;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82367618
	ctx.lr = 0x823669D8;
	sub_82367618(ctx, base);
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r31,r30,32
	ctx.r31.s64 = ctx.r30.s64 + 32;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// stw r29,40(r30)
	REX_STORE_U32(ctx.r30.u32 + 40, ctx.r29.u32);
	// beq cr6,0x82366a1c
	if (ctx.cr6.eq) goto loc_82366A1C;
loc_82366A04:
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825e0378
	ctx.lr = 0x82366A0C;
	sub_825E0378(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82366a04
	if (!ctx.cr6.eq) goto loc_82366A04;
loc_82366A1C:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82366a2c
	if (ctx.cr6.eq) goto loc_82366A2C;
	// bl 0x825e0378
	ctx.lr = 0x82366A2C;
	sub_825E0378(ctx, base);
loc_82366A2C:
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82369F70) {
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
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82369fac
	if (ctx.cr6.eq) goto loc_82369FAC;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x82369F9C;
	sub_82222BB0(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
loc_82369FAC:
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

DEFINE_REX_FUNC(sub_8236B828) {
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
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x8236b8e0
	if (ctx.cr6.eq) goto loc_8236B8E0;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x8236b8e8
	if (!ctx.cr6.eq) goto loc_8236B8E8;
	// lwz r10,16(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// addi r11,r3,448
	ctx.r11.s64 = ctx.r3.s64 + 448;
	// lwz r9,20(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,452(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 452);
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r7,456(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// rlwinm r8,r9,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// li r10,0
	ctx.r10.s64 = 0;
	// subf r9,r4,r7
	ctx.r9.u64 = ctx.r7.u64 - ctx.r4.u64;
	// or r4,r6,r8
	ctx.r4.u64 = ctx.r6.u64 | ctx.r8.u64;
	// srawi. r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r4,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// beq 0x8236b8c8
	if (ctx.cr0.eq) goto loc_8236B8C8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r7,452(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 452);
	// subf r6,r6,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r6.u64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// srawi r6,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 2;
loc_8236B898:
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r3,r3,0,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFF0000;
	// cmplw cr6,r3,r8
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8236b8bc
	if (ctx.cr6.eq) goto loc_8236B8BC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8236b898
	if (ctx.cr6.lt) goto loc_8236B898;
	// b 0x8236b8c8
	goto loc_8236B8C8;
loc_8236B8BC:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,1
	ctx.r5.s64 = 1;
	// stwx r4,r10,r7
	REX_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r4.u32);
loc_8236B8C8:
	// clrlwi. r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8236b8e8
	if (!ctx.cr0.eq) goto loc_8236B8E8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82396cc8
	ctx.lr = 0x8236B8DC;
	sub_82396CC8(ctx, base);
	// b 0x8236b8e8
	goto loc_8236B8E8;
loc_8236B8E0:
	// lwz r11,16(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// stw r11,412(r3)
	REX_STORE_U32(ctx.r3.u32 + 412, ctx.r11.u32);
loc_8236B8E8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8236E990) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee4
	ctx.lr = 0x8236E998;
	__savegprlr_15(ctx, base);
	// addi r12,r1,-144
	ctx.r12.s64 = ctx.r1.s64 + -144;
	// bl 0x8273af24
	ctx.lr = 0x8236E9A0;
	__savefpr_27(ctx, base);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
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
	ctx.lr = 0x8236E9B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8236ef40
	if (ctx.cr0.eq) goto loc_8236EF40;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8236E9D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8236ef40
	if (ctx.cr0.eq) goto loc_8236EF40;
	// lbz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 240);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8236ef38
	if (!ctx.cr0.eq) goto loc_8236EF38;
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
	// bne 0x8236ea04
	if (!ctx.cr0.eq) goto loc_8236EA04;
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x8236ea0c
	goto loc_8236EA0C;
loc_8236EA04:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_8236EA0C:
	// lbz r10,280(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 280);
	// li r27,1
	ctx.r27.s64 = 1;
	// lwz r11,276(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// rlwinm r30,r10,0,30,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8236ea6c
	if (ctx.cr6.lt) goto loc_8236EA6C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8236EA38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r6,248(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r5,244(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// lwz r4,276(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r27,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r27.u8);
	// rlwinm r8,r11,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823beba0
	ctx.lr = 0x8236EA68;
	sub_823BEBA0(ctx, base);
	// b 0x8236ea98
	goto loc_8236EA98;
loc_8236EA6C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r6,248(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r8,-1
	ctx.r8.s64 = -1;
	// lwz r5,244(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// li r9,0
	ctx.r9.s64 = 0;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823be020
	ctx.lr = 0x8236EA98;
	sub_823BE020(ctx, base);
loc_8236EA98:
	// addi r3,r31,332
	ctx.r3.s64 = ctx.r31.s64 + 332;
	// bl 0x8245d190
	ctx.lr = 0x8236EAA0;
	sub_8245D190(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x8236ef38
	if (ctx.cr0.eq) goto loc_8236EF38;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8236ef38
	if (ctx.cr6.eq) goto loc_8236EF38;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f12,96(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r29,296(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lwz r10,-12872(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12872);
	// lfs f13,1812(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1812);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,29160(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29160);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f31,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
	// fnmsubs f27,f0,f13,f12
	ctx.f27.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
	// beq cr6,0x8236eaf0
	if (ctx.cr6.eq) goto loc_8236EAF0;
	// lfs f13,664(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 664);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8236eaf4
	goto loc_8236EAF4;
loc_8236EAF0:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
loc_8236EAF4:
	// lhz r9,8(r28)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r28.u32 + 8);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lhz r7,10(r28)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r28.u32 + 10);
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// extsw r7,r7
	ctx.r7.s64 = ctx.r7.s32;
	// fdivs f12,f31,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f31.f64 / ctx.f13.f64));
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// lwz r10,-15432(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -15432);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// lwz r9,-15444(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -15444);
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
	// std r7,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r7.u64);
	// lfs f0,1908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,324(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,328(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 328);
	ctx.f10.f64 = double(temp.f32);
	// std r10,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// std r9,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// vpermwi128 v0,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// lfs f28,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// stfs f28,120(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vmulfp128 v11,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vpermwi128 v60,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// vspltw128 v8,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v7,v56,v58
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vpermwi128 v13,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// vspltw128 v57,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v56,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vspltw128 v6,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// lfd f9,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// vspltw128 v2,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v30,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// lfd f8,136(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// vspltw128 v10,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// vmulfp128 v3,v56,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v5,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// lfd f7,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// vmaddfp v9,v12,v0,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lfd f6,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f7,f7
	ctx.f7.f64 = double(ctx.f7.s64);
	// fcfid f6,f6
	ctx.f6.f64 = double(ctx.f6.s64);
	// vmaddfp v8,v8,v0,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vspltw128 v4,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// vmulfp128 v7,v57,v58
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v1,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// frsp f9,f9
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// vspltw128 v11,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vspltw128 v31,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vspltw128 v12,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// frsp f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// frsp f7,f7
	ctx.f7.f64 = double(float(ctx.f7.f64));
	// frsp f6,f6
	ctx.f6.f64 = double(float(ctx.f6.f64));
	// vmaddfp v9,v6,v13,v9
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// fmuls f9,f9,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fmuls f13,f8,f13
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fmuls f8,f7,f12
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// fmuls f12,f6,f12
	ctx.f12.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// fdivs f30,f0,f9
	ctx.f30.f64 = double(float(ctx.f0.f64 / ctx.f9.f64));
	// fnmsubs f11,f8,f0,f11
	ctx.f11.f64 = double(float(-std::fma(ctx.f8.f64, ctx.f0.f64, -ctx.f11.f64)));
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmsubs f12,f12,f0,f10
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f10.f64)));
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vmaddfp v7,v5,v0,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// vmaddfp v6,v4,v0,v3
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v2,v13,v8
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// vmaddfp v9,v30,v0,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// lwz r6,452(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// fdivs f29,f0,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f29.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// vmaddfp v7,v1,v13,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v6,v31,v13,v6
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v10,v10,v0,v8
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// stvx128 v9,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v13,v11,v0,v7
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v0,v12,v0,v6
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v10,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8236ecd4
	if (!ctx.cr6.eq) goto loc_8236ECD4;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x8236EC9C;
	sub_825F8D38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8236eccc
	if (ctx.cr0.eq) goto loc_8236ECCC;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rlwinm r26,r11,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x825f8b88
	ctx.lr = 0x8236ECB4;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x8236ECC8;
	sub_825F8BF8(ctx, base);
	// b 0x8236ecd0
	goto loc_8236ECD0;
loc_8236ECCC:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8236ECD0:
	// stw r30,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r30.u32);
loc_8236ECD4:
	// lwz r10,288(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f11,348(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f11.f64 = double(temp.f32);
	// lwz r30,452(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// neg r9,r10
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// lwz r8,284(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// fsubs f0,f31,f30
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f30.f64));
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// fsubs f13,f31,f29
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f29.f64));
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f9,96(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r11,r11,24072
	ctx.r11.s64 = ctx.r11.s64 + 24072;
	// lwz r7,424(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 424);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lfs f12,31608(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31608);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fctidz f12,f12
	ctx.f12.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f12,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// fcfid f11,f9
	ctx.f11.f64 = double(ctx.f9.s64);
	// oris r6,r9,65460
	ctx.r6.u64 = ctx.r9.u64 | 4289986560;
	// fcfid f12,f10
	ctx.f12.f64 = double(ctx.f10.s64);
	// ori r6,r6,16384
	ctx.r6.u64 = ctx.r6.u64 | 16384;
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// ble cr6,0x8236eee0
	if (!ctx.cr6.gt) goto loc_8236EEE0;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f28,120(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r11,r9,4436
	ctx.r11.s64 = ctx.r9.s64 + 4436;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f28,168(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lfs f10,4436(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4436);
	ctx.f10.f64 = double(temp.f32);
	// stfs f28,200(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// lfs f11,-14680(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14680);
	ctx.f11.f64 = double(temp.f32);
	// stfs f31,204(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f28,184(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f30,144(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f29,148(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f29,140(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_8236EDA4:
	// mulli r11,r10,160
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(160));
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x8236edd0
	if (ctx.cr6.eq) goto loc_8236EDD0;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x8236edc8
	if (ctx.cr6.eq) goto loc_8236EDC8;
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f28.f64;
	// fmr f13,f28
	ctx.f13.f64 = ctx.f28.f64;
	// b 0x8236edd8
	goto loc_8236EDD8;
loc_8236EDC8:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f11.f64;
	// b 0x8236edd4
	goto loc_8236EDD4;
loc_8236EDD0:
	// fmr f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f10.f64;
loc_8236EDD4:
	// fmr f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f12.f64;
loc_8236EDD8:
	// li r8,4
	ctx.r8.s64 = 4;
	// fadds f7,f13,f9
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f13.f64 + ctx.f9.f64));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// fadds f6,f0,f8
	ctx.f6.f64 = double(float(ctx.f0.f64 + ctx.f8.f64));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// fadds f0,f0,f9
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f9.f64));
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// fadds f13,f13,f8
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f8.f64));
	// addi r26,r1,176
	ctx.r26.s64 = ctx.r1.s64 + 176;
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f6,112(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// stfs f7,116(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r25,12(r5)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lwz r24,0(r4)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lwz r23,4(r4)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lwz r22,12(r4)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// stfs f6,176(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lwz r21,0(r3)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lwz r20,4(r3)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r19,8(r3)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r11,40
	ctx.r9.s64 = ctx.r11.s64 + 40;
	// lwz r8,0(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// addi r9,r11,-12
	ctx.r9.s64 = ctx.r11.s64 + -12;
	// lwz r18,4(r26)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// lwz r17,8(r26)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lwz r16,0(r5)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r15,4(r5)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r26,12(r26)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// lwz r4,8(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r5,8(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// stw r25,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r25.u32);
	// stw r24,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r24.u32);
	// stw r23,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r23.u32);
	// stw r22,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r22.u32);
	// stw r21,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r21.u32);
	// stw r20,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r20.u32);
	// stw r19,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r19.u32);
	// stw r8,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r8.u32);
	// stw r18,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r18.u32);
	// stw r17,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r17.u32);
	// stw r16,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r16.u32);
	// stw r15,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r15.u32);
	// stw r3,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r3.u32);
	// stw r26,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r26.u32);
	// stw r4,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r4.u32);
	// stw r5,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
loc_8236EEA8:
	// stwu r6,40(r9)
	ea = 40 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r6.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8236eea8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8236EEA8;
	// ld r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// ld r8,128(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// ld r5,136(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// ld r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r9,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r9.u64);
	// std r8,112(r11)
	REX_STORE_U64(ctx.r11.u32 + 112, ctx.r8.u64);
	// std r5,72(r11)
	REX_STORE_U64(ctx.r11.u32 + 72, ctx.r5.u64);
	// std r4,152(r11)
	REX_STORE_U64(ctx.r11.u32 + 152, ctx.r4.u64);
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8236eda4
	if (ctx.cr6.lt) goto loc_8236EDA4;
loc_8236EEE0:
	// lwz r11,448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 448);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stw r11,76(r30)
	REX_STORE_U32(ctx.r30.u32 + 76, ctx.r11.u32);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// stw r28,208(r30)
	REX_STORE_U32(ctx.r30.u32 + 208, ctx.r28.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// stb r27,71(r30)
	REX_STORE_U8(ctx.r30.u32 + 71, ctx.r27.u8);
	// stfs f27,412(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r30.u32 + 412, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,408(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stw r11,408(r30)
	REX_STORE_U32(ctx.r30.u32 + 408, ctx.r11.u32);
	// lwz r11,3616(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 3616);
	// stw r11,368(r30)
	REX_STORE_U32(ctx.r30.u32 + 368, ctx.r11.u32);
	// lwz r11,408(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// ori r11,r11,448
	ctx.r11.u64 = ctx.r11.u64 | 448;
	// stw r11,408(r30)
	REX_STORE_U32(ctx.r30.u32 + 408, ctx.r11.u32);
	// bl 0x8273a030
	ctx.lr = 0x8236EF28;
	sub_8273A030(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82459d08
	ctx.lr = 0x8236EF38;
	sub_82459D08(ctx, base);
loc_8236EF38:
	// addi r3,r31,372
	ctx.r3.s64 = ctx.r31.s64 + 372;
	// bl 0x823665e8
	ctx.lr = 0x8236EF40;
	sub_823665E8(ctx, base);
loc_8236EF40:
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-144
	ctx.r12.s64 = ctx.r1.s64 + -144;
	// bl 0x8273af70
	ctx.lr = 0x8236EF4C;
	__restfpr_27(ctx, base);
	// b 0x82739f34
	__restgprlr_15(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823974B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823974B8;
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
	// li r4,444
	ctx.r4.s64 = 444;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823974E0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823974fc
	if (ctx.cr0.eq) goto loc_823974FC;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82397508
	ctx.lr = 0x823974F8;
	sub_82397508(ctx, base);
	// b 0x82397500
	goto loc_82397500;
loc_823974FC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82397500:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8239A040) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8239A048;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r31,r3,276
	ctx.r31.s64 = ctx.r3.s64 + 276;
	// li r29,2
	ctx.r29.s64 = 2;
	// li r30,0
	ctx.r30.s64 = 0;
loc_8239A05C:
	// lwz r3,-4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8239a070
	if (ctx.cr6.eq) goto loc_8239A070;
	// bl 0x8221cc98
	ctx.lr = 0x8239A06C;
	sub_8221CC98(ctx, base);
	// stw r30,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r30.u32);
loc_8239A070:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8239a084
	if (ctx.cr6.eq) goto loc_8239A084;
	// bl 0x8221cc98
	ctx.lr = 0x8239A080;
	sub_8221CC98(ctx, base);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
loc_8239A084:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,48
	ctx.r31.s64 = ctx.r31.s64 + 48;
	// bne 0x8239a05c
	if (!ctx.cr0.eq) goto loc_8239A05C;
	// addi r30,r28,340
	ctx.r30.s64 = ctx.r28.s64 + 340;
	// li r31,3
	ctx.r31.s64 = 3;
loc_8239A098:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8245d0d8
	ctx.lr = 0x8239A0A0;
	sub_8245D0D8(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// bne 0x8239a098
	if (!ctx.cr0.eq) goto loc_8239A098;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8235fb40
	ctx.lr = 0x8239A0B4;
	sub_8235FB40(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8239FD38) {
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
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,519
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 519, ctx.xer);
	// beq cr6,0x8239fd64
	if (ctx.cr6.eq) goto loc_8239FD64;
	// bl 0x8235f668
	ctx.lr = 0x8239FD60;
	sub_8235F668(ctx, base);
	// b 0x8239fdc4
	goto loc_8239FDC4;
loc_8239FD64:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8239fdc4
	if (ctx.cr6.eq) goto loc_8239FDC4;
	// lwz r10,20(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// addi r11,r31,272
	ctx.r11.s64 = ctx.r31.s64 + 272;
	// stw r10,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r10.u32);
	// lwz r10,24(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// stw r10,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r10.u32);
	// lbz r10,28(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8239fdb0
	if (!ctx.cr0.eq) goto loc_8239FDB0;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stw r10,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r9,5708
	ctx.r3.s64 = ctx.r9.s64 + 5708;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// bl 0x8257d4d8
	ctx.lr = 0x8239FDAC;
	sub_8257D4D8(ctx, base);
	// b 0x8239fdb8
	goto loc_8239FDB8;
loc_8239FDB0:
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
loc_8239FDB8:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_8239FDC4:
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

DEFINE_REX_FUNC(sub_823A3D70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x823A3D78;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af18
	ctx.lr = 0x823A3D80;
	__savefpr_24(ctx, base);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823A3D98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823a4240
	if (ctx.cr0.eq) goto loc_823A4240;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823A3DB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823a4240
	if (ctx.cr0.eq) goto loc_823A4240;
	// addi r3,r26,816
	ctx.r3.s64 = ctx.r26.s64 + 816;
	// bl 0x8245d190
	ctx.lr = 0x823A3DC4;
	sub_8245D190(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lwz r10,-12872(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12872);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f31,-232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x823a3dec
	if (ctx.cr6.eq) goto loc_823A3DEC;
	// lfs f0,664(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 664);
	ctx.f0.f64 = double(temp.f32);
	// b 0x823a3df0
	goto loc_823A3DF0;
loc_823A3DEC:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_823A3DF0:
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// fdivs f11,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,1908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f30,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r30,r10,-4080
	ctx.r30.s64 = ctx.r10.s64 + -4080;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r10,-15432(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + -15432);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r11,-15444(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -15444);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
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
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// lhz r29,8(r27)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r27.u32 + 8);
	// lfs f13,1464(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1464);
	ctx.f13.f64 = double(temp.f32);
	// lhz r28,10(r27)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r27.u32 + 10);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// addi r11,r1,256
	ctx.r11.s64 = ctx.r1.s64 + 256;
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// lfs f12,1444(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1444);
	ctx.f12.f64 = double(temp.f32);
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// li r4,4
	ctx.r4.s64 = 4;
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// li r3,432
	ctx.r3.s64 = 432;
	// vpermwi128 v60,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// vpermwi128 v0,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v11,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v57,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v56,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v55,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v13,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// vmulfp128 v7,v57,v58
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v4,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vmulfp128 v1,v56,v58
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v8,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vmulfp128 v30,v55,v58
	simde_mm_store_ps(ctx.v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v2,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vspltw128 v31,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// stvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v3,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// vspltw128 v9,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vspltw128 v10,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// lfd f10,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lfd f9,88(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// vmaddfp v6,v12,v0,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v11,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vspltw128 v12,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v5,v8,v0,v7
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vspltw128 v8,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vspltw128 v7,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// frsp f10,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// vmaddfp v6,v4,v13,v6
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v4,v2,v0,v1
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v0,v31,v0,v30
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vmaddfp v5,v3,v13,v5
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// fmuls f10,f10,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fmuls f11,f9,f11
	ctx.f11.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// vmaddfp v7,v7,v13,v4
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v8,v8,v13,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// fnmsubs f13,f10,f0,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f0.f64, -ctx.f13.f64)));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmsubs f0,f11,f0,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, -ctx.f12.f64)));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v9,v9,v0,v6
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v10,v10,v0,v5
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// vmaddfp v13,v11,v0,v7
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// vmaddfp v0,v12,v0,v8
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// stvx128 v9,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825f8d38
	ctx.lr = 0x823A3F5C;
	sub_825F8D38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x823a3f84
	if (ctx.cr0.eq) goto loc_823A3F84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b88
	ctx.lr = 0x823A3F6C;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x823A3F80;
	sub_825F8BF8(ctx, base);
	// b 0x823a3f88
	goto loc_823A3F88;
loc_823A3F84:
	// li r31,0
	ctx.r31.s64 = 0;
loc_823A3F88:
	// extsw r11,r28
	ctx.r11.s64 = ctx.r28.s32;
	// lwz r7,424(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// extsw r10,r29
	ctx.r10.s64 = ctx.r29.s32;
	// lfs f25,1632(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1632);
	ctx.f25.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r11,r11,-23056
	ctx.r11.s64 = ctx.r11.s64 + -23056;
	// frsp f6,f0
	ctx.f6.f64 = double(float(ctx.f0.f64));
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// lfs f1,380(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 380);
	ctx.f1.f64 = double(temp.f32);
	// stfs f30,136(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f28,-25436(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25436);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// lfs f29,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f29.f64 = double(temp.f32);
	// lfs f26,13768(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 13768);
	ctx.f26.f64 = double(temp.f32);
	// stfs f30,184(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,-15868(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15868);
	ctx.f13.f64 = double(temp.f32);
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// fdivs f2,f31,f6
	ctx.f2.f64 = double(float(ctx.f31.f64 / ctx.f6.f64));
	// stfs f30,152(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f30,168(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// fdivs f7,f31,f12
	ctx.f7.f64 = double(float(ctx.f31.f64 / ctx.f12.f64));
	// fmuls f3,f7,f13
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
loc_823A4010:
	// mulli r11,r9,36
	ctx.r11.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(36));
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + ctx.r26.u64;
	// mulli r11,r9,160
	ctx.r11.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(160));
	// lwz r8,256(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 256);
	// lfs f0,260(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 260);
	ctx.f0.f64 = double(temp.f32);
	// lfs f8,264(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 264);
	ctx.f8.f64 = double(temp.f32);
	// lfs f12,268(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 268);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x823a4064
	if (!ctx.cr6.eq) goto loc_823A4064;
	// fsubs f24,f31,f12
	ctx.f24.f64 = double(float(ctx.f31.f64 - ctx.f12.f64));
	// fsubs f4,f0,f1
	ctx.f4.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// fadds f5,f0,f1
	ctx.f5.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// fadds f9,f8,f28
	ctx.f9.f64 = double(float(ctx.f8.f64 + ctx.f28.f64));
	// fmr f12,f3
	ctx.f12.f64 = ctx.f3.f64;
	// fmuls f11,f7,f27
	ctx.f11.f64 = double(float(ctx.f7.f64 * ctx.f27.f64));
	// fmuls f10,f2,f26
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f26.f64));
	// fmuls f0,f24,f29
	ctx.f0.f64 = double(float(ctx.f24.f64 * ctx.f29.f64));
	// fsubs f24,f13,f0
	ctx.f24.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fsubs f0,f9,f0
	ctx.f0.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// b 0x823a40c0
	goto loc_823A40C0;
loc_823A4064:
	// fsubs f12,f31,f12
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f31.f64 - ctx.f12.f64));
	// cmpwi cr6,r9,15
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 15, ctx.xer);
	// fmr f4,f0
	ctx.f4.f64 = ctx.f0.f64;
	// fmuls f9,f12,f25
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f25.f64));
	// bne cr6,0x823a4080
	if (!ctx.cr6.eq) goto loc_823A4080;
	// fadds f5,f0,f13
	ctx.f5.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// b 0x823a40a8
	goto loc_823A40A8;
loc_823A4080:
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// lfs f0,296(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,272(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f5.f64 = double(temp.f32);
loc_823A40A8:
	// fadds f0,f8,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f8.f64 + ctx.f13.f64));
	// fsubs f24,f13,f9
	ctx.f24.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// fmuls f12,f7,f30
	ctx.f12.f64 = double(float(ctx.f7.f64 * ctx.f30.f64));
	// fmr f11,f3
	ctx.f11.f64 = ctx.f3.f64;
	// fmuls f10,f2,f30
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f30.f64));
	// fsubs f0,f0,f9
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f9.f64));
loc_823A40C0:
	// stfs f0,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f4,128(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f5,144(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stfs f8,148(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f4,160(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lwz r19,12(r6)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// stfs f8,164(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r19,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r19.u32);
	// lwz r3,0(r6)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stfs f5,176(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lwz r24,0(r5)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lwz r10,4(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// addi r25,r11,40
	ctx.r25.s64 = ctx.r11.s64 + 40;
	// lwz r23,8(r5)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// fdivs f9,f24,f6
	ctx.f9.f64 = double(float(ctx.f24.f64 / ctx.f6.f64));
	// lwz r22,0(r4)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r21,4(r4)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r20,8(r4)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r19,8(r6)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r30,0(r8)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r29,4(r8)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r28,8(r8)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r25,12(r8)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// addi r8,r11,-12
	ctx.r8.s64 = ctx.r11.s64 + -12;
	// lwz r5,12(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r4,12(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r6,4(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// stw r19,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r19.u32);
	// stw r30,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r30.u32);
	// stw r29,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r29.u32);
	// stw r28,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r28.u32);
	// stw r25,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r25.u32);
	// stw r24,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r24.u32);
	// stw r10,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r10.u32);
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// stw r23,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r23.u32);
	// stw r5,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r5.u32);
	// stw r22,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r22.u32);
	// stw r21,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r21.u32);
	// stw r20,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r20.u32);
	// stw r4,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r4.u32);
loc_823A4184:
	// li r10,-1
	ctx.r10.s64 = -1;
	// stwu r10,40(r8)
	ea = 40 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x823a4184
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823A4184;
	// stfs f11,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// cmpwi cr6,r9,16
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 16, ctx.xer);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f9,92(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r6,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r6.u64);
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r10,72(r11)
	REX_STORE_U64(ctx.r11.u32 + 72, ctx.r10.u64);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// ld r8,88(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r10,112(r11)
	REX_STORE_U64(ctx.r11.u32 + 112, ctx.r10.u64);
	// std r8,152(r11)
	REX_STORE_U64(ctx.r11.u32 + 152, ctx.r8.u64);
	// blt cr6,0x823a4010
	if (ctx.cr6.lt) goto loc_823A4010;
	// lwz r11,832(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 832);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r27,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r27.u32);
	// lfs f0,12716(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12716);
	ctx.f0.f64 = double(temp.f32);
	// stb r10,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r10.u8);
	// stfs f0,412(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// lwz r11,3596(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 3596);
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r11,r11,1472
	ctx.r11.u64 = ctx.r11.u64 | 1472;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// bl 0x8273a030
	ctx.lr = 0x823A4230;
	sub_8273A030(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82459d08
	ctx.lr = 0x823A4240;
	sub_82459D08(ctx, base);
loc_823A4240:
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af64
	ctx.lr = 0x823A424C;
	__restfpr_24(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823CC100) {
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
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lbz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// subf r11,r3,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r3.u64;
	// srawi r5,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r11.s32 >> 2;
	// bl 0x823cc750
	ctx.lr = 0x823CC134;
	sub_823CC750(ctx, base);
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// beq cr6,0x823cc2c0
	if (ctx.cr6.eq) goto loc_823CC2C0;
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// beq cr6,0x823cc26c
	if (ctx.cr6.eq) goto loc_823CC26C;
	// cmpwi cr6,r30,3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 3, ctx.xer);
	// beq cr6,0x823cc218
	if (ctx.cr6.eq) goto loc_823CC218;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// beq cr6,0x823cc1c4
	if (ctx.cr6.eq) goto loc_823CC1C4;
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// bne cr6,0x823cc31c
	if (!ctx.cr6.eq) goto loc_823CC31C;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r3,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r3.u64;
	// srawi r5,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r11.s32 >> 2;
	// bl 0x823cc948
	ctx.lr = 0x823CC170;
	sub_823CC948(ctx, base);
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x823cc31c
	if (ctx.cr6.eq) goto loc_823CC31C;
	// subf r10,r3,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r3.u64;
	// lbz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r11,0
	ctx.r11.s64 = 0;
	// srawi r5,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 2;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r5,1
	ctx.r9.s64 = ctx.r5.s64 + 1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// bl 0x823cced0
	ctx.lr = 0x823CC1BC;
	sub_823CCED0(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x823cc310
	goto loc_823CC310;
loc_823CC1C4:
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x823cc31c
	if (ctx.cr6.eq) goto loc_823CC31C;
	// subf r10,r3,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r3.u64;
	// lbz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r11,0
	ctx.r11.s64 = 0;
	// srawi r5,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 2;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r5,1
	ctx.r9.s64 = ctx.r5.s64 + 1;
	// stw r11,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r11.u32);
	// stw r11,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// stw r10,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// stw r11,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r11.u32);
	// bl 0x823cd080
	ctx.lr = 0x823CC210;
	sub_823CD080(ctx, base);
	// lwz r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// b 0x823cc310
	goto loc_823CC310;
loc_823CC218:
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x823cc31c
	if (ctx.cr6.eq) goto loc_823CC31C;
	// subf r10,r3,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r3.u64;
	// lbz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r11,0
	ctx.r11.s64 = 0;
	// srawi r5,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 2;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r5,1
	ctx.r9.s64 = ctx.r5.s64 + 1;
	// stw r11,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r11.u32);
	// stw r11,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// stw r10,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// stw r11,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r11.u32);
	// bl 0x823ccfa8
	ctx.lr = 0x823CC264;
	sub_823CCFA8(ctx, base);
	// lwz r3,160(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// b 0x823cc310
	goto loc_823CC310;
loc_823CC26C:
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x823cc31c
	if (ctx.cr6.eq) goto loc_823CC31C;
	// subf r10,r3,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r3.u64;
	// lbz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r11,0
	ctx.r11.s64 = 0;
	// srawi r5,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 2;
	// stw r11,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r11.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r9,r5,1
	ctx.r9.s64 = ctx.r5.s64 + 1;
	// stw r11,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r11.u32);
	// stw r11,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r11.u32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// stw r10,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r10.u32);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// stw r11,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r11.u32);
	// bl 0x823ccdf8
	ctx.lr = 0x823CC2B8;
	sub_823CCDF8(ctx, base);
	// lwz r3,192(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// b 0x823cc310
	goto loc_823CC310;
loc_823CC2C0:
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x823cc31c
	if (ctx.cr6.eq) goto loc_823CC31C;
	// subf r10,r3,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r3.u64;
	// lbz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r11,0
	ctx.r11.s64 = 0;
	// srawi r5,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 2;
	// stw r11,224(r1)
	REX_STORE_U32(ctx.r1.u32 + 224, ctx.r11.u32);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// addi r9,r5,1
	ctx.r9.s64 = ctx.r5.s64 + 1;
	// stw r11,228(r1)
	REX_STORE_U32(ctx.r1.u32 + 228, ctx.r11.u32);
	// stw r11,232(r1)
	REX_STORE_U32(ctx.r1.u32 + 232, ctx.r11.u32);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// stw r10,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r10.u32);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// stw r11,236(r1)
	REX_STORE_U32(ctx.r1.u32 + 236, ctx.r11.u32);
	// bl 0x823cced0
	ctx.lr = 0x823CC30C;
	sub_823CCED0(ctx, base);
	// lwz r3,224(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 224);
loc_823CC310:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823cc31c
	if (ctx.cr6.eq) goto loc_823CC31C;
	// bl 0x825e0378
	ctx.lr = 0x823CC31C;
	sub_825E0378(ctx, base);
loc_823CC31C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
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

DEFINE_REX_FUNC(sub_823DD740) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x823DD748;
	__savegprlr_18(ctx, base);
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8273af28
	ctx.lr = 0x823DD750;
	__savefpr_28(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r10,r10,17124
	ctx.r10.s64 = ctx.r10.s64 + 17124;
	// addi r11,r11,-27352
	ctx.r11.s64 = ctx.r11.s64 + -27352;
	// addi r20,r10,-4
	ctx.r20.s64 = ctx.r10.s64 + -4;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// addi r7,r10,-4080
	ctx.r7.s64 = ctx.r10.s64 + -4080;
	// lis r8,-32228
	ctx.r8.s64 = -2112094208;
	// lfs f0,-28148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f30,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f29,14376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14376);
	ctx.f29.f64 = double(temp.f32);
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// lfs f31,1564(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 1564);
	ctx.f31.f64 = double(temp.f32);
	// addi r28,r3,172
	ctx.r28.s64 = ctx.r3.s64 + 172;
	// lfs f28,-2184(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -2184);
	ctx.f28.f64 = double(temp.f32);
	// li r25,3
	ctx.r25.s64 = 3;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r22,-32225
	ctx.r22.s64 = -2111897600;
	// lis r21,-32114
	ctx.r21.s64 = -2104623104;
	// lis r23,-32114
	ctx.r23.s64 = -2104623104;
	// addi r18,r11,31356
	ctx.r18.s64 = ctx.r11.s64 + 31356;
	// addi r24,r10,22072
	ctx.r24.s64 = ctx.r10.s64 + 22072;
loc_823DD7BC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x825e02a0
	ctx.lr = 0x823DD7CC;
	sub_825E02A0(ctx, base);
	// mr. r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq 0x823dd870
	if (ctx.cr0.eq) goto loc_823DD870;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// li r4,40
	ctx.r4.s64 = 40;
	// bl 0x825e02a0
	ctx.lr = 0x823DD7E4;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x823dd860
	if (ctx.cr0.eq) goto loc_823DD860;
	// lfs f0,-32128(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -32128);
	ctx.f0.f64 = double(temp.f32);
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// lfs f13,-20940(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -20940);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stfs f30,4(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// stw r26,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r26.u32);
	// stfs f29,12(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// addi r27,r31,28
	ctx.r27.s64 = ctx.r31.s64 + 28;
	// li r29,2
	ctx.r29.s64 = 2;
loc_823DD820:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// li r4,188
	ctx.r4.s64 = 188;
	// bl 0x825e02a0
	ctx.lr = 0x823DD830;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823dd844
	if (ctx.cr0.eq) goto loc_823DD844;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823bdc58
	ctx.lr = 0x823DD840;
	sub_823BDC58(ctx, base);
	// b 0x823dd848
	goto loc_823DD848;
loc_823DD844:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_823DD848:
	// li r11,10
	ctx.r11.s64 = 10;
	// stwu r3,4(r27)
	ea = 4 + ctx.r27.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r27.u32 = ea;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r11,120(r3)
	REX_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// bne 0x823dd820
	if (!ctx.cr0.eq) goto loc_823DD820;
	// b 0x823dd864
	goto loc_823DD864;
loc_823DD860:
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
loc_823DD864:
	// stw r31,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r31.u32);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// b 0x823dd874
	goto loc_823DD874;
loc_823DD870:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_823DD874:
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// lfs f13,-26744(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + -26744);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r10,-151
	ctx.r10.s64 = -9895936;
	// lwz r9,240(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 240);
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// stw r9,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// ori r10,r10,255
	ctx.r10.u64 = ctx.r10.u64 | 255;
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lfsu f0,4(r20)
	ea = 4 + ctx.r20.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r20.u32 = ea;
	// fsubs f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f28.f64));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// ld r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r9.u64);
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// lwzu r11,4(r28)
	ea = 4 + ctx.r28.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r28.u32 = ea;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,16(r9)
	REX_STORE_U32(ctx.r9.u32 + 16, ctx.r10.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r30,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r30.u32);
	// bne 0x823dd7bc
	if (!ctx.cr0.eq) goto loc_823DD7BC;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8273af74
	ctx.lr = 0x823DD8E0;
	__restfpr_28(ctx, base);
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823EA4F8) {
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
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x823ea518
	if (!ctx.cr6.eq) goto loc_823EA518;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// b 0x823ea554
	goto loc_823EA554;
loc_823EA518:
	// extsw r11,r4
	ctx.r11.s64 = ctx.r4.s32;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,-30652(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30652);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r11,31936
	ctx.r6.s64 = ctx.r11.s64 + 31936;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,256
	ctx.r4.s64 = 256;
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfd f1,48(r1)
	REX_STORE_U64(ctx.r1.u32 + 48, ctx.f1.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 48);
	// bl 0x82738b58
	ctx.lr = 0x823EA554;
	sub_82738B58(ctx, base);
loc_823EA554:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823ED2B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x823ED2B8;
	__savegprlr_23(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// lwz r3,296(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 296);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// lbz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 28);
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// mr r24,r10
	ctx.r24.u64 = ctx.r10.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823ed2f0
	if (ctx.cr0.eq) goto loc_823ED2F0;
	// bl 0x82855b44
	ctx.lr = 0x823ED2F0;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_823ED2F0:
	// lwz r11,284(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 284);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r9,288(r23)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r23.u32 + 288);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x823ed354
	if (ctx.cr6.eq) goto loc_823ED354;
	// clrlwi r8,r26,24
	ctx.r8.u64 = ctx.r26.u32 & 0xFF;
loc_823ED30C:
	// lbz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x823ed328
	if (ctx.cr6.eq) goto loc_823ED328;
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x823ed30c
	if (!ctx.cr6.eq) goto loc_823ED30C;
	// b 0x823ed354
	goto loc_823ED354;
loc_823ED328:
	// clrlwi r10,r24,24
	ctx.r10.u64 = ctx.r24.u32 & 0xFF;
	// std r27,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r27.u64);
	// stb r31,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r31.u8);
	// addic r8,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stb r30,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r30.u8);
	// stb r29,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r29.u8);
	// subfe r8,r8,r10
	temp.u8 = (~ctx.r8.u32 + ctx.r10.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r8.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r28,3(r11)
	REX_STORE_U8(ctx.r11.u32 + 3, ctx.r28.u8);
	// stb r25,5(r11)
	REX_STORE_U8(ctx.r11.u32 + 5, ctx.r25.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r8,6(r11)
	REX_STORE_U8(ctx.r11.u32 + 6, ctx.r8.u8);
loc_823ED354:
	// clrlwi. r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823ed410
	if (!ctx.cr0.eq) goto loc_823ED410;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stb r26,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r26.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// std r27,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r27.u64);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stb r30,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r30.u8);
	// stb r29,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r29.u8);
	// stb r28,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r28.u8);
	// stb r31,100(r1)
	REX_STORE_U8(ctx.r1.u32 + 100, ctx.r31.u8);
	// stb r31,101(r1)
	REX_STORE_U8(ctx.r1.u32 + 101, ctx.r31.u8);
	// stb r31,102(r1)
	REX_STORE_U8(ctx.r1.u32 + 102, ctx.r31.u8);
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// stb r31,103(r1)
	REX_STORE_U8(ctx.r1.u32 + 103, ctx.r31.u8);
	// bl 0x8242a790
	ctx.lr = 0x823ED394;
	sub_8242A790(ctx, base);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x8273a030
	ctx.lr = 0x823ED3A4;
	sub_8273A030(ctx, base);
	// lwz r11,284(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 284);
	// addi r3,r23,280
	ctx.r3.s64 = ctx.r23.s64 + 280;
	// li r10,40
	ctx.r10.s64 = 40;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823ed3c4
	if (ctx.cr6.eq) goto loc_823ED3C4;
	// lwz r9,12(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	// divw r31,r9,r10
	ctx.r31.u64 = uint32_t((ctx.r10.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r9.s32 / ctx.r10.s32 : 0);
loc_823ED3C4:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// divw r11,r11,r10
	ctx.r11.u64 = uint32_t((ctx.r10.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r11.s32 / ctx.r10.s32 : 0);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x823ed408
	if (!ctx.cr6.lt) goto loc_823ED408;
	// cmplwi r4,0
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq 0x823ed3fc
	if (ctx.cr0.eq) goto loc_823ED3FC;
	// li r11,5
	ctx.r11.s64 = 5;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// addi r9,r4,-8
	ctx.r9.s64 = ctx.r4.s64 + -8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_823ED3F0:
	// ldu r11,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdu r11,8(r9)
	ea = 8 + ctx.r9.u32;
	REX_STORE_U64(ea, ctx.r11.u64);
	ctx.r9.u32 = ea;
	// bdnz 0x823ed3f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823ED3F0;
loc_823ED3FC:
	// addi r11,r4,40
	ctx.r11.s64 = ctx.r4.s64 + 40;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x823ed410
	goto loc_823ED410;
loc_823ED408:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// bl 0x823ee270
	ctx.lr = 0x823ED410;
	sub_823EE270(ctx, base);
loc_823ED410:
	// lwz r3,296(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 296);
	// lbz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823ed424
	if (ctx.cr0.eq) goto loc_823ED424;
	// bl 0x82855b34
	ctx.lr = 0x823ED424;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_823ED424:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F6E18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823F6E20;
	__savegprlr_29(ctx, base);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// rlwinm r29,r4,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,3352
	ctx.r11.s64 = ctx.r11.s64 + 3352;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwzx r30,r29,r11
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// blt cr6,0x823f6e98
	if (ctx.cr6.lt) goto loc_823F6E98;
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// bge cr6,0x823f6e98
	if (!ctx.cr6.lt) goto loc_823F6E98;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r10,56(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// rlwinm r9,r30,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,-20440
	ctx.r11.s64 = ctx.r11.s64 + -20440;
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
	ctx.lr = 0x823F6E98;
	sub_823C82A8(ctx, base);
loc_823F6E98:
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,40(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
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
	ctx.lr = 0x823F6ED8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
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
	ctx.lr = 0x823F6F0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,16
	ctx.r11.s64 = 1048576;
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// ori r11,r11,583
	ctx.r11.u64 = ctx.r11.u64 | 583;
	// ori r10,r10,154
	ctx.r10.u64 = ctx.r10.u64 | 154;
	// li r4,256
	ctx.r4.s64 = 256;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lwzx r5,r29,r9
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r9.u32);
	// bl 0x823c7af0
	ctx.lr = 0x823F6F38;
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
	ctx.lr = 0x823F6F5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x823c8220
	ctx.lr = 0x823F6F64;
	sub_823C8220(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823FF6A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x823FF6A8;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// li r23,0
	ctx.r23.s64 = 0;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lfs f31,-19936(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -19936);
	ctx.f31.f64 = double(temp.f32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r23
	ctx.r31.u64 = ctx.r23.u64;
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// li r22,255
	ctx.r22.s64 = 255;
	// lis r24,-32112
	ctx.r24.s64 = -2104492032;
	// addi r28,r11,-18544
	ctx.r28.s64 = ctx.r11.s64 + -18544;
	// addi r26,r10,-18760
	ctx.r26.s64 = ctx.r10.s64 + -18760;
	// addi r25,r9,-18904
	ctx.r25.s64 = ctx.r9.s64 + -18904;
loc_823FF6E8:
	// addi r11,r28,19504
	ctx.r11.s64 = ctx.r28.s64 + 19504;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r5,r31,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x823c7af0
	ctx.lr = 0x823FF6FC;
	sub_823C7AF0(ctx, base);
	// addi r27,r28,19576
	ctx.r27.s64 = ctx.r28.s64 + 19576;
	// lwz r11,-13064(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwzx r4,r31,r27
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	// bne cr6,0x823ff718
	if (!ctx.cr6.eq) goto loc_823FF718;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// b 0x823ff724
	goto loc_823FF724;
loc_823FF718:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235d7f0
	ctx.lr = 0x823FF724;
	sub_8235D7F0(ctx, base);
loc_823FF724:
	// stwx r3,r31,r29
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, ctx.r3.u32);
	// add r11,r30,r25
	ctx.r11.u64 = ctx.r30.u64 + ctx.r25.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfsx f0,r30,r25
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r25.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// fmuls f2,f0,f31
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823FF74C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r26,4
	ctx.r11.s64 = ctx.r26.s64 + 4;
	// lwzx r9,r31,r29
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// lfsx f0,r30,r26
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r26.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r28,19648
	ctx.r10.s64 = ctx.r28.s64 + 19648;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lfsx f13,r30,r11
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// lwz r11,16(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f0,60(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// lwz r11,16(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f13,64(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lwzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwzx r10,r31,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// stw r10,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r10.u32);
	// lwzx r11,r31,r27
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823ff7b4
	if (!ctx.cr6.eq) goto loc_823FF7B4;
	// lfs f12,-4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// b 0x823ff7b8
	goto loc_823FF7B8;
loc_823FF7B4:
	// lfs f12,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_823FF7B8:
	// li r3,-100
	ctx.r3.s64 = -100;
	// bl 0x823c7f28
	ctx.lr = 0x823FF7C0;
	sub_823C7F28(ctx, base);
	// lwzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// fmuls f0,f1,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// li r10,68
	ctx.r10.s64 = 68;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfiwx f0,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.f0.u32);
	// stb r23,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r23.u8);
	// stb r23,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r23.u8);
	// stb r23,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r23.u8);
	// stb r22,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r22.u8);
	// lwzx r3,r31,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823FF808;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r30,144
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 144, ctx.xer);
	// blt cr6,0x823ff6e8
	if (ctx.cr6.lt) goto loc_823FF6E8;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x823c80a8
	ctx.lr = 0x823FF820;
	sub_823C80A8(ctx, base);
	// stb r22,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r22.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r22,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r22.u8);
	// stb r23,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r23.u8);
	// stb r23,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r23.u8);
	// lwz r3,56(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 56);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823FF848;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240CCD8) {
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
	// bl 0x8240cd30
	ctx.lr = 0x8240CCF8;
	sub_8240CD30(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8240cd10
	if (ctx.cr0.eq) goto loc_8240CD10;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8240cd10
	if (ctx.cr6.eq) goto loc_8240CD10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8240CD10;
	sub_825E0378(ctx, base);
loc_8240CD10:
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

DEFINE_REX_FUNC(sub_8240FC20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x8240FC28;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af28
	ctx.lr = 0x8240FC30;
	__savefpr_28(ctx, base);
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,168(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 168);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82410478
	if (!ctx.cr0.eq) goto loc_82410478;
	// lis r5,16
	ctx.r5.s64 = 1048576;
	// li r4,256
	ctx.r4.s64 = 256;
	// ori r5,r5,335
	ctx.r5.u64 = ctx.r5.u64 | 335;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823c7af0
	ctx.lr = 0x8240FC58;
	sub_823C7AF0(ctx, base);
	// lwz r11,300(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 300);
	// li r22,0
	ctx.r22.s64 = 0;
	// lis r19,-32112
	ctx.r19.s64 = -2104492032;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8240fcb4
	if (!ctx.cr6.eq) goto loc_8240FCB4;
	// lwz r11,-13064(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8240fc80
	if (!ctx.cr6.eq) goto loc_8240FC80;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x8240fc90
	goto loc_8240FC90;
loc_8240FC80:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235d7f0
	ctx.lr = 0x8240FC90;
	sub_8235D7F0(ctx, base);
loc_8240FC90:
	// stw r3,300(r23)
	REX_STORE_U32(ctx.r23.u32 + 300, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8240fca4
	if (!ctx.cr6.eq) goto loc_8240FCA4;
loc_8240FC9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8241047c
	goto loc_8241047C;
loc_8240FCA4:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,14(r3)
	REX_STORE_U8(ctx.r3.u32 + 14, ctx.r11.u8);
	// lwz r3,300(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 300);
	// bl 0x823c80a8
	ctx.lr = 0x8240FCB4;
	sub_823C80A8(ctx, base);
loc_8240FCB4:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r21,r11,-19936
	ctx.r21.s64 = ctx.r11.s64 + -19936;
	// addi r30,r10,-4080
	ctx.r30.s64 = ctx.r10.s64 + -4080;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// lfs f31,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// lfs f29,2268(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2268);
	ctx.f29.f64 = double(temp.f32);
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// li r20,255
	ctx.r20.s64 = 255;
	// addi r24,r11,22664
	ctx.r24.s64 = ctx.r11.s64 + 22664;
	// addi r28,r10,-31112
	ctx.r28.s64 = ctx.r10.s64 + -31112;
	// addi r27,r9,-31116
	ctx.r27.s64 = ctx.r9.s64 + -31116;
	// addi r26,r8,-31120
	ctx.r26.s64 = ctx.r8.s64 + -31120;
	// addi r25,r7,-31124
	ctx.r25.s64 = ctx.r7.s64 + -31124;
loc_8240FCFC:
	// addi r11,r29,71
	ctx.r11.s64 = ctx.r29.s64 + 71;
	// rlwinm r31,r11,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r31,r23
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8240fea8
	if (!ctx.cr6.eq) goto loc_8240FEA8;
	// cmplwi cr6,r29,1
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 1, ctx.xer);
	// blt cr6,0x8240fdac
	if (ctx.cr6.lt) goto loc_8240FDAC;
	// beq cr6,0x8240fd80
	if (ctx.cr6.eq) goto loc_8240FD80;
	// cmplwi cr6,r29,3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 3, ctx.xer);
	// blt cr6,0x8240fd54
	if (ctx.cr6.lt) goto loc_8240FD54;
	// bne cr6,0x8240fdd4
	if (!ctx.cr6.eq) goto loc_8240FDD4;
	// lwz r11,-13064(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8240fd3c
	if (!ctx.cr6.eq) goto loc_8240FD3C;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x8240fd4c
	goto loc_8240FD4C;
loc_8240FD3C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8235d7f0
	ctx.lr = 0x8240FD4C;
	sub_8235D7F0(ctx, base);
loc_8240FD4C:
	// stw r3,296(r23)
	REX_STORE_U32(ctx.r23.u32 + 296, ctx.r3.u32);
	// b 0x8240fdd4
	goto loc_8240FDD4;
loc_8240FD54:
	// lwz r11,-13064(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8240fd68
	if (!ctx.cr6.eq) goto loc_8240FD68;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x8240fd78
	goto loc_8240FD78;
loc_8240FD68:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8235d7f0
	ctx.lr = 0x8240FD78;
	sub_8235D7F0(ctx, base);
loc_8240FD78:
	// stw r3,292(r23)
	REX_STORE_U32(ctx.r23.u32 + 292, ctx.r3.u32);
	// b 0x8240fdd4
	goto loc_8240FDD4;
loc_8240FD80:
	// lwz r11,-13064(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8240fd94
	if (!ctx.cr6.eq) goto loc_8240FD94;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x8240fda4
	goto loc_8240FDA4;
loc_8240FD94:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8235d7f0
	ctx.lr = 0x8240FDA4;
	sub_8235D7F0(ctx, base);
loc_8240FDA4:
	// stw r3,288(r23)
	REX_STORE_U32(ctx.r23.u32 + 288, ctx.r3.u32);
	// b 0x8240fdd4
	goto loc_8240FDD4;
loc_8240FDAC:
	// lwz r11,-13064(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8240fdc0
	if (!ctx.cr6.eq) goto loc_8240FDC0;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x8240fdd0
	goto loc_8240FDD0;
loc_8240FDC0:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8235d7f0
	ctx.lr = 0x8240FDD0;
	sub_8235D7F0(ctx, base);
loc_8240FDD0:
	// stw r3,284(r23)
	REX_STORE_U32(ctx.r23.u32 + 284, ctx.r3.u32);
loc_8240FDD4:
	// lwzx r11,r31,r23
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240fc9c
	if (ctx.cr6.eq) goto loc_8240FC9C;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stfs f29,60(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r10.u32 + 60, temp.u32);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f29,64(r11)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lwzx r11,r31,r23
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r22,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r22.u32);
	// lwzx r11,r31,r23
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// stb r22,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r22.u8);
	// bne cr6,0x8240fe30
	if (!ctx.cr6.eq) goto loc_8240FE30;
	// lis r11,16448
	ctx.r11.s64 = 1077936128;
	// ori r11,r11,16639
	ctx.r11.u64 = ctx.r11.u64 | 16639;
	// b 0x8240fe34
	goto loc_8240FE34;
loc_8240FE30:
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
loc_8240FE34:
	// rlwinm r9,r11,24,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF;
	// stb r11,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r11.u8);
	// rlwinm r10,r11,16,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFF;
	// lwzx r3,r31,r23
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// rlwinm r11,r11,8,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF;
	// stb r9,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r9.u8);
	// stb r10,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r10.u8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stb r11,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8240FE68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r29,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r3,r31,r23
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// addi r10,r24,28
	ctx.r10.s64 = ctx.r24.s64 + 28;
	// lfs f0,-28356(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -28356);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r24,24
	ctx.r9.s64 = ctx.r24.s64 + 24;
	// lfs f13,7588(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 7588);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// fadds f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmuls f2,f0,f31
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmuls f1,f13,f31
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x8240FEA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8240FEA8:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// blt cr6,0x8240fcfc
	if (ctx.cr6.lt) goto loc_8240FCFC;
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// lfs f28,2420(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2420);
	ctx.f28.f64 = double(temp.f32);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
	// ori r28,r10,348
	ctx.r28.u64 = ctx.r10.u64 | 348;
	// addi r26,r11,-15724
	ctx.r26.s64 = ctx.r11.s64 + -15724;
loc_8240FECC:
	// addi r11,r31,48
	ctx.r11.s64 = ctx.r31.s64 + 48;
	// rlwinm r30,r11,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r30,r23
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r23.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8241008c
	if (!ctx.cr6.eq) goto loc_8241008C;
	// cmpwi cr6,r31,4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4, ctx.xer);
	// blt cr6,0x8240ff48
	if (ctx.cr6.lt) goto loc_8240FF48;
	// cmpwi cr6,r31,6
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 6, ctx.xer);
	// bgt cr6,0x8240ff48
	if (ctx.cr6.gt) goto loc_8240FF48;
	// addi r11,r31,74
	ctx.r11.s64 = ctx.r31.s64 + 74;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r23
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r23.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8240ff40
	if (ctx.cr6.eq) goto loc_8240FF40;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8240ff34
	if (ctx.cr6.eq) goto loc_8240FF34;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8240ff28
	if (ctx.cr6.eq) goto loc_8240FF28;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8240ff40
	if (!ctx.cr6.eq) goto loc_8240FF40;
	// lis r5,15
	ctx.r5.s64 = 983040;
	// ori r5,r5,4
	ctx.r5.u64 = ctx.r5.u64 | 4;
	// b 0x8240ff54
	goto loc_8240FF54;
loc_8240FF28:
	// lis r5,15
	ctx.r5.s64 = 983040;
	// ori r5,r5,3
	ctx.r5.u64 = ctx.r5.u64 | 3;
	// b 0x8240ff54
	goto loc_8240FF54;
loc_8240FF34:
	// lis r5,16
	ctx.r5.s64 = 1048576;
	// ori r5,r5,347
	ctx.r5.u64 = ctx.r5.u64 | 347;
	// b 0x8240ff54
	goto loc_8240FF54;
loc_8240FF40:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// b 0x8240ff54
	goto loc_8240FF54;
loc_8240FF48:
	// addi r11,r26,-64
	ctx.r11.s64 = ctx.r26.s64 + -64;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r10,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
loc_8240FF54:
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823c7af0
	ctx.lr = 0x8240FF60;
	sub_823C7AF0(ctx, base);
	// lwz r11,-13064(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8240ff74
	if (!ctx.cr6.eq) goto loc_8240FF74;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x8240ff84
	goto loc_8240FF84;
loc_8240FF74:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235d7f0
	ctx.lr = 0x8240FF84;
	sub_8235D7F0(ctx, base);
loc_8240FF84:
	// stwx r3,r30,r23
	REX_STORE_U32(ctx.r30.u32 + ctx.r23.u32, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240fc9c
	if (ctx.cr6.eq) goto loc_8240FC9C;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cntlzw r10,r31
	ctx.r10.u64 = ctx.r31.u32 == 0 ? 32 : __builtin_clz(ctx.r31.u32);
	// cmpwi cr6,r31,3
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 3, ctx.xer);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f29,60(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f29,64(r11)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lwzx r11,r30,r23
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r23.u32);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r10.u32);
	// lwzx r11,r30,r23
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r23.u32);
	// stb r22,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r22.u8);
	// bne cr6,0x8240ffe8
	if (!ctx.cr6.eq) goto loc_8240FFE8;
	// lis r11,16448
	ctx.r11.s64 = 1077936128;
	// ori r11,r11,16639
	ctx.r11.u64 = ctx.r11.u64 | 16639;
	// b 0x8240ffec
	goto loc_8240FFEC;
loc_8240FFE8:
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
loc_8240FFEC:
	// rlwinm r10,r11,8,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF;
	// stb r11,91(r1)
	REX_STORE_U8(ctx.r1.u32 + 91, ctx.r11.u8);
	// rlwinm r9,r11,16,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFF;
	// lwzx r3,r30,r23
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r23.u32);
	// stb r10,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r10.u8);
	// rlwinm r8,r11,24,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF;
	// stb r9,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r9.u8);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stb r8,90(r1)
	REX_STORE_U8(ctx.r1.u32 + 90, ctx.r8.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82410020;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r31,3
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 3, ctx.xer);
	// blt cr6,0x82410050
	if (ctx.cr6.lt) goto loc_82410050;
	// cmpwi cr6,r31,6
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 6, ctx.xer);
	// bgt cr6,0x82410050
	if (ctx.cr6.gt) goto loc_82410050;
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// lfs f0,-28356(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -28356);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r24,4
	ctx.r10.s64 = ctx.r24.s64 + 4;
	// lfsx f13,r11,r24
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f12.f64 = double(temp.f32);
	// fadds f13,f13,f28
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f28.f64));
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// b 0x82410070
	goto loc_82410070;
loc_82410050:
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// lfs f0,-28356(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -28356);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r24,4
	ctx.r10.s64 = ctx.r24.s64 + 4;
	// lfs f13,7588(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 7588);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r11,r24
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f11.f64 = double(temp.f32);
	// fadds f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// fadds f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
loc_82410070:
	// lwzx r3,r30,r23
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r23.u32);
	// fmuls f2,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmuls f1,f13,f31
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8241008C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8241008C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,9
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 9, ctx.xer);
	// blt cr6,0x8240fecc
	if (ctx.cr6.lt) goto loc_8240FECC;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r31,r23,256
	ctx.r31.s64 = ctx.r23.s64 + 256;
	// addi r29,r11,22792
	ctx.r29.s64 = ctx.r11.s64 + 22792;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// lfs f30,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f30.f64 = double(temp.f32);
loc_824100B0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824101e0
	if (!ctx.cr6.eq) goto loc_824101E0;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82410104
	if (ctx.cr6.eq) goto loc_82410104;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x824100f8
	if (ctx.cr6.eq) goto loc_824100F8;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x824100ec
	if (ctx.cr6.eq) goto loc_824100EC;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82410104
	if (!ctx.cr6.eq) goto loc_82410104;
	// lis r5,15
	ctx.r5.s64 = 983040;
	// ori r5,r5,4
	ctx.r5.u64 = ctx.r5.u64 | 4;
	// b 0x82410108
	goto loc_82410108;
loc_824100EC:
	// lis r5,15
	ctx.r5.s64 = 983040;
	// ori r5,r5,3
	ctx.r5.u64 = ctx.r5.u64 | 3;
	// b 0x82410108
	goto loc_82410108;
loc_824100F8:
	// lis r5,16
	ctx.r5.s64 = 1048576;
	// ori r5,r5,347
	ctx.r5.u64 = ctx.r5.u64 | 347;
	// b 0x82410108
	goto loc_82410108;
loc_82410104:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
loc_82410108:
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823c7af0
	ctx.lr = 0x82410114;
	sub_823C7AF0(ctx, base);
	// lwz r11,-13064(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82410128
	if (!ctx.cr6.eq) goto loc_82410128;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x82410138
	goto loc_82410138;
loc_82410128:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235d7f0
	ctx.lr = 0x82410138;
	sub_8235D7F0(ctx, base);
loc_82410138:
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240fc9c
	if (ctx.cr6.eq) goto loc_8240FC9C;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f29,60(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f29,64(r11)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r22,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r22.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stb r22,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r22.u8);
	// stb r20,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r20.u8);
	// stb r22,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r22.u8);
	// stb r22,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r22.u8);
	// stb r20,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r20.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824101A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// fsubs f12,f12,f30
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f30.f64));
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,-28356(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -28356);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// fadds f13,f12,f28
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f28.f64));
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmuls f2,f0,f31
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmuls f1,f13,f31
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x824101E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824101E0:
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// addi r11,r29,24
	ctx.r11.s64 = ctx.r29.s64 + 24;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x824100b0
	if (ctx.cr6.lt) goto loc_824100B0;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r29,r26,-28
	ctx.r29.s64 = ctx.r26.s64 + -28;
	// addi r30,r11,22736
	ctx.r30.s64 = ctx.r11.s64 + 22736;
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
	// addi r31,r23,228
	ctx.r31.s64 = ctx.r23.s64 + 228;
	// lis r27,-32114
	ctx.r27.s64 = -2104623104;
loc_8241020C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82410338
	if (!ctx.cr6.eq) goto loc_82410338;
	// li r4,256
	ctx.r4.s64 = 256;
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823c7af0
	ctx.lr = 0x82410228;
	sub_823C7AF0(ctx, base);
	// cmpwi cr6,r28,5
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 5, ctx.xer);
	// beq cr6,0x8241023c
	if (ctx.cr6.eq) goto loc_8241023C;
	// cmpwi cr6,r28,6
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 6, ctx.xer);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// bne cr6,0x82410240
	if (!ctx.cr6.eq) goto loc_82410240;
loc_8241023C:
	// li r4,1
	ctx.r4.s64 = 1;
loc_82410240:
	// lwz r11,-13064(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82410254
	if (!ctx.cr6.eq) goto loc_82410254;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x82410260
	goto loc_82410260;
loc_82410254:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235d7f0
	ctx.lr = 0x82410260;
	sub_8235D7F0(ctx, base);
loc_82410260:
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240fc9c
	if (ctx.cr6.eq) goto loc_8240FC9C;
	// cmpwi cr6,r28,5
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 5, ctx.xer);
	// beq cr6,0x824102a0
	if (ctx.cr6.eq) goto loc_824102A0;
	// cmpwi cr6,r28,6
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 6, ctx.xer);
	// beq cr6,0x824102a0
	if (ctx.cr6.eq) goto loc_824102A0;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f29,60(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f29,64(r11)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// b 0x824102c0
	goto loc_824102C0;
loc_824102A0:
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f30,60(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f30,64(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
loc_824102C0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r22,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r22.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stb r22,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r22.u8);
	// stb r22,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r22.u8);
	// stb r22,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r22.u8);
	// stb r22,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r22.u8);
	// stb r20,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r20.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82410304;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,-16808(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -16808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// lfs f13,-28356(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -28356);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmuls f2,f13,f31
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82410338;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82410338:
	// addi r11,r26,-28
	ctx.r11.s64 = ctx.r26.s64 + -28;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8241020c
	if (ctx.cr6.lt) goto loc_8241020C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// addi r30,r11,22816
	ctx.r30.s64 = ctx.r11.s64 + 22816;
	// addi r31,r23,268
	ctx.r31.s64 = ctx.r23.s64 + 268;
loc_82410368:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82410454
	if (!ctx.cr6.eq) goto loc_82410454;
	// li r4,256
	ctx.r4.s64 = 256;
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823c7af0
	ctx.lr = 0x82410384;
	sub_823C7AF0(ctx, base);
	// lwz r11,-13064(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82410398
	if (!ctx.cr6.eq) goto loc_82410398;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// b 0x824103a8
	goto loc_824103A8;
loc_82410398:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235d7f0
	ctx.lr = 0x824103A8;
	sub_8235D7F0(ctx, base);
loc_824103A8:
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240fc9c
	if (ctx.cr6.eq) goto loc_8240FC9C;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f29,60(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f29,64(r11)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r22,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r22.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stb r22,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r22.u8);
	// stb r20,92(r1)
	REX_STORE_U8(ctx.r1.u32 + 92, ctx.r20.u8);
	// stb r22,93(r1)
	REX_STORE_U8(ctx.r1.u32 + 93, ctx.r22.u8);
	// stb r22,94(r1)
	REX_STORE_U8(ctx.r1.u32 + 94, ctx.r22.u8);
	// stb r20,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r20.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82410418;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f12,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f12,f12,f30
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f30.f64));
	// fsubs f11,f11,f30
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f30.f64));
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,-16808(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -16808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28356(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + -28356);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// fadds f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmuls f2,f13,f31
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x82410454;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82410454:
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r11,r26,16
	ctx.r11.s64 = ctx.r26.s64 + 16;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82410368
	if (ctx.cr6.lt) goto loc_82410368;
	// lwz r11,168(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 168);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stw r11,168(r23)
	REX_STORE_U32(ctx.r23.u32 + 168, ctx.r11.u32);
loc_82410478:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8241047C:
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af74
	ctx.lr = 0x82410488;
	__restfpr_28(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82453330) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82453338;
	__savegprlr_29(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,60(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r29,64(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// b 0x8245347c
	goto loc_8245347C;
loc_8245334C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r11,280(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 280);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82453478
	if (ctx.cr0.eq) goto loc_82453478;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8245336C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82453478
	if (ctx.cr0.eq) goto loc_82453478;
	// ld r11,72(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 72);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f13,80(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lfs f12,84(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r4,88(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,292(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 292);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,156(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
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
	// bne cr6,0x82453444
	if (!ctx.cr6.eq) goto loc_82453444;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8245343c
	if (ctx.cr6.eq) goto loc_8245343C;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// li r10,3
	ctx.r10.s64 = 3;
	// bne cr6,0x82453468
	if (!ctx.cr6.eq) goto loc_82453468;
loc_8245343C:
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x82453468
	goto loc_82453468;
loc_82453444:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82453464
	if (ctx.cr6.eq) goto loc_82453464;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x82453464
	if (ctx.cr6.eq) goto loc_82453464;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,292(r11)
	REX_STORE_U32(ctx.r11.u32 + 292, ctx.r9.u32);
	// b 0x82453468
	goto loc_82453468;
loc_82453464:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82453468:
	// stw r10,292(r11)
	REX_STORE_U32(ctx.r11.u32 + 292, ctx.r10.u32);
	// ld r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// std r10,44(r11)
	REX_STORE_U64(ctx.r11.u32 + 44, ctx.r10.u64);
loc_82453478:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_8245347C:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8245334c
	if (!ctx.cr6.eq) goto loc_8245334C;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824605D0) {
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
	// lis r11,-32186
	ctx.r11.s64 = -2109341696;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r11,14192
	ctx.r3.s64 = ctx.r11.s64 + 14192;
	// bl 0x8242a0f8
	ctx.lr = 0x824605F0;
	sub_8242A0F8(ctx, base);
	// lis r11,-32186
	ctx.r11.s64 = -2109341696;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r3,r11,14400
	ctx.r3.s64 = ctx.r11.s64 + 14400;
	// bl 0x8242a0f8
	ctx.lr = 0x82460604;
	sub_8242A0F8(ctx, base);
	// lis r11,-32186
	ctx.r11.s64 = -2109341696;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r11,16440
	ctx.r3.s64 = ctx.r11.s64 + 16440;
	// bl 0x8242a0f8
	ctx.lr = 0x82460618;
	sub_8242A0F8(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12668(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12668);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246064c
	if (ctx.cr6.eq) goto loc_8246064C;
	// lis r9,-32186
	ctx.r9.s64 = -2109341696;
	// lis r8,-32223
	ctx.r8.s64 = -2111766528;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,16568
	ctx.r9.s64 = ctx.r9.s64 + 16568;
	// addi r8,r8,17200
	ctx.r8.s64 = ctx.r8.s64 + 17200;
	// stw r10,408(r11)
	REX_STORE_U32(ctx.r11.u32 + 408, ctx.r10.u32);
	// stw r9,404(r11)
	REX_STORE_U32(ctx.r11.u32 + 404, ctx.r9.u32);
	// stw r8,420(r11)
	REX_STORE_U32(ctx.r11.u32 + 420, ctx.r8.u32);
	// stw r10,424(r11)
	REX_STORE_U32(ctx.r11.u32 + 424, ctx.r10.u32);
loc_8246064C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824647A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x824647B0;
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
	// bl 0x825af990
	ctx.lr = 0x824647C0;
	sub_825AF990(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r10,r10,-27332
	ctx.r10.s64 = ctx.r10.s64 + -27332;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r29,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r29.u32);
	// lfs f31,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stfs f31,76(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// stw r9,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// stw r29,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r29.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r29,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r29.u32);
	// fmr f3,f31
	ctx.f3.f64 = ctx.f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x824576b0
	ctx.lr = 0x82464804;
	sub_824576B0(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lwz r10,-12884(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + -12884);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// ble cr6,0x82464850
	if (!ctx.cr6.gt) goto loc_82464850;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82464850
	if (ctx.cr6.eq) goto loc_82464850;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82464850
	if (ctx.cr6.eq) goto loc_82464850;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246484C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,-12884(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + -12884);
loc_82464850:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// ble cr6,0x8246488c
	if (!ctx.cr6.gt) goto loc_8246488C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8246488c
	if (ctx.cr6.eq) goto loc_8246488C;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8246488c
	if (ctx.cr6.eq) goto loc_8246488C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246488C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8246488C:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lwz r11,3648(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 3648);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x824648a4
	if (!ctx.cr6.eq) goto loc_824648A4;
	// stb r11,92(r31)
	REX_STORE_U8(ctx.r31.u32 + 92, ctx.r11.u8);
	// b 0x824648a8
	goto loc_824648A8;
loc_824648A4:
	// stb r29,92(r31)
	REX_STORE_U8(ctx.r31.u32 + 92, ctx.r29.u8);
loc_824648A8:
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

DEFINE_REX_FUNC(sub_8246E7F0) {
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
	ctx.lr = 0x8246E810;
	sub_8235EC48(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,-25908
	ctx.r4.s64 = ctx.r11.s64 + -25908;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8246b640
	ctx.lr = 0x8246E824;
	sub_8246B640(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8246e838
	if (!ctx.cr6.lt) goto loc_8246E838;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_8246E838:
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// lwz r11,-12860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246e86c
	if (ctx.cr6.eq) goto loc_8246E86C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x8246E850;
	sub_8246D8F0(ctx, base);
	// lwz r11,-12860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246e86c
	if (ctx.cr6.eq) goto loc_8246E86C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,1340
	ctx.r3.s64 = ctx.r11.s64 + 1340;
	// bl 0x8246d8f0
	ctx.lr = 0x8246E86C;
	sub_8246D8F0(ctx, base);
loc_8246E86C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8246E87C;
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

DEFINE_REX_FUNC(sub_82472478) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82472480;
	__savegprlr_28(ctx, base);
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// bne cr6,0x824724b4
	if (!ctx.cr6.eq) goto loc_824724B4;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// lfs f0,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// b 0x824724b8
	goto loc_824724B8;
loc_824724B4:
	// lfs f0,12472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f0.f64 = double(temp.f32);
loc_824724B8:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r10,32720
	ctx.r10.s64 = ctx.r10.s64 + 32720;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfd f30,2408(r11)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r11.u32 + 2408);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82738cc0
	ctx.lr = 0x82472500;
	sub_82738CC0(ctx, base);
	// lfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f31.f64 = double(temp.f32);
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
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
	// bl 0x82738be0
	ctx.lr = 0x82472530;
	sub_82738BE0(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f31,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r9,22072
	ctx.r9.s64 = ctx.r9.s64 + 22072;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,5312
	ctx.r4.s64 = 5312;
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,44(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
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
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x825e02a0
	ctx.lr = 0x82472624;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82472648
	if (ctx.cr0.eq) goto loc_82472648;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x824e7748
	ctx.lr = 0x82472640;
	sub_824E7748(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8247264c
	goto loc_8247264C;
loc_82472648:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8247264C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8247265c
	if (!ctx.cr6.eq) goto loc_8247265C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82472664
	goto loc_82472664;
loc_8247265C:
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stb r28,80(r11)
	REX_STORE_U8(ctx.r11.u32 + 80, ctx.r28.u8);
loc_82472664:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8248B4B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8248B4C0;
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
	// lhz r10,6(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// lfs f13,316(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,140(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r28,r11,-9856
	ctx.r28.s64 = ctx.r11.s64 + -9856;
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lfs f0,1212(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1212);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// fmadds f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248B518;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8248bda8
	if (ctx.cr6.lt) goto loc_8248BDA8;
	// beq cr6,0x8248b7b8
	if (ctx.cr6.eq) goto loc_8248B7B8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8248b5c4
	if (ctx.cr6.lt) goto loc_8248B5C4;
	// bne cr6,0x8248bea8
	if (!ctx.cr6.eq) goto loc_8248BEA8;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248B558;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x8248b588
	if (ctx.cr6.eq) goto loc_8248B588;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// lfs f1,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x8248B588;
	sub_8224A2A0(ctx, base);
loc_8248B588:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248B5A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8248bea8
	if (!ctx.cr6.eq) goto loc_8248BEA8;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,74(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8248bea8
	if (!ctx.cr0.eq) goto loc_8248BEA8;
	// b 0x8248b7ac
	goto loc_8248B7AC;
loc_8248B5C4:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r30,r31,68
	ctx.r30.s64 = ctx.r31.s64 + 68;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f31,12468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x8248b608
	if (ctx.cr6.lt) goto loc_8248B608;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8248B608:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f13,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r29,r11,11948
	ctx.r29.s64 = ctx.r11.s64 + 11948;
	// lfs f0,22936(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 22936);
	ctx.f0.f64 = double(temp.f32);
	// beq 0x8248b628
	if (ctx.cr0.eq) goto loc_8248B628;
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// b 0x8248b62c
	goto loc_8248B62C;
loc_8248B628:
	// fsubs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
loc_8248B62C:
	// stfs f0,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248B64C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f11,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// lfs f10,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f13,15464(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 15464);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r10,-30832
	ctx.r10.s64 = ctx.r10.s64 + -30832;
	// lfs f12,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
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
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// lfs f11,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
	// lfs f0,304(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// fadds f11,f0,f30
	ctx.f11.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stfs f11,304(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stw r10,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r10.u32);
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// fnmsubs f0,f11,f13,f12
	ctx.f0.f64 = double(float(-std::fma(ctx.f11.f64, ctx.f13.f64, -ctx.f12.f64)));
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// li r11,255
	ctx.r11.s64 = 255;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// ble cr6,0x8248b784
	if (!ctx.cr6.gt) goto loc_8248B784;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lbz r9,87(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r9,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r9.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248B780;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8248bea8
	goto loc_8248BEA8;
loc_8248B784:
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r9,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r9.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x8248B7AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8248B7AC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x8248bea8
	goto loc_8248BEA8;
loc_8248B7B8:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248B7D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// lfs f31,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// bne cr6,0x8248b810
	if (!ctx.cr6.eq) goto loc_8248B810;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,74(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8248b810
	if (!ctx.cr0.eq) goto loc_8248B810;
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8224a2a0
	ctx.lr = 0x8248B810;
	sub_8224A2A0(ctx, base);
loc_8248B810:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r27,r31,68
	ctx.r27.s64 = ctx.r31.s64 + 68;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x8248b84c
	if (ctx.cr6.lt) goto loc_8248B84C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8248B84C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f13,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r11,r11,11948
	ctx.r11.s64 = ctx.r11.s64 + 11948;
	// lfs f0,22936(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22936);
	ctx.f0.f64 = double(temp.f32);
	// beq 0x8248b86c
	if (ctx.cr0.eq) goto loc_8248B86C;
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// b 0x8248b870
	goto loc_8248B870;
loc_8248B86C:
	// fsubs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
loc_8248B870:
	// stfs f0,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248B890;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f12,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f13,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r10,-30832
	ctx.r10.s64 = ctx.r10.s64 + -30832;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r28,r11,32720
	ctx.r28.s64 = ctx.r11.s64 + 32720;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
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
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
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
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r27)
	REX_STORE_U64(ctx.r27.u32 + 0, ctx.r11.u64);
	// bl 0x8231e0d8
	ctx.lr = 0x8248B964;
	sub_8231E0D8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lfs f12,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,32544
	ctx.r11.s64 = ctx.r11.s64 + 32544;
	// lfs f11,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r30,r31,44
	ctx.r30.s64 = ctx.r31.s64 + 44;
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// li r25,0
	ctx.r25.s64 = 0;
	// lwz r29,-13032(r5)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r5.u32 + -13032);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f5,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f5.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f5,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f5,136(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f5,132(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f5,128(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f6,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,144(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f6,156(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f6,152(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f6,148(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8248ba9c
	if (ctx.cr6.eq) goto loc_8248BA9C;
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823ae578
	ctx.lr = 0x8248BA98;
	sub_823AE578(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_8248BA9C:
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// li r26,0
	ctx.r26.s64 = 0;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f6,140(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f6,132(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f6,136(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f5,156(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f5,148(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f5,144(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f5,152(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8248bb58
	if (ctx.cr6.eq) goto loc_8248BB58;
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823ae2c0
	ctx.lr = 0x8248BB54;
	sub_823AE2C0(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
loc_8248BB58:
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f5,156(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stfs f5,148(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stfs f5,144(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f5,152(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f6,92(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f6,88(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f6,84(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8248bc10
	if (ctx.cr6.eq) goto loc_8248BC10;
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aebd8
	ctx.lr = 0x8248BC10;
	sub_823AEBD8(ctx, base);
loc_8248BC10:
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// mullw r11,r25,r25
	ctx.r11.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r25.s32);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8248bea8
	if (!ctx.cr6.lt) goto loc_8248BEA8;
	// mullw r10,r3,r3
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bge cr6,0x8248bd18
	if (!ctx.cr6.lt) goto loc_8248BD18;
	// mullw r10,r26,r26
	ctx.r10.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r26.s32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// ble cr6,0x8248bcb8
	if (!ctx.cr6.gt) goto loc_8248BCB8;
	// extsw r11,r25
	ctx.r11.s64 = ctx.r25.s32;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f0,f0,f6
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f6.f64));
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8254bb70
	ctx.lr = 0x8248BCA8;
	sub_8254BB70(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f1,308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 308);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8248bd5c
	goto loc_8248BD5C;
loc_8248BCB8:
	// extsw r11,r26
	ctx.r11.s64 = ctx.r26.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fsubs f0,f0,f6
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f6.f64));
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8254bb70
	ctx.lr = 0x8248BD08;
	sub_8254BB70(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f1,236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8248bd5c
	goto loc_8248BD5C;
loc_8248BD18:
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// fadds f0,f5,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f5.f64 + ctx.f0.f64));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8254bb70
	ctx.lr = 0x8248BD58;
	sub_8254BB70(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_8248BD5C:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248BD74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// std r11,0(r27)
	REX_STORE_U64(ctx.r27.u32 + 0, ctx.r11.u64);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248BD9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
	// b 0x8248bea8
	goto loc_8248BEA8;
loc_8248BDA8:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f31,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// lfs f2,-5008(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5008);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8248BDC4;
	sub_825A4A40(ctx, base);
	// stfs f1,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x8248BDE8;
	sub_8224A2A0(ctx, base);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f1,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8248BE04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f2,11948(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11948);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8248BE18;
	sub_825A4A40(ctx, base);
	// stfs f1,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f1,148(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f1,152(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f1,156(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f1,144(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lfs f0,288(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 288);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,292(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,152(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
loc_8248BEA8:
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

DEFINE_REX_FUNC(sub_824EB870) {
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
	// lbz r11,90(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 90);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824eb8b0
	if (ctx.cr0.eq) goto loc_824EB8B0;
	// lwz r11,92(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// addi r3,r3,92
	ctx.r3.s64 = ctx.r3.s64 + 92;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824EB8AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r3,90(r31)
	REX_STORE_U8(ctx.r31.u32 + 90, ctx.r3.u8);
loc_824EB8B0:
	// lbz r11,90(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 90);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824eb95c
	if (!ctx.cr0.eq) goto loc_824EB95C;
	// lfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,76(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f31,f0,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f0,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bgt cr6,0x824eb8e8
	if (ctx.cr6.gt) goto loc_824EB8E8;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bge cr6,0x824eb8ec
	if (!ctx.cr6.lt) goto loc_824EB8EC;
loc_824EB8E8:
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f0.f64;
loc_824EB8EC:
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// addi r30,r31,92
	ctx.r30.s64 = ctx.r31.s64 + 92;
	// addi r4,r31,60
	ctx.r4.s64 = ctx.r31.s64 + 60;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824EB908;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 412);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
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
	ctx.lr = 0x824EB948;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824EB95C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824EB95C:
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

DEFINE_REX_FUNC(sub_824F1FD8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,1144(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1144);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// rlwinm. r11,r4,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,4(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,-12816(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,16(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r8,172(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwzx r9,r9,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824f2028
	if (!ctx.cr6.eq) goto loc_824F2028;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x824f202c
	if (!ctx.cr6.eq) goto loc_824F202C;
loc_824F2028:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824F202C:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x824f206c
	if (ctx.cr0.eq) goto loc_824F206C;
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824f206c
	if (!ctx.cr6.eq) goto loc_824F206C;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824f206c
	if (ctx.cr6.eq) goto loc_824F206C;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r10,r11,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x824f2068
	if (!ctx.cr0.eq) goto loc_824F2068;
	// rlwinm. r11,r11,26,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824f206c
	if (ctx.cr0.eq) goto loc_824F206C;
loc_824F2068:
	// li r7,1
	ctx.r7.s64 = 1;
loc_824F206C:
	// clrlwi. r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// lwz r3,88(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// rlwinm r11,r3,4,12,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFF0;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
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
	// beqlr 
	if (ctx.cr0.eq) return;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x82444678
	sub_82444678(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824F7020) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x824F7028;
	__savegprlr_28(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,656(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 656);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r28,440(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 440);
	// bne cr6,0x824f704c
	if (!ctx.cr6.eq) goto loc_824F704C;
loc_824F7040:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x824f72f0
	goto loc_824F72F0;
loc_824F704C:
	// bl 0x8259be58
	ctx.lr = 0x824F7050;
	sub_8259BE58(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824f7040
	if (ctx.cr0.eq) goto loc_824F7040;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x824f7040
	if (ctx.cr6.eq) goto loc_824F7040;
	// lwz r9,424(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 424);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x824f7040
	if (ctx.cr6.eq) goto loc_824F7040;
	// lhz r11,10(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 10);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f0,416(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 416);
	ctx.f0.f64 = double(temp.f32);
	// ld r8,44(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lhz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r10,12236
	ctx.r6.s64 = ctx.r10.s64 + 12236;
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f13,232(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// ld r6,44(r31)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lwz r11,340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,336(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// lfs f13,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// li r4,24
	ctx.r4.s64 = 24;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// frsp f11,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(ctx.f0.f64));
	// lfs f0,12236(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// std r6,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// divw r29,r11,r4
	ctx.r29.u64 = uint32_t((ctx.r4.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r4.s32 == -1)) ? ctx.r11.s32 / ctx.r4.s32 : 0);
	// addi r6,r9,32
	ctx.r6.s64 = ctx.r9.s64 + 32;
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f9,f0,f13
	ctx.f9.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fdivs f10,f0,f11
	ctx.f10.f64 = double(float(ctx.f0.f64 / ctx.f11.f64));
loc_824F7134:
	// lfs f13,408(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 408);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f12,312(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,412(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x824f9080
	ctx.lr = 0x824F7164;
	sub_824F9080(ctx, base);
	// lfs f12,516(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 516);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r6,40
	ctx.r10.s64 = ctx.r6.s64 + 40;
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fmuls f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r3,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// fmuls f0,f0,f9
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r3,112(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// lwz r5,8(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r4,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r4.u32);
	// stw r5,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r5.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
	// lwz r11,428(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 428);
	// std r3,0(r6)
	REX_STORE_U64(ctx.r6.u32 + 0, ctx.r3.u64);
	// addi r6,r10,80
	ctx.r6.s64 = ctx.r10.s64 + 80;
	// stw r11,28(r9)
	REX_STORE_U32(ctx.r9.u32 + 28, ctx.r11.u32);
	// addi r9,r9,120
	ctx.r9.s64 = ctx.r9.s64 + 120;
loc_824F71D4:
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// cmplw cr6,r8,r29
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x824f71f0
	if (ctx.cr6.lt) goto loc_824F71F0;
	// divwu r11,r8,r29
	ctx.r11.u64 = uint32_t(ctx.r29.u32 ? ctx.r8.u32 / ctx.r29.u32 : 0);
	// twllei r29,0
	if (ctx.r29.s32 == 0 || ctx.r29.u32 < 0u) ppc_trap(ctx, base, 0);
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// subf r5,r11,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r11.u64;
loc_824F71F0:
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// mulli r5,r5,24
	ctx.r5.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(24));
	// lfs f0,408(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 408);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,412(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x824f9080
	ctx.lr = 0x824F722C;
	sub_824F9080(ctx, base);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r5,r10,-32
	ctx.r5.s64 = ctx.r10.s64 + -32;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// lfs f12,516(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 516);
	ctx.f12.f64 = double(temp.f32);
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// fmuls f0,f0,f9
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r5,8(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r5,-24(r10)
	REX_STORE_U32(ctx.r10.u32 + -24, ctx.r5.u32);
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r5,-32(r10)
	REX_STORE_U32(ctx.r10.u32 + -32, ctx.r5.u32);
	// stw r4,-20(r10)
	REX_STORE_U32(ctx.r10.u32 + -20, ctx.r4.u32);
	// stw r11,-28(r10)
	REX_STORE_U32(ctx.r10.u32 + -28, ctx.r11.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r11,428(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 428);
	// std r5,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r5.u64);
	// stw r11,-4(r10)
	REX_STORE_U32(ctx.r10.u32 + -4, ctx.r11.u32);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// bne 0x824f71d4
	if (!ctx.cr0.eq) goto loc_824F71D4;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,96
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 96, ctx.xer);
	// blt cr6,0x824f7134
	if (ctx.cr6.lt) goto loc_824F7134;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8234ace0
	ctx.lr = 0x824F72D0;
	sub_8234ACE0(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8273a030
	ctx.lr = 0x824F72E0;
	sub_8273A030(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82459d08
	ctx.lr = 0x824F72F0;
	sub_82459D08(ctx, base);
loc_824F72F0:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8250B898) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8250B8A0;
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
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r29,r8
	ctx.r29.u64 = ctx.r8.u64;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// addi r4,r10,-9796
	ctx.r4.s64 = ctx.r10.s64 + -9796;
	// li r8,9
	ctx.r8.s64 = 9;
	// li r7,11
	ctx.r7.s64 = 11;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x8250B8DC;
	sub_825190E8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// stb r27,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r27.u8);
	// addi r11,r11,15088
	ctx.r11.s64 = ctx.r11.s64 + 15088;
	// addic r10,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r10.s64 = ctx.r28.s64 + -1;
	// li r9,0
	ctx.r9.s64 = 0;
	// subfe r10,r10,r28
	temp.u8 = (~ctx.r10.u32 + ctx.r28.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r28.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r28.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r8,r8,-7128
	ctx.r8.s64 = ctx.r8.s64 + -7128;
	// stb r9,317(r31)
	REX_STORE_U8(ctx.r31.u32 + 317, ctx.r9.u8);
	// lfs f0,-2620(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2620);
	ctx.f0.f64 = double(temp.f32);
	// stb r10,316(r31)
	REX_STORE_U8(ctx.r31.u32 + 316, ctx.r10.u8);
	// lfs f11,-2852(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2852);
	ctx.f11.f64 = double(temp.f32);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stfs f11,300(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stw r9,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r9.u32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stw r9,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r9.u32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// addi r7,r7,32432
	ctx.r7.s64 = ctx.r7.s64 + 32432;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f10,-2616(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2616);
	ctx.f10.f64 = double(temp.f32);
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
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
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x8250b974
	if (ctx.cr0.eq) goto loc_8250B974;
	// fmr f12,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = ctx.f10.f64;
	// b 0x8250b978
	goto loc_8250B978;
loc_8250B974:
	// fmr f12,f11
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f11.f64;
loc_8250B978:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r11,-6412
	ctx.r11.s64 = ctx.r11.s64 + -6412;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
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
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r10.u64);
	// stfs f13,56(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// lbz r10,316(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 316);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8250ba44
	if (ctx.cr0.eq) goto loc_8250BA44;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x8250ba48
	goto loc_8250BA48;
loc_8250BA44:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f11.f64;
loc_8250BA48:
	// lfs f13,23508(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23508);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f12,23504(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23504);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stfs f12,72(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stb r9,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r9.u8);
	// stb r29,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r29.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82519B98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82519BA0;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
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
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// addi r4,r10,-4636
	ctx.r4.s64 = ctx.r10.s64 + -4636;
	// li r8,8
	ctx.r8.s64 = 8;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x82519BD8;
	sub_825190E8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// stb r28,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r28.u8);
	// addi r11,r11,15088
	ctx.r11.s64 = ctx.r11.s64 + 15088;
	// addic r10,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r10.s64 = ctx.r29.s64 + -1;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r8,-4624
	ctx.r8.s64 = ctx.r8.s64 + -4624;
	// subfe r10,r10,r29
	temp.u8 = (~ctx.r10.u32 + ctx.r29.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r9,305(r31)
	REX_STORE_U8(ctx.r31.u32 + 305, ctx.r9.u8);
	// lfs f0,-2620(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2620);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stb r10,304(r31)
	REX_STORE_U8(ctx.r31.u32 + 304, ctx.r10.u8);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stw r9,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r9.u32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f11,-2852(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2852);
	ctx.f11.f64 = double(temp.f32);
	// addi r8,r8,32432
	ctx.r8.s64 = ctx.r8.s64 + 32432;
	// lfs f10,-2616(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2616);
	ctx.f10.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// beq 0x82519c64
	if (ctx.cr0.eq) goto loc_82519C64;
	// fmr f12,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = ctx.f10.f64;
	// b 0x82519c68
	goto loc_82519C68;
loc_82519C64:
	// fmr f12,f11
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f11.f64;
loc_82519C68:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
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
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
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
	// beq cr6,0x82519d20
	if (ctx.cr6.eq) goto loc_82519D20;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x82519d24
	goto loc_82519D24;
loc_82519D20:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f11.f64;
loc_82519D24:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,17092(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17092);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32088);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stfs f12,72(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stw r10,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r10.u32);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// stw r10,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r10.u32);
	// stw r11,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r11.u32);
	// stw r11,348(r31)
	REX_STORE_U32(ctx.r31.u32 + 348, ctx.r11.u32);
	// lfs f0,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// lfs f13,312(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stfs f13,320(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8252BD98) {
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
	// addi r11,r11,-2248
	ctx.r11.s64 = ctx.r11.s64 + -2248;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469fb0
	ctx.lr = 0x8252BDBC;
	sub_82469FB0(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4750
	ctx.lr = 0x8252BDC4;
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
	ctx.lr = 0x8252BDD8;
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

DEFINE_REX_FUNC(sub_8252E200) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8252E208;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r4,76(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-1712
	ctx.r11.s64 = ctx.r11.s64 + -1712;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x8252e250
	if (ctx.cr6.eq) goto loc_8252E250;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r3,-12860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -12860);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8252e244
	if (ctx.cr6.eq) goto loc_8252E244;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8246d2e8
	ctx.lr = 0x8252E244;
	sub_8246D2E8(ctx, base);
loc_8252E244:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r29,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r29.u32);
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
loc_8252E250:
	// addi r30,r31,84
	ctx.r30.s64 = ctx.r31.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82524ba8
	ctx.lr = 0x8252E25C;
	sub_82524BA8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82524ba8
	ctx.lr = 0x8252E264;
	sub_82524BA8(ctx, base);
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8252e274
	if (ctx.cr6.eq) goto loc_8252E274;
	// bl 0x825e0378
	ctx.lr = 0x8252E274;
	sub_825E0378(ctx, base);
loc_8252E274:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stw r29,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r29.u32);
	// addi r11,r11,136
	ctx.r11.s64 = ctx.r11.s64 + 136;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825306D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x825306D8;
	__savegprlr_18(ctx, base);
	// stfd f30,-136(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.f30.u64);
	// stfd f31,-128(r1)
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.f31.u64);
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
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
	// bne 0x82530d10
	if (!ctx.cr0.eq) goto loc_82530D10;
	// lfs f0,320(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,320(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 320, temp.u32);
	// addi r29,r11,1612
	ctx.r29.s64 = ctx.r11.s64 + 1612;
	// li r24,1
	ctx.r24.s64 = 1;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lfs f13,-4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82530734
	if (!ctx.cr6.gt) goto loc_82530734;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82530730;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8253079c
	goto loc_8253079C;
loc_82530734:
	// lfs f13,-8024(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -8024);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8253079c
	if (!ctx.cr6.gt) goto loc_8253079C;
	// lbz r11,381(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 381);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8253079c
	if (!ctx.cr0.eq) goto loc_8253079C;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r8,r31,384
	ctx.r8.s64 = ctx.r31.s64 + 384;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82530758:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82530790
	if (ctx.cr6.eq) goto loc_82530790;
	// lwz r10,-12816(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + -12816);
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
	// bne cr6,0x82530790
	if (!ctx.cr6.eq) goto loc_82530790;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82530790
	if (ctx.cr6.eq) goto loc_82530790;
	// stb r24,468(r11)
	REX_STORE_U8(ctx.r11.u32 + 468, ctx.r24.u8);
loc_82530790:
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bdnz 0x82530758
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82530758;
	// stb r24,381(r31)
	REX_STORE_U8(ctx.r31.u32 + 381, ctx.r24.u8);
loc_8253079C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lbz r9,364(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 364);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r25,r11,12236
	ctx.r25.s64 = ctx.r11.s64 + 12236;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// addi r27,r10,32720
	ctx.r27.s64 = ctx.r10.s64 + 32720;
	// addi r26,r11,22072
	ctx.r26.s64 = ctx.r11.s64 + 22072;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lfs f30,232(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 232);
	ctx.f30.f64 = double(temp.f32);
	// bne 0x82530944
	if (!ctx.cr0.eq) goto loc_82530944;
	// lfs f0,312(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// stb r24,364(r31)
	REX_STORE_U8(ctx.r31.u32 + 364, ctx.r24.u8);
	// ble cr6,0x825307dc
	if (!ctx.cr6.gt) goto loc_825307DC;
	// li r28,0
	ctx.r28.s64 = 0;
loc_825307DC:
	// ld r9,44(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,-32640
	ctx.r11.s64 = ctx.r11.s64 + -32640;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lbz r30,80(r31)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lwz r29,88(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r4,336
	ctx.r4.s64 = 336;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
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
	// bl 0x825e02a0
	ctx.lr = 0x825308B4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825308d8
	if (ctx.cr0.eq) goto loc_825308D8;
	// li r8,0
	ctx.r8.s64 = 0;
	// ld r5,96(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// clrlwi r7,r30,24
	ctx.r7.u64 = ctx.r30.u32 & 0xFF;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8254d198
	ctx.lr = 0x825308D4;
	sub_8254D198(ctx, base);
	// b 0x825308dc
	goto loc_825308DC;
loc_825308D8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825308DC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x825308ec
	if (ctx.cr6.eq) goto loc_825308EC;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
loc_825308EC:
	// lwz r10,368(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// stw r11,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x82530998
	if (!ctx.cr6.eq) goto loc_82530998;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r10,-1132
	ctx.r3.s64 = ctx.r10.s64 + -1132;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfs f0,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82229438
	ctx.lr = 0x8253093C;
	sub_82229438(ctx, base);
	// stw r3,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r3.u32);
	// b 0x82530998
	goto loc_82530998;
loc_82530944:
	// lbz r11,380(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 380);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82530998
	if (!ctx.cr0.eq) goto loc_82530998;
	// lwz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82530994
	if (ctx.cr6.eq) goto loc_82530994;
	// lwz r10,-12816(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + -12816);
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
	// bne cr6,0x82530994
	if (!ctx.cr6.eq) goto loc_82530994;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82530994
	if (ctx.cr6.eq) goto loc_82530994;
	// lfs f13,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,196(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 196, temp.u32);
loc_82530994:
	// stb r24,380(r31)
	REX_STORE_U8(ctx.r31.u32 + 380, ctx.r24.u8);
loc_82530998:
	// lfs f0,316(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x82530ce0
	if (!ctx.cr6.lt) goto loc_82530CE0;
	// lbz r11,381(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 381);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825309c8
	if (ctx.cr0.eq) goto loc_825309C8;
	// lfs f0,376(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f0,376(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x825309c8
	if (!ctx.cr6.lt) goto loc_825309C8;
	// stfs f30,376(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
loc_825309C8:
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r28,r11,-31744
	ctx.r28.s64 = ctx.r11.s64 + -31744;
	// lfs f31,1956(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1956);
	ctx.f31.f64 = double(temp.f32);
loc_825309E0:
	// addi r11,r29,96
	ctx.r11.s64 = ctx.r29.s64 + 96;
	// rlwinm r30,r11,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r30,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r31.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82530c04
	if (!ctx.cr6.eq) goto loc_82530C04;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,9936
	ctx.r4.s64 = 9936;
	// bne cr6,0x82530a68
	if (!ctx.cr6.eq) goto loc_82530A68;
	// bl 0x825e02a0
	ctx.lr = 0x82530A0C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82530a50
	if (ctx.cr0.eq) goto loc_82530A50;
	// lbz r11,81(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// li r10,1
	ctx.r10.s64 = 1;
	// ld r9,44(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lfs f1,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f1.f64 = double(temp.f32);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// fmr f3,f30
	ctx.f3.f64 = ctx.f30.f64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// std r9,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r9.u64);
	// bl 0x82531458
	ctx.lr = 0x82530A4C;
	sub_82531458(ctx, base);
	// b 0x82530a54
	goto loc_82530A54;
loc_82530A50:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82530A54:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82530c04
	if (ctx.cr6.eq) goto loc_82530C04;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// b 0x82530c04
	goto loc_82530C04;
loc_82530A68:
	// bl 0x825e02a0
	ctx.lr = 0x82530A6C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82530be8
	if (ctx.cr0.eq) goto loc_82530BE8;
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// lfs f1,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f1.f64 = double(temp.f32);
	// addi r11,r1,256
	ctx.r11.s64 = ctx.r1.s64 + 256;
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,256(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// stfs f1,268(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// ld r8,44(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// stfs f1,264(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,272
	ctx.r8.s64 = ctx.r1.s64 + 272;
	// stfs f1,260(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// addi r10,r29,-1
	ctx.r10.s64 = ctx.r29.s64 + -1;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,352
	ctx.r7.s64 = ctx.r1.s64 + 352;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lfs f0,288(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f0.f64 = double(temp.f32);
	// std r10,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r10.u64);
	// lvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r1,224
	ctx.r23.s64 = ctx.r1.s64 + 224;
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// addi r21,r1,304
	ctx.r21.s64 = ctx.r1.s64 + 304;
	// stfs f0,280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// addi r22,r1,192
	ctx.r22.s64 = ctx.r1.s64 + 192;
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// addi r20,r1,208
	ctx.r20.s64 = ctx.r1.s64 + 208;
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// ld r5,44(r31)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r18,r1,240
	ctx.r18.s64 = ctx.r1.s64 + 240;
	// lfd f13,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// lbz r19,81(r31)
	ctx.r19.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// lfs f0,320(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// std r5,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r5.u64);
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stfs f0,236(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r8,r1,336
	ctx.r8.s64 = ctx.r1.s64 + 336;
	// lvx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stw r19,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r19.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lfs f0,352(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lfs f0,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v62,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,1364(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 1364);
	ctx.f3.f64 = double(temp.f32);
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
	// fmuls f2,f12,f31
	ctx.f2.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// lvx128 v63,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,252(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lvx128 v61,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,336(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 336);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,368(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// bl 0x82531458
	ctx.lr = 0x82530BE4;
	sub_82531458(ctx, base);
	// b 0x82530bec
	goto loc_82530BEC;
loc_82530BE8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82530BEC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82530c04
	if (ctx.cr6.eq) goto loc_82530C04;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stwx r11,r30,r31
	REX_STORE_U32(ctx.r30.u32 + ctx.r31.u32, ctx.r11.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// stw r11,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
loc_82530C04:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// blt cr6,0x825309e0
	if (ctx.cr6.lt) goto loc_825309E0;
	// lbz r11,372(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 372);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82530ca0
	if (!ctx.cr0.eq) goto loc_82530CA0;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r10,-1112
	ctx.r3.s64 = ctx.r10.s64 + -1112;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x82229438
	ctx.lr = 0x82530C5C;
	sub_82229438(ctx, base);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r10,-1092
	ctx.r3.s64 = ctx.r10.s64 + -1092;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f13.u64);
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x82229438
	ctx.lr = 0x82530C9C;
	sub_82229438(ctx, base);
	// stb r24,372(r31)
	REX_STORE_U8(ctx.r31.u32 + 372, ctx.r24.u8);
loc_82530CA0:
	// lwz r3,368(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82530cb4
	if (!ctx.cr6.eq) goto loc_82530CB4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82530cb8
	goto loc_82530CB8;
loc_82530CB4:
	// bl 0x82576728
	ctx.lr = 0x82530CB8;
	sub_82576728(ctx, base);
loc_82530CB8:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82530d10
	if (ctx.cr0.eq) goto loc_82530D10;
	// lwz r3,368(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82530cd4
	if (ctx.cr6.eq) goto loc_82530CD4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825765f0
	ctx.lr = 0x82530CD4;
	sub_825765F0(ctx, base);
loc_82530CD4:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// b 0x82530d10
	goto loc_82530D10;
loc_82530CE0:
	// fsubs f13,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// lfs f0,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,316(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f13,376(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// fcmpu cr6,f13,f30
	ctx.cr6.compare(ctx.f13.f64, ctx.f30.f64);
	// bge cr6,0x82530d00
	if (!ctx.cr6.lt) goto loc_82530D00;
	// stfs f30,376(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
loc_82530D00:
	// lfs f13,376(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82530d10
	if (!ctx.cr6.gt) goto loc_82530D10;
	// stfs f0,376(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
loc_82530D10:
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// lfd f30,-136(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825602A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x825602B0;
	__savegprlr_21(ctx, base);
	// stfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f29.u64);
	// stfd f30,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f30.u64);
	// stfd f31,-104(r1)
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,288(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 288);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// li r23,4
	ctx.r23.s64 = 4;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825602e8
	if (ctx.cr0.eq) goto loc_825602E8;
	// lwz r11,292(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 292);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x825602e8
	if (ctx.cr6.eq) goto loc_825602E8;
	// stw r23,292(r3)
	REX_STORE_U32(ctx.r3.u32 + 292, ctx.r23.u32);
loc_825602E8:
	// lbz r11,289(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 289);
	// li r25,1
	ctx.r25.s64 = 1;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825602fc
	if (ctx.cr0.eq) goto loc_825602FC;
	// stb r25,409(r31)
	REX_STORE_U8(ctx.r31.u32 + 409, ctx.r25.u8);
loc_825602FC:
	// lwz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r22,-32240
	ctx.r22.s64 = -2112880640;
	// addi r24,r10,15656
	ctx.r24.s64 = ctx.r10.s64 + 15656;
	// addi r21,r9,-32688
	ctx.r21.s64 = ctx.r9.s64 + -32688;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82560e04
	if (ctx.cr6.lt) goto loc_82560E04;
	// beq cr6,0x82560ca8
	if (ctx.cr6.eq) goto loc_82560CA8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x825607b4
	if (ctx.cr6.lt) goto loc_825607B4;
	// beq cr6,0x8256033c
	if (ctx.cr6.eq) goto loc_8256033C;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x82560ee4
	if (!ctx.cr6.lt) goto loc_82560EE4;
	// stb r25,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r25.u8);
	// b 0x82560ee4
	goto loc_82560EE4;
loc_8256033C:
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82560398
	if (ctx.cr6.eq) goto loc_82560398;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x82560354;
	sub_82222D88(ctx, base);
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8256037C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82560394;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r3,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r3.u8);
loc_82560398:
	// lwz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82560708
	if (ctx.cr6.lt) goto loc_82560708;
	// beq cr6,0x82560478
	if (ctx.cr6.eq) goto loc_82560478;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82560ee4
	if (!ctx.cr6.lt) goto loc_82560EE4;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,340(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,17092
	ctx.r11.s64 = ctx.r11.s64 + 17092;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lfs f0,23804(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23804);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r31,324
	ctx.r11.s64 = ctx.r31.s64 + 324;
	// fmuls f4,f13,f0
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f4,156(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f4,152(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f4,148(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f4,144(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f4,340(r31)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// lfs f0,324(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
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
	// lfs f13,328(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 328);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
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
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
	// lfs f2,324(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,328(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 328);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a7c80
	ctx.lr = 0x82560458;
	sub_825A7C80(ctx, base);
	// lfs f0,344(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f0.f64 = double(temp.f32);
	// stfs f1,376(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// fcmpu cr6,f4,f0
	ctx.cr6.compare(ctx.f4.f64, ctx.f0.f64);
	// bge cr6,0x82560ee4
	if (!ctx.cr6.lt) goto loc_82560EE4;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r10,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r10.u32);
	// b 0x82560ee0
	goto loc_82560EE0;
loc_82560478:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82561028
	ctx.lr = 0x82560480;
	sub_82561028(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r29,r31,316
	ctx.r29.s64 = ctx.r31.s64 + 316;
	// addi r28,r11,17092
	ctx.r28.s64 = ctx.r11.s64 + 17092;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r30,r31,44
	ctx.r30.s64 = ctx.r31.s64 + 44;
	// lfs f3,-21624(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -21624);
	ctx.f3.f64 = double(temp.f32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x82561200
	ctx.lr = 0x825604A8;
	sub_82561200(ctx, base);
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lfs f1,376(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8223eea0
	ctx.lr = 0x825604B4;
	sub_8223EEA0(ctx, base);
	// stfs f1,376(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x825604BC;
	sub_82738CC0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,324(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// lfs f1,376(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82738be0
	ctx.lr = 0x825604CC;
	sub_82738BE0(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,24624
	ctx.r10.s64 = ctx.r11.s64 + 24624;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,328(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 328, temp.u32);
	// lfs f12,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,24624(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,10784(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 10784);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f13,340(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x825604fc
	if (!ctx.cr6.gt) goto loc_825604FC;
	// stfs f0,340(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
loc_825604FC:
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lfs f0,328(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 328);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lfs f13,324(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stfs f13,200(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f12,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,192(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f12,188(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f13,204(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f12,180(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,352(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 352);
	ctx.f0.f64 = double(temp.f32);
	// fadds f11,f29,f0
	ctx.f11.f64 = double(float(ctx.f29.f64 + ctx.f0.f64));
	// stfs f11,352(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 352, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
	// bl 0x82322d08
	ctx.lr = 0x8256059C;
	sub_82322D08(ctx, base);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,204(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f13,200(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f13,192(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v0,v0,v12,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lfs f12,-29492(r22)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -29492);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// blt cr6,0x82560630
	if (ctx.cr6.lt) goto loc_82560630;
	// lfs f0,-23504(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -23504);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// ble cr6,0x82560644
	if (!ctx.cr6.gt) goto loc_82560644;
loc_82560630:
	// lwz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// lfs f0,-3188(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -3188);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,352(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 352, temp.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
loc_82560644:
	// lbz r11,409(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 409);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82560ee4
	if (ctx.cr0.eq) goto loc_82560EE4;
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82560678
	if (ctx.cr6.eq) goto loc_82560678;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x8256066C;
	sub_82222D88(ctx, base);
	// addi r11,r3,60
	ctx.r11.s64 = ctx.r3.s64 + 60;
	// stb r27,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r27.u8);
	// stb r27,25(r11)
	REX_STORE_U8(ctx.r11.u32 + 25, ctx.r27.u8);
loc_82560678:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82560694;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lfs f0,10320(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 10320);
	ctx.f0.f64 = double(temp.f32);
	// li r30,255
	ctx.r30.s64 = 255;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f0,f29,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f29.f64, ctx.f0.f64, -ctx.f13.f64)));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_825606C8:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// blt cr6,0x82560c80
	if (ctx.cr6.lt) goto loc_82560C80;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82560c80
	if (ctx.cr6.eq) goto loc_82560C80;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82560704;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82560ee4
	goto loc_82560EE4;
loc_82560708:
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r5,r31,44
	ctx.r5.s64 = ctx.r31.s64 + 44;
	// stb r27,416(r31)
	REX_STORE_U8(ctx.r31.u32 + 416, ctx.r27.u8);
	// addi r4,r31,316
	ctx.r4.s64 = ctx.r31.s64 + 316;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82322d08
	ctx.lr = 0x82560720;
	sub_82322D08(ctx, base);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,-3188(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -3188);
	ctx.f31.f64 = double(temp.f32);
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8256075c
	if (!ctx.cr6.lt) goto loc_8256075C;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8256075C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bne 0x82560780
	if (!ctx.cr0.eq) goto loc_82560780;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82560780:
	// bctrl 
	ctx.lr = 0x82560784;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r4,r31,68
	ctx.r4.s64 = ctx.r31.s64 + 68;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8231e0d8
	ctx.lr = 0x82560790;
	sub_8231E0D8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r10,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r10.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f31,352(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 352, temp.u32);
	// stw r11,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
	// stw r10,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r10.u32);
	// b 0x82560ee4
	goto loc_82560EE4;
loc_825607B4:
	// lbz r10,417(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 417);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r26,r11,3456
	ctx.r26.s64 = ctx.r11.s64 + 3456;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82560838
	if (ctx.cr0.eq) goto loc_82560838;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// addi r4,r31,424
	ctx.r4.s64 = ctx.r31.s64 + 424;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r11,316(r31)
	REX_STORE_U64(ctx.r31.u32 + 316, ctx.r11.u64);
	// bl 0x8255ffc0
	ctx.lr = 0x825607E0;
	sub_8255FFC0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82560834
	if (ctx.cr0.eq) goto loc_82560834;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwinm r10,r3,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x82560818
	if (!ctx.cr6.eq) goto loc_82560818;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// bne cr6,0x8256081c
	if (!ctx.cr6.eq) goto loc_8256081C;
loc_82560818:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8256081C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82560834
	if (ctx.cr0.eq) goto loc_82560834;
	// stw r3,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r3.u32);
	// stb r25,416(r31)
	REX_STORE_U8(ctx.r31.u32 + 416, ctx.r25.u8);
	// stb r27,417(r31)
	REX_STORE_U8(ctx.r31.u32 + 417, ctx.r27.u8);
	// b 0x82560838
	goto loc_82560838;
loc_82560834:
	// stw r27,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r27.u32);
loc_82560838:
	// lfs f0,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 356);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// stfs f0,356(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 356, temp.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x825608b0
	if (ctx.cr6.eq) goto loc_825608B0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x8256085C;
	sub_82222D88(ctx, base);
	// lfs f13,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 356);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-1376(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -1376);
	ctx.f0.f64 = double(temp.f32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x825608b0
	if (!ctx.cr6.gt) goto loc_825608B0;
	// lfs f0,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,136
	ctx.r4.s64 = ctx.r1.s64 + 136;
	// lfs f13,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82560894;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825608AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r3,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r3.u8);
loc_825608B0:
	// lfs f12,-1280(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -1280);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// lfs f0,344(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x825608d0
	if (!ctx.cr6.gt) goto loc_825608D0;
	// stfs f11,340(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// b 0x825608e8
	goto loc_825608E8;
loc_825608D0:
	// fsubs f13,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x825608e4
	if (!ctx.cr6.lt) goto loc_825608E4;
	// stfs f13,340(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// b 0x825608e8
	goto loc_825608E8;
loc_825608E4:
	// stfs f0,340(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
loc_825608E8:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// addi r3,r1,92
	ctx.r3.s64 = ctx.r1.s64 + 92;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82560904;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r30,255
	ctx.r30.s64 = 255;
	// lfs f0,-20940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20940);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmadds f0,f29,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, ctx.f13.f64)));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82560978
	if (!ctx.cr6.gt) goto loc_82560978;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// stb r30,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r30.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82560970;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r25,408(r31)
	REX_STORE_U8(ctx.r31.u32 + 408, ctx.r25.u8);
	// b 0x82560a00
	goto loc_82560A00;
loc_82560978:
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bge cr6,0x825609a4
	if (!ctx.cr6.lt) goto loc_825609A4;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
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
	ctx.lr = 0x825609A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82560a00
	goto loc_82560A00;
loc_825609A4:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// stb r30,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r30.u8);
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
	ctx.lr = 0x825609C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 408);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82560a00
	if (!ctx.cr0.eq) goto loc_82560A00;
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// stb r25,408(r31)
	REX_STORE_U8(ctx.r31.u32 + 408, ctx.r25.u8);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82560a00
	if (ctx.cr6.eq) goto loc_82560A00;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x825609EC;
	sub_82222D88(ctx, base);
	// lfs f3,-3184(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -3184);
	ctx.f3.f64 = double(temp.f32);
	// addi r3,r3,60
	ctx.r3.s64 = ctx.r3.s64 + 60;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82224038
	ctx.lr = 0x82560A00;
	sub_82224038(ctx, base);
loc_82560A00:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r4,404(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82560A1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f2,-568(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -568);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r28,r11,17092
	ctx.r28.s64 = ctx.r11.s64 + 17092;
	// lfs f1,-12656(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -12656);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82560A34;
	sub_825A4A40(ctx, base);
	// addi r29,r31,44
	ctx.r29.s64 = ctx.r31.s64 + 44;
	// lfs f0,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-568(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -568);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r31,308
	ctx.r4.s64 = ctx.r31.s64 + 308;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmadds f11,f1,f0,f13
	ctx.f11.f64 = double(float(std::fma(ctx.f1.f64, ctx.f0.f64, ctx.f13.f64)));
	// lfs f1,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82561148
	ctx.lr = 0x82560A54;
	sub_82561148(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f3,-21624(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -21624);
	ctx.f3.f64 = double(temp.f32);
	// fadds f31,f1,f11
	ctx.f31.f64 = double(float(ctx.f1.f64 + ctx.f11.f64));
	// bl 0x82561200
	ctx.lr = 0x82560A64;
	sub_82561200(ctx, base);
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lfs f1,376(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8223eea0
	ctx.lr = 0x82560A70;
	sub_8223EEA0(ctx, base);
	// stfs f1,376(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x82560A78;
	sub_82738CC0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// lfs f1,376(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82738be0
	ctx.lr = 0x82560A8C;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// li r11,200
	ctx.r11.s64 = 200;
	// lfs f30,-3188(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -3188);
	ctx.f30.f64 = double(temp.f32);
	// lfs f2,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// rotlwi r29,r11,0
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lfs f0,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f29.f64));
	// stfs f0,380(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4a40
	ctx.lr = 0x82560AC4;
	sub_825A4A40(ctx, base);
	// extsw r11,r29
	ctx.r11.s64 = ctx.r29.s32;
	// twllei r29,0
	if (ctx.r29.s32 == 0 || ctx.r29.u32 < 0u) ppc_trap(ctx, base, 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rotlwi r11,r10,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r9,r10,r29
	ctx.r9.u64 = uint32_t((ctx.r29.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r29.s32 == -1)) ? ctx.r10.s32 / ctx.r29.s32 : 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mullw r9,r9,r29
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r29.s32);
	// andc r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 & ~ctx.r11.u64;
	// subf. r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// twlgei r11,-1
	if (ctx.r11.s32 == -1 || ctx.r11.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// bne 0x82560b28
	if (!ctx.cr0.eq) goto loc_82560B28;
	// lbz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 408);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82560b28
	if (ctx.cr0.eq) goto loc_82560B28;
	// lfs f0,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bgt cr6,0x82560b28
	if (ctx.cr6.gt) goto loc_82560B28;
	// stb r25,417(r31)
	REX_STORE_U8(ctx.r31.u32 + 417, ctx.r25.u8);
loc_82560B28:
	// lbz r11,416(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 416);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82560bf0
	if (ctx.cr0.eq) goto loc_82560BF0;
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lfs f13,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82560bc8
	if (!ctx.cr0.eq) goto loc_82560BC8;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lfs f13,320(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lfs f0,4(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// beq 0x82560bcc
	if (ctx.cr0.eq) goto loc_82560BCC;
loc_82560BC8:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_82560BCC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82560bf0
	if (ctx.cr0.eq) goto loc_82560BF0;
	// lwz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// lfs f0,-23504(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -23504);
	ctx.f0.f64 = double(temp.f32);
	// stfs f31,340(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// stw r27,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r27.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stfs f0,380(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// stw r11,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
loc_82560BF0:
	// lbz r11,289(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 289);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82560c00
	if (ctx.cr0.eq) goto loc_82560C00;
	// stb r25,409(r31)
	REX_STORE_U8(ctx.r31.u32 + 409, ctx.r25.u8);
loc_82560C00:
	// lbz r11,409(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 409);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82560ee4
	if (ctx.cr0.eq) goto loc_82560EE4;
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82560c30
	if (ctx.cr6.eq) goto loc_82560C30;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x82560C24;
	sub_82222D88(ctx, base);
	// addi r11,r3,60
	ctx.r11.s64 = ctx.r3.s64 + 60;
	// stb r27,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r27.u8);
	// stb r27,25(r11)
	REX_STORE_U8(ctx.r11.u32 + 25, ctx.r27.u8);
loc_82560C30:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
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
	ctx.lr = 0x82560C4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lfs f0,10320(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 10320);
	ctx.f0.f64 = double(temp.f32);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f0,f29,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f29.f64, ctx.f0.f64, -ctx.f13.f64)));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x825606c8
	goto loc_825606C8;
loc_82560C80:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// stb r27,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r27.u8);
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
	ctx.lr = 0x82560CA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r23,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r23.u32);
	// b 0x82560ee4
	goto loc_82560EE4;
loc_82560CA8:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r4,404(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82560CC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r11,r11,-30416
	ctx.r11.s64 = ctx.r11.s64 + -30416;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82560d34
	if (!ctx.cr6.eq) goto loc_82560D34;
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
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
	// vxor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_82560D34:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,300
	ctx.r4.s64 = ctx.r31.s64 + 300;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8255f918
	ctx.lr = 0x82560D44;
	sub_8255F918(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,-568(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -568);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r29,r11,17092
	ctx.r29.s64 = ctx.r11.s64 + 17092;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,-3188(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -3188);
	ctx.f1.f64 = double(temp.f32);
	// addi r30,r31,308
	ctx.r30.s64 = ctx.r31.s64 + 308;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// lfs f2,172(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 172);
	ctx.f2.f64 = double(temp.f32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// lwz r10,308(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// stw r11,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r10,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// bl 0x825a4a40
	ctx.lr = 0x82560D88;
	sub_825A4A40(ctx, base);
	// lfs f0,172(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 172);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,344(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 344, temp.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x82561200
	ctx.lr = 0x82560DA8;
	sub_82561200(ctx, base);
	// lwa r10,400(r31)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r31.u32 + 400));
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// stfs f1,376(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// addi r10,r10,24624
	ctx.r10.s64 = ctx.r10.s64 + 24624;
	// lfs f0,5520(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5520);
	ctx.f0.f64 = double(temp.f32);
	// std r8,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// fdivs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f12.f64));
	// lfs f13,32104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 32104);
	ctx.f13.f64 = double(temp.f32);
	// frsp f12,f11
	ctx.f12.f64 = double(float(ctx.f11.f64));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// stfs f0,348(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 348, temp.u32);
	// b 0x82560ed8
	goto loc_82560ED8;
loc_82560E04:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,124
	ctx.r4.s64 = 124;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82560E1C;
	sub_825E02A0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82560e54
	if (ctx.cr0.eq) goto loc_82560E54;
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
	ctx.lr = 0x82560E3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lfs f1,-3420(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -3420);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822409f8
	ctx.lr = 0x82560E4C;
	sub_822409F8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82560e58
	goto loc_82560E58;
loc_82560E54:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82560E58:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82560ed8
	if (ctx.cr6.eq) goto loc_82560ED8;
	// stw r25,112(r30)
	REX_STORE_U32(ctx.r30.u32 + 112, ctx.r25.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r3,r30,60
	ctx.r3.s64 = ctx.r30.s64 + 60;
	// lfs f3,-1376(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -1376);
	ctx.f3.f64 = double(temp.f32);
	// addi r11,r11,17092
	ctx.r11.s64 = ctx.r11.s64 + 17092;
	// lfs f2,-3420(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -3420);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-12652(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12652);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82224038
	ctx.lr = 0x82560E80;
	sub_82224038(ctx, base);
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f1,-3420(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -3420);
	ctx.f1.f64 = double(temp.f32);
	// stb r11,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r11.u8);
	// lwz r11,40(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82560EA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82222ad8
	ctx.lr = 0x82560EAC;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82560ed8
	if (!ctx.cr6.eq) goto loc_82560ED8;
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
	ctx.lr = 0x82560ED8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82560ED8:
	// lwz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82560EE0:
	// stw r11,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
loc_82560EE4:
	// lwz r11,292(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// blt cr6,0x82561014
	if (ctx.cr6.lt) goto loc_82561014;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lvx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lwz r9,404(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// addi r10,r10,-32544
	ctx.r10.s64 = ctx.r10.s64 + -32544;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bne cr6,0x82560f60
	if (!ctx.cr6.eq) goto loc_82560F60;
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
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
	// vxor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
loc_82560F60:
	// lfs f1,348(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82738be0
	ctx.lr = 0x82560F68;
	sub_82738BE0(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfs f0,-29492(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f1,348(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
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
	// bl 0x82738cc0
	ctx.lr = 0x82560F8C;
	sub_82738CC0(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lfs f0,-568(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -568);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lfs f12,348(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// fadds f12,f12,f29
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f29.f64));
	// stfs f12,348(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 348, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r31,300
	ctx.r4.s64 = ctx.r31.s64 + 300;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82560FF4;
	sub_8255F918(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x82561004;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
loc_82561014:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825D1DC8) {
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
	// beq cr6,0x825d1e04
	if (ctx.cr6.eq) goto loc_825D1E04;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32787
	ctx.r4.u64 = ctx.r4.u64 | 32787;
	// bl 0x8263b710
	ctx.lr = 0x825D1E00;
	sub_8263B710(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825D1E04:
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

DEFINE_REX_FUNC(sub_825D7D20) {
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
	// beq cr6,0x825d7d90
	if (ctx.cr6.eq) goto loc_825D7D90;
	// lwz r10,28(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825d7d90
	if (ctx.cr6.eq) goto loc_825D7D90;
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d7d90
	if (ctx.cr6.eq) goto loc_825D7D90;
	// lwz r4,52(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 52);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x825d7d6c
	if (ctx.cr6.eq) goto loc_825D7D6C;
	// lwz r3,40(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825D7D6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825D7D6C:
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r4,28(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r3,40(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825D7D80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// b 0x825d7d94
	goto loc_825D7D94;
loc_825D7D90:
	// li r3,-2
	ctx.r3.s64 = -2;
loc_825D7D94:
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

DEFINE_REX_FUNC(sub_825DC610) {
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
	// lwz r10,5820(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 5820);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// lhz r9,5816(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 5816);
	// cmpwi cr6,r10,11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 11, ctx.xer);
	// ble cr6,0x825dc69c
	if (!ctx.cr6.gt) goto loc_825DC69C;
	// addi r11,r4,-257
	ctx.r11.s64 = ctx.r4.s64 + -257;
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r7,8(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// slw r10,r11,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r11,5816(r3)
	REX_STORE_U16(ctx.r3.u32 + 5816, ctx.r11.u16);
	// stbx r11,r8,r7
	REX_STORE_U8(ctx.r8.u32 + ctx.r7.u32, ctx.r11.u8);
	// lbz r10,5816(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 5816);
	// lwz r8,8(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stbx r10,r11,r8
	REX_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r10.u8);
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r11,5820(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 5820);
	// subfic r8,r11,16
	ctx.xer.ca = ctx.r11.u32 <= 16;
	ctx.r8.u64 = static_cast<uint64_t>(16) - ctx.r11.u64;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,-11
	ctx.r11.s64 = ctx.r11.s64 + -11;
	// srw r9,r9,r8
	ctx.r9.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stw r11,5820(r3)
	REX_STORE_U32(ctx.r3.u32 + 5820, ctx.r11.u32);
	// sth r9,5816(r3)
	REX_STORE_U16(ctx.r3.u32 + 5816, ctx.r9.u16);
	// b 0x825dc6b8
	goto loc_825DC6B8;
loc_825DC69C:
	// addis r11,r4,1
	ctx.r11.s64 = ctx.r4.s64 + 65536;
	// addi r8,r10,5
	ctx.r8.s64 = ctx.r10.s64 + 5;
	// addi r11,r11,-257
	ctx.r11.s64 = ctx.r11.s64 + -257;
	// stw r8,5820(r3)
	REX_STORE_U32(ctx.r3.u32 + 5820, ctx.r8.u32);
	// slw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// or r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 | ctx.r9.u64;
	// sth r11,5816(r3)
	REX_STORE_U16(ctx.r3.u32 + 5816, ctx.r11.u16);
loc_825DC6B8:
	// lwz r10,5820(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 5820);
	// lhz r9,5816(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 5816);
	// cmpwi cr6,r10,11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 11, ctx.xer);
	// ble cr6,0x825dc730
	if (!ctx.cr6.gt) goto loc_825DC730;
	// addi r11,r31,-1
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r7,8(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// slw r10,r11,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r11,5816(r3)
	REX_STORE_U16(ctx.r3.u32 + 5816, ctx.r11.u16);
	// stbx r11,r8,r7
	REX_STORE_U8(ctx.r8.u32 + ctx.r7.u32, ctx.r11.u8);
	// lbz r10,5816(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 5816);
	// lwz r8,8(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stbx r10,r11,r8
	REX_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r10.u8);
	// lwz r11,5820(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 5820);
	// subfic r10,r11,16
	ctx.xer.ca = ctx.r11.u32 <= 16;
	ctx.r10.u64 = static_cast<uint64_t>(16) - ctx.r11.u64;
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// addi r11,r11,-11
	ctx.r11.s64 = ctx.r11.s64 + -11;
	// srw r10,r9,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// stw r11,5820(r3)
	REX_STORE_U32(ctx.r3.u32 + 5820, ctx.r11.u32);
	// sth r10,5816(r3)
	REX_STORE_U16(ctx.r3.u32 + 5816, ctx.r10.u16);
	// b 0x825dc74c
	goto loc_825DC74C;
loc_825DC730:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r8,r10,5
	ctx.r8.s64 = ctx.r10.s64 + 5;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r8,5820(r3)
	REX_STORE_U32(ctx.r3.u32 + 5820, ctx.r8.u32);
	// slw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// or r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 | ctx.r9.u64;
	// sth r11,5816(r3)
	REX_STORE_U16(ctx.r3.u32 + 5816, ctx.r11.u16);
loc_825DC74C:
	// lwz r10,5820(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 5820);
	// lhz r9,5816(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 5816);
	// cmpwi cr6,r10,12
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 12, ctx.xer);
	// ble cr6,0x825dc7c0
	if (!ctx.cr6.gt) goto loc_825DC7C0;
	// addi r11,r6,-4
	ctx.r11.s64 = ctx.r6.s64 + -4;
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r7,8(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// slw r10,r11,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r11,5816(r3)
	REX_STORE_U16(ctx.r3.u32 + 5816, ctx.r11.u16);
	// stbx r11,r8,r7
	REX_STORE_U8(ctx.r8.u32 + ctx.r7.u32, ctx.r11.u8);
	// lwz r8,8(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r10,5816(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 5816);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stbx r10,r11,r8
	REX_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r10.u8);
	// lwz r11,5820(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 5820);
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// subfic r8,r11,16
	ctx.xer.ca = ctx.r11.u32 <= 16;
	ctx.r8.u64 = static_cast<uint64_t>(16) - ctx.r11.u64;
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// stw r11,5820(r3)
	REX_STORE_U32(ctx.r3.u32 + 5820, ctx.r11.u32);
	// srw r11,r9,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// b 0x825dc7d8
	goto loc_825DC7D8;
loc_825DC7C0:
	// addis r11,r6,1
	ctx.r11.s64 = ctx.r6.s64 + 65536;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// stw r8,5820(r3)
	REX_STORE_U32(ctx.r3.u32 + 5820, ctx.r8.u32);
	// slw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r10.u8 & 0x3F));
	// or r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 | ctx.r9.u64;
loc_825DC7D8:
	// sth r11,5816(r3)
	REX_STORE_U16(ctx.r3.u32 + 5816, ctx.r11.u16);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble cr6,0x825dc894
	if (!ctx.cr6.gt) goto loc_825DC894;
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// addi r8,r11,32196
	ctx.r8.s64 = ctx.r11.s64 + 32196;
loc_825DC7F4:
	// lbzx r10,r9,r8
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// lwz r11,5820(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 5820);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// cmpwi cr6,r11,13
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 13, ctx.xer);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lhz r10,2686(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 2686);
	// ble cr6,0x825dc874
	if (!ctx.cr6.gt) goto loc_825DC874;
	// slw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// lhz r7,5816(r3)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r3.u32 + 5816);
	// or r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 | ctx.r7.u64;
	// lwz r6,20(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r5,8(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r11,5816(r3)
	REX_STORE_U16(ctx.r3.u32 + 5816, ctx.r11.u16);
	// stbx r11,r6,r5
	REX_STORE_U8(ctx.r6.u32 + ctx.r5.u32, ctx.r11.u8);
	// lbz r6,5816(r3)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r3.u32 + 5816);
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stbx r6,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r6.u8);
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r11,5820(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 5820);
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// subfic r10,r11,16
	ctx.xer.ca = ctx.r11.u32 <= 16;
	ctx.r10.u64 = static_cast<uint64_t>(16) - ctx.r11.u64;
	// addi r11,r11,-13
	ctx.r11.s64 = ctx.r11.s64 + -13;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r11,5820(r3)
	REX_STORE_U32(ctx.r3.u32 + 5820, ctx.r11.u32);
	// srw r11,r7,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r10.u8 & 0x3F));
	// b 0x825dc888
	goto loc_825DC888;
loc_825DC874:
	// addi r7,r11,3
	ctx.r7.s64 = ctx.r11.s64 + 3;
	// lhz r6,5816(r3)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r3.u32 + 5816);
	// slw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// stw r7,5820(r3)
	REX_STORE_U32(ctx.r3.u32 + 5820, ctx.r7.u32);
	// or r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 | ctx.r6.u64;
loc_825DC888:
	// sth r11,5816(r3)
	REX_STORE_U16(ctx.r3.u32 + 5816, ctx.r11.u16);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x825dc7f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825DC7F4;
loc_825DC894:
	// addi r5,r4,-1
	ctx.r5.s64 = ctx.r4.s64 + -1;
	// addi r4,r3,148
	ctx.r4.s64 = ctx.r3.s64 + 148;
	// bl 0x825dc0c0
	ctx.lr = 0x825DC8A0;
	sub_825DC0C0(ctx, base);
	// addi r4,r3,2440
	ctx.r4.s64 = ctx.r3.s64 + 2440;
	// addi r5,r31,-1
	ctx.r5.s64 = ctx.r31.s64 + -1;
	// bl 0x825dc0c0
	ctx.lr = 0x825DC8AC;
	sub_825DC0C0(ctx, base);
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

DEFINE_REX_FUNC(sub_825ED700) {
	REX_FUNC_PROLOGUE();
	// lwz r11,552(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 552);
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bne cr6,0x825ed714
	if (!ctx.cr6.eq) goto loc_825ED714;
	// lwz r10,556(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 556);
	// b 0x825ed75c
	goto loc_825ED75C;
loc_825ED714:
	// lwz r11,520(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 520);
	// stw r4,552(r3)
	REX_STORE_U32(ctx.r3.u32 + 552, ctx.r4.u32);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x825ed740
	if (!ctx.cr6.lt) goto loc_825ED740;
	// lwz r10,516(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 516);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x825ed758
	if (ctx.cr6.eq) goto loc_825ED758;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
loc_825ED734:
	// lwz r10,116(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 116);
	// bdnz 0x825ed734
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825ED734;
	// b 0x825ed758
	goto loc_825ED758;
loc_825ED740:
	// lwz r10,532(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 532);
	// subf. r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825ed758
	if (ctx.cr0.eq) goto loc_825ED758;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_825ED750:
	// lwz r10,116(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 116);
	// bdnz 0x825ed750
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825ED750;
loc_825ED758:
	// stw r10,556(r3)
	REX_STORE_U32(ctx.r3.u32 + 556, ctx.r10.u32);
loc_825ED75C:
	// lwz r11,16(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// mulli r9,r5,24
	ctx.r9.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(24));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// stw r9,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
	// lwz r9,20(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// stw r9,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// ld r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r9,8(r6)
	REX_STORE_U64(ctx.r6.u32 + 8, ctx.r9.u64);
	// ld r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// std r11,16(r6)
	REX_STORE_U64(ctx.r6.u32 + 16, ctx.r11.u64);
	// lwz r11,32(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// stw r11,24(r6)
	REX_STORE_U32(ctx.r6.u32 + 24, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825F30D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825F30D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,6(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 6);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825f3198
	if (ctx.cr0.eq) goto loc_825F3198;
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825f3198
	if (ctx.cr0.eq) goto loc_825F3198;
	// lhz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 4);
	// lhz r10,4(r5)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r5.u32 + 4);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x8273c6c0
	ctx.lr = 0x825F3110;
	sub_8273C6C0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x825f3240
	if (ctx.cr0.eq) goto loc_825F3240;
	// lbz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 6);
	// li r4,0
	ctx.r4.s64 = 0;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825f312c
	if (ctx.cr0.eq) goto loc_825F312C;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_825F312C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lhz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// bl 0x8263a4c0
	ctx.lr = 0x825F3138;
	sub_8263A4C0(ctx, base);
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbz r11,6(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 6);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825f3154
	if (ctx.cr0.eq) goto loc_825F3154;
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
loc_825F3154:
	// lhz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 4);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8263a4c0
	ctx.lr = 0x825F3160;
	sub_8263A4C0(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_825F3164:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825f3164
	if (!ctx.cr6.eq) goto loc_825F3164;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// stw r30,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r10,6(r28)
	REX_STORE_U8(ctx.r28.u32 + 6, ctx.r10.u8);
	// sth r11,4(r28)
	REX_STORE_U16(ctx.r28.u32 + 4, ctx.r11.u16);
	// stw r9,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r9.u32);
	// b 0x825f3250
	goto loc_825F3250;
loc_825F3198:
	// rlwinm. r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825f3240
	if (ctx.cr0.eq) goto loc_825F3240;
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825f3240
	if (ctx.cr0.eq) goto loc_825F3240;
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r29.u32 + 4);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x8273c6c0
	ctx.lr = 0x825F31C0;
	sub_8273C6C0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x825f3240
	if (ctx.cr0.eq) goto loc_825F3240;
	// lbz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 6);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825f31dc
	if (ctx.cr0.eq) goto loc_825F31DC;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_825F31DC:
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rotlwi r5,r11,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// bl 0x8263a4c0
	ctx.lr = 0x825F31EC;
	sub_8263A4C0(ctx, base);
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// lbz r10,6(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 6);
	// li r4,0
	ctx.r4.s64 = 0;
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// rlwinm. r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// beq 0x825f320c
	if (ctx.cr0.eq) goto loc_825F320C;
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
loc_825F320C:
	// lhz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x8263a4c0
	ctx.lr = 0x825F321C;
	sub_8263A4C0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273a560
	ctx.lr = 0x825F3224;
	sub_8273A560(ctx, base);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r30,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
	// sth r3,4(r28)
	REX_STORE_U16(ctx.r28.u32 + 4, ctx.r3.u16);
	// stb r10,6(r28)
	REX_STORE_U8(ctx.r28.u32 + 6, ctx.r10.u8);
	// stw r9,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r9.u32);
	// b 0x825f3250
	goto loc_825F3250;
loc_825F3240:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r4,r11,31418
	ctx.r4.s64 = ctx.r11.s64 + 31418;
	// bl 0x825e4958
	ctx.lr = 0x825F3250;
	sub_825E4958(ctx, base);
loc_825F3250:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FB150) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// addi r10,r3,144
	ctx.r10.s64 = ctx.r3.s64 + 144;
	// lis r7,-32114
	ctx.r7.s64 = -2104623104;
	// addi r11,r10,4
	ctx.r11.s64 = ctx.r10.s64 + 4;
	// addi r8,r10,-20
	ctx.r8.s64 = ctx.r10.s64 + -20;
	// li r9,8
	ctx.r9.s64 = 8;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r7,11048
	ctx.r7.s64 = ctx.r7.s64 + 11048;
loc_825FB16C:
	// stw r10,20(r8)
	REX_STORE_U32(ctx.r8.u32 + 20, ctx.r10.u32);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lwz r5,0(r7)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// lwz r5,4(r7)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// lwz r5,8(r7)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// stw r5,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
	// lwz r6,12(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// stw r6,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// stwu r10,20(r8)
	ea = 20 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r8.u32 = ea;
	// bne 0x825fb16c
	if (!ctx.cr0.eq) goto loc_825FB16C;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// sth r10,8(r3)
	REX_STORE_U16(ctx.r3.u32 + 8, ctx.r10.u16);
	// stw r10,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825FE440) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x825FE448;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r25,r11,-15400
	ctx.r25.s64 = ctx.r11.s64 + -15400;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x825FE460;
	sub_825F8ED0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r11,-15408
	ctx.r29.s64 = ctx.r11.s64 + -15408;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825fe4b0
	if (!ctx.cr6.eq) goto loc_825FE4B0;
	// lwsync 
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
loc_825FE480:
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
	// stwcx. r30,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r30.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825fe480
	if (!ctx.cr0.eq) goto loc_825FE480;
	// bl 0x826073b8
	ctx.lr = 0x825FE49C;
	sub_826073B8(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x825FE4A4;
	sub_825F8ED0(ctx, base);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825fe54c
	if (ctx.cr6.eq) goto loc_825FE54C;
loc_825FE4B0:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// subf r10,r29,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r29.u64;
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825fe4e8
	if (ctx.cr0.eq) goto loc_825FE4E8;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_825FE4E8:
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and. r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x825fe54c
	if (ctx.cr0.eq) goto loc_825FE54C;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,-15396(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -15396);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-15396(r28)
	REX_STORE_U32(ctx.r28.u32 + -15396, ctx.r11.u32);
	// bl 0x8260f3b8
	ctx.lr = 0x825FE518;
	sub_8260F3B8(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x825fe580
	if (ctx.cr0.eq) goto loc_825FE580;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,16
	ctx.r6.s64 = 16;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8260f680
	ctx.lr = 0x825FE538;
	sub_8260F680(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x825fe574
	if (!ctx.cr0.eq) goto loc_825FE574;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8260f420
	ctx.lr = 0x825FE548;
	sub_8260F420(ctx, base);
	// b 0x825fe580
	goto loc_825FE580;
loc_825FE54C:
	// lwsync 
loc_825FE550:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r25
	ea = ctx.r25.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r30,0,r25
	ea = ctx.r25.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r30.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825fe550
	if (!ctx.cr0.eq) goto loc_825FE550;
	// li r3,0
	ctx.r3.s64 = 0;
loc_825FE56C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_825FE574:
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x825fe604
	if (!ctx.cr6.eq) goto loc_825FE604;
loc_825FE580:
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// addi r9,r31,28
	ctx.r9.s64 = ctx.r31.s64 + 28;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
loc_825FE594:
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
	// stwcx. r30,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r30.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825fe594
	if (!ctx.cr0.eq) goto loc_825FE594;
	// lwsync 
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,-15396(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + -15396);
	// addi r10,r31,12
	ctx.r10.s64 = ctx.r31.s64 + 12;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r9,-15396(r28)
	REX_STORE_U32(ctx.r28.u32 + -15396, ctx.r9.u32);
	// stw r8,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_825FE5E4:
	// lwsync 
loc_825FE5E8:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r25
	ea = ctx.r25.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r30,0,r25
	ea = ctx.r25.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r30.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825fe5e8
	if (!ctx.cr0.eq) goto loc_825FE5E8;
	// b 0x825fe56c
	goto loc_825FE56C;
loc_825FE604:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,-11552(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -11552);
	// cmplwi cr6,r11,8191
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8191, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// blt cr6,0x825fe620
	if (ctx.cr6.lt) goto loc_825FE620;
	// li r11,1
	ctx.r11.s64 = 1;
loc_825FE620:
	// stw r11,-11552(r10)
	REX_STORE_U32(ctx.r10.u32 + -11552, ctx.r11.u32);
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// clrlwi r9,r9,17
	ctx.r9.u64 = ctx.r9.u32 & 0x7FFF;
	// stw r8,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
	// rlwimi r10,r11,15,4,16
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFFF8000) | (ctx.r10.u64 & 0xFFFFFFFFF0007FFF);
	// stw r26,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r9,r31,28
	ctx.r9.s64 = ctx.r31.s64 + 28;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_825FE64C:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r8,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r8.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825fe64c
	if (!ctx.cr0.eq) goto loc_825FE64C;
	// lwsync 
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r10,r31,12
	ctx.r10.s64 = ctx.r31.s64 + 12;
	// lwz r11,-15392(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15392);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x825fe5e4
	goto loc_825FE5E4;
}

DEFINE_REX_FUNC(sub_82615D70) {
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
	// lwz r3,-11488(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -11488);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// addi r31,r11,3640
	ctx.r31.s64 = ctx.r11.s64 + 3640;
loc_82615D90:
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
loc_82615D98:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r7
	ea = ctx.r7.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stwcx. r9,0,r7
	ea = ctx.r7.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82615d98
	if (!ctx.cr0.eq) goto loc_82615D98;
	// mr r11,r11
	ctx.r11.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82615d90
	if (!ctx.cr6.eq) goto loc_82615D90;
	// lwsync 
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-14492(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -14492);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82615DD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwsync 
	// li r10,0
	ctx.r10.s64 = 0;
loc_82615DDC:
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
	// bne 0x82615ddc
	if (!ctx.cr0.eq) goto loc_82615DDC;
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

DEFINE_REX_FUNC(sub_8261AEA8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8261AEB0;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8261aed4
	if (!ctx.cr6.eq) goto loc_8261AED4;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8261aee0
	goto loc_8261AEE0;
loc_8261AED4:
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r9,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
loc_8261AEE0:
	// lwz r31,8(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// subf r11,r11,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r11.u64;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// subf r8,r11,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bge cr6,0x8261af48
	if (!ctx.cr6.lt) goto loc_8261AF48;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,56
	ctx.r4.s64 = ctx.r11.s64 + 56;
	// bl 0x822167f8
	ctx.lr = 0x8261AF10;
	sub_822167F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82216678
	ctx.lr = 0x8261AF1C;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x8261AF20;
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
	ctx.lr = 0x8261AF34;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8261AF44;
	sub_8235EC48(ctx, base);
	// b 0x8261b13c
	goto loc_8261B13C;
loc_8261AF48:
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8261b038
	if (!ctx.cr6.lt) goto loc_8261B038;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8261af6c
	if (!ctx.cr6.lt) goto loc_8261AF6C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8261af70
	goto loc_8261AF70;
loc_8261AF6C:
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_8261AF70:
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8261af7c
	if (!ctx.cr6.lt) goto loc_8261AF7C;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8261AF7C:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// rlwinm r27,r11,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x8261AF98;
	sub_825E02A0(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// subf r11,r11,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r11.u64;
	// srawi r28,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r28.s64 = ctx.r11.s32 >> 2;
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r11,r3
	REX_STORE_U32(ctx.r11.u32 + ctx.r3.u32, ctx.r10.u32);
	// lwz r5,4(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r5,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r5.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8261afd0
	if (ctx.cr0.eq) goto loc_8261AFD0;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x827388e8
	ctx.lr = 0x8261AFD0;
	sub_827388E8(ctx, base);
loc_8261AFD0:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r11,r29,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r29.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8261affc
	if (ctx.cr0.eq) goto loc_8261AFFC;
	// addi r10,r28,1
	ctx.r10.s64 = ctx.r28.s64 + 1;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// add r3,r11,r31
	ctx.r3.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x827388e8
	ctx.lr = 0x8261AFFC;
	sub_827388E8(ctx, base);
loc_8261AFFC:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x8261b01c
	if (ctx.cr6.eq) goto loc_8261B01C;
	// bl 0x825e0378
	ctx.lr = 0x8261B01C;
	sub_825E0378(ctx, base);
loc_8261B01C:
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r31,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// add r10,r27,r31
	ctx.r10.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r10,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r10.u32);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// b 0x8261b13c
	goto loc_8261B13C;
loc_8261B038:
	// subf r11,r29,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r29.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8261b0c8
	if (!ctx.cr6.lt) goto loc_8261B0C8;
	// lwz r31,0(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8261b068
	if (ctx.cr0.eq) goto loc_8261B068;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r3,r29,4
	ctx.r3.s64 = ctx.r29.s64 + 4;
	// bl 0x827388e8
	ctx.lr = 0x8261B068;
	sub_827388E8(ctx, base);
loc_8261B068:
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r11,r29,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r29.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// subfic r11,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r11.u64 = static_cast<uint64_t>(1) - ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8261b098
	if (ctx.cr6.eq) goto loc_8261B098;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8261b098
	if (ctx.cr0.eq) goto loc_8261B098;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8261B090:
	// stwu r31,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r31.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8261b090
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8261B090;
loc_8261B098:
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r9,r10,-4
	ctx.r9.s64 = ctx.r10.s64 + -4;
	// stw r10,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8261b13c
	if (ctx.cr6.eq) goto loc_8261B13C;
loc_8261B0B4:
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8261b0b4
	if (!ctx.cr6.eq) goto loc_8261B0B4;
	// b 0x8261b13c
	goto loc_8261B13C;
loc_8261B0C8:
	// addi r28,r31,-4
	ctx.r28.s64 = ctx.r31.s64 + -4;
	// lwz r26,0(r26)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// subf r11,r28,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r28.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r27,r6,r31
	ctx.r27.u64 = ctx.r6.u64 + ctx.r31.u64;
	// beq 0x8261b0f4
	if (ctx.cr0.eq) goto loc_8261B0F4;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827388e8
	ctx.lr = 0x8261B0F4;
	sub_827388E8(ctx, base);
loc_8261B0F4:
	// subf r11,r29,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r29.u64;
	// stw r27,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r27.u32);
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8261b11c
	if (!ctx.cr0.gt) goto loc_8261B11C;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// subf r3,r11,r31
	ctx.r3.u64 = ctx.r31.u64 - ctx.r11.u64;
	// bl 0x827388e8
	ctx.lr = 0x8261B11C;
	sub_827388E8(ctx, base);
loc_8261B11C:
	// addi r10,r29,4
	ctx.r10.s64 = ctx.r29.s64 + 4;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8261b13c
	if (ctx.cr6.eq) goto loc_8261B13C;
loc_8261B12C:
	// stw r26,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8261b12c
	if (!ctx.cr6.eq) goto loc_8261B12C;
loc_8261B13C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82630EA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82630EB0;
	__savegprlr_27(ctx, base);
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r30,r3,8
	ctx.r30.s64 = ctx.r3.s64 + 8;
	// lis r28,16384
	ctx.r28.s64 = 1073741824;
loc_82630EBC:
	// lwz r29,0(r4)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r5,r4,4
	ctx.r5.s64 = ctx.r4.s64 + 4;
	// b 0x82630fcc
	goto loc_82630FCC;
loc_82630EC8:
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r3,4(r5)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// rlwinm r11,r10,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// subf r11,r28,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r28.u64;
	// dcbf r0,r11
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82630f6c
	if (!ctx.cr0.eq) goto loc_82630F6C;
	// addi r6,r31,-1
	ctx.r6.s64 = ctx.r31.s64 + -1;
	// lhz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// lhz r9,6(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// li r7,0
	ctx.r7.s64 = 0;
	// rlwinm r8,r6,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lhz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r27,4(r11)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r11,r8,r30
	ctx.r11.u64 = ctx.r8.u64 + ctx.r30.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rotlwi r8,r4,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// rotlwi r4,r27,3
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r27.u32, 3);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
loc_82630F20:
	// lwz r27,-4(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r27,r10
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82630f58
	if (!ctx.cr6.lt) goto loc_82630F58;
	// lwz r27,4(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r27,r8
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x82630f58
	if (!ctx.cr6.gt) goto loc_82630F58;
	// lwz r27,0(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r27,r9
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82630f58
	if (!ctx.cr6.lt) goto loc_82630F58;
	// lwz r27,8(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r27,r4
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r4.u32, ctx.xer);
	// ble cr6,0x82630f58
	if (!ctx.cr6.gt) goto loc_82630F58;
	// ori r7,r7,3
	ctx.r7.u64 = ctx.r7.u64 | 3;
loc_82630F58:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// addi r11,r11,-16
	ctx.r11.s64 = ctx.r11.s64 + -16;
	// bne cr6,0x82630f20
	if (!ctx.cr6.eq) goto loc_82630F20;
	// b 0x82630fa8
	goto loc_82630FA8;
loc_82630F6C:
	// addi r10,r11,48
	ctx.r10.s64 = ctx.r11.s64 + 48;
	// addi r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 16;
	// addi r8,r11,52
	ctx.r8.s64 = ctx.r11.s64 + 52;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// li r7,-1
	ctx.r7.s64 = -1;
	// lwbrx r10,0,r10
	ctx.r10.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r10.u32));
	// lwbrx r9,0,r9
	ctx.r9.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r9.u32));
	// lwbrx r8,0,r8
	ctx.r8.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r8.u32));
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// lwbrx r11,0,r11
	ctx.r11.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r11.u32));
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 & ctx.r7.u64;
loc_82630FA8:
	// rlwinm r11,r3,12,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 12) & 0xFFF;
	// stw r7,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// clrlwi r10,r3,3
	ctx.r10.u64 = ctx.r3.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	ctx.r11.s64 = ctx.r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r11,r28,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r28.u64;
	// dcbf r0,r11
	// addi r5,r5,8
	ctx.r5.s64 = ctx.r5.s64 + 8;
loc_82630FCC:
	// cmplw cr6,r5,r29
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x82630ec8
	if (ctx.cr6.lt) goto loc_82630EC8;
	// lwz r4,0(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82630ebc
	if (!ctx.cr6.eq) goto loc_82630EBC;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8263A178) {
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
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x828559c4
	ctx.lr = 0x8263A194;
	__imp__XexLoadImage(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8263a1a8
	if (!ctx.cr0.lt) goto loc_8263A1A8;
	// bl 0x8263c0a8
	ctx.lr = 0x8263A1A0;
	sub_8263C0A8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8263a1ac
	goto loc_8263A1AC;
loc_8263A1A8:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8263A1AC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8263B630) {
	REX_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8263d958
	sub_8263D958(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8263B728) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8263B730) {
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
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82855ad4
	ctx.lr = 0x8263B744;
	__imp__NtResumeThread(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8263b758
	if (!ctx.cr0.lt) goto loc_8263B758;
	// bl 0x8263bc90
	ctx.lr = 0x8263B750;
	sub_8263BC90(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8263b75c
	goto loc_8263B75C;
loc_8263B758:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8263B75C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8263C440) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r6,16
	ctx.r6.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r9,64
	ctx.r9.s64 = 64;
	// li r10,80
	ctx.r10.s64 = 80;
	// li r11,96
	ctx.r11.s64 = 96;
	// li r12,112
	ctx.r12.s64 = 112;
	// cmplwi cr6,r5,1024
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1024, ctx.xer);
	// blt cr6,0x8263c708
	if (ctx.cr6.lt) goto loc_8263C708;
loc_8263C464:
	// addi r0,r5,-1024
	ctx.r0.s64 = ctx.r5.s64 + -1024;
	// cmplwi cr6,r0,1024
	ctx.cr6.compare<uint32_t>(ctx.r0.u32, 1024, ctx.xer);
	// blt cr6,0x8263c474
	if (ctx.cr6.lt) goto loc_8263C474;
	// li r0,1024
	ctx.r0.s64 = 1024;
loc_8263C474:
	// lvx128 v1,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v9,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v14,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v15,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v16,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v17,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v18,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v19,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v20,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v21,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v22,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v23,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v24,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v25,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v26,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v27,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v28,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v29,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v30,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v31,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v33,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v35,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v41,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v49,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v57,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// stvlx128 v1,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v1.u8[15 - i]);
	// stvlx128 v2,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v2.u8[15 - i]);
	// stvlx128 v3,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v3.u8[15 - i]);
	// stvlx128 v4,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v4.u8[15 - i]);
	// stvlx128 v5,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v5.u8[15 - i]);
	// stvlx128 v6,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v6.u8[15 - i]);
	// stvlx128 v7,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v7.u8[15 - i]);
	// stvlx128 v8,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v8.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// stvlx128 v9,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v9.u8[15 - i]);
	// stvlx128 v10,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v10.u8[15 - i]);
	// stvlx128 v11,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v11.u8[15 - i]);
	// stvlx128 v12,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v12.u8[15 - i]);
	// stvlx128 v13,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v13.u8[15 - i]);
	// stvlx128 v14,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v14.u8[15 - i]);
	// stvlx128 v15,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v15.u8[15 - i]);
	// stvlx128 v16,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v16.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// stvlx128 v17,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v17.u8[15 - i]);
	// stvlx128 v18,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v18.u8[15 - i]);
	// stvlx128 v19,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v19.u8[15 - i]);
	// stvlx128 v20,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v20.u8[15 - i]);
	// stvlx128 v21,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v21.u8[15 - i]);
	// stvlx128 v22,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v22.u8[15 - i]);
	// stvlx128 v23,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v23.u8[15 - i]);
	// stvlx128 v24,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v24.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// stvlx128 v25,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v25.u8[15 - i]);
	// stvlx128 v26,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v26.u8[15 - i]);
	// stvlx128 v27,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v27.u8[15 - i]);
	// stvlx128 v28,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v28.u8[15 - i]);
	// stvlx128 v29,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v29.u8[15 - i]);
	// stvlx128 v30,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v30.u8[15 - i]);
	// stvlx128 v31,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v31.u8[15 - i]);
	// stvlx128 v32,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v32.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// stvlx128 v33,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v33.u8[15 - i]);
	// stvlx128 v34,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v34.u8[15 - i]);
	// stvlx128 v35,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v35.u8[15 - i]);
	// stvlx128 v36,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v36.u8[15 - i]);
	// stvlx128 v37,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v37.u8[15 - i]);
	// stvlx128 v38,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v38.u8[15 - i]);
	// stvlx128 v39,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v39.u8[15 - i]);
	// stvlx128 v40,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v40.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// stvlx128 v41,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v41.u8[15 - i]);
	// stvlx128 v42,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v42.u8[15 - i]);
	// stvlx128 v43,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v43.u8[15 - i]);
	// stvlx128 v44,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v44.u8[15 - i]);
	// stvlx128 v45,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v45.u8[15 - i]);
	// stvlx128 v46,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v46.u8[15 - i]);
	// stvlx128 v47,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v47.u8[15 - i]);
	// stvlx128 v48,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v48.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// stvlx128 v49,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v49.u8[15 - i]);
	// stvlx128 v50,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v50.u8[15 - i]);
	// stvlx128 v51,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v51.u8[15 - i]);
	// stvlx128 v52,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v52.u8[15 - i]);
	// stvlx128 v53,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v53.u8[15 - i]);
	// stvlx128 v54,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v54.u8[15 - i]);
	// stvlx128 v55,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v55.u8[15 - i]);
	// stvlx128 v56,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v56.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// stvlx128 v57,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v57.u8[15 - i]);
	// stvlx128 v58,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v58.u8[15 - i]);
	// stvlx128 v59,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v59.u8[15 - i]);
	// stvlx128 v60,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v60.u8[15 - i]);
	// stvlx128 v61,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v61.u8[15 - i]);
	// stvlx128 v62,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v62.u8[15 - i]);
	// stvlx128 v63,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// stvlx128 v0,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v0.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// addi r5,r5,-1024
	ctx.r5.s64 = ctx.r5.s64 + -1024;
	// cmplwi cr6,r5,1024
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1024, ctx.xer);
	// bge cr6,0x8263c464
	if (!ctx.cr6.lt) goto loc_8263C464;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_8263C708:
	// lvx128 v1,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// stvlx128 v1,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v1.u8[15 - i]);
	// stvlx128 v2,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v2.u8[15 - i]);
	// stvlx128 v3,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v3.u8[15 - i]);
	// stvlx128 v4,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v4.u8[15 - i]);
	// stvlx128 v5,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v5.u8[15 - i]);
	// stvlx128 v6,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v6.u8[15 - i]);
	// stvlx128 v7,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v7.u8[15 - i]);
	// stvlx128 v8,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v8.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// addi r5,r5,-128
	ctx.r5.s64 = ctx.r5.s64 + -128;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bgt cr6,0x8263c708
	if (ctx.cr6.gt) goto loc_8263C708;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82678178) {
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
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82678248
	if (!ctx.cr6.eq) goto loc_82678248;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// subf r11,r4,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r4.u64;
	// addi r10,r11,8
	ctx.r10.s64 = ctx.r11.s64 + 8;
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// bgt cr6,0x82678248
	if (ctx.cr6.gt) goto loc_82678248;
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x826782a8
	if (!ctx.cr6.gt) goto loc_826782A8;
loc_826781C0:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// addi r10,r11,8
	ctx.r10.s64 = ctx.r11.s64 + 8;
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// bgt cr6,0x826782a8
	if (ctx.cr6.gt) goto loc_826782A8;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lbz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// stw r9,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r9.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826781F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lwz r7,36(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// subfic r6,r30,8
	ctx.xer.ca = ctx.r30.u32 <= 8;
	ctx.r6.u64 = static_cast<uint64_t>(8) - ctx.r30.u64;
	// slw r5,r8,r30
	ctx.r5.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r4,40(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// clrlwi r3,r30,24
	ctx.r3.u64 = ctx.r30.u32 & 0xFF;
	// clrlwi r9,r5,24
	ctx.r9.u64 = ctx.r5.u32 & 0xFF;
	// slw r8,r7,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r6.u8 & 0x3F));
	// subf r10,r30,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r30.u64;
	// srw r7,r9,r3
	ctx.r7.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r3.u8 & 0x3F));
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// or r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 | ctx.r7.u64;
	// addi r4,r10,8
	ctx.r4.s64 = ctx.r10.s64 + 8;
	// stw r6,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// rotlwi r3,r6,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r5,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r5.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r4,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r4.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bgt cr6,0x826781c0
	if (ctx.cr6.gt) goto loc_826781C0;
	// b 0x826782a8
	goto loc_826782A8;
loc_82678248:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lbz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// stw r9,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r9.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82678264;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// lwz r7,44(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// slw r5,r8,r30
	ctx.r5.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r4,48(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// clrlwi r3,r5,24
	ctx.r3.u64 = ctx.r5.u32 & 0xFF;
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// subfic r6,r30,8
	ctx.xer.ca = ctx.r30.u32 <= 8;
	ctx.r6.u64 = static_cast<uint64_t>(8) - ctx.r30.u64;
	// srw r8,r3,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (ctx.r11.u8 & 0x3F));
	// slw r9,r7,r6
	ctx.r9.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r6.u8 & 0x3F));
	// subf r11,r30,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r30.u64;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// addi r5,r11,8
	ctx.r5.s64 = ctx.r11.s64 + 8;
	// stw r7,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r7.u32);
	// stw r6,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// stw r5,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r5.u32);
loc_826782A8:
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

DEFINE_REX_FUNC(sub_82683A10) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,116(r3)
	REX_STORE_U32(ctx.r3.u32 + 116, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82683A80) {
	REX_FUNC_PROLOGUE();
	// lwz r11,116(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 116);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82683CD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82683CE0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8268f040
	ctx.lr = 0x82683CEC;
	sub_8268F040(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82683dcc
	if (ctx.cr0.lt) goto loc_82683DCC;
	// lwz r4,124(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8265dfd8
	ctx.lr = 0x82683D00;
	sub_8265DFD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8264dcc8
	ctx.lr = 0x82683D10;
	sub_8264DCC8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82683d5c
	if (ctx.cr0.eq) goto loc_82683D5C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82683500
	ctx.lr = 0x82683D20;
	sub_82683500(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r30,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r30.u32);
	// lwz r11,44(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// lwz r10,52(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
	// divwu r4,r10,r11
	ctx.r4.u64 = uint32_t(ctx.r11.u32 ? ctx.r10.u32 / ctx.r11.u32 : 0);
	// lwz r9,48(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 48);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82683D4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// lwz r29,44(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82683d68
	if (!ctx.cr6.eq) goto loc_82683D68;
loc_82683D5C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82683dcc
	goto loc_82683DCC;
loc_82683D68:
	// lwz r3,132(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82683D7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,44(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r10,52(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r9,128(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lhz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// divwu r11,r10,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r10.u32 / ctx.r11.u32 : 0);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82683DCC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82683DCC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8268CD78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x8268CD80;
	__savegprlr_21(ctx, base);
	// stfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f30.u64);
	// stfd f31,-104(r1)
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r21,r6
	ctx.r21.u64 = ctx.r6.u64;
	// cmpwi cr6,r5,16
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 16, ctx.xer);
	// slw r22,r11,r5
	ctx.r22.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r5.u8 & 0x3F));
	// bge cr6,0x8268cdd0
	if (!ctx.cr6.lt) goto loc_8268CDD0;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r23,r11,592
	ctx.r23.s64 = ctx.r11.s64 + 592;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r23,72
	ctx.r8.s64 = ctx.r23.s64 + 72;
	// addi r7,r23,8
	ctx.r7.s64 = ctx.r23.s64 + 8;
	// lfs f0,8680(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8680);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r10,r8
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f31,r10,r7
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// b 0x8268ce24
	goto loc_8268CE24;
loc_8268CDD0:
	// extsw r11,r22
	ctx.r11.s64 = ctx.r22.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lfd f0,6304(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 6304);
	// addi r23,r11,592
	ctx.r23.s64 = ctx.r11.s64 + 592;
	// fdiv f30,f0,f13
	ctx.f30.f64 = ctx.f0.f64 / ctx.f13.f64;
	// lfd f0,592(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 592);
	// fmul f1,f30,f0
	ctx.f1.f64 = ctx.f30.f64 * ctx.f0.f64;
	// bl 0x82738cc0
	ctx.lr = 0x8268CE00;
	sub_82738CC0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64));
	// lfd f0,520(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 520);
	// fmul f1,f30,f0
	ctx.f1.f64 = ctx.f30.f64 * ctx.f0.f64;
	// bl 0x82738be0
	ctx.lr = 0x8268CE14;
	sub_82738BE0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfd f0,24264(r8)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r8.u32 + 24264);
	// fmul f12,f1,f0
	ctx.f12.f64 = ctx.f1.f64 * ctx.f0.f64;
	// frsp f0,f12
	ctx.f0.f64 = double(float(ctx.f12.f64));
loc_8268CE24:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// bne cr6,0x8268ce38
	if (!ctx.cr6.eq) goto loc_8268CE38;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,8220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8220);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
loc_8268CE38:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// li r7,176
	ctx.r7.s64 = 176;
	// lfs f13,7996(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7996);
	ctx.f13.f64 = double(temp.f32);
	// li r11,192
	ctx.r11.s64 = 192;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r10,144
	ctx.r10.s64 = 144;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,208
	ctx.r9.s64 = 208;
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,160
	ctx.r8.s64 = 160;
	// vspltw128 v2,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// rlwinm r24,r22,1,0,30
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// lvx128 v62,r23,r7
	ea = (ctx.r23.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v29,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// lvx128 v31,r23,r11
	ea = (ctx.r23.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lvx128 v0,r23,r10
	ea = (ctx.r23.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v30,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// lvx128 v28,r23,r9
	ea = (ctx.r23.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v1,v2,v62
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// lvx128 v63,r23,r8
	ea = (ctx.r23.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8268CEA8:
	// cmpwi cr6,r3,8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 8, ctx.xer);
	// bgt cr6,0x8268cec0
	if (ctx.cr6.gt) goto loc_8268CEC0;
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// bne cr6,0x8268d0e8
	if (!ctx.cr6.eq) goto loc_8268D0E8;
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// ble cr6,0x8268d08c
	if (!ctx.cr6.gt) goto loc_8268D08C;
loc_8268CEC0:
	// vmaddfp v9,v2,v29,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v29.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// srawi r26,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r26.s64 = ctx.r3.s32 >> 1;
	// vmaddfp v5,v1,v30,v31
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v30.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vor v4,v31,v31
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)ctx.v31.u8));
	// vor v3,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// vmaddfp v2,v9,v28,v0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v28.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsldoi128 v59,v0,v9,8
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8), 8));
	// vsldoi v12,v31,v5,8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8), 8));
	// vor v30,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vor v29,v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_load_si128((simde__m128i*)ctx.v5.u8));
	// vxor128 v11,v59,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vxor128 v1,v2,v62
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// ble cr6,0x8268cf44
	if (!ctx.cr6.gt) goto loc_8268CF44;
	// rlwinm r10,r26,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
loc_8268CF0C:
	// lvx128 v58,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lvx128 v57,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v58,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v57.f32)));
	// cmpw cr6,r9,r24
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r24.s32, ctx.xer);
	// vaddfp128 v56,v58,v57
	simde_mm_store_ps(ctx.v56.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v57.f32)));
	// vmaddfp v10,v12,v13,v0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vpermwi128 v13,v13,78
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0xB1));
	// stvx128 v56,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// vmaddfp v13,v11,v13,v10
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v13,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// blt cr6,0x8268cf0c
	if (ctx.cr6.lt) goto loc_8268CF0C;
loc_8268CF44:
	// li r25,4
	ctx.r25.s64 = 4;
	// cmpwi cr6,r26,4
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 4, ctx.xer);
	// ble cr6,0x8268d084
	if (!ctx.cr6.gt) goto loc_8268D084;
	// add r11,r26,r3
	ctx.r11.u64 = ctx.r26.u64 + ctx.r3.u64;
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r8,r26,4
	ctx.r8.s64 = ctx.r26.s64 + 4;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r31,16
	ctx.r28.s64 = ctx.r31.s64 + 16;
	// add r27,r11,r31
	ctx.r27.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r29,r10,r31
	ctx.r29.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r30,r9,r31
	ctx.r30.u64 = ctx.r9.u64 + ctx.r31.u64;
loc_8268CF7C:
	// vmaddfp v4,v1,v9,v4
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// add r6,r25,r3
	ctx.r6.u64 = ctx.r25.u64 + ctx.r3.u64;
	// vmaddfp v3,v2,v5,v3
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// cmpw cr6,r6,r24
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r24.s32, ctx.xer);
	// vmaddfp v9,v2,v4,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v5,v1,v3,v5
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vsldoi128 v55,v3,v9,8
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8), 8));
	// vsldoi v11,v4,v5,8
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8), 8));
	// vxor128 v10,v55,v63
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// bgt cr6,0x8268d028
	if (ctx.cr6.gt) goto loc_8268D028;
	// rlwinm r5,r3,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r3,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_8268CFC0:
	// lvx128 v54,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// lvx128 v53,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r4,r5,r4
	ctx.r4.u64 = ctx.r5.u64 + ctx.r4.u64;
	// lvx128 v52,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v54,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v53.f32)));
	// lvx128 v51,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v50,v54,v53
	simde_mm_store_ps(ctx.v50.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v53.f32)));
	// vsubfp128 v12,v52,v51
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v52.f32), simde_mm_load_ps(ctx.v51.f32)));
	// cmpw cr6,r6,r24
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r24.s32, ctx.xer);
	// vaddfp128 v49,v52,v51
	simde_mm_store_ps(ctx.v49.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v52.f32), simde_mm_load_ps(ctx.v51.f32)));
	// vmaddfp v8,v11,v13,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vpermwi128 v7,v13,78
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0xB1));
	// stvx128 v50,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// vmaddfp v13,v11,v12,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vpermwi128 v6,v12,78
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0xB1));
	// stvx128 v49,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// vmaddfp v12,v10,v7,v8
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v13,v10,v6,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// stvx128 v13,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// ble cr6,0x8268cfc0
	if (!ctx.cr6.gt) goto loc_8268CFC0;
loc_8268D028:
	// cmpw cr6,r4,r24
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r24.s32, ctx.xer);
	// bgt cr6,0x8268d068
	if (ctx.cr6.gt) goto loc_8268D068;
	// add r10,r4,r26
	ctx.r10.u64 = ctx.r4.u64 + ctx.r26.u64;
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lvx128 v48,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v48,v47
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v48.f32), simde_mm_load_ps(ctx.v47.f32)));
	// vaddfp128 v46,v48,v47
	simde_mm_store_ps(ctx.v46.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v48.f32), simde_mm_load_ps(ctx.v47.f32)));
	// vmaddfp v12,v11,v13,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vpermwi128 v13,v13,78
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0xB1));
	// stvx128 v46,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v13,v10,v13,v12
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v13,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8268D068:
	// addi r25,r25,4
	ctx.r25.s64 = ctx.r25.s64 + 4;
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// addi r29,r29,16
	ctx.r29.s64 = ctx.r29.s64 + 16;
	// addi r28,r28,16
	ctx.r28.s64 = ctx.r28.s64 + 16;
	// addi r27,r27,16
	ctx.r27.s64 = ctx.r27.s64 + 16;
	// cmpw cr6,r25,r26
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x8268cf7c
	if (ctx.cr6.lt) goto loc_8268CF7C;
loc_8268D084:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// b 0x8268cea8
	goto loc_8268CEA8;
loc_8268D08C:
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// ble cr6,0x8268d190
	if (!ctx.cr6.gt) goto loc_8268D190;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// ble cr6,0x8268d190
	if (!ctx.cr6.gt) goto loc_8268D190;
	// addi r10,r24,-1
	ctx.r10.s64 = ctx.r24.s64 + -1;
	// addi r11,r31,-4
	ctx.r11.s64 = ctx.r31.s64 + -4;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8268D0B0:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// fsubs f9,f0,f12
	ctx.f9.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// stfs f10,4(r11)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fadds f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stfs f9,12(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// stfs f8,8(r11)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// fsubs f7,f13,f11
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// stfsu f7,16(r11)
	ea = 16 + ctx.r11.u32;
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8268d0b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8268D0B0;
	// b 0x8268d190
	goto loc_8268D190;
loc_8268D0E8:
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// ble cr6,0x8268d190
	if (!ctx.cr6.gt) goto loc_8268D190;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// ble cr6,0x8268d190
	if (!ctx.cr6.gt) goto loc_8268D190;
	// addi r11,r24,-1
	ctx.r11.s64 = ctx.r24.s64 + -1;
	// li r5,240
	ctx.r5.s64 = 240;
	// rlwinm r10,r11,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// lvx128 v11,r23,r5
	ea = (ctx.r23.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r6,-16
	ctx.r6.s64 = -16;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r10,224
	ctx.r10.s64 = 224;
	// lvx128 v12,r23,r10
	ea = (ctx.r23.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8268D12C:
	// lvlx128 v45,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r11,32
	ctx.r10.s64 = ctx.r11.s64 + 32;
	// lvlx128 v44,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v43,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vaddfp128 v0,v45,v44
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v45.f32), simde_mm_load_ps(ctx.v44.f32)));
	// lvlx128 v42,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vsubfp128 v41,v45,v44
	simde_mm_store_ps(ctx.v41.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v45.f32), simde_mm_load_ps(ctx.v44.f32)));
	// vsubfp128 v40,v43,v42
	simde_mm_store_ps(ctx.v40.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v43.f32), simde_mm_load_ps(ctx.v42.f32)));
	// vaddfp128 v13,v43,v42
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v43.f32), simde_mm_load_ps(ctx.v42.f32)));
	// vpermwi128 v10,v0,177
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x4E));
	// vpermwi128 v9,v41,238
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v41.u32), 0x11));
	// vpermwi128 v8,v41,17
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v41.u32), 0xEE));
	// vpermwi128 v7,v13,177
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x4E));
	// vpermwi128 v5,v40,17
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v40.u32), 0xEE));
	// vmaddfp v0,v0,v12,v10
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vpermwi128 v6,v40,238
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v40.u32), 0x11));
	// vmaddfp v10,v9,v11,v8
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v13,v13,v12,v7
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v9,v6,v11,v5
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// stvx128 v10,r10,r6
	ea = (ctx.r10.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bdnz 0x8268d12c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8268D12C;
loc_8268D190:
	// cmpwi cr6,r24,4
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 4, ctx.xer);
	// ble cr6,0x8268d298
	if (!ctx.cr6.gt) goto loc_8268D298;
	// srawi r11,r22,1
	ctx.xer.ca = (ctx.r22.s32 < 0) & ((ctx.r22.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r22.s32 >> 1;
	// addi r3,r22,1
	ctx.r3.s64 = ctx.r22.s64 + 1;
	// addze r30,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r30.s64 = temp.s64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// ble cr6,0x8268d298
	if (!ctx.cr6.gt) goto loc_8268D298;
	// addi r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 1;
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r9,r31
	ctx.r5.u64 = ctx.r9.u64 + ctx.r31.u64;
loc_8268D1C4:
	// cmpw cr6,r4,r10
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8268d234
	if (!ctx.cr6.lt) goto loc_8268D234;
	// addi r8,r3,2
	ctx.r8.s64 = ctx.r3.s64 + 2;
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// add r7,r4,r8
	ctx.r7.u64 = ctx.r4.u64 + ctx.r8.u64;
	// lfs f12,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r3,r10
	ctx.r6.u64 = ctx.r3.u64 + ctx.r10.u64;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r29,r6,1
	ctx.r29.s64 = ctx.r6.s64 + 1;
	// lfs f11,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f10,r7,r31
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r31.u32);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r8,r29,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f11,-8(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + -8, temp.u32);
	// lfs f9,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,-4(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// lfsx f8,r8,r31
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,0(r5)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// lfsx f7,r6,r31
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + ctx.r31.u32);
	ctx.f7.f64 = double(temp.f32);
	// stfsx f7,r7,r31
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r7.u32 + ctx.r31.u32, temp.u32);
	// stfs f0,0(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f12,4(r9)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfsx f13,r8,r31
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, temp.u32);
	// stfsx f10,r6,r31
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r6.u32 + ctx.r31.u32, temp.u32);
loc_8268D234:
	// add r9,r10,r22
	ctx.r9.u64 = ctx.r10.u64 + ctx.r22.u64;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// lfs f12,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f11,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,4(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f0,0(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f13,4(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// bgt cr6,0x8268d280
	if (ctx.cr6.gt) goto loc_8268D280;
loc_8268D26C:
	// srawi r9,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 1;
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8268d26c
	if (!ctx.cr6.gt) goto loc_8268D26C;
loc_8268D280:
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmpw cr6,r4,r22
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r22.s32, ctx.xer);
	// blt cr6,0x8268d1c4
	if (ctx.cr6.lt) goto loc_8268D1C4;
loc_8268D298:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// bne cr6,0x8268d35c
	if (!ctx.cr6.eq) goto loc_8268D35C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r24,4
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 4, ctx.xer);
	// lfs f13,5864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5864);
	ctx.f13.f64 = double(temp.f32);
	// blt cr6,0x8268d318
	if (ctx.cr6.lt) goto loc_8268D318;
	// extsw r11,r22
	ctx.r11.s64 = ctx.r22.s32;
	// addi r10,r24,-4
	ctx.r10.s64 = ctx.r24.s64 + -4;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// rlwinm r11,r10,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r11,r31,-4
	ctx.r11.s64 = ctx.r31.s64 + -4;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// fdivs f0,f13,f11
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
loc_8268D2E4:
	// lfs f12,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f9,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lfs f7,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f10,4(r11)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fmuls f5,f7,f0
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// stfs f8,8(r11)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// stfs f6,12(r11)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// stfsu f5,16(r11)
	ea = 16 + ctx.r11.u32;
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8268d2e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8268D2E4;
loc_8268D318:
	// cmpw cr6,r10,r24
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r24.s32, ctx.xer);
	// bge cr6,0x8268d35c
	if (!ctx.cr6.lt) goto loc_8268D35C;
	// extsw r9,r22
	ctx.r9.s64 = ctx.r22.s32;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// subf r8,r10,r24
	ctx.r8.u64 = ctx.r24.u64 - ctx.r10.u64;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// fdivs f0,f13,f11
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
loc_8268D34C:
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
	// bdnz 0x8268d34c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8268D34C;
loc_8268D35C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826E7708) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x826E7710;
	__savegprlr_22(ctx, base);
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// vspltish v0,15
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_set1_epi16(short(0xF)));
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// vslb v13,v0,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi8(0x7));
		simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_sllv_epi8(a, shift));
	}
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// beq cr6,0x826e7a24
	if (ctx.cr6.eq) goto loc_826E7A24;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// li r11,16
	ctx.r11.s64 = 16;
	// beq cr6,0x826e79a4
	if (ctx.cr6.eq) goto loc_826E79A4;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v63,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v60,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vspltish v0,3
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_set1_epi16(short(0x3)));
	// add r31,r8,r3
	ctx.r31.u64 = ctx.r8.u64 + ctx.r3.u64;
	// vor128 v9,v63,v60
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// add r9,r8,r4
	ctx.r9.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lvlx128 v62,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v58,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vspltish v8,4
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_set1_epi16(short(0x4)));
	// lvlx128 v61,r8,r3
	temp.u32 = ctx.r8.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v12,v62,v58
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8)));
	// lvlx128 v56,r8,r4
	temp.u32 = ctx.r8.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r30,r1,-192
	ctx.r30.s64 = ctx.r1.s64 + -192;
	// lvrx128 v59,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r29,r1,-192
	ctx.r29.s64 = ctx.r1.s64 + -192;
	// vor128 v10,v61,v59
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// lvrx128 v57,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v11,v56,v57
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8)));
	// vmrghh v5,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrghh v6,v8,v0
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// vslh v30,v9,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// addi r28,r1,-176
	ctx.r28.s64 = ctx.r1.s64 + -176;
	// vslh v4,v10,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// rlwinm r3,r7,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// vsubshs v3,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// addi r31,r1,-176
	ctx.r31.s64 = ctx.r1.s64 + -176;
	// vsubshs v7,v11,v12
	simde_mm_store_si128((simde__m128i*)ctx.v7.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// addi r27,r1,-160
	ctx.r27.s64 = ctx.r1.s64 + -160;
	// vsubshs v8,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// addi r26,r1,-144
	ctx.r26.s64 = ctx.r1.s64 + -144;
	// vslh v31,v11,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// subf r23,r3,r6
	ctx.r23.u64 = ctx.r6.u64 - ctx.r3.u64;
	// vaddshs v1,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// addi r25,r1,-160
	ctx.r25.s64 = ctx.r1.s64 + -160;
	// vsubshs v2,v10,v9
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// addi r24,r1,-144
	ctx.r24.s64 = ctx.r1.s64 + -144;
	// vslh v29,v12,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// subf r22,r7,r6
	ctx.r22.u64 = ctx.r6.u64 - ctx.r7.u64;
	// vaddshs v27,v31,v8
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// add r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 + ctx.r7.u64;
	// vaddshs v28,v1,v7
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v26,v30,v2
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vaddshs v25,v29,v7
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v23,v27,v5
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v24,v28,v5
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v22,v26,v8
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v21,v25,v6
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vsrah v19,v23,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v23.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v20,v24,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v24.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v18,v22,v6
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vsrah v17,v21,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v11,v20,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vsrah v16,v18,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v18.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v12,v17,v13
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vaddshs v0,v19,v13
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vpkshus128 v55,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// stvx128 v11,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v10,v16,v13
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vpkshus128 v54,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// stvx128 v12,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus128 v53,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// stvx128 v0,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus128 v52,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// stvx128 v10,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,-192(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -192);
	// lwz r30,-188(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -188);
	// stvx128 v54,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,-176(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + -176);
	// stw r31,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r31.u32);
	// stvx128 v53,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r10.u32);
	// lwz r31,-160(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + -160);
	// add r10,r3,r6
	ctx.r10.u64 = ctx.r3.u64 + ctx.r6.u64;
	// lwz r29,-140(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -140);
	// lwz r28,-172(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -172);
	// lwz r27,-156(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -156);
	// lwz r26,-144(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -144);
	// stw r31,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r31.u32);
	// stwx r26,r6,r7
	REX_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r26.u32);
	// stw r28,4(r23)
	REX_STORE_U32(ctx.r23.u32 + 4, ctx.r28.u32);
	// stw r30,4(r22)
	REX_STORE_U32(ctx.r22.u32 + 4, ctx.r30.u32);
	// stw r27,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r27.u32);
	// stw r29,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r29.u32);
	// bne cr6,0x826e7c44
	if (!ctx.cr6.eq) goto loc_826E7C44;
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r5,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r5,r9
	ctx.r5.u64 = ctx.r5.u64 + ctx.r9.u64;
	// add r9,r6,r4
	ctx.r9.u64 = ctx.r6.u64 + ctx.r4.u64;
	// rlwinm r31,r5,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lvlx128 v51,r6,r4
	temp.u32 = ctx.r6.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r4,r6,r9
	ctx.r4.u64 = ctx.r6.u64 + ctx.r9.u64;
	// addi r30,r1,-144
	ctx.r30.s64 = ctx.r1.s64 + -144;
	// lvlx128 v50,r8,r9
	temp.u32 = ctx.r8.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r8,r31,r9
	ctx.r8.u64 = ctx.r31.u64 + ctx.r9.u64;
	// lvlx128 v49,r6,r9
	temp.u32 = ctx.r6.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r6,r1,-144
	ctx.r6.s64 = ctx.r1.s64 + -144;
	// lvrx128 v48,r11,r5
	temp.u32 = ctx.r11.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r5,r1,-160
	ctx.r5.s64 = ctx.r1.s64 + -160;
	// lvrx128 v47,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v0,v50,v48
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8)));
	// lvlx128 v46,r31,r9
	temp.u32 = ctx.r31.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v11,v49,v47
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8)));
	// lvrx128 v45,r11,r8
	temp.u32 = ctx.r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r4,r1,-160
	ctx.r4.s64 = ctx.r1.s64 + -160;
	// lvrx128 v44,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v10,v46,v45
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v45.u8)));
	// vor128 v9,v51,v44
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v44.u8)));
	// addi r9,r1,-176
	ctx.r9.s64 = ctx.r1.s64 + -176;
	// vaddshs v12,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// addi r8,r1,-176
	ctx.r8.s64 = ctx.r1.s64 + -176;
	// vaddshs v11,v11,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// addi r31,r1,-192
	ctx.r31.s64 = ctx.r1.s64 + -192;
	// vaddshs v10,v10,v13
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// addi r29,r1,-192
	ctx.r29.s64 = ctx.r1.s64 + -192;
	// vaddshs v0,v9,v13
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// vpkshus128 v43,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// stvx128 v12,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus128 v42,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// stvx128 v11,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus128 v41,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// stvx128 v10,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus128 v40,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// stvx128 v0,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stvx128 v43,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,-144(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -144);
	// stvx128 v42,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,-160(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -160);
	// stvx128 v41,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,-176(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -176);
	// stvx128 v40,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,-188(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + -188);
	// lwz r30,-140(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -140);
	// add r8,r3,r10
	ctx.r8.u64 = ctx.r3.u64 + ctx.r10.u64;
	// lwz r28,-172(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -172);
	// lwz r27,-192(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -192);
	// stw r27,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r27.u32);
	// lwz r29,-156(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -156);
	// stwx r6,r10,r7
	REX_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r6.u32);
	// stwx r5,r3,r10
	REX_STORE_U32(ctx.r3.u32 + ctx.r10.u32, ctx.r5.u32);
	// stw r4,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// stw r31,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r31.u32);
	// stw r30,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r30.u32);
	// stw r29,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r29.u32);
	// stw r28,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r28.u32);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826E79A4:
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lvrx128 v38,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v39,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r5,r1,-144
	ctx.r5.s64 = ctx.r1.s64 + -144;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// vor128 v0,v39,v38
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)ctx.v38.u8)));
	// addi r9,r1,-160
	ctx.r9.s64 = ctx.r1.s64 + -160;
	// addi r4,r1,-144
	ctx.r4.s64 = ctx.r1.s64 + -144;
	// addi r8,r1,-160
	ctx.r8.s64 = ctx.r1.s64 + -160;
	// vaddshs v0,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// rlwinm r3,r7,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lvrx128 v37,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v36,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// subf r10,r3,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r3.u64;
	// vor128 v12,v36,v37
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v36.u8), simde_mm_load_si128((simde__m128i*)ctx.v37.u8)));
	// vpkshus128 v35,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// stvx128 v0,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r10,r7
	ctx.r11.u64 = ctx.r10.u64 + ctx.r7.u64;
	// vaddshs v12,v12,v13
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vpkshus128 v34,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// stvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,-140(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -140);
	// lwz r6,-144(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -144);
	// stw r6,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// stvx128 v34,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,-156(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -156);
	// lwz r5,-160(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -160);
	// stwx r5,r10,r7
	REX_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r5.u32);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r4,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r4.u32);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826E7A24:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x826e7c44
	if (ctx.cr6.eq) goto loc_826E7C44;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// li r11,16
	ctx.r11.s64 = 16;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// beq cr6,0x826e7ab0
	if (ctx.cr6.eq) goto loc_826E7AB0;
	// lvrx128 v32,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r3,r1,-144
	ctx.r3.s64 = ctx.r1.s64 + -144;
	// lvlx128 v33,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r4,r1,-144
	ctx.r4.s64 = ctx.r1.s64 + -144;
	// vor128 v0,v33,v32
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v33.u8), simde_mm_load_si128((simde__m128i*)ctx.v32.u8)));
	// lvrx128 v62,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r8,r1,-160
	ctx.r8.s64 = ctx.r1.s64 + -160;
	// vor128 v12,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// addi r5,r1,-160
	ctx.r5.s64 = ctx.r1.s64 + -160;
	// add r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 + ctx.r7.u64;
	// vaddshs v0,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vaddshs v13,v12,v13
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vpkshus128 v61,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// stvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus128 v60,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// stvx128 v13,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-140(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -140);
	// lwz r11,-144(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -144);
	// stvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// lwz r10,-160(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -160);
	// lwz r8,-156(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -156);
	// stwx r10,r6,r7
	REX_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r10.u32);
	// stw r3,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r3.u32);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
loc_826E7AB0:
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lvrx128 v58,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v59,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// rlwinm r31,r5,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r5,r9
	ctx.r8.u64 = ctx.r5.u64 + ctx.r9.u64;
	// vor128 v0,v59,v58
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8)));
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lvrx128 v57,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v55,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r10,r5,r31
	ctx.r10.u64 = ctx.r5.u64 + ctx.r31.u64;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// vor128 v12,v55,v57
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8)));
	// vaddshs v0,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// rlwinm r3,r5,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r30,r1,-160
	ctx.r30.s64 = ctx.r1.s64 + -160;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// vaddshs v12,v12,v13
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// lvrx128 v56,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vpkshus128 v52,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// lvlx128 v54,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lvlx128 v47,r3,r4
	temp.u32 = ctx.r3.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// stvx128 v0,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,-160
	ctx.r5.s64 = ctx.r1.s64 + -160;
	// lvrx128 v53,r11,r8
	temp.u32 = ctx.r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v49,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r29,r1,-176
	ctx.r29.s64 = ctx.r1.s64 + -176;
	// stvx128 v12,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v11,v54,v56
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8)));
	// lvrx128 v48,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v10,v49,v53
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8)));
	// lvrx128 v46,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v9,v47,v48
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8)));
	// lvlx128 v45,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vpkshus128 v51,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// stvx128 v52,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v8,v45,v46
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)ctx.v46.u8)));
	// vaddshs v11,v11,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// addi r30,r1,-128
	ctx.r30.s64 = ctx.r1.s64 + -128;
	// vaddshs v10,v10,v13
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// addi r4,r1,-176
	ctx.r4.s64 = ctx.r1.s64 + -176;
	// vaddshs v9,v9,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// addi r8,r1,-112
	ctx.r8.s64 = ctx.r1.s64 + -112;
	// vaddshs v13,v8,v13
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// addi r29,r1,-144
	ctx.r29.s64 = ctx.r1.s64 + -144;
	// vpkshus128 v50,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// addi r28,r1,-192
	ctx.r28.s64 = ctx.r1.s64 + -192;
	// vpkshus128 v44,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// addi r31,r1,-112
	ctx.r31.s64 = ctx.r1.s64 + -112;
	// stvx128 v9,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus128 v42,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vpkshus128 v43,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// addi r3,r1,-192
	ctx.r3.s64 = ctx.r1.s64 + -192;
	// addi r30,r1,-144
	ctx.r30.s64 = ctx.r1.s64 + -144;
	// stvx128 v51,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,-128
	ctx.r4.s64 = ctx.r1.s64 + -128;
	// stvx128 v10,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stvx128 v13,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stvx128 v11,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stvx128 v50,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 + ctx.r11.u64;
	// stvx128 v44,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stvx128 v43,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r31,-176(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + -176);
	// add r11,r5,r6
	ctx.r11.u64 = ctx.r5.u64 + ctx.r6.u64;
	// lwz r29,-192(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -192);
	// lwz r30,-144(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -144);
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// stvx128 v42,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-160(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -160);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// add r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 + ctx.r7.u64;
	// stw r3,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
	// stwx r31,r6,r7
	REX_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r31.u32);
	// lwz r27,-112(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -112);
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// lwz r29,-128(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -128);
	// lwz r3,-156(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -156);
	// lwz r7,-172(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -172);
	// stw r27,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r27.u32);
	// lwz r31,-188(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + -188);
	// lwz r27,-108(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -108);
	// stw r29,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r29.u32);
	// lwz r4,-124(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -124);
	// lwz r28,-140(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -140);
	// stw r30,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r30.u32);
	// stw r3,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r3.u32);
	// stw r7,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r7.u32);
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// stw r27,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r27.u32);
	// stw r4,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r4.u32);
	// stw r28,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r28.u32);
loc_826E7C44:
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82735A20) {
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
	ctx.lr = 0x82735A40;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82735ab4
	if (!ctx.cr0.eq) goto loc_82735AB4;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// ori r4,r4,17
	ctx.r4.u64 = ctx.r4.u64 | 17;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x82855704
	ctx.lr = 0x82735A78;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82735a88
	if (!ctx.cr0.lt) goto loc_82735A88;
	// li r31,1627
	ctx.r31.s64 = 1627;
	// b 0x82735aac
	goto loc_82735AAC;
loc_82735A88:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82735aa8
	if (!ctx.cr6.eq) goto loc_82735AA8;
	// bl 0x8263bcc8
	ctx.lr = 0x82735A94;
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
	// b 0x82735aac
	goto loc_82735AAC;
loc_82735AA8:
	// li r31,997
	ctx.r31.s64 = 997;
loc_82735AAC:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82855a64
	ctx.lr = 0x82735AB4;
	__imp__ObDereferenceObject(ctx, base);
loc_82735AB4:
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

DEFINE_REX_FUNC(sub_82736660) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82736668;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,2
	ctx.r11.s64 = 2;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82737d08
	ctx.lr = 0x82736688;
	sub_82737D08(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x827366a8
	if (ctx.cr0.lt) goto loc_827366A8;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x827366a8
	if (ctx.cr0.eq) goto loc_827366A8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82737cd8
	ctx.lr = 0x827366A8;
	sub_82737CD8(ctx, base);
loc_827366A8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82737D60) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r4,64
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 64, ctx.xer);
	// bge cr6,0x82737dd0
	if (!ctx.cr6.lt) goto loc_82737DD0;
	// cmplwi cr6,r5,3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 3, ctx.xer);
	// bgt cr6,0x82737dd0
	if (ctx.cr6.gt) goto loc_82737DD0;
	// rlwinm r11,r4,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82737d90
	if (ctx.cr0.eq) goto loc_82737D90;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// blr 
	return;
loc_82737D90:
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82737db8
	if (ctx.cr6.eq) goto loc_82737DB8;
	// lbz r8,1(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 1);
	// clrlwi. r8,r8,31
	ctx.r8.u64 = ctx.r8.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82737db8
	if (ctx.cr0.eq) goto loc_82737DB8;
	// slw r8,r10,r5
	ctx.r8.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r5.u8 & 0x3F));
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// divdu r6,r6,r8
	ctx.r6.u64 = ctx.r8.u64 ? ctx.r6.u64 / ctx.r8.u64 : 0;
	// tdllei r8,0
	if (ctx.r8.s64 == 0ll || ctx.r8.u64 < 0ull) ppc_trap(ctx, base, 0);
loc_82737DB8:
	// rlwimi r5,r10,31,0,29
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0xFFFFFFFC) | (ctx.r5.u64 & 0xFFFFFFFF00000003);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// std r6,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r6.u64);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// blr 
	return;
loc_82737DD0:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82739670) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-7152
	ctx.r11.s64 = ctx.r11.s64 + -7152;
	// lwz r11,200(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 200);
	// lhzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// rlwinm r3,r11,0,30,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82739E00) {
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
	// bl 0x82739c70
	ctx.lr = 0x82739E10;
	sub_82739C70(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lfd f0,20640(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 20640);
	// fmul f1,f1,f0
	ctx.f1.f64 = ctx.f1.f64 * ctx.f0.f64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(__savegprlr_30) {
	REX_FUNC_PROLOGUE();
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(__restgprlr_22) {
	REX_FUNC_PROLOGUE();
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

DEFINE_REX_FUNC(__savefpr_14) {
	REX_FUNC_PROLOGUE();
	// stfd f14,-144(r12)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r12.u32 + -144, ctx.f14.u64);
	// stfd f15,-136(r12)
	REX_STORE_U64(ctx.r12.u32 + -136, ctx.f15.u64);
	// stfd f16,-128(r12)
	REX_STORE_U64(ctx.r12.u32 + -128, ctx.f16.u64);
	// stfd f17,-120(r12)
	REX_STORE_U64(ctx.r12.u32 + -120, ctx.f17.u64);
	// stfd f18,-112(r12)
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

DEFINE_REX_FUNC(__savevmx_28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(__savevmx_87) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(__restvmx_109) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(sub_8273D1E8) {
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
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,20932
	ctx.r11.s64 = ctx.r11.s64 + 20932;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x827437d0
	ctx.lr = 0x8273D214;
	sub_827437D0(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273d224
	if (ctx.cr0.eq) goto loc_8273D224;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825ac978
	ctx.lr = 0x8273D224;
	sub_825AC978(ctx, base);
loc_8273D224:
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

DEFINE_REX_FUNC(sub_8273F218) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8273F220;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// rlwinm. r11,r3,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// clrlwi r28,r3,27
	ctx.r28.u64 = ctx.r3.u32 & 0x1F;
	// beq 0x8273f258
	if (ctx.cr0.eq) goto loc_8273F258;
	// rlwinm. r11,r5,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f258
	if (ctx.cr0.eq) goto loc_8273F258;
	// lis r3,8192
	ctx.r3.s64 = 536870912;
	// bl 0x8273f7d4
	ctx.lr = 0x8273F250;
	sub_8273F7D4(ctx, base);
	// rlwinm r28,r28,0,29,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// b 0x8273f43c
	goto loc_8273F43C;
loc_8273F258:
	// rlwinm. r11,r29,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f278
	if (ctx.cr0.eq) goto loc_8273F278;
	// rlwinm. r11,r27,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f278
	if (ctx.cr0.eq) goto loc_8273F278;
	// lis r3,1024
	ctx.r3.s64 = 67108864;
	// bl 0x8273f7d4
	ctx.lr = 0x8273F270;
	sub_8273F7D4(ctx, base);
	// rlwinm r28,r28,0,30,28
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// b 0x8273f43c
	goto loc_8273F43C;
loc_8273F278:
	// clrlwi. r11,r29,31
	ctx.r11.u64 = ctx.r29.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f344
	if (ctx.cr0.eq) goto loc_8273F344;
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f344
	if (ctx.cr0.eq) goto loc_8273F344;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// bl 0x8273f7d4
	ctx.lr = 0x8273F290;
	sub_8273F7D4(ctx, base);
	// clrlwi r11,r27,30
	ctx.r11.u64 = ctx.r27.u32 & 0x3;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8273f30c
	if (ctx.cr6.lt) goto loc_8273F30C;
	// beq cr6,0x8273f2ec
	if (ctx.cr6.eq) goto loc_8273F2EC;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8273f2cc
	if (ctx.cr6.lt) goto loc_8273F2CC;
	// bne cr6,0x8273f33c
	if (!ctx.cr6.eq) goto loc_8273F33C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,24136(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 24136);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8273f32c
	if (!ctx.cr6.gt) goto loc_8273F32C;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfd f0,-7184(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -7184);
	// b 0x8273f338
	goto loc_8273F338;
loc_8273F2CC:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,24136(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 24136);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8273f320
	if (ctx.cr6.gt) goto loc_8273F320;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfd f0,-7184(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -7184);
	// b 0x8273f334
	goto loc_8273F334;
loc_8273F2EC:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,24136(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 24136);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// lfd f0,-7184(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -7184);
	// bgt cr6,0x8273f338
	if (ctx.cr6.gt) goto loc_8273F338;
	// b 0x8273f334
	goto loc_8273F334;
loc_8273F30C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,24136(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 24136);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8273f32c
	if (!ctx.cr6.gt) goto loc_8273F32C;
loc_8273F320:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfd f0,-7200(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -7200);
	// b 0x8273f338
	goto loc_8273F338;
loc_8273F32C:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfd f0,-7200(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -7200);
loc_8273F334:
	// fneg f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8273F338:
	// stfd f0,0(r30)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.f0.u64);
loc_8273F33C:
	// rlwinm r28,r28,0,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFE;
	// b 0x8273f43c
	goto loc_8273F43C;
loc_8273F344:
	// rlwinm. r11,r29,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f43c
	if (ctx.cr0.eq) goto loc_8273F43C;
	// rlwinm. r11,r27,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f43c
	if (ctx.cr0.eq) goto loc_8273F43C;
	// rlwinm. r11,r29,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r31,0
	ctx.r31.s64 = 0;
	// beq 0x8273f364
	if (ctx.cr0.eq) goto loc_8273F364;
	// li r31,1
	ctx.r31.s64 = 1;
loc_8273F364:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f1,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f31,24136(r11)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r11.u32 + 24136);
	// fcmpu cr6,f1,f31
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// beq cr6,0x8273f424
	if (ctx.cr6.eq) goto loc_8273F424;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8273eb08
	ctx.lr = 0x8273F380;
	sub_8273EB08(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stfd f1,80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// addi r11,r11,-1536
	ctx.r11.s64 = ctx.r11.s64 + -1536;
	// cmpwi cr6,r11,-1074
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1074, ctx.xer);
	// bge cr6,0x8273f3a0
	if (!ctx.cr6.lt) goto loc_8273F3A0;
	// fmul f0,f1,f31
	ctx.f0.f64 = ctx.f1.f64 * ctx.f31.f64;
	// li r31,1
	ctx.r31.s64 = 1;
	// b 0x8273f41c
	goto loc_8273F41C;
loc_8273F3A0:
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// li r9,1
	ctx.r9.s64 = 1;
	// blt cr6,0x8273f3b0
	if (ctx.cr6.lt) goto loc_8273F3B0;
	// li r9,0
	ctx.r9.s64 = 0;
loc_8273F3B0:
	// lhz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1021
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1021, ctx.xer);
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// ori r10,r10,16
	ctx.r10.u64 = ctx.r10.u64 | 16;
	// sth r10,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// bge cr6,0x8273f40c
	if (!ctx.cr6.lt) goto loc_8273F40C;
	// subfic r11,r11,-1021
	ctx.xer.ca = ctx.r11.u32 <= 4294966275;
	ctx.r11.u64 = static_cast<uint64_t>(-1021) - ctx.r11.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_8273F3D8:
	// clrlwi. r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8273f3ec
	if (ctx.cr0.eq) goto loc_8273F3EC;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x8273f3ec
	if (!ctx.cr6.eq) goto loc_8273F3EC;
	// li r31,1
	ctx.r31.s64 = 1;
loc_8273F3EC:
	// clrlwi. r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// beq 0x8273f3fc
	if (ctx.cr0.eq) goto loc_8273F3FC;
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
loc_8273F3FC:
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// bdnz 0x8273f3d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273F3D8;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_8273F40C:
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8273f41c
	if (ctx.cr6.eq) goto loc_8273F41C;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8273F41C:
	// stfd f0,0(r30)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.f0.u64);
	// b 0x8273f428
	goto loc_8273F428;
loc_8273F424:
	// li r31,1
	ctx.r31.s64 = 1;
loc_8273F428:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x8273f438
	if (ctx.cr6.eq) goto loc_8273F438;
	// lis r3,2048
	ctx.r3.s64 = 134217728;
	// bl 0x8273f7d4
	ctx.lr = 0x8273F438;
	sub_8273F7D4(ctx, base);
loc_8273F438:
	// rlwinm r28,r28,0,31,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
loc_8273F43C:
	// rlwinm. r11,r29,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f458
	if (ctx.cr0.eq) goto loc_8273F458;
	// rlwinm. r11,r27,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f458
	if (ctx.cr0.eq) goto loc_8273F458;
	// lis r3,512
	ctx.r3.s64 = 33554432;
	// bl 0x8273f7d4
	ctx.lr = 0x8273F454;
	sub_8273F7D4(ctx, base);
	// rlwinm r28,r28,0,28,26
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_8273F458:
	// cntlzw r11,r28
	ctx.r11.u64 = ctx.r28.u32 == 0 ? 32 : __builtin_clz(ctx.r28.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82757E40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82757E48;
	__savegprlr_24(ctx, base);
	// stfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f29.u64);
	// stfd f30,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
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
	// beq cr6,0x82757e80
	if (ctx.cr6.eq) goto loc_82757E80;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82753110
	ctx.lr = 0x82757E7C;
	sub_82753110(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_82757E80:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82757e9c
	if (ctx.cr6.eq) goto loc_82757E9C;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82755cf8
	ctx.lr = 0x82757E98;
	sub_82755CF8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_82757E9C:
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
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
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
	// bne 0x82757f08
	if (!ctx.cr0.eq) goto loc_82757F08;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,1
	ctx.r30.s64 = 1;
	// b 0x82757f10
	goto loc_82757F10;
loc_82757F08:
	// addi r29,r11,-1
	ctx.r29.s64 = ctx.r11.s64 + -1;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_82757F10:
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82757f28
	if (ctx.cr6.eq) goto loc_82757F28;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82756298
	ctx.lr = 0x82757F28;
	sub_82756298(ctx, base);
loc_82757F28:
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x827581f4
	if (!ctx.cr6.gt) goto loc_827581F4;
	// rlwinm r10,r29,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r30,r29
	ctx.r9.u64 = ctx.r30.u64 + ctx.r29.u64;
	// subf r7,r30,r29
	ctx.r7.u64 = ctx.r29.u64 - ctx.r30.u64;
	// rlwinm r25,r30,1,0,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r27
	ctx.r11.u64 = ctx.r10.u64 + ctx.r27.u64;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r7,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// subf r29,r25,r28
	ctx.r29.u64 = ctx.r28.u64 - ctx.r25.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// lis r4,-32249
	ctx.r4.s64 = -2113470464;
	// lis r28,-32256
	ctx.r28.s64 = -2113929216;
	// lfd f10,25856(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = REX_LOAD_U64(ctx.r11.u32 + 25856);
	// lfs f11,28428(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 28428);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r30,r30,4,0,27
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f12,-30548(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -30548);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-30552(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -30552);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-30528(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -30528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f6,8028(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 8028);
	ctx.f6.f64 = double(temp.f32);
loc_82757F90:
	// lfs f9,-8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + -8);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r11,r26,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xC;
	// lfs f8,-4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + -4);
	ctx.f8.f64 = double(temp.f32);
	// fadds f9,f9,f31
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f31.f64));
	// lfs f7,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fadds f8,f8,f30
	ctx.f8.f64 = double(float(ctx.f8.f64 + ctx.f30.f64));
	// fadds f7,f7,f29
	ctx.f7.f64 = double(float(ctx.f7.f64 + ctx.f29.f64));
	// lwz r7,92(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// lfsx f5,r11,r24
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	ctx.f5.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// fmuls f9,f9,f6
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f6.f64));
	// fmuls f8,f8,f6
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// fmuls f7,f7,f6
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fadds f4,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 + ctx.f5.f64));
	// fadds f3,f8,f5
	ctx.f3.f64 = double(float(ctx.f8.f64 + ctx.f5.f64));
	// fadds f5,f7,f5
	ctx.f5.f64 = double(float(ctx.f7.f64 + ctx.f5.f64));
	// fctiwz f4,f4
	ctx.f4.s64 = std::isnan(ctx.f4.f64) ? int64_t(0x80000000U) : (ctx.f4.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// fctiwz f4,f3
	ctx.f4.s64 = std::isnan(ctx.f3.f64) ? int64_t(0x80000000U) : (ctx.f3.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f4,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f4.u64);
	// fctiwz f5,f5
	ctx.f5.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f5,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f5.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,92(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// beq cr6,0x8275813c
	if (ctx.cr6.eq) goto loc_8275813C;
	// extsw r7,r5
	ctx.r7.s64 = ctx.r5.s32;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// extsw r28,r4
	ctx.r28.s64 = ctx.r4.s32;
	// std r7,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r7.u64);
	// lfd f5,104(r1)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// std r28,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r28.u64);
	// lfd f4,112(r1)
	ctx.f4.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f4,f4
	ctx.f4.f64 = double(ctx.f4.s64);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// frsp f4,f4
	ctx.f4.f64 = double(float(ctx.f4.f64));
	// extsw r7,r6
	ctx.r7.s64 = ctx.r6.s32;
	// fcfid f5,f5
	ctx.f5.f64 = double(ctx.f5.s64);
	// lfs f2,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// std r7,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r7.u64);
	// lfd f3,120(r1)
	ctx.f3.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// fsubs f9,f9,f4
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f4.f64));
	// frsp f5,f5
	ctx.f5.f64 = double(float(ctx.f5.f64));
	// fmuls f9,f9,f0
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fsubs f8,f8,f5
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f5.f64));
	// fmadds f5,f9,f13,f2
	ctx.f5.f64 = double(float(std::fma(ctx.f9.f64, ctx.f13.f64, ctx.f2.f64)));
	// stfs f5,16(r11)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// fmuls f8,f8,f0
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// lfs f5,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f5,f9,f12,f5
	ctx.f5.f64 = double(float(std::fma(ctx.f9.f64, ctx.f12.f64, ctx.f5.f64)));
	// stfs f5,16(r11)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// fcfid f5,f3
	ctx.f5.f64 = double(ctx.f3.s64);
	// lfs f4,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f4,f9,f11,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f9.f64, ctx.f11.f64, ctx.f4.f64)));
	// stfs f4,16(r11)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// frsp f5,f5
	ctx.f5.f64 = double(float(ctx.f5.f64));
	// lfs f4,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f4,f8,f13,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f8.f64, ctx.f13.f64, ctx.f4.f64)));
	// stfs f4,20(r11)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// addi r7,r11,20
	ctx.r7.s64 = ctx.r11.s64 + 20;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// fsubs f7,f7,f5
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f5.f64));
	// lfs f5,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f5,f8,f12,f5
	ctx.f5.f64 = double(float(std::fma(ctx.f8.f64, ctx.f12.f64, ctx.f5.f64)));
	// stfs f5,20(r11)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// addi r7,r11,20
	ctx.r7.s64 = ctx.r11.s64 + 20;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lfs f5,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f7,f7,f0
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// fmadds f5,f8,f11,f5
	ctx.f5.f64 = double(float(std::fma(ctx.f8.f64, ctx.f11.f64, ctx.f5.f64)));
	// stfs f5,20(r11)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// addi r7,r11,20
	ctx.r7.s64 = ctx.r11.s64 + 20;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// fmul f9,f9,f10
	ctx.f9.f64 = ctx.f9.f64 * ctx.f10.f64;
	// fmul f8,f8,f10
	ctx.f8.f64 = ctx.f8.f64 * ctx.f10.f64;
	// lfs f5,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f5,f7,f13,f5
	ctx.f5.f64 = double(float(std::fma(ctx.f7.f64, ctx.f13.f64, ctx.f5.f64)));
	// stfs f5,24(r11)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// addi r7,r11,24
	ctx.r7.s64 = ctx.r11.s64 + 24;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// frsp f31,f9
	ctx.f31.f64 = double(float(ctx.f9.f64));
	// lfs f9,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// frsp f30,f8
	ctx.f30.f64 = double(float(ctx.f8.f64));
	// fmadds f9,f7,f12,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f7.f64, ctx.f12.f64, ctx.f9.f64)));
	// stfs f9,24(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// fmul f8,f7,f10
	ctx.f8.f64 = ctx.f7.f64 * ctx.f10.f64;
	// addi r7,r11,24
	ctx.r7.s64 = ctx.r11.s64 + 24;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lfs f9,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f9,f7,f11,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f7.f64, ctx.f11.f64, ctx.f9.f64)));
	// stfs f9,24(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// addi r7,r11,24
	ctx.r7.s64 = ctx.r11.s64 + 24;
	// frsp f29,f8
	ctx.f29.f64 = double(float(ctx.f8.f64));
loc_8275813C:
	// cmpwi cr6,r4,15
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 15, ctx.xer);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// blt cr6,0x8275814c
	if (ctx.cr6.lt) goto loc_8275814C;
	// li r11,15
	ctx.r11.s64 = 15;
loc_8275814C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82758164
	if (!ctx.cr6.gt) goto loc_82758164;
	// cmpwi cr6,r4,15
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 15, ctx.xer);
	// blt cr6,0x82758168
	if (ctx.cr6.lt) goto loc_82758168;
	// li r4,15
	ctx.r4.s64 = 15;
	// b 0x82758168
	goto loc_82758168;
loc_82758164:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82758168:
	// cmpwi cr6,r5,15
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 15, ctx.xer);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// blt cr6,0x82758178
	if (ctx.cr6.lt) goto loc_82758178;
	// li r11,15
	ctx.r11.s64 = 15;
loc_82758178:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82758190
	if (!ctx.cr6.gt) goto loc_82758190;
	// cmpwi cr6,r5,15
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 15, ctx.xer);
	// blt cr6,0x82758194
	if (ctx.cr6.lt) goto loc_82758194;
	// li r5,15
	ctx.r5.s64 = 15;
	// b 0x82758194
	goto loc_82758194;
loc_82758190:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82758194:
	// cmpwi cr6,r6,15
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 15, ctx.xer);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// blt cr6,0x827581a4
	if (ctx.cr6.lt) goto loc_827581A4;
	// li r11,15
	ctx.r11.s64 = 15;
loc_827581A4:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x827581bc
	if (!ctx.cr6.gt) goto loc_827581BC;
	// cmpwi cr6,r6,15
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 15, ctx.xer);
	// blt cr6,0x827581c0
	if (ctx.cr6.lt) goto loc_827581C0;
	// li r6,15
	ctx.r6.s64 = 15;
	// b 0x827581c0
	goto loc_827581C0;
loc_827581BC:
	// li r6,0
	ctx.r6.s64 = 0;
loc_827581C0:
	// rlwinm r11,r4,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// or r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 | ctx.r5.u64;
	// add r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r30,r3
	ctx.r3.u64 = ctx.r30.u64 + ctx.r3.u64;
	// or r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 | ctx.r6.u64;
	// add r9,r30,r9
	ctx.r9.u64 = ctx.r30.u64 + ctx.r9.u64;
	// sthux r11,r29,r25
	ea = ctx.r29.u32 + ctx.r25.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r29.u32 = ea;
	// add r8,r30,r8
	ctx.r8.u64 = ctx.r30.u64 + ctx.r8.u64;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82757f90
	if (ctx.cr6.lt) goto loc_82757F90;
loc_827581F4:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
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

DEFINE_REX_FUNC(sub_8276FD20) {
	REX_FUNC_PROLOGUE();
	// b 0x8276eed0
	sub_8276EED0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8276FD28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8276FD30;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x8276fd7c
	if (!ctx.cr6.eq) goto loc_8276FD7C;
	// lis r4,-32761
	ctx.r4.s64 = -2147024896;
	// ori r4,r4,1226
	ctx.r4.u64 = ctx.r4.u64 | 1226;
	// bl 0x82768860
	ctx.lr = 0x8276FD54;
	sub_82768860(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8276ff10
	if (ctx.cr0.lt) goto loc_8276FF10;
	// lwz r11,740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 740);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// oris r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 1048576;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r11.u32);
	// bl 0x82768d88
	ctx.lr = 0x8276FD78;
	sub_82768D88(ctx, base);
	// b 0x8276ff10
	goto loc_8276FF10;
loc_8276FD7C:
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x8276fd98
	if (ctx.cr6.lt) goto loc_8276FD98;
loc_8276FD84:
	// lwz r3,396(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// bl 0x82773eb8
	ctx.lr = 0x8276FD8C;
	sub_82773EB8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// b 0x8276ff0c
	goto loc_8276FF0C;
loc_8276FD98:
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x8276fdac
	if (!ctx.cr6.eq) goto loc_8276FDAC;
	// lwz r11,740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 740);
	// rlwinm. r11,r11,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8276fd84
	if (!ctx.cr0.eq) goto loc_8276FD84;
loc_8276FDAC:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r28,r31,248
	ctx.r28.s64 = ctx.r31.s64 + 248;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8276fe6c
	if (ctx.cr6.eq) goto loc_8276FE6C;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8276fe6c
	if (ctx.cr0.eq) goto loc_8276FE6C;
loc_8276FDCC:
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r29,r27,-92
	ctx.r29.s64 = ctx.r27.s64 + -92;
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// subf r9,r10,r28
	ctx.r9.u64 = ctx.r28.u64 - ctx.r10.u64;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// subfic r9,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r9.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r27,r9,r10
	ctx.r27.u64 = ctx.r9.u64 & ctx.r10.u64;
	// beq cr6,0x8276fe64
	if (ctx.cr6.eq) goto loc_8276FE64;
	// lwz r4,100(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 100);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8276fe08
	if (!ctx.cr6.eq) goto loc_8276FE08;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x8276fe64
	if (!ctx.cr6.eq) goto loc_8276FE64;
loc_8276FE08:
	// lwz r11,396(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 396);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8276fe64
	if (ctx.cr0.eq) goto loc_8276FE64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8276fe60
	if (ctx.cr6.eq) goto loc_8276FE60;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8276fe3c
	if (ctx.cr6.eq) goto loc_8276FE3C;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r5,100(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// bl 0x82771f68
	ctx.lr = 0x8276FE34;
	sub_82771F68(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8276fe44
	goto loc_8276FE44;
loc_8276FE3C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_8276FE44:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8276fe60
	if (ctx.cr6.lt) goto loc_8276FE60;
	// bne cr6,0x8276fe64
	if (!ctx.cr6.eq) goto loc_8276FE64;
	// lwz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// lwz r10,24(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8276fe64
	if (!ctx.cr6.lt) goto loc_8276FE64;
loc_8276FE60:
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_8276FE64:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8276fdcc
	if (!ctx.cr6.eq) goto loc_8276FDCC;
loc_8276FE6C:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm r10,r10,0,2,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// ori r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 | 32;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// stw r11,396(r30)
	REX_STORE_U32(ctx.r30.u32 + 396, ctx.r11.u32);
	// rlwinm. r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r3,396(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// beq 0x8276fee4
	if (ctx.cr0.eq) goto loc_8276FEE4;
	// lwz r11,740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 740);
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// stw r11,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r11.u32);
	// bl 0x82773eb8
	ctx.lr = 0x8276FEB4;
	sub_82773EB8(ctx, base);
	// stw r30,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827646e8
	ctx.lr = 0x8276FEC0;
	sub_827646E8(ctx, base);
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// addi r4,r31,48
	ctx.r4.s64 = ctx.r31.s64 + 48;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x8273a030
	ctx.lr = 0x8276FED0;
	sub_8273A030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8276ef80
	ctx.lr = 0x8276FED8;
	sub_8276EF80(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8276fef4
	if (!ctx.cr0.lt) goto loc_8276FEF4;
	// b 0x8276ff10
	goto loc_8276FF10;
loc_8276FEE4:
	// bl 0x82773eb8
	ctx.lr = 0x8276FEE8;
	sub_82773EB8(ctx, base);
	// stw r30,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827646e8
	ctx.lr = 0x8276FEF4;
	sub_827646E8(ctx, base);
loc_8276FEF4:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8276FF0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8276FF0C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8276FF10:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82779998) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x827799A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lwz r4,180(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 180);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r11,r11,-28952
	ctx.r11.s64 = ctx.r11.s64 + -28952;
	// addi r10,r10,-29004
	ctx.r10.s64 = ctx.r10.s64 + -29004;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// addi r28,r3,8
	ctx.r28.s64 = ctx.r3.s64 + 8;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82779a04
	if (ctx.cr6.eq) goto loc_82779A04;
loc_827799D4:
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
	// bne 0x827799d4
	if (!ctx.cr0.eq) goto loc_827799D4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82779a00
	if (!ctx.cr6.eq) goto loc_82779A00;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82772060
	ctx.lr = 0x82779A00;
	sub_82772060(ctx, base);
loc_82779A00:
	// stw r29,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r29.u32);
loc_82779A04:
	// lwz r4,184(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82779a40
	if (ctx.cr6.eq) goto loc_82779A40;
loc_82779A10:
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
	// bne 0x82779a10
	if (!ctx.cr0.eq) goto loc_82779A10;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82779a3c
	if (!ctx.cr6.eq) goto loc_82779A3C;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82772060
	ctx.lr = 0x82779A3C;
	sub_82772060(ctx, base);
loc_82779A3C:
	// stw r29,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r29.u32);
loc_82779A40:
	// lwz r4,188(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82779a7c
	if (ctx.cr6.eq) goto loc_82779A7C;
loc_82779A4C:
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
	// bne 0x82779a4c
	if (!ctx.cr0.eq) goto loc_82779A4C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82779a78
	if (!ctx.cr6.eq) goto loc_82779A78;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82772060
	ctx.lr = 0x82779A78;
	sub_82772060(ctx, base);
loc_82779A78:
	// stw r29,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r29.u32);
loc_82779A7C:
	// lwz r4,192(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82779ab8
	if (ctx.cr6.eq) goto loc_82779AB8;
loc_82779A88:
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
	// bne 0x82779a88
	if (!ctx.cr0.eq) goto loc_82779A88;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82779ab4
	if (!ctx.cr6.eq) goto loc_82779AB4;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82772060
	ctx.lr = 0x82779AB4;
	sub_82772060(ctx, base);
loc_82779AB4:
	// stw r29,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r29.u32);
loc_82779AB8:
	// addi r3,r31,60
	ctx.r3.s64 = ctx.r31.s64 + 60;
	// bl 0x82597cc0
	ctx.lr = 0x82779AC0;
	sub_82597CC0(ctx, base);
	// addi r30,r31,356
	ctx.r30.s64 = ctx.r31.s64 + 356;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82597cc0
	ctx.lr = 0x82779ACC;
	sub_82597CC0(ctx, base);
	// lwz r3,104(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// bl 0x82775930
	ctx.lr = 0x82779AD4;
	sub_82775930(ctx, base);
	// stw r29,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82597cc0
	ctx.lr = 0x82779AE0;
	sub_82597CC0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827871d8
	ctx.lr = 0x82779AE8;
	sub_827871D8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r11,r11,24712
	ctx.r11.s64 = ctx.r11.s64 + 24712;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82785F58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82785F60;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r4,44
	ctx.r4.s64 = 44;
	// li r3,267
	ctx.r3.s64 = 267;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// bl 0x82772048
	ctx.lr = 0x82785F84;
	sub_82772048(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82785fa4
	if (ctx.cr0.eq) goto loc_82785FA4;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82785cf8
	ctx.lr = 0x82785FA4;
	sub_82785CF8(ctx, base);
loc_82785FA4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82787150) {
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
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// addi r11,r11,-28896
	ctx.r11.s64 = ctx.r11.s64 + -28896;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82784480
	ctx.lr = 0x8278717C;
	sub_82784480(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r31,28
	ctx.r10.s64 = ctx.r31.s64 + 28;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r9,r31,36
	ctx.r9.s64 = ctx.r31.s64 + 36;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r10,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// stw r10,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// stw r9,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// stw r9,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r9.u32);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_82789618) {
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
	// lwz r4,100(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8278966c
	if (ctx.cr6.eq) goto loc_8278966C;
loc_82789638:
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
	// bne 0x82789638
	if (!ctx.cr0.eq) goto loc_82789638;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82789664
	if (!ctx.cr6.eq) goto loc_82789664;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82772060
	ctx.lr = 0x82789664;
	sub_82772060(ctx, base);
loc_82789664:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
loc_8278966C:
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

DEFINE_REX_FUNC(sub_8278C100) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x8278c114
	if (!ctx.cr6.lt) goto loc_8278C114;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// b 0x8278c140
	goto loc_8278C140;
loc_8278C114:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// bge cr6,0x8278c130
	if (!ctx.cr6.lt) goto loc_8278C130;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,15
	ctx.r11.s64 = ctx.r11.s64 + 15;
	// b 0x8278c13c
	goto loc_8278C13C;
loc_8278C130:
	// addi r11,r11,-16
	ctx.r11.s64 = ctx.r11.s64 + -16;
	// rlwinm r11,r11,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r11,r11,103
	ctx.r11.s64 = ctx.r11.s64 + 103;
loc_8278C13C:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
loc_8278C140:
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// lhz r9,900(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 900);
	// lwz r11,896(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 896);
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8278E278) {
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
	// lwz r11,1048(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1048);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8278e394
	if (ctx.cr6.eq) goto loc_8278E394;
	// lhz r11,336(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 336);
	// rlwinm. r11,r11,0,0,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8278e338
	if (!ctx.cr0.eq) goto loc_8278E338;
	// lis r4,-32646
	ctx.r4.s64 = -2139488256;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r4,r4,4108
	ctx.r4.u64 = ctx.r4.u64 | 4108;
	// bl 0x82794ea0
	ctx.lr = 0x8278E2BC;
	sub_82794EA0(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// bl 0x82789c80
	ctx.lr = 0x8278E2E8;
	sub_82789C80(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
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
	ctx.lr = 0x8278E314;
	sub_82789C80(ctx, base);
	// lhz r11,1076(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 1076);
	// lwz r10,1204(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 1204);
	// addi r3,r30,688
	ctx.r3.s64 = ctx.r30.s64 + 688;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r11,1076(r30)
	REX_STORE_U16(ctx.r30.u32 + 1076, ctx.r11.u16);
	// stw r10,1204(r30)
	REX_STORE_U32(ctx.r30.u32 + 1204, ctx.r10.u32);
	// bl 0x82797408
	ctx.lr = 0x8278E334;
	sub_82797408(ctx, base);
	// b 0x8278e394
	goto loc_8278E394;
loc_8278E338:
	// lhz r11,334(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 334);
	// subf r11,r11,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r11.u64;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x8278e394
	if (ctx.cr0.lt) goto loc_8278E394;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// addi r10,r5,4
	ctx.r10.s64 = ctx.r5.s64 + 4;
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8278e394
	if (!ctx.cr6.lt) goto loc_8278E394;
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// lwz r8,20(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,16(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// bl 0x8278c1b0
	ctx.lr = 0x8278E394;
	sub_8278C1B0(ctx, base);
loc_8278E394:
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

DEFINE_REX_FUNC(sub_827958C0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827958d8
	if (ctx.cr6.gt) goto loc_827958D8;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_827958D8:
	// b 0x82795830
	sub_82795830(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82795C30) {
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
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,40
	ctx.r3.s64 = ctx.r11.s64 + 40;
	// bl 0x82855b44
	ctx.lr = 0x82795C50;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bne 0x82795c74
	if (!ctx.cr0.eq) goto loc_82795C74;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r3,r11,40
	ctx.r3.s64 = ctx.r11.s64 + 40;
	// bl 0x82855b34
	ctx.lr = 0x82795C70;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x82795cd8
	goto loc_82795CD8;
loc_82795C74:
	// bl 0x82748820
	ctx.lr = 0x82795C78;
	sub_82748820(ctx, base);
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// subf r10,r11,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r11.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82795cc0
	if (ctx.cr6.lt) goto loc_82795CC0;
	// subf r5,r5,r11
	ctx.r5.u64 = ctx.r11.u64 - ctx.r5.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x82784e88
	ctx.lr = 0x82795CA4;
	sub_82784E88(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r3,r11,40
	ctx.r3.s64 = ctx.r11.s64 + 40;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bl 0x82855b34
	ctx.lr = 0x82795CBC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x82795ce0
	goto loc_82795CE0;
loc_82795CC0:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm r11,r11,0,2,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bl 0x8278fcb0
	ctx.lr = 0x82795CD8;
	sub_8278FCB0(ctx, base);
loc_82795CD8:
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x82789c80
	ctx.lr = 0x82795CE0;
	sub_82789C80(ctx, base);
loc_82795CE0:
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

DEFINE_REX_FUNC(sub_8279A420) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r3,7(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 7);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8279A8A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8279A8A8;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// stw r30,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r30.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r30.u32);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// lwz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8279a97c
	if (ctx.cr6.eq) goto loc_8279A97C;
loc_8279A8E0:
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// lwz r29,0(r5)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8279a708
	ctx.lr = 0x8279A8F8;
	sub_8279A708(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279a924
	if (ctx.cr6.eq) goto loc_8279A924;
	// lwz r8,4(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8279a918
	if (ctx.cr6.eq) goto loc_8279A918;
	// stw r11,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// b 0x8279a91c
	goto loc_8279A91C;
loc_8279A918:
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_8279A91C:
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_8279A924:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279a950
	if (ctx.cr6.eq) goto loc_8279A950;
	// lwz r8,4(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8279a944
	if (ctx.cr6.eq) goto loc_8279A944;
	// stw r11,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// b 0x8279a948
	goto loc_8279A948;
loc_8279A944:
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
loc_8279A948:
	// stw r11,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_8279A950:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8279a964
	if (!ctx.cr6.eq) goto loc_8279A964;
	// stw r29,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r29.u32);
	// b 0x8279a970
	goto loc_8279A970;
loc_8279A964:
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// mr r26,r11
	ctx.r26.u64 = ctx.r11.u64;
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
loc_8279A970:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8279a8e0
	if (!ctx.cr6.eq) goto loc_8279A8E0;
loc_8279A97C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8279a98c
	if (!ctx.cr6.eq) goto loc_8279A98C;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_8279A98C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A10F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x827A10F8;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// beq cr6,0x827a1254
	if (ctx.cr6.eq) goto loc_827A1254;
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x827a1158
	if (!ctx.cr6.gt) goto loc_827A1158;
	// addi r30,r3,20
	ctx.r30.s64 = ctx.r3.s64 + 20;
loc_827A113C:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x827a1da0
	ctx.lr = 0x827A1144;
	sub_827A1DA0(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stwu r28,4(r30)
	ea = 4 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r30.u32 = ea;
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x827a113c
	if (ctx.cr6.lt) goto loc_827A113C;
loc_827A1158:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x827a1194
	if (!ctx.cr6.gt) goto loc_827A1194;
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
loc_827A116C:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827A1180;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stwu r28,4(r30)
	ea = 4 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r30.u32 = ea;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x827a116c
	if (ctx.cr6.lt) goto loc_827A116C;
loc_827A1194:
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827a1204
	if (ctx.cr6.eq) goto loc_827A1204;
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827a1200
	if (ctx.cr6.eq) goto loc_827A1200;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// lfs f1,2524(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2524);
	ctx.f1.f64 = double(temp.f32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827A11C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827A11E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827A1200;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_827A1200:
	// stw r28,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r28.u32);
loc_827A1204:
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827a1224
	if (ctx.cr6.eq) goto loc_827A1224;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827A1220;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r28,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r28.u32);
loc_827A1224:
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827a1244
	if (ctx.cr6.eq) goto loc_827A1244;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827A1240;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r28,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r28.u32);
loc_827A1244:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r4,r4,32784
	ctx.r4.u64 = ctx.r4.u64 | 32784;
	// bl 0x8263b710
	ctx.lr = 0x827A1254;
	sub_8263B710(ctx, base);
loc_827A1254:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827ACCA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-10608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ACEE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-10552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,22200(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 22200);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,-10540(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AD400) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10392(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10392, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AD8B0) {
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
	// lfs f0,22248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10364(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10364);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10252(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10252, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ADFC0) {
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
	// lfs f0,22312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10156(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10156);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10048(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE930) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9752(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AF200) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9488(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9488, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AFAB0) {
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
	// lfs f0,22840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9276(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9276);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9228(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9228, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0678) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8892);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8888(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8888, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B11E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
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

DEFINE_REX_FUNC(sub_827B1E40) {
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
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8248);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8168(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8168, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2CD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B3AD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7324);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7320(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B47B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6996(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6996);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6944(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B54B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23956(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23956);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6564(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6238) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,24072
	ctx.r9.s64 = ctx.r11.s64 + 24072;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6160(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6160, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B72B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-5672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5672);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-5668(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -5668, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7B58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-5512(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -5512);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5408(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8A80) {
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
	// lfs f0,24504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5120(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5120);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5000(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9CB0) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4580(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4580);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4464(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4464, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BAE20) {
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
	// lfs f0,25104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3992(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3992);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3932(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3932, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BBD30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,25400
	ctx.r9.s64 = ctx.r11.s64 + 25400;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,25400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3472(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BCF58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-2948(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2948);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-2944(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -2944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD9D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2640(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BE938) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-2192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-2188(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -2188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BF238) {
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
	// lfs f0,25992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2044(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2044);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1928(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0408) {
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
	// lfs f0,26344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1452(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1452);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1380(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1600) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-972(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -972);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-852(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2B98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-236(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -236, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C37E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,27144
	ctx.r9.s64 = ctx.r11.s64 + 27144;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,27144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,132(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 132, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C4AE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,712(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 712, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5B58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,1188(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1188);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1192(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 1192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6368) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27964(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27964);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1440(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1440, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7310) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28292(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28292);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1920(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1920, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8060) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2228(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2228);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2336(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8EA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,2744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2748(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2748, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9C60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,3148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3152(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3152, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CAD28) {
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
	// lfs f12,3540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3540);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3640(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CBFA8) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4116(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4116);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4204(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD1E0) {
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
	// lfs f0,29352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4668(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4668);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4736(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4736, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CE548) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,5296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5296);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,5300(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 5300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CEF78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5596(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5596, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CFD48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6004(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0E30) {
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
	// lfs f0,29928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6372(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6372);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6492(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6492, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D20F8) {
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
	// lfs f0,30120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6924(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6924);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7040(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D33C0) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7476(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7476);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7588(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7588, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4640) {
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
	// lfs f12,8028(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8028);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8128(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8128, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D58D8) {
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
	// lfs f12,8560(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8560);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8672(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8672, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6B18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,9200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9200);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,9204(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 9204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D74D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31052(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31052);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9488(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9488, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D83F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,31160
	ctx.r9.s64 = ctx.r11.s64 + 31160;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9928(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D96E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,31368
	ctx.r9.s64 = ctx.r11.s64 + 31368;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10480(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA9C8) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10944(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10944);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11032(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11032, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DBC70) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,11516(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 11516);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11576(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11576, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DCEE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31948(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31948);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12132(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12132, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DDE20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12584(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12584, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DEF10) {
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
	// lfs f12,12964(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12964);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13076(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13076, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E00D0) {
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
	// lfs f0,32440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13532(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13532);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13596(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13596, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E12F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14144(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14144, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E2390) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32524(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32524);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14644(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3458) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15116(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15116, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E42D8) {
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
	// lfs f0,-32088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,15428(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15428);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,15532(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 15532, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E5638) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,16064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16064);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16068(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16068, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E65C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,16520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16524(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16524, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7620) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-27456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27456);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16964(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E85D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17404(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17404);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17408(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E94F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-24552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24552);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,17852(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 17852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EA0D8) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18112(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18112);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18172(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18172, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB190) {
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
	// lfs f0,-22792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18544(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18544);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18644(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EC658) {
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
	// lfs f0,19192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19192);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22040(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22040);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,19216(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 19216, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EE1D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-20480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19964(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EEED0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,20324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20324);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20328(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0048) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-19076(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19076);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20800(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20800, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0E20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-18512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18512);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,21192(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 21192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F1920) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r8,21500
	ctx.r6.s64 = ctx.r8.s64 + 21500;
	// li r10,7
	ctx.r10.s64 = 7;
	// li r5,97
	ctx.r5.s64 = 97;
	// lwz r11,21500(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 21500);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwimi r11,r7,1,24,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF00);
	// stw r11,21500(r8)
	REX_STORE_U32(ctx.r8.u32 + 21500, ctx.r11.u32);
	// stb r10,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r10.u8);
	// lwz r11,21500(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 21500);
	// rlwimi r11,r5,16,8,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFF0000) | (ctx.r11.u64 & 0xFFFFFFFFFF00FFFF);
	// stw r11,21500(r8)
	REX_STORE_U32(ctx.r8.u32 + 21500, ctx.r11.u32);
	// stb r9,21500(r8)
	REX_STORE_U8(ctx.r8.u32 + 21500, ctx.r9.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F31B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22180(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22180, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F3F10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-16808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2460(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2460);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22560(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F50A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
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
	// stfs f0,23240(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F60D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23756(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23756, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7198) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-14032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24216(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24216, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F81B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-13736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24532(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24532);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24636(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24636, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9040) {
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
	// lfs f12,24932(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24932);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25044(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25044, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FA4F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25620(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25620);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25624(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25624, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB2A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26024(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FC208) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,26468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,26472(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 26472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FCBA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26748(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26748);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26752(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FDB28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-9240
	ctx.r9.s64 = ctx.r11.s64 + -9240;
	// lfs f0,-9240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27204(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 27204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FEA98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27652(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FF898) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28060(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28060);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28064(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800938) {
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
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28428(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28428);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28544(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801C90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-8604(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8604);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,29108(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 29108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828024D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29356(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828035C0) {
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
	// lfs f0,-8344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29724(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29724);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29844(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804918) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30408(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828056F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30812(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30812);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30816(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30816, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828065A8) {
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
	// lfs f0,-7832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31160(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31160);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31244(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31244, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807910) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,31804(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31804);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,31808(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 31808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808348) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7488);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,32108(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 32108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809228) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-7384
	ctx.r9.s64 = ctx.r11.s64 + -7384;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-7384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32540(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A650) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32524);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-32408(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -32408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280BA78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6932);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280C7C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31416(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280D8F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-31020(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -31020);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30912(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30912, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E7F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6340(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6340);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30472(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280F658) {
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
	// lfs f0,-6232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30124(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30124);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30052(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810968) {
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
	// lfs f0,-5976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5976);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29600(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29600);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-29484(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -29484, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811F58) {
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
	// lfs f0,-5720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28952(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28952);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28840(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828131B0) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28352(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28352);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28292(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814238) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27772(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27772);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27768(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27768, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815328) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-27356(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27356);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27252(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27252, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82816360) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26772(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26772, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828171E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4228(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4228);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26344(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818268) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-25836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25832(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828193B0) {
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
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25400(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25400);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25320(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281A518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24804(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24804);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24800(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24800, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281B638) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24292(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24292);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24288(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281C5D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-23828(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23828);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281D6A8) {
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
	// lfs f0,-2632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23416(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23416);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23316(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23316, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281E9D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-22748(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22748);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22744(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281FA40) {
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
	// lfs f0,-2136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22376);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22264(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82820D30) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21764(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21764);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21704(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821F50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-21180(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21180);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21176(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21176, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828230C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-20676(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20676);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20672(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20672, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82823E80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20252(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20252, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82824D80) {
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
	// lfs f0,-1032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19868(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19868);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19808(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828260D8) {
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
	// lfs f0,-664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19340(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19340);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19220(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82827630) {
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
	// lfs f0,-376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18640(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18640);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18592(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18592, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828289D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-18016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18012(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18012, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829A00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-17548(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17548);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-17544(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -17544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282A358) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 164);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17272(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17272, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282B368) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-16796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16796);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16792(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282C4C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-16284(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16284);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16280(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -16280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282CD98) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16140(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -16140);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16024(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E138) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15568(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15568);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15448(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15448, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282F528) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14980(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14980);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14860(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14860, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830898) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14280(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831758) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-13848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828326D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-13384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13380(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833728) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12892(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828346F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12420(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12420, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828357A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,2448
	ctx.r9.s64 = ctx.r11.s64 + 2448;
	// lfs f0,2448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11924(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -11924, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836788) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11460(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837618) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11032(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11032, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838578) {
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
	// lfs f0,2992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10648(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10648);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10580(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828399A8) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10072(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10072);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9988(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9988, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283ADA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,3472
	ctx.r9.s64 = ctx.r11.s64 + 3472;
	// lfs f0,3472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9404(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -9404, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283BDA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3724(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3724);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8940(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8940, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283CC28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-8516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8516);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8512(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8512, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283DDF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4092(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4092);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7996(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283EC68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7572(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7572, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283FB58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7132(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7132, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82840AA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6680(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6680, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82841A98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,4832
	ctx.r9.s64 = ctx.r11.s64 + 4832;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,4832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6212(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842F58) {
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
	// lfs f12,-5720(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5720);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5604(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828442D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
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
	// stfs f0,-5024(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845310) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,5648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4532(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4532, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828462F8) {
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
	// lfs f0,5808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4116(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4116);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4060(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828475B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3516(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848670) {
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
	// lfs f0,6192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3124(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3124);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3016(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3016, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849A38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-2544(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2544);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2440(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2440, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284A930) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6660);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2000(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284B918) {
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
	// lfs f0,6784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1620(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1620);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1536(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1536, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284CC28) {
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
	// lfs f0,6992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1060(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1060);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-980(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -980, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284E0A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -364);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-360(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284EF38) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-48(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -48);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,72(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 72, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850508) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
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
	// stfs f0,736(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 736, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851588) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,8232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1224(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 1224, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851D98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// lfs f0,8312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8312);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1428(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1428);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,1448(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 1448, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853AF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
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
	// stfs f0,2320(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8285B2E0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,1368(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1368);
	// srawi r9,r4,8
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 8;
	// extsh r6,r4
	ctx.r6.s64 = ctx.r4.s16;
	// lwz r7,1464(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 1464);
	// rlwinm r10,r11,9,0,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 9) & 0xFFFFFE00;
	// rlwinm r11,r9,0,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF00;
	// mullw r5,r6,r7
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r3,r5,8
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 8;
	// addi r4,r11,-256
	ctx.r4.s64 = ctx.r11.s64 + -256;
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// rlwinm r11,r4,0,0,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFE00;
	// mullw r9,r11,r7
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// rlwinm r8,r9,0,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFE0000;
	// or r3,r8,r10
	ctx.r3.u64 = ctx.r8.u64 | ctx.r10.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828773B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// cntlzw r11,r9
	ctx.r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// vspltish v11,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_set1_epi16(short(0x3)));
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// lvsl v7,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r5,1
	ctx.r5.s64 = 1;
	// and r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmpwi cr6,r7,2
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 2, ctx.xer);
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// li r8,16
	ctx.r8.s64 = 16;
	// slw r7,r5,r11
	ctx.r7.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r11.u8 & 0x3F));
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lvsl v6,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// bne cr6,0x828774f4
	if (!ctx.cr6.eq) goto loc_828774F4;
	// lvx128 v60,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lvx128 v62,r3,r4
	ea = (ctx.r3.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v10,v62,v60,v6
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v12,v63,v61,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v59,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v5,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v10,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v4,v58,v59,v5
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vmrghb v7,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v13,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// ble cr6,0x828775d4
	if (!ctx.cr6.gt) goto loc_828775D4;
	// addi r5,r6,4
	ctx.r5.s64 = ctx.r6.s64 + 4;
	// rlwinm r3,r6,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r31,4
	ctx.r31.s64 = 4;
loc_82877440:
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// vadduhm v9,v10,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// vslh v12,v9,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// lvx128 v62,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v6,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// vperm128 v8,v63,v62,v6
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vadduhm v6,v9,v12
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrghb v12,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v57,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vadduhm v5,v6,v2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// lvsl v4,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v3,v56,v57,v4
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vadduhm v9,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vadduhm v31,v7,v12
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vor v7,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vmrghb v8,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vslh v30,v9,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubshs v29,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vadduhm v28,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v28.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vadduhm v27,v9,v30
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	// vor v10,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vadduhm v12,v5,v29
	simde_mm_store_si128((simde__m128i*)ctx.v12.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// vsubshs v26,v0,v28
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vadduhm v25,v27,v2
	simde_mm_store_si128((simde__m128i*)ctx.v25.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vor v13,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vsrah v24,v12,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vadduhm v12,v25,v26
	simde_mm_store_si128((simde__m128i*)ctx.v12.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.u16), simde_mm_load_si128((simde__m128i*)ctx.v26.u16)));
	// vpkshus128 v55,v24,v24
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v24.s16)));
	// vsrah v23,v12,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkshus128 v54,v23,v23
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v23.s16)));
	// stvewx128 v55,r0,r10
	ea = (ctx.r10.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v55.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v55,r10,r31
	ea = (ctx.r10.u32 + ctx.r31.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v55.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v54,r10,r6
	ea = (ctx.r10.u32 + ctx.r6.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v54.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v54,r10,r5
	ea = (ctx.r10.u32 + ctx.r5.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v54.u32[3 - ((ea & 0xF) >> 2)]);
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
	// blt cr6,0x82877440
	if (ctx.cr6.lt) goto loc_82877440;
	// li r3,0
	ctx.r3.s64 = 0;
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_828774F4:
	// lvx128 v50,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lvx128 v53,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lvx128 v51,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r3,r4
	ea = (ctx.r3.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v10,v53,v51,v7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v12,v52,v50,v6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvx128 v49,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v3,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v5,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v9,v48,v49,v3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// vmrglb v4,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v13,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v12,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v10,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v9,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// ble cr6,0x828775d4
	if (!ctx.cr6.gt) goto loc_828775D4;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82877544:
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// vadduhm v8,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vadduhm v7,v12,v9
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// vslh v3,v8,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v47,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v31,v7,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v46,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// lvsl v6,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v6,v46,v47,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vadduhm v3,v8,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vadduhm v31,v7,v31
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v31.u16)));
	// vmrghb v8,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vadduhm v30,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vmrglb v7,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vadduhm v29,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v29.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vadduhm v28,v5,v8
	simde_mm_store_si128((simde__m128i*)ctx.v28.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vadduhm v27,v4,v7
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v7.u16)));
	// vor v5,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vor v4,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vsubshs v26,v0,v28
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vsubshs v25,v0,v27
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// vor v13,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vor v12,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vadduhm v6,v30,v26
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v26.u16)));
	// vadduhm v3,v29,v25
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), simde_mm_load_si128((simde__m128i*)ctx.v25.u16)));
	// vor v10,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vor v9,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// vsrah v24,v6,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v23,v3,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkshus128 v45,v24,v23
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v24.s16)));
	// stvx128 v45,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// blt cr6,0x82877544
	if (ctx.cr6.lt) goto loc_82877544;
loc_828775D4:
	// li r3,0
	ctx.r3.s64 = 0;
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

