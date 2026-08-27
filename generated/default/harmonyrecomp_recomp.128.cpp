#include "harmonyrecomp_funcs.128.h"

DEFINE_REX_FUNC(sub_822182D0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82218A48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82218A50;
	__savegprlr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// bne cr6,0x82218b60
	if (!ctx.cr6.eq) goto loc_82218B60;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,22072
	ctx.r30.s64 = ctx.r11.s64 + 22072;
	// li r4,116
	ctx.r4.s64 = 116;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82218A84;
	sub_825E02A0(ctx, base);
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82218aa4
	if (ctx.cr0.eq) goto loc_82218AA4;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,-9888(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -9888);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8221d8f8
	ctx.lr = 0x82218A9C;
	sub_8221D8F8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82218aa8
	goto loc_82218AA8;
loc_82218AA4:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82218AA8:
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
	ctx.lr = 0x82218AC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lfs f13,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82218AE8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82218AF4;
	sub_82222AD8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,144
	ctx.r4.s64 = 144;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82218B04;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82218b20
	if (ctx.cr0.eq) goto loc_82218B20;
	// li r4,5
	ctx.r4.s64 = 5;
	// lfs f1,-9888(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -9888);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8221d810
	ctx.lr = 0x82218B18;
	sub_8221D810(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82218b24
	goto loc_82218B24;
loc_82218B20:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82218B24:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f13,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	ctx.lr = 0x82218B4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82218B58;
	sub_82222AD8(ctx, base);
	// li r3,49
	ctx.r3.s64 = 49;
	// b 0x82218d9c
	goto loc_82218D9C;
loc_82218B60:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82218ca0
	if (!ctx.cr6.eq) goto loc_82218CA0;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,22072
	ctx.r30.s64 = ctx.r11.s64 + 22072;
	// li r4,144
	ctx.r4.s64 = 144;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82218B80;
	sub_825E02A0(ctx, base);
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82218ba0
	if (ctx.cr0.eq) goto loc_82218BA0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,-9888(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -9888);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8221d810
	ctx.lr = 0x82218B98;
	sub_8221D810(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82218ba4
	goto loc_82218BA4;
loc_82218BA0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82218BA4:
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
	ctx.lr = 0x82218BBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82218BE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r11,213
	ctx.r11.s64 = 213;
	// sth r11,88(r31)
	REX_STORE_U16(ctx.r31.u32 + 88, ctx.r11.u16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82218bfc
	if (ctx.cr6.eq) goto loc_82218BFC;
	// sth r11,84(r10)
	REX_STORE_U16(ctx.r10.u32 + 84, ctx.r11.u16);
loc_82218BFC:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82218C08;
	sub_82222AD8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,42
	ctx.r3.s64 = 42;
	// bl 0x8257d438
	ctx.lr = 0x82218C18;
	sub_8257D438(ctx, base);
	// rlwinm. r11,r29,0,16,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xE000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82218da8
	if (ctx.cr0.eq) goto loc_82218DA8;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// li r4,116
	ctx.r4.s64 = 116;
	// bl 0x825e02a0
	ctx.lr = 0x82218C30;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82218c4c
	if (ctx.cr0.eq) goto loc_82218C4C;
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f1,-9888(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -9888);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8221d8f8
	ctx.lr = 0x82218C44;
	sub_8221D8F8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82218c50
	goto loc_82218C50;
loc_82218C4C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82218C50:
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
	ctx.lr = 0x82218C68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82218C90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82218C9C;
	sub_82222AD8(ctx, base);
	// b 0x82218da8
	goto loc_82218DA8;
loc_82218CA0:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// andc r4,r29,r10
	ctx.r4.u64 = ctx.r29.u64 & ~ctx.r10.u64;
	// addi r11,r11,-8296
	ctx.r11.s64 = ctx.r11.s64 + -8296;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82218CB8:
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// and. r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 & ctx.r4.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x82218cdc
	if (!ctx.cr0.eq) goto loc_82218CDC;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// cmplwi cr6,r10,96
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 96, ctx.xer);
	// blt cr6,0x82218cb8
	if (ctx.cr6.lt) goto loc_82218CB8;
	// b 0x82218cf0
	goto loc_82218CF0;
loc_82218CDC:
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82218648
	ctx.lr = 0x82218CEC;
	sub_82218648(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
loc_82218CF0:
	// clrlwi. r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82218da8
	if (!ctx.cr0.eq) goto loc_82218DA8;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,144
	ctx.r4.s64 = 144;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82218D10;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82218d30
	if (ctx.cr0.eq) goto loc_82218D30;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,-9888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9888);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8221d810
	ctx.lr = 0x82218D28;
	sub_8221D810(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82218d34
	goto loc_82218D34;
loc_82218D30:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82218D34:
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
	ctx.lr = 0x82218D4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82218D74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r11,213
	ctx.r11.s64 = 213;
	// sth r11,88(r31)
	REX_STORE_U16(ctx.r31.u32 + 88, ctx.r11.u16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82218d8c
	if (ctx.cr6.eq) goto loc_82218D8C;
	// sth r11,84(r10)
	REX_STORE_U16(ctx.r10.u32 + 84, ctx.r11.u16);
loc_82218D8C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82218D98;
	sub_82222AD8(ctx, base);
	// li r3,42
	ctx.r3.s64 = 42;
loc_82218D9C:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x8257d438
	ctx.lr = 0x82218DA8;
	sub_8257D438(ctx, base);
loc_82218DA8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82237840) {
	REX_FUNC_PROLOGUE();
	// addi r7,r3,500
	ctx.r7.s64 = ctx.r3.s64 + 500;
	// addi r6,r3,472
	ctx.r6.s64 = ctx.r3.s64 + 472;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// b 0x82236c80
	sub_82236C80(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82238AF8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwinm r10,r3,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFF0;
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
	// bne cr6,0x82238b48
	if (!ctx.cr6.eq) goto loc_82238B48;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82238b48
	if (ctx.cr6.eq) goto loc_82238B48;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r9,r10,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// rlwinm. r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82238b40
	if (ctx.cr0.eq) goto loc_82238B40;
loc_82238B38:
	// lwz r3,88(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// blr 
	return;
loc_82238B40:
	// rlwinm. r10,r10,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82238b38
	if (!ctx.cr0.eq) goto loc_82238B38;
loc_82238B48:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8223BB90) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r8,-13068(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -13068);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8223bc1c
	if (ctx.cr6.eq) goto loc_8223BC1C;
	// lwz r10,108(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 108);
	// addi r9,r8,104
	ctx.r9.s64 = ctx.r8.s64 + 104;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x8223bbcc
	goto loc_8223BBCC;
loc_8223BBB0:
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r7,r3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x8223bbc4
	if (!ctx.cr6.lt) goto loc_8223BBC4;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8223bbcc
	goto loc_8223BBCC;
loc_8223BBC4:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_8223BBCC:
	// lbz r7,21(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq 0x8223bbb0
	if (ctx.cr0.eq) goto loc_8223BBB0;
	// lwz r11,4(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r10.u32);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8223bbfc
	if (ctx.cr6.eq) goto loc_8223BBFC;
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8223bbfc
	if (ctx.cr6.lt) goto loc_8223BBFC;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// b 0x8223bc04
	goto loc_8223BC04;
loc_8223BBFC:
	// stw r11,-12(r1)
	REX_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// addi r11,r1,-12
	ctx.r11.s64 = ctx.r1.s64 + -12;
loc_8223BC04:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,108(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 108);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8223bc1c
	if (ctx.cr6.eq) goto loc_8223BC1C;
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// blr 
	return;
loc_8223BC1C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8223FCC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8223FCC8;
	__savegprlr_26(ctx, base);
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// bl 0x82444358
	ctx.lr = 0x8223FCDC;
	sub_82444358(ctx, base);
	// bl 0x824443c8
	ctx.lr = 0x8223FCE0;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8223fe20
	if (ctx.cr0.eq) goto loc_8223FE20;
	// lwz r27,2356(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 2356);
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// blt cr6,0x8223fe20
	if (ctx.cr6.lt) goto loc_8223FE20;
	// cmpwi cr6,r27,4
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4, ctx.xer);
	// bge cr6,0x8223fe20
	if (!ctx.cr6.lt) goto loc_8223FE20;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r28,r11,4644
	ctx.r28.s64 = ctx.r11.s64 + 4644;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
loc_8223FD10:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8242d5f8
	ctx.lr = 0x8223FD1C;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223fd30
	if (ctx.cr0.eq) goto loc_8223FD30;
	// li r11,1
	ctx.r11.s64 = 1;
	// slw r11,r11,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r30.u8 & 0x3F));
	// or r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 | ctx.r29.u64;
loc_8223FD30:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r11,r28,52
	ctx.r11.s64 = ctx.r28.s64 + 52;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8223fd10
	if (ctx.cr6.lt) goto loc_8223FD10;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8242d5f8
	ctx.lr = 0x8223FD50;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8223fe04
	if (!ctx.cr0.eq) goto loc_8223FE04;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8242d5f8
	ctx.lr = 0x8223FD64;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8223fe04
	if (!ctx.cr0.eq) goto loc_8223FE04;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8242d5f8
	ctx.lr = 0x8223FD78;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8223fe04
	if (!ctx.cr0.eq) goto loc_8223FE04;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8242d5f8
	ctx.lr = 0x8223FD8C;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8223fe04
	if (!ctx.cr0.eq) goto loc_8223FE04;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8242d760
	ctx.lr = 0x8223FDA0;
	sub_8242D760(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f30,-31476(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31476);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f1,f30
	ctx.cr6.compare(ctx.f1.f64, ctx.f30.f64);
	// bge cr6,0x8223fdb4
	if (!ctx.cr6.lt) goto loc_8223FDB4;
	// ori r29,r29,1
	ctx.r29.u64 = ctx.r29.u64 | 1;
loc_8223FDB4:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8242d760
	ctx.lr = 0x8223FDC0;
	sub_8242D760(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f31,14376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14376);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// ble cr6,0x8223fdd4
	if (!ctx.cr6.gt) goto loc_8223FDD4;
	// ori r29,r29,2
	ctx.r29.u64 = ctx.r29.u64 | 2;
loc_8223FDD4:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8242d7c8
	ctx.lr = 0x8223FDE0;
	sub_8242D7C8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// ble cr6,0x8223fdec
	if (!ctx.cr6.gt) goto loc_8223FDEC;
	// ori r29,r29,4
	ctx.r29.u64 = ctx.r29.u64 | 4;
loc_8223FDEC:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8242d7c8
	ctx.lr = 0x8223FDF8;
	sub_8242D7C8(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f30.f64);
	// bge cr6,0x8223fe04
	if (!ctx.cr6.lt) goto loc_8223FE04;
	// ori r29,r29,8
	ctx.r29.u64 = ctx.r29.u64 | 8;
loc_8223FE04:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// stw r29,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r29.u32);
	// xor r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r29.u64;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// b 0x8223fe24
	goto loc_8223FE24;
loc_8223FE20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8223FE24:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8224A690) {
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
	// ori r4,r4,62416
	ctx.r4.u64 = ctx.r4.u64 | 62416;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8224A6B8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8224a6c8
	if (ctx.cr0.eq) goto loc_8224A6C8;
	// bl 0x8224a560
	ctx.lr = 0x8224A6C4;
	sub_8224A560(ctx, base);
	// b 0x8224a6cc
	goto loc_8224A6CC;
loc_8224A6C8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8224A6CC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8224CDF0) {
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
	// bl 0x8224ce98
	ctx.lr = 0x8224CE10;
	sub_8224CE98(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8224ce28
	if (ctx.cr0.eq) goto loc_8224CE28;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8224ce28
	if (ctx.cr6.eq) goto loc_8224CE28;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8224CE28;
	sub_825E0378(ctx, base);
loc_8224CE28:
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

DEFINE_REX_FUNC(sub_8224F710) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8224F718;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r29,r3,1
	ctx.r29.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r29,-3016
	ctx.r29.s64 = ctx.r29.s64 + -3016;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8224f7e0
	if (ctx.cr6.eq) goto loc_8224F7E0;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// addi r30,r30,-3012
	ctx.r30.s64 = ctx.r30.s64 + -3012;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8224f7e0
	if (ctx.cr6.eq) goto loc_8224F7E0;
	// lbz r11,278(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 278);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8224f7e0
	if (ctx.cr0.eq) goto loc_8224F7E0;
	// bl 0x82232628
	ctx.lr = 0x8224F758;
	sub_82232628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8224f7e0
	if (!ctx.cr0.eq) goto loc_8224F7E0;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224F774;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8224f7e0
	if (!ctx.cr0.eq) goto loc_8224F7E0;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224F790;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8224f7e0
	if (!ctx.cr0.eq) goto loc_8224F7E0;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// addi r11,r11,-3040
	ctx.r11.s64 = ctx.r11.s64 + -3040;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r10,r10,62500
	ctx.r10.u64 = ctx.r10.u64 | 62500;
	// lfs f0,12468(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// ori r9,r9,62476
	ctx.r9.u64 = ctx.r9.u64 | 62476;
	// ori r8,r8,62504
	ctx.r8.u64 = ctx.r8.u64 | 62504;
	// addi r5,r5,-2072
	ctx.r5.s64 = ctx.r5.s64 + -2072;
	// li r7,1
	ctx.r7.s64 = 1;
	// stwx r6,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r6.u32);
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// stbx r7,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r7.u8);
loc_8224F7E0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822549A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x822549A8;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af28
	ctx.lr = 0x822549B0;
	__savefpr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82223a50
	ctx.lr = 0x822549BC;
	sub_82223A50(ctx, base);
	// lbz r10,104(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 104);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r29,r11,12468
	ctx.r29.s64 = ctx.r11.s64 + 12468;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82254ae8
	if (!ctx.cr0.eq) goto loc_82254AE8;
	// lis r30,-32228
	ctx.r30.s64 = -2112094208;
	// lfs f2,-232(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -232);
	ctx.f2.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r27,r30,1612
	ctx.r27.s64 = ctx.r30.s64 + 1612;
	// lfs f1,18732(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 18732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822549EC;
	sub_825A4A40(ctx, base);
	// lfs f0,16768(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 16768);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lfs f2,1612(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1612);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82254A04;
	sub_825A4A40(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,2816(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2816);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// addi r30,r11,-4080
	ctx.r30.s64 = ctx.r11.s64 + -4080;
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// lfs f2,1504(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1504);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82254A24;
	sub_825A4A40(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-30132(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30132);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-29492(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -29492);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82254A40;
	sub_825A4A40(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,144
	ctx.r4.s64 = 144;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82254A5C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82254aa4
	if (ctx.cr0.eq) goto loc_82254AA4;
	// lis r10,-8807
	ctx.r10.s64 = -577175552;
	// stfs f31,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stfs f30,108(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ori r10,r10,144
	ctx.r10.u64 = ctx.r10.u64 | 144;
	// stfs f29,112(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f28,120(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r9,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// stw r10,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// ld r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// lfs f1,244(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 244);
	ctx.f1.f64 = double(temp.f32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8221de30
	ctx.lr = 0x82254A9C;
	sub_8221DE30(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82254aa8
	goto loc_82254AA8;
loc_82254AA4:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82254AA8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82254ae0
	if (ctx.cr6.eq) goto loc_82254AE0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82254ABC;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82254ae0
	if (!ctx.cr6.eq) goto loc_82254AE0;
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
	ctx.lr = 0x82254AE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82254AE0:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,104(r31)
	REX_STORE_U8(ctx.r31.u32 + 104, ctx.r11.u8);
loc_82254AE8:
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82254b68
	if (!ctx.cr6.gt) goto loc_82254B68;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f13,100(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmadds f1,f13,f0,f12
	ctx.f1.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f12.f64)));
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82254B18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82254b54
	if (ctx.cr6.eq) goto loc_82254B54;
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lfs f13,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
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
	// bl 0x823af008
	ctx.lr = 0x82254B54;
	sub_823AF008(ctx, base);
loc_82254B54:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r11,r11,0
	ctx.r11.s64 = ctx.r11.s64 + 0;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 & ctx.r28.u64;
loc_82254B68:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af74
	ctx.lr = 0x82254B78;
	__restfpr_28(ctx, base);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8226F5D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8226F5E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r11,r11,63308
	ctx.r11.u64 = ctx.r11.u64 | 63308;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8226f690
	if (!ctx.cr6.eq) goto loc_8226F690;
	// bl 0x824281d8
	ctx.lr = 0x8226F604;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8226f66c
	if (ctx.cr0.eq) goto loc_8226F66C;
	// clrlwi r29,r30,24
	ctx.r29.u64 = ctx.r30.u32 & 0xFF;
	// bl 0x8242a5e0
	ctx.lr = 0x8226F614;
	sub_8242A5E0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8226f690
	if (!ctx.cr6.eq) goto loc_8226F690;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x824299b8
	ctx.lr = 0x8226F628;
	sub_824299B8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8226f698
	ctx.lr = 0x8226F634;
	sub_8226F698(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ori r11,r11,63293
	ctx.r11.u64 = ctx.r11.u64 | 63293;
	// stbx r3,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u8);
	// beq 0x8226f690
	if (ctx.cr0.eq) goto loc_8226F690;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8227a0c8
	ctx.lr = 0x8226F658;
	sub_8227A0C8(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,63294
	ctx.r11.u64 = ctx.r11.u64 | 63294;
	// stbx r10,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u8);
	// b 0x8226f690
	goto loc_8226F690;
loc_8226F66C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,44(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x8226f698
	ctx.lr = 0x8226F678;
	sub_8226F698(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,63293
	ctx.r11.u64 = ctx.r11.u64 | 63293;
	// ori r10,r10,63294
	ctx.r10.u64 = ctx.r10.u64 | 63294;
	// stbx r3,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u8);
	// stbx r3,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r3.u8);
loc_8226F690:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82274AB8) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3160
	ctx.r30.s64 = ctx.r30.s64 + -3160;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82274dc0
	if (ctx.cr6.lt) goto loc_82274DC0;
	// beq cr6,0x82274d10
	if (ctx.cr6.eq) goto loc_82274D10;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82274c60
	if (ctx.cr6.lt) goto loc_82274C60;
	// beq cr6,0x82274bf4
	if (ctx.cr6.eq) goto loc_82274BF4;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x82274b78
	if (ctx.cr6.lt) goto loc_82274B78;
	// beq cr6,0x82274b28
	if (ctx.cr6.eq) goto loc_82274B28;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bge cr6,0x82274e5c
	if (!ctx.cr6.lt) goto loc_82274E5C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f1,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8226f4b8
	ctx.lr = 0x82274B24;
	sub_8226F4B8(ctx, base);
	// b 0x82274e5c
	goto loc_82274E5C;
loc_82274B28:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lbz r10,73(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 73);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82274e5c
	if (!ctx.cr0.eq) goto loc_82274E5C;
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// lbz r10,73(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 73);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82274e5c
	if (!ctx.cr0.eq) goto loc_82274E5C;
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lbz r10,73(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 73);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82274e5c
	if (!ctx.cr0.eq) goto loc_82274E5C;
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// lbz r11,73(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 73);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82274e5c
	if (!ctx.cr0.eq) goto loc_82274E5C;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x82274e5c
	goto loc_82274E5C;
loc_82274B78:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,-2436
	ctx.r11.s64 = ctx.r11.s64 + -2436;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// lfs f0,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82274e5c
	if (!ctx.cr6.gt) goto loc_82274E5C;
	// li r11,5
	ctx.r11.s64 = 5;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,36(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// lfs f1,12468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8224a2a0
	ctx.lr = 0x82274BC8;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x8224a2a0
	ctx.lr = 0x82274BD4;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,56(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// bl 0x8224a2a0
	ctx.lr = 0x82274BE4;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,52(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// bl 0x8224a2a0
	ctx.lr = 0x82274BF0;
	sub_8224A2A0(ctx, base);
	// b 0x82274e5c
	goto loc_82274E5C;
loc_82274BF4:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r11,r11,-2100
	ctx.r11.s64 = ctx.r11.s64 + -2100;
	// lfs f31,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x82274e5c
	if (ctx.cr6.gt) goto loc_82274E5C;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// ori r11,r11,63282
	ctx.r11.u64 = ctx.r11.u64 | 63282;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r10,7636
	ctx.r3.s64 = ctx.r10.s64 + 7636;
	// stbx r9,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u8);
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// bl 0x8257d4d8
	ctx.lr = 0x82274C44;
	sub_8257D4D8(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,63252
	ctx.r11.u64 = ctx.r11.u64 | 63252;
	// ori r10,r10,63100
	ctx.r10.u64 = ctx.r10.u64 | 63100;
	// stwx r3,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u32);
	// stfsx f31,r31,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// b 0x82274e5c
	goto loc_82274E5C;
loc_82274C60:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r10,r10,-2344
	ctx.r10.s64 = ctx.r10.s64 + -2344;
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// lfs f0,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82274e5c
	if (!ctx.cr6.gt) goto loc_82274E5C;
	// li r10,3
	ctx.r10.s64 = 3;
	// lwz r9,264(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f1,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,36(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 36);
	// bl 0x8224a2a0
	ctx.lr = 0x82274CB0;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x8224a2a0
	ctx.lr = 0x82274CBC;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,56(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// bl 0x8224a2a0
	ctx.lr = 0x82274CCC;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,52(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// bl 0x8224a2a0
	ctx.lr = 0x82274CD8;
	sub_8224A2A0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// addi r3,r11,7624
	ctx.r3.s64 = ctx.r11.s64 + 7624;
	// bl 0x8257d4d8
	ctx.lr = 0x82274CE8;
	sub_8257D4D8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,-32216
	ctx.r11.s64 = ctx.r11.s64 + -32216;
	// ori r10,r10,63252
	ctx.r10.u64 = ctx.r10.u64 | 63252;
	// ori r9,r9,63436
	ctx.r9.u64 = ctx.r9.u64 | 63436;
	// lfs f0,18984(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18984);
	ctx.f0.f64 = double(temp.f32);
	// stwx r3,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// b 0x82274e5c
	goto loc_82274E5C;
loc_82274D10:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r11,r11,-31232
	ctx.r11.s64 = ctx.r11.s64 + -31232;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r8,-32228
	ctx.r8.s64 = -2112094208;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// lfs f0,624(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 624);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82274e5c
	if (!ctx.cr6.lt) goto loc_82274E5C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// addi r10,r10,-2272
	ctx.r10.s64 = ctx.r10.s64 + -2272;
	// lfs f31,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// stfs f31,128(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x82274da8
	if (!ctx.cr0.eq) goto loc_82274DA8;
	// lfs f1,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f1.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8227ab28
	ctx.lr = 0x82274DA8;
	sub_8227AB28(ctx, base);
loc_82274DA8:
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// ori r11,r11,63192
	ctx.r11.u64 = ctx.r11.u64 | 63192;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stfsx f31,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// b 0x82274e5c
	goto loc_82274E5C;
loc_82274DC0:
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,32720
	ctx.r10.s64 = ctx.r10.s64 + 32720;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// ori r11,r11,63264
	ctx.r11.u64 = ctx.r11.u64 | 63264;
	// addi r9,r9,-31232
	ctx.r9.s64 = ctx.r9.s64 + -31232;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stbx r6,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r6.u8);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stw r8,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_82274E5C:
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

DEFINE_REX_FUNC(sub_82299F48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82299F50;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 65536;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r31,r31,-1292
	ctx.r31.s64 = ctx.r31.s64 + -1292;
	// addi r11,r11,8960
	ctx.r11.s64 = ctx.r11.s64 + 8960;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lbz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82299f88
	if (ctx.cr0.eq) goto loc_82299F88;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8242a170
	ctx.lr = 0x82299F84;
	sub_8242A170(ctx, base);
	// stb r29,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
loc_82299F88:
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// li r28,7
	ctx.r28.s64 = 7;
	// addi r31,r31,-2364
	ctx.r31.s64 = ctx.r31.s64 + -2364;
loc_82299F94:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82299fa8
	if (ctx.cr6.eq) goto loc_82299FA8;
	// bl 0x82231d48
	ctx.lr = 0x82299FA4;
	sub_82231D48(ctx, base);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_82299FA8:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x82299f94
	if (!ctx.cr0.eq) goto loc_82299F94;
	// addis r28,r30,1
	ctx.r28.s64 = ctx.r30.s64 + 65536;
	// addi r28,r28,-2428
	ctx.r28.s64 = ctx.r28.s64 + -2428;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82217698
	ctx.lr = 0x82299FC4;
	sub_82217698(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822a5520
	ctx.lr = 0x82299FCC;
	sub_822A5520(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822a2a60
	ctx.lr = 0x82299FD8;
	sub_822A2A60(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822a2a60
	ctx.lr = 0x82299FE4;
	sub_822A2A60(ctx, base);
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-600
	ctx.r11.s64 = ctx.r11.s64 + -600;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82299ffc
	if (ctx.cr0.eq) goto loc_82299FFC;
	// stb r29,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r29.u8);
loc_82299FFC:
	// bl 0x825e04c0
	ctx.lr = 0x8229A000;
	sub_825E04C0(ctx, base);
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-648
	ctx.r11.s64 = ctx.r11.s64 + -648;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8229a018
	if (ctx.cr0.eq) goto loc_8229A018;
	// stb r29,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r29.u8);
loc_8229A018:
	// bl 0x825e04c0
	ctx.lr = 0x8229A01C;
	sub_825E04C0(ctx, base);
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-688
	ctx.r11.s64 = ctx.r11.s64 + -688;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8229a034
	if (ctx.cr0.eq) goto loc_8229A034;
	// stb r29,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r29.u8);
loc_8229A034:
	// bl 0x825e04c0
	ctx.lr = 0x8229A038;
	sub_825E04C0(ctx, base);
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-728
	ctx.r11.s64 = ctx.r11.s64 + -728;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8229a050
	if (ctx.cr0.eq) goto loc_8229A050;
	// stb r29,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r29.u8);
loc_8229A050:
	// bl 0x825e04c0
	ctx.lr = 0x8229A054;
	sub_825E04C0(ctx, base);
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-776
	ctx.r11.s64 = ctx.r11.s64 + -776;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8229a06c
	if (ctx.cr0.eq) goto loc_8229A06C;
	// stb r29,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r29.u8);
loc_8229A06C:
	// bl 0x825e04c0
	ctx.lr = 0x8229A070;
	sub_825E04C0(ctx, base);
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-812
	ctx.r11.s64 = ctx.r11.s64 + -812;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8229a088
	if (ctx.cr0.eq) goto loc_8229A088;
	// stb r29,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r29.u8);
loc_8229A088:
	// bl 0x825e04c0
	ctx.lr = 0x8229A08C;
	sub_825E04C0(ctx, base);
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-848
	ctx.r11.s64 = ctx.r11.s64 + -848;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8229a0a4
	if (ctx.cr0.eq) goto loc_8229A0A4;
	// stb r29,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r29.u8);
loc_8229A0A4:
	// bl 0x825e04c0
	ctx.lr = 0x8229A0A8;
	sub_825E04C0(ctx, base);
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-884
	ctx.r11.s64 = ctx.r11.s64 + -884;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8229a0c0
	if (ctx.cr0.eq) goto loc_8229A0C0;
	// stb r29,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r29.u8);
loc_8229A0C0:
	// bl 0x825e04c0
	ctx.lr = 0x8229A0C4;
	sub_825E04C0(ctx, base);
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-948
	ctx.r11.s64 = ctx.r11.s64 + -948;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8229a0dc
	if (ctx.cr0.eq) goto loc_8229A0DC;
	// stb r29,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r29.u8);
loc_8229A0DC:
	// bl 0x825e04c0
	ctx.lr = 0x8229A0E0;
	sub_825E04C0(ctx, base);
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// addi r31,r31,-2324
	ctx.r31.s64 = ctx.r31.s64 + -2324;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8229a0f8
	if (ctx.cr6.eq) goto loc_8229A0F8;
	// bl 0x825e0378
	ctx.lr = 0x8229A0F8;
	sub_825E0378(ctx, base);
loc_8229A0F8:
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8229a114
	if (ctx.cr6.eq) goto loc_8229A114;
	// bl 0x825e0378
	ctx.lr = 0x8229A114;
	sub_825E0378(ctx, base);
loc_8229A114:
	// stw r29,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
	// stw r29,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r29.u32);
	// bl 0x82231c80
	ctx.lr = 0x8229A128;
	sub_82231C80(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822A5760) {
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
	// addis r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 65536;
	// li r11,6
	ctx.r11.s64 = 6;
	// addi r31,r31,-988
	ctx.r31.s64 = ctx.r31.s64 + -988;
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stb r11,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r11.u8);
	// bl 0x82429a18
	ctx.lr = 0x822A578C;
	sub_82429A18(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lfs f0,20068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20068);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,1(r30)
	REX_STORE_U32(ctx.r30.u32 + 1, ctx.r11.u32);
	// bl 0x8242a5e0
	ctx.lr = 0x822A57AC;
	sub_8242A5E0(ctx, base);
	// stb r3,5(r30)
	REX_STORE_U8(ctx.r30.u32 + 5, ctx.r3.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,6
	ctx.r5.s64 = 6;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x82429ff8
	ctx.lr = 0x822A57C4;
	sub_82429FF8(ctx, base);
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

DEFINE_REX_FUNC(sub_822A7BF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x822A7BF8;
	__savegprlr_21(ctx, base);
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8273af28
	ctx.lr = 0x822A7C00;
	__savefpr_28(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r23,r3,1
	ctx.r23.s64 = ctx.r3.s64 + 65536;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r23,r23,-3164
	ctx.r23.s64 = ctx.r23.s64 + -3164;
	// addi r22,r11,15180
	ctx.r22.s64 = ctx.r11.s64 + 15180;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r21,r11,-7108
	ctx.r21.s64 = ctx.r11.s64 + -7108;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lfs f28,-2708(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2708);
	ctx.f28.f64 = double(temp.f32);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x822a7f94
	if (ctx.cr6.eq) goto loc_822A7F94;
	// addis r24,r3,1
	ctx.r24.s64 = ctx.r3.s64 + 65536;
	// addi r24,r24,-3160
	ctx.r24.s64 = ctx.r24.s64 + -3160;
	// lbz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822a7f74
	if (ctx.cr0.eq) goto loc_822A7F74;
	// addis r27,r3,1
	ctx.r27.s64 = ctx.r3.s64 + 65536;
	// addis r26,r3,1
	ctx.r26.s64 = ctx.r3.s64 + 65536;
	// addi r27,r27,-3152
	ctx.r27.s64 = ctx.r27.s64 + -3152;
	// addi r26,r26,-3140
	ctx.r26.s64 = ctx.r26.s64 + -3140;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-3104
	ctx.r4.s64 = ctx.r4.s64 + -3104;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// stfs f0,0(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// lfs f1,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f2,f1,f0
	ctx.f2.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// bl 0x825a5d18
	ctx.lr = 0x822A7C7C;
	sub_825A5D18(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// ori r11,r11,64244
	ctx.r11.u64 = ctx.r11.u64 | 64244;
	// stw r10,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// beq 0x822a7d0c
	if (ctx.cr0.eq) goto loc_822A7D0C;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8dd8
	ctx.lr = 0x822A7CCC;
	sub_822A8DD8(ctx, base);
	// lfs f0,19324(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 19324);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fsubs f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x822a7ce8
	if (ctx.cr6.lt) goto loc_822A7CE8;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822A7CE8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822a7d0c
	if (ctx.cr0.eq) goto loc_822A7D0C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-11424
	ctx.r11.s64 = ctx.r11.s64 + -11424;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
loc_822A7D0C:
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// lfs f29,-2944(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2944);
	ctx.f29.f64 = double(temp.f32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r25,r25,-3156
	ctx.r25.s64 = ctx.r25.s64 + -3156;
	// ori r28,r11,64596
	ctx.r28.u64 = ctx.r11.u64 | 64596;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x822a7e3c
	if (ctx.cr6.eq) goto loc_822A7E3C;
	// lwzx r11,r31,r28
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
	// add r30,r31,r28
	ctx.r30.u64 = ctx.r31.u64 + ctx.r28.u64;
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// bl 0x8225f588
	ctx.lr = 0x822A7D3C;
	sub_8225F588(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822a7e3c
	if (ctx.cr0.eq) goto loc_822A7E3C;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// addi r4,r10,2880
	ctx.r4.s64 = ctx.r10.s64 + 2880;
	// bl 0x8255a7f0
	ctx.lr = 0x822A7D58;
	sub_8255A7F0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822a7d84
	if (ctx.cr0.eq) goto loc_822A7D84;
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r5,r31,88
	ctx.r5.s64 = ctx.r31.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r29,24
	ctx.r4.s64 = ctx.r29.s64 + 24;
	// bl 0x82322d08
	ctx.lr = 0x822A7D74;
	sub_82322D08(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,16(r29)
	REX_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r11.u32);
loc_822A7D84:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lfs f12,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f0,f29,f0
	ctx.f0.f64 = double(float(ctx.f29.f64 - ctx.f0.f64));
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
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x82322d08
	ctx.lr = 0x822A7E2C;
	sub_82322D08(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
loc_822A7E3C:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,-2712(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -2712);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x822a7f80
	if (!ctx.cr6.lt) goto loc_822A7F80;
	// bl 0x8242a5e0
	ctx.lr = 0x822A7E50;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822a7e60
	if (!ctx.cr0.eq) goto loc_822A7E60;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x822a7e64
	goto loc_822A7E64;
loc_822A7E60:
	// bl 0x8242aa28
	ctx.lr = 0x822A7E64;
	sub_8242AA28(ctx, base);
loc_822A7E64:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lis r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ori r30,r10,62392
	ctx.r30.u64 = ctx.r10.u64 | 62392;
	// beq cr6,0x822a7f40
	if (ctx.cr6.eq) goto loc_822A7F40;
	// bne 0x822a7ed0
	if (!ctx.cr0.eq) goto loc_822A7ED0;
	// lwzx r11,r31,r28
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
	// add r8,r31,r28
	ctx.r8.u64 = ctx.r31.u64 + ctx.r28.u64;
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// bl 0x8225f588
	ctx.lr = 0x822A7E90;
	sub_8225F588(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822a7f40
	if (ctx.cr0.eq) goto loc_822A7F40;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// stw r9,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r9.u32);
	// lwz r9,28(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// stw r9,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r9.u32);
	// ld r10,3456(r10)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// std r10,24(r11)
	REX_STORE_U64(ctx.r11.u32 + 24, ctx.r10.u64);
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lbz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 12);
	// stbx r11,r31,r30
	REX_STORE_U8(ctx.r31.u32 + ctx.r30.u32, ctx.r11.u8);
	// bl 0x822b2a28
	ctx.lr = 0x822A7ECC;
	sub_822B2A28(ctx, base);
	// b 0x822a7f40
	goto loc_822A7F40;
loc_822A7ED0:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// li r11,2
	ctx.r11.s64 = 2;
	// addi r29,r29,-976
	ctx.r29.s64 = ctx.r29.s64 + -976;
	// lwz r28,0(r29)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stb r11,0(r28)
	REX_STORE_U8(ctx.r28.u32 + 0, ctx.r11.u8);
	// bl 0x82429a18
	ctx.lr = 0x822A7EE8;
	sub_82429A18(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
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
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,1(r28)
	REX_STORE_U32(ctx.r28.u32 + 1, ctx.r11.u32);
	// lbzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r30.u32);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,5(r28)
	REX_STORE_U8(ctx.r28.u32 + 5, ctx.r11.u8);
	// bl 0x82428150
	ctx.lr = 0x822A7F20;
	sub_82428150(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,10
	ctx.r5.s64 = 10;
	// li r3,10
	ctx.r3.s64 = 10;
	// stw r11,6(r28)
	REX_STORE_U32(ctx.r28.u32 + 6, ctx.r11.u32);
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x82429ff8
	ctx.lr = 0x822A7F3C;
	sub_82429FF8(ctx, base);
	// stfs f31,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
loc_822A7F40:
	// li r10,0
	ctx.r10.s64 = 0;
	// lbzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r30.u32);
	// stb r10,0(r24)
	REX_STORE_U8(ctx.r24.u32 + 0, ctx.r10.u8);
	// stfs f31,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 124, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822a7f60
	if (ctx.cr0.eq) goto loc_822A7F60;
	// stfs f29,120(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// b 0x822a7f64
	goto loc_822A7F64;
loc_822A7F60:
	// stfs f28,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 120, temp.u32);
loc_822A7F64:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,0(r25)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// bl 0x822a91c8
	ctx.lr = 0x822A7F70;
	sub_822A91C8(ctx, base);
	// b 0x822a7f80
	goto loc_822A7F80;
loc_822A7F74:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822a94b0
	ctx.lr = 0x822A7F80;
	sub_822A94B0(ctx, base);
loc_822A7F80:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822aa7a0
	ctx.lr = 0x822A7F88;
	sub_822AA7A0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822b36e8
	ctx.lr = 0x822A7F94;
	sub_822B36E8(ctx, base);
loc_822A7F94:
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x822a8084
	if (ctx.cr6.gt) goto loc_822A8084;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-5568
	ctx.r12.s64 = ctx.r12.s64 + -5568;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// lis r12,-32214
	ctx.r12.s64 = -2111176704;
	// nop 
	// addi r12,r12,32716
	ctx.r12.s64 = ctx.r12.s64 + 32716;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_822A7FCC;
	case 1:
		goto loc_822A7FD8;
	case 2:
		goto loc_822A7FE8;
	case 3:
		goto loc_822A7FF8;
	case 4:
		goto loc_822A8008;
	case 5:
		goto loc_822A8018;
	case 6:
		goto loc_822A8028;
	case 7:
		goto loc_822A8038;
	case 8:
		goto loc_822A8048;
	case 9:
		goto loc_822A8058;
	case 10:
		goto loc_822A8068;
	case 11:
		goto loc_822A8078;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_822A7FCC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822aaa18
	ctx.lr = 0x822A7FD4;
	sub_822AAA18(ctx, base);
	// b 0x822a8084
	goto loc_822A8084;
loc_822A7FD8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822aaad0
	ctx.lr = 0x822A7FE4;
	sub_822AAAD0(ctx, base);
	// b 0x822a8084
	goto loc_822A8084;
loc_822A7FE8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822ab450
	ctx.lr = 0x822A7FF4;
	sub_822AB450(ctx, base);
	// b 0x822a8084
	goto loc_822A8084;
loc_822A7FF8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822aba90
	ctx.lr = 0x822A8004;
	sub_822ABA90(ctx, base);
	// b 0x822a8084
	goto loc_822A8084;
loc_822A8008:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822abe00
	ctx.lr = 0x822A8014;
	sub_822ABE00(ctx, base);
	// b 0x822a8084
	goto loc_822A8084;
loc_822A8018:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822ac6e8
	ctx.lr = 0x822A8024;
	sub_822AC6E8(ctx, base);
	// b 0x822a8084
	goto loc_822A8084;
loc_822A8028:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822ad448
	ctx.lr = 0x822A8034;
	sub_822AD448(ctx, base);
	// b 0x822a8084
	goto loc_822A8084;
loc_822A8038:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822adcf8
	ctx.lr = 0x822A8044;
	sub_822ADCF8(ctx, base);
	// b 0x822a8084
	goto loc_822A8084;
loc_822A8048:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822ae1a8
	ctx.lr = 0x822A8054;
	sub_822AE1A8(ctx, base);
	// b 0x822a8084
	goto loc_822A8084;
loc_822A8058:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822ae968
	ctx.lr = 0x822A8064;
	sub_822AE968(ctx, base);
	// b 0x822a8084
	goto loc_822A8084;
loc_822A8068:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822aefb0
	ctx.lr = 0x822A8074;
	sub_822AEFB0(ctx, base);
	// b 0x822a8084
	goto loc_822A8084;
loc_822A8078:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822af830
	ctx.lr = 0x822A8084;
	sub_822AF830(ctx, base);
loc_822A8084:
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lfs f1,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// beq cr6,0x822a80a4
	if (ctx.cr6.eq) goto loc_822A80A4;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bne cr6,0x822a80a8
	if (!ctx.cr6.eq) goto loc_822A80A8;
	// lfs f1,0(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// b 0x822a80a8
	goto loc_822A80A8;
loc_822A80A4:
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f28.f64;
loc_822A80A8:
	// addi r5,r31,88
	ctx.r5.s64 = ctx.r31.s64 + 88;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f30.f64;
	// addi r4,r31,128
	ctx.r4.s64 = ctx.r31.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822b2178
	ctx.lr = 0x822A80BC;
	sub_822B2178(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x8273af74
	ctx.lr = 0x822A80C8;
	__restfpr_28(ctx, base);
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822CE828) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x822CE830;
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
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x823bfa70
	ctx.lr = 0x822CE854;
	sub_823BFA70(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r30,0
	ctx.r30.s64 = 0;
	// bl 0x8222ff78
	ctx.lr = 0x822CE870;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x822CE88C;
	sub_8222FF78(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f30,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822CE8B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 128);
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
	// lfs f12,12468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bgt cr6,0x822ce8f8
	if (ctx.cr6.gt) goto loc_822CE8F8;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822CE8F8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r11,r11,624
	ctx.r11.s64 = ctx.r11.s64 + 624;
	// lfs f5,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// beq 0x822ce928
	if (ctx.cr0.eq) goto loc_822CE928;
	// lwa r10,120(r1)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 120));
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fadds f13,f13,f5
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f5.f64));
	// b 0x822ce940
	goto loc_822CE940;
loc_822CE928:
	// lwa r10,112(r1)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 112));
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f13,f13,f5
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f5.f64));
loc_822CE940:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fadds f6,f13,f31
	ctx.f6.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bgt cr6,0x822ce978
	if (ctx.cr6.gt) goto loc_822CE978;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822CE978:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,-13032
	ctx.r11.s64 = ctx.r11.s64 + -13032;
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822ce9dc
	if (ctx.cr6.eq) goto loc_822CE9DC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// beq 0x822ce9c0
	if (ctx.cr0.eq) goto loc_822CE9C0;
	// fctiwz f0,f6
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// fctiwz f0,f30
	ctx.f0.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823ae578
	ctx.lr = 0x822CE9BC;
	sub_823AE578(ctx, base);
	// b 0x822ce9dc
	goto loc_822CE9DC;
loc_822CE9C0:
	// fctiwz f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// fctiwz f0,f6
	ctx.f0.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823ae2c0
	ctx.lr = 0x822CE9DC;
	sub_823AE2C0(ctx, base);
loc_822CE9DC:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x822cea30
	if (!ctx.cr6.eq) goto loc_822CEA30;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822cea28
	if (ctx.cr6.eq) goto loc_822CEA28;
	// lwa r11,124(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 124));
	// fctiwz f0,f6
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f0,f0,f5
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f5.f64));
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823af008
	ctx.lr = 0x822CEA28;
	sub_823AF008(ctx, base);
loc_822CEA28:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822cea34
	if (!ctx.cr0.eq) goto loc_822CEA34;
loc_822CEA30:
	// li r30,1
	ctx.r30.s64 = 1;
loc_822CEA34:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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

DEFINE_REX_FUNC(sub_822DDFA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x822DDFA8;
	__savegprlr_29(ctx, base);
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x8273af28
	ctx.lr = 0x822DDFB0;
	__savefpr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f31,f3
	ctx.f31.f64 = ctx.f3.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f29,f4
	ctx.f29.f64 = ctx.f4.f64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x822DDFDC;
	sub_8222FF78(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f0,96(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
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
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f28,140(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f28,136(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f28,132(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f28,128(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
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
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vcmpgefp128. v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822de260
	if (ctx.cr0.eq) goto loc_822DE260;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x822DE054;
	sub_8222FF78(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f0,96(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
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
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,132(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vcmpgefp128. v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822de260
	if (ctx.cr0.eq) goto loc_822DE260;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x822DE0CC;
	sub_8222FF78(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,100(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f30,116(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f30,112(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f30,124(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgefp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822de260
	if (ctx.cr0.eq) goto loc_822DE260;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x822DE144;
	sub_8222FF78(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f29,140(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f29,136(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f0,100(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
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
	// stfs f29,132(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f29,128(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgefp128. v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822de260
	if (ctx.cr0.eq) goto loc_822DE260;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8222ff78
	ctx.lr = 0x822DE1BC;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x822DE1D8;
	sub_8222FF78(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r31,-13032(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822de214
	if (ctx.cr6.eq) goto loc_822DE214;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f31
	ctx.f13.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x822DE210;
	sub_823AEFA8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_822DE214:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822de248
	if (ctx.cr6.eq) goto loc_822DE248;
	// lfs f0,96(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f0,100(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x822DE248;
	sub_823AEFA8(ctx, base);
loc_822DE248:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r29,24
	ctx.r10.u64 = ctx.r29.u32 & 0xFF;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// b 0x822de264
	goto loc_822DE264;
loc_822DE260:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822DE264:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x8273af74
	ctx.lr = 0x822DE270;
	__restfpr_28(ctx, base);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822FE2C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x822FE2C8;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r29,r3,1
	ctx.r29.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r29,r29,-2996
	ctx.r29.s64 = ctx.r29.s64 + -2996;
	// ori r30,r11,62440
	ctx.r30.u64 = ctx.r11.u64 | 62440;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822fe3d8
	if (ctx.cr0.eq) goto loc_822FE3D8;
	// bl 0x82300ef0
	ctx.lr = 0x822FE2FC;
	sub_82300EF0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r8,98
	ctx.r8.s64 = 98;
	// bne 0x822fe520
	if (!ctx.cr0.eq) goto loc_822FE520;
	// lwzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
	// stw r8,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r8.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stw r9,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r9.u32);
	// stw r28,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r28.u32);
	// stb r28,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r28.u8);
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
	// lwzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x822fe39c
	if (!ctx.cr6.eq) goto loc_822FE39C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// addi r9,r9,32688
	ctx.r9.s64 = ctx.r9.s64 + 32688;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
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
	// b 0x822fe3cc
	goto loc_822FE3CC;
loc_822FE39C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r11,r11,32608
	ctx.r11.s64 = ctx.r11.s64 + 32608;
	// addi r9,r9,32720
	ctx.r9.s64 = ctx.r9.s64 + 32720;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
loc_822FE3CC:
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stb r28,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r28.u8);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_822FE3D8:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// add r30,r31,r30
	ctx.r30.u64 = ctx.r31.u64 + ctx.r30.u64;
	// addi r10,r10,-3076
	ctx.r10.s64 = ctx.r10.s64 + -3076;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm. r10,r10,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x822fe418
	if (ctx.cr0.eq) goto loc_822FE418;
	// lwz r9,72(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r10,r9,1
	ctx.r10.u64 = ctx.r9.u64 | 1;
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// bl 0x82300580
	ctx.lr = 0x822FE418;
	sub_82300580(ctx, base);
loc_822FE418:
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,88(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x822fe42c
	if (ctx.cr6.gt) goto loc_822FE42C;
	// lwz r11,136(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 136);
loc_822FE42C:
	// lwz r9,72(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 72);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm. r9,r9,29,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x822fe448
	if (ctx.cr0.eq) goto loc_822FE448;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x822fe44c
	if (ctx.cr6.eq) goto loc_822FE44C;
loc_822FE448:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_822FE44C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822fe48c
	if (!ctx.cr0.eq) goto loc_822FE48C;
	// lwz r11,88(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x822fe464
	if (ctx.cr6.gt) goto loc_822FE464;
	// lwz r11,136(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 136);
loc_822FE464:
	// lwz r10,72(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 72);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm. r10,r10,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x822fe480
	if (ctx.cr0.eq) goto loc_822FE480;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x822fe484
	if (ctx.cr6.eq) goto loc_822FE484;
loc_822FE480:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_822FE484:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822fe514
	if (ctx.cr0.eq) goto loc_822FE514;
loc_822FE48C:
	// ld r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 88);
	// li r3,160
	ctx.r3.s64 = 160;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82240a58
	ctx.lr = 0x822FE4C4;
	sub_82240A58(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r28,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// bl 0x823bb008
	ctx.lr = 0x822FE4DC;
	sub_823BB008(ctx, base);
	// lwa r10,96(r1)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 96));
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lwa r11,80(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 80));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x823013a0
	ctx.lr = 0x822FE514;
	sub_823013A0(ctx, base);
loc_822FE514:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
loc_822FE520:
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r9,r9,-3096
	ctx.r9.s64 = ctx.r9.s64 + -3096;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r7,15
	ctx.r7.s64 = 15;
	// addi r5,r10,32720
	ctx.r5.s64 = ctx.r10.s64 + 32720;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r28.u32);
	// stw r8,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r8.u32);
	// stb r28,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r28.u8);
	// stw r7,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r7.u32);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r10,r10,0,31,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF1;
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lwz r9,72(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r9.u32);
	// std r10,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r10.u64);
	// bl 0x82300580
	ctx.lr = 0x822FE5B0;
	sub_82300580(ctx, base);
	// b 0x822fe514
	goto loc_822FE514;
}

DEFINE_REX_FUNC(sub_8230FEC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8230FED0;
	__savegprlr_24(ctx, base);
	// li r12,-112
	ctx.r12.s64 = -112;
	// stvx128 v126,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-96
	ctx.r12.s64 = -96;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r11,r11,62445
	ctx.r11.u64 = ctx.r11.u64 | 62445;
	// lbzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8230ffd4
	if (!ctx.cr0.eq) goto loc_8230FFD4;
	// lwz r11,248(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8230FF14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,21
	ctx.r4.s64 = 21;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// bl 0x823c29d8
	ctx.lr = 0x8230FF24;
	sub_823C29D8(ctx, base);
	// li r11,255
	ctx.r11.s64 = 255;
	// li r25,0
	ctx.r25.s64 = 0;
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// addi r27,r27,-3088
	ctx.r27.s64 = ctx.r27.s64 + -3088;
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// addi r30,r30,-3080
	ctx.r30.s64 = ctx.r30.s64 + -3080;
	// stb r25,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r25.u8);
	// li r26,10
	ctx.r26.s64 = 10;
loc_8230FF50:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r24,0(r11)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r28,0(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// bl 0x8222ff78
	ctx.lr = 0x8230FF74;
	sub_8222FF78(ctx, base);
	// addi r11,r29,16017
	ctx.r11.s64 = ctx.r29.s64 + 16017;
	// lwz r10,24(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r7,0(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// ld r4,0(r5)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r5.u32 + 0);
	// lfsx f1,r11,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	ctx.f1.f64 = double(temp.f32);
	// bctrl 
	ctx.lr = 0x8230FFA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,67
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 67, ctx.xer);
	// blt cr6,0x8230ffc0
	if (ctx.cr6.lt) goto loc_8230FFC0;
	// stw r25,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
loc_8230FFC0:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x8230ff50
	if (!ctx.cr0.eq) goto loc_8230FF50;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82231a30
	ctx.lr = 0x8230FFD0;
	sub_82231A30(ctx, base);
	// b 0x823100d8
	goto loc_823100D8;
loc_8230FFD4:
	// vspltisw128 v127,-1
	simde_mm_store_si128((simde__m128i*)ctx.v127.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// li r11,255
	ctx.r11.s64 = 255;
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// li r29,0
	ctx.r29.s64 = 0;
	// vslw128 v126,v127,v127
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_sllv_epi32(a, shift));
	}
	// addi r27,r27,-3088
	ctx.r27.s64 = ctx.r27.s64 + -3088;
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// addi r28,r28,-1472
	ctx.r28.s64 = ctx.r28.s64 + -1472;
	// addi r30,r30,-3084
	ctx.r30.s64 = ctx.r30.s64 + -3084;
loc_82310008:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// vslw128 v63,v127,v127
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lfs f0,1084(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1084);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f13,1080(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1080);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v63,v126
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v126.u8)));
	// lwz r11,160(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lhz r5,94(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 94);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lhz r4,102(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82310094;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,808(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 808);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// ldu r4,8(r30)
	ea = 8 + ctx.r30.u32;
	ctx.r4.u64 = REX_LOAD_U64(ea);
	ctx.r30.u32 = ea;
	// lfsu f1,4(r28)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r28.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f1.f64 = double(temp.f32);
	ctx.r28.u32 = ea;
	// lwz r7,0(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823100CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r29,67
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 67, ctx.xer);
	// blt cr6,0x82310008
	if (ctx.cr6.lt) goto loc_82310008;
loc_823100D8:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// li r0,-112
	ctx.r0.s64 = -112;
	// lvx128 v126,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-96
	ctx.r0.s64 = -96;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8232A4C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8232A4C8;
	__savegprlr_23(ctx, base);
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f30.u64);
	// stfd f31,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r27,r3,1
	ctx.r27.s64 = ctx.r3.s64 + 65536;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r27,r27,-3152
	ctx.r27.s64 = ctx.r27.s64 + -3152;
	// addi r26,r11,12236
	ctx.r26.s64 = ctx.r11.s64 + 12236;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r9,0(r27)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// li r24,1
	ctx.r24.s64 = 1;
	// lfs f31,232(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// li r25,0
	ctx.r25.s64 = 0;
	// clrlwi. r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ori r28,r10,62392
	ctx.r28.u64 = ctx.r10.u64 | 62392;
	// ori r29,r11,62372
	ctx.r29.u64 = ctx.r11.u64 | 62372;
	// beq 0x8232a6cc
	if (ctx.cr0.eq) goto loc_8232A6CC;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x8232A534;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f1,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,236(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8232A550;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8224a2a0
	ctx.lr = 0x8232A570;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r23,4(r11)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,0(r23)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8232A590;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,112(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 112);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8232A5A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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
	ctx.lr = 0x8232A5C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8232ab38
	ctx.lr = 0x8232A5D4;
	sub_8232AB38(ctx, base);
	// ld r4,88(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8232ac88
	ctx.lr = 0x8232A5E0;
	sub_8232AC88(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232a644
	if (ctx.cr0.eq) goto loc_8232A644;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x8232a620
	if (ctx.cr6.lt) goto loc_8232A620;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_8232A620:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// beq 0x8232a660
	if (ctx.cr0.eq) goto loc_8232A660;
loc_8232A634:
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232a684
	if (ctx.cr0.eq) goto loc_8232A684;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8232a66c
	goto loc_8232A66C;
loc_8232A644:
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r11,r11,-29280
	ctx.r11.s64 = ctx.r11.s64 + -29280;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// beq cr6,0x8232a634
	if (ctx.cr6.eq) goto loc_8232A634;
loc_8232A660:
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232a684
	if (ctx.cr0.eq) goto loc_8232A684;
	// li r4,2
	ctx.r4.s64 = 2;
loc_8232A66C:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8232A684;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8232A684:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lbz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfsx f31,r31,r29
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// stwx r25,r31,r28
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, ctx.r25.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r10,0(r27)
	REX_STORE_U8(ctx.r27.u32 + 0, ctx.r10.u8);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_8232A6CC:
	// lfsx f0,r31,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	ctx.f0.f64 = double(temp.f32);
	// lwzx r11,r31,r28
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// stfsx f0,r31,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
	// add r10,r31,r29
	ctx.r10.u64 = ctx.r31.u64 + ctx.r29.u64;
	// add r30,r31,r28
	ctx.r30.u64 = ctx.r31.u64 + ctx.r28.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8232a880
	if (ctx.cr6.lt) goto loc_8232A880;
	// beq cr6,0x8232a820
	if (ctx.cr6.eq) goto loc_8232A820;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8232a78c
	if (ctx.cr6.lt) goto loc_8232A78C;
	// beq cr6,0x8232a734
	if (ctx.cr6.eq) goto loc_8232A734;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x8232a8e4
	if (!ctx.cr6.lt) goto loc_8232A8E4;
	// lfs f13,2140(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 2140);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8232a8e4
	if (!ctx.cr6.gt) goto loc_8232A8E4;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lbz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// lis r9,-32205
	ctx.r9.s64 = -2110586880;
	// ori r11,r11,62380
	ctx.r11.u64 = ctx.r11.u64 | 62380;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// addi r9,r9,-24160
	ctx.r9.s64 = ctx.r9.s64 + -24160;
	// stb r10,0(r27)
	REX_STORE_U8(ctx.r27.u32 + 0, ctx.r10.u8);
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
	// b 0x8232a8e4
	goto loc_8232A8E4;
loc_8232A734:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,-11996(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11996);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8232a8e4
	if (!ctx.cr6.gt) goto loc_8232A8E4;
	// stfs f31,0(r10)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x8232A768;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8232A784;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x8232a878
	goto loc_8232A878;
loc_8232A78C:
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// ori r9,r9,62404
	ctx.r9.u64 = ctx.r9.u64 | 62404;
	// lwzx r9,r31,r9
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bne cr6,0x8232a7a8
	if (!ctx.cr6.eq) goto loc_8232A7A8;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8232A7A8:
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// bne cr6,0x8232a7b4
	if (!ctx.cr6.eq) goto loc_8232A7B4;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8232A7B4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232a8e4
	if (ctx.cr0.eq) goto loc_8232A8E4;
	// lis r11,0
	ctx.r11.s64 = 0;
	// stfs f31,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// ori r11,r11,62396
	ctx.r11.u64 = ctx.r11.u64 | 62396;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// stwx r25,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r25.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x8232A7EC;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8224a2a0
	ctx.lr = 0x8232A7FC;
	sub_8224A2A0(ctx, base);
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
	ctx.lr = 0x8232A818;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x8232a878
	goto loc_8232A878;
loc_8232A820:
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// ori r9,r9,62404
	ctx.r9.u64 = ctx.r9.u64 | 62404;
	// lwzx r9,r31,r9
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x8232a83c
	if (!ctx.cr6.eq) goto loc_8232A83C;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8232A83C:
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// bne cr6,0x8232a848
	if (!ctx.cr6.eq) goto loc_8232A848;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8232A848:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232a8e4
	if (ctx.cr0.eq) goto loc_8232A8E4;
	// stfs f31,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x8232A874;
	sub_8224A2A0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
loc_8232A878:
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x8232a8e4
	goto loc_8232A8E4;
loc_8232A880:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-11996
	ctx.r11.s64 = ctx.r11.s64 + -11996;
	// lfs f13,-16880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16880);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8232a8e4
	if (!ctx.cr6.gt) goto loc_8232A8E4;
	// lis r11,0
	ctx.r11.s64 = 0;
	// stfs f31,0(r10)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// ori r11,r11,62400
	ctx.r11.u64 = ctx.r11.u64 | 62400;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// stbx r24,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r24.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x8232A8C4;
	sub_8224A2A0(ctx, base);
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
	ctx.lr = 0x8232A8E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r24,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r24.u32);
loc_8232A8E4:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82342AB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82342AC0;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r11,4320
	ctx.r29.s64 = ctx.r11.s64 + 4320;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8222fa58
	ctx.lr = 0x82342AD8;
	sub_8222FA58(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r9,-3160
	ctx.r9.s64 = ctx.r9.s64 + -3160;
	// addi r8,r8,-3148
	ctx.r8.s64 = ctx.r8.s64 + -3148;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r10,18584
	ctx.r10.s64 = ctx.r10.s64 + 18584;
	// stwx r30,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r30,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r30.u32);
	// addi r3,r3,-3140
	ctx.r3.s64 = ctx.r3.s64 + -3140;
	// stb r30,4(r9)
	REX_STORE_U8(ctx.r9.u32 + 4, ctx.r30.u8);
	// stb r30,5(r9)
	REX_STORE_U8(ctx.r9.u32 + 5, ctx.r30.u8);
	// stb r30,6(r9)
	REX_STORE_U8(ctx.r9.u32 + 6, ctx.r30.u8);
	// stw r30,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r30.u32);
	// stb r30,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r30.u8);
	// stb r30,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r30.u8);
	// sth r30,2(r8)
	REX_STORE_U16(ctx.r8.u32 + 2, ctx.r30.u16);
	// stw r30,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r30.u32);
	// bl 0x822131a0
	ctx.lr = 0x82342B34;
	sub_822131A0(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3108
	ctx.r11.s64 = ctx.r11.s64 + -3108;
	// addi r3,r3,-3100
	ctx.r3.s64 = ctx.r3.s64 + -3100;
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// sth r30,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r30.u16);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x822131a0
	ctx.lr = 0x82342B54;
	sub_822131A0(ctx, base);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// ori r10,r11,62468
	ctx.r10.u64 = ctx.r11.u64 | 62468;
	// lis r30,0
	ctx.r30.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r28,-32111
	ctx.r28.s64 = -2104426496;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r5,r5,62488
	ctx.r5.u64 = ctx.r5.u64 | 62488;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r4,r4,62492
	ctx.r4.u64 = ctx.r4.u64 | 62492;
	// ori r3,r3,62496
	ctx.r3.u64 = ctx.r3.u64 | 62496;
	// ori r7,r7,62476
	ctx.r7.u64 = ctx.r7.u64 | 62476;
	// ori r6,r6,62484
	ctx.r6.u64 = ctx.r6.u64 | 62484;
	// lis r27,0
	ctx.r27.s64 = 0;
	// lis r26,0
	ctx.r26.s64 = 0;
	// lis r25,0
	ctx.r25.s64 = 0;
	// ld r11,3456(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// stdx r11,r31,r10
	REX_STORE_U64(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u64);
	// addi r11,r8,12236
	ctx.r11.s64 = ctx.r8.s64 + 12236;
	// ld r10,2880(r28)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r28.u32 + 2880);
	// lis r28,0
	ctx.r28.s64 = 0;
	// stdx r10,r31,r7
	REX_STORE_U64(ctx.r31.u32 + ctx.r7.u32, ctx.r10.u64);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r30,62500
	ctx.r11.u64 = ctx.r30.u64 | 62500;
	// stfsx f0,r31,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stfsx f0,r31,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// lis r4,0
	ctx.r4.s64 = 0;
	// stfsx f0,r31,r3
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, temp.u32);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r30,0
	ctx.r30.s64 = 0;
	// stwx r11,r31,r6
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u32);
	// ori r6,r5,62516
	ctx.r6.u64 = ctx.r5.u64 | 62516;
	// ori r5,r4,62520
	ctx.r5.u64 = ctx.r4.u64 | 62520;
	// ori r4,r3,62521
	ctx.r4.u64 = ctx.r3.u64 | 62521;
	// ori r10,r10,62508
	ctx.r10.u64 = ctx.r10.u64 | 62508;
	// ori r7,r7,62512
	ctx.r7.u64 = ctx.r7.u64 | 62512;
	// ori r3,r30,62522
	ctx.r3.u64 = ctx.r30.u64 | 62522;
	// ori r30,r28,62524
	ctx.r30.u64 = ctx.r28.u64 | 62524;
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// ori r28,r27,62528
	ctx.r28.u64 = ctx.r27.u64 | 62528;
	// stfsx f0,r31,r6
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// ori r27,r26,62532
	ctx.r27.u64 = ctx.r26.u64 | 62532;
	// stwx r11,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u32);
	// ori r26,r25,62696
	ctx.r26.u64 = ctx.r25.u64 | 62696;
	// stbx r11,r31,r5
	REX_STORE_U8(ctx.r31.u32 + ctx.r5.u32, ctx.r11.u8);
	// lis r25,0
	ctx.r25.s64 = 0;
	// stbx r11,r31,r4
	REX_STORE_U8(ctx.r31.u32 + ctx.r4.u32, ctx.r11.u8);
	// lis r24,0
	ctx.r24.s64 = 0;
	// stbx r11,r31,r3
	REX_STORE_U8(ctx.r31.u32 + ctx.r3.u32, ctx.r11.u8);
	// ori r10,r25,62704
	ctx.r10.u64 = ctx.r25.u64 | 62704;
	// stfsx f0,r31,r28
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, temp.u32);
	// ori r6,r24,62708
	ctx.r6.u64 = ctx.r24.u64 | 62708;
	// stwx r11,r31,r30
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, ctx.r11.u32);
	// li r28,255
	ctx.r28.s64 = 255;
	// stwx r11,r31,r27
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, ctx.r11.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stwx r28,r31,r26
	REX_STORE_U32(ctx.r31.u32 + ctx.r26.u32, ctx.r28.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stbx r11,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u8);
	// ori r7,r7,62712
	ctx.r7.u64 = ctx.r7.u64 | 62712;
	// stfsx f0,r31,r6
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// ld r11,3456(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// stdx r11,r31,r7
	REX_STORE_U64(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u64);
	// ori r6,r5,62720
	ctx.r6.u64 = ctx.r5.u64 | 62720;
	// ld r11,3456(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stdx r11,r31,r6
	REX_STORE_U64(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u64);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r4,r5,62728
	ctx.r4.u64 = ctx.r5.u64 | 62728;
	// ld r11,3456(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// ori r10,r10,62736
	ctx.r10.u64 = ctx.r10.u64 | 62736;
	// lfs f0,12236(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stdx r11,r31,r4
	REX_STORE_U64(ctx.r31.u32 + ctx.r4.u32, ctx.r11.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// bl 0x8235ec48
	ctx.lr = 0x82342CAC;
	sub_8235EC48(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8246b640
	ctx.lr = 0x82342CBC;
	sub_8246B640(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82342cd0
	if (!ctx.cr6.lt) goto loc_82342CD0;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_82342CD0:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12860(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82342ce8
	if (ctx.cr6.eq) goto loc_82342CE8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x82342CE8;
	sub_8246D8F0(ctx, base);
loc_82342CE8:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x82342CF8;
	sub_8235EC48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82350A60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82350A68;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,176(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 176);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82350bb8
	if (!ctx.cr6.gt) goto loc_82350BB8;
	// lwz r11,172(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 172);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r31,0(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82350bb8
	if (ctx.cr6.eq) goto loc_82350BB8;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// lfs f31,1700(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1700);
	ctx.f31.f64 = double(temp.f32);
loc_82350AA8:
	// ld r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 8);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// ld r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8230d580
	ctx.lr = 0x82350ACC;
	sub_8230D580(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x82222370
	ctx.lr = 0x82350AE0;
	sub_82222370(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825a7c80
	ctx.lr = 0x82350AF4;
	sub_825A7C80(ctx, base);
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fneg f13,f1
	ctx.f13.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// lbz r11,164(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 164);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82350b48
	if (ctx.cr0.eq) goto loc_82350B48;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825a4a90
	ctx.lr = 0x82350B20;
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
	ctx.lr = 0x82350B34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,5
	ctx.r11.s64 = 5;
	// divwu r11,r3,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r3.u32 / ctx.r11.u32 : 0);
	// mulli r11,r11,5
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(5));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// stb r11,36(r31)
	REX_STORE_U8(ctx.r31.u32 + 36, ctx.r11.u8);
loc_82350B48:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x825a4a90
	ctx.lr = 0x82350B50;
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
	ctx.lr = 0x82350B64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,100
	ctx.r11.s64 = 100;
	// divwu r11,r3,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r3.u32 / ctx.r11.u32 : 0);
	// mulli r11,r11,100
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(100));
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// cmplwi cr6,r11,25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 25, ctx.xer);
	// bge cr6,0x82350b84
	if (!ctx.cr6.lt) goto loc_82350B84;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// b 0x82350ba8
	goto loc_82350BA8;
loc_82350B84:
	// cmplwi cr6,r11,50
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 50, ctx.xer);
	// bge cr6,0x82350b94
	if (!ctx.cr6.lt) goto loc_82350B94;
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x82350ba4
	goto loc_82350BA4;
loc_82350B94:
	// cmplwi cr6,r11,75
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 75, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x82350ba4
	if (ctx.cr6.lt) goto loc_82350BA4;
	// li r11,3
	ctx.r11.s64 = 3;
loc_82350BA4:
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_82350BA8:
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,172(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82350aa8
	if (!ctx.cr6.eq) goto loc_82350AA8;
loc_82350BB8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82359E80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82359E88;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,4384
	ctx.r4.s64 = ctx.r11.s64 + 4384;
	// bl 0x8222fa58
	ctx.lr = 0x82359E9C;
	sub_8222FA58(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r3,r11,62372
	ctx.r3.u64 = ctx.r11.u64 | 62372;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r11,r10,62376
	ctx.r11.u64 = ctx.r10.u64 | 62376;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r10,r9,62380
	ctx.r10.u64 = ctx.r9.u64 | 62380;
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r9,r8,62384
	ctx.r9.u64 = ctx.r8.u64 | 62384;
	// lis r5,-32240
	ctx.r5.s64 = -2112880640;
	// ori r8,r7,62388
	ctx.r8.u64 = ctx.r7.u64 | 62388;
	// ori r7,r6,62392
	ctx.r7.u64 = ctx.r6.u64 | 62392;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r4,-32226
	ctx.r4.s64 = -2111963136;
	// lfs f0,12468(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// ori r6,r6,62393
	ctx.r6.u64 = ctx.r6.u64 | 62393;
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stfsx f0,r31,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// addi r8,r4,19672
	ctx.r8.s64 = ctx.r4.s64 + 19672;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// ori r5,r5,62394
	ctx.r5.u64 = ctx.r5.u64 | 62394;
	// stwx r11,r31,r3
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, ctx.r11.u32);
	// ori r10,r10,62395
	ctx.r10.u64 = ctx.r10.u64 | 62395;
	// stbx r11,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u8);
	// ori r9,r9,62396
	ctx.r9.u64 = ctx.r9.u64 | 62396;
	// stbx r11,r31,r6
	REX_STORE_U8(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u8);
	// stbx r11,r31,r5
	REX_STORE_U8(ctx.r31.u32 + ctx.r5.u32, ctx.r11.u8);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// stbx r11,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u8);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stbx r11,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u8);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lwz r10,-12860(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12860);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r30,0
	ctx.r30.s64 = 0;
	// lis r29,0
	ctx.r29.s64 = 0;
	// lis r28,0
	ctx.r28.s64 = 0;
	// ori r27,r9,62408
	ctx.r27.u64 = ctx.r9.u64 | 62408;
	// ori r7,r7,62464
	ctx.r7.u64 = ctx.r7.u64 | 62464;
	// ori r6,r6,62472
	ctx.r6.u64 = ctx.r6.u64 | 62472;
	// ori r5,r5,62476
	ctx.r5.u64 = ctx.r5.u64 | 62476;
	// ori r4,r4,62477
	ctx.r4.u64 = ctx.r4.u64 | 62477;
	// ori r3,r3,62480
	ctx.r3.u64 = ctx.r3.u64 | 62480;
	// ori r30,r30,62484
	ctx.r30.u64 = ctx.r30.u64 | 62484;
	// ori r29,r29,62488
	ctx.r29.u64 = ctx.r29.u64 | 62488;
	// ori r28,r28,62492
	ctx.r28.u64 = ctx.r28.u64 | 62492;
	// li r26,255
	ctx.r26.s64 = 255;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ld r9,3456(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 3456);
	// stfsx f0,r31,r7
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// stfsx f0,r31,r3
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, temp.u32);
	// stwx r26,r31,r6
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r26.u32);
	// stfsx f0,r31,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
	// stbx r11,r31,r5
	REX_STORE_U8(ctx.r31.u32 + ctx.r5.u32, ctx.r11.u8);
	// stfsx f0,r31,r28
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, temp.u32);
	// stbx r11,r31,r4
	REX_STORE_U8(ctx.r31.u32 + ctx.r4.u32, ctx.r11.u8);
	// stbx r11,r31,r30
	REX_STORE_U8(ctx.r31.u32 + ctx.r30.u32, ctx.r11.u8);
	// stdx r9,r31,r27
	REX_STORE_U64(ctx.r31.u32 + ctx.r27.u32, ctx.r9.u64);
	// beq cr6,0x82359fc4
	if (ctx.cr6.eq) goto loc_82359FC4;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-26224
	ctx.r3.s64 = ctx.r11.s64 + -26224;
	// bl 0x8246d8f0
	ctx.lr = 0x82359FC4;
	sub_8246D8F0(ctx, base);
loc_82359FC4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8235F918) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r3,96
	ctx.r31.s64 = ctx.r3.s64 + 96;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8235f948
	if (ctx.cr0.eq) goto loc_8235F948;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82855b44
	ctx.lr = 0x8235F948;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8235F948:
	// lwz r11,128(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 128);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stw r11,128(r30)
	REX_STORE_U32(ctx.r30.u32 + 128, ctx.r11.u32);
	// lbz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8235f968
	if (ctx.cr0.eq) goto loc_8235F968;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82855b34
	ctx.lr = 0x8235F968;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8235F968:
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

DEFINE_REX_FUNC(sub_82360968) {
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
	// lwz r3,152(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 152);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82360994
	if (ctx.cr6.eq) goto loc_82360994;
	// bl 0x8221cc98
	ctx.lr = 0x8236098C;
	sub_8221CC98(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
loc_82360994:
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

DEFINE_REX_FUNC(sub_823628B0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,56(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mulli r10,r11,124
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(124));
	// stw r11,308(r3)
	REX_STORE_U32(ctx.r3.u32 + 308, ctx.r11.u32);
	// add r11,r10,r3
	ctx.r11.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// stw r10,312(r3)
	REX_STORE_U32(ctx.r3.u32 + 312, ctx.r10.u32);
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// stw r11,316(r3)
	REX_STORE_U32(ctx.r3.u32 + 316, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82363F08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82363F10;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r11,-13060(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -13060);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82363f38
	if (!ctx.cr6.eq) goto loc_82363F38;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82363fe0
	goto loc_82363FE0;
loc_82363F38:
	// lbz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 96);
	// addi r3,r11,68
	ctx.r3.s64 = ctx.r11.s64 + 68;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82363f50
	if (ctx.cr0.eq) goto loc_82363F50;
	// bl 0x82855b44
	ctx.lr = 0x82363F4C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,-13060(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -13060);
loc_82363F50:
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r28,1
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 1, ctx.xer);
	// blt cr6,0x82363f94
	if (ctx.cr6.lt) goto loc_82363F94;
	// bne cr6,0x82363fc8
	if (!ctx.cr6.eq) goto loc_82363FC8;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// beq cr6,0x82363f74
	if (ctx.cr6.eq) goto loc_82363F74;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x82363fc8
	if (!ctx.cr6.eq) goto loc_82363FC8;
loc_82363F74:
	// lwz r10,120(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lwz r10,124(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// lwz r10,128(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 128);
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// lwz r10,132(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// b 0x82363fc0
	goto loc_82363FC0;
loc_82363F94:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x82363fa4
	if (ctx.cr6.eq) goto loc_82363FA4;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x82363fc8
	if (!ctx.cr6.eq) goto loc_82363FC8;
loc_82363FA4:
	// lwz r10,104(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lwz r10,108(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// lwz r10,112(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// lwz r10,116(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
loc_82363FC0:
	// stw r10,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r10.u32);
	// li r31,1
	ctx.r31.s64 = 1;
loc_82363FC8:
	// lbz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 96);
	// addi r3,r11,68
	ctx.r3.s64 = ctx.r11.s64 + 68;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82363fdc
	if (ctx.cr0.eq) goto loc_82363FDC;
	// bl 0x82855b34
	ctx.lr = 0x82363FDC;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82363FDC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82363FE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823686C0) {
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
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r3,r10,1368
	ctx.r3.s64 = ctx.r10.s64 + 1368;
	// lwz r11,-15508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15508);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823686F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x823686F4;
	sub_8245A220(ctx, base);
	// stw r3,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82369448
	ctx.lr = 0x82368700;
	sub_82369448(ctx, base);
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

DEFINE_REX_FUNC(sub_8236A328) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8236A330;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8235f428
	ctx.lr = 0x8236A340;
	sub_8235F428(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,20784
	ctx.r11.s64 = ctx.r11.s64 + 20784;
	// stw r30,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r30.u32);
	// addi r28,r31,284
	ctx.r28.s64 = ctx.r31.s64 + 284;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// stb r30,232(r31)
	REX_STORE_U8(ctx.r31.u32 + 232, ctx.r30.u8);
	// lfs f31,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// stb r30,233(r31)
	REX_STORE_U8(ctx.r31.u32 + 233, ctx.r30.u8);
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// stfs f31,256(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 256, temp.u32);
	// stfs f31,260(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 260, temp.u32);
	// stw r30,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r30.u32);
	// stfs f31,264(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 264, temp.u32);
	// stw r30,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r30.u32);
	// stw r30,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r30.u32);
	// stw r30,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r30.u32);
	// std r11,236(r31)
	REX_STORE_U64(ctx.r31.u32 + 236, ctx.r11.u64);
	// stw r30,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r30.u32);
	// stw r30,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r30.u32);
	// stw r30,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r30.u32);
loc_8236A3A0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8236a250
	ctx.lr = 0x8236A3A8;
	sub_8236A250(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r28,r28,64
	ctx.r28.s64 = ctx.r28.s64 + 64;
	// bge 0x8236a3a0
	if (!ctx.cr0.lt) goto loc_8236A3A0;
	// stw r30,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r30.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r29,r31,416
	ctx.r29.s64 = ctx.r31.s64 + 416;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8236A3D4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8236a3e4
	if (ctx.cr0.eq) goto loc_8236A3E4;
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8236a3e8
	goto loc_8236A3E8;
loc_8236A3E4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8236A3E8:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,16(r29)
	REX_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
	// stw r30,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// addi r11,r11,-27424
	ctx.r11.s64 = ctx.r11.s64 + -27424;
	// stw r30,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r30.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r30,28(r29)
	REX_STORE_U32(ctx.r29.u32 + 28, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r30.u32);
	// stw r30,456(r31)
	REX_STORE_U32(ctx.r31.u32 + 456, ctx.r30.u32);
	// stw r30,460(r31)
	REX_STORE_U32(ctx.r31.u32 + 460, ctx.r30.u32);
	// stfs f31,468(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 468, temp.u32);
	// stw r30,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r30.u32);
	// stw r10,472(r31)
	REX_STORE_U32(ctx.r31.u32 + 472, ctx.r10.u32);
	// stw r11,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r11.u32);
	// stw r9,480(r31)
	REX_STORE_U32(ctx.r31.u32 + 480, ctx.r9.u32);
	// stw r30,484(r31)
	REX_STORE_U32(ctx.r31.u32 + 484, ctx.r30.u32);
	// stw r30,488(r31)
	REX_STORE_U32(ctx.r31.u32 + 488, ctx.r30.u32);
	// stw r30,492(r31)
	REX_STORE_U32(ctx.r31.u32 + 492, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8236FA20) {
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
	// lbz r11,261(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 261);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8236fa70
	if (ctx.cr0.eq) goto loc_8236FA70;
	// lwz r5,4(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,1000
	ctx.r4.s64 = 1000;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x8236FA50;
	sub_825A49B0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// mulli r11,r11,1000
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(1000));
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// subfc r11,r11,r3
	ctx.xer.ca = ctx.r3.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r11,r11,41
	ctx.r11.s64 = ctx.r11.s64 + 41;
	// b 0x8236fb00
	goto loc_8236FB00;
loc_8236FA70:
	// lwz r11,236(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// rlwinm. r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8236fa84
	if (ctx.cr0.eq) goto loc_8236FA84;
	// li r11,7
	ctx.r11.s64 = 7;
	// b 0x8236fb00
	goto loc_8236FB00;
loc_8236FA84:
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8236fa98
	if (ctx.cr0.eq) goto loc_8236FA98;
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// b 0x8236fadc
	goto loc_8236FADC;
loc_8236FA98:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x825a4a90
	ctx.lr = 0x8236FAA8;
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
	ctx.lr = 0x8236FABC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r3,28,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 28) & 0xFF;
	// lwz r10,268(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// li r9,3
	ctx.r9.s64 = 3;
	// divwu r9,r11,r9
	ctx.r9.u64 = uint32_t(ctx.r9.u32 ? ctx.r11.u32 / ctx.r9.u32 : 0);
	// mulli r9,r9,3
	ctx.r9.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(3));
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8236FADC:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8236faec
	if (!ctx.cr6.lt) goto loc_8236FAEC;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8236fb00
	goto loc_8236FB00;
loc_8236FAEC:
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// ble cr6,0x8236faf8
	if (!ctx.cr6.gt) goto loc_8236FAF8;
	// li r11,7
	ctx.r11.s64 = 7;
loc_8236FAF8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8236fb04
	if (ctx.cr6.eq) goto loc_8236FB04;
loc_8236FB00:
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
loc_8236FB04:
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

DEFINE_REX_FUNC(sub_82376C40) {
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
	// bl 0x82377108
	ctx.lr = 0x82376C58;
	sub_82377108(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fb40
	ctx.lr = 0x82376C60;
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

DEFINE_REX_FUNC(sub_82377E88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82377E90;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,232(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 232);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82377f60
	if (ctx.cr6.lt) goto loc_82377F60;
	// beq cr6,0x82377ef4
	if (ctx.cr6.eq) goto loc_82377EF4;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82377f7c
	if (!ctx.cr6.lt) goto loc_82377F7C;
	// lwz r30,260(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 260);
	// lwz r29,264(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// b 0x82377ee8
	goto loc_82377EE8;
loc_82377EC4:
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82378530
	ctx.lr = 0x82377ED4;
	sub_82378530(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82377ee4
	if (ctx.cr0.eq) goto loc_82377EE4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823780e8
	ctx.lr = 0x82377EE4;
	sub_823780E8(ctx, base);
loc_82377EE4:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
loc_82377EE8:
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82377ec4
	if (!ctx.cr6.eq) goto loc_82377EC4;
	// b 0x82377f7c
	goto loc_82377F7C;
loc_82377EF4:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,244(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
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
	// beq cr6,0x82377f2c
	if (ctx.cr6.eq) goto loc_82377F2C;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82377f2c
	if (ctx.cr6.eq) goto loc_82377F2C;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x82377f30
	if (!ctx.cr6.eq) goto loc_82377F30;
loc_82377F2C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82377F30:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82377f7c
	if (!ctx.cr0.eq) goto loc_82377F7C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,240(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// bl 0x82378258
	ctx.lr = 0x82377F44;
	sub_82378258(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82377F58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x82377f78
	goto loc_82377F78;
loc_82377F60:
	// lbz r11,228(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 228);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82377f7c
	if (ctx.cr0.eq) goto loc_82377F7C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82377ff0
	ctx.lr = 0x82377F74;
	sub_82377FF0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
loc_82377F78:
	// stw r11,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
loc_82377F7C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8237CEE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,521
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 521, ctx.xer);
	// beq cr6,0x8237cf6c
	if (ctx.cr6.eq) goto loc_8237CF6C;
	// cmplwi cr6,r11,522
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 522, ctx.xer);
	// beq cr6,0x8237cefc
	if (ctx.cr6.eq) goto loc_8237CEFC;
	// b 0x8235f668
	sub_8235F668(ctx, base);
	return;
loc_8237CEFC:
	// lbz r9,20(r4)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r4.u32 + 20);
	// lbz r11,280(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 280);
	// lwz r10,268(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// xor r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r9.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// subfe r11,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8237cf38
	if (!ctx.cr6.lt) goto loc_8237CF38;
	// lbz r11,348(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 348);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// b 0x8237cf40
	goto loc_8237CF40;
loc_8237CF38:
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// subfe r11,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_8237CF40:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_8237CF44:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x8237cf88
	if (ctx.cr6.eq) goto loc_8237CF88;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x8237cf60
	if (ctx.cr6.eq) goto loc_8237CF60;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// b 0x8237cf90
	goto loc_8237CF90;
loc_8237CF60:
	// clrlwi. r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// b 0x8237cf90
	goto loc_8237CF90;
loc_8237CF6C:
	// lwz r10,268(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lbz r11,348(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 348);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// b 0x8237cf44
	goto loc_8237CF44;
loc_8237CF88:
	// clrlwi. r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
loc_8237CF90:
	// stb r11,348(r3)
	REX_STORE_U8(ctx.r3.u32 + 348, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8237F520) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lwz r10,232(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 232);
	// addi r11,r11,25712
	ctx.r11.s64 = ctx.r11.s64 + 25712;
	// mulli r9,r10,3
	ctx.r9.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(3));
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbzx r10,r9,r10
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r4,r10,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// b 0x8235fc38
	sub_8235FC38(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8237FEA8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8237FEB0;
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
	// li r4,304
	ctx.r4.s64 = 304;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8237FED8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8237fef4
	if (ctx.cr0.eq) goto loc_8237FEF4;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8237ff00
	ctx.lr = 0x8237FEF0;
	sub_8237FF00(ctx, base);
	// b 0x8237fef8
	goto loc_8237FEF8;
loc_8237FEF4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8237FEF8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82381708) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// extsw r11,r4
	ctx.r11.s64 = ctx.r4.s32;
	// extsw r10,r5
	ctx.r10.s64 = ctx.r5.s32;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f0,624(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 624);
	ctx.f0.f64 = double(temp.f32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stfs f12,280(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 280, temp.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f0,284(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 284, temp.u32);
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,288(r3)
	REX_STORE_U32(ctx.r3.u32 + 288, ctx.r11.u32);
	// bne cr6,0x82381770
	if (!ctx.cr6.eq) goto loc_82381770;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// stb r10,304(r3)
	REX_STORE_U8(ctx.r3.u32 + 304, ctx.r10.u8);
	// lfs f0,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,296(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// b 0x823817b8
	goto loc_823817B8;
loc_82381770:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,116(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,296(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stfs f0,300(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 300, temp.u32);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// stb r11,304(r3)
	REX_STORE_U8(ctx.r3.u32 + 304, ctx.r11.u8);
	// stb r11,305(r3)
	REX_STORE_U8(ctx.r3.u32 + 305, ctx.r11.u8);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,12472(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
loc_823817B8:
	// stfs f0,300(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82386A20) {
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
	// bl 0x82386a78
	ctx.lr = 0x82386A40;
	sub_82386A78(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82386a58
	if (ctx.cr0.eq) goto loc_82386A58;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82386a58
	if (ctx.cr6.eq) goto loc_82386A58;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82386A58;
	sub_825E0378(ctx, base);
loc_82386A58:
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

DEFINE_REX_FUNC(sub_82387E40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82387E48;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,116(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 116);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r29,120(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 120);
	// b 0x82387e88
	goto loc_82387E88;
loc_82387E5C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82387e7c
	if (ctx.cr6.eq) goto loc_82387E7C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82387E7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82387E7C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_82387E88:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82387e5c
	if (!ctx.cr6.eq) goto loc_82387E5C;
	// lwz r3,116(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 116);
	// addi r29,r30,112
	ctx.r29.s64 = ctx.r30.s64 + 112;
	// lwz r5,120(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 120);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x82387ec4
	if (ctx.cr6.eq) goto loc_82387EC4;
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
	// ble 0x82387ec0
	if (!ctx.cr0.gt) goto loc_82387EC0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x82387EC0;
	sub_827388E8(ctx, base);
loc_82387EC0:
	// stw r31,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
loc_82387EC4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8238B068) {
	REX_FUNC_PROLOGUE();
	// li r3,40
	ctx.r3.s64 = 40;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8238B070) {
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
	// lwa r11,264(r3)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r3.u32 + 264));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,292(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r3,262
	ctx.r3.s64 = 262;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
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
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8257d438
	ctx.lr = 0x8238B0F4;
	sub_8257D438(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8238F888) {
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
	// addi r11,r11,27048
	ctx.r11.s64 = ctx.r11.s64 + 27048;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8235f568
	ctx.lr = 0x8238F8B4;
	sub_8235F568(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8238f8c4
	if (ctx.cr0.eq) goto loc_8238F8C4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8238F8C4;
	sub_825E0378(ctx, base);
loc_8238F8C4:
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

DEFINE_REX_FUNC(sub_82391118) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82391120;
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
	// beq 0x82391140
	if (ctx.cr0.eq) goto loc_82391140;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82855b44
	ctx.lr = 0x82391140;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_82391140:
	// lwz r30,212(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 212);
	// lwz r26,216(r28)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + 216);
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x823911b4
	if (ctx.cr6.eq) goto loc_823911B4;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// addi r29,r10,20580
	ctx.r29.s64 = ctx.r10.s64 + 20580;
	// addi r27,r11,22072
	ctx.r27.s64 = ctx.r11.s64 + 22072;
loc_82391160:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 44);
	// li r4,20
	ctx.r4.s64 = 20;
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x825e02a0
	ctx.lr = 0x82391174;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823911a0
	if (ctx.cr0.eq) goto loc_823911A0;
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
	// b 0x823911a4
	goto loc_823911A4;
loc_823911A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823911A4:
	// bl 0x825a2ef8
	ctx.lr = 0x823911A8;
	sub_825A2EF8(ctx, base);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x82391160
	if (!ctx.cr6.eq) goto loc_82391160;
loc_823911B4:
	// lbz r11,28(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823911c8
	if (ctx.cr0.eq) goto loc_823911C8;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82855b34
	ctx.lr = 0x823911C8;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_823911C8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82394F80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82394F88;
	__savegprlr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x8239504c
	if (!ctx.cr6.eq) goto loc_8239504C;
	// addi r4,r3,292
	ctx.r4.s64 = ctx.r3.s64 + 292;
	// addi r3,r3,284
	ctx.r3.s64 = ctx.r3.s64 + 284;
	// bl 0x8235fad0
	ctx.lr = 0x82394FAC;
	sub_8235FAD0(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x8239504c
	if (ctx.cr0.eq) goto loc_8239504C;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// rlwinm r10,r29,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,-12816(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x823951b0
	if (!ctx.cr6.eq) goto loc_823951B0;
	// lwz r27,4(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x823951b0
	if (ctx.cr6.eq) goto loc_823951B0;
	// lwz r3,2340(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82394FF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823951b0
	if (!ctx.cr0.eq) goto loc_823951B0;
	// lwz r3,2340(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82395010;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823951b0
	if (!ctx.cr0.eq) goto loc_823951B0;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// stw r29,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// li r9,270
	ctx.r9.s64 = 270;
	// addi r29,r10,20580
	ctx.r29.s64 = ctx.r10.s64 + 20580;
	// stw r30,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r30.u32);
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r29,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// lwz r3,-12816(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -12816);
	// bl 0x825a2f98
	ctx.lr = 0x82395048;
	sub_825A2F98(ctx, base);
	// stw r29,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
loc_8239504C:
	// lwz r11,228(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x823951b0
	if (!ctx.cr6.eq) goto loc_823951B0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8239506C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823951b0
	if (!ctx.cr0.eq) goto loc_823951B0;
	// lwz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x823950d0
	if (!ctx.cr6.eq) goto loc_823950D0;
	// bl 0x824281d8
	ctx.lr = 0x82395084;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823950d0
	if (ctx.cr0.eq) goto loc_823950D0;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823950A4;
	sub_825E02A0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r10,2343
	ctx.r10.s64 = 2343;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,268
	ctx.r3.s64 = ctx.r31.s64 + 268;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x82396cc8
	ctx.lr = 0x823950C4;
	sub_82396CC8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,337(r31)
	REX_STORE_U8(ctx.r31.u32 + 337, ctx.r11.u8);
	// b 0x82395164
	goto loc_82395164;
loc_823950D0:
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// addi r11,r11,-16
	ctx.r11.s64 = ctx.r11.s64 + -16;
	// rlwinm. r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r11.u32);
	// beq 0x82395138
	if (ctx.cr0.eq) goto loc_82395138;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// li r29,16
	ctx.r29.s64 = 16;
	// addi r28,r11,17432
	ctx.r28.s64 = ctx.r11.s64 + 17432;
loc_823950F4:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r11,r29,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// rlwinm r10,r11,18,14,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 18) & 0x3FFFC;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lwzx r10,r10,r28
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r28.u32);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x82396778
	ctx.lr = 0x82395118;
	sub_82396778(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82395124
	if (!ctx.cr0.eq) goto loc_82395124;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_82395124:
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x823950f4
	if (ctx.cr6.lt) goto loc_823950F4;
loc_82395138:
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// lwz r10,252(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// subf r11,r27,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r27.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r11.u32);
	// bge cr6,0x8239515c
	if (!ctx.cr6.lt) goto loc_8239515C;
	// lwz r11,256(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82395164
	if (ctx.cr6.lt) goto loc_82395164;
loc_8239515C:
	// li r11,1000
	ctx.r11.s64 = 1000;
	// stw r11,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r11.u32);
loc_82395164:
	// lbz r11,337(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 337);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82395178
	if (!ctx.cr0.eq) goto loc_82395178;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82395f10
	ctx.lr = 0x82395178;
	sub_82395F10(ctx, base);
loc_82395178:
	// lwz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x82395190
	if (!ctx.cr6.eq) goto loc_82395190;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// b 0x823951b0
	goto loc_823951B0;
loc_82395190:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r9,5
	ctx.r9.s64 = 5;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r9,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r9.u32);
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,248(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 248, temp.u32);
loc_823951B0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823A8C28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x823A8C30;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fabs f13,f1
	ctx.f13.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lfs f0,14204(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14204);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x823a8d50
	if (!ctx.cr6.gt) goto loc_823A8D50;
	// lwz r11,368(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 368);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823a8d50
	if (ctx.cr6.eq) goto loc_823A8D50;
	// lwz r25,340(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 340);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lwz r24,364(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 364);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r26,r3,340
	ctx.r26.s64 = ctx.r3.s64 + 340;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// stw r25,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// addi r31,r10,32720
	ctx.r31.s64 = ctx.r10.s64 + 32720;
	// addi r30,r9,20580
	ctx.r30.s64 = ctx.r9.s64 + 20580;
	// addi r29,r11,20580
	ctx.r29.s64 = ctx.r11.s64 + 20580;
loc_823A8C8C:
	// lwz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r11,24(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 24);
	// lwz r10,28(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 28);
	// cmplw cr6,r25,r9
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r9.u32, ctx.xer);
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bne cr6,0x823a8cb4
	if (!ctx.cr6.eq) goto loc_823A8CB4;
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x823a8cb8
	if (ctx.cr6.eq) goto loc_823A8CB8;
loc_823A8CB4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823A8CB8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823a8d50
	if (!ctx.cr0.eq) goto loc_823A8D50;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8236c610
	ctx.lr = 0x823A8CC8;
	sub_8236C610(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823a8d48
	if (ctx.cr6.eq) goto loc_823A8D48;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r7,4(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// stfs f31,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r6,517
	ctx.r6.s64 = 517;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r11,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r11.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,0
	ctx.r10.s64 = 0;
	// lvx128 v63,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r6.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r7.u32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r10.u32);
	// stw r29,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r29.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r3,-12816(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -12816);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,164(r1)
	REX_STORE_U64(ctx.r1.u32 + 164, ctx.r11.u64);
	// bl 0x825a2f98
	ctx.lr = 0x823A8D44;
	sub_825A2F98(ctx, base);
	// stw r30,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r30.u32);
loc_823A8D48:
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// b 0x823a8c8c
	goto loc_823A8C8C;
loc_823A8D50:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823B1478) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x823B1480;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,-13032(r9)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r9.u32 + -13032);
	// rlwinm. r8,r4,0,1,1
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// li r26,2
	ctx.r26.s64 = 2;
	// addi r25,r11,2668
	ctx.r25.s64 = ctx.r11.s64 + 2668;
	// addi r27,r10,4844
	ctx.r27.s64 = ctx.r10.s64 + 4844;
	// beq 0x823b1524
	if (ctx.cr0.eq) goto loc_823B1524;
	// lwz r31,32(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// b 0x823b1518
	goto loc_823B1518;
loc_823B14B8:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823b1514
	if (ctx.cr6.eq) goto loc_823B1514;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// ld r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 4);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stw r27,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stw r26,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r26.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r9,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823b1618
	ctx.lr = 0x823B1508;
	sub_823B1618(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823b1534
	if (!ctx.cr0.eq) goto loc_823B1534;
	// stw r25,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
loc_823B1514:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_823B1518:
	// lwz r11,36(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823b14b8
	if (!ctx.cr6.eq) goto loc_823B14B8;
loc_823B1524:
	// rlwinm. r11,r30,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823b15a8
	if (ctx.cr0.eq) goto loc_823B15A8;
	// lwz r31,48(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// b 0x823b159c
	goto loc_823B159C;
loc_823B1534:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823b15ac
	goto loc_823B15AC;
loc_823B153C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823b1598
	if (ctx.cr6.eq) goto loc_823B1598;
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ld r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 4);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stw r27,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r26,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r26.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823b1618
	ctx.lr = 0x823B158C;
	sub_823B1618(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823b1534
	if (!ctx.cr0.eq) goto loc_823B1534;
	// stw r25,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
loc_823B1598:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_823B159C:
	// lwz r11,52(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 52);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823b153c
	if (!ctx.cr6.eq) goto loc_823B153C;
loc_823B15A8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823B15AC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823B85A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x823B85A8;
	__savegprlr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r3,36(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823b85d0
	if (ctx.cr6.eq) goto loc_823B85D0;
	// bl 0x823ba3a0
	ctx.lr = 0x823B85C0;
	sub_823BA3A0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823b85d0
	if (ctx.cr0.eq) goto loc_823B85D0;
loc_823B85C8:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823b87a0
	goto loc_823B87A0;
loc_823B85D0:
	// lwz r11,52(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 52);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823b862c
	if (ctx.cr6.eq) goto loc_823B862C;
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823b862c
	if (ctx.cr0.eq) goto loc_823B862C;
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
loc_823B85F4:
	// lwz r11,40(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 40);
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823b8614
	if (ctx.cr6.eq) goto loc_823B8614;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x823ba490
	ctx.lr = 0x823B860C;
	sub_823BA490(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823b85c8
	if (!ctx.cr0.eq) goto loc_823B85C8;
loc_823B8614:
	// lwz r11,52(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 52);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x823b85f4
	if (ctx.cr6.lt) goto loc_823B85F4;
loc_823B862C:
	// lbz r11,32(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823b86c8
	if (!ctx.cr0.eq) goto loc_823B86C8;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,92(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 92);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// lwz r9,-12824(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + -12824);
	// beq cr6,0x823b8684
	if (ctx.cr6.eq) goto loc_823B8684;
	// lwz r10,8(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// mulli r11,r11,52
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(52));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823b8678
	if (ctx.cr6.eq) goto loc_823B8678;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x823b8678
	if (ctx.cr6.eq) goto loc_823B8678;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x823b867c
	if (!ctx.cr6.eq) goto loc_823B867C;
loc_823B8678:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_823B867C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823b85c8
	if (!ctx.cr0.eq) goto loc_823B85C8;
loc_823B8684:
	// lwz r10,100(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 100);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x823b86c8
	if (ctx.cr6.eq) goto loc_823B86C8;
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// mulli r10,r10,52
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(52));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823b86bc
	if (ctx.cr6.eq) goto loc_823B86BC;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x823b86bc
	if (ctx.cr6.eq) goto loc_823B86BC;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x823b86c0
	if (!ctx.cr6.eq) goto loc_823B86C0;
loc_823B86BC:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_823B86C0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823b85c8
	if (!ctx.cr0.eq) goto loc_823B85C8;
loc_823B86C8:
	// stb r27,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r27.u8);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stb r27,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r27.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823b87a8
	ctx.lr = 0x823B86DC;
	sub_823B87A8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,31064
	ctx.r4.s64 = ctx.r11.s64 + 31064;
	// bl 0x82374c48
	ctx.lr = 0x823B86EC;
	sub_82374C48(ctx, base);
	// addi r3,r1,97
	ctx.r3.s64 = ctx.r1.s64 + 97;
	// bl 0x8259b6a0
	ctx.lr = 0x823B86F4;
	sub_8259B6A0(ctx, base);
	// stw r3,96(r28)
	REX_STORE_U32(ctx.r28.u32 + 96, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823b87a8
	ctx.lr = 0x823B8704;
	sub_823B87A8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,31072
	ctx.r4.s64 = ctx.r11.s64 + 31072;
	// bl 0x82374c48
	ctx.lr = 0x823B8714;
	sub_82374C48(ctx, base);
	// addi r4,r1,97
	ctx.r4.s64 = ctx.r1.s64 + 97;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825a4160
	ctx.lr = 0x823B8720;
	sub_825A4160(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r31,-13024(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -13024);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823b8794
	if (ctx.cr6.eq) goto loc_823B8794;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r29,r31,144
	ctx.r29.s64 = ctx.r31.s64 + 144;
	// lbz r10,172(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 172);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq 0x823b8754
	if (ctx.cr0.eq) goto loc_823B8754;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b44
	ctx.lr = 0x823B8754;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_823B8754:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,36
	ctx.r4.s64 = ctx.r31.s64 + 36;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823b9908
	ctx.lr = 0x823B8764;
	sub_823B9908(ctx, base);
	// lwz r10,40(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x823b8778
	if (ctx.cr6.eq) goto loc_823B8778;
	// lwz r30,16(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
loc_823B8778:
	// lbz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823b878c
	if (ctx.cr0.eq) goto loc_823B878C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b34
	ctx.lr = 0x823B878C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_823B878C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x823b8798
	goto loc_823B8798;
loc_823B8794:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_823B8798:
	// stw r11,104(r28)
	REX_STORE_U32(ctx.r28.u32 + 104, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_823B87A0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823C58D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r11,r3,8
	ctx.r11.s64 = ctx.r3.s64 + 8;
	// addi r8,r10,2464
	ctx.r8.s64 = ctx.r10.s64 + 2464;
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// lfs f0,2464(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2464);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lfs f0,-4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stw r11,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// stfs f0,100(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stfs f13,104(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stw r11,96(r3)
	REX_STORE_U32(ctx.r3.u32 + 96, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823C73F0) {
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// li r30,2
	ctx.r30.s64 = 2;
loc_823C7414:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823c7428
	if (ctx.cr6.eq) goto loc_823C7428;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c7248
	ctx.lr = 0x823C7428;
	sub_823C7248(ctx, base);
loc_823C7428:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x823c7414
	if (!ctx.cr0.eq) goto loc_823C7414;
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

DEFINE_REX_FUNC(sub_823C8D10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x823C8D18;
	__savegprlr_24(ctx, base);
	// stfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f29.u64);
	// stfd f30,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// lwz r11,-12972(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12972);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r29,424(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x825fa250
	ctx.lr = 0x823C8D50;
	sub_825FA250(ctx, base);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// li r28,1
	ctx.r28.s64 = 1;
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r28,19,11,12
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 19) & 0x180000) | (ctx.r10.u64 & 0xFFFFFFFFFFE7FFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r28,21,9,10
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 21) & 0x600000) | (ctx.r10.u64 & 0xFFFFFFFFFF9FFFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825f9cf8
	ctx.lr = 0x823C8D7C;
	sub_825F9CF8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x823C8D88;
	sub_825F8D38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x823c8db0
	if (ctx.cr0.eq) goto loc_823C8DB0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b88
	ctx.lr = 0x823C8D98;
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
	ctx.lr = 0x823C8DAC;
	sub_825F8BF8(ctx, base);
	// b 0x823c8db4
	goto loc_823C8DB4;
loc_823C8DB0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_823C8DB4:
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r7,r8,12236
	ctx.r7.s64 = ctx.r8.s64 + 12236;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f30,12236(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12236);
	ctx.f30.f64 = double(temp.f32);
	// addi r10,r10,16536
	ctx.r10.s64 = ctx.r10.s64 + 16536;
	// stfs f30,124(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f31,232(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// addi r8,r10,-28
	ctx.r8.s64 = ctx.r10.s64 + -28;
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r7,r10,-28
	ctx.r7.s64 = ctx.r10.s64 + -28;
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r25,12(r6)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// lwz r3,8(r6)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stw r3,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r24,0(r6)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// stfs f30,108(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r6,4(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// addi r7,r7,2
	ctx.r7.s64 = ctx.r7.s64 + 2;
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// addi r6,r11,40
	ctx.r6.s64 = ctx.r11.s64 + 40;
	// stw r24,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r24.u32);
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stw r25,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r25.u32);
	// stfs f30,92(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lhzx r6,r9,r8
	ctx.r6.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r8.u32);
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// std r6,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r6,4(r5)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r3,8(r5)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// stfs f30,140(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r25,12(r5)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// addi r24,r1,128
	ctx.r24.s64 = ctx.r1.s64 + 128;
	// lwz r5,0(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r6,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r6.u32);
	// stw r3,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r3.u32);
	// stw r25,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r25.u32);
	// stw r5,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r5.u32);
	// lhzx r6,r9,r7
	ctx.r6.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r7.u32);
	// lhzx r8,r9,r8
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r8.u32);
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// std r8,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// std r6,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r8,4(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r6,8(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r5,12(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r4,0(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stw r4,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r4.u32);
	// stw r8,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r8.u32);
	// stw r6,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r6.u32);
	// stw r5,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r5.u32);
	// lhzx r9,r9,r7
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r7.u32);
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// std r9,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r7,4(r24)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// lwz r6,8(r24)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r5,12(r24)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r24.u32 + 12);
	// addi r8,r11,-12
	ctx.r8.s64 = ctx.r11.s64 + -12;
	// lwz r4,0(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// stw r7,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r6,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r6.u32);
	// stw r5,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r5.u32);
	// stw r4,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r4.u32);
loc_823C8F20:
	// stwu r26,40(r8)
	ea = 40 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r26.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x823c8f20
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823C8F20;
	// rlwinm r8,r30,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// addi r7,r10,8
	ctx.r7.s64 = ctx.r10.s64 + 8;
	// addi r9,r9,-4080
	ctx.r9.s64 = ctx.r9.s64 + -4080;
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// lfsx f13,r8,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r10,12
	ctx.r5.s64 = ctx.r10.s64 + 12;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfsx f12,r8,r7
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	ctx.f12.f64 = double(temp.f32);
	// lis r4,-32226
	ctx.r4.s64 = -2111963136;
	// lfs f0,1568(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1568);
	ctx.f0.f64 = double(temp.f32);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfsx f10,r8,r6
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,1572(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1572);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// lwz r10,-15508(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -15508);
	// fadds f12,f10,f13
	ctx.f12.f64 = double(float(ctx.f10.f64 + ctx.f13.f64));
	// lfsx f10,r8,r5
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r3,r4,1368
	ctx.r3.s64 = ctx.r4.s64 + 1368;
	// fadds f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 + ctx.f13.f64));
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r4,12
	ctx.r4.s64 = 12;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r9,72(r11)
	REX_STORE_U64(ctx.r11.u32 + 72, ctx.r9.u64);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// std r8,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r8.u64);
	// ld r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,112(r11)
	REX_STORE_U64(ctx.r11.u32 + 112, ctx.r10.u64);
	// std r8,152(r11)
	REX_STORE_U64(ctx.r11.u32 + 152, ctx.r8.u64);
	// bctrl 
	ctx.lr = 0x823C8FC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x823C8FC8;
	sub_8245A220(ctx, base);
	// stw r3,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// stw r29,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r29.u32);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// stb r28,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r28.u8);
	// stfs f29,412(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// lwz r10,408(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// stw r10,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r10.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r11,3596(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 3596);
	// stfs f30,140(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r11,r11,448
	ctx.r11.u64 = ctx.r11.u64 | 448;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
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
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// vpermwi128 v62,v63,174
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x51));
	// vpermwi128 v61,v63,186
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x45));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// vpermwi128 v63,v63,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x15));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8273a030
	ctx.lr = 0x823C9060;
	sub_8273A030(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82459d08
	ctx.lr = 0x823C9070;
	sub_82459D08(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
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

DEFINE_REX_FUNC(sub_823E5EB8) {
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
	// bl 0x823e5f10
	ctx.lr = 0x823E5ED8;
	sub_823E5F10(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823e5ef0
	if (ctx.cr0.eq) goto loc_823E5EF0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823e5ef0
	if (ctx.cr6.eq) goto loc_823E5EF0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x823E5EF0;
	sub_825E0378(ctx, base);
loc_823E5EF0:
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

DEFINE_REX_FUNC(sub_823E7DF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823E7DF8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lwz r9,192(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 192);
	// subf r11,r5,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r5.u64;
	// addi r10,r10,-23608
	ctx.r10.s64 = ctx.r10.s64 + -23608;
	// addi r30,r11,31
	ctx.r30.s64 = ctx.r11.s64 + 31;
	// lis r28,-32226
	ctx.r28.s64 = -2111963136;
	// addi r11,r10,4
	ctx.r11.s64 = ctx.r10.s64 + 4;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r10,r28,-19936
	ctx.r10.s64 = ctx.r28.s64 + -19936;
	// rlwinm r7,r30,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lfs f13,-4112(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4112);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r7,r11
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-20468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -20468);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r8)
	REX_STORE_U64(ctx.r8.u32 + 0, ctx.r11.u64);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x823c82a8
	ctx.lr = 0x823E7E54;
	sub_823C82A8(ctx, base);
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r29,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r29.u32);
	// lwz r3,172(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
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
	ctx.lr = 0x823E7E94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
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
	ctx.lr = 0x823E7EC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823EF788) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x823efb88
	sub_823EFB88(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823EFB88) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x823c8488
	ctx.lr = 0x823EFBAC;
	sub_823C8488(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c73f0
	ctx.lr = 0x823EFBB8;
	sub_823C73F0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
loc_823EFBD0:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823efbe4
	if (ctx.cr6.eq) goto loc_823EFBE4;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stb r9,25(r10)
	REX_STORE_U8(ctx.r10.u32 + 25, ctx.r9.u8);
loc_823EFBE4:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x823efbd0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823EFBD0;
	// lwz r10,76(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,52(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x823efc14
	if (!ctx.cr6.eq) goto loc_823EFC14;
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
	// bge cr6,0x823efc38
	if (!ctx.cr6.lt) goto loc_823EFC38;
loc_823EFC14:
	// lwz r11,64(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r9,52(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x823efc40
	if (!ctx.cr6.eq) goto loc_823EFC40;
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
	// bgt cr6,0x823efc40
	if (ctx.cr6.gt) goto loc_823EFC40;
loc_823EFC38:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823efc44
	goto loc_823EFC44;
loc_823EFC40:
	// li r11,1
	ctx.r11.s64 = 1;
loc_823EFC44:
	// lbz r9,152(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x823efc68
	if (ctx.cr0.eq) goto loc_823EFC68;
	// lbz r9,153(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 153);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x823efc68
	if (!ctx.cr0.eq) goto loc_823EFC68;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x823efc6c
	if (!ctx.cr0.eq) goto loc_823EFC6C;
loc_823EFC68:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823EFC6C:
	// stb r11,65(r31)
	REX_STORE_U8(ctx.r31.u32 + 65, ctx.r11.u8);
	// lbz r11,152(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// stb r11,64(r31)
	REX_STORE_U8(ctx.r31.u32 + 64, ctx.r11.u8);
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

DEFINE_REX_FUNC(sub_823F71B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823F71C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x823c5778
	ctx.lr = 0x823F71D0;
	sub_823C5778(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,32140
	ctx.r9.s64 = ctx.r11.s64 + 32140;
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
	// li r4,72
	ctx.r4.s64 = 72;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x823F71FC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823f7210
	if (ctx.cr0.eq) goto loc_823F7210;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x823f7448
	ctx.lr = 0x823F720C;
	sub_823F7448(ctx, base);
	// b 0x823f7214
	goto loc_823F7214;
loc_823F7210:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823F7214:
	// stw r3,156(r30)
	REX_STORE_U32(ctx.r30.u32 + 156, ctx.r3.u32);
	// stw r31,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r31.u32);
	// lwz r31,156(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 156);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// bl 0x82457b58
	ctx.lr = 0x823F7228;
	sub_82457B58(ctx, base);
	// bl 0x825fd7a0
	ctx.lr = 0x823F722C;
	sub_825FD7A0(ctx, base);
	// stw r3,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823f7910
	ctx.lr = 0x823F7238;
	sub_823F7910(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x823F7248;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823f7258
	if (ctx.cr0.eq) goto loc_823F7258;
	// bl 0x823c8308
	ctx.lr = 0x823F7254;
	sub_823C8308(ctx, base);
	// b 0x823f725c
	goto loc_823F725C;
loc_823F7258:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823F725C:
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r4,60(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x823f7280
	if (ctx.cr6.eq) goto loc_823F7280;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823f7b68
	ctx.lr = 0x823F7280;
	sub_823F7B68(ctx, base);
loc_823F7280:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823ecb10
	ctx.lr = 0x823F7288;
	sub_823ECB10(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823FACC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823FACC8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r30,160(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 160);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,32280
	ctx.r11.s64 = ctx.r11.s64 + 32280;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x823fad0c
	if (ctx.cr6.eq) goto loc_823FAD0C;
	// lwz r3,16(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823fad00
	if (ctx.cr6.eq) goto loc_823FAD00;
	// bl 0x823c74f0
	ctx.lr = 0x823FAD00;
	sub_823C74F0(ctx, base);
loc_823FAD00:
	// stw r28,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825e0378
	ctx.lr = 0x823FAD0C;
	sub_825E0378(ctx, base);
loc_823FAD0C:
	// stw r28,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823f9890
	ctx.lr = 0x823FAD18;
	sub_823F9890(ctx, base);
	// clrlwi. r11,r29,31
	ctx.r11.u64 = ctx.r29.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fad28
	if (ctx.cr0.eq) goto loc_823FAD28;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x823FAD28;
	sub_825E0378(ctx, base);
loc_823FAD28:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823FDFB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x823FDFB8;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-2240(r1)
	ea = -2240 + ctx.r1.u32;
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r23
	ctx.r31.u64 = ctx.r23.u64;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lis r25,-32112
	ctx.r25.s64 = -2104492032;
	// addi r28,r11,-18544
	ctx.r28.s64 = ctx.r11.s64 + -18544;
	// addi r24,r10,-19004
	ctx.r24.s64 = ctx.r10.s64 + -19004;
	// addi r26,r9,-19036
	ctx.r26.s64 = ctx.r9.s64 + -19036;
loc_823FDFF4:
	// addi r11,r28,20036
	ctx.r11.s64 = ctx.r28.s64 + 20036;
	// li r4,2048
	ctx.r4.s64 = 2048;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r5,r31,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x823c7af0
	ctx.lr = 0x823FE008;
	sub_823C7AF0(ctx, base);
	// addi r27,r28,20052
	ctx.r27.s64 = ctx.r28.s64 + 20052;
	// lwz r11,-13064(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwzx r4,r31,r27
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	// bne cr6,0x823fe024
	if (!ctx.cr6.eq) goto loc_823FE024;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// b 0x823fe030
	goto loc_823FE030;
loc_823FE024:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235d7f0
	ctx.lr = 0x823FE030;
	sub_8235D7F0(ctx, base);
loc_823FE030:
	// stwx r3,r31,r30
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, ctx.r3.u32);
	// add r11,r29,r26
	ctx.r11.u64 = ctx.r29.u64 + ctx.r26.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfsx f0,r29,r26
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r26.u32);
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
	ctx.lr = 0x823FE058;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r24,4
	ctx.r11.s64 = ctx.r24.s64 + 4;
	// lwzx r9,r31,r30
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// lfsx f0,r29,r24
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r24.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r28,20072
	ctx.r10.s64 = ctx.r28.s64 + 20072;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lfsx f13,r29,r11
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
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
	// lwzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
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
	// bne cr6,0x823fe0c0
	if (!ctx.cr6.eq) goto loc_823FE0C0;
	// lfs f12,-4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// b 0x823fe0c4
	goto loc_823FE0C4;
loc_823FE0C0:
	// lfs f12,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_823FE0C4:
	// li r3,-100
	ctx.r3.s64 = -100;
	// bl 0x823c7f28
	ctx.lr = 0x823FE0CC;
	sub_823C7F28(ctx, base);
	// lwzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// fmuls f0,f1,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// li r10,68
	ctx.r10.s64 = 68;
	// li r9,255
	ctx.r9.s64 = 255;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
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
	// stb r23,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r23.u8);
	// stb r23,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r23.u8);
	// stb r23,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r23.u8);
	// stb r9,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r9.u8);
	// lwzx r3,r31,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823FE118;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r29,32
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 32, ctx.xer);
	// blt cr6,0x823fdff4
	if (ctx.cr6.lt) goto loc_823FDFF4;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x823c80a8
	ctx.lr = 0x823FE130;
	sub_823C80A8(ctx, base);
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// bl 0x82443da0
	ctx.lr = 0x823FE13C;
	sub_82443DA0(ctx, base);
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// li r28,808
	ctx.r28.s64 = 808;
	// lwz r11,-12952(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fe178
	if (ctx.cr6.eq) goto loc_823FE178;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r28
	ctx.r11.u64 = uint32_t((ctx.r28.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r28.s32 == -1)) ? ctx.r11.s32 / ctx.r28.s32 : 0);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x823fe178
	if (!ctx.cr6.gt) goto loc_823FE178;
	// mulli r11,r3,808
	ctx.r11.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(808));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,668(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 668);
	// b 0x823fe17c
	goto loc_823FE17C;
loc_823FE178:
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
loc_823FE17C:
	// li r4,2048
	ctx.r4.s64 = 2048;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823c7af0
	ctx.lr = 0x823FE188;
	sub_823C7AF0(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
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
	ctx.lr = 0x823FE1AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r29,1
	ctx.r29.s64 = 1;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r29,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r29.u32);
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// bl 0x82443da0
	ctx.lr = 0x823FE1D0;
	sub_82443DA0(ctx, base);
	// lwz r11,-12952(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fe204
	if (ctx.cr6.eq) goto loc_823FE204;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r28
	ctx.r11.u64 = uint32_t((ctx.r28.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r28.s32 == -1)) ? ctx.r11.s32 / ctx.r28.s32 : 0);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x823fe204
	if (!ctx.cr6.gt) goto loc_823FE204;
	// mulli r11,r3,808
	ctx.r11.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(808));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,672(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 672);
	// b 0x823fe208
	goto loc_823FE208;
loc_823FE204:
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
loc_823FE208:
	// li r4,2048
	ctx.r4.s64 = 2048;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823c7af0
	ctx.lr = 0x823FE214;
	sub_823C7AF0(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
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
	ctx.lr = 0x823FE238;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lwz r10,16(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r29,124(r10)
	REX_STORE_U32(ctx.r10.u32 + 124, ctx.r29.u32);
	// lfs f0,20(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,3652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 3652);
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r11,0,30,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// addi r11,r11,50
	ctx.r11.s64 = ctx.r11.s64 + 50;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// bl 0x8235e968
	ctx.lr = 0x823FE288;
	sub_8235E968(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lfs f0,14376(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f31,f13
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f13.f64));
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// bl 0x827389e8
	ctx.lr = 0x823FE2B0;
	sub_827389E8(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// addi r1,r1,2240
	ctx.r1.s64 = ctx.r1.s64 + 2240;
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82419BE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82419BF0;
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
	// li r10,41
	ctx.r10.s64 = 41;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r3,12
	ctx.r11.s64 = ctx.r3.s64 + 12;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82419C0C:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// lbz r9,200(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 200);
	// stb r9,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r9.u8);
	// bdnz 0x82419c0c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82419C0C;
	// lbz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 200);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82419d30
	if (ctx.cr0.eq) goto loc_82419D30;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r28,-32227
	ctx.r28.s64 = -2112028672;
	// addi r8,r9,12472
	ctx.r8.s64 = ctx.r9.s64 + 12472;
	// lwz r11,-12972(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12972);
	// lwz r29,4(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f31,12472(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12472);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,-236(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -236);
	ctx.f30.f64 = double(temp.f32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,760(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 760);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82419c80
	if (ctx.cr6.eq) goto loc_82419C80;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f3,17244(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 17244);
	ctx.f3.f64 = double(temp.f32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// fmr f5,f31
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfs f2,-12348(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12348);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x823c5a58
	ctx.lr = 0x82419C7C;
	sub_823C5A58(ctx, base);
	// lwz r11,-12972(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12972);
loc_82419C80:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,764(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 764);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82419cb0
	if (ctx.cr6.eq) goto loc_82419CB0;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f3,17244(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 17244);
	ctx.f3.f64 = double(temp.f32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// fmr f5,f31
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfs f2,-14008(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14008);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x823c5a58
	ctx.lr = 0x82419CB0;
	sub_823C5A58(ctx, base);
loc_82419CB0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82419f80
	ctx.lr = 0x82419CB8;
	sub_82419F80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8241ad00
	ctx.lr = 0x82419CC0;
	sub_8241AD00(ctx, base);
	// lwz r3,184(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82419cd0
	if (ctx.cr6.eq) goto loc_82419CD0;
	// bl 0x823c8528
	ctx.lr = 0x82419CD0;
	sub_823C8528(ctx, base);
loc_82419CD0:
	// lwz r3,204(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// bl 0x823cb3a8
	ctx.lr = 0x82419CD8;
	sub_823CB3A8(ctx, base);
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82419d30
	if (ctx.cr6.eq) goto loc_82419D30;
	// lwz r10,2784(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 2784);
	// li r11,13
	ctx.r11.s64 = 13;
	// lwz r8,180(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// mulli r10,r10,1288
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(1288));
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r9,r10,208
	ctx.r9.s64 = ctx.r10.s64 + 208;
	// lwz r10,208(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 208);
	// subfc r9,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// eqv r11,r11,r10
	ctx.r11.u64 = ~(ctx.r11.u64 ^ ctx.r10.u64);
	// neg r7,r10
	ctx.r7.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rlwinm r11,r11,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// andc r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ~ctx.r10.u64;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r10,r10,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// stb r10,8(r8)
	REX_STORE_U8(ctx.r8.u32 + 8, ctx.r10.u8);
	// stb r11,9(r8)
	REX_STORE_U8(ctx.r8.u32 + 9, ctx.r11.u8);
	// lwz r3,180(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// bl 0x823c7450
	ctx.lr = 0x82419D30;
	sub_823C7450(ctx, base);
loc_82419D30:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824280D8) {
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
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// bl 0x823edfb8
	ctx.lr = 0x824280F4;
	sub_823EDFB8(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82428104
	if (ctx.cr6.eq) goto loc_82428104;
	// bl 0x825e0378
	ctx.lr = 0x82428104;
	sub_825E0378(ctx, base);
loc_82428104:
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// bl 0x823edfb8
	ctx.lr = 0x8242810C;
	sub_823EDFB8(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8242811c
	if (ctx.cr6.eq) goto loc_8242811C;
	// bl 0x825e0378
	ctx.lr = 0x8242811C;
	sub_825E0378(ctx, base);
loc_8242811C:
	// lbz r10,40(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 40);
	// addi r11,r31,12
	ctx.r11.s64 = ctx.r31.s64 + 12;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82428134
	if (ctx.cr0.eq) goto loc_82428134;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r10.u8);
loc_82428134:
	// bl 0x825e04c0
	ctx.lr = 0x82428138;
	sub_825E04C0(ctx, base);
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

DEFINE_REX_FUNC(sub_8242AA90) {
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
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// addi r11,r11,10464
	ctx.r11.s64 = ctx.r11.s64 + 10464;
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8242aae8
	if (ctx.cr6.eq) goto loc_8242AAE8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242AAC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// blt cr6,0x8242aad4
	if (ctx.cr6.lt) goto loc_8242AAD4;
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// ble cr6,0x8242aad8
	if (!ctx.cr6.gt) goto loc_8242AAD8;
loc_8242AAD4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8242AAD8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// b 0x8242aaec
	goto loc_8242AAEC;
loc_8242AAE8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8242AAEC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8242DC00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8242DC08;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r25,-32112
	ctx.r25.s64 = -2104492032;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r3,-12816(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + -12816);
	// bl 0x825a2d20
	ctx.lr = 0x8242DC28;
	sub_825A2D20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lis r5,4
	ctx.r5.s64 = 262144;
	// bl 0x825a17c0
	ctx.lr = 0x8242DC38;
	sub_825A17C0(ctx, base);
	// lis r24,-32240
	ctx.r24.s64 = -2112880640;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r30,2324(r31)
	REX_STORE_U32(ctx.r31.u32 + 2324, ctx.r30.u32);
	// addi r10,r24,12236
	ctx.r10.s64 = ctx.r24.s64 + 12236;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-30416
	ctx.r11.s64 = ctx.r11.s64 + -30416;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r30,2308(r31)
	REX_STORE_U8(ctx.r31.u32 + 2308, ctx.r30.u8);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lfs f31,232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// stb r9,2320(r31)
	REX_STORE_U8(ctx.r31.u32 + 2320, ctx.r9.u8);
	// stfs f31,2260(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2260, temp.u32);
	// stb r30,2321(r31)
	REX_STORE_U8(ctx.r31.u32 + 2321, ctx.r30.u8);
	// stfs f31,2264(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2264, temp.u32);
	// stw r30,2328(r31)
	REX_STORE_U32(ctx.r31.u32 + 2328, ctx.r30.u32);
	// stfs f31,2268(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2268, temp.u32);
	// stw r30,2332(r31)
	REX_STORE_U32(ctx.r31.u32 + 2332, ctx.r30.u32);
	// stfs f31,2272(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2272, temp.u32);
	// stw r30,2336(r31)
	REX_STORE_U32(ctx.r31.u32 + 2336, ctx.r30.u32);
	// stfs f31,2276(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2276, temp.u32);
	// stw r30,2340(r31)
	REX_STORE_U32(ctx.r31.u32 + 2340, ctx.r30.u32);
	// stfs f31,2280(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2280, temp.u32);
	// stw r30,2352(r31)
	REX_STORE_U32(ctx.r31.u32 + 2352, ctx.r30.u32);
	// stfs f31,2292(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2292, temp.u32);
	// stw r30,2356(r31)
	REX_STORE_U32(ctx.r31.u32 + 2356, ctx.r30.u32);
	// stfs f31,2296(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2296, temp.u32);
	// stw r30,2360(r31)
	REX_STORE_U32(ctx.r31.u32 + 2360, ctx.r30.u32);
	// stfs f31,2300(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2300, temp.u32);
	// stb r30,2364(r31)
	REX_STORE_U8(ctx.r31.u32 + 2364, ctx.r30.u8);
	// stfs f31,2304(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2304, temp.u32);
	// stb r30,2365(r31)
	REX_STORE_U8(ctx.r31.u32 + 2365, ctx.r30.u8);
	// stfs f31,2312(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2312, temp.u32);
	// stb r30,2376(r31)
	REX_STORE_U8(ctx.r31.u32 + 2376, ctx.r30.u8);
	// stfs f31,2316(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2316, temp.u32);
	// stw r8,2380(r31)
	REX_STORE_U32(ctx.r31.u32 + 2380, ctx.r8.u32);
	// stb r30,2384(r31)
	REX_STORE_U8(ctx.r31.u32 + 2384, ctx.r30.u8);
	// addi r3,r31,2412
	ctx.r3.s64 = ctx.r31.s64 + 2412;
	// bl 0x8243c288
	ctx.lr = 0x8242DCD4;
	sub_8243C288(ctx, base);
	// li r29,-1
	ctx.r29.s64 = -1;
	// li r11,6
	ctx.r11.s64 = 6;
	// stfs f31,2472(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2472, temp.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stfs f31,2500(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2500, temp.u32);
	// stw r30,2428(r31)
	REX_STORE_U32(ctx.r31.u32 + 2428, ctx.r30.u32);
	// addi r27,r31,2548
	ctx.r27.s64 = ctx.r31.s64 + 2548;
	// stw r30,2448(r31)
	REX_STORE_U32(ctx.r31.u32 + 2448, ctx.r30.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r30,2452(r31)
	REX_STORE_U32(ctx.r31.u32 + 2452, ctx.r30.u32);
	// stw r30,2456(r31)
	REX_STORE_U32(ctx.r31.u32 + 2456, ctx.r30.u32);
	// stw r29,2460(r31)
	REX_STORE_U32(ctx.r31.u32 + 2460, ctx.r29.u32);
	// stb r30,2464(r31)
	REX_STORE_U8(ctx.r31.u32 + 2464, ctx.r30.u8);
	// stb r30,2465(r31)
	REX_STORE_U8(ctx.r31.u32 + 2465, ctx.r30.u8);
	// stw r30,2468(r31)
	REX_STORE_U32(ctx.r31.u32 + 2468, ctx.r30.u32);
	// stw r11,2476(r31)
	REX_STORE_U32(ctx.r31.u32 + 2476, ctx.r11.u32);
	// stb r30,2480(r31)
	REX_STORE_U8(ctx.r31.u32 + 2480, ctx.r30.u8);
	// stw r30,2484(r31)
	REX_STORE_U32(ctx.r31.u32 + 2484, ctx.r30.u32);
	// stw r30,2488(r31)
	REX_STORE_U32(ctx.r31.u32 + 2488, ctx.r30.u32);
	// stw r30,2492(r31)
	REX_STORE_U32(ctx.r31.u32 + 2492, ctx.r30.u32);
	// stw r30,2496(r31)
	REX_STORE_U32(ctx.r31.u32 + 2496, ctx.r30.u32);
	// stw r30,2504(r31)
	REX_STORE_U32(ctx.r31.u32 + 2504, ctx.r30.u32);
	// stw r30,2508(r31)
	REX_STORE_U32(ctx.r31.u32 + 2508, ctx.r30.u32);
	// stw r30,2528(r31)
	REX_STORE_U32(ctx.r31.u32 + 2528, ctx.r30.u32);
	// stw r29,2532(r31)
	REX_STORE_U32(ctx.r31.u32 + 2532, ctx.r29.u32);
	// stfs f31,2540(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2540, temp.u32);
	// stw r10,2536(r31)
	REX_STORE_U32(ctx.r31.u32 + 2536, ctx.r10.u32);
	// stw r30,2544(r31)
	REX_STORE_U32(ctx.r31.u32 + 2544, ctx.r30.u32);
	// stw r30,2552(r31)
	REX_STORE_U32(ctx.r31.u32 + 2552, ctx.r30.u32);
	// stw r30,2556(r31)
	REX_STORE_U32(ctx.r31.u32 + 2556, ctx.r30.u32);
	// stw r30,2560(r31)
	REX_STORE_U32(ctx.r31.u32 + 2560, ctx.r30.u32);
	// stfs f31,2636(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2636, temp.u32);
	// stfs f31,2640(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2640, temp.u32);
	// stw r30,2624(r31)
	REX_STORE_U32(ctx.r31.u32 + 2624, ctx.r30.u32);
	// stfs f31,2644(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2644, temp.u32);
	// stw r30,2656(r31)
	REX_STORE_U32(ctx.r31.u32 + 2656, ctx.r30.u32);
	// stfs f31,2648(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2648, temp.u32);
	// stw r9,2660(r31)
	REX_STORE_U32(ctx.r31.u32 + 2660, ctx.r9.u32);
	// stfs f31,2652(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2652, temp.u32);
	// stb r30,2676(r31)
	REX_STORE_U8(ctx.r31.u32 + 2676, ctx.r30.u8);
	// stfs f31,2680(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2680, temp.u32);
	// stw r30,2688(r31)
	REX_STORE_U32(ctx.r31.u32 + 2688, ctx.r30.u32);
	// stw r30,2692(r31)
	REX_STORE_U32(ctx.r31.u32 + 2692, ctx.r30.u32);
	// addi r28,r31,2984
	ctx.r28.s64 = ctx.r31.s64 + 2984;
	// stw r29,2696(r31)
	REX_STORE_U32(ctx.r31.u32 + 2696, ctx.r29.u32);
	// stw r30,2700(r31)
	REX_STORE_U32(ctx.r31.u32 + 2700, ctx.r30.u32);
	// stb r30,2704(r31)
	REX_STORE_U8(ctx.r31.u32 + 2704, ctx.r30.u8);
	// stw r30,2712(r31)
	REX_STORE_U32(ctx.r31.u32 + 2712, ctx.r30.u32);
	// stw r30,2716(r31)
	REX_STORE_U32(ctx.r31.u32 + 2716, ctx.r30.u32);
	// stw r30,2720(r31)
	REX_STORE_U32(ctx.r31.u32 + 2720, ctx.r30.u32);
	// stw r11,2728(r31)
	REX_STORE_U32(ctx.r31.u32 + 2728, ctx.r11.u32);
	// stw r11,2732(r31)
	REX_STORE_U32(ctx.r31.u32 + 2732, ctx.r11.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stw r30,2724(r31)
	REX_STORE_U32(ctx.r31.u32 + 2724, ctx.r30.u32);
	// stw r30,2736(r31)
	REX_STORE_U32(ctx.r31.u32 + 2736, ctx.r30.u32);
	// stw r30,2740(r31)
	REX_STORE_U32(ctx.r31.u32 + 2740, ctx.r30.u32);
	// stw r30,2744(r31)
	REX_STORE_U32(ctx.r31.u32 + 2744, ctx.r30.u32);
	// stw r30,2764(r31)
	REX_STORE_U32(ctx.r31.u32 + 2764, ctx.r30.u32);
	// stw r30,2768(r31)
	REX_STORE_U32(ctx.r31.u32 + 2768, ctx.r30.u32);
	// stw r30,2772(r31)
	REX_STORE_U32(ctx.r31.u32 + 2772, ctx.r30.u32);
	// stw r30,2776(r31)
	REX_STORE_U32(ctx.r31.u32 + 2776, ctx.r30.u32);
	// stw r30,2780(r31)
	REX_STORE_U32(ctx.r31.u32 + 2780, ctx.r30.u32);
	// stw r30,2788(r31)
	REX_STORE_U32(ctx.r31.u32 + 2788, ctx.r30.u32);
	// stw r30,2792(r31)
	REX_STORE_U32(ctx.r31.u32 + 2792, ctx.r30.u32);
	// stw r30,2796(r31)
	REX_STORE_U32(ctx.r31.u32 + 2796, ctx.r30.u32);
	// stfs f31,2860(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2860, temp.u32);
	// stfs f31,2864(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2864, temp.u32);
	// stw r30,2804(r31)
	REX_STORE_U32(ctx.r31.u32 + 2804, ctx.r30.u32);
	// stfs f31,2920(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2920, temp.u32);
	// stw r30,2808(r31)
	REX_STORE_U32(ctx.r31.u32 + 2808, ctx.r30.u32);
	// stfs f31,2924(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2924, temp.u32);
	// stw r29,2856(r31)
	REX_STORE_U32(ctx.r31.u32 + 2856, ctx.r29.u32);
	// stfs f31,2940(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2940, temp.u32);
	// stw r30,2868(r31)
	REX_STORE_U32(ctx.r31.u32 + 2868, ctx.r30.u32);
	// stfs f31,2944(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 2944, temp.u32);
	// stw r30,2872(r31)
	REX_STORE_U32(ctx.r31.u32 + 2872, ctx.r30.u32);
	// stw r30,2928(r31)
	REX_STORE_U32(ctx.r31.u32 + 2928, ctx.r30.u32);
	// stw r30,2932(r31)
	REX_STORE_U32(ctx.r31.u32 + 2932, ctx.r30.u32);
	// stw r30,2948(r31)
	REX_STORE_U32(ctx.r31.u32 + 2948, ctx.r30.u32);
	// stw r30,2952(r31)
	REX_STORE_U32(ctx.r31.u32 + 2952, ctx.r30.u32);
	// stw r29,2964(r31)
	REX_STORE_U32(ctx.r31.u32 + 2964, ctx.r29.u32);
	// stw r29,2968(r31)
	REX_STORE_U32(ctx.r31.u32 + 2968, ctx.r29.u32);
	// stw r29,2972(r31)
	REX_STORE_U32(ctx.r31.u32 + 2972, ctx.r29.u32);
	// stw r29,2976(r31)
	REX_STORE_U32(ctx.r31.u32 + 2976, ctx.r29.u32);
	// stw r29,2980(r31)
	REX_STORE_U32(ctx.r31.u32 + 2980, ctx.r29.u32);
	// stw r29,2984(r31)
	REX_STORE_U32(ctx.r31.u32 + 2984, ctx.r29.u32);
	// stw r29,2988(r31)
	REX_STORE_U32(ctx.r31.u32 + 2988, ctx.r29.u32);
	// stw r29,2992(r31)
	REX_STORE_U32(ctx.r31.u32 + 2992, ctx.r29.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bl 0x825a4640
	ctx.lr = 0x8242DE48;
	sub_825A4640(ctx, base);
	// lwz r11,-12816(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -12816);
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x825a48b0
	ctx.lr = 0x8242DE60;
	sub_825A48B0(ctx, base);
	// stfs f31,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// stw r30,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// lfs f0,12236(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// stw r30,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r30,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// stfs f31,68(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stfs f31,76(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// stfs f0,80(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// stfs f31,84(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 84, temp.u32);
	// sth r30,88(r31)
	REX_STORE_U16(ctx.r31.u32 + 88, ctx.r30.u16);
	// stw r30,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
	// sth r30,96(r31)
	REX_STORE_U16(ctx.r31.u32 + 96, ctx.r30.u16);
	// li r11,268
	ctx.r11.s64 = 268;
	// stfs f31,100(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 100, temp.u32);
	// addi r10,r31,112
	ctx.r10.s64 = ctx.r31.s64 + 112;
	// stfs f31,104(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 104, temp.u32);
	// stfs f31,108(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// stb r30,112(r31)
	REX_STORE_U8(ctx.r31.u32 + 112, ctx.r30.u8);
	// stb r30,113(r31)
	REX_STORE_U8(ctx.r31.u32 + 113, ctx.r30.u8);
	// stb r30,114(r31)
	REX_STORE_U8(ctx.r31.u32 + 114, ctx.r30.u8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8242DEBC:
	// stw r30,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// stwu r30,8(r10)
	ea = 8 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r30.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8242debc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8242DEBC;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x8242df14
	if (ctx.cr6.eq) goto loc_8242DF14;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8263a178
	ctx.lr = 0x8242DEDC;
	sub_8263A178(ctx, base);
	// stw r3,2332(r31)
	REX_STORE_U32(ctx.r31.u32 + 2332, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8242df14
	if (ctx.cr0.eq) goto loc_8242DF14;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8263a0f0
	ctx.lr = 0x8242DEF0;
	sub_8263A0F0(ctx, base);
	// stw r3,2336(r31)
	REX_STORE_U32(ctx.r31.u32 + 2336, ctx.r3.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32165
	ctx.r10.s64 = -2107965440;
	// lis r9,-32185
	ctx.r9.s64 = -2109276160;
	// addi r4,r10,-13960
	ctx.r4.s64 = ctx.r10.s64 + -13960;
	// addi r3,r9,-13400
	ctx.r3.s64 = ctx.r9.s64 + -13400;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242DF10;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,2340(r31)
	REX_STORE_U32(ctx.r31.u32 + 2340, ctx.r3.u32);
loc_8242DF14:
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8242dff0
	if (ctx.cr6.eq) goto loc_8242DFF0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32189
	ctx.r10.s64 = -2109538304;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r10,-10192
	ctx.r4.s64 = ctx.r10.s64 + -10192;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242DF3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lis r11,-32197
	ctx.r11.s64 = -2110062592;
	// addi r4,r11,23584
	ctx.r4.s64 = ctx.r11.s64 + 23584;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1088(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1088);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242DF58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lis r11,-32197
	ctx.r11.s64 = -2110062592;
	// addi r4,r11,25920
	ctx.r4.s64 = ctx.r11.s64 + 25920;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1092(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1092);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242DF74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12944(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12944);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8242df98
	if (ctx.cr6.eq) goto loc_8242DF98;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x82454730
	ctx.lr = 0x8242DF90;
	sub_82454730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8242df9c
	goto loc_8242DF9C;
loc_8242DF98:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
loc_8242DF9C:
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242DFB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// addi r4,r31,2848
	ctx.r4.s64 = ctx.r31.s64 + 2848;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,604(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 604);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242DFC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8242dfdc
	if (!ctx.cr6.eq) goto loc_8242DFDC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x8242dfec
	goto loc_8242DFEC;
loc_8242DFDC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,576(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 576);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242DFEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8242DFEC:
	// stw r3,2328(r31)
	REX_STORE_U32(ctx.r31.u32 + 2328, ctx.r3.u32);
loc_8242DFF0:
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r9,8(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8242e03c
	if (ctx.cr6.eq) goto loc_8242E03C;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// cmplw cr6,r9,r9
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8242e038
	if (ctx.cr6.eq) goto loc_8242E038;
loc_8242E00C:
	// li r8,5
	ctx.r8.s64 = 5;
	// addi r7,r11,-4
	ctx.r7.s64 = ctx.r11.s64 + -4;
	// addi r6,r10,-4
	ctx.r6.s64 = ctx.r10.s64 + -4;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8242E01C:
	// lwzu r8,4(r7)
	ea = 4 + ctx.r7.u32;
	ctx.r8.u64 = REX_LOAD_U32(ea);
	ctx.r7.u32 = ea;
	// stwu r8,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r6.u32 = ea;
	// bdnz 0x8242e01c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8242E01C;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8242e00c
	if (!ctx.cr6.eq) goto loc_8242E00C;
loc_8242E038:
	// stw r10,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r10.u32);
loc_8242E03C:
	// stw r29,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r29.u32);
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8244EBC0) {
	REX_FUNC_PROLOGUE();
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8244F138) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8244F140;
	__savegprlr_25(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8273af18
	ctx.lr = 0x8244F148;
	__savefpr_24(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = ctx.f1.f64;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244F164;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244fda0
	if (ctx.cr0.eq) goto loc_8244FDA0;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8244fd88
	if (ctx.cr6.eq) goto loc_8244FD88;
	// lwz r3,2340(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244F18C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8244fd88
	if (!ctx.cr0.eq) goto loc_8244FD88;
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
	ctx.lr = 0x8244F1AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8244fd88
	if (!ctx.cr0.eq) goto loc_8244FD88;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r3,2340(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1064(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1064);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244F1D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244fd88
	if (ctx.cr0.eq) goto loc_8244FD88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f25.f64;
	// bl 0x8244baf8
	ctx.lr = 0x8244F1E4;
	sub_8244BAF8(ctx, base);
	// lfs f0,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f25,f0
	ctx.f0.f64 = double(float(ctx.f25.f64 + ctx.f0.f64));
	// stfs f0,64(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82430a10
	ctx.lr = 0x8244F1FC;
	sub_82430A10(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f9,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,108(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r7,12236
	ctx.r5.s64 = ctx.r7.s64 + 12236;
	// lfs f0,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
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
	// lfs f13,76(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f8,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,124(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f8,120(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f8,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// stfs f8,112(r1)
	temp.f32 = float(ctx.f8.f64);
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
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lfs f28,232(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 232);
	ctx.f28.f64 = double(temp.f32);
	// lfs f30,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// lfs f26,12236(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12236);
	ctx.f26.f64 = double(temp.f32);
	// fcmpu cr6,f30,f28
	ctx.cr6.compare(ctx.f30.f64, ctx.f28.f64);
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bge cr6,0x8244f3a8
	if (!ctx.cr6.lt) goto loc_8244F3A8;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// fadds f12,f30,f26
	ctx.f12.f64 = double(float(ctx.f30.f64 + ctx.f26.f64));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r30,r1,144
	ctx.r30.s64 = ctx.r1.s64 + 144;
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r10,17
	ctx.r10.s64 = 17;
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r11,r11,-36
	ctx.r11.s64 = ctx.r11.s64 + -36;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,120(r1)
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
	// stfs f9,108(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v58,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vsubfp128 v59,v59,v58
	simde_mm_store_ps(ctx.v59.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vmulfp128 v62,v62,v60
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vmulfp128 v63,v59,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// fadds f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f11.f64));
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// stfs f13,76(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_8244F37C:
	// li r9,17
	ctx.r9.s64 = 17;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8244F384:
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,40(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f0,f12,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f12.f64, -ctx.f0.f64)));
	// stfs f0,36(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 36, temp.u32);
	// fnmsubs f0,f13,f12,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f12.f64, -ctx.f13.f64)));
	// stfsu f0,40(r11)
	ea = 40 + ctx.r11.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8244f384
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F384;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8244f37c
	if (!ctx.cr0.eq) goto loc_8244F37C;
loc_8244F3A8:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f1,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lfs f31,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f31.f64 = double(temp.f32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// addi r4,r11,616
	ctx.r4.s64 = ctx.r11.s64 + 616;
	// addi r30,r10,24772
	ctx.r30.s64 = ctx.r10.s64 + 24772;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lfs f11,616(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 616);
	ctx.f11.f64 = double(temp.f32);
	// addi r29,r9,-4080
	ctx.r29.s64 = ctx.r9.s64 + -4080;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f27,-2804(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -2804);
	ctx.f27.f64 = double(temp.f32);
	// lfs f5,1840(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1840);
	ctx.f5.f64 = double(temp.f32);
	// fcmpu cr6,f1,f27
	ctx.cr6.compare(ctx.f1.f64, ctx.f27.f64);
	// lfs f7,992(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 992);
	ctx.f7.f64 = double(temp.f32);
	// lfs f3,10636(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 10636);
	ctx.f3.f64 = double(temp.f32);
	// lfs f4,30136(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 30136);
	ctx.f4.f64 = double(temp.f32);
	// lfs f6,224(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 224);
	ctx.f6.f64 = double(temp.f32);
	// lfs f2,-24640(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -24640);
	ctx.f2.f64 = double(temp.f32);
	// lfs f10,-2796(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -2796);
	ctx.f10.f64 = double(temp.f32);
	// lfs f29,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f29.f64 = double(temp.f32);
	// ble cr6,0x8244f4b4
	if (!ctx.cr6.gt) goto loc_8244F4B4;
	// fsubs f0,f1,f27
	ctx.f0.f64 = double(float(ctx.f1.f64 - ctx.f27.f64));
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// fadds f12,f31,f5
	ctx.f12.f64 = double(float(ctx.f31.f64 + ctx.f5.f64));
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
loc_8244F410:
	// clrldi r7,r8,32
	ctx.r7.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r11,16
	ctx.r11.s64 = 16;
	// std r7,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f13,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmsubs f13,f13,f29,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f29.f64, -ctx.f12.f64)));
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fmuls f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fnmsubs f13,f13,f7,f0
	ctx.f13.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f7.f64, -ctx.f0.f64)));
	// stfs f13,640(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 640, temp.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r11,640
	ctx.r11.s64 = ctx.r11.s64 + 640;
	// addi r10,r11,-40
	ctx.r10.s64 = ctx.r11.s64 + -40;
loc_8244F45C:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f24,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// fsubs f24,f13,f24
	ctx.f24.f64 = double(float(ctx.f13.f64 - ctx.f24.f64));
	// fcmpu cr6,f24,f3
	ctx.cr6.compare(ctx.f24.f64, ctx.f3.f64);
	// ble cr6,0x8244f478
	if (!ctx.cr6.gt) goto loc_8244F478;
	// fsubs f13,f13,f3
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f3.f64));
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_8244F478:
	// addi r11,r11,-40
	ctx.r11.s64 = ctx.r11.s64 + -40;
	// addi r10,r10,-40
	ctx.r10.s64 = ctx.r10.s64 + -40;
	// bdnz 0x8244f45c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F45C;
	// li r10,17
	ctx.r10.s64 = 17;
	// addi r11,r11,-40
	ctx.r11.s64 = ctx.r11.s64 + -40;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8244F490:
	// lfs f13,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfsu f13,40(r11)
	ea = 40 + ctx.r11.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8244f490
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F490;
	// addi r9,r9,680
	ctx.r9.s64 = ctx.r9.s64 + 680;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r9,10880
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 10880, ctx.xer);
	// ble cr6,0x8244f410
	if (!ctx.cr6.gt) goto loc_8244F410;
	// b 0x8244f564
	goto loc_8244F564;
loc_8244F4B4:
	// fcmpu cr6,f1,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f10.f64);
	// bge cr6,0x8244f574
	if (!ctx.cr6.lt) goto loc_8244F574;
	// fadds f0,f1,f27
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f27.f64));
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// fadds f12,f31,f5
	ctx.f12.f64 = double(float(ctx.f31.f64 + ctx.f5.f64));
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
loc_8244F4CC:
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// lwz r7,56(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r11,16
	ctx.r11.s64 = 16;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f13,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmsubs f13,f13,f29,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f29.f64, -ctx.f12.f64)));
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fmuls f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fnmsubs f13,f13,f7,f0
	ctx.f13.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f7.f64, -ctx.f0.f64)));
	// stfsx f13,r9,r7
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r7.u32, temp.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r10,r11,40
	ctx.r10.s64 = ctx.r11.s64 + 40;
loc_8244F510:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f24,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// fsubs f24,f13,f24
	ctx.f24.f64 = double(float(ctx.f13.f64 - ctx.f24.f64));
	// fcmpu cr6,f24,f4
	ctx.cr6.compare(ctx.f24.f64, ctx.f4.f64);
	// bge cr6,0x8244f52c
	if (!ctx.cr6.lt) goto loc_8244F52C;
	// fadds f13,f13,f3
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f3.f64));
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_8244F52C:
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// bdnz 0x8244f510
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F510;
	// li r10,17
	ctx.r10.s64 = 17;
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8244F544:
	// lfs f13,-40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -40);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfsu f13,-40(r11)
	ea = -40 + ctx.r11.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8244f544
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F544;
	// addi r9,r9,680
	ctx.r9.s64 = ctx.r9.s64 + 680;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r9,10880
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 10880, ctx.xer);
	// ble cr6,0x8244f4cc
	if (!ctx.cr6.gt) goto loc_8244F4CC;
loc_8244F564:
	// lfs f13,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// b 0x8244f5e0
	goto loc_8244F5E0;
loc_8244F574:
	// fcmpu cr6,f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f28.f64);
	// ble cr6,0x8244f58c
	if (!ctx.cr6.gt) goto loc_8244F58C;
	// fcmpu cr6,f1,f29
	ctx.cr6.compare(ctx.f1.f64, ctx.f29.f64);
	// blt cr6,0x8244f59c
	if (ctx.cr6.lt) goto loc_8244F59C;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x8244f5a8
	goto loc_8244F5A8;
loc_8244F58C:
	// fcmpu cr6,f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f28.f64);
	// bge cr6,0x8244f5b4
	if (!ctx.cr6.lt) goto loc_8244F5B4;
	// fcmpu cr6,f1,f11
	ctx.cr6.compare(ctx.f1.f64, ctx.f11.f64);
	// ble cr6,0x8244f5a4
	if (!ctx.cr6.gt) goto loc_8244F5A4;
loc_8244F59C:
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
	// b 0x8244f5a8
	goto loc_8244F5A8;
loc_8244F5A4:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f11.f64;
loc_8244F5A8:
	// lfs f13,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f25,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f25.f64, ctx.f13.f64)));
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_8244F5B4:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r10,17
	ctx.r10.s64 = 17;
	// addi r11,r11,-40
	ctx.r11.s64 = ctx.r11.s64 + -40;
loc_8244F5C0:
	// li r9,17
	ctx.r9.s64 = 17;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8244F5C8:
	// lfs f0,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f2
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f2.f64));
	// stfsu f0,40(r11)
	ea = 40 + ctx.r11.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8244f5c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F5C8;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8244f5c0
	if (!ctx.cr0.eq) goto loc_8244F5C0;
loc_8244F5E0:
	// fcmpu cr6,f31,f27
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f27.f64);
	// ble cr6,0x8244f6a4
	if (!ctx.cr6.gt) goto loc_8244F6A4;
	// fsubs f0,f31,f27
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f27.f64));
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// fadds f13,f1,f5
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f5.f64));
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// fneg f11,f0
	ctx.f11.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8244F5FC:
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r11,16
	ctx.r11.s64 = 16;
	// std r7,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f12,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmsubs f12,f12,f29,f13
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f29.f64, -ctx.f13.f64)));
	// fabs f12,f12
	ctx.f12.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fmuls f12,f12,f6
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f6.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmsubs f12,f12,f7,f0
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f7.f64, -ctx.f0.f64)));
	// stfs f12,10884(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 10884, temp.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r11,10880
	ctx.r11.s64 = ctx.r11.s64 + 10880;
	// addi r10,r11,-680
	ctx.r10.s64 = ctx.r11.s64 + -680;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_8244F64C:
	// lfs f12,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f10,f12,f10
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fcmpu cr6,f10,f4
	ctx.cr6.compare(ctx.f10.f64, ctx.f4.f64);
	// bge cr6,0x8244f668
	if (!ctx.cr6.lt) goto loc_8244F668;
	// fadds f12,f12,f3
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f3.f64));
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_8244F668:
	// addi r11,r11,-680
	ctx.r11.s64 = ctx.r11.s64 + -680;
	// addi r10,r10,-680
	ctx.r10.s64 = ctx.r10.s64 + -680;
	// bdnz 0x8244f64c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F64C;
	// li r10,17
	ctx.r10.s64 = 17;
	// addi r11,r11,-676
	ctx.r11.s64 = ctx.r11.s64 + -676;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8244F680:
	// lfs f12,680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 680);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// stfsu f12,680(r11)
	ea = 680 + ctx.r11.u32;
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8244f680
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F680;
	// addi r9,r9,40
	ctx.r9.s64 = ctx.r9.s64 + 40;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r9,640
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 640, ctx.xer);
	// ble cr6,0x8244f5fc
	if (!ctx.cr6.gt) goto loc_8244F5FC;
	// b 0x8244f760
	goto loc_8244F760;
loc_8244F6A4:
	// fcmpu cr6,f31,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f10.f64);
	// bge cr6,0x8244f770
	if (!ctx.cr6.lt) goto loc_8244F770;
	// fadds f0,f31,f27
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f27.f64));
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// fadds f13,f1,f5
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f5.f64));
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// fneg f11,f0
	ctx.f11.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8244F6C0:
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r11,16
	ctx.r11.s64 = 16;
	// std r7,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f12,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmsubs f12,f12,f29,f13
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f29.f64, -ctx.f13.f64)));
	// fabs f12,f12
	ctx.f12.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fmuls f12,f12,f6
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f6.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmsubs f12,f12,f7,f0
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f7.f64, -ctx.f0.f64)));
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r10,r11,680
	ctx.r10.s64 = ctx.r11.s64 + 680;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_8244F70C:
	// lfs f12,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f10,f12,f10
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fcmpu cr6,f10,f3
	ctx.cr6.compare(ctx.f10.f64, ctx.f3.f64);
	// ble cr6,0x8244f728
	if (!ctx.cr6.gt) goto loc_8244F728;
	// fsubs f12,f12,f3
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f3.f64));
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_8244F728:
	// addi r11,r11,680
	ctx.r11.s64 = ctx.r11.s64 + 680;
	// addi r10,r10,680
	ctx.r10.s64 = ctx.r10.s64 + 680;
	// bdnz 0x8244f70c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F70C;
	// li r10,17
	ctx.r10.s64 = 17;
	// addi r11,r11,684
	ctx.r11.s64 = ctx.r11.s64 + 684;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8244F740:
	// lfs f12,-680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -680);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// stfsu f12,-680(r11)
	ea = -680 + ctx.r11.u32;
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8244f740
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F740;
	// addi r9,r9,40
	ctx.r9.s64 = ctx.r9.s64 + 40;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r9,640
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 640, ctx.xer);
	// ble cr6,0x8244f6c0
	if (!ctx.cr6.gt) goto loc_8244F6C0;
loc_8244F760:
	// lfs f13,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,76(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// b 0x8244f7dc
	goto loc_8244F7DC;
loc_8244F770:
	// fcmpu cr6,f31,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f28.f64);
	// ble cr6,0x8244f788
	if (!ctx.cr6.gt) goto loc_8244F788;
	// fcmpu cr6,f31,f29
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// blt cr6,0x8244f798
	if (ctx.cr6.lt) goto loc_8244F798;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x8244f7a4
	goto loc_8244F7A4;
loc_8244F788:
	// fcmpu cr6,f31,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f28.f64);
	// bge cr6,0x8244f7b0
	if (!ctx.cr6.lt) goto loc_8244F7B0;
	// fcmpu cr6,f31,f11
	ctx.cr6.compare(ctx.f31.f64, ctx.f11.f64);
	// ble cr6,0x8244f7a0
	if (!ctx.cr6.gt) goto loc_8244F7A0;
loc_8244F798:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
	// b 0x8244f7a4
	goto loc_8244F7A4;
loc_8244F7A0:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f11.f64;
loc_8244F7A4:
	// lfs f13,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f25,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f25.f64, ctx.f13.f64)));
	// stfs f0,76(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
loc_8244F7B0:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r10,17
	ctx.r10.s64 = 17;
	// addi r11,r11,-36
	ctx.r11.s64 = ctx.r11.s64 + -36;
loc_8244F7BC:
	// li r9,17
	ctx.r9.s64 = 17;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8244F7C4:
	// lfs f0,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f2
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f2.f64));
	// stfsu f0,40(r11)
	ea = 40 + ctx.r11.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8244f7c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F7C4;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8244f7bc
	if (!ctx.cr0.eq) goto loc_8244F7BC;
loc_8244F7DC:
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,289
	ctx.r10.s64 = 289;
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// addi r7,r9,-10728
	ctx.r7.s64 = ctx.r9.s64 + -10728;
	// addi r6,r8,-10716
	ctx.r6.s64 = ctx.r8.s64 + -10716;
loc_8244F7F8:
	// lwz r9,60(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// lwz r25,0(r6)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r26,-1
	ctx.r26.s64 = -1;
	// add r27,r11,r9
	ctx.r27.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stwx r25,r11,r9
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, ctx.r25.u32);
	// lwz r9,4(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// stw r9,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r9.u32);
	// lwz r9,8(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// stw r9,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r9.u32);
	// lwz r9,12(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// stw r9,12(r27)
	REX_STORE_U32(ctx.r27.u32 + 12, ctx.r9.u32);
	// lwz r9,60(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r8,0(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// stw r8,16(r9)
	REX_STORE_U32(ctx.r9.u32 + 16, ctx.r8.u32);
	// lwz r8,4(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// stw r8,20(r9)
	REX_STORE_U32(ctx.r9.u32 + 20, ctx.r8.u32);
	// lwz r8,8(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// stw r8,24(r9)
	REX_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r9,60(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r26,28(r9)
	REX_STORE_U32(ctx.r9.u32 + 28, ctx.r26.u32);
	// ld r9,-10736(r5)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r5.u32 + -10736);
	// lwz r8,60(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// std r9,32(r8)
	REX_STORE_U64(ctx.r8.u32 + 32, ctx.r9.u64);
	// bne 0x8244f7f8
	if (!ctx.cr0.eq) goto loc_8244F7F8;
	// fcmpu cr6,f30,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f30.f64, ctx.f28.f64);
	// bge cr6,0x8244fa70
	if (!ctx.cr6.lt) goto loc_8244FA70;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8244f898
	if (ctx.cr6.eq) goto loc_8244F898;
	// ld r10,2432(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 2432);
	// ld r11,2440(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2440);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
loc_8244F898:
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r27,r1,128
	ctx.r27.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r26,r1,112
	ctx.r26.s64 = ctx.r1.s64 + 112;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r25,r1,96
	ctx.r25.s64 = ctx.r1.s64 + 96;
	// stfs f9,124(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r11,-36
	ctx.r10.s64 = ctx.r11.s64 + -36;
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
	// lfs f11,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f8,108(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f8,104(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f8,100(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f8,96(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fadds f13,f30,f26
	ctx.f13.f64 = double(float(ctx.f30.f64 + ctx.f26.f64));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vaddfp128 v12,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f12,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v57,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,988(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 988);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v60,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v59,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v57.f32)));
	// lvx128 v58,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,152(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// vaddfp128 v10,v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f11,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f11,148(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v59,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v11,v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v60.f32)));
loc_8244F990:
	// extsw r11,r8
	ctx.r11.s64 = ctx.r8.s32;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// li r9,17
	ctx.r9.s64 = 17;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lfd f11,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmuls f11,f11,f12
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f11,148(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f11,152(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v11,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8244F9DC:
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// lfs f10,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f10.f64 = double(temp.f32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f9,76(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f9.f64 = double(temp.f32);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// frsp f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// lfs f7,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f10,f10,f5
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f5.f64));
	// lfs f6,36(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f9,f9,f5
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f5.f64));
	// lfs f4,40(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// fmuls f8,f8,f12
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfs f8,132(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f8,128(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f8,136(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fadds f9,f9,f11
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// stfs f8,140(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fmadds f10,f8,f0,f10
	ctx.f10.f64 = double(float(std::fma(ctx.f8.f64, ctx.f0.f64, ctx.f10.f64)));
	// fsubs f9,f7,f9
	ctx.f9.f64 = double(float(ctx.f7.f64 - ctx.f9.f64));
	// lvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v13,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fnmsubs f9,f9,f13,f4
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(-std::fma(ctx.f9.f64, ctx.f13.f64, -ctx.f4.f64)));
	// lfs f8,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f10,f8,f10
	ctx.f10.f64 = double(float(ctx.f8.f64 - ctx.f10.f64));
	// fmadds f10,f10,f13,f6
	ctx.f10.f64 = double(float(std::fma(ctx.f10.f64, ctx.f13.f64, ctx.f6.f64)));
	// stfs f10,36(r10)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r10.u32 + 36, temp.u32);
	// stfsu f9,40(r10)
	ea = 40 + ctx.r10.u32;
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8244f9dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244F9DC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// ble cr6,0x8244f990
	if (!ctx.cr6.gt) goto loc_8244F990;
	// b 0x8244fc6c
	goto loc_8244FC6C;
loc_8244FA70:
	// fcmpu cr6,f30,f26
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f30.f64, ctx.f26.f64);
	// bge cr6,0x8244fc6c
	if (!ctx.cr6.lt) goto loc_8244FC6C;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8244fa94
	if (ctx.cr6.eq) goto loc_8244FA94;
	// ld r10,2432(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 2432);
	// ld r11,2440(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2440);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
loc_8244FA94:
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f11,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r26,r1,128
	ctx.r26.s64 = ctx.r1.s64 + 128;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// addi r25,r1,112
	ctx.r25.s64 = ctx.r1.s64 + 112;
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r27,r1,144
	ctx.r27.s64 = ctx.r1.s64 + 144;
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r28,r1,96
	ctx.r28.s64 = ctx.r1.s64 + 96;
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fsubs f10,f26,f30
	ctx.f10.f64 = double(float(ctx.f26.f64 - ctx.f30.f64));
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r10,r11,-36
	ctx.r10.s64 = ctx.r11.s64 + -36;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f8,120(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f8,116(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f8,112(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f8,124(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fmuls f12,f10,f10
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// lfs f0,96(r1)
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
	// lvx128 v59,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f9,140(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f9,136(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f9,132(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f9,128(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vaddfp128 v10,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stfs f11,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v60,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vsubfp128 v13,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lfs f0,988(r4)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 988);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v58,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v12,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// lvx128 v58,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v11,v58,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v62.f32)));
loc_8244FB90:
	// extsw r11,r8
	ctx.r11.s64 = ctx.r8.s32;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f11,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// li r9,17
	ctx.r9.s64 = 17;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// fmuls f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f11,152(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f11,148(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v11,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8244FBDC:
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// lfs f8,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f8,f8,f5
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f5.f64));
	// lfs f7,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f7.f64 = double(temp.f32);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f9,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// fsubs f9,f9,f5
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f5.f64));
	// lfs f6,36(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,40(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// fadds f8,f8,f11
	ctx.f8.f64 = double(float(ctx.f8.f64 + ctx.f11.f64));
	// fsubs f8,f7,f8
	ctx.f8.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// lfd f3,80(r1)
	ctx.f3.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f3
	ctx.f3.f64 = double(ctx.f3.s64);
	// fnmsubs f8,f8,f10,f4
	ctx.f8.f64 = double(float(-std::fma(ctx.f8.f64, ctx.f10.f64, -ctx.f4.f64)));
	// frsp f7,f3
	ctx.f7.f64 = double(float(ctx.f3.f64));
	// fmuls f7,f7,f13
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stfs f7,140(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f7,132(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f7,128(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f7,136(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fmadds f9,f7,f0,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f7.f64, ctx.f0.f64, ctx.f9.f64)));
	// lvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v13,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f9,f7,f9
	ctx.f9.f64 = double(float(ctx.f7.f64 - ctx.f9.f64));
	// fmadds f9,f9,f12,f6
	ctx.f9.f64 = double(float(std::fma(ctx.f9.f64, ctx.f12.f64, ctx.f6.f64)));
	// stfs f9,36(r10)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r10.u32 + 36, temp.u32);
	// stfsu f8,40(r10)
	ea = 40 + ctx.r10.u32;
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8244fbdc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244FBDC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// ble cr6,0x8244fb90
	if (!ctx.cr6.gt) goto loc_8244FB90;
loc_8244FC6C:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r8,60(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lfs f10,1304(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1304);
	ctx.f10.f64 = double(temp.f32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lfs f9,448(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 448);
	ctx.f9.f64 = double(temp.f32);
	// fadds f8,f1,f5
	ctx.f8.f64 = double(float(ctx.f1.f64 + ctx.f5.f64));
	// fadds f7,f31,f5
	ctx.f7.f64 = double(float(ctx.f31.f64 + ctx.f5.f64));
	// lfs f11,-8568(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8568);
	ctx.f11.f64 = double(temp.f32);
loc_8244FC8C:
	// extsw r10,r9
	ctx.r10.s64 = ctx.r9.s32;
	// li r11,17
	ctx.r11.s64 = 17;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmsubs f13,f0,f29,f7
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f29.f64, -ctx.f7.f64)));
	// fmuls f12,f13,f13
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
loc_8244FCB4:
	// extsw r11,r10
	ctx.r11.s64 = ctx.r10.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmsubs f0,f0,f29,f8
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f29.f64, -ctx.f8.f64)));
	// fmadds f6,f0,f0,f12
	ctx.f6.f64 = double(float(std::fma(ctx.f0.f64, ctx.f0.f64, ctx.f12.f64)));
	// fcmpu cr6,f6,f9
	ctx.cr6.compare(ctx.f6.f64, ctx.f9.f64);
	// bge cr6,0x8244fcf8
	if (!ctx.cr6.lt) goto loc_8244FCF8;
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f6,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f13,f11
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// lfs f4,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f0,f0,f10,f6
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f10.f64, ctx.f6.f64)));
	// stfs f0,0(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fnmsubs f0,f5,f10,f4
	ctx.f0.f64 = double(float(-std::fma(ctx.f5.f64, ctx.f10.f64, -ctx.f4.f64)));
	// stfs f0,4(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
loc_8244FCF8:
	// addi r8,r8,40
	ctx.r8.s64 = ctx.r8.s64 + 40;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8244fcb4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8244FCB4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// ble cr6,0x8244fc8c
	if (!ctx.cr6.gt) goto loc_8244FC8C;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
loc_8244FD14:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lfs f0,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f25,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f25.f64, ctx.f13.f64)));
	// stfs f0,20(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r6,r11,r7
	ctx.r6.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lfs f1,20(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822ea1a8
	ctx.lr = 0x8244FD3C;
	sub_822EA1A8(ctx, base);
	// stb r3,28(r6)
	REX_STORE_U8(ctx.r6.u32 + 28, ctx.r3.u8);
	// fadds f0,f1,f26
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f26.f64));
	// fmuls f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f27.f64));
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// stb r3,29(r11)
	REX_STORE_U8(ctx.r11.u32 + 29, ctx.r3.u8);
	// lbz r10,103(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// stb r3,30(r11)
	REX_STORE_U8(ctx.r11.u32 + 30, ctx.r3.u8);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r7,r7,40
	ctx.r7.s64 = ctx.r7.s64 + 40;
	// stb r10,31(r11)
	REX_STORE_U8(ctx.r11.u32 + 31, ctx.r10.u8);
	// cmplwi cr6,r7,11560
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 11560, ctx.xer);
	// blt cr6,0x8244fd14
	if (ctx.cr6.lt) goto loc_8244FD14;
	// b 0x8244fda0
	goto loc_8244FDA0;
loc_8244FD88:
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
	ctx.lr = 0x8244FDA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8244FDA0:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8273af64
	ctx.lr = 0x8244FDAC;
	__restfpr_24(ctx, base);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824D0BF8) {
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
	// addi r11,r11,-15840
	ctx.r11.s64 = ctx.r11.s64 + -15840;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x824D0C24;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824d0c34
	if (ctx.cr0.eq) goto loc_824D0C34;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x824D0C34;
	sub_825E0378(ctx, base);
loc_824D0C34:
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

DEFINE_REX_FUNC(sub_824D2EA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lwz r11,308(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 308);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// addi r8,r10,32560
	ctx.r8.s64 = ctx.r10.s64 + 32560;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// stw r11,308(r3)
	REX_STORE_U32(ctx.r3.u32 + 308, ctx.r11.u32);
	// lfs f0,68(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,68(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stb r11,186(r3)
	REX_STORE_U8(ctx.r3.u32 + 186, ctx.r11.u8);
	// stb r10,356(r3)
	REX_STORE_U8(ctx.r3.u32 + 356, ctx.r10.u8);
	// stb r10,116(r3)
	REX_STORE_U8(ctx.r3.u32 + 116, ctx.r10.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D4E60) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,312(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 312);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824d5010
	if (ctx.cr6.eq) goto loc_824D5010;
	// lwz r10,288(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 288);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bgt cr6,0x824d4f10
	if (ctx.cr6.gt) goto loc_824D4F10;
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
	// bne cr6,0x824d5010
	if (!ctx.cr6.eq) goto loc_824D5010;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824d5010
	if (ctx.cr6.eq) goto loc_824D5010;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r9,r10,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x824d4eec
	if (ctx.cr0.eq) goto loc_824D4EEC;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_824D4ED8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x824D4EE0;
	sub_82430A88(ctx, base);
loc_824D4EE0:
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
	// b 0x824d50a0
	goto loc_824D50A0;
loc_824D4EEC:
	// rlwinm. r10,r10,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x824d5010
	if (ctx.cr0.eq) goto loc_824D5010;
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// addi r11,r11,-3204
	ctx.r11.s64 = ctx.r11.s64 + -3204;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// b 0x824d50a0
	goto loc_824D50A0;
loc_824D4F10:
	// bl 0x824281d8
	ctx.lr = 0x824D4F14;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824d4f50
	if (!ctx.cr0.eq) goto loc_824D4F50;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,312(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
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
	// bne cr6,0x824d5010
	if (!ctx.cr6.eq) goto loc_824D5010;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824d5010
	if (ctx.cr6.eq) goto loc_824D5010;
	// b 0x824d4ed8
	goto loc_824D4ED8;
loc_824D4F50:
	// bl 0x82429a18
	ctx.lr = 0x824D4F54;
	sub_82429A18(ctx, base);
	// lwz r3,312(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// bl 0x82429960
	ctx.lr = 0x824D4F5C;
	sub_82429960(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82429668
	ctx.lr = 0x824D4F68;
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
	// bne 0x824d5004
	if (!ctx.cr0.eq) goto loc_824D5004;
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
	// beq 0x824d5008
	if (ctx.cr0.eq) goto loc_824D5008;
loc_824D5004:
	// li r11,1
	ctx.r11.s64 = 1;
loc_824D5008:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824d4ee0
	if (!ctx.cr0.eq) goto loc_824D4EE0;
loc_824D5010:
	// bl 0x82577228
	ctx.lr = 0x824D5014;
	sub_82577228(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfs f31,14376(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14376);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f30,f0,f31
	ctx.f30.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x82577290
	ctx.lr = 0x824D5038;
	sub_82577290(ctx, base);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f30,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f30,112(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f30,116(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
loc_824D50A0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

DEFINE_REX_FUNC(sub_824E53C0) {
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
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// lwz r10,300(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 300);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,22232
	ctx.r11.s64 = ctx.r11.s64 + 22232;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824e561c
	if (!ctx.cr6.eq) goto loc_824E561C;
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,92(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E540C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,15088(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f1,f0
	ctx.f31.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E5430;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,-29492(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f30,f1,f0
	ctx.f30.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E5458;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f30,140(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f30,136(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f30,132(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f30,128(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r6,-32226
	ctx.r6.s64 = -2111963136;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r6,r6,2688
	ctx.r6.s64 = ctx.r6.s64 + 2688;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r5,228(r1)
	REX_STORE_U32(ctx.r1.u32 + 228, ctx.r5.u32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stw r6,224(r1)
	REX_STORE_U32(ctx.r1.u32 + 224, ctx.r6.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f31,184(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f31,180(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f31,176(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f30,220(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// lwz r30,-13032(r8)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r8.u32 + -13032);
	// stfs f30,216(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f30,212(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f30,208(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f31,168(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f31,164(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f31,160(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
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
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// vsubfp128 v62,v62,v60
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v61,v60
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,208(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f10.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// std r11,232(r1)
	REX_STORE_U64(ctx.r1.u32 + 232, ctx.r11.u64);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r10,240(r1)
	REX_STORE_U64(ctx.r1.u32 + 240, ctx.r10.u64);
	// beq cr6,0x824e55cc
	if (ctx.cr6.eq) goto loc_824E55CC;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x823aefa8
	ctx.lr = 0x824E55C8;
	sub_823AEFA8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_824E55CC:
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
	// lwz r7,296(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
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
	// beq cr6,0x824e5618
	if (ctx.cr6.eq) goto loc_824E5618;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r11,2880
	ctx.r10.s64 = ctx.r11.s64 + 2880;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x823b0938
	ctx.lr = 0x824E5614;
	sub_823B0938(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_824E5618:
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
loc_824E561C:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
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

DEFINE_REX_FUNC(sub_824FA198) {
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
	// lfs f13,8(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17608(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -17608);
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
	ctx.lr = 0x824FA1FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 328);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824fa224
	if (ctx.cr0.eq) goto loc_824FA224;
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
	ctx.lr = 0x824FA224;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824FA224:
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

DEFINE_REX_FUNC(sub_824FC668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x824FC670;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,6(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,128(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 128);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r8,124(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// addi r30,r3,120
	ctx.r30.s64 = ctx.r3.s64 + 120;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
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
	// lis r27,-32114
	ctx.r27.s64 = -2104623104;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r26,-32111
	ctx.r26.s64 = -2104426496;
	// li r28,0
	ctx.r28.s64 = 0;
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// beq 0x824fc72c
	if (ctx.cr0.eq) goto loc_824FC72C;
	// li r29,0
	ctx.r29.s64 = 0;
loc_824FC6C8:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f0,280(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16888(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -16888);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824FC6F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
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
	ctx.lr = 0x824FC70C;
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
	// blt cr6,0x824fc6c8
	if (ctx.cr6.lt) goto loc_824FC6C8;
loc_824FC72C:
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
	// beq 0x824fc7b0
	if (ctx.cr0.eq) goto loc_824FC7B0;
	// li r29,0
	ctx.r29.s64 = 0;
loc_824FC74C:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f0,280(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16888(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -16888);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824FC774;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
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
	ctx.lr = 0x824FC790;
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
	// blt cr6,0x824fc74c
	if (ctx.cr6.lt) goto loc_824FC74C;
loc_824FC7B0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82505ED8) {
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
	// lbz r11,312(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 312);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// beq 0x82505f08
	if (ctx.cr0.eq) goto loc_82505F08;
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// lfs f0,236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82505f0c
	goto loc_82505F0C;
loc_82505F08:
	// lfs f0,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
loc_82505F0C:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82505F2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 312);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82505f54
	if (ctx.cr0.eq) goto loc_82505F54;
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
	ctx.lr = 0x82505F54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82505F54:
	// li r11,1
	ctx.r11.s64 = 1;
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

DEFINE_REX_FUNC(sub_8250AA30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8250AA38;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82223a50
	ctx.lr = 0x8250AA48;
	sub_82223A50(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lfs f31,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// beq cr6,0x8250aca8
	if (ctx.cr6.eq) goto loc_8250ACA8;
	// lfs f13,144(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f13,144(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 144, temp.u32);
	// lfs f13,120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f12,124(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 124);
	ctx.f12.f64 = double(temp.f32);
	// addi r28,r1,112
	ctx.r28.s64 = ctx.r1.s64 + 112;
	// fmadds f13,f12,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r29,r1,144
	ctx.r29.s64 = ctx.r1.s64 + 144;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r26,r1,144
	ctx.r26.s64 = ctx.r1.s64 + 144;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r27,0(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lwz r27,24(r27)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// stfs f13,120(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// lfs f13,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lfs f0,112(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,108(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,148(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
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
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
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
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bctrl 
	ctx.lr = 0x8250ABFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 152);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8250ac48
	if (!ctx.cr0.eq) goto loc_8250AC48;
	// lfs f0,140(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f11,136(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 136);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,26028(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-9856(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9856);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f13,f12,f13,f11
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f11.f64)));
	// stfs f13,136(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 136, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8250ac6c
	if (ctx.cr6.lt) goto loc_8250AC6C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f0,136(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 136, temp.u32);
	// stb r11,152(r31)
	REX_STORE_U8(ctx.r31.u32 + 152, ctx.r11.u8);
	// b 0x8250ac6c
	goto loc_8250AC6C;
loc_8250AC48:
	// lfs f0,136(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,140(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f0,f13,f12,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f12.f64, -ctx.f0.f64)));
	// stfs f0,136(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 136, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8250ac6c
	if (ctx.cr6.gt) goto loc_8250AC6C;
	// stfs f31,136(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 136, temp.u32);
	// li r30,0
	ctx.r30.s64 = 0;
loc_8250AC6C:
	// lfs f0,136(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 136);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lbz r10,95(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 95);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// lbz r11,90(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 90);
	// lbz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 88);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lbz r11,89(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 89);
	// stb r10,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
loc_8250ACA8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825214E8) {
	REX_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,269(r3)
	REX_STORE_U8(ctx.r3.u32 + 269, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82521CA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82521CA8;
	__savegprlr_27(ctx, base);
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
	// li r4,392
	ctx.r4.s64 = 392;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// bl 0x825e02a0
	ctx.lr = 0x82521CD8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82521cfc
	if (ctx.cr0.eq) goto loc_82521CFC;
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
	// bl 0x82521d18
	ctx.lr = 0x82521CF8;
	sub_82521D18(ctx, base);
	// b 0x82521d00
	goto loc_82521D00;
loc_82521CFC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82521D00:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82521d0c
	if (ctx.cr6.eq) goto loc_82521D0C;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
loc_82521D0C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82524C18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x82524C20;
	__savegprlr_21(ctx, base);
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// bgt cr6,0x82524c4c
	if (ctx.cr6.gt) goto loc_82524C4C;
	// li r28,4
	ctx.r28.s64 = 4;
	// b 0x82524c6c
	goto loc_82524C6C;
loc_82524C4C:
	// cmpwi cr6,r30,3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 3, ctx.xer);
	// bgt cr6,0x82524c5c
	if (ctx.cr6.gt) goto loc_82524C5C;
	// li r28,5
	ctx.r28.s64 = 5;
	// b 0x82524c6c
	goto loc_82524C6C;
loc_82524C5C:
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// li r28,6
	ctx.r28.s64 = 6;
	// ble cr6,0x82524c6c
	if (!ctx.cr6.gt) goto loc_82524C6C;
	// li r28,7
	ctx.r28.s64 = 7;
loc_82524C6C:
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// ble cr6,0x82524d34
	if (!ctx.cr6.gt) goto loc_82524D34;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// addi r26,r10,-3144
	ctx.r26.s64 = ctx.r10.s64 + -3144;
	// addi r21,r11,22072
	ctx.r21.s64 = ctx.r11.s64 + 22072;
	// lfs f31,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
loc_82524C94:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r21)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r21.u32 + 44);
	// li r4,340
	ctx.r4.s64 = 340;
	// bl 0x825e02a0
	ctx.lr = 0x82524CA4;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82524d0c
	if (ctx.cr0.eq) goto loc_82524D0C;
	// clrlwi r9,r30,24
	ctx.r9.u64 = ctx.r30.u32 & 0xFF;
	// li r8,8
	ctx.r8.s64 = 8;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,6
	ctx.r6.s64 = 6;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825190e8
	ctx.lr = 0x82524CCC;
	sub_825190E8(ctx, base);
	// stfs f31,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// stfs f31,316(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stfs f31,320(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stfs f31,324(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// stw r27,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r27.u32);
	// std r25,296(r31)
	REX_STORE_U64(ctx.r31.u32 + 296, ctx.r25.u64);
	// stw r23,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r23.u32);
	// stw r30,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r30.u32);
	// stw r28,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r28.u32);
	// stw r29,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r29.u32);
	// stb r27,336(r31)
	REX_STORE_U8(ctx.r31.u32 + 336, ctx.r27.u8);
	// std r25,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r25.u64);
	// stb r22,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r22.u8);
	// b 0x82524d10
	goto loc_82524D10;
loc_82524D0C:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_82524D10:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82524d2c
	if (ctx.cr6.eq) goto loc_82524D2C;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stb r30,80(r11)
	REX_STORE_U8(ctx.r11.u32 + 80, ctx.r30.u8);
	// cmpw cr6,r29,r28
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r28.s32, ctx.xer);
	// blt cr6,0x82524c94
	if (ctx.cr6.lt) goto loc_82524C94;
	// b 0x82524d38
	goto loc_82524D38;
loc_82524D2C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82524d3c
	goto loc_82524D3C;
loc_82524D34:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_82524D38:
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82524D3C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8252BC00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8252BC08;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// addi r4,r10,-25908
	ctx.r4.s64 = ctx.r10.s64 + -25908;
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,11
	ctx.r7.s64 = 11;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x8252BC44;
	sub_825190E8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stb r27,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r27.u8);
	// addi r11,r11,-2248
	ctx.r11.s64 = ctx.r11.s64 + -2248;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x825a4640
	ctx.lr = 0x8252BC5C;
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
	ctx.lr = 0x8252BC78;
	sub_825A48B0(ctx, base);
	// lis r27,-32240
	ctx.r27.s64 = -2112880640;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r27,14280
	ctx.r10.s64 = ctx.r27.s64 + 14280;
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lfs f2,-30128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f2.f64 = double(temp.f32);
	// lfs f0,-1812(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1812);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// lfs f1,-23524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23524);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8252BCA4;
	sub_825A4A40(ctx, base);
	// extsw r11,r28
	ctx.r11.s64 = ctx.r28.s32;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,14280(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 14280);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmadds f0,f13,f0,f1
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f1.f64)));
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
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
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82534A40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82534A48;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// addi r11,r11,144
	ctx.r11.s64 = ctx.r11.s64 + 144;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r3,300
	ctx.r31.s64 = ctx.r3.s64 + 300;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r28,2
	ctx.r28.s64 = 2;
	// lwz r3,-12860(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -12860);
loc_82534A6C:
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82534a9c
	if (ctx.cr6.eq) goto loc_82534A9C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82534a8c
	if (ctx.cr6.eq) goto loc_82534A8C;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8246d2e8
	ctx.lr = 0x82534A88;
	sub_8246D2E8(ctx, base);
	// lwz r3,-12860(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -12860);
loc_82534A8C:
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,-8(r31)
	REX_STORE_U32(ctx.r31.u32 + -8, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_82534A9C:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x82534a6c
	if (!ctx.cr0.eq) goto loc_82534A6C;
	// lwz r3,332(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 332);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82534abc
	if (ctx.cr6.eq) goto loc_82534ABC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825765f0
	ctx.lr = 0x82534ABC;
	sub_825765F0(ctx, base);
loc_82534ABC:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x825a4750
	ctx.lr = 0x82534AC4;
	sub_825A4750(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r11,r11,-4968
	ctx.r11.s64 = ctx.r11.s64 + -4968;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x82534AD8;
	sub_82469EE8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82537480) {
	REX_FUNC_PROLOGUE();
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lbz r11,21(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 21);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,308(r3)
	REX_STORE_U32(ctx.r3.u32 + 308, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,68(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 68);
	// ld r11,2880(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 2880);
	// stb r10,116(r3)
	REX_STORE_U8(ctx.r3.u32 + 116, ctx.r10.u8);
	// stb r10,21(r3)
	REX_STORE_U8(ctx.r3.u32 + 21, ctx.r10.u8);
	// std r11,68(r3)
	REX_STORE_U64(ctx.r3.u32 + 68, ctx.r11.u64);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_8253A308) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,292(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8253A8B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8253A8B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825a4a90
	ctx.lr = 0x8253A8D0;
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
	ctx.lr = 0x8253A8E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r3,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r9,3
	ctx.r9.s64 = 3;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// divwu r9,r11,r9
	ctx.r9.u64 = uint32_t(ctx.r9.u32 ? ctx.r11.u32 / ctx.r9.u32 : 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// mulli r9,r9,3
	ctx.r9.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(3));
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f1,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x8224a2a0
	ctx.lr = 0x8253A920;
	sub_8224A2A0(ctx, base);
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r30,-32226
	ctx.r30.s64 = -2111963136;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r29,-32111
	ctx.r29.s64 = -2104426496;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f0,-8644(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10608(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -10608);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f13,f12,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// bctrl 
	ctx.lr = 0x8253A968;
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
	ctx.lr = 0x8253A984;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246c998
	ctx.lr = 0x8253A990;
	sub_8246C998(ctx, base);
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f0,-8644(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfs f13,-10608(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -10608);
	ctx.f13.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f13,f12,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// bctrl 
	ctx.lr = 0x8253A9D0;
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
	ctx.lr = 0x8253A9EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 296);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8253aa14
	if (ctx.cr0.eq) goto loc_8253AA14;
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
	ctx.lr = 0x8253AA14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8253AA14:
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
	ctx.lr = 0x8253AA30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,171
	ctx.r4.s64 = 171;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,108(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253AA4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f1,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
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
	ctx.lr = 0x8253AA68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82544158) {
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
	// addi r11,r11,3184
	ctx.r11.s64 = ctx.r11.s64 + 3184;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469fb0
	ctx.lr = 0x82544184;
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
	ctx.lr = 0x82544198;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825441a8
	if (ctx.cr0.eq) goto loc_825441A8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x825441A8;
	sub_825E0378(ctx, base);
loc_825441A8:
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

DEFINE_REX_FUNC(sub_82545A00) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,3484
	ctx.r30.s64 = ctx.r11.s64 + 3484;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x82545A2C;
	sub_8246A4B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82545a4c
	if (ctx.cr0.eq) goto loc_82545A4C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x82545A44;
	sub_8246A4B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82545a54
	if (!ctx.cr0.eq) goto loc_82545A54;
loc_82545A4C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_82545A54:
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

DEFINE_REX_FUNC(sub_8254A6C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8254A6C8;
	__savegprlr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8254A6E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8254a8d4
	if (ctx.cr0.eq) goto loc_8254A8D4;
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x8254a8d4
	if (!ctx.cr6.eq) goto loc_8254A8D4;
	// lbz r11,369(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 369);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8254a8d4
	if (ctx.cr0.eq) goto loc_8254A8D4;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// ld r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r29,r31,44
	ctx.r29.s64 = ctx.r31.s64 + 44;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,-13032(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8254a750
	if (ctx.cr6.eq) goto loc_8254A750;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
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
	ctx.lr = 0x8254A750;
	sub_823AEFA8(ctx, base);
loc_8254A750:
	// lbz r11,368(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 368);
	// clrlwi r28,r3,24
	ctx.r28.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8254a768
	if (ctx.cr0.eq) goto loc_8254A768;
	// lbz r11,370(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 370);
	// b 0x8254a8a0
	goto loc_8254A8A0;
loc_8254A768:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// ld r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// addi r4,r31,68
	ctx.r4.s64 = ctx.r31.s64 + 68;
	// addi r11,r11,-31664
	ctx.r11.s64 = ctx.r11.s64 + -31664;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8231e0d8
	ctx.lr = 0x8254A788;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// vmulfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vaddfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8254a89c
	if (ctx.cr6.eq) goto loc_8254A89C;
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x8254A89C;
	sub_823AEFA8(ctx, base);
loc_8254A89C:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
loc_8254A8A0:
	// clrlwi r10,r28,16
	ctx.r10.u64 = ctx.r28.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8254a8d4
	if (ctx.cr6.eq) goto loc_8254A8D4;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// li r7,-1
	ctx.r7.s64 = -1;
	// addi r8,r11,2880
	ctx.r8.s64 = ctx.r11.s64 + 2880;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82218a48
	ctx.lr = 0x8254A8CC;
	sub_82218A48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8254a900
	ctx.lr = 0x8254A8D4;
	sub_8254A900(ctx, base);
loc_8254A8D4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82558088) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82558090;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r5,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r5.u64);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r7,13
	ctx.r7.s64 = 13;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x825580C4;
	sub_825190E8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lis r6,-32225
	ctx.r6.s64 = -2111897600;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r6,6944
	ctx.r6.s64 = ctx.r6.s64 + 6944;
	// addi r30,r31,300
	ctx.r30.s64 = ctx.r31.s64 + 300;
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,300(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stfs f13,312(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// stfs f12,308(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// stw r28,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r28.u32);
	// stb r5,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r5.u8);
	// bne cr6,0x8255814c
	if (!ctx.cr6.eq) goto loc_8255814C;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// lfs f12,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f12.f64 = double(temp.f32);
	// b 0x82558150
	goto loc_82558150;
loc_8255814C:
	// lfs f12,12472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f12.f64 = double(temp.f32);
loc_82558150:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,212(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 212);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
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
	// li r29,0
	ctx.r29.s64 = 0;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r29,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r29.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f13,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r6,88(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// rlwinm r10,r6,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFF0;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
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
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x825582a8
	if (!ctx.cr6.eq) goto loc_825582A8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825582a8
	if (ctx.cr6.eq) goto loc_825582A8;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825582a8
	if (ctx.cr0.eq) goto loc_825582A8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x82558200;
	sub_82430A88(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r5,44(r31)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r5,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
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
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
loc_825582A8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r29,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r29.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8256E5C8) {
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
	// addi r11,r11,11104
	ctx.r11.s64 = ctx.r11.s64 + 11104;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469fb0
	ctx.lr = 0x8256E5EC;
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
	ctx.lr = 0x8256E600;
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

DEFINE_REX_FUNC(sub_825705B8) {
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
	// lwz r11,312(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 312);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r10,-9092
	ctx.r4.s64 = ctx.r10.s64 + -9092;
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x8246a2c0
	ctx.lr = 0x825705E0;
	sub_8246A2C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825705f4
	if (!ctx.cr0.eq) goto loc_825705F4;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x82570618
	goto loc_82570618;
loc_825705F4:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// lfs f2,6740(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6740);
	ctx.f2.f64 = double(temp.f32);
	// fneg f1,f2
	ctx.f1.u64 = ctx.f2.u64 ^ 0x8000000000000000;
	// bl 0x825a4a40
	ctx.lr = 0x82570614;
	sub_825A4A40(ctx, base);
	// stfs f1,316(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
loc_82570618:
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

DEFINE_REX_FUNC(sub_82572148) {
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r5,525
	ctx.r5.s64 = 525;
	// addi r4,r11,1340
	ctx.r4.s64 = ctx.r11.s64 + 1340;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x8257216C;
	sub_8246A4B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82572180
	if (!ctx.cr0.eq) goto loc_82572180;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x8257218c
	goto loc_8257218C;
loc_82572180:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
loc_8257218C:
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

DEFINE_REX_FUNC(sub_82573D28) {
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
	// bl 0x82573d80
	ctx.lr = 0x82573D48;
	sub_82573D80(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82573d60
	if (ctx.cr0.eq) goto loc_82573D60;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82573d60
	if (ctx.cr6.eq) goto loc_82573D60;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82573D60;
	sub_825E0378(ctx, base);
loc_82573D60:
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

DEFINE_REX_FUNC(sub_82575408) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// addi r11,r11,7240
	ctx.r11.s64 = ctx.r11.s64 + 7240;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r9,32
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 32, ctx.xer);
	// blt cr6,0x82575424
	if (ctx.cr6.lt) goto loc_82575424;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82575424:
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// mulli r7,r10,268
	ctx.r7.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(268));
	// addi r9,r6,-26976
	ctx.r9.s64 = ctx.r6.s64 + -26976;
	// clrlwi r10,r5,27
	ctx.r10.u64 = ctx.r5.u32 & 0x1F;
	// add r3,r7,r9
	ctx.r3.u64 = ctx.r7.u64 + ctx.r9.u64;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82576728) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82576730;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82576768
	if (ctx.cr6.eq) goto loc_82576768;
	// bl 0x825b2970
	ctx.lr = 0x82576740;
	sub_825B2970(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82576760
	if (ctx.cr6.eq) goto loc_82576760;
	// rlwinm. r11,r3,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82576760
	if (!ctx.cr0.eq) goto loc_82576760;
	// rlwinm. r11,r3,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82576760
	if (!ctx.cr0.eq) goto loc_82576760;
	// rlwinm. r11,r3,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825767e4
	if (ctx.cr0.eq) goto loc_825767E4;
loc_82576760:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x825767e8
	goto loc_825767E8;
loc_82576768:
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
	// lwz r11,-16160(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -16160);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825767e4
	if (ctx.cr6.eq) goto loc_825767E4;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// lis r29,-32111
	ctx.r29.s64 = -2104426496;
loc_82576784:
	// cmplwi cr6,r30,65535
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 65535, ctx.xer);
	// beq cr6,0x82576760
	if (ctx.cr6.eq) goto loc_82576760;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,2500(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2500);
	// bl 0x8263b630
	ctx.lr = 0x82576798;
	sub_8263B630(ctx, base);
	// lwz r11,-16172(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -16172);
	// mulli r10,r30,868
	ctx.r10.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(868));
	// lwz r3,2500(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2500);
	// lwzx r31,r10,r11
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// bl 0x8263b638
	ctx.lr = 0x825767AC;
	sub_8263B638(ctx, base);
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// beq cr6,0x82576760
	if (ctx.cr6.eq) goto loc_82576760;
	// rlwinm. r11,r31,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82576760
	if (!ctx.cr0.eq) goto loc_82576760;
	// rlwinm. r11,r31,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82576760
	if (!ctx.cr0.eq) goto loc_82576760;
	// rlwinm. r11,r31,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82576760
	if (!ctx.cr0.eq) goto loc_82576760;
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lwz r10,-16160(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + -16160);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82576784
	if (ctx.cr6.lt) goto loc_82576784;
loc_825767E4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825767E8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8257C8A8) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r9,4(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// lwz r30,-15432(r8)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r8.u32 + -15432);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x82577228
	ctx.lr = 0x8257C8F4;
	sub_82577228(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// std r30,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r30.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lwz r30,-15444(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -15444);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmsubs f31,f13,f30,f0
	ctx.f31.f64 = double(float(std::fma(ctx.f13.f64, ctx.f30.f64, -ctx.f0.f64)));
	// bl 0x82577290
	ctx.lr = 0x8257C92C;
	sub_82577290(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// std r30,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r30.u64);
	// lfd f12,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
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
	// fmsubs f12,f11,f30,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f11.f64, ctx.f30.f64, -ctx.f12.f64)));
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
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8257c9bc
	if (ctx.cr0.eq) goto loc_8257C9BC;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// b 0x8257ca10
	goto loc_8257CA10;
loc_8257C9BC:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
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
	// beq 0x8257ca20
	if (ctx.cr0.eq) goto loc_8257CA20;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
loc_8257CA10:
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
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
loc_8257CA20:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
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
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8257ca84
	if (ctx.cr0.eq) goto loc_8257CA84;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// b 0x8257cad8
	goto loc_8257CAD8;
loc_8257CA84:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
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
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8257cae8
	if (ctx.cr0.eq) goto loc_8257CAE8;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f12,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
loc_8257CAD8:
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
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
loc_8257CAE8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

DEFINE_REX_FUNC(sub_82594B28) {
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
	// bl 0x82594b80
	ctx.lr = 0x82594B48;
	sub_82594B80(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82594b60
	if (ctx.cr0.eq) goto loc_82594B60;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82594b60
	if (ctx.cr6.eq) goto loc_82594B60;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82594B60;
	sub_825E0378(ctx, base);
loc_82594B60:
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

DEFINE_REX_FUNC(sub_82597368) {
	REX_FUNC_PROLOGUE();
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lbz r11,41(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 41);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82597D10) {
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
	// bl 0x82597c68
	ctx.lr = 0x82597D2C;
	sub_82597C68(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r30,r11,15736
	ctx.r30.s64 = ctx.r11.s64 + 15736;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_82597D3C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82597d3c
	if (!ctx.cr6.eq) goto loc_82597D3C;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x8259a4e8
	ctx.lr = 0x82597D60;
	sub_8259A4E8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82597dc0
	if (ctx.cr6.eq) goto loc_82597DC0;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_82597D74:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82597d74
	if (!ctx.cr6.eq) goto loc_82597D74;
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,31016
	ctx.r11.s64 = ctx.r11.s64 + 31016;
	// rotlwi r5,r10,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_82597D9C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82597d9c
	if (!ctx.cr6.eq) goto loc_82597D9C;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r6,r11,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x8259a2c0
	ctx.lr = 0x82597DC0;
	sub_8259A2C0(ctx, base);
loc_82597DC0:
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

DEFINE_REX_FUNC(sub_8259C848) {
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
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,32(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x825e02a0
	ctx.lr = 0x8259C874;
	sub_825E02A0(ctx, base);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq 0x8259c884
	if (ctx.cr0.eq) goto loc_8259C884;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8259C884:
	// addic. r9,r11,4
	ctx.xer.ca = ctx.r11.u32 > 4294967291;
	ctx.r9.s64 = ctx.r11.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8259c890
	if (ctx.cr0.eq) goto loc_8259C890;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
loc_8259C890:
	// addic. r9,r11,8
	ctx.xer.ca = ctx.r11.u32 > 4294967287;
	ctx.r9.s64 = ctx.r11.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8259c89c
	if (ctx.cr0.eq) goto loc_8259C89C;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
loc_8259C89C:
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r10,29(r11)
	REX_STORE_U8(ctx.r11.u32 + 29, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r9,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r9.u8);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stb r9,29(r11)
	REX_STORE_U8(ctx.r11.u32 + 29, ctx.r9.u8);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r11.u32);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_825A0240) {
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
	// bl 0x825a0298
	ctx.lr = 0x825A0260;
	sub_825A0298(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825a0278
	if (ctx.cr0.eq) goto loc_825A0278;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825a0278
	if (ctx.cr6.eq) goto loc_825A0278;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x825A0278;
	sub_825E0378(ctx, base);
loc_825A0278:
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

DEFINE_REX_FUNC(sub_825A27E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x825A27E8;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x825a3358
	ctx.lr = 0x825A27F4;
	sub_825A3358(ctx, base);
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// lwz r11,-12788(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12788);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A2814;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-12788(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12788);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A2830;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r4,204(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 204);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// stw r27,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// stw r27,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r27.u32);
	// bl 0x825a3aa0
	ctx.lr = 0x825A284C;
	sub_825A3AA0(ctx, base);
	// lwz r10,200(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 200);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r30,104(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r26,100(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_825A2860:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x825a2900
	if (ctx.cr6.eq) goto loc_825A2900;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,172(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 172);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// bne cr6,0x825a288c
	if (!ctx.cr6.eq) goto loc_825A288C;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_825A288C:
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825a28ec
	if (ctx.cr6.eq) goto loc_825A28EC;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x825a28a8
	if (!ctx.cr6.eq) goto loc_825A28A8;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// b 0x825a28b4
	goto loc_825A28B4;
loc_825A28A8:
	// lwz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// subf r11,r26,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r26.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
loc_825A28B4:
	// subf r9,r26,r30
	ctx.r9.u64 = ctx.r30.u64 - ctx.r26.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x825a28d4
	if (!ctx.cr6.lt) goto loc_825A28D4;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// stw r30,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// b 0x825a28ec
	goto loc_825A28EC;
loc_825A28D4:
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8259acf8
	ctx.lr = 0x825A28E4;
	sub_8259ACF8(ctx, base);
	// lwz r30,104(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r26,100(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_825A28EC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82216520
	ctx.lr = 0x825A28F4;
	sub_82216520(ctx, base);
	// lwz r10,200(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 200);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x825a2860
	goto loc_825A2860;
loc_825A2900:
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// cmplw cr6,r26,r30
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x825a2938
	if (ctx.cr6.eq) goto loc_825A2938;
loc_825A290C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825a292c
	if (ctx.cr6.eq) goto loc_825A292C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A292C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825A292C:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x825a290c
	if (!ctx.cr6.eq) goto loc_825A290C;
loc_825A2938:
	// lwz r11,200(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 200);
	// addi r31,r28,196
	ctx.r31.s64 = ctx.r28.s64 + 196;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// lbz r11,21(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 21);
	// b 0x825a2978
	goto loc_825A2978;
loc_825A2950:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,8(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// bl 0x82360500
	ctx.lr = 0x825A295C;
	sub_82360500(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r29,0(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// beq cr6,0x825a2970
	if (ctx.cr6.eq) goto loc_825A2970;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825e0378
	ctx.lr = 0x825A2970;
	sub_825E0378(ctx, base);
loc_825A2970:
	// lbz r11,21(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 21);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_825A2978:
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825a2950
	if (ctx.cr0.eq) goto loc_825A2950;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
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
	// lwz r31,4(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// b 0x825a29c8
	goto loc_825A29C8;
loc_825A29A4:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825a29c4
	if (ctx.cr6.eq) goto loc_825A29C4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A29C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825A29C4:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_825A29C8:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825a29a4
	if (!ctx.cr6.eq) goto loc_825A29A4;
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x825a2a04
	if (ctx.cr6.eq) goto loc_825A2A04;
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
	// ble 0x825a2a00
	if (!ctx.cr0.gt) goto loc_825A2A00;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x825A2A00;
	sub_827388E8(ctx, base);
loc_825A2A00:
	// stw r31,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r31.u32);
loc_825A2A04:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x825a2a14
	if (ctx.cr6.eq) goto loc_825A2A14;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x825e0378
	ctx.lr = 0x825A2A14;
	sub_825E0378(ctx, base);
loc_825A2A14:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B2EE0) {
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
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x825b2f04
	if (!ctx.cr6.eq) goto loc_825B2F04;
loc_825B2EFC:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x825b2f74
	goto loc_825B2F74;
loc_825B2F04:
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// mulli r31,r3,268
	ctx.r31.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(268));
	// lwz r11,-16144(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -16144);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lwz r3,256(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 256);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825b2efc
	if (ctx.cr6.eq) goto loc_825B2EFC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825B2F30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x825b2efc
	if (!ctx.cr0.eq) goto loc_825B2EFC;
	// lwz r11,-16144(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -16144);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r31,r31,r11
	ctx.r31.u64 = ctx.r31.u64 + ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a590
	ctx.lr = 0x825B2F50;
	sub_8273A590(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r11.u32);
	// stw r11,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r11.u32);
	// lwz r10,-16152(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + -16152);
	// stw r11,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r11.u32);
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// stw r11,-16152(r9)
	REX_STORE_U32(ctx.r9.u32 + -16152, ctx.r11.u32);
loc_825B2F74:
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

DEFINE_REX_FUNC(sub_825B62B0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x825b6040
	sub_825B6040(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B6308) {
	REX_FUNC_PROLOGUE();
	// addi r11,r3,244
	ctx.r11.s64 = ctx.r3.s64 + 244;
	// stw r11,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// lwz r11,252(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 252);
	// stw r11,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// lwz r10,252(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 252);
	// stw r4,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// stw r4,252(r3)
	REX_STORE_U32(ctx.r3.u32 + 252, ctx.r4.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825B6A80) {
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
	// lwz r4,16(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,18368
	ctx.r10.s64 = ctx.r11.s64 + 18368;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// beq cr6,0x825b6ad0
	if (ctx.cr6.eq) goto loc_825B6AD0;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825B6AC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
loc_825B6AD0:
	// lwz r3,116(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// lis r11,8324
	ctx.r11.s64 = 545521664;
	// ori r30,r11,1
	ctx.r30.u64 = ctx.r11.u64 | 1;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825b6aec
	if (ctx.cr6.eq) goto loc_825B6AEC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8263b710
	ctx.lr = 0x825B6AEC;
	sub_8263B710(ctx, base);
loc_825B6AEC:
	// lwz r3,132(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825b6b00
	if (ctx.cr6.eq) goto loc_825B6B00;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8263b710
	ctx.lr = 0x825B6B00;
	sub_8263B710(ctx, base);
loc_825B6B00:
	// lwz r3,124(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825b6b14
	if (ctx.cr6.eq) goto loc_825B6B14;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8263b710
	ctx.lr = 0x825B6B14;
	sub_8263B710(ctx, base);
loc_825B6B14:
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825b6b28
	if (ctx.cr6.eq) goto loc_825B6B28;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8263b710
	ctx.lr = 0x825B6B28;
	sub_8263B710(ctx, base);
loc_825B6B28:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825b6b6c
	if (ctx.cr6.eq) goto loc_825B6B6C;
	// lwz r10,-4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// addi r3,r11,-4
	ctx.r3.s64 = ctx.r11.s64 + -4;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825b6b60
	if (ctx.cr6.eq) goto loc_825B6B60;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825B6B5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825b6b6c
	goto loc_825B6B6C;
loc_825B6B60:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825b6b6c
	if (ctx.cr6.eq) goto loc_825B6B6C;
	// bl 0x825e0378
	ctx.lr = 0x825B6B6C;
	sub_825E0378(ctx, base);
loc_825B6B6C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r11,18140
	ctx.r10.s64 = ctx.r11.s64 + 18140;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_825BCC50) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r7,r11,18888
	ctx.r7.s64 = ctx.r11.s64 + 18888;
	// addi r6,r10,18980
	ctx.r6.s64 = ctx.r10.s64 + 18980;
	// addi r5,r9,18988
	ctx.r5.s64 = ctx.r9.s64 + 18988;
	// stw r7,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// addi r4,r8,18992
	ctx.r4.s64 = ctx.r8.s64 + 18992;
	// stw r6,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// addi r31,r3,12
	ctx.r31.s64 = ctx.r3.s64 + 12;
	// stw r5,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r4,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// lwz r3,16(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmplw cr6,r3,r31
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x825bccd4
	if (ctx.cr6.eq) goto loc_825BCCD4;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x825bccd4
	if (ctx.cr6.eq) goto loc_825BCCD4;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r31,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r31.u32);
	// stw r31,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r31.u32);
loc_825BCCD4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825bcd50
	ctx.lr = 0x825BCCDC;
	sub_825BCD50(ctx, base);
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// bl 0x8273a590
	ctx.lr = 0x825BCCEC;
	sub_8273A590(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// lbz r9,108(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 108);
	// rldicr r8,r10,8,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// stw r30,89(r1)
	REX_STORE_U32(ctx.r1.u32 + 89, ctx.r30.u32);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// lwz r3,24(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// ld r6,96(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// rldicr r7,r7,24,39
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 24) & 0xFFFFFFFFFF000000;
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x825b5a38
	ctx.lr = 0x825BCD20;
	sub_825B5A38(ctx, base);
	// addi r3,r30,28
	ctx.r3.s64 = ctx.r30.s64 + 28;
	// bl 0x825b9750
	ctx.lr = 0x825BCD28;
	sub_825B9750(ctx, base);
	// lis r6,-32225
	ctx.r6.s64 = -2111897600;
	// addi r5,r6,18140
	ctx.r5.s64 = ctx.r6.s64 + 18140;
	// stw r5,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
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

DEFINE_REX_FUNC(sub_825C34B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x825C34C0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r27,r11,204
	ctx.r27.s64 = ctx.r11.s64 + 204;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x82855b44
	ctx.lr = 0x825C34E4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825c3514
	if (ctx.cr6.eq) goto loc_825C3514;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C3510;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_825C3514:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82855b34
	ctx.lr = 0x825C351C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C6990) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x825C6998;
	__savegprlr_26(ctx, base);
	// stwu r1,-1168(r1)
	ea = -1168 + ctx.r1.u32;
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
	ctx.lr = 0x825C69B0;
	sub_825B32D0(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r26,48(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8273a590
	ctx.lr = 0x825C69C8;
	sub_8273A590(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// addi r6,r31,64
	ctx.r6.s64 = ctx.r31.s64 + 64;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x825c6a54
	if (ctx.cr6.eq) goto loc_825C6A54;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r7,r10,-4
	ctx.r7.s64 = ctx.r10.s64 + -4;
loc_825C69E4:
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// cmplw cr6,r9,r26
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x825c6a48
	if (!ctx.cr6.eq) goto loc_825C6A48;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r10,9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 9, ctx.xer);
	// beq cr6,0x825c6a10
	if (ctx.cr6.eq) goto loc_825C6A10;
	// cmpwi cr6,r10,18
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 18, ctx.xer);
	// bne cr6,0x825c6a48
	if (!ctx.cr6.eq) goto loc_825C6A48;
loc_825C6A10:
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpw cr6,r10,r27
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r27.s32, ctx.xer);
	// ble cr6,0x825c6a48
	if (!ctx.cr6.gt) goto loc_825C6A48;
	// lwz r10,7(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 7);
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x825c6a48
	if (ctx.cr6.lt) goto loc_825C6A48;
	// cmplw cr6,r10,r28
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r28.u32, ctx.xer);
	// bgt cr6,0x825c6a48
	if (ctx.cr6.gt) goto loc_825C6A48;
	// stwu r11,4(r7)
	ea = 4 + ctx.r7.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r7.u32 = ea;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x825c6a54
	if (!ctx.cr6.eq) goto loc_825C6A54;
	// cmpwi cr6,r8,256
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 256, ctx.xer);
	// beq cr6,0x825c6a54
	if (ctx.cr6.eq) goto loc_825C6A54;
loc_825C6A48:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x825c69e4
	if (!ctx.cr6.eq) goto loc_825C69E4;
loc_825C6A54:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x825c6a98
	if (!ctx.cr6.gt) goto loc_825C6A98;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x825c6a7c
	if (ctx.cr6.eq) goto loc_825C6A7C;
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
loc_825C6A7C:
	// addi r5,r8,-1
	ctx.r5.s64 = ctx.r8.s64 + -1;
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825b55e0
	ctx.lr = 0x825C6A8C;
	sub_825B55E0(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
loc_825C6A98:
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825CF708) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// addi r9,r10,21744
	ctx.r9.s64 = ctx.r10.s64 + 21744;
	// stw r4,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// stw r6,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stw r7,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r7.u32);
	// stw r5,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r11,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stb r11,40(r3)
	REX_STORE_U8(ctx.r3.u32 + 40, ctx.r11.u8);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// sth r11,48(r3)
	REX_STORE_U16(ctx.r3.u32 + 48, ctx.r11.u16);
	// stw r8,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r8.u32);
	// beq cr6,0x825cf75c
	if (ctx.cr6.eq) goto loc_825CF75C;
	// lhz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r8.u32 + 0);
	// b 0x825cf760
	goto loc_825CF760;
loc_825CF75C:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_825CF760:
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// addi r7,r9,21240
	ctx.r7.s64 = ctx.r9.s64 + 21240;
	// addi r10,r6,8
	ctx.r10.s64 = ctx.r6.s64 + 8;
	// sth r8,56(r3)
	REX_STORE_U16(ctx.r3.u32 + 56, ctx.r8.u16);
	// stw r7,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r10,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// lwz r5,8(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// stw r5,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r5.u32);
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,68(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// lwz r4,12(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// stw r4,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r4.u32);
	// lfs f13,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,72(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// lhz r10,20(r6)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r6.u32 + 20);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r11,80(r3)
	REX_STORE_U64(ctx.r3.u32 + 80, ctx.r11.u64);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stfs f10,76(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825DA098) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-1120(r1)
	ea = -1120 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,1140(r1)
	REX_STORE_U32(ctx.r1.u32 + 1140, ctx.r3.u32);
	// stw r4,1148(r1)
	REX_STORE_U32(ctx.r1.u32 + 1148, ctx.r4.u32);
	// stw r5,1156(r1)
	REX_STORE_U32(ctx.r1.u32 + 1156, ctx.r5.u32);
	// stw r6,1164(r1)
	REX_STORE_U32(ctx.r1.u32 + 1164, ctx.r6.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,1164(r1)
	REX_STORE_U32(ctx.r1.u32 + 1164, ctx.r11.u32);
	// lwz r11,1164(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 1164);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825da0ec
	if (ctx.cr6.eq) goto loc_825DA0EC;
	// lwz r8,1140(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 1140);
	// lwz r7,1164(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 1164);
	// lwz r6,1156(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 1156);
	// lwz r5,1148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 1148);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r4,r11,22508
	ctx.r4.s64 = ctx.r11.s64 + 22508;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82738a28
	ctx.lr = 0x825DA0E8;
	sub_82738A28(ctx, base);
	// b 0x825da108
	goto loc_825DA108;
loc_825DA0EC:
	// lwz r7,1140(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 1140);
	// lwz r6,1156(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 1156);
	// lwz r5,1148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 1148);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r4,r11,22544
	ctx.r4.s64 = ctx.r11.s64 + 22544;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82738a28
	ctx.lr = 0x825DA108;
	sub_82738A28(ctx, base);
loc_825DA108:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,22576
	ctx.r3.s64 = ctx.r11.s64 + 22576;
	// bl 0x8273b638
	ctx.lr = 0x825DA118;
	sub_8273B638(ctx, base);
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
	// addi r1,r1,1120
	ctx.r1.s64 = ctx.r1.s64 + 1120;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825DFBF8) {
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
	// li r30,1
	ctx.r30.s64 = 1;
	// addi r31,r11,-15596
	ctx.r31.s64 = ctx.r11.s64 + -15596;
	// addi r7,r31,-488
	ctx.r7.s64 = ctx.r31.s64 + -488;
loc_825DFC1C:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r7
	ea = ctx.r7.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r30,r10
	ctx.r9.u64 = ctx.r30.u64 + ctx.r10.u64;
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
	// bne 0x825dfc1c
	if (!ctx.cr0.eq) goto loc_825DFC1C;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825dfca4
	if (!ctx.cr6.eq) goto loc_825DFCA4;
	// addi r11,r31,-4
	ctx.r11.s64 = ctx.r31.s64 + -4;
loc_825DFC48:
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
	// add r9,r30,r10
	ctx.r9.u64 = ctx.r30.u64 + ctx.r10.u64;
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
	// bne 0x825dfc48
	if (!ctx.cr0.eq) goto loc_825DFC48;
	// bl 0x822104c0
	ctx.lr = 0x825DFC68;
	sub_822104C0(ctx, base);
	// addi r11,r31,-8
	ctx.r11.s64 = ctx.r31.s64 + -8;
loc_825DFC6C:
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
	// add r9,r30,r10
	ctx.r9.u64 = ctx.r30.u64 + ctx.r10.u64;
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
	// bne 0x825dfc6c
	if (!ctx.cr0.eq) goto loc_825DFC6C;
loc_825DFC88:
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
	// add r10,r30,r11
	ctx.r10.u64 = ctx.r30.u64 + ctx.r11.u64;
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
	// bne 0x825dfc88
	if (!ctx.cr0.eq) goto loc_825DFC88;
loc_825DFCA4:
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

DEFINE_REX_FUNC(sub_825E6630) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r8,r3,32
	ctx.r8.s64 = ctx.r3.s64 + 32;
loc_825E6638:
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
	// bne 0x825e6638
	if (!ctx.cr0.eq) goto loc_825E6638;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825E7268) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r8,r3,72
	ctx.r8.s64 = ctx.r3.s64 + 72;
loc_825E7270:
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
	// bne 0x825e7270
	if (!ctx.cr0.eq) goto loc_825E7270;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825E87A8) {
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
	// addi r3,r3,104
	ctx.r3.s64 = ctx.r3.s64 + 104;
	// addi r11,r11,23396
	ctx.r11.s64 = ctx.r11.s64 + 23396;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// bl 0x825e6b90
	ctx.lr = 0x825E87D8;
	sub_825E6B90(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,23184
	ctx.r11.s64 = ctx.r11.s64 + 23184;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// bl 0x825e5a00
	ctx.lr = 0x825E87EC;
	sub_825E5A00(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825e8804
	if (ctx.cr0.eq) goto loc_825E8804;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825e8804
	if (ctx.cr6.eq) goto loc_825E8804;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x825E8804;
	sub_825E0378(ctx, base);
loc_825E8804:
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

DEFINE_REX_FUNC(sub_825EA950) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825EA958;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,148(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8273c660
	ctx.lr = 0x825EA96C;
	sub_8273C660(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x825ea980
	if (!ctx.cr6.eq) goto loc_825EA980;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,148(r29)
	REX_STORE_U32(ctx.r29.u32 + 148, ctx.r11.u32);
	// b 0x825ea9c4
	goto loc_825EA9C4;
loc_825EA980:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_825EA984:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825ea984
	if (!ctx.cr6.eq) goto loc_825EA984;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273c6c0
	ctx.lr = 0x825EA9AC;
	sub_8273C6C0(ctx, base);
	// stw r3,148(r29)
	REX_STORE_U32(ctx.r29.u32 + 148, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825ea9c4
	if (ctx.cr0.eq) goto loc_825EA9C4;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8263a4c0
	ctx.lr = 0x825EA9C4;
	sub_8263A4C0(ctx, base);
loc_825EA9C4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825ED598) {
	REX_FUNC_PROLOGUE();
	// lwz r10,552(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 552);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// bne cr6,0x825ed5b0
	if (!ctx.cr6.eq) goto loc_825ED5B0;
	// lwz r3,556(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 556);
	// b 0x825ed604
	goto loc_825ED604;
loc_825ED5B0:
	// lwz r10,520(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 520);
	// stw r11,552(r3)
	REX_STORE_U32(ctx.r3.u32 + 552, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x825ed5e4
	if (!ctx.cr6.lt) goto loc_825ED5E4;
	// lwz r10,516(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 516);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825ed5d8
	if (ctx.cr6.eq) goto loc_825ED5D8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_825ED5D0:
	// lwz r10,116(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 116);
	// bdnz 0x825ed5d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825ED5D0;
loc_825ED5D8:
	// stw r10,556(r3)
	REX_STORE_U32(ctx.r3.u32 + 556, ctx.r10.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// b 0x825ed604
	goto loc_825ED604;
loc_825ED5E4:
	// subf. r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r11,532(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 532);
	// beq 0x825ed5fc
	if (ctx.cr0.eq) goto loc_825ED5FC;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_825ED5F4:
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// bdnz 0x825ed5f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825ED5F4;
loc_825ED5FC:
	// stw r11,556(r3)
	REX_STORE_U32(ctx.r3.u32 + 556, ctx.r11.u32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_825ED604:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_825F2568) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825F2570;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r29,r11,-15580
	ctx.r29.s64 = ctx.r11.s64 + -15580;
	// lwz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f2594
	if (ctx.cr6.eq) goto loc_825F2594;
	// lis r3,-16381
	ctx.r3.s64 = -1073545216;
	// ori r3,r3,2
	ctx.r3.u64 = ctx.r3.u64 | 2;
	// b 0x825f269c
	goto loc_825F269C;
loc_825F2594:
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r31,r9,-31200
	ctx.r31.s64 = ctx.r9.s64 + -31200;
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r10,r11,24844
	ctx.r10.s64 = ctx.r11.s64 + 24844;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// addi r5,r29,-20
	ctx.r5.s64 = ctx.r29.s64 + -20;
	// stw r10,-31200(r9)
	REX_STORE_U32(ctx.r9.u32 + -31200, ctx.r10.u32);
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
loc_825F25B8:
	// mfmsr r6
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r6.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r8,0,r5
	ea = ctx.r5.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r8.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r7,r28,r8
	ctx.r7.u64 = ctx.r28.u64 + ctx.r8.u64;
	// stwcx. r7,0,r5
	ea = ctx.r5.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r7.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825f25b8
	if (!ctx.cr0.eq) goto loc_825F25B8;
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// bl 0x82856014
	ctx.lr = 0x825F25E0;
	__imp__RtlInitializeCriticalSectionAndSpinCount(ctx, base);
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r28,68(r31)
	REX_STORE_U8(ctx.r31.u32 + 68, ctx.r28.u8);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// stw r31,28(r29)
	REX_STORE_U32(ctx.r29.u32 + 28, ctx.r31.u32);
	// addi r30,r9,-31216
	ctx.r30.s64 = ctx.r9.s64 + -31216;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// addi r9,r10,24856
	ctx.r9.s64 = ctx.r10.s64 + 24856;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// stw r31,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r31.u32);
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
loc_825F2628:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r8,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r8.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stwcx. r8,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r8.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825f2628
	if (!ctx.cr0.eq) goto loc_825F2628;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
loc_825F2648:
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
	// bne 0x825f2648
	if (!ctx.cr0.eq) goto loc_825F2648;
	// mr r11,r11
	ctx.r11.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825f2694
	if (!ctx.cr6.eq) goto loc_825F2694;
	// addi r11,r29,-20
	ctx.r11.s64 = ctx.r29.s64 + -20;
loc_825F2674:
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
	// bne 0x825f2674
	if (!ctx.cr0.eq) goto loc_825F2674;
	// bl 0x825f2568
	ctx.lr = 0x825F2694;
	sub_825F2568(ctx, base);
loc_825F2694:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,32(r29)
	REX_STORE_U32(ctx.r29.u32 + 32, ctx.r30.u32);
loc_825F269C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FAF98) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825FAFA0;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
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
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// beq cr6,0x825fb04c
	if (ctx.cr6.eq) goto loc_825FB04C;
	// lis r11,4095
	ctx.r11.s64 = 268369920;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x825fb028
	if (!ctx.cr6.gt) goto loc_825FB028;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,56
	ctx.r4.s64 = ctx.r11.s64 + 56;
	// bl 0x822167f8
	ctx.lr = 0x825FAFF0;
	sub_822167F8(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82216678
	ctx.lr = 0x825FAFFC;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x825FB000;
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
	ctx.lr = 0x825FB014;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235ec48
	ctx.lr = 0x825FB024;
	sub_8235EC48(ctx, base);
	// b 0x825fb048
	goto loc_825FB048;
loc_825FB028:
	// rlwinm r29,r30,4,0,27
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 4) & 0xFFFFFFF0;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825f8d38
	ctx.lr = 0x825FB038;
	sub_825F8D38(ctx, base);
	// add r11,r29,r3
	ctx.r11.u64 = ctx.r29.u64 + ctx.r3.u64;
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_825FB048:
	// li r11,1
	ctx.r11.s64 = 1;
loc_825FB04C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825fb0ac
	if (ctx.cr0.eq) goto loc_825FB0AC;
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// beq cr6,0x825fb0a0
	if (ctx.cr6.eq) goto loc_825FB0A0;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_825FB068:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825fb094
	if (ctx.cr6.eq) goto loc_825FB094;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r6,4(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r5,8(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r8,12(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// stw r5,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
loc_825FB094:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bne 0x825fb068
	if (!ctx.cr0.eq) goto loc_825FB068;
loc_825FB0A0:
	// rlwinm r11,r30,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_825FB0AC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82604F30) {
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
	// stw r4,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// li r31,0
	ctx.r31.s64 = 0;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r31,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r31.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stw r31,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r31.u32);
	// stw r31,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// stw r31,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// stw r31,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
	// bl 0x825f8d38
	ctx.lr = 0x82604F74;
	sub_825F8D38(ctx, base);
	// li r11,100
	ctx.r11.s64 = 100;
	// stw r3,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r3.u32);
	// stw r3,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stw r31,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
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

DEFINE_REX_FUNC(sub_8260AAC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8260AAC8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r29,r11,-15072
	ctx.r29.s64 = ctx.r11.s64 + -15072;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x8260AAE0;
	sub_825F8ED0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8260ab0c
	if (ctx.cr6.eq) goto loc_8260AB0C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// clrlwi r10,r30,17
	ctx.r10.u64 = ctx.r30.u32 & 0x7FFF;
	// mulli r10,r10,72
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(72));
	// lwz r11,-15076(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15076);
	// lwzx r8,r10,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r8,r30
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8260ab34
	if (ctx.cr6.eq) goto loc_8260AB34;
loc_8260AB0C:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8260AB10:
	// lwsync 
loc_8260AB14:
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
	// stwcx. r9,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8260ab14
	if (!ctx.cr0.eq) goto loc_8260AB14;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
loc_8260AB34:
	// addi r3,r31,68
	ctx.r3.s64 = ctx.r31.s64 + 68;
	// bl 0x825f8fb0
	ctx.lr = 0x8260AB3C;
	sub_825F8FB0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8260ab10
	if (!ctx.cr0.eq) goto loc_8260AB10;
	// lwz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lwz r7,20(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r31,20
	ctx.r11.s64 = ctx.r31.s64 + 20;
	// addi r8,r8,-15064
	ctx.r8.s64 = ctx.r8.s64 + -15064;
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r7,24(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stw r7,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// stw r9,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
	// stw r9,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r10,r10,0,17,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFF0007FFF;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r8,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r8.u32);
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
	// b 0x8260ab10
	goto loc_8260AB10;
}

DEFINE_REX_FUNC(sub_8260FE98) {
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
	// beq cr6,0x8260ff98
	if (ctx.cr6.eq) goto loc_8260FF98;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwinm r10,r3,6,11,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x1FFFC0;
	// lwz r11,-14884(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -14884);
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x8260ff98
	if (!ctx.cr6.eq) goto loc_8260FF98;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8260ff3c
	if (!ctx.cr6.eq) goto loc_8260FF3C;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm. r8,r11,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8260ff1c
	if (ctx.cr0.eq) goto loc_8260FF1C;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,52(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8260ff1c
	if (ctx.cr6.eq) goto loc_8260FF1C;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r11,r11,25,7,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1FFFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8260FF10:
	// dcbf r10,r9
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// bdnz 0x8260ff10
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8260FF10;
loc_8260FF1C:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8260ff3c
	if (!ctx.cr6.eq) goto loc_8260FF3C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r5,56(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,52(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r3,-11620(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -11620);
	// bl 0x82623f58
	ctx.lr = 0x8260FF3C;
	sub_82623F58(ctx, base);
loc_8260FF3C:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8260ff6c
	if (!ctx.cr6.eq) goto loc_8260FF6C;
	// lwsync 
	// addi r9,r31,32
	ctx.r9.s64 = ctx.r31.s64 + 32;
loc_8260FF50:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// ldarx r10,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u64 = *(uint64_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap64(ctx.reserved.u64);
	// stdcx. r11,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s64, __builtin_bswap64(ctx.r11.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8260ff50
	if (!ctx.cr0.eq) goto loc_8260FF50;
	// b 0x8260ff90
	goto loc_8260FF90;
loc_8260FF6C:
	// addi r11,r31,32
	ctx.r11.s64 = ctx.r31.s64 + 32;
loc_8260FF70:
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
	// bne 0x8260ff70
	if (!ctx.cr0.eq) goto loc_8260FF70;
	// lwsync 
loc_8260FF90:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8260fc08
	ctx.lr = 0x8260FF98;
	sub_8260FC08(ctx, base);
loc_8260FF98:
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

DEFINE_REX_FUNC(sub_82617948) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82617950;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
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
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82617978;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f0,60(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bne cr6,0x826179f0
	if (!ctx.cr6.eq) goto loc_826179F0;
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,76(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bge cr6,0x82617a40
	if (!ctx.cr6.lt) goto loc_82617A40;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,76(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// bl 0x826176d0
	ctx.lr = 0x826179CC;
	sub_826176D0(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// stfs f0,4(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// b 0x82617a40
	goto loc_82617A40;
loc_826179F0:
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x82617a08
	if (ctx.cr6.lt) goto loc_82617A08;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// ble cr6,0x82617a0c
	if (!ctx.cr6.gt) goto loc_82617A0C;
loc_82617A08:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82617A0C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82617a40
	if (ctx.cr0.eq) goto loc_82617A40;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f0,80(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,76(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x82617a38
	if (ctx.cr6.lt) goto loc_82617A38;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_82617A38:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
loc_82617A40:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f0,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82617a94
	if (ctx.cr6.eq) goto loc_82617A94;
	// ble cr6,0x82617a9c
	if (!ctx.cr6.gt) goto loc_82617A9C;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x82617a9c
	if (ctx.cr6.gt) goto loc_82617A9C;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82617a8c
	if (ctx.cr6.eq) goto loc_82617A8C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82617a9c
	if (!ctx.cr6.eq) goto loc_82617A9C;
	// b 0x82617a98
	goto loc_82617A98;
loc_82617A8C:
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x82617a9c
	goto loc_82617A9C;
loc_82617A94:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82617A98:
	// li r9,1
	ctx.r9.s64 = 1;
loc_82617A9C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r28,r11,14376
	ctx.r28.s64 = ctx.r11.s64 + 14376;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r11,r11,-29748
	ctx.r11.s64 = ctx.r11.s64 + -29748;
	// lfs f12,-1908(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1908);
	ctx.f12.f64 = double(temp.f32);
	// beq 0x82617aec
	if (ctx.cr0.eq) goto loc_82617AEC;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f0,8(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,120(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 120);
	// lfs f11,76(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 76);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f10,r10,r11
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// fnmsubs f13,f10,f13,f0
	ctx.f13.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f13.f64, -ctx.f0.f64)));
	// fsubs f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x82617aec
	if (!ctx.cr6.gt) goto loc_82617AEC;
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
loc_82617AEC:
	// clrlwi. r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82617b30
	if (ctx.cr0.eq) goto loc_82617B30;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f13,-2140(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -2140);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lwz r9,120(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 120);
	// lfs f10,80(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f9,r10,r11
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// fmadds f13,f13,f11,f0
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f11.f64, ctx.f0.f64)));
	// fsubs f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x82617b30
	if (!ctx.cr6.lt) goto loc_82617B30;
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
loc_82617B30:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lbz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 44);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82617b48
	if (!ctx.cr0.eq) goto loc_82617B48;
loc_82617B40:
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x82617b7c
	goto loc_82617B7C;
loc_82617B48:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82617B5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82615e10
	ctx.lr = 0x82617B60;
	sub_82615E10(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82617b40
	if (ctx.cr0.eq) goto loc_82617B40;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82617B78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsb r29,r3
	ctx.r29.s64 = ctx.r3.s8;
loc_82617B7C:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82617B90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82617BA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsb r10,r3
	ctx.r10.s64 = ctx.r3.s8;
	// extsb r11,r26
	ctx.r11.s64 = ctx.r26.s8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x82617618
	ctx.lr = 0x82617BC0;
	sub_82617618(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lwz r11,36(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// frsp f31,f0
	ctx.f31.f64 = double(float(ctx.f0.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82617BE8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r3.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f0,52(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 52);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,12(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 12, temp.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82617cbc
	if (ctx.cr6.eq) goto loc_82617CBC;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82617c74
	if (ctx.cr6.eq) goto loc_82617C74;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82617d0c
	if (!ctx.cr6.eq) goto loc_82617D0C;
	// extsw r11,r29
	ctx.r11.s64 = ctx.r29.s32;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// clrldi r11,r9,32
	ctx.r11.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,64(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// lwa r9,72(r10)
	ctx.r9.s64 = int32_t(REX_LOAD_U32(ctx.r10.u32 + 72));
	// lfd f10,88(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fadds f11,f11,f31
	ctx.f11.f64 = double(float(ctx.f11.f64 + ctx.f31.f64));
	// fmadds f12,f11,f12,f10
	ctx.f12.f64 = double(float(std::fma(ctx.f11.f64, ctx.f12.f64, ctx.f10.f64)));
	// fnmsubs f0,f12,f13,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f13.f64, -ctx.f0.f64)));
	// b 0x82617d08
	goto loc_82617D08;
loc_82617C74:
	// addi r10,r3,-1
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lwa r10,72(r11)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r11.u32 + 72));
	// lfs f12,64(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fadds f11,f11,f31
	ctx.f11.f64 = double(float(ctx.f11.f64 + ctx.f31.f64));
	// fmadds f13,f11,f13,f31
	ctx.f13.f64 = double(float(std::fma(ctx.f11.f64, ctx.f13.f64, ctx.f31.f64)));
	// fnmsubs f0,f13,f12,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f12.f64, -ctx.f0.f64)));
	// b 0x82617d08
	goto loc_82617D08;
loc_82617CBC:
	// addi r10,r3,-1
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f13,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lwa r10,72(r11)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r11.u32 + 72));
	// lfs f11,64(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f11.f64 = double(temp.f32);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f10,88(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fadds f10,f10,f31
	ctx.f10.f64 = double(float(ctx.f10.f64 + ctx.f31.f64));
	// fmadds f12,f10,f12,f31
	ctx.f12.f64 = double(float(std::fma(ctx.f10.f64, ctx.f12.f64, ctx.f31.f64)));
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fnmsubs f0,f12,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
loc_82617D08:
	// stfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 12, temp.u32);
loc_82617D0C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82639D60) {
	REX_FUNC_PROLOGUE();
	// b 0x828557b4
	__imp__XamContentDelete(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82639D88) {
	REX_FUNC_PROLOGUE();
	// b 0x82855804
	__imp__XamContentGetDeviceState(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82639E80) {
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
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// bne cr6,0x82639eec
	if (!ctx.cr6.eq) goto loc_82639EEC;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x82639ec8
	if (ctx.cr6.eq) goto loc_82639EC8;
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82639ec8
	if (ctx.cr6.eq) goto loc_82639EC8;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x8263b630
	ctx.lr = 0x82639EC4;
	sub_8263B630(ctx, base);
	// b 0x82639ecc
	goto loc_82639ECC;
loc_82639EC8:
	// li r3,258
	ctx.r3.s64 = 258;
loc_82639ECC:
	// cmplwi cr6,r3,258
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 258, ctx.xer);
	// bne cr6,0x82639edc
	if (!ctx.cr6.eq) goto loc_82639EDC;
	// li r3,996
	ctx.r3.s64 = 996;
	// b 0x82639f00
	goto loc_82639F00;
loc_82639EDC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82639eec
	if (ctx.cr6.eq) goto loc_82639EEC;
	// bl 0x82639f50
	ctx.lr = 0x82639EE8;
	sub_82639F50(ctx, base);
	// b 0x82639f00
	goto loc_82639F00;
loc_82639EEC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82639efc
	if (ctx.cr6.eq) goto loc_82639EFC;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_82639EFC:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_82639F00:
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

DEFINE_REX_FUNC(sub_8263BCE8) {
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
	// li r31,1627
	ctx.r31.s64 = 1627;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8263bd14
	if (!ctx.cr6.eq) goto loc_8263BD14;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8263bd40
	goto loc_8263BD40;
loc_8263BD14:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x828558f4
	ctx.lr = 0x8263BD1C;
	__imp__XamGetExecutionId(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8263bd40
	if (ctx.cr0.lt) goto loc_8263BD40;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r30,16,16,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 16) & 0xFFFF;
	// lhz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 & ctx.r31.u64;
loc_8263BD40:
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

DEFINE_REX_FUNC(sub_826417D8) {
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
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82641800;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82641838
	if (ctx.cr0.lt) goto loc_82641838;
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264181C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82641838
	if (ctx.cr0.lt) goto loc_82641838;
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// addi r3,r31,116
	ctx.r3.s64 = ctx.r31.s64 + 116;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82641838;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82641838:
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

DEFINE_REX_FUNC(sub_82643350) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82643358;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8264337c
	if (!ctx.cr6.eq) goto loc_8264337C;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// bl 0x82644e00
	ctx.lr = 0x82643378;
	sub_82644E00(ctx, base);
	// b 0x826433c0
	goto loc_826433C0;
loc_8264337C:
	// bl 0x82644c80
	ctx.lr = 0x82643380;
	sub_82644C80(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x826433c0
	if (ctx.cr0.eq) goto loc_826433C0;
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// stw r31,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826433ac
	if (ctx.cr6.eq) goto loc_826433AC;
	// stw r3,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// b 0x826433b0
	goto loc_826433B0;
loc_826433AC:
	// stw r3,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r3.u32);
loc_826433B0:
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r11.u32);
loc_826433C0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826456B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mulli r11,r3,96
	ctx.r11.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(96));
	// addi r11,r11,143
	ctx.r11.s64 = ctx.r11.s64 + 143;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r8,r11,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826456f4
	if (ctx.cr6.eq) goto loc_826456F4;
	// addi r11,r4,-8
	ctx.r11.s64 = ctx.r4.s64 + -8;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
loc_826456D8:
	// lbz r7,16(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
	// lwzu r9,12(r11)
	ea = 12 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// mullw r9,r9,r7
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bdnz 0x826456d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826456D8;
loc_826456F4:
	// add r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 + ctx.r8.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82647C40) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x826537d8
	sub_826537D8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82647DB8) {
	REX_FUNC_PROLOGUE();
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
}

DEFINE_REX_FUNC(sub_82647EF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82647EF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82647F1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// addi r30,r31,352
	ctx.r30.s64 = ctx.r31.s64 + 352;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82647F34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82647f5c
	if (ctx.cr6.eq) goto loc_82647F5C;
	// lwz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 412);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82647f54
	if (ctx.cr6.eq) goto loc_82647F54;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82647f58
	goto loc_82647F58;
loc_82647F54:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82647F58:
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
loc_82647F5C:
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82647F74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// lwz r10,64(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// ld r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 232);
	// divdu r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 ? ctx.r11.u64 / ctx.r10.u64 : 0;
	// std r11,8(r29)
	REX_STORE_U64(ctx.r29.u32 + 8, ctx.r11.u64);
	// tdllei r10,0
	if (ctx.r10.s64 == 0ll || ctx.r10.u64 < 0ull) ppc_trap(ctx, base, 0);
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
	ctx.lr = 0x82647FAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264C888) {
	REX_FUNC_PROLOGUE();
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8264C9A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,128(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 128);
	// addic r9,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// subfe r10,r9,r10
	temp.u8 = (~ctx.r9.u32 + ctx.r10.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r9.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r9,36(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// stw r10,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,40(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r9,40(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// b 0x826549f8
	sub_826549F8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264DF98) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x8264df70
	sub_8264DF70(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264E250) {
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
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r10,28(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r11,7536
	ctx.r11.s64 = ctx.r11.s64 + 7536;
	// addi r9,r9,7616
	ctx.r9.s64 = ctx.r9.s64 + 7616;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// addi r11,r7,7512
	ctx.r11.s64 = ctx.r7.s64 + 7512;
	// addi r8,r8,7528
	ctx.r8.s64 = ctx.r8.s64 + 7528;
	// addi r9,r6,7496
	ctx.r9.s64 = ctx.r6.s64 + 7496;
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r8,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// addi r30,r3,28
	ctx.r30.s64 = ctx.r3.s64 + 28;
	// stw r9,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264E2BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264dfb8
	ctx.lr = 0x8264E2C4;
	sub_8264DFB8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264db18
	ctx.lr = 0x8264E2CC;
	sub_8264DB18(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264E2E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r3,r31,340
	ctx.r3.s64 = ctx.r31.s64 + 340;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x826432c0
	ctx.lr = 0x8264E2F0;
	sub_826432C0(ctx, base);
	// addi r3,r31,120
	ctx.r3.s64 = ctx.r31.s64 + 120;
	// bl 0x82643458
	ctx.lr = 0x8264E2F8;
	sub_82643458(ctx, base);
	// addi r3,r31,84
	ctx.r3.s64 = ctx.r31.s64 + 84;
	// bl 0x826420b0
	ctx.lr = 0x8264E300;
	sub_826420B0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826420b0
	ctx.lr = 0x8264E308;
	sub_826420B0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r11,r11,5832
	ctx.r11.s64 = ctx.r11.s64 + 5832;
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

DEFINE_REX_FUNC(sub_82654350) {
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
	// bl 0x82644c80
	ctx.lr = 0x82654370;
	sub_82644C80(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x826543b4
	if (ctx.cr0.eq) goto loc_826543B4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826543a0
	if (ctx.cr6.eq) goto loc_826543A0;
	// stw r3,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// b 0x826543a4
	goto loc_826543A4;
loc_826543A0:
	// stw r3,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
loc_826543A4:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// stw r3,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_826543B4:
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

DEFINE_REX_FUNC(sub_8265D838) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8265D840;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lhz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x826826f0
	ctx.lr = 0x8265D854;
	sub_826826F0(ctx, base);
	// lwz r26,0(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r30,4(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// lhz r7,2(r28)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r28.u32 + 2);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r6,4(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x8265cb30
	ctx.lr = 0x8265D874;
	sub_8265CB30(ctx, base);
	// li r27,1
	ctx.r27.s64 = 1;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x8265d89c
	if (ctx.cr6.eq) goto loc_8265D89C;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x8265d89c
	if (!ctx.cr6.eq) goto loc_8265D89C;
	// lwz r5,20(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// b 0x8265d8a8
	goto loc_8265D8A8;
loc_8265D89C:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
loc_8265D8A8:
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// beq cr6,0x8265d8c4
	if (ctx.cr6.eq) goto loc_8265D8C4;
	// cmplwi cr6,r29,3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 3, ctx.xer);
	// bne cr6,0x8265d8c8
	if (!ctx.cr6.eq) goto loc_8265D8C8;
	// li r31,16
	ctx.r31.s64 = 16;
	// b 0x8265d8c8
	goto loc_8265D8C8;
loc_8265D8C4:
	// li r31,8
	ctx.r31.s64 = 8;
loc_8265D8C8:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8265d8dc
	if (!ctx.cr6.eq) goto loc_8265D8DC;
loc_8265D8D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
loc_8265D8DC:
	// lwz r7,8(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8265d8d0
	if (ctx.cr6.eq) goto loc_8265D8D0;
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
loc_8265D8F4:
	// lwz r11,21(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 21);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// rlwimi r10,r27,0,31,29
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD) | (ctx.r10.u64 & 0x2);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8265d96c
	if (ctx.cr6.eq) goto loc_8265D96C;
	// and r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 & ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8265d96c
	if (ctx.cr6.eq) goto loc_8265D96C;
	// lbz r11,20(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 20);
	// lhz r10,14(r28)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8265d96c
	if (!ctx.cr6.eq) goto loc_8265D96C;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8265d934
	if (ctx.cr6.eq) goto loc_8265D934;
	// lwz r10,16(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// b 0x8265d938
	goto loc_8265D938;
loc_8265D934:
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
loc_8265D938:
	// subf r11,r10,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r10.u64;
	// srawi r29,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r29.s64 = ctx.r11.s32 >> 31;
	// xor r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r29.u64;
	// subf. r11,r29,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8265d980
	if (ctx.cr0.eq) goto loc_8265D980;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8265d96c
	if (!ctx.cr6.gt) goto loc_8265D96C;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8265d964
	if (ctx.cr6.eq) goto loc_8265D964;
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8265d96c
	if (ctx.cr6.gt) goto loc_8265D96C;
loc_8265D964:
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
loc_8265D96C:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,25
	ctx.r9.s64 = ctx.r9.s64 + 25;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8265d8f4
	if (ctx.cr6.lt) goto loc_8265D8F4;
	// b 0x8265d984
	goto loc_8265D984;
loc_8265D980:
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
loc_8265D984:
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x8265d8d0
	if (ctx.cr6.eq) goto loc_8265D8D0;
	// mulli r11,r4,25
	ctx.r11.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(25));
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82666140) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82666148;
	__savegprlr_28(ctx, base);
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r29,4(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r31,20(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r5,24(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r4,32(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// beq cr6,0x8266616c
	if (ctx.cr6.eq) goto loc_8266616C;
	// li r5,1
	ctx.r5.s64 = 1;
loc_8266616C:
	// addi r11,r5,-1
	ctx.r11.s64 = ctx.r5.s64 + -1;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x826663d0
	if (ctx.cr6.gt) goto loc_826663D0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x826661c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_826661C8;
	// bdzf 4*cr6+eq,0x82666208
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82666208;
	// bdzf 4*cr6+eq,0x82666258
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82666258;
	// bdzf 4*cr6+eq,0x826662b8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_826662B8;
	// bne cr6,0x82666328
	if (!ctx.cr6.eq) goto loc_82666328;
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24804(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24804);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,-112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// beq cr6,0x826663d0
	if (ctx.cr6.eq) goto loc_826663D0;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,-80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// b 0x826663d0
	goto loc_826663D0;
loc_826661C8:
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f0,24804(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24804);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f11,-112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// stfs f10,-108(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// beq cr6,0x826663d0
	if (ctx.cr6.eq) goto loc_826663D0;
	// lfs f12,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f10,-76(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// b 0x826663c4
	goto loc_826663C4;
loc_82666208:
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f0,24804(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24804);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f10,32(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f11,-112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// stfs f9,-108(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// stfs f8,-104(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// beq cr6,0x826663d0
	if (ctx.cr6.eq) goto loc_826663D0;
	// lfs f10,32(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// lfs f12,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f8,-72(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// b 0x826663bc
	goto loc_826663BC;
loc_82666258:
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f0,24804(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24804);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f10,40(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 40);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f8,60(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 60);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stfs f11,-112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// stfs f9,-108(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// stfs f7,-104(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// stfs f6,-100(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + -100, temp.u32);
	// beq cr6,0x826663d0
	if (ctx.cr6.eq) goto loc_826663D0;
	// lfs f8,60(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 60);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// lfs f12,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,40(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f10.f64 = double(temp.f32);
	// stfs f6,-68(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// b 0x826663b4
	goto loc_826663B4;
loc_826662B8:
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f0,24804(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24804);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f10,48(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 48);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f8,72(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 72);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// lfs f6,96(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 96);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f8,f0
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// stfs f11,-112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// stfs f9,-108(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// stfs f7,-104(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// stfs f5,-100(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + -100, temp.u32);
	// stfs f4,-96(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// beq cr6,0x826663d0
	if (ctx.cr6.eq) goto loc_826663D0;
	// lfs f6,96(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 96);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// lfs f12,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,48(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 48);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,72(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 72);
	ctx.f8.f64 = double(temp.f32);
	// stfs f4,-64(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// b 0x826663ac
	goto loc_826663AC;
loc_82666328:
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f0,24804(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24804);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f10,56(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f8,84(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// lfs f6,112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f8,f0
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// lfs f4,140(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 140);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f6,f0
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// fmuls f2,f4,f0
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// stfs f11,-112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// stfs f9,-108(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// stfs f7,-104(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// stfs f5,-100(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + -100, temp.u32);
	// stfs f3,-96(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// stfs f2,-92(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// beq cr6,0x826663d0
	if (ctx.cr6.eq) goto loc_826663D0;
	// lfs f6,112(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 140);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f6,f0
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// fmuls f2,f4,f0
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// lfs f12,28(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,56(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,84(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// stfs f3,-64(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// stfs f2,-60(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
loc_826663AC:
	// fmuls f5,f8,f0
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stfs f5,-68(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
loc_826663B4:
	// fmuls f7,f10,f0
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f7,-72(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
loc_826663BC:
	// fmuls f9,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f9,-76(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
loc_826663C4:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f11,-80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
loc_826663D0:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x826665f0
	if (!ctx.cr6.eq) goto loc_826665F0;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r31,4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4, ctx.xer);
	// blt cr6,0x8266656c
	if (ctx.cr6.lt) goto loc_8266656C;
	// addi r10,r31,-4
	ctx.r10.s64 = ctx.r31.s64 + -4;
	// addi r6,r29,8
	ctx.r6.s64 = ctx.r29.s64 + 8;
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r30,4
	ctx.r10.s64 = ctx.r30.s64 + 4;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82666410:
	// lhz r7,-4(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + -4);
	// lfsx f0,r8,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// std r8,-144(r1)
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.r8.u64);
	// lfd f13,-144(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// beq cr6,0x82666448
	if (ctx.cr6.eq) goto loc_82666448;
	// lfs f13,-8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,-8(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + -8, temp.u32);
	// b 0x8266644c
	goto loc_8266644C;
loc_82666448:
	// stfs f0,-8(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + -8, temp.u32);
loc_8266644C:
	// lhz r7,-2(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + -2);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r8,r1,-112
	ctx.r8.s64 = ctx.r1.s64 + -112;
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// subfc r9,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r9.u64 = ctx.r11.u64 - ctx.r5.u64;
	// std r7,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r7.u64);
	// lfd f0,-136(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f11,r7,r8
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f11,f12
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// beq cr6,0x8266649c
	if (ctx.cr6.eq) goto loc_8266649C;
	// lfs f13,-4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,-4(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + -4, temp.u32);
	// b 0x826664a0
	goto loc_826664A0;
loc_8266649C:
	// stfs f0,-4(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + -4, temp.u32);
loc_826664A0:
	// lhz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r8,r1,-112
	ctx.r8.s64 = ctx.r1.s64 + -112;
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// subfc r9,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r9.u64 = ctx.r11.u64 - ctx.r5.u64;
	// std r7,-128(r1)
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.r7.u64);
	// lfd f13,-128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r7,r8
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// beq cr6,0x826664f0
	if (ctx.cr6.eq) goto loc_826664F0;
	// lfs f13,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,0(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// b 0x826664f4
	goto loc_826664F4;
loc_826664F0:
	// stfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
loc_826664F4:
	// lhz r7,2(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r8,r1,-112
	ctx.r8.s64 = ctx.r1.s64 + -112;
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// subfc r9,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r9.u64 = ctx.r11.u64 - ctx.r5.u64;
	// std r7,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.r7.u64);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f11,r7,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfd f0,-120(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f11,f12
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// beq cr6,0x82666544
	if (ctx.cr6.eq) goto loc_82666544;
	// lfs f13,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,4(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// b 0x82666548
	goto loc_82666548;
loc_82666544:
	// stfs f0,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
loc_82666548:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// subfc r9,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r9.u64 = ctx.r11.u64 - ctx.r5.u64;
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bdnz 0x82666410
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82666410;
loc_8266656C:
	// cmplw cr6,r3,r31
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x8266684c
	if (!ctx.cr6.lt) goto loc_8266684C;
	// subf r7,r3,r31
	ctx.r7.u64 = ctx.r31.u64 - ctx.r3.u64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r3,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r29
	ctx.r9.u64 = ctx.r10.u64 + ctx.r29.u64;
	// add r10,r8,r30
	ctx.r10.u64 = ctx.r8.u64 + ctx.r30.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8266658C:
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r1,-112
	ctx.r6.s64 = ctx.r1.s64 + -112;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// std r8,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.r8.u64);
	// lfd f13,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfsx f0,r7,r6
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// beq cr6,0x826665cc
	if (ctx.cr6.eq) goto loc_826665CC;
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,0(r9)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// b 0x826665d0
	goto loc_826665D0;
loc_826665CC:
	// stfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
loc_826665D0:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// subfc r8,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r8.u64 = ctx.r11.u64 - ctx.r5.u64;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 & ctx.r11.u64;
	// bdnz 0x8266658c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8266658C;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
loc_826665F0:
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r31,4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4, ctx.xer);
	// blt cr6,0x826667bc
	if (ctx.cr6.lt) goto loc_826667BC;
	// addi r10,r31,-4
	ctx.r10.s64 = ctx.r31.s64 + -4;
	// addi r7,r29,8
	ctx.r7.s64 = ctx.r29.s64 + 8;
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r30,4
	ctx.r10.s64 = ctx.r30.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82666618:
	// lhz r3,-4(r10)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r10.u32 + -4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,-112
	ctx.r8.s64 = ctx.r1.s64 + -112;
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// addi r28,r1,-80
	ctx.r28.s64 = ctx.r1.s64 + -80;
	// std r3,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.r3.u64);
	// lfd f0,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfsx f12,r9,r8
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f10,r9,r28
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f12.f64));
	// stfsx f9,r9,r8
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r8.u32, temp.u32);
	// fmuls f0,f11,f12
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// beq cr6,0x82666668
	if (ctx.cr6.eq) goto loc_82666668;
	// lfs f13,-8(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,-8(r7)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r7.u32 + -8, temp.u32);
	// b 0x8266666c
	goto loc_8266666C;
loc_82666668:
	// stfs f0,-8(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + -8, temp.u32);
loc_8266666C:
	// lhz r3,-2(r10)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r10.u32 + -2);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// subfc r8,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r8.u64 = ctx.r11.u64 - ctx.r5.u64;
	// std r3,-128(r1)
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.r3.u64);
	// addi r3,r1,-80
	ctx.r3.s64 = ctx.r1.s64 + -80;
	// subfe r8,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// and r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 & ctx.r11.u64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f11,r11,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f10,r11,r3
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// stfsx f9,r11,r9
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, temp.u32);
	// lfd f0,-128(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f12,f11
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// beq cr6,0x826666cc
	if (ctx.cr6.eq) goto loc_826666CC;
	// lfs f13,-4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,-4(r7)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r7.u32 + -4, temp.u32);
	// b 0x826666d0
	goto loc_826666D0;
loc_826666CC:
	// stfs f0,-4(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + -4, temp.u32);
loc_826666D0:
	// lhz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// subfc r3,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r3.u64 = ctx.r11.u64 - ctx.r5.u64;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// subfe r3,r3,r3
	temp.u8 = (~ctx.r3.u32 + ctx.r3.u32 < ~ctx.r3.u32) | (~ctx.r3.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r3.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// std r8,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r8.u64);
	// lfd f11,-136(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// and r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 & ctx.r11.u64;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r1,-80
	ctx.r28.s64 = ctx.r1.s64 + -80;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lfsx f0,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r11,r28
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfsx f12,r11,r9
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, temp.u32);
	// fmuls f0,f9,f0
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// beq cr6,0x82666734
	if (ctx.cr6.eq) goto loc_82666734;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,0(r7)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// b 0x82666738
	goto loc_82666738;
loc_82666734:
	// stfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
loc_82666738:
	// lhz r3,2(r10)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// subfc r3,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r3.u64 = ctx.r11.u64 - ctx.r5.u64;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// subfe r3,r3,r3
	temp.u8 = (~ctx.r3.u32 + ctx.r3.u32 < ~ctx.r3.u32) | (~ctx.r3.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r3.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// std r8,-144(r1)
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.r8.u64);
	// lfd f0,-144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// and r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 & ctx.r11.u64;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,-80
	ctx.r3.s64 = ctx.r1.s64 + -80;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lfsx f11,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f10,r11,r3
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// stfsx f9,r11,r9
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, temp.u32);
	// fmuls f0,f12,f11
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// beq cr6,0x8266679c
	if (ctx.cr6.eq) goto loc_8266679C;
	// lfs f13,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,4(r7)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// b 0x826667a0
	goto loc_826667A0;
loc_8266679C:
	// stfs f0,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
loc_826667A0:
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// subfc r9,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r9.u64 = ctx.r11.u64 - ctx.r5.u64;
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// subfe r3,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 & ctx.r11.u64;
	// bdnz 0x82666618
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82666618;
loc_826667BC:
	// cmplw cr6,r6,r31
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x8266684c
	if (!ctx.cr6.lt) goto loc_8266684C;
	// subf r8,r6,r31
	ctx.r8.u64 = ctx.r31.u64 - ctx.r6.u64;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r6,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 + ctx.r29.u64;
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826667DC:
	// lhz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,-112
	ctx.r8.s64 = ctx.r1.s64 + -112;
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// addi r6,r1,-80
	ctx.r6.s64 = ctx.r1.s64 + -80;
	// std r3,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.r3.u64);
	// lfd f0,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfsx f12,r10,r8
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f10,r10,r6
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f12.f64));
	// stfsx f9,r10,r8
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r8.u32, temp.u32);
	// fmuls f0,f11,f12
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// beq cr6,0x8266682c
	if (ctx.cr6.eq) goto loc_8266682C;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,0(r7)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// b 0x82666830
	goto loc_82666830;
loc_8266682C:
	// stfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
loc_82666830:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// subfc r10,r5,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r5.u32;
	ctx.r10.u64 = ctx.r11.u64 - ctx.r5.u64;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// subfe r6,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 & ctx.r11.u64;
	// bdnz 0x826667dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826667DC;
loc_8266684C:
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826C1C28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x826C1C30;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,644
	ctx.r5.s64 = 644;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x8273a590
	ctx.lr = 0x826C1C50;
	sub_8273A590(ctx, base);
	// lis r10,8320
	ctx.r10.s64 = 545259520;
	// addi r11,r29,32
	ctx.r11.s64 = ctx.r29.s64 + 32;
	// ori r27,r10,4096
	ctx.r27.u64 = ctx.r10.u64 | 4096;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// add r4,r11,r26
	ctx.r4.u64 = ctx.r11.u64 + ctx.r26.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8263d8a0
	ctx.lr = 0x826C1C74;
	sub_8263D8A0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x826c1c90
	if (!ctx.cr6.eq) goto loc_826C1C90;
loc_826C1C84:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_826C1C90:
	// addi r11,r29,16
	ctx.r11.s64 = ctx.r29.s64 + 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r5,r11,r26
	ctx.r5.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bl 0x8273a590
	ctx.lr = 0x826C1CA8;
	sub_8273A590(ctx, base);
	// add r10,r30,r29
	ctx.r10.u64 = ctx.r30.u64 + ctx.r29.u64;
	// add r11,r28,r29
	ctx.r11.u64 = ctx.r28.u64 + ctx.r29.u64;
	// addi r10,r10,31
	ctx.r10.s64 = ctx.r10.s64 + 31;
	// addi r28,r11,32
	ctx.r28.s64 = ctx.r11.s64 + 32;
	// rlwinm r9,r10,0,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFE0;
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8263d8a0
	ctx.lr = 0x826C1CD4;
	sub_8263D8A0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826c1c84
	if (ctx.cr6.eq) goto loc_826C1C84;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x8273a590
	ctx.lr = 0x826C1CF0;
	sub_8273A590(ctx, base);
	// srawi r25,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r25.s64 = ctx.r29.s32 >> 1;
	// add r10,r25,r30
	ctx.r10.u64 = ctx.r25.u64 + ctx.r30.u64;
	// clrlwi r11,r10,27
	ctx.r11.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826c1d08
	if (ctx.cr6.eq) goto loc_826C1D08;
	// subfic r11,r11,32
	ctx.xer.ca = ctx.r11.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
loc_826C1D08:
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8263d8a0
	ctx.lr = 0x826C1D24;
	sub_8263D8A0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826c1c84
	if (ctx.cr6.eq) goto loc_826C1C84;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x8273a590
	ctx.lr = 0x826C1D40;
	sub_8273A590(ctx, base);
	// add r10,r25,r30
	ctx.r10.u64 = ctx.r25.u64 + ctx.r30.u64;
	// clrlwi r11,r10,27
	ctx.r11.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826c1d54
	if (ctx.cr6.eq) goto loc_826C1D54;
	// subfic r11,r11,32
	ctx.xer.ca = ctx.r11.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
loc_826C1D54:
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r29,592(r31)
	REX_STORE_U32(ctx.r31.u32 + 592, ctx.r29.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r26,588(r31)
	REX_STORE_U32(ctx.r31.u32 + 588, ctx.r26.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,636(r31)
	REX_STORE_U32(ctx.r31.u32 + 636, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826C7818) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x826C7820;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// lwz r7,16(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// mr r19,r8
	ctx.r19.u64 = ctx.r8.u64;
	// stw r3,260(r1)
	REX_STORE_U32(ctx.r1.u32 + 260, ctx.r3.u32);
	// mr r18,r9
	ctx.r18.u64 = ctx.r9.u64;
	// mr r17,r10
	ctx.r17.u64 = ctx.r10.u64;
	// lis r11,22870
	ctx.r11.s64 = 1498808320;
	// lis r10,22101
	ctx.r10.s64 = 1448411136;
	// lis r9,12338
	ctx.r9.s64 = 808583168;
	// lis r8,12593
	ctx.r8.s64 = 825294848;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// ori r14,r11,22869
	ctx.r14.u64 = ctx.r11.u64 | 22869;
	// ori r16,r10,22857
	ctx.r16.u64 = ctx.r10.u64 | 22857;
	// ori r15,r9,13385
	ctx.r15.u64 = ctx.r9.u64 | 13385;
	// ori r30,r8,13392
	ctx.r30.u64 = ctx.r8.u64 | 13392;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x826c78c8
	if (ctx.cr6.eq) goto loc_826C78C8;
	// cmpwi cr6,r7,3
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 3, ctx.xer);
	// beq cr6,0x826c78c8
	if (ctx.cr6.eq) goto loc_826C78C8;
	// cmpw cr6,r7,r14
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r14.s32, ctx.xer);
	// beq cr6,0x826c78c8
	if (ctx.cr6.eq) goto loc_826C78C8;
	// lis r11,12889
	ctx.r11.s64 = 844693504;
	// ori r10,r11,21849
	ctx.r10.u64 = ctx.r11.u64 | 21849;
	// cmpw cr6,r7,r10
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x826c78c8
	if (ctx.cr6.eq) goto loc_826C78C8;
	// cmpw cr6,r7,r16
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r16.s32, ctx.xer);
	// beq cr6,0x826c78c8
	if (ctx.cr6.eq) goto loc_826C78C8;
	// cmpw cr6,r7,r15
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r15.s32, ctx.xer);
	// beq cr6,0x826c78c8
	if (ctx.cr6.eq) goto loc_826C78C8;
	// lis r11,12849
	ctx.r11.s64 = 842072064;
	// ori r10,r11,22105
	ctx.r10.u64 = ctx.r11.u64 | 22105;
	// cmpw cr6,r7,r10
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x826c78c8
	if (ctx.cr6.eq) goto loc_826C78C8;
	// lis r11,12850
	ctx.r11.s64 = 842137600;
	// ori r10,r11,13392
	ctx.r10.u64 = ctx.r11.u64 | 13392;
	// cmplw cr6,r7,r10
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x826c78c8
	if (ctx.cr6.eq) goto loc_826C78C8;
	// cmpw cr6,r7,r30
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r30.s32, ctx.xer);
	// bne cr6,0x826c7b74
	if (!ctx.cr6.eq) goto loc_826C7B74;
loc_826C78C8:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x826c7b7c
	if (ctx.cr6.eq) goto loc_826C7B7C;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// blt cr6,0x826c7b74
	if (ctx.cr6.lt) goto loc_826C7B74;
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// blt cr6,0x826c7b74
	if (ctx.cr6.lt) goto loc_826C7B74;
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// blt cr6,0x826c7b74
	if (ctx.cr6.lt) goto loc_826C7B74;
	// cmpwi cr6,r17,1
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 1, ctx.xer);
	// blt cr6,0x826c7b74
	if (ctx.cr6.lt) goto loc_826C7B74;
	// lwz r20,324(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// cmpwi cr6,r20,1
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 1, ctx.xer);
	// blt cr6,0x826c7b74
	if (ctx.cr6.lt) goto loc_826C7B74;
	// lwz r21,332(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 332);
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// blt cr6,0x826c7b74
	if (ctx.cr6.lt) goto loc_826C7B74;
	// lwz r22,340(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 340);
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// blt cr6,0x826c7b74
	if (ctx.cr6.lt) goto loc_826C7B74;
	// lwz r23,348(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 348);
	// cmpwi cr6,r23,1
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 1, ctx.xer);
	// blt cr6,0x826c7b74
	if (ctx.cr6.lt) goto loc_826C7B74;
	// lwz r24,356(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 356);
	// cmpwi cr6,r24,1
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 1, ctx.xer);
	// blt cr6,0x826c7b74
	if (ctx.cr6.lt) goto loc_826C7B74;
	// lwz r4,4(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// bgt cr6,0x826c7940
	if (ctx.cr6.gt) goto loc_826C7940;
	// neg r11,r4
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r4.u64);
loc_826C7940:
	// add r10,r19,r17
	ctx.r10.u64 = ctx.r19.u64 + ctx.r17.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x826c7b74
	if (ctx.cr6.gt) goto loc_826C7B74;
	// lwz r5,8(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// bgt cr6,0x826c7960
	if (ctx.cr6.gt) goto loc_826C7960;
	// neg r11,r5
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r5.u64);
loc_826C7960:
	// add r10,r18,r20
	ctx.r10.u64 = ctx.r18.u64 + ctx.r20.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x826c7b74
	if (ctx.cr6.gt) goto loc_826C7B74;
	// add r11,r21,r23
	ctx.r11.u64 = ctx.r21.u64 + ctx.r23.u64;
	// cmpw cr6,r11,r25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r25.s32, ctx.xer);
	// bgt cr6,0x826c7b74
	if (ctx.cr6.gt) goto loc_826C7B74;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// bgt cr6,0x826c7988
	if (ctx.cr6.gt) goto loc_826C7988;
	// neg r11,r26
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r26.u64);
loc_826C7988:
	// add r10,r22,r24
	ctx.r10.u64 = ctx.r22.u64 + ctx.r24.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x826c7b74
	if (ctx.cr6.gt) goto loc_826C7B74;
	// lwz r29,372(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lhz r31,14(r28)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// bl 0x826c5fc0
	ctx.lr = 0x826C79A8;
	sub_826C5FC0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826c7b74
	if (!ctx.cr6.eq) goto loc_826C7B74;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x826c5fc0
	ctx.lr = 0x826C79C0;
	sub_826C5FC0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826c7b74
	if (!ctx.cr6.eq) goto loc_826C7B74;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x826c5fc0
	ctx.lr = 0x826C79D8;
	sub_826C5FC0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826c7b74
	if (!ctx.cr6.eq) goto loc_826C7B74;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x826c5fc0
	ctx.lr = 0x826C79F0;
	sub_826C5FC0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826c7b74
	if (!ctx.cr6.eq) goto loc_826C7B74;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x826c5fc0
	ctx.lr = 0x826C7A08;
	sub_826C5FC0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826c7b74
	if (!ctx.cr6.eq) goto loc_826C7B74;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x826c5fc0
	ctx.lr = 0x826C7A20;
	sub_826C5FC0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826c7b74
	if (!ctx.cr6.eq) goto loc_826C7B74;
	// cmpw cr6,r7,r30
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r30.s32, ctx.xer);
	// bne cr6,0x826c7a38
	if (!ctx.cr6.eq) goto loc_826C7A38;
	// li r30,1
	ctx.r30.s64 = 1;
	// b 0x826c7a98
	goto loc_826C7A98;
loc_826C7A38:
	// cmpw cr6,r7,r16
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r16.s32, ctx.xer);
	// beq cr6,0x826c7a94
	if (ctx.cr6.eq) goto loc_826C7A94;
	// cmpw cr6,r7,r15
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r15.s32, ctx.xer);
	// beq cr6,0x826c7a94
	if (ctx.cr6.eq) goto loc_826C7A94;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x826c7a58
	if (!ctx.cr6.eq) goto loc_826C7A58;
	// cmpwi cr6,r31,32
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 32, ctx.xer);
	// b 0x826c7a8c
	goto loc_826C7A8C;
loc_826C7A58:
	// cmpw cr6,r7,r14
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r14.s32, ctx.xer);
	// beq cr6,0x826c7a94
	if (ctx.cr6.eq) goto loc_826C7A94;
	// lis r11,12889
	ctx.r11.s64 = 844693504;
	// ori r10,r11,21849
	ctx.r10.u64 = ctx.r11.u64 | 21849;
	// cmpw cr6,r7,r10
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x826c7a94
	if (ctx.cr6.eq) goto loc_826C7A94;
	// lis r11,12850
	ctx.r11.s64 = 842137600;
	// ori r10,r11,13392
	ctx.r10.u64 = ctx.r11.u64 | 13392;
	// cmplw cr6,r7,r10
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x826c7a94
	if (ctx.cr6.eq) goto loc_826C7A94;
	// lis r11,12849
	ctx.r11.s64 = 842072064;
	// ori r10,r11,22105
	ctx.r10.u64 = ctx.r11.u64 | 22105;
	// cmpw cr6,r7,r10
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, ctx.xer);
loc_826C7A8C:
	// li r30,0
	ctx.r30.s64 = 0;
	// bne cr6,0x826c7a98
	if (!ctx.cr6.eq) goto loc_826C7A98;
loc_826C7A94:
	// lwz r30,364(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 364);
loc_826C7A98:
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826c6418
	ctx.lr = 0x826C7AB4;
	sub_826C6418(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826c7b80
	if (!ctx.cr6.eq) goto loc_826C7B80;
	// lwz r31,0(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lwz r10,8(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// stw r10,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
	// stw r25,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r25.u32);
	// stw r26,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r26.u32);
	// stw r30,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r30.u32);
	// stw r29,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r29.u32);
	// bl 0x826c7448
	ctx.lr = 0x826C7AE8;
	sub_826C7448(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826c7b7c
	if (ctx.cr6.eq) goto loc_826C7B7C;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// mr r6,r17
	ctx.r6.u64 = ctx.r17.u64;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x826c74f0
	ctx.lr = 0x826C7B18;
	sub_826C74F0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826c7b7c
	if (!ctx.cr6.eq) goto loc_826C7B7C;
	// lwz r11,260(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 260);
	// lwz r10,22368(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 22368);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x826c7b68
	if (ctx.cr6.eq) goto loc_826C7B68;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
	// lwz r9,22372(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 22372);
	// stw r9,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r9.u32);
	// lwz r8,22376(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 22376);
	// stw r8,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r8.u32);
	// lwz r7,22380(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 22380);
	// stw r7,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r7.u32);
	// lwz r6,22384(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 22384);
	// stw r6,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r6.u32);
	// lwz r5,22388(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 22388);
	// stw r5,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r5.u32);
	// lwz r4,22392(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 22392);
	// stw r4,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r4.u32);
loc_826C7B68:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_826C7B74:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
loc_826C7B7C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_826C7B80:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826E68F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// vspltisb v0,15
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0xF)));
	// srawi. r11,r6,6
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3F) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 6;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// vspltisb v13,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_set1_epi8(char(0x1)));
	// vslb v0,v0,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi8(0x7));
		simde_mm_store_si128((simde__m128i*)ctx.v0.u8, rex::ppc::simde_mm_sllv_epi8(a, shift));
	}
	// ble 0x826e696c
	if (!ctx.cr0.gt) goto loc_826E696C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,48
	ctx.r11.s64 = 48;
loc_826E6914:
	// lvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsububm v10,v12,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_sub_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v9,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsububm v8,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_sub_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v7,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsububm v6,v9,v0
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_sub_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsububm v5,v7,v0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_sub_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsrab v4,v10,v13
	ctx.v4.s8[0] = ctx.v10.s8[0] >> (ctx.v13.u8[0] & 0x7);
	ctx.v4.s8[1] = ctx.v10.s8[1] >> (ctx.v13.u8[1] & 0x7);
	ctx.v4.s8[2] = ctx.v10.s8[2] >> (ctx.v13.u8[2] & 0x7);
	ctx.v4.s8[3] = ctx.v10.s8[3] >> (ctx.v13.u8[3] & 0x7);
	ctx.v4.s8[4] = ctx.v10.s8[4] >> (ctx.v13.u8[4] & 0x7);
	ctx.v4.s8[5] = ctx.v10.s8[5] >> (ctx.v13.u8[5] & 0x7);
	ctx.v4.s8[6] = ctx.v10.s8[6] >> (ctx.v13.u8[6] & 0x7);
	ctx.v4.s8[7] = ctx.v10.s8[7] >> (ctx.v13.u8[7] & 0x7);
	ctx.v4.s8[8] = ctx.v10.s8[8] >> (ctx.v13.u8[8] & 0x7);
	ctx.v4.s8[9] = ctx.v10.s8[9] >> (ctx.v13.u8[9] & 0x7);
	ctx.v4.s8[10] = ctx.v10.s8[10] >> (ctx.v13.u8[10] & 0x7);
	ctx.v4.s8[11] = ctx.v10.s8[11] >> (ctx.v13.u8[11] & 0x7);
	ctx.v4.s8[12] = ctx.v10.s8[12] >> (ctx.v13.u8[12] & 0x7);
	ctx.v4.s8[13] = ctx.v10.s8[13] >> (ctx.v13.u8[13] & 0x7);
	ctx.v4.s8[14] = ctx.v10.s8[14] >> (ctx.v13.u8[14] & 0x7);
	ctx.v4.s8[15] = ctx.v10.s8[15] >> (ctx.v13.u8[15] & 0x7);
	// vsrab v3,v8,v13
	ctx.v3.s8[0] = ctx.v8.s8[0] >> (ctx.v13.u8[0] & 0x7);
	ctx.v3.s8[1] = ctx.v8.s8[1] >> (ctx.v13.u8[1] & 0x7);
	ctx.v3.s8[2] = ctx.v8.s8[2] >> (ctx.v13.u8[2] & 0x7);
	ctx.v3.s8[3] = ctx.v8.s8[3] >> (ctx.v13.u8[3] & 0x7);
	ctx.v3.s8[4] = ctx.v8.s8[4] >> (ctx.v13.u8[4] & 0x7);
	ctx.v3.s8[5] = ctx.v8.s8[5] >> (ctx.v13.u8[5] & 0x7);
	ctx.v3.s8[6] = ctx.v8.s8[6] >> (ctx.v13.u8[6] & 0x7);
	ctx.v3.s8[7] = ctx.v8.s8[7] >> (ctx.v13.u8[7] & 0x7);
	ctx.v3.s8[8] = ctx.v8.s8[8] >> (ctx.v13.u8[8] & 0x7);
	ctx.v3.s8[9] = ctx.v8.s8[9] >> (ctx.v13.u8[9] & 0x7);
	ctx.v3.s8[10] = ctx.v8.s8[10] >> (ctx.v13.u8[10] & 0x7);
	ctx.v3.s8[11] = ctx.v8.s8[11] >> (ctx.v13.u8[11] & 0x7);
	ctx.v3.s8[12] = ctx.v8.s8[12] >> (ctx.v13.u8[12] & 0x7);
	ctx.v3.s8[13] = ctx.v8.s8[13] >> (ctx.v13.u8[13] & 0x7);
	ctx.v3.s8[14] = ctx.v8.s8[14] >> (ctx.v13.u8[14] & 0x7);
	ctx.v3.s8[15] = ctx.v8.s8[15] >> (ctx.v13.u8[15] & 0x7);
	// vsrab v2,v6,v13
	ctx.v2.s8[0] = ctx.v6.s8[0] >> (ctx.v13.u8[0] & 0x7);
	ctx.v2.s8[1] = ctx.v6.s8[1] >> (ctx.v13.u8[1] & 0x7);
	ctx.v2.s8[2] = ctx.v6.s8[2] >> (ctx.v13.u8[2] & 0x7);
	ctx.v2.s8[3] = ctx.v6.s8[3] >> (ctx.v13.u8[3] & 0x7);
	ctx.v2.s8[4] = ctx.v6.s8[4] >> (ctx.v13.u8[4] & 0x7);
	ctx.v2.s8[5] = ctx.v6.s8[5] >> (ctx.v13.u8[5] & 0x7);
	ctx.v2.s8[6] = ctx.v6.s8[6] >> (ctx.v13.u8[6] & 0x7);
	ctx.v2.s8[7] = ctx.v6.s8[7] >> (ctx.v13.u8[7] & 0x7);
	ctx.v2.s8[8] = ctx.v6.s8[8] >> (ctx.v13.u8[8] & 0x7);
	ctx.v2.s8[9] = ctx.v6.s8[9] >> (ctx.v13.u8[9] & 0x7);
	ctx.v2.s8[10] = ctx.v6.s8[10] >> (ctx.v13.u8[10] & 0x7);
	ctx.v2.s8[11] = ctx.v6.s8[11] >> (ctx.v13.u8[11] & 0x7);
	ctx.v2.s8[12] = ctx.v6.s8[12] >> (ctx.v13.u8[12] & 0x7);
	ctx.v2.s8[13] = ctx.v6.s8[13] >> (ctx.v13.u8[13] & 0x7);
	ctx.v2.s8[14] = ctx.v6.s8[14] >> (ctx.v13.u8[14] & 0x7);
	ctx.v2.s8[15] = ctx.v6.s8[15] >> (ctx.v13.u8[15] & 0x7);
	// vsrab v1,v5,v13
	ctx.v1.s8[0] = ctx.v5.s8[0] >> (ctx.v13.u8[0] & 0x7);
	ctx.v1.s8[1] = ctx.v5.s8[1] >> (ctx.v13.u8[1] & 0x7);
	ctx.v1.s8[2] = ctx.v5.s8[2] >> (ctx.v13.u8[2] & 0x7);
	ctx.v1.s8[3] = ctx.v5.s8[3] >> (ctx.v13.u8[3] & 0x7);
	ctx.v1.s8[4] = ctx.v5.s8[4] >> (ctx.v13.u8[4] & 0x7);
	ctx.v1.s8[5] = ctx.v5.s8[5] >> (ctx.v13.u8[5] & 0x7);
	ctx.v1.s8[6] = ctx.v5.s8[6] >> (ctx.v13.u8[6] & 0x7);
	ctx.v1.s8[7] = ctx.v5.s8[7] >> (ctx.v13.u8[7] & 0x7);
	ctx.v1.s8[8] = ctx.v5.s8[8] >> (ctx.v13.u8[8] & 0x7);
	ctx.v1.s8[9] = ctx.v5.s8[9] >> (ctx.v13.u8[9] & 0x7);
	ctx.v1.s8[10] = ctx.v5.s8[10] >> (ctx.v13.u8[10] & 0x7);
	ctx.v1.s8[11] = ctx.v5.s8[11] >> (ctx.v13.u8[11] & 0x7);
	ctx.v1.s8[12] = ctx.v5.s8[12] >> (ctx.v13.u8[12] & 0x7);
	ctx.v1.s8[13] = ctx.v5.s8[13] >> (ctx.v13.u8[13] & 0x7);
	ctx.v1.s8[14] = ctx.v5.s8[14] >> (ctx.v13.u8[14] & 0x7);
	ctx.v1.s8[15] = ctx.v5.s8[15] >> (ctx.v13.u8[15] & 0x7);
	// vaddubm v31,v4,v0
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddubm v30,v3,v0
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddubm v29,v2,v0
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddubm v28,v1,v0
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvx128 v31,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v30,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v29,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v28,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r3,64
	ctx.r3.s64 = ctx.r3.s64 + 64;
	// bdnz 0x826e6914
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E6914;
loc_826E696C:
	// srawi. r11,r7,4
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r7.s32 >> 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blelr 
	if (!ctx.cr0.gt) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826E6978:
	// lvx128 v12,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsububm v10,v12,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_sub_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsububm v9,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_sub_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsrab v8,v10,v13
	ctx.v8.s8[0] = ctx.v10.s8[0] >> (ctx.v13.u8[0] & 0x7);
	ctx.v8.s8[1] = ctx.v10.s8[1] >> (ctx.v13.u8[1] & 0x7);
	ctx.v8.s8[2] = ctx.v10.s8[2] >> (ctx.v13.u8[2] & 0x7);
	ctx.v8.s8[3] = ctx.v10.s8[3] >> (ctx.v13.u8[3] & 0x7);
	ctx.v8.s8[4] = ctx.v10.s8[4] >> (ctx.v13.u8[4] & 0x7);
	ctx.v8.s8[5] = ctx.v10.s8[5] >> (ctx.v13.u8[5] & 0x7);
	ctx.v8.s8[6] = ctx.v10.s8[6] >> (ctx.v13.u8[6] & 0x7);
	ctx.v8.s8[7] = ctx.v10.s8[7] >> (ctx.v13.u8[7] & 0x7);
	ctx.v8.s8[8] = ctx.v10.s8[8] >> (ctx.v13.u8[8] & 0x7);
	ctx.v8.s8[9] = ctx.v10.s8[9] >> (ctx.v13.u8[9] & 0x7);
	ctx.v8.s8[10] = ctx.v10.s8[10] >> (ctx.v13.u8[10] & 0x7);
	ctx.v8.s8[11] = ctx.v10.s8[11] >> (ctx.v13.u8[11] & 0x7);
	ctx.v8.s8[12] = ctx.v10.s8[12] >> (ctx.v13.u8[12] & 0x7);
	ctx.v8.s8[13] = ctx.v10.s8[13] >> (ctx.v13.u8[13] & 0x7);
	ctx.v8.s8[14] = ctx.v10.s8[14] >> (ctx.v13.u8[14] & 0x7);
	ctx.v8.s8[15] = ctx.v10.s8[15] >> (ctx.v13.u8[15] & 0x7);
	// vsrab v7,v9,v13
	ctx.v7.s8[0] = ctx.v9.s8[0] >> (ctx.v13.u8[0] & 0x7);
	ctx.v7.s8[1] = ctx.v9.s8[1] >> (ctx.v13.u8[1] & 0x7);
	ctx.v7.s8[2] = ctx.v9.s8[2] >> (ctx.v13.u8[2] & 0x7);
	ctx.v7.s8[3] = ctx.v9.s8[3] >> (ctx.v13.u8[3] & 0x7);
	ctx.v7.s8[4] = ctx.v9.s8[4] >> (ctx.v13.u8[4] & 0x7);
	ctx.v7.s8[5] = ctx.v9.s8[5] >> (ctx.v13.u8[5] & 0x7);
	ctx.v7.s8[6] = ctx.v9.s8[6] >> (ctx.v13.u8[6] & 0x7);
	ctx.v7.s8[7] = ctx.v9.s8[7] >> (ctx.v13.u8[7] & 0x7);
	ctx.v7.s8[8] = ctx.v9.s8[8] >> (ctx.v13.u8[8] & 0x7);
	ctx.v7.s8[9] = ctx.v9.s8[9] >> (ctx.v13.u8[9] & 0x7);
	ctx.v7.s8[10] = ctx.v9.s8[10] >> (ctx.v13.u8[10] & 0x7);
	ctx.v7.s8[11] = ctx.v9.s8[11] >> (ctx.v13.u8[11] & 0x7);
	ctx.v7.s8[12] = ctx.v9.s8[12] >> (ctx.v13.u8[12] & 0x7);
	ctx.v7.s8[13] = ctx.v9.s8[13] >> (ctx.v13.u8[13] & 0x7);
	ctx.v7.s8[14] = ctx.v9.s8[14] >> (ctx.v13.u8[14] & 0x7);
	ctx.v7.s8[15] = ctx.v9.s8[15] >> (ctx.v13.u8[15] & 0x7);
	// vaddubm v6,v8,v0
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddubm v5,v7,v0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvx128 v6,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// stvx128 v5,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// bdnz 0x826e6978
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E6978;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826F2A30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x826f2a88
	if (ctx.cr6.eq) goto loc_826F2A88;
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// beq cr6,0x826f2a88
	if (ctx.cr6.eq) goto loc_826F2A88;
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// beq cr6,0x826f2a88
	if (ctx.cr6.eq) goto loc_826F2A88;
	// cmpwi cr6,r4,5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 5, ctx.xer);
	// beq cr6,0x826f2a88
	if (ctx.cr6.eq) goto loc_826F2A88;
	// li r10,16
	ctx.r10.s64 = 16;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// subf r9,r6,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r6.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826F2A6C:
	// lhzx r10,r9,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r11.u32);
	// sth r10,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bdnz 0x826f2a6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826F2A6C;
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_826F2A88:
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lbz r5,-20(r7)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r7.u32 + -20);
	// lwz r4,6576(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 6576);
	// lis r8,2
	ctx.r8.s64 = 131072;
	// addi r10,r11,17496
	ctx.r10.s64 = ctx.r11.s64 + 17496;
	// lbz r11,4(r7)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r7.u32 + 4);
	// rotlwi r30,r5,2
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// lhz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// rotlwi r31,r11,2
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// add r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 + ctx.r30.u64;
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r31,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// extsh r4,r3
	ctx.r4.s64 = ctx.r3.s16;
	// li r3,3
	ctx.r3.s64 = 3;
	// lwz r31,16(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// addi r11,r6,4
	ctx.r11.s64 = ctx.r6.s64 + 4;
	// lwz r30,16(r5)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r5.u32 + 16);
	// subf r5,r6,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r6.u64;
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
	// lwzx r3,r30,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// mullw r3,r3,r31
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r31.s32);
	// mullw r4,r3,r4
	ctx.r4.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// add r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 + ctx.r8.u64;
	// srawi r4,r3,18
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 18;
	// sth r4,0(r6)
	REX_STORE_U16(ctx.r6.u32 + 0, ctx.r4.u16);
loc_826F2AFC:
	// lbz r4,4(r7)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r7.u32 + 4);
	// lhz r3,2(r9)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r9.u32 + 2);
	// rotlwi r4,r4,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lbz r31,-20(r7)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r7.u32 + -20);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// lwzx r4,r4,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// mullw r4,r4,r31
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r31.s32);
	// mullw r3,r4,r3
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r3.s32);
	// add r4,r3,r8
	ctx.r4.u64 = ctx.r3.u64 + ctx.r8.u64;
	// srawi r3,r4,18
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3FFFF) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 18;
	// sth r3,-2(r11)
	REX_STORE_U16(ctx.r11.u32 + -2, ctx.r3.u16);
	// lhzx r3,r11,r5
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r5.u32);
	// lbz r4,-20(r7)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r7.u32 + -20);
	// lbz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r7.u32 + 4);
	// rotlwi r31,r31,2
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r31.u32, 2);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// lwzx r31,r31,r10
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// mullw r3,r31,r3
	ctx.r3.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r3.s32);
	// mullw r4,r3,r4
	ctx.r4.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// add r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 + ctx.r8.u64;
	// srawi r4,r3,18
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 18;
	// sth r4,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r4.u16);
	// lhz r4,6(r9)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r9.u32 + 6);
	// lbz r3,-20(r7)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r7.u32 + -20);
	// lbz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r7.u32 + 4);
	// rotlwi r31,r31,2
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r31.u32, 2);
	// lwzx r31,r31,r10
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// mullw r3,r31,r3
	ctx.r3.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r3.s32);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// mullw r3,r3,r4
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// add r4,r3,r8
	ctx.r4.u64 = ctx.r3.u64 + ctx.r8.u64;
	// srawi r3,r4,18
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3FFFF) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 18;
	// sth r3,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r3.u16);
	// lhz r3,8(r9)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r9.u32 + 8);
	// lbz r4,-20(r7)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r7.u32 + -20);
	// lbz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r7.u32 + 4);
	// rotlwi r31,r31,2
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r31.u32, 2);
	// lwzx r31,r31,r10
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// mullw r4,r31,r4
	ctx.r4.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r4.s32);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// mullw r4,r4,r3
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r3.s32);
	// add r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 + ctx.r8.u64;
	// srawi r4,r3,18
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 18;
	// sth r4,4(r11)
	REX_STORE_U16(ctx.r11.u32 + 4, ctx.r4.u16);
	// lbz r3,-20(r7)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r7.u32 + -20);
	// lhzu r4,10(r9)
	ea = 10 + ctx.r9.u32;
	ctx.r4.u64 = REX_LOAD_U16(ea);
	ctx.r9.u32 = ea;
	// lbz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r7.u32 + 4);
	// rotlwi r31,r31,2
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r31.u32, 2);
	// lwzx r31,r31,r10
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// mullw r3,r31,r3
	ctx.r3.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r3.s32);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// mullw r3,r3,r4
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// add r4,r3,r8
	ctx.r4.u64 = ctx.r3.u64 + ctx.r8.u64;
	// srawi r3,r4,18
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3FFFF) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 18;
	// sth r3,6(r11)
	REX_STORE_U16(ctx.r11.u32 + 6, ctx.r3.u16);
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// bdnz 0x826f2afc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826F2AFC;
	// lhz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r6.u32 + 0);
	// sth r11,16(r6)
	REX_STORE_U16(ctx.r6.u32 + 16, ctx.r11.u16);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82703558) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82703560;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// lbz r4,2148(r3)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r3.u32 + 2148);
	// lwz r31,84(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// subfic r11,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// lwz r29,2140(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 2140);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// clrldi r10,r11,32
	ctx.r10.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// srd r9,r11,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r10.u8 & 0x7F));
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82703ad0
	if (ctx.cr6.lt) goto loc_82703AD0;
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
	// bge cr6,0x82703658
	if (!ctx.cr6.lt) goto loc_82703658;
loc_827035C4:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827035ec
	if (ctx.cr6.lt) goto loc_827035EC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8ab8
	ctx.lr = 0x827035E0;
	sub_826C8AB8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x827035c4
	if (ctx.cr6.eq) goto loc_827035C4;
	// b 0x82703658
	goto loc_82703658;
loc_827035EC:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r9,r9,8,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFFFF;
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
loc_82703658:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82703b14
	if (ctx.cr6.lt) goto loc_82703B14;
loc_82703664:
	// cmpwi cr6,r30,63
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 63, ctx.xer);
	// bgt cr6,0x82703b14
	if (ctx.cr6.gt) goto loc_82703B14;
	// lwz r11,84(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 84);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82703b14
	if (!ctx.cr6.eq) goto loc_82703B14;
	// srawi r11,r30,5
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 5;
	// srawi r10,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r30.s32 >> 4;
	// srawi r9,r30,3
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r30.s32 >> 3;
	// srawi r8,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r30.s32 >> 2;
	// srawi r7,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r30.s32 >> 1;
	// clrlwi r6,r11,31
	ctx.r6.u64 = ctx.r11.u32 & 0x1;
	// clrlwi r5,r10,31
	ctx.r5.u64 = ctx.r10.u32 & 0x1;
	// clrlwi r4,r9,31
	ctx.r4.u64 = ctx.r9.u32 & 0x1;
	// stb r6,14(r24)
	REX_STORE_U8(ctx.r24.u32 + 14, ctx.r6.u8);
	// clrlwi r3,r8,31
	ctx.r3.u64 = ctx.r8.u32 & 0x1;
	// stb r5,15(r24)
	REX_STORE_U8(ctx.r24.u32 + 15, ctx.r5.u8);
	// clrlwi r11,r7,31
	ctx.r11.u64 = ctx.r7.u32 & 0x1;
	// stb r4,16(r24)
	REX_STORE_U8(ctx.r24.u32 + 16, ctx.r4.u8);
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// stb r3,17(r24)
	REX_STORE_U8(ctx.r24.u32 + 17, ctx.r3.u8);
	// stb r11,18(r24)
	REX_STORE_U8(ctx.r24.u32 + 18, ctx.r11.u8);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// stb r10,19(r24)
	REX_STORE_U8(ctx.r24.u32 + 19, ctx.r10.u8);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8270ab40
	ctx.lr = 0x827036D4;
	sub_8270AB40(ctx, base);
	// lwz r9,15504(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 15504);
	// cmpwi cr6,r9,7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 7, ctx.xer);
	// bne cr6,0x827036ec
	if (!ctx.cr6.eq) goto loc_827036EC;
	// lwz r11,20932(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 20932);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827037ac
	if (!ctx.cr6.eq) goto loc_827037AC;
loc_827036EC:
	// lwz r31,84(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + 84);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82703760
	if (!ctx.cr6.lt) goto loc_82703760;
loc_82703708:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82703760
	if (ctx.cr6.eq) goto loc_82703760;
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
	// bge 0x82703750
	if (!ctx.cr0.lt) goto loc_82703750;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82703750;
	sub_826C8B78(ctx, base);
loc_82703750:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82703708
	if (ctx.cr6.gt) goto loc_82703708;
loc_82703760:
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
	// bge 0x8270379c
	if (!ctx.cr0.lt) goto loc_8270379C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x8270379C;
	sub_826C8B78(ctx, base);
loc_8270379C:
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// clrlwi r10,r30,24
	ctx.r10.u64 = ctx.r30.u32 & 0xFF;
	// rlwimi r11,r10,3,27,28
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x18) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
loc_827037AC:
	// lwz r11,84(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 84);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82703b14
	if (!ctx.cr6.eq) goto loc_82703B14;
	// lis r12,32573
	ctx.r12.s64 = 2134704128;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// ori r12,r12,65535
	ctx.r12.u64 = ctx.r12.u64 | 65535;
	// and r10,r11,r12
	ctx.r10.u64 = ctx.r11.u64 & ctx.r12.u64;
	// stw r10,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
	// lbz r9,15(r24)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r24.u32 + 15);
	// lbz r8,16(r24)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r24.u32 + 16);
	// lwz r4,392(r25)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r25.u32 + 392);
	// lbz r7,17(r24)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r24.u32 + 17);
	// lbz r6,18(r24)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r24.u32 + 18);
	// lbz r5,19(r24)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r24.u32 + 19);
	// lbz r3,14(r24)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r24.u32 + 14);
	// rotlwi r11,r3,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// or r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 | ctx.r9.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// or r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 | ctx.r8.u64;
	// rlwinm r4,r8,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// or r3,r4,r7
	ctx.r3.u64 = ctx.r4.u64 | ctx.r7.u64;
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// or r10,r11,r6
	ctx.r10.u64 = ctx.r11.u64 | ctx.r6.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// or r11,r9,r5
	ctx.r11.u64 = ctx.r9.u64 | ctx.r5.u64;
	// beq cr6,0x827039a0
	if (ctx.cr6.eq) goto loc_827039A0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827039a0
	if (ctx.cr6.eq) goto loc_827039A0;
	// lwz r31,84(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + 84);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82703898
	if (!ctx.cr6.lt) goto loc_82703898;
loc_82703840:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82703898
	if (ctx.cr6.eq) goto loc_82703898;
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
	// bge 0x82703888
	if (!ctx.cr0.lt) goto loc_82703888;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82703888;
	sub_826C8B78(ctx, base);
loc_82703888:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82703840
	if (ctx.cr6.gt) goto loc_82703840;
loc_82703898:
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
	// bge 0x827038d4
	if (!ctx.cr0.lt) goto loc_827038D4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x827038D4;
	sub_826C8B78(ctx, base);
loc_827038D4:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82703994
	if (ctx.cr6.eq) goto loc_82703994;
	// lwz r31,84(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + 84);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82703954
	if (!ctx.cr6.lt) goto loc_82703954;
loc_827038FC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82703954
	if (ctx.cr6.eq) goto loc_82703954;
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
	// bge 0x82703944
	if (!ctx.cr0.lt) goto loc_82703944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82703944;
	sub_826C8B78(ctx, base);
loc_82703944:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827038fc
	if (ctx.cr6.gt) goto loc_827038FC;
loc_82703954:
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
	// bge 0x82703990
	if (!ctx.cr0.lt) goto loc_82703990;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82703990;
	sub_826C8B78(ctx, base);
loc_82703990:
	// add r11,r30,r28
	ctx.r11.u64 = ctx.r30.u64 + ctx.r28.u64;
loc_82703994:
	// lwz r10,0(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// rlwimi r10,r11,22,8,9
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 22) & 0xC00000) | (ctx.r10.u64 & 0xFFFFFFFFFF3FFFFF);
	// stw r10,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
loc_827039A0:
	// lwz r11,2992(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 2992);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82703a80
	if (ctx.cr6.eq) goto loc_82703A80;
	// lwz r11,21868(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 21868);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82703a80
	if (!ctx.cr6.eq) goto loc_82703A80;
	// lwz r31,84(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + 84);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82703a30
	if (!ctx.cr6.lt) goto loc_82703A30;
loc_827039D8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82703a30
	if (ctx.cr6.eq) goto loc_82703A30;
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
	// bge 0x82703a20
	if (!ctx.cr0.lt) goto loc_82703A20;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82703A20;
	sub_826C8B78(ctx, base);
loc_82703A20:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827039d8
	if (ctx.cr6.gt) goto loc_827039D8;
loc_82703A30:
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
	// bge 0x82703a6c
	if (!ctx.cr0.lt) goto loc_82703A6C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82703A6C;
	sub_826C8B78(ctx, base);
loc_82703A6C:
	// addic r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// lwz r10,0(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// subfe r9,r11,r30
	temp.u8 = (~ctx.r11.u32 + ctx.r30.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r10,r9,11,20,20
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 11) & 0x800) | (ctx.r10.u64 & 0xFFFFFFFFFFFFF7FF);
	// stw r10,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
loc_82703A80:
	// lwz r11,20984(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 20984);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82703ac4
	if (ctx.cr6.eq) goto loc_82703AC4;
	// lwz r11,248(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 248);
	// lwz r10,252(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 252);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r10,r11,255
	ctx.r10.s64 = ctx.r11.s64 + 255;
	// stb r10,4(r24)
	REX_STORE_U8(ctx.r24.u32 + 4, ctx.r10.u8);
	// lwz r8,280(r25)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r25.u32 + 280);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82703ac4
	if (ctx.cr6.eq) goto loc_82703AC4;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82702140
	ctx.lr = 0x82703ABC;
	sub_82702140(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82703b14
	if (!ctx.cr6.eq) goto loc_82703B14;
loc_82703AC4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
loc_82703AD0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8c48
	ctx.lr = 0x82703AD8;
	sub_826C8C48(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r28,r11,32768
	ctx.r28.u64 = ctx.r11.u64 | 32768;
loc_82703AE0:
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
	ctx.lr = 0x82703AF8;
	sub_826C8C48(ctx, base);
	// add r10,r30,r28
	ctx.r10.u64 = ctx.r30.u64 + ctx.r28.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82703ae0
	if (ctx.cr6.lt) goto loc_82703AE0;
	// b 0x82703664
	goto loc_82703664;
loc_82703B14:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8272EEC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x8272EED0;
	__savegprlr_14(ctx, base);
	// stwu r1,-1264(r1)
	ea = -1264 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r8,r8,30
	ctx.r8.u64 = ctx.r8.u32 & 0x3;
	// stw r7,1316(r1)
	REX_STORE_U32(ctx.r1.u32 + 1316, ctx.r7.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// clrlwi r3,r9,30
	ctx.r3.u64 = ctx.r9.u32 & 0x3;
	// addi r10,r10,18296
	ctx.r10.s64 = ctx.r10.s64 + 18296;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r3,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8272f1b0
	if (!ctx.cr6.eq) goto loc_8272F1B0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8272ef34
	if (!ctx.cr6.eq) goto loc_8272EF34;
	// lwz r11,1356(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 1356);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8272f72c
	if (!ctx.cr6.gt) goto loc_8272F72C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// subf r11,r5,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r5.u64;
	// subf r10,r7,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r7.u64;
loc_8272EF20:
	// ldux r9,r11,r5
	ea = ctx.r11.u32 + ctx.r5.u32;
	ctx.r9.u64 = REX_LOAD_U64(ea);
	ctx.r11.u32 = ea;
	// stdux r9,r10,r7
	ea = ctx.r10.u32 + ctx.r7.u32;
	REX_STORE_U64(ea, ctx.r9.u64);
	ctx.r10.u32 = ea;
	// bdnz 0x8272ef20
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8272EF20;
	// addi r1,r1,1264
	ctx.r1.s64 = ctx.r1.s64 + 1264;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_8272EF34:
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// li r3,4
	ctx.r3.s64 = 4;
	// beq cr6,0x8272ef44
	if (ctx.cr6.eq) goto loc_8272EF44;
	// li r3,6
	ctx.r3.s64 = 6;
loc_8272EF44:
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// lwz r11,1348(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 1348);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r30,1356(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 1356);
	// slw r9,r8,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r11,-1
	ctx.r31.s64 = ctx.r11.s64 + -1;
	// ble cr6,0x8272f72c
	if (!ctx.cr6.gt) goto loc_8272F72C;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// subfic r28,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r28.u64 = static_cast<uint64_t>(1) - ctx.r11.u64;
	// add r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 + ctx.r9.u64;
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// subfic r27,r11,2
	ctx.xer.ca = ctx.r11.u32 <= 2;
	ctx.r27.u64 = static_cast<uint64_t>(2) - ctx.r11.u64;
	// subfic r26,r11,3
	ctx.xer.ca = ctx.r11.u32 <= 3;
	ctx.r26.u64 = static_cast<uint64_t>(3) - ctx.r11.u64;
	// subf r24,r11,r9
	ctx.r24.u64 = ctx.r9.u64 - ctx.r11.u64;
	// subf r25,r5,r9
	ctx.r25.u64 = ctx.r9.u64 - ctx.r5.u64;
	// subfic r23,r5,-1
	ctx.xer.ca = ctx.r5.u32 <= 4294967295;
	ctx.r23.u64 = static_cast<uint64_t>(-1) - ctx.r5.u64;
	// addi r22,r4,1
	ctx.r22.s64 = ctx.r4.s64 + 1;
	// addi r21,r6,1
	ctx.r21.s64 = ctx.r6.s64 + 1;
	// addi r20,r8,3
	ctx.r20.s64 = ctx.r8.s64 + 3;
	// addi r19,r5,-1
	ctx.r19.s64 = ctx.r5.s64 + -1;
loc_8272EFA0:
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r4,r21,-2
	ctx.r4.s64 = ctx.r21.s64 + -2;
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// add r11,r19,r22
	ctx.r11.u64 = ctx.r19.u64 + ctx.r22.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8272EFB8:
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// lhz r7,6(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// lbzx r6,r9,r23
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r23.u32);
	// lbzx r18,r24,r11
	ctx.r18.u64 = REX_LOAD_U8(ctx.r24.u32 + ctx.r11.u32);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// lhz r17,2(r10)
	ctx.r17.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// mullw r6,r6,r8
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// lbz r16,-1(r9)
	ctx.r16.u64 = REX_LOAD_U8(ctx.r9.u32 + -1);
	// lhz r15,4(r10)
	ctx.r15.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// lbz r14,0(r11)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// mullw r8,r18,r7
	ctx.r8.s64 = int64_t(ctx.r18.s32) * int64_t(ctx.r7.s32);
	// extsh r7,r17
	ctx.r7.s64 = ctx.r17.s16;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// mullw r8,r16,r7
	ctx.r8.s64 = int64_t(ctx.r16.s32) * int64_t(ctx.r7.s32);
	// extsh r7,r15
	ctx.r7.s64 = ctx.r15.s16;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// mullw r8,r14,r7
	ctx.r8.s64 = int64_t(ctx.r14.s32) * int64_t(ctx.r7.s32);
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// add r6,r8,r31
	ctx.r6.u64 = ctx.r8.u64 + ctx.r31.u64;
	// sraw. r8,r6,r3
	temp.u32 = ctx.r3.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r6.s32 < 0) & (((ctx.r6.s32 >> temp.u32) << temp.u32) != ctx.r6.s32);
	ctx.r8.s64 = ctx.r6.s32 >> temp.u32;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge 0x8272f018
	if (!ctx.cr0.lt) goto loc_8272F018;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8272f024
	goto loc_8272F024;
loc_8272F018:
	// cmpwi cr6,r8,255
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 255, ctx.xer);
	// ble cr6,0x8272f024
	if (!ctx.cr6.gt) goto loc_8272F024;
	// li r8,255
	ctx.r8.s64 = 255;
loc_8272F024:
	// stb r8,1(r4)
	REX_STORE_U8(ctx.r4.u32 + 1, ctx.r8.u8);
	// lhz r14,6(r10)
	ctx.r14.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// lbzx r6,r25,r9
	ctx.r6.u64 = REX_LOAD_U8(ctx.r25.u32 + ctx.r9.u32);
	// lbzx r8,r28,r11
	ctx.r8.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r11.u32);
	// lhz r18,4(r10)
	ctx.r18.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// lbz r17,1(r11)
	ctx.r17.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lhz r16,2(r10)
	ctx.r16.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// lbz r15,0(r9)
	ctx.r15.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lhz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// extsh r14,r14
	ctx.r14.s64 = ctx.r14.s16;
	// mullw r8,r8,r7
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// mullw r6,r6,r14
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r14.s32);
	// extsh r7,r18
	ctx.r7.s64 = ctx.r18.s16;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// mullw r8,r17,r7
	ctx.r8.s64 = int64_t(ctx.r17.s32) * int64_t(ctx.r7.s32);
	// extsh r7,r16
	ctx.r7.s64 = ctx.r16.s16;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// mullw r8,r7,r15
	ctx.r8.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r15.s32);
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// add r6,r8,r31
	ctx.r6.u64 = ctx.r8.u64 + ctx.r31.u64;
	// sraw. r8,r6,r3
	temp.u32 = ctx.r3.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r6.s32 < 0) & (((ctx.r6.s32 >> temp.u32) << temp.u32) != ctx.r6.s32);
	ctx.r8.s64 = ctx.r6.s32 >> temp.u32;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge 0x8272f088
	if (!ctx.cr0.lt) goto loc_8272F088;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8272f094
	goto loc_8272F094;
loc_8272F088:
	// cmpwi cr6,r8,255
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 255, ctx.xer);
	// ble cr6,0x8272f094
	if (!ctx.cr6.gt) goto loc_8272F094;
	// li r8,255
	ctx.r8.s64 = 255;
loc_8272F094:
	// stb r8,2(r4)
	REX_STORE_U8(ctx.r4.u32 + 2, ctx.r8.u8);
	// lhz r16,6(r10)
	ctx.r16.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// lbzx r18,r27,r11
	ctx.r18.u64 = REX_LOAD_U8(ctx.r27.u32 + ctx.r11.u32);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// lhz r6,4(r10)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// lbz r7,2(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// mullw r8,r18,r8
	ctx.r8.s64 = int64_t(ctx.r18.s32) * int64_t(ctx.r8.s32);
	// lbz r18,-1(r29)
	ctx.r18.u64 = REX_LOAD_U8(ctx.r29.u32 + -1);
	// lhz r17,2(r10)
	ctx.r17.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// extsh r17,r17
	ctx.r17.s64 = ctx.r17.s16;
	// mullw r6,r7,r6
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// lbz r7,1(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// mullw r6,r7,r17
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r17.s32);
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// extsh r18,r16
	ctx.r18.s64 = ctx.r16.s16;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// mullw r6,r7,r18
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r18.s32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// add r6,r8,r31
	ctx.r6.u64 = ctx.r8.u64 + ctx.r31.u64;
	// sraw. r8,r6,r3
	temp.u32 = ctx.r3.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r6.s32 < 0) & (((ctx.r6.s32 >> temp.u32) << temp.u32) != ctx.r6.s32);
	ctx.r8.s64 = ctx.r6.s32 >> temp.u32;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge 0x8272f0fc
	if (!ctx.cr0.lt) goto loc_8272F0FC;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8272f108
	goto loc_8272F108;
loc_8272F0FC:
	// cmpwi cr6,r8,255
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 255, ctx.xer);
	// ble cr6,0x8272f108
	if (!ctx.cr6.gt) goto loc_8272F108;
	// li r8,255
	ctx.r8.s64 = 255;
loc_8272F108:
	// stb r8,3(r4)
	REX_STORE_U8(ctx.r4.u32 + 3, ctx.r8.u8);
	// lbz r16,3(r11)
	ctx.r16.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbzx r17,r26,r11
	ctx.r17.u64 = REX_LOAD_U8(ctx.r26.u32 + ctx.r11.u32);
	// lbz r15,0(r29)
	ctx.r15.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// lhz r6,2(r10)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// lhz r7,6(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// extsh r18,r6
	ctx.r18.s64 = ctx.r6.s16;
	// lhz r6,4(r10)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// mullw r8,r17,r8
	ctx.r8.s64 = int64_t(ctx.r17.s32) * int64_t(ctx.r8.s32);
	// lbz r17,2(r9)
	ctx.r17.u64 = REX_LOAD_U8(ctx.r9.u32 + 2);
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// mullw r6,r16,r6
	ctx.r6.s64 = int64_t(ctx.r16.s32) * int64_t(ctx.r6.s32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// mullw r6,r17,r18
	ctx.r6.s64 = int64_t(ctx.r17.s32) * int64_t(ctx.r18.s32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// mullw r6,r15,r7
	ctx.r6.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r7.s32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// mr r18,r15
	ctx.r18.u64 = ctx.r15.u64;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// sraw. r8,r8,r3
	temp.u32 = ctx.r3.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r8.s64 = ctx.r8.s32 >> temp.u32;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge 0x8272f170
	if (!ctx.cr0.lt) goto loc_8272F170;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8272f17c
	goto loc_8272F17C;
loc_8272F170:
	// cmpwi cr6,r8,255
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 255, ctx.xer);
	// ble cr6,0x8272f17c
	if (!ctx.cr6.gt) goto loc_8272F17C;
	// li r8,255
	ctx.r8.s64 = 255;
loc_8272F17C:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stbu r8,4(r4)
	ea = 4 + ctx.r4.u32;
	REX_STORE_U8(ea, ctx.r8.u8);
	ctx.r4.u32 = ea;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bdnz 0x8272efb8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8272EFB8;
	// lwz r11,1316(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 1316);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// add r22,r22,r5
	ctx.r22.u64 = ctx.r22.u64 + ctx.r5.u64;
	// add r21,r21,r11
	ctx.r21.u64 = ctx.r21.u64 + ctx.r11.u64;
	// add r20,r20,r5
	ctx.r20.u64 = ctx.r20.u64 + ctx.r5.u64;
	// bne 0x8272efa0
	if (!ctx.cr0.eq) goto loc_8272EFA0;
	// addi r1,r1,1264
	ctx.r1.s64 = ctx.r1.s64 + 1264;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_8272F1B0:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8272f3e4
	if (!ctx.cr6.eq) goto loc_8272F3E4;
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// li r3,4
	ctx.r3.s64 = 4;
	// beq cr6,0x8272f1c8
	if (ctx.cr6.eq) goto loc_8272F1C8;
	// li r3,6
	ctx.r3.s64 = 6;
loc_8272F1C8:
	// li r31,1
	ctx.r31.s64 = 1;
	// lwz r8,1348(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 1348);
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// lwz r10,1356(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 1356);
	// slw r9,r31,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r31.u32 << (ctx.r9.u8 & 0x3F));
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r31,r8,r9
	ctx.r31.u64 = ctx.r9.u64 - ctx.r8.u64;
	// ble cr6,0x8272f72c
	if (!ctx.cr6.gt) goto loc_8272F72C;
	// addi r30,r4,1
	ctx.r30.s64 = ctx.r4.s64 + 1;
	// addi r4,r6,1
	ctx.r4.s64 = ctx.r6.s64 + 1;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
loc_8272F1F4:
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r6,r4,-2
	ctx.r6.s64 = ctx.r4.s64 + -2;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8272F204:
	// lhz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// lbz r28,-2(r10)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r10.u32 + -2);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// lbz r27,0(r10)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// lhz r26,6(r11)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// mullw r9,r28,r9
	ctx.r9.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// lbz r28,1(r10)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// lhz r25,2(r11)
	ctx.r25.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// lbz r24,-1(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + -1);
	// mullw r8,r8,r27
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r27.s32);
	// extsh r27,r26
	ctx.r27.s64 = ctx.r26.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r28,r27
	ctx.r8.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r27.s32);
	// extsh r28,r25
	ctx.r28.s64 = ctx.r25.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r24,r28
	ctx.r8.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r28.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// sraw. r9,r9,r3
	temp.u32 = ctx.r3.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r9.s32 < 0) & (((ctx.r9.s32 >> temp.u32) << temp.u32) != ctx.r9.s32);
	ctx.r9.s64 = ctx.r9.s32 >> temp.u32;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge 0x8272f264
	if (!ctx.cr0.lt) goto loc_8272F264;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8272f270
	goto loc_8272F270;
loc_8272F264:
	// cmpwi cr6,r9,255
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 255, ctx.xer);
	// ble cr6,0x8272f270
	if (!ctx.cr6.gt) goto loc_8272F270;
	// li r9,255
	ctx.r9.s64 = 255;
loc_8272F270:
	// stb r9,1(r6)
	REX_STORE_U8(ctx.r6.u32 + 1, ctx.r9.u8);
	// lhz r24,2(r11)
	ctx.r24.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// lbz r23,0(r10)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lhz r25,0(r11)
	ctx.r25.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// lhz r9,6(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// extsh r27,r8
	ctx.r27.s64 = ctx.r8.s16;
	// lbz r28,2(r10)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// lbz r26,1(r10)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// mullw r8,r28,r8
	ctx.r8.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r8.s32);
	// lbz r28,-1(r10)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r10.u32 + -1);
	// mullw r9,r27,r26
	ctx.r9.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r26.s32);
	// extsh r27,r25
	ctx.r27.s64 = ctx.r25.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r28,r27
	ctx.r8.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r27.s32);
	// extsh r28,r24
	ctx.r28.s64 = ctx.r24.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r23,r28
	ctx.r8.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r28.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// sraw. r9,r9,r3
	temp.u32 = ctx.r3.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r9.s32 < 0) & (((ctx.r9.s32 >> temp.u32) << temp.u32) != ctx.r9.s32);
	ctx.r9.s64 = ctx.r9.s32 >> temp.u32;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge 0x8272f2d4
	if (!ctx.cr0.lt) goto loc_8272F2D4;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8272f2e0
	goto loc_8272F2E0;
loc_8272F2D4:
	// cmpwi cr6,r9,255
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 255, ctx.xer);
	// ble cr6,0x8272f2e0
	if (!ctx.cr6.gt) goto loc_8272F2E0;
	// li r9,255
	ctx.r9.s64 = 255;
loc_8272F2E0:
	// stb r9,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r9.u8);
	// lhz r25,2(r11)
	ctx.r25.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// lhz r8,6(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// lhz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// lbz r28,2(r10)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// lbz r27,3(r10)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// lhz r26,0(r11)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// mullw r9,r9,r28
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r28.s32);
	// lbz r24,1(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// mullw r8,r8,r27
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r27.s32);
	// lbz r27,0(r10)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// extsh r28,r26
	ctx.r28.s64 = ctx.r26.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r27,r28
	ctx.r8.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r28.s32);
	// extsh r28,r25
	ctx.r28.s64 = ctx.r25.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r24,r28
	ctx.r8.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r28.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r8,r9,r31
	ctx.r8.u64 = ctx.r9.u64 + ctx.r31.u64;
	// sraw. r9,r8,r3
	temp.u32 = ctx.r3.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r9.s64 = ctx.r8.s32 >> temp.u32;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge 0x8272f344
	if (!ctx.cr0.lt) goto loc_8272F344;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8272f350
	goto loc_8272F350;
loc_8272F344:
	// cmpwi cr6,r9,255
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 255, ctx.xer);
	// ble cr6,0x8272f350
	if (!ctx.cr6.gt) goto loc_8272F350;
	// li r9,255
	ctx.r9.s64 = 255;
loc_8272F350:
	// stb r9,3(r6)
	REX_STORE_U8(ctx.r6.u32 + 3, ctx.r9.u8);
	// lbz r23,2(r10)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// lhz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r9,6(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// extsh r28,r8
	ctx.r28.s64 = ctx.r8.s16;
	// lhz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// lbz r26,4(r10)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r10.u32 + 4);
	// lbz r27,3(r10)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// extsh r25,r8
	ctx.r25.s64 = ctx.r8.s16;
	// mullw r8,r26,r9
	ctx.r8.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r9.s32);
	// lbz r24,1(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// lhz r26,2(r11)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// mullw r9,r25,r27
	ctx.r9.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r27.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r24,r28
	ctx.r8.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r28.s32);
	// extsh r28,r26
	ctx.r28.s64 = ctx.r26.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r23,r28
	ctx.r8.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r28.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r8,r9,r31
	ctx.r8.u64 = ctx.r9.u64 + ctx.r31.u64;
	// sraw. r9,r8,r3
	temp.u32 = ctx.r3.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r9.s64 = ctx.r8.s32 >> temp.u32;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge 0x8272f3b4
	if (!ctx.cr0.lt) goto loc_8272F3B4;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8272f3c0
	goto loc_8272F3C0;
loc_8272F3B4:
	// cmpwi cr6,r9,255
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 255, ctx.xer);
	// ble cr6,0x8272f3c0
	if (!ctx.cr6.gt) goto loc_8272F3C0;
	// li r9,255
	ctx.r9.s64 = 255;
loc_8272F3C0:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stbu r9,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r6.u32 = ea;
	// bdnz 0x8272f204
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8272F204;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// add r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 + ctx.r7.u64;
	// add r30,r30,r5
	ctx.r30.u64 = ctx.r30.u64 + ctx.r5.u64;
	// bne 0x8272f1f4
	if (!ctx.cr0.eq) goto loc_8272F1F4;
	// addi r1,r1,1264
	ctx.r1.s64 = ctx.r1.s64 + 1264;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_8272F3E4:
	// addi r9,r1,47
	ctx.r9.s64 = ctx.r1.s64 + 47;
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// rlwinm r19,r9,0,0,26
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFE0;
	// li r8,4
	ctx.r8.s64 = 4;
	// mr r21,r19
	ctx.r21.u64 = ctx.r19.u64;
	// beq cr6,0x8272f400
	if (ctx.cr6.eq) goto loc_8272F400;
	// li r8,6
	ctx.r8.s64 = 6;
loc_8272F400:
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// li r9,4
	ctx.r9.s64 = 4;
	// beq cr6,0x8272f410
	if (ctx.cr6.eq) goto loc_8272F410;
	// li r9,6
	ctx.r9.s64 = 6;
loc_8272F410:
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwz r8,1348(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 1348);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r20,1356(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 1356);
	// addi r27,r9,-7
	ctx.r27.s64 = ctx.r9.s64 + -7;
	// subfic r25,r8,64
	ctx.xer.ca = ctx.r8.u32 <= 64;
	ctx.r25.u64 = static_cast<uint64_t>(64) - ctx.r8.u64;
	// addi r9,r27,-1
	ctx.r9.s64 = ctx.r27.s64 + -1;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// slw r9,r3,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r9.u8 & 0x3F));
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r26,r9,-1
	ctx.r26.s64 = ctx.r9.s64 + -1;
	// ble cr6,0x8272f72c
	if (!ctx.cr6.gt) goto loc_8272F72C;
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r31,r5,r9
	ctx.r31.u64 = ctx.r5.u64 + ctx.r9.u64;
	// add r9,r4,r5
	ctx.r9.u64 = ctx.r4.u64 + ctx.r5.u64;
	// subf r8,r5,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r5.u64;
	// subf r29,r3,r31
	ctx.r29.u64 = ctx.r31.u64 - ctx.r3.u64;
	// subf r28,r3,r5
	ctx.r28.u64 = ctx.r5.u64 - ctx.r3.u64;
	// addi r23,r9,-1
	ctx.r23.s64 = ctx.r9.s64 + -1;
	// addi r24,r8,-1
	ctx.r24.s64 = ctx.r8.s64 + -1;
	// mr r22,r20
	ctx.r22.u64 = ctx.r20.u64;
loc_8272F468:
	// li r3,11
	ctx.r3.s64 = 11;
	// addi r4,r21,-2
	ctx.r4.s64 = ctx.r21.s64 + -2;
	// addi r8,r24,-1
	ctx.r8.s64 = ctx.r24.s64 + -1;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
loc_8272F47C:
	// lhz r3,6(r10)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// lhz r31,2(r10)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// lbzx r30,r29,r9
	ctx.r30.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r9.u32);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// lbzx r18,r28,r9
	ctx.r18.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r9.u32);
	// extsh r17,r31
	ctx.r17.s64 = ctx.r31.s16;
	// lhz r16,4(r10)
	ctx.r16.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// mullw r31,r30,r3
	ctx.r31.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r3.s32);
	// lbz r15,0(r9)
	ctx.r15.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lbzu r3,1(r8)
	ea = 1 + ctx.r8.u32;
	ctx.r3.u64 = REX_LOAD_U8(ea);
	ctx.r8.u32 = ea;
	// lhz r14,0(r10)
	ctx.r14.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// mullw r30,r18,r17
	ctx.r30.s64 = int64_t(ctx.r18.s32) * int64_t(ctx.r17.s32);
	// extsh r18,r16
	ctx.r18.s64 = ctx.r16.s16;
	// add r31,r31,r30
	ctx.r31.u64 = ctx.r31.u64 + ctx.r30.u64;
	// mullw r30,r15,r18
	ctx.r30.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r18.s32);
	// mr r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	// extsh r17,r14
	ctx.r17.s64 = ctx.r14.s16;
	// add r3,r31,r30
	ctx.r3.u64 = ctx.r31.u64 + ctx.r30.u64;
	// mullw r31,r18,r17
	ctx.r31.s64 = int64_t(ctx.r18.s32) * int64_t(ctx.r17.s32);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r3,r3,r26
	ctx.r3.u64 = ctx.r3.u64 + ctx.r26.u64;
	// sraw r3,r3,r27
	temp.u32 = ctx.r27.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r3.s32 < 0) & (((ctx.r3.s32 >> temp.u32) << temp.u32) != ctx.r3.s32);
	ctx.r3.s64 = ctx.r3.s32 >> temp.u32;
	// sthu r3,2(r4)
	ea = 2 + ctx.r4.u32;
	REX_STORE_U16(ea, ctx.r3.u16);
	ctx.r4.u32 = ea;
	// bdnz 0x8272f47c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8272F47C;
	// addic. r22,r22,-1
	ctx.xer.ca = ctx.r22.u32 > 0;
	ctx.r22.s64 = ctx.r22.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// add r24,r24,r5
	ctx.r24.u64 = ctx.r24.u64 + ctx.r5.u64;
	// add r23,r23,r5
	ctx.r23.u64 = ctx.r23.u64 + ctx.r5.u64;
	// addi r21,r21,64
	ctx.r21.s64 = ctx.r21.s64 + 64;
	// bne 0x8272f468
	if (!ctx.cr0.eq) goto loc_8272F468;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// ble cr6,0x8272f72c
	if (!ctx.cr6.gt) goto loc_8272F72C;
	// addi r5,r19,4
	ctx.r5.s64 = ctx.r19.s64 + 4;
	// addi r4,r6,1
	ctx.r4.s64 = ctx.r6.s64 + 1;
loc_8272F504:
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r6,r4,-2
	ctx.r6.s64 = ctx.r4.s64 + -2;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8272F514:
	// lhz r9,-4(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + -4);
	// lhz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r3,6(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// lhz r31,2(r10)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// lhz r30,0(r10)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// extsh r31,r31
	ctx.r31.s64 = ctx.r31.s16;
	// lhz r29,4(r11)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// lhz r28,-2(r10)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r10.u32 + -2);
	// lhz r27,2(r11)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// mullw r8,r31,r3
	ctx.r8.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r3.s32);
	// extsh r3,r30
	ctx.r3.s64 = ctx.r30.s16;
	// extsh r31,r29
	ctx.r31.s64 = ctx.r29.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r3,r31
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r31.s32);
	// extsh r3,r28
	ctx.r3.s64 = ctx.r28.s16;
	// extsh r31,r27
	ctx.r31.s64 = ctx.r27.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r3,r31
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r31.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// srawi. r9,r9,7
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 7;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge 0x8272f584
	if (!ctx.cr0.lt) goto loc_8272F584;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8272f590
	goto loc_8272F590;
loc_8272F584:
	// cmpwi cr6,r9,255
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 255, ctx.xer);
	// ble cr6,0x8272f590
	if (!ctx.cr6.gt) goto loc_8272F590;
	// li r9,255
	ctx.r9.s64 = 255;
loc_8272F590:
	// stb r9,1(r6)
	REX_STORE_U8(ctx.r6.u32 + 1, ctx.r9.u8);
	// lhz r29,6(r11)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// lhz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r31,r31
	ctx.r31.s64 = ctx.r31.s16;
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// extsh r29,r29
	ctx.r29.s64 = ctx.r29.s16;
	// lhz r9,-2(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + -2);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// lhz r8,4(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// lhz r27,2(r10)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// extsh r28,r8
	ctx.r28.s64 = ctx.r8.s16;
	// lhz r26,4(r11)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// mullw r8,r9,r31
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r31.s32);
	// lhz r3,2(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// mullw r9,r28,r29
	ctx.r9.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r29.s32);
	// extsh r31,r27
	ctx.r31.s64 = ctx.r27.s16;
	// extsh r29,r26
	ctx.r29.s64 = ctx.r26.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r31,r29
	ctx.r8.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r29.s32);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r30,r3
	ctx.r8.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r3.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// srawi. r9,r9,7
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 7;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge 0x8272f604
	if (!ctx.cr0.lt) goto loc_8272F604;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8272f610
	goto loc_8272F610;
loc_8272F604:
	// cmpwi cr6,r9,255
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 255, ctx.xer);
	// ble cr6,0x8272f610
	if (!ctx.cr6.gt) goto loc_8272F610;
	// li r9,255
	ctx.r9.s64 = 255;
loc_8272F610:
	// stb r9,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r9.u8);
	// lhz r9,6(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// lhz r8,6(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// lhz r31,0(r10)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// lhz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// extsh r31,r31
	ctx.r31.s64 = ctx.r31.s16;
	// lhz r29,4(r10)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// extsh r30,r30
	ctx.r30.s64 = ctx.r30.s16;
	// lhz r28,4(r11)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// lhz r3,2(r10)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// lhz r27,2(r11)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// mullw r8,r31,r30
	ctx.r8.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r30.s32);
	// extsh r31,r29
	ctx.r31.s64 = ctx.r29.s16;
	// extsh r30,r28
	ctx.r30.s64 = ctx.r28.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r31,r30
	ctx.r8.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r30.s32);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// extsh r31,r27
	ctx.r31.s64 = ctx.r27.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r3,r31
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r31.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// srawi. r9,r9,7
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 7;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge 0x8272f684
	if (!ctx.cr0.lt) goto loc_8272F684;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8272f690
	goto loc_8272F690;
loc_8272F684:
	// cmpwi cr6,r9,255
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 255, ctx.xer);
	// ble cr6,0x8272f690
	if (!ctx.cr6.gt) goto loc_8272F690;
	// li r9,255
	ctx.r9.s64 = 255;
loc_8272F690:
	// stb r9,3(r6)
	REX_STORE_U8(ctx.r6.u32 + 3, ctx.r9.u8);
	// lhz r8,8(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// lhz r3,6(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// lhz r9,2(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// lhz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// extsh r30,r9
	ctx.r30.s64 = ctx.r9.s16;
	// lhz r29,6(r10)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// extsh r31,r31
	ctx.r31.s64 = ctx.r31.s16;
	// lhz r28,4(r11)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// mullw r9,r8,r3
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r3.s32);
	// lhz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// lhz r27,2(r11)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// mullw r8,r30,r31
	ctx.r8.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r31.s32);
	// extsh r31,r29
	ctx.r31.s64 = ctx.r29.s16;
	// extsh r30,r28
	ctx.r30.s64 = ctx.r28.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r31,r30
	ctx.r8.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r30.s32);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// extsh r31,r27
	ctx.r31.s64 = ctx.r27.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r3,r31
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r31.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// srawi. r9,r9,7
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 7;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge 0x8272f704
	if (!ctx.cr0.lt) goto loc_8272F704;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8272f710
	goto loc_8272F710;
loc_8272F704:
	// cmpwi cr6,r9,255
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 255, ctx.xer);
	// ble cr6,0x8272f710
	if (!ctx.cr6.gt) goto loc_8272F710;
	// li r9,255
	ctx.r9.s64 = 255;
loc_8272F710:
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stbu r9,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r6.u32 = ea;
	// bdnz 0x8272f514
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8272F514;
	// addic. r20,r20,-1
	ctx.xer.ca = ctx.r20.u32 > 0;
	ctx.r20.s64 = ctx.r20.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// addi r5,r5,64
	ctx.r5.s64 = ctx.r5.s64 + 64;
	// add r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 + ctx.r7.u64;
	// bne 0x8272f504
	if (!ctx.cr0.eq) goto loc_8272F504;
loc_8272F72C:
	// addi r1,r1,1264
	ctx.r1.s64 = ctx.r1.s64 + 1264;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8274376C) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-144
	ctx.r31.s64 = ctx.r12.s64 + -144;
	// std r27,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r27.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,164(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// b 0x827437a4
	goto loc_827437A4;
loc_827437A4:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82745a68
	ctx.lr = 0x827437AC;
	sub_82745A68(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// ld r27,-16(r1)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82745218) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8274526c
	if (!ctx.cr6.eq) goto loc_8274526C;
loc_82745240:
	// bl 0x8273dc40
	ctx.lr = 0x82745244;
	sub_8273DC40(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8273db00
	ctx.lr = 0x82745264;
	sub_8273DB00(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82745330
	goto loc_82745330;
loc_8274526C:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8274527c
	if (ctx.cr6.eq) goto loc_8274527C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82745240
	if (ctx.cr6.eq) goto loc_82745240;
loc_8274527C:
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// li r9,66
	ctx.r9.s64 = 66;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x827452a8
	if (!ctx.cr6.gt) goto loc_827452A8;
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// b 0x827452ac
	goto loc_827452AC;
loc_827452A8:
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
loc_827452AC:
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8273fc18
	ctx.lr = 0x827452C0;
	sub_8273FC18(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8274532c
	if (ctx.cr6.eq) goto loc_8274532C;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r31,0
	ctx.r31.s64 = 0;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// blt 0x827452f8
	if (ctx.cr0.lt) goto loc_827452F8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stb r31,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r31.u8);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// b 0x82745308
	goto loc_82745308;
loc_827452F8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8273dd20
	ctx.lr = 0x82745304;
	sub_8273DD20(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_82745308:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// blt 0x82745320
	if (ctx.cr0.lt) goto loc_82745320;
	// stb r31,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r31.u8);
	// b 0x8274532c
	goto loc_8274532C;
loc_82745320:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8273dd20
	ctx.lr = 0x8274532C;
	sub_8273DD20(ctx, base);
loc_8274532C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82745330:
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

DEFINE_REX_FUNC(sub_8274F7B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8274F7C0;
	__savegprlr_24(ctx, base);
	// mullw r11,r6,r7
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// add r26,r11,r4
	ctx.r26.u64 = ctx.r11.u64 + ctx.r4.u64;
	// cmplw cr6,r4,r26
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r26.u32, ctx.xer);
	// bge cr6,0x8274f8a4
	if (!ctx.cr6.lt) goto loc_8274F8A4;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r27,r7,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r28,r11,r4
	ctx.r28.u64 = ctx.r11.u64 + ctx.r4.u64;
loc_8274F7DC:
	// cmplw cr6,r4,r28
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x8274f890
	if (!ctx.cr6.lt) goto loc_8274F890;
	// subf r10,r4,r28
	ctx.r10.u64 = ctx.r28.u64 - ctx.r4.u64;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r29,r7,-4
	ctx.r29.s64 = ctx.r7.s64 + -4;
	// rlwinm r9,r10,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r10,r3,-4
	ctx.r10.s64 = ctx.r3.s64 + -4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8274F804:
	// lwzx r31,r29,r11
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r9,-4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// rlwinm r6,r31,30,2,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 30) & 0x3FFFFFC0;
	// lwzx r25,r11,r7
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// rlwinm r5,r9,30,2,25
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFC0;
	// lwz r24,0(r11)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r6,r6,0,18,9
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFC03FFF;
	// rlwinm r5,r5,0,18,9
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFFC03FFF;
	// clrlwi r9,r9,8
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFFFF;
	// clrlwi r30,r31,8
	ctx.r30.u64 = ctx.r31.u32 & 0xFFFFFF;
	// add r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 + ctx.r6.u64;
	// rlwinm r9,r9,0,24,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFF00FF;
	// rlwinm r30,r30,0,24,15
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFFFFFFFFFFFF00FF;
	// rlwinm r31,r25,30,2,25
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 30) & 0x3FFFFFC0;
	// clrlwi r6,r25,8
	ctx.r6.u64 = ctx.r25.u32 & 0xFFFFFF;
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
	// rlwinm r6,r6,0,24,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFF00FF;
	// rlwinm r31,r31,0,18,9
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0xFFFFFFFFFFC03FFF;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 + ctx.r31.u64;
	// rlwinm r31,r24,30,2,25
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 30) & 0x3FFFFFC0;
	// clrlwi r6,r24,8
	ctx.r6.u64 = ctx.r24.u32 & 0xFFFFFF;
	// rlwinm r31,r31,0,18,9
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0xFFFFFFFFFFC03FFF;
	// rlwinm r6,r6,0,24,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFF00FF;
	// add r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 + ctx.r31.u64;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// addis r6,r5,128
	ctx.r6.s64 = ctx.r5.s64 + 8388608;
	// addis r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 131072;
	// addi r6,r6,128
	ctx.r6.s64 = ctx.r6.s64 + 128;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// rlwimi r6,r9,30,24,31
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0xFF) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFF00);
	// rlwimi r6,r9,30,8,15
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0xFF0000) | (ctx.r6.u64 & 0xFFFFFFFFFF00FFFF);
	// stwu r6,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r6.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8274f804
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8274F804;
loc_8274F890:
	// add r4,r27,r4
	ctx.r4.u64 = ctx.r27.u64 + ctx.r4.u64;
	// add r3,r3,r8
	ctx.r3.u64 = ctx.r3.u64 + ctx.r8.u64;
	// add r28,r28,r27
	ctx.r28.u64 = ctx.r28.u64 + ctx.r27.u64;
	// cmplw cr6,r4,r26
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r26.u32, ctx.xer);
	// blt cr6,0x8274f7dc
	if (ctx.cr6.lt) goto loc_8274F7DC;
loc_8274F8A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8275C0B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8275C0B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275c0e0
	if (ctx.cr6.eq) goto loc_8275C0E0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82755cf8
	ctx.lr = 0x8275C0DC;
	sub_82755CF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
loc_8275C0E0:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r9,100(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r7,104(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// mullw r9,r9,r29
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r29.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// ble cr6,0x8275c134
	if (!ctx.cr6.gt) goto loc_8275C134;
	// addi r11,r6,-12
	ctx.r11.s64 = ctx.r6.s64 + -12;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
loc_8275C114:
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stfs f0,4(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfsu f0,16(r11)
	ea = 16 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// stfsu f0,8(r10)
	ea = 8 + ctx.r10.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// lwz r9,104(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8275c114
	if (ctx.cr6.lt) goto loc_8275C114;
loc_8275C134:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8275DF90) {
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
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8275e008
	if (!ctx.cr6.lt) goto loc_8275E008;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,5864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5864);
	ctx.f0.f64 = double(temp.f32);
loc_8275DFEC:
	// lfsu f13,4(r9)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r9.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r9.u32 = ea;
	// stfs f13,0(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f0,12(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// stfs f0,8(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// stfs f0,4(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// bdnz 0x8275dfec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8275DFEC;
loc_8275E008:
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275e024
	if (ctx.cr6.eq) goto loc_8275E024;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// bl 0x82755c68
	ctx.lr = 0x8275E024;
	sub_82755C68(ctx, base);
loc_8275E024:
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275e040
	if (ctx.cr6.eq) goto loc_8275E040;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// bl 0x82756030
	ctx.lr = 0x8275E040;
	sub_82756030(ctx, base);
loc_8275E040:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82762688) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-27872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -27872);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8276269c
	if (ctx.cr6.eq) goto loc_8276269C;
	// b 0x82762490
	sub_82762490(ctx, base);
	return;
loc_8276269C:
	// b 0x827623d8
	sub_827623D8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82762998) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x827629A0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stw r4,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r5,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// lis r10,19794
	ctx.r10.s64 = 1297219584;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// std r30,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r30.u64);
	// ori r29,r10,20294
	ctx.r29.u64 = ctx.r10.u64 | 20294;
	// beq cr6,0x827629f4
	if (ctx.cr6.eq) goto loc_827629F4;
	// lis r10,17990
	ctx.r10.s64 = 1178992640;
	// lwz r11,12(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r30,16(r4)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// ori r9,r10,18770
	ctx.r9.u64 = ctx.r10.u64 | 18770;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x827629f0
	if (ctx.cr6.eq) goto loc_827629F0;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x827629f4
	if (!ctx.cr6.eq) goto loc_827629F4;
loc_827629F0:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
loc_827629F4:
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82762A14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82762b14
	if (ctx.cr6.lt) goto loc_82762B14;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82762A44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82762b14
	if (ctx.cr6.lt) goto loc_82762B14;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82762a84
	if (ctx.cr6.eq) goto loc_82762A84;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82762a84
	if (!ctx.cr6.eq) goto loc_82762A84;
	// lbz r8,81(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r7,82(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r9,83(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// stb r8,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r8.u8);
	// stb r7,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r7.u8);
	// stb r9,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r9.u8);
	// b 0x82762ac0
	goto loc_82762AC0;
loc_82762A84:
	// lbz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 84);
	// lbz r7,87(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// lbz r6,81(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r5,85(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 85);
	// lbz r4,82(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r27,86(r1)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r1.u32 + 86);
	// lbz r8,83(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// stb r7,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r7.u8);
	// stb r9,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r9.u8);
	// stb r4,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r4.u8);
	// stb r8,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
	// stb r27,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r27.u8);
	// stb r6,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r6.u8);
	// stb r5,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r5.u8);
loc_82762AC0:
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r10
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82762af4
	if (ctx.cr6.eq) goto loc_82762AF4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82762ae8
	if (ctx.cr6.eq) goto loc_82762AE8;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// b 0x827629f4
	goto loc_827629F4;
loc_82762AE8:
	// lis r3,-28655
	ctx.r3.s64 = -1877934080;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_82762AF4:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r10,r30,8
	ctx.r10.s64 = ctx.r30.s64 + 8;
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// ori r8,r11,1
	ctx.r8.u64 = ctx.r11.u64 | 1;
	// stw r28,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// stw r10,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// stw r8,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
	// stw r9,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
loc_82762B14:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82769A48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x82769A50;
	__savegprlr_19(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,420(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 420);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r20,r4
	ctx.r20.u64 = ctx.r4.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// mr r21,r8
	ctx.r21.u64 = ctx.r8.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// li r22,0
	ctx.r22.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82769a88
	if (ctx.cr6.eq) goto loc_82769A88;
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r19,r11,2,31,31
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1;
	// b 0x82769a8c
	goto loc_82769A8C;
loc_82769A88:
	// mr r19,r22
	ctx.r19.u64 = ctx.r22.u64;
loc_82769A8C:
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// addi r27,r30,380
	ctx.r27.s64 = ctx.r30.s64 + 380;
loc_82769A98:
	// li r11,1
	ctx.r11.s64 = 1;
	// slw r11,r11,r29
	ctx.r11.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r29.u8 & 0x3F));
	// and. r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 & ctx.r20.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82769c78
	if (ctx.cr0.eq) goto loc_82769C78;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82639c90
	ctx.lr = 0x82769AB8;
	sub_82639C90(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82769d60
	if (!ctx.cr0.eq) goto loc_82769D60;
	// subf r11,r29,r24
	ctx.r11.u64 = ctx.r24.u64 - ctx.r29.u64;
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// ld r4,0(r25)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r25.u32 + 0);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stw r21,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r21.u32);
	// rlwinm r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// rlwinm r8,r11,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82773df0
	ctx.lr = 0x82769AF4;
	sub_82773DF0(ctx, base);
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82769d7c
	if (ctx.cr0.eq) goto loc_82769D7C;
	// add r28,r29,r30
	ctx.r28.u64 = ctx.r29.u64 + ctx.r30.u64;
	// lbz r11,736(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 736);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82769b58
	if (!ctx.cr0.eq) goto loc_82769B58;
	// lwz r10,428(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 428);
	// addi r11,r30,424
	ctx.r11.s64 = ctx.r30.s64 + 424;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82769b40
	if (ctx.cr6.eq) goto loc_82769B40;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82769B38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82769b44
	goto loc_82769B44;
loc_82769B40:
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
loc_82769B44:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x82769d88
	if (ctx.cr6.lt) goto loc_82769D88;
	// lbz r11,736(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 736);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stb r11,736(r28)
	REX_STORE_U8(ctx.r28.u32 + 736, ctx.r11.u8);
loc_82769B58:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// beq cr6,0x82769b70
	if (ctx.cr6.eq) goto loc_82769B70;
	// lbz r11,171(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 171);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,171(r30)
	REX_STORE_U8(ctx.r30.u32 + 171, ctx.r11.u8);
	// b 0x82769b7c
	goto loc_82769B7C;
loc_82769B70:
	// lbz r11,170(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 170);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,170(r30)
	REX_STORE_U8(ctx.r30.u32 + 170, ctx.r11.u8);
loc_82769B7C:
	// lwz r10,428(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 428);
	// addi r11,r30,424
	ctx.r11.s64 = ctx.r30.s64 + 424;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82769ba8
	if (ctx.cr6.eq) goto loc_82769BA8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82769BA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82769bac
	goto loc_82769BAC;
loc_82769BA8:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
loc_82769BAC:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82769bd4
	if (ctx.cr6.eq) goto loc_82769BD4;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// oris r10,r10,512
	ctx.r10.u64 = ctx.r10.u64 | 33554432;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// ori r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 32768;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
loc_82769BD4:
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// beq cr6,0x82769bec
	if (ctx.cr6.eq) goto loc_82769BEC;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// oris r10,r10,256
	ctx.r10.u64 = ctx.r10.u64 | 16777216;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
loc_82769BEC:
	// cmplw cr6,r29,r24
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x82769c04
	if (!ctx.cr6.eq) goto loc_82769C04;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x827646e8
	ctx.lr = 0x82769BFC;
	sub_827646E8(ctx, base);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// stw r11,396(r30)
	REX_STORE_U32(ctx.r30.u32 + 396, ctx.r11.u32);
loc_82769C04:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82769c4c
	if (ctx.cr6.eq) goto loc_82769C4C;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,0(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x827734f8
	ctx.lr = 0x82769C18;
	sub_827734F8(ctx, base);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,100(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 100);
	// stw r10,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r10,r11,376
	ctx.r10.s64 = ctx.r11.s64 + 376;
	// lwz r10,376(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 376);
	// stw r10,376(r11)
	REX_STORE_U32(ctx.r11.u32 + 376, ctx.r10.u32);
	// lwz r10,380(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 380);
	// stw r10,380(r11)
	REX_STORE_U32(ctx.r11.u32 + 380, ctx.r10.u32);
	// lwz r10,384(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 384);
	// stw r10,384(r11)
	REX_STORE_U32(ctx.r11.u32 + 384, ctx.r10.u32);
	// lwz r10,388(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 388);
	// stw r10,388(r11)
	REX_STORE_U32(ctx.r11.u32 + 388, ctx.r10.u32);
loc_82769C4C:
	// lwz r4,0(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// bl 0x82766a60
	ctx.lr = 0x82769C5C;
	sub_82766A60(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,0(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82769038
	ctx.lr = 0x82769C6C;
	sub_82769038(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82769d54
	if (ctx.cr0.lt) goto loc_82769D54;
	// b 0x82769d3c
	goto loc_82769D3C;
loc_82769C78:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82769d3c
	if (!ctx.cr6.eq) goto loc_82769D3C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826399f0
	ctx.lr = 0x82769C8C;
	sub_826399F0(ctx, base);
	// add r28,r29,r30
	ctx.r28.u64 = ctx.r29.u64 + ctx.r30.u64;
	// stw r3,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lbz r11,736(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 736);
	// beq 0x82769cf4
	if (ctx.cr0.eq) goto loc_82769CF4;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82769d3c
	if (!ctx.cr0.eq) goto loc_82769D3C;
	// lwz r10,428(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 428);
	// addi r11,r30,424
	ctx.r11.s64 = ctx.r30.s64 + 424;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82769cd8
	if (ctx.cr6.eq) goto loc_82769CD8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82769CD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82769cdc
	goto loc_82769CDC;
loc_82769CD8:
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
loc_82769CDC:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x82769d54
	if (ctx.cr6.lt) goto loc_82769D54;
	// lbz r11,736(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 736);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stb r11,736(r28)
	REX_STORE_U8(ctx.r28.u32 + 736, ctx.r11.u8);
	// b 0x82769d3c
	goto loc_82769D3C;
loc_82769CF4:
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82769d3c
	if (ctx.cr0.eq) goto loc_82769D3C;
	// lwz r10,428(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 428);
	// addi r11,r30,424
	ctx.r11.s64 = ctx.r30.s64 + 424;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82769d2c
	if (ctx.cr6.eq) goto loc_82769D2C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82769D24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82769d30
	goto loc_82769D30;
loc_82769D2C:
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
loc_82769D30:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x82769d54
	if (ctx.cr6.lt) goto loc_82769D54;
	// stb r22,736(r28)
	REX_STORE_U8(ctx.r28.u32 + 736, ctx.r22.u8);
loc_82769D3C:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// addi r25,r25,8
	ctx.r25.s64 = ctx.r25.s64 + 8;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x82769a98
	if (ctx.cr6.lt) goto loc_82769A98;
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
loc_82769D54:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
loc_82769D60:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bgt cr6,0x82769d70
	if (ctx.cr6.gt) goto loc_82769D70;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82769d54
	goto loc_82769D54;
loc_82769D70:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r31,r11,32775
	ctx.r31.u64 = ctx.r11.u64 | 2147942400;
	// b 0x82769d54
	goto loc_82769D54;
loc_82769D7C:
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x82769d54
	goto loc_82769D54;
loc_82769D88:
	// addi r11,r29,95
	ctx.r11.s64 = ctx.r29.s64 + 95;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r29,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// bl 0x82773eb8
	ctx.lr = 0x82769D98;
	sub_82773EB8(ctx, base);
	// stwx r22,r29,r30
	REX_STORE_U32(ctx.r29.u32 + ctx.r30.u32, ctx.r22.u32);
	// b 0x82769d54
	goto loc_82769D54;
}

DEFINE_REX_FUNC(sub_8277D790) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x8277D798;
	__savegprlr_20(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// lwz r10,208(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 208);
	// addi r23,r3,208
	ctx.r23.s64 = ctx.r3.s64 + 208;
	// li r3,16
	ctx.r3.s64 = 16;
	// subf r9,r10,r23
	ctx.r9.u64 = ctx.r23.u64 - ctx.r10.u64;
	// lwz r11,200(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 200);
	// subfic r9,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r9.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r11,3
	ctx.r4.s64 = ctx.r11.s64 + 3;
	// subfe r11,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// addi r22,r11,-4
	ctx.r22.s64 = ctx.r11.s64 + -4;
	// bl 0x82788e50
	ctx.lr = 0x8277D7D0;
	sub_82788E50(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x8277d7e4
	if (!ctx.cr0.eq) goto loc_8277D7E4;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x8277dbc8
	goto loc_8277DBC8;
loc_8277D7E4:
	// li r20,0
	ctx.r20.s64 = 0;
	// addi r27,r28,68
	ctx.r27.s64 = ctx.r28.s64 + 68;
	// stb r20,69(r28)
	REX_STORE_U8(ctx.r28.u32 + 69, ctx.r20.u8);
	// li r25,3
	ctx.r25.s64 = 3;
	// stb r20,70(r28)
	REX_STORE_U8(ctx.r28.u32 + 70, ctx.r20.u8);
	// addi r26,r27,3
	ctx.r26.s64 = ctx.r27.s64 + 3;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplw cr6,r11,r23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r23.u32, ctx.xer);
	// beq cr6,0x8277d8e0
	if (ctx.cr6.eq) goto loc_8277D8E0;
	// mr r24,r11
	ctx.r24.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8277d8e0
	if (ctx.cr0.eq) goto loc_8277D8E0;
loc_8277D814:
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// addi r29,r24,-4
	ctx.r29.s64 = ctx.r24.s64 + -4;
	// lwz r10,284(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 284);
	// subf r9,r11,r23
	ctx.r9.u64 = ctx.r23.u64 - ctx.r11.u64;
	// rlwinm. r10,r10,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subfic r9,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r9.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// subfe r10,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r24,r10,r11
	ctx.r24.u64 = ctx.r10.u64 & ctx.r11.u64;
	// beq 0x8277d8d8
	if (ctx.cr0.eq) goto loc_8277D8D8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x8277b600
	ctx.lr = 0x8277D844;
	sub_8277B600(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8277dbd4
	if (ctx.cr0.eq) goto loc_8277DBD4;
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8277d87c
	if (!ctx.cr6.eq) goto loc_8277D87C;
	// cmplw cr6,r31,r22
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r22.u32, ctx.xer);
	// beq cr6,0x8277d87c
	if (ctx.cr6.eq) goto loc_8277D87C;
	// lbz r11,1(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 1);
	// addi r25,r25,4
	ctx.r25.s64 = ctx.r25.s64 + 4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r11,1(r27)
	REX_STORE_U8(ctx.r27.u32 + 1, ctx.r11.u8);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
loc_8277D87C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,184
	ctx.r3.s64 = ctx.r31.s64 + 184;
	// bl 0x82784518
	ctx.lr = 0x8277D888;
	sub_82784518(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8277d89c
	if (!ctx.cr0.eq) goto loc_8277D89C;
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
loc_8277D89C:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8277dbe8
	if (!ctx.cr6.eq) goto loc_8277DBE8;
	// lwz r11,288(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 288);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rlwinm r11,r11,0,17,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// stw r11,288(r29)
	REX_STORE_U32(ctx.r29.u32 + 288, ctx.r11.u32);
	// lwz r11,200(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 200);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,200(r21)
	REX_STORE_U32(ctx.r21.u32 + 200, ctx.r11.u32);
	// bl 0x82784c88
	ctx.lr = 0x8277D8CC;
	sub_82784C88(ctx, base);
	// lwz r11,324(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 324);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,324(r21)
	REX_STORE_U32(ctx.r21.u32 + 324, ctx.r11.u32);
loc_8277D8D8:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x8277d814
	if (!ctx.cr6.eq) goto loc_8277D814;
loc_8277D8E0:
	// lwz r11,172(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 172);
	// li r24,-1
	ctx.r24.s64 = -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8277d980
	if (ctx.cr6.eq) goto loc_8277D980;
	// lwz r11,192(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 192);
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8277d980
	if (ctx.cr6.eq) goto loc_8277D980;
	// mr r30,r20
	ctx.r30.u64 = ctx.r20.u64;
	// addi r26,r26,-4
	ctx.r26.s64 = ctx.r26.s64 + -4;
loc_8277D908:
	// lwz r11,184(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 184);
	// lwzx r31,r11,r30
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// lhz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 280);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,280(r31)
	REX_STORE_U16(ctx.r31.u32 + 280, ctx.r11.u16);
loc_8277D91C:
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
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
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
	// bne 0x8277d91c
	if (!ctx.cr0.eq) goto loc_8277D91C;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// li r5,20000
	ctx.r5.s64 = 20000;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// oris r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 2097152;
	// addi r3,r31,96
	ctx.r3.s64 = ctx.r31.s64 + 96;
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// bl 0x82784e88
	ctx.lr = 0x8277D954;
	sub_82784E88(ctx, base);
	// lbz r11,2(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 2);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r25,r25,4
	ctx.r25.s64 = ctx.r25.s64 + 4;
	// stb r11,2(r27)
	REX_STORE_U8(ctx.r27.u32 + 2, ctx.r11.u8);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stwu r11,4(r26)
	ea = 4 + ctx.r26.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r26.u32 = ea;
	// lwz r11,192(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 192);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8277d908
	if (ctx.cr6.lt) goto loc_8277D908;
loc_8277D980:
	// stw r25,48(r28)
	REX_STORE_U32(ctx.r28.u32 + 48, ctx.r25.u32);
	// li r7,131
	ctx.r7.s64 = 131;
	// addi r5,r28,36
	ctx.r5.s64 = ctx.r28.s64 + 36;
	// lwz r6,32(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82785048
	ctx.lr = 0x8277D99C;
	sub_82785048(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82785460
	ctx.lr = 0x8277D9B8;
	sub_82785460(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827850b0
	ctx.lr = 0x8277D9C0;
	sub_827850B0(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827853c8
	ctx.lr = 0x8277D9CC;
	sub_827853C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8277dbe8
	if (!ctx.cr0.eq) goto loc_8277DBE8;
	// addi r11,r28,4
	ctx.r11.s64 = ctx.r28.s64 + 4;
loc_8277D9D8:
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
	// bne 0x8277d9d8
	if (!ctx.cr0.eq) goto loc_8277D9D8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8277da14
	if (!ctx.cr6.eq) goto loc_8277DA14;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8277DA14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8277DA14:
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplw cr6,r11,r23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r23.u32, ctx.xer);
	// beq cr6,0x8277dbc4
	if (ctx.cr6.eq) goto loc_8277DBC4;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8277dbc4
	if (ctx.cr0.eq) goto loc_8277DBC4;
loc_8277DA2C:
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// addi r30,r25,-4
	ctx.r30.s64 = ctx.r25.s64 + -4;
	// subf r10,r11,r23
	ctx.r10.u64 = ctx.r23.u64 - ctx.r11.u64;
	// cmplw cr6,r30,r22
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r22.u32, ctx.xer);
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r25,r10,r11
	ctx.r25.u64 = ctx.r10.u64 & ctx.r11.u64;
	// beq cr6,0x8277dbbc
	if (ctx.cr6.eq) goto loc_8277DBBC;
	// lwz r11,288(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 288);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8277dbbc
	if (!ctx.cr0.eq) goto loc_8277DBBC;
	// lwz r31,172(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 172);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8277dbbc
	if (ctx.cr6.eq) goto loc_8277DBBC;
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// li r3,18
	ctx.r3.s64 = 18;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82788e50
	ctx.lr = 0x8277DA74;
	sub_82788E50(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x8277dbe0
	if (ctx.cr0.eq) goto loc_8277DBE0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r31,69(r28)
	REX_STORE_U8(ctx.r28.u32 + 69, ctx.r31.u8);
	// addi r11,r28,68
	ctx.r11.s64 = ctx.r28.s64 + 68;
	// sth r10,70(r28)
	REX_STORE_U16(ctx.r28.u32 + 70, ctx.r10.u16);
	// mr r27,r20
	ctx.r27.u64 = ctx.r20.u64;
	// lwz r10,192(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 192);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8277db10
	if (ctx.cr6.eq) goto loc_8277DB10;
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
	// addi r26,r11,-4
	ctx.r26.s64 = ctx.r11.s64 + -4;
loc_8277DAA8:
	// lwz r11,184(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// lwzx r31,r11,r29
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// lhz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 280);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,280(r31)
	REX_STORE_U16(ctx.r31.u32 + 280, ctx.r11.u16);
loc_8277DABC:
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
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
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
	// bne 0x8277dabc
	if (!ctx.cr0.eq) goto loc_8277DABC;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// li r5,20000
	ctx.r5.s64 = 20000;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// oris r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 2097152;
	// addi r3,r31,96
	ctx.r3.s64 = ctx.r31.s64 + 96;
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// bl 0x82784e88
	ctx.lr = 0x8277DAF4;
	sub_82784E88(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// stwu r11,4(r26)
	ea = 4 + ctx.r26.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r26.u32 = ea;
	// lwz r11,192(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 192);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8277daa8
	if (ctx.cr6.lt) goto loc_8277DAA8;
loc_8277DB10:
	// lwz r11,396(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 396);
	// rlwinm. r11,r11,0,9,9
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8277db2c
	if (ctx.cr0.eq) goto loc_8277DB2C;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82776690
	ctx.lr = 0x8277DB2C;
	sub_82776690(ctx, base);
loc_8277DB2C:
	// li r7,131
	ctx.r7.s64 = 131;
	// lwz r6,32(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 32);
	// addi r5,r28,36
	ctx.r5.s64 = ctx.r28.s64 + 36;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82785048
	ctx.lr = 0x8277DB44;
	sub_82785048(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82785460
	ctx.lr = 0x8277DB60;
	sub_82785460(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827850b0
	ctx.lr = 0x8277DB68;
	sub_827850B0(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827853c8
	ctx.lr = 0x8277DB74;
	sub_827853C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8277dbe8
	if (!ctx.cr0.eq) goto loc_8277DBE8;
	// addi r11,r28,4
	ctx.r11.s64 = ctx.r28.s64 + 4;
loc_8277DB80:
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
	// bne 0x8277db80
	if (!ctx.cr0.eq) goto loc_8277DB80;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8277dbbc
	if (!ctx.cr6.eq) goto loc_8277DBBC;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8277DBBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8277DBBC:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x8277da2c
	if (!ctx.cr6.eq) goto loc_8277DA2C;
loc_8277DBC4:
	// mr r30,r20
	ctx.r30.u64 = ctx.r20.u64;
loc_8277DBC8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
loc_8277DBD4:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4120
	ctx.r30.u64 = ctx.r30.u64 | 4120;
	// b 0x8277dbe8
	goto loc_8277DBE8;
loc_8277DBE0:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
loc_8277DBE8:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8277dbc8
	if (ctx.cr6.eq) goto loc_8277DBC8;
	// addi r11,r28,4
	ctx.r11.s64 = ctx.r28.s64 + 4;
loc_8277DBF4:
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
	// bne 0x8277dbf4
	if (!ctx.cr0.eq) goto loc_8277DBF4;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8277dbc8
	if (!ctx.cr6.eq) goto loc_8277DBC8;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8277DC30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8277dbc8
	goto loc_8277DBC8;
}

DEFINE_REX_FUNC(sub_8279A128) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8279A130;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// rlwinm r9,r10,0,25,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x60;
	// addi r30,r3,4
	ctx.r30.s64 = ctx.r3.s64 + 4;
	// stw r26,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r26.u32);
	// sth r26,8(r3)
	REX_STORE_U16(ctx.r3.u32 + 8, ctx.r26.u16);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// sth r26,10(r3)
	REX_STORE_U16(ctx.r3.u32 + 10, ctx.r26.u16);
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// sth r26,12(r3)
	REX_STORE_U16(ctx.r3.u32 + 12, ctx.r26.u16);
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r29,r8
	ctx.r29.u64 = ctx.r8.u64;
	// stb r9,14(r31)
	REX_STORE_U8(ctx.r31.u32 + 14, ctx.r9.u8);
	// clrlwi. r11,r10,28
	ctx.r11.u64 = ctx.r10.u32 & 0xF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r28,r6,1
	ctx.r28.s64 = ctx.r6.s64 + 1;
	// addi r3,r4,1
	ctx.r3.s64 = ctx.r4.s64 + 1;
	// mr r24,r10
	ctx.r24.u64 = ctx.r10.u64;
	// beq 0x8279a188
	if (ctx.cr0.eq) goto loc_8279A188;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x8279a190
	goto loc_8279A190;
loc_8279A188:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8279a0c0
	ctx.lr = 0x8279A190;
	sub_8279A0C0(ctx, base);
loc_8279A190:
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8279a254
	if (ctx.cr6.eq) goto loc_8279A254;
	// cmplw cr6,r9,r28
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x8279a254
	if (!ctx.cr6.lt) goto loc_8279A254;
	// rlwinm. r11,r24,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8279a218
	if (ctx.cr0.eq) goto loc_8279A218;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8279a1f0
	if (ctx.cr6.eq) goto loc_8279A1F0;
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
loc_8279A1BC:
	// lwzu r11,-4(r10)
	ea = -4 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8279a1e8
	if (!ctx.cr6.eq) goto loc_8279A1E8;
	// lbz r8,15(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 15);
	// cmplwi cr6,r8,2
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 2, ctx.xer);
	// beq cr6,0x8279a254
	if (ctx.cr6.eq) goto loc_8279A254;
	// lbz r8,14(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 14);
	// rlwinm. r8,r8,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8279a264
	if (!ctx.cr0.eq) goto loc_8279A264;
loc_8279A1E8:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8279a1bc
	if (!ctx.cr6.eq) goto loc_8279A1BC;
loc_8279A1F0:
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lhz r10,10(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 10);
	// rotlwi r11,r11,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// sth r11,10(r31)
	REX_STORE_U16(ctx.r31.u32 + 10, ctx.r11.u16);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lbzu r10,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r10.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
loc_8279A214:
	// sth r11,10(r31)
	REX_STORE_U16(ctx.r31.u32 + 10, ctx.r11.u16);
loc_8279A218:
	// rlwinm. r11,r24,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// beq 0x8279a27c
	if (ctx.cr0.eq) goto loc_8279A27C;
	// lhz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// rotlwi r11,r11,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// sth r11,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r11.u16);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lbzu r10,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r10.u64 = REX_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// sth r11,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r11.u16);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8279a288
	if (!ctx.cr0.eq) goto loc_8279A288;
loc_8279A254:
	// stb r26,15(r31)
	REX_STORE_U8(ctx.r31.u32 + 15, ctx.r26.u8);
loc_8279A258:
	// subf r3,r25,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
loc_8279A264:
	// lhz r11,10(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// rlwinm. r10,r24,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sth r11,10(r31)
	REX_STORE_U16(ctx.r31.u32 + 10, ctx.r11.u16);
	// beq 0x8279a218
	if (ctx.cr0.eq) goto loc_8279A218;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x8279a214
	goto loc_8279A214;
loc_8279A27C:
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// sth r11,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r11.u16);
loc_8279A288:
	// rlwinm. r11,r24,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8279a29c
	if (ctx.cr0.eq) goto loc_8279A29C;
	// li r11,128
	ctx.r11.s64 = 128;
	// stb r11,15(r31)
	REX_STORE_U8(ctx.r31.u32 + 15, ctx.r11.u8);
	// b 0x8279a2b4
	goto loc_8279A2B4;
loc_8279A29C:
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stb r11,15(r31)
	REX_STORE_U8(ctx.r31.u32 + 15, ctx.r11.u8);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x8279a254
	if (!ctx.cr6.lt) goto loc_8279A254;
loc_8279A2B4:
	// lhz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8279a2d4
	if (!ctx.cr0.eq) goto loc_8279A2D4;
	// subf r11,r25,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r25.u64;
	// cmplw cr6,r11,r23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r23.u32, ctx.xer);
	// bge cr6,0x8279a254
	if (!ctx.cr6.lt) goto loc_8279A254;
	// subf r11,r11,r23
	ctx.r11.u64 = ctx.r23.u64 - ctx.r11.u64;
	// sth r11,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r11.u16);
loc_8279A2D4:
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// b 0x8279a258
	goto loc_8279A258;
}

DEFINE_REX_FUNC(sub_827A86C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x827A86D0;
	__savegprlr_29(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x827a87f0
	if (!ctx.cr6.lt) goto loc_827A87F0;
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r7,r3,12
	ctx.r7.s64 = ctx.r3.s64 + 12;
loc_827A86F4:
	// addi r9,r8,3
	ctx.r9.s64 = ctx.r8.s64 + 3;
	// cmpw cr6,r9,r4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, ctx.xer);
	// bgt cr6,0x827a87a4
	if (ctx.cr6.gt) goto loc_827A87A4;
	// lwz r9,-8(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + -8);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x827a8714
	if (!ctx.cr6.gt) goto loc_827A8714;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
loc_827A8714:
	// cmpw cr6,r9,r30
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r30.s32, ctx.xer);
	// bge cr6,0x827a8724
	if (!ctx.cr6.lt) goto loc_827A8724;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
loc_827A8724:
	// lwz r9,-4(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + -4);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x827a8738
	if (!ctx.cr6.gt) goto loc_827A8738;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
loc_827A8738:
	// cmpw cr6,r9,r30
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r30.s32, ctx.xer);
	// bge cr6,0x827a8748
	if (!ctx.cr6.lt) goto loc_827A8748;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// mr r29,r8
	ctx.r29.u64 = ctx.r8.u64;
loc_827A8748:
	// lwz r9,0(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x827a875c
	if (!ctx.cr6.gt) goto loc_827A875C;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// addi r31,r8,1
	ctx.r31.s64 = ctx.r8.s64 + 1;
loc_827A875C:
	// cmpw cr6,r9,r30
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r30.s32, ctx.xer);
	// bge cr6,0x827a876c
	if (!ctx.cr6.lt) goto loc_827A876C;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// addi r29,r8,1
	ctx.r29.s64 = ctx.r8.s64 + 1;
loc_827A876C:
	// lwz r9,4(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x827a8780
	if (!ctx.cr6.gt) goto loc_827A8780;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// addi r31,r8,2
	ctx.r31.s64 = ctx.r8.s64 + 2;
loc_827A8780:
	// cmpw cr6,r9,r30
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r30.s32, ctx.xer);
	// bge cr6,0x827a8790
	if (!ctx.cr6.lt) goto loc_827A8790;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// addi r29,r8,2
	ctx.r29.s64 = ctx.r8.s64 + 2;
loc_827A8790:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x827a86f4
	if (ctx.cr6.lt) goto loc_827A86F4;
loc_827A87A4:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x827a87f0
	if (!ctx.cr6.lt) goto loc_827A87F0;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 + ctx.r3.u64;
loc_827A87B4:
	// cmpw cr6,r10,r4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x827a87f0
	if (!ctx.cr6.lt) goto loc_827A87F0;
	// lwz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x827a87d0
	if (!ctx.cr6.gt) goto loc_827A87D0;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
loc_827A87D0:
	// cmpw cr6,r9,r30
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r30.s32, ctx.xer);
	// bge cr6,0x827a87e0
	if (!ctx.cr6.lt) goto loc_827A87E0;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
loc_827A87E0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x827a87b4
	if (ctx.cr6.lt) goto loc_827A87B4;
loc_827A87F0:
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r7,r4
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, ctx.xer);
	// bgt cr6,0x827a886c
	if (ctx.cr6.gt) goto loc_827A886C;
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 + ctx.r3.u64;
loc_827A8808:
	// lwz r9,-8(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -8);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x827a881c
	if (!ctx.cr6.gt) goto loc_827A881C;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
loc_827A881C:
	// lwz r9,-4(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -4);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x827a8830
	if (!ctx.cr6.gt) goto loc_827A8830;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// addi r31,r10,1
	ctx.r31.s64 = ctx.r10.s64 + 1;
loc_827A8830:
	// lwz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x827a8844
	if (!ctx.cr6.gt) goto loc_827A8844;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// addi r31,r10,2
	ctx.r31.s64 = ctx.r10.s64 + 2;
loc_827A8844:
	// lwz r9,4(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x827a8858
	if (!ctx.cr6.gt) goto loc_827A8858;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// addi r31,r10,3
	ctx.r31.s64 = ctx.r10.s64 + 3;
loc_827A8858:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// cmpw cr6,r7,r4
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, ctx.xer);
	// ble cr6,0x827a8808
	if (!ctx.cr6.gt) goto loc_827A8808;
loc_827A886C:
	// cmpw cr6,r10,r4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x827a88a4
	if (!ctx.cr6.lt) goto loc_827A88A4;
	// subf r7,r10,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r10.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 + ctx.r3.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_827A8884:
	// lwz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x827a8898
	if (!ctx.cr6.gt) goto loc_827A8898;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
loc_827A8898:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bdnz 0x827a8884
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827A8884;
loc_827A88A4:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,-48(r1)
	REX_STORE_U32(ctx.r1.u32 + -48, ctx.r11.u32);
	// bge cr6,0x827a88b8
	if (!ctx.cr6.lt) goto loc_827A88B8;
	// stw r30,-48(r1)
	REX_STORE_U32(ctx.r1.u32 + -48, ctx.r30.u32);
	// blt cr6,0x827a88c0
	if (ctx.cr6.lt) goto loc_827A88C0;
loc_827A88B8:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// b 0x827a88c4
	goto loc_827A88C4;
loc_827A88C0:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_827A88C4:
	// lfs f0,-48(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// stfs f0,0(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827B05D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8908(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8908, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0E48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23068);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8656(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1938) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8328);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8324(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8324, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2530) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-7972(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7972);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-7968(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -7968, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2E78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-7732(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7732);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7680(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7680, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B3C90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,23624
	ctx.r9.s64 = ctx.r11.s64 + 23624;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,23624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7272(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7272, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B4BC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6832(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5910) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6428(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6778) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6000(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7728) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24332);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5528(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5528, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8478) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-5180(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5180);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5176(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5176, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9080) {
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
	// lfs f0,24568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4936(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4936);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4824(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BA2B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,24840
	ctx.r9.s64 = ctx.r11.s64 + 24840;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4288(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB360) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3780(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3780, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC070) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-3384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3380(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BCE48) {
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
	// lfs f0,25624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3020(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3020);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2972(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BE118) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2428(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2428);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BEFC8) {
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
	// lfs f0,25992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2080(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2080);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1996(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0048) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-1548(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1548);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-1496(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -1496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0A68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1188(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1BF0) {
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
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-772(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -772);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-704(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2CF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -196);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-192(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3CC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,224(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,276(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 276, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C4AC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,708(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 708, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5B20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,1180(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1180);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1184(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 1184, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6288) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27900(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27900);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1412(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7250) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1892);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7F48) {
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
	// lfs f0,28512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2216(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2216);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2304(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2304, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9300) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,28704
	ctx.r9.s64 = ctx.r11.s64 + 28704;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,28704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2880(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CA6D8) {
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
	// lfs f0,28904(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28904);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3356(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3356);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3456(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3456, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CBAA0) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3940(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3940);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4056(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4056, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CCBE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,4556(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4556);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4560(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD5F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,4848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4852(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CE3D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,5256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5260(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5260, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CF4C0) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5628(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5628);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5748(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5748, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0768) {
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
	// lfs f0,29864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6188(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6188);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6296(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6296, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30056);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,6716(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6716);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2818) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30260(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30260);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7248(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7248, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D35D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7652(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4618) {
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
	// lfs f0,30504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8004(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8004);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8124(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D5868) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,30696
	ctx.r9.s64 = ctx.r11.s64 + 30696;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,30696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8660(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8660, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6B58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,30888
	ctx.r9.s64 = ctx.r11.s64 + 30888;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,30888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9212(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7E70) {
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
	// lfs f0,31088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9664(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9664);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9768(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9768, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D90D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,31304
	ctx.r9.s64 = ctx.r11.s64 + 31304;
	// lfs f0,31304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10304(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 10304, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA000) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10744(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DADC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11148(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DBE40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,31752
	ctx.r9.s64 = ctx.r11.s64 + 31752;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11628(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DD040) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31964(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31964);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12176(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12176, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE010) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12556(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12556);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12640(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DF178) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13144(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13144, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0238) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,13632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13632);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,13636(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 13636, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0B38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13892);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1868) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14300(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E2818) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-32472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32472);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,14772(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 14772, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15140(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15140, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E44E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-32056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32056);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,15584(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 15584, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E50B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,15912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15912);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,15916(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 15916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E5978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-31160
	ctx.r9.s64 = ctx.r11.s64 + -31160;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-31160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16164(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16164, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6E18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,16756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16760(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16760, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7E00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-26688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17188(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8D40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17628(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9BE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18028(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EABB0) {
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
	// lfs f0,-22856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18360(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18360);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18472(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EBFC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-22400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19036(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ECF78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,19460(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19460);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19464(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19464, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EDCC0) {
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
	// lfs f0,19816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-20744(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -20744);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,19832(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EF138) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,20384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20388(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20388, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0208) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,20852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20852);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20856(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F1200) {
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
	// lfs f0,-18360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,21236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 21236);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,21300(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 21300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F23F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-18024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F34B0) {
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
	// lfs f0,-17268(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17268);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,22248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 22248);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,22268(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 22268, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5028) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23220);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23224(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23224, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6F10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24148(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8000) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-13736
	ctx.r9.s64 = ctx.r11.s64 + -13736;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-13736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,24588(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 24588, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9508) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25172(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25172);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25176(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25176, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FA458) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9764(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9764);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB208) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26004(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FC030) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,26368(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 26368);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26420(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26420, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FD0F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26904(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26904, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FDEF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27316(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27316, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FEE78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-9048
	ctx.r9.s64 = ctx.r11.s64 + -9048;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9048(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9048);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27768(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27768, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800200) {
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
	// lfs f0,-8856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28220(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28220);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28336(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801540) {
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
	// lfs f0,-8664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28796(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28796);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28896(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828028D0) {
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
	// lfs f0,-8472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29356(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29356);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29468(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803BC0) {
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
	// lfs f0,-8280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29908(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29908);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30020(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804F00) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30460(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30460);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30580(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82806278) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31148(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807098) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31564(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807FD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-7576
	ctx.r9.s64 = ctx.r11.s64 + -7576;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-7576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7576);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32008(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828093B0) {
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
	// lfs f0,-7384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32484(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32484);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32584(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32584, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A788) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7124);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32376(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280B588) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6980(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6980);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31964(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280C3E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280D448) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-31056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31056);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31052(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E280) {
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
	// lfs f0,-6424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30676(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30676);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30628(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280F6C0) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30124(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30124);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30040(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810A00) {
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
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29576(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29576);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-29468(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -29468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811FF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28828(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28828);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812D00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28440(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28440, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813AD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5196);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28012(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28012, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814A98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-27504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27504);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-27500(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -27500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815698) {
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
	// lfs f0,-4680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-27208(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -27208);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-27148(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -27148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828169B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26588(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26588, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828178E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26136(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26136, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818798) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,30752(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 30752);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,-25684(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25684, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82819730) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3596(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3596);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281A6C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24748(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24748, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281B860) {
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
	// lfs f0,-3096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24296(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24296);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-24224(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -24224, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281CBE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-23748(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -23748);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23644(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281DA10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281EB18) {
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
	// lfs f13,-22756(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -22756);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22704(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281FC80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2040);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22200(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82820AA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-21788(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21788);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21784(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21784, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821920) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-21360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21356(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828229E8) {
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
	// lfs f0,-1560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20992(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20992);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20872(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20872, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82823D60) {
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
	// lfs f0,-1240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20392);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20284(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825180) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19700);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19696(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19696, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825ED0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,-664
	ctx.r9.s64 = ctx.r11.s64 + -664;
	// lfs f0,-664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19276(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -19276, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826F20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-18804(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18804);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18800(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18800, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828280C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-18292(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18292);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18288(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828EC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-17876(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17876);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17872(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17872, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829EB8) {
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
	// lfs f0,80(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17460(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17460);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17404(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17404, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282B1D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 272);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16844(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -16844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282BCE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-16512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16508(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282CC88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-16060(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16060);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16056(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -16056, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D788) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15784(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15784);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E7E0) {
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
	// lfs f0,952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15360(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15360);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15248(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15248, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282FB48) {
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
	// lfs f0,1160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14792(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14792);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14680(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14680, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830E88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14108(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831C60) {
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
	// lfs f0,1704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-13760(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -13760);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13688(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828331B8) {
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
	// lfs f0,1992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-13096(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -13096);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13048(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82834470) {
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
	// lfs f0,2216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12612(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12612);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12500(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828359D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8808);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,-11864(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11864, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836848) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11436(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11436, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837818) {
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
	// lfs f0,2872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11016(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11016);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10968(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10968, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838AC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-10428(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10428);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839CA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3348(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3348);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9904(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9904, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283AB08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-9484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9484);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9480(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283BB38) {
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
	// lfs f0,3616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9112(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9112);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9008(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283CF40) {
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
	// lfs f0,3856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8540);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8424(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283E348) {
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
	// lfs f0,4080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7952(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7952);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7840(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283F758) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7336(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7336);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7248(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7248, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82840930) {
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
	// lfs f0,4608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6840(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6840);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6724(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82841E48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6108(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6108);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6104(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6104, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842D40) {
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
	// lfs f0,5072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5732(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5732);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5664(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5664, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828440F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,5356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5084(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5084, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845070) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4620(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4620);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4616(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846090) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4136(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4136, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846F60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3700(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3700, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848140) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6204(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6204);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3168(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3168, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848FC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2740(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2740, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284A0E8) {
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
	// lfs f0,6512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2356(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2356);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2244(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2244, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284B4A8) {
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
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1784(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1784);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1668(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1668, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284C8E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1084);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1080(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1080, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284D788) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-648(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -648, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284E710) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-172(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -172, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284F550) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,260(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 260);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,264(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850648) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,772(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 772);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,776(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 776, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851790) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1276(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1276);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1280(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852708) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,8424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8424);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1728(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 1728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853150) {
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
	// lfs f0,8568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1956(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1956);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2036(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82854848) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r11,r11,32688
	ctx.r11.s64 = ctx.r11.s64 + 32688;
	// addi r10,r10,3312
	ctx.r10.s64 = ctx.r10.s64 + 3312;
	// li r9,48
	ctx.r9.s64 = 48;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v54,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v55,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v59,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v58,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vmrghw128 v62,v54,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v54.u32)));
	// vor128 v57,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vmrghw128 v61,v55,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v55.u32)));
	// vor128 v56,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vmrghw128 v63,v55,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v55.u32)));
	// vmrghw128 v60,v54,v60
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v54.u32)));
	// vmrghw128 v59,v55,v59
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), simde_mm_load_si128((simde__m128i*)ctx.v55.u32)));
	// vmrghw128 v58,v54,v58
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), simde_mm_load_si128((simde__m128i*)ctx.v54.u32)));
	// vmrghw128 v57,v55,v57
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), simde_mm_load_si128((simde__m128i*)ctx.v55.u32)));
	// vmrghw128 v56,v54,v56
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), simde_mm_load_si128((simde__m128i*)ctx.v54.u32)));
	// vmrghw128 v63,v59,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v59.u32)));
	// vmrghw128 v62,v58,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v58.u32)));
	// vmrghw128 v61,v57,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v57.u32)));
	// vmrghw128 v60,v56,v60
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v56.u32)));
	// stvx128 v63,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r8
	ea = (ctx.r10.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r7
	ea = (ctx.r10.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82881158) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82881160;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1156(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 1156);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r25,r1,128
	ctx.r25.s64 = ctx.r1.s64 + 128;
	// lbz r8,35(r7)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r7.u32 + 35);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// vspltish v0,7
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_set1_epi16(short(0x7)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lwz r31,1164(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 1164);
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// lwz r28,308(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// lvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r1,144
	ctx.r26.s64 = ctx.r1.s64 + 144;
	// stw r8,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// subf r10,r4,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r4.u64;
	// vspltish v1,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_set1_epi16(short(0x1)));
	// rlwinm r11,r27,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// lvx128 v12,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// vsplth v2,v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u16), simde_mm_set1_epi16(short(0xD0C))));
	// vsplth v11,v13,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_set1_epi16(short(0xD0C))));
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// stvx128 v0,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// addi r6,r11,3
	ctx.r6.s64 = ctx.r11.s64 + 3;
	// addi r3,r10,-1
	ctx.r3.s64 = ctx.r10.s64 + -1;
	// stvx128 v11,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82871a70
	ctx.lr = 0x828811D8;
	sub_82871A70(ctx, base);
	// cntlzw r5,r28
	ctx.r5.u64 = ctx.r28.u32 == 0 ? 32 : __builtin_clz(ctx.r28.u32);
	// vspltish v10,8
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_set1_epi16(short(0x8)));
	// vspltish v8,-1
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_set1_epi16(short(0xFFFF)));
	// li r4,1
	ctx.r4.s64 = 1;
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// vspltisb v11,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_set1_epi8(char(0x0)));
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// vspltish v9,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_set1_epi16(short(0x3)));
	// and r9,r3,r27
	ctx.r9.u64 = ctx.r3.u64 & ctx.r27.u64;
	// vspltish v12,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_set1_epi16(short(0x0)));
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// vslh v8,v8,v10
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// slw r9,r4,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r9.u8 & 0x3F));
	// bne cr6,0x82881290
	if (!ctx.cr6.eq) goto loc_82881290;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x8288133c
	if (!ctx.cr6.gt) goto loc_8288133C;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,4
	ctx.r8.s64 = 4;
loc_8288122C:
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// vsldoi128 v13,v0,v63,4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 12));
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// vsldoi128 v10,v0,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 14));
	// vsldoi128 v7,v0,v63,6
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 10));
	// lvx128 v6,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vadduhm v13,v10,v13
	simde_mm_store_si128((simde__m128i*)ctx.v13.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// vadduhm v4,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v7.u16)));
	// vslh v3,v13,v9
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubshs v2,v11,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vadduhm v1,v13,v3
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vadduhm v31,v1,v6
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vadduhm v30,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vsrah v29,v30,v5
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkshus128 v62,v29,v29
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vor v12,v12,v29
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v29.u8)));
	// stvewx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v62.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v62,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v62.u32[3 - ((ea & 0xF) >> 2)]);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bdnz 0x8288122c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8288122C;
	// b 0x8288133c
	goto loc_8288133C;
loc_82881290:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x8288133c
	if (!ctx.cr6.gt) goto loc_8288133C;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r10,r31,32
	ctx.r10.s64 = ctx.r31.s64 + 32;
	// li r9,-32
	ctx.r9.s64 = -32;
	// li r8,-16
	ctx.r8.s64 = -16;
loc_828812A8:
	// lvx128 v0,r10,r8
	ea = (ctx.r10.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// vsldoi128 v10,v0,v61,4
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), 12));
	// lvx128 v13,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsldoi128 v7,v0,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), 14));
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// vsldoi128 v6,v0,v61,6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), 10));
	// vsldoi v5,v13,v0,4
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), 12));
	// vsldoi v4,v13,v0,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), 14));
	// vadduhm v3,v7,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vsldoi v2,v13,v0,6
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), 10));
	// vadduhm v1,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vadduhm v10,v4,v5
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v5.u16)));
	// vor v0,v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v3.u8));
	// vadduhm v31,v13,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vsubshs v30,v11,v1
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vslh v29,v10,v9
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v28,v0,v9
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubshs v27,v11,v31
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vadduhm v26,v10,v29
	simde_mm_store_si128((simde__m128i*)ctx.v26.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// lvx128 v10,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vadduhm v25,v0,v28
	simde_mm_store_si128((simde__m128i*)ctx.v25.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// lvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vadduhm v24,v26,v10
	simde_mm_store_si128((simde__m128i*)ctx.v24.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vadduhm v23,v25,v10
	simde_mm_store_si128((simde__m128i*)ctx.v23.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vadduhm v13,v24,v27
	simde_mm_store_si128((simde__m128i*)ctx.v13.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.u16), simde_mm_load_si128((simde__m128i*)ctx.v27.u16)));
	// vadduhm v22,v23,v30
	simde_mm_store_si128((simde__m128i*)ctx.v22.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	// vsrah v21,v13,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v20,v22,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v22.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vor128 v60,v12,v21
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v21.u8)));
	// vpkshus128 v59,v21,v20
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v21.s16)));
	// vor128 v12,v60,v20
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v20.u8)));
	// stvx128 v59,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bdnz 0x828812a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_828812A8;
loc_8288133C:
	// vand v0,v12,v8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)));
	// vcmpgtuh. v13,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), 0xFFFF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// not r10,r11
	ctx.r10.u64 = ~ctx.r11.u64;
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

