#include "harmonyrecomp_funcs.114.h"

DEFINE_REX_FUNC(sub_82220A08) {
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
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9960);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82220a28
	if (ctx.cr6.eq) goto loc_82220A28;
	// bl 0x823c1ca0
	ctx.lr = 0x82220A28;
	sub_823C1CA0(ctx, base);
loc_82220A28:
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

DEFINE_REX_FUNC(sub_82221030) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x82221038;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// bl 0x82220bd8
	ctx.lr = 0x82221044;
	sub_82220BD8(ctx, base);
	// bl 0x825b3a80
	ctx.lr = 0x82221048;
	sub_825B3A80(ctx, base);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r24,r11,22392
	ctx.r24.s64 = ctx.r11.s64 + 22392;
	// li r4,28
	ctx.r4.s64 = 28;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x82221060;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r26,0
	ctx.r26.s64 = 0;
	// beq 0x82221090
	if (ctx.cr0.eq) goto loc_82221090;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r26,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r26.u32);
	// stw r26,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r26.u32);
	// stw r26,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r26.u32);
	// stw r26,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r26.u32);
	// stw r26,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r26.u32);
	// stw r26,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r26.u32);
	// stw r3,-9716(r11)
	REX_STORE_U32(ctx.r11.u32 + -9716, ctx.r3.u32);
	// b 0x8222109c
	goto loc_8222109C;
loc_82221090:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9716(r10)
	REX_STORE_U32(ctx.r10.u32 + -9716, ctx.r26.u32);
loc_8222109C:
	// bl 0x825c2280
	ctx.lr = 0x822210A0;
	sub_825C2280(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,332
	ctx.r4.s64 = 332;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x822210B0;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822210c8
	if (ctx.cr0.eq) goto loc_822210C8;
	// bl 0x825b74c8
	ctx.lr = 0x822210BC;
	sub_825B74C8(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,-9748(r11)
	REX_STORE_U32(ctx.r11.u32 + -9748, ctx.r3.u32);
	// b 0x822210d4
	goto loc_822210D4;
loc_822210C8:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9748(r10)
	REX_STORE_U32(ctx.r10.u32 + -9748, ctx.r26.u32);
loc_822210D4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// li r4,168
	ctx.r4.s64 = 168;
	// bl 0x825fc4b0
	ctx.lr = 0x822210E4;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221104
	if (ctx.cr0.eq) goto loc_82221104;
	// li r4,2048
	ctx.r4.s64 = 2048;
	// bl 0x825b45e0
	ctx.lr = 0x822210F4;
	sub_825B45E0(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r30,r11,-9752
	ctx.r30.s64 = ctx.r11.s64 + -9752;
	// stw r3,-9752(r11)
	REX_STORE_U32(ctx.r11.u32 + -9752, ctx.r3.u32);
	// b 0x82221114
	goto loc_82221114;
loc_82221104:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// addi r30,r10,-9752
	ctx.r30.s64 = ctx.r10.s64 + -9752;
	// stw r26,-9752(r10)
	REX_STORE_U32(ctx.r10.u32 + -9752, ctx.r26.u32);
loc_82221114:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x825fc4b0
	ctx.lr = 0x82221124;
	sub_825FC4B0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82221190
	if (ctx.cr0.eq) goto loc_82221190;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// addi r7,r11,18576
	ctx.r7.s64 = ctx.r11.s64 + 18576;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,8
	ctx.r10.s64 = 524288;
	// stw r7,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// stw r11,-13412(r9)
	REX_STORE_U32(ctx.r9.u32 + -13412, ctx.r11.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r10,-13408(r8)
	REX_STORE_U32(ctx.r8.u32 + -13408, ctx.r10.u32);
	// lis r4,32
	ctx.r4.s64 = 2097152;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x825fc4b0
	ctx.lr = 0x82221160;
	sub_825FC4B0(ctx, base);
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r11,16
	ctx.r11.s64 = 16;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// addi r10,r10,-13432
	ctx.r10.s64 = ctx.r10.s64 + -13432;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stw r3,-13416(r8)
	REX_STORE_U32(ctx.r8.u32 + -13416, ctx.r3.u32);
loc_82221180:
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82221180
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82221180;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x82221194
	goto loc_82221194;
loc_82221190:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_82221194:
	// bl 0x825b43a0
	ctx.lr = 0x82221198;
	sub_825B43A0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x822211A8;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822211c0
	if (ctx.cr0.eq) goto loc_822211C0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,1164
	ctx.r11.s64 = ctx.r11.s64 + 1164;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x822211c4
	goto loc_822211C4;
loc_822211C0:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_822211C4:
	// bl 0x825b43a0
	ctx.lr = 0x822211C8;
	sub_825B43A0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x822211D8;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822211f0
	if (ctx.cr0.eq) goto loc_822211F0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,1188
	ctx.r11.s64 = ctx.r11.s64 + 1188;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x822211f4
	goto loc_822211F4;
loc_822211F0:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_822211F4:
	// bl 0x825b43a0
	ctx.lr = 0x822211F8;
	sub_825B43A0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x82221208;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221220
	if (ctx.cr0.eq) goto loc_82221220;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,1212
	ctx.r11.s64 = ctx.r11.s64 + 1212;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x82221224
	goto loc_82221224;
loc_82221220:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_82221224:
	// bl 0x825b43a0
	ctx.lr = 0x82221228;
	sub_825B43A0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x82221238;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221250
	if (ctx.cr0.eq) goto loc_82221250;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,1236
	ctx.r11.s64 = ctx.r11.s64 + 1236;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x82221254
	goto loc_82221254;
loc_82221250:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_82221254:
	// bl 0x825b43a0
	ctx.lr = 0x82221258;
	sub_825B43A0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r5,r11,1012
	ctx.r5.s64 = ctx.r11.s64 + 1012;
	// addi r4,r10,1024
	ctx.r4.s64 = ctx.r10.s64 + 1024;
	// bl 0x825b51e8
	ctx.lr = 0x82221270;
	sub_825B51E8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1496
	ctx.r4.s64 = 1496;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x825fc4b0
	ctx.lr = 0x82221280;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221298
	if (ctx.cr0.eq) goto loc_82221298;
	// bl 0x825c4588
	ctx.lr = 0x8222128C;
	sub_825C4588(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,-9696(r11)
	REX_STORE_U32(ctx.r11.u32 + -9696, ctx.r3.u32);
	// b 0x822212a4
	goto loc_822212A4;
loc_82221298:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9696(r10)
	REX_STORE_U32(ctx.r10.u32 + -9696, ctx.r26.u32);
loc_822212A4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,312
	ctx.r4.s64 = 312;
	// bl 0x825fc4b0
	ctx.lr = 0x822212B4;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822212cc
	if (ctx.cr0.eq) goto loc_822212CC;
	// bl 0x82444fa0
	ctx.lr = 0x822212C0;
	sub_82444FA0(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,-9884(r11)
	REX_STORE_U32(ctx.r11.u32 + -9884, ctx.r3.u32);
	// b 0x822212d8
	goto loc_822212D8;
loc_822212CC:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9884(r10)
	REX_STORE_U32(ctx.r10.u32 + -9884, ctx.r26.u32);
loc_822212D8:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lfs f0,13668(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13668);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-13252(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + -13252, temp.u32);
	// bl 0x825c0090
	ctx.lr = 0x822212EC;
	sub_825C0090(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,-13252(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -13252);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32113
	ctx.r10.s64 = -2104557568;
	// addi r28,r11,-28872
	ctx.r28.s64 = ctx.r11.s64 + -28872;
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// li r11,2
	ctx.r11.s64 = 2;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// stw r11,20668(r10)
	REX_STORE_U32(ctx.r10.u32 + 20668, ctx.r11.u32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r10,2
	ctx.r10.s64 = 2;
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// stw r10,-13236(r9)
	REX_STORE_U32(ctx.r9.u32 + -13236, ctx.r10.u32);
	// stfs f0,-13240(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13240, temp.u32);
	// lwz r11,-9792(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9792);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82221360
	if (!ctx.cr6.eq) goto loc_82221360;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,10096
	ctx.r4.s64 = 10096;
	// bl 0x825fc4b0
	ctx.lr = 0x82221340;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221354
	if (ctx.cr0.eq) goto loc_82221354;
	// bl 0x82476428
	ctx.lr = 0x8222134C;
	sub_82476428(ctx, base);
	// stw r3,-9792(r31)
	REX_STORE_U32(ctx.r31.u32 + -9792, ctx.r3.u32);
	// b 0x8222135c
	goto loc_8222135C;
loc_82221354:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9792(r31)
	REX_STORE_U32(ctx.r31.u32 + -9792, ctx.r26.u32);
loc_8222135C:
	// bl 0x82476ce0
	ctx.lr = 0x82221360;
	sub_82476CE0(ctx, base);
loc_82221360:
	// bl 0x825c7210
	ctx.lr = 0x82221364;
	sub_825C7210(ctx, base);
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9800(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9800);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822213a4
	if (!ctx.cr6.eq) goto loc_822213A4;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,768
	ctx.r4.s64 = 768;
	// bl 0x825fc4b0
	ctx.lr = 0x82221384;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221398
	if (ctx.cr0.eq) goto loc_82221398;
	// bl 0x82472b68
	ctx.lr = 0x82221390;
	sub_82472B68(ctx, base);
	// stw r3,-9800(r31)
	REX_STORE_U32(ctx.r31.u32 + -9800, ctx.r3.u32);
	// b 0x822213a0
	goto loc_822213A0;
loc_82221398:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9800(r31)
	REX_STORE_U32(ctx.r31.u32 + -9800, ctx.r26.u32);
loc_822213A0:
	// bl 0x82471b10
	ctx.lr = 0x822213A4;
	sub_82471B10(ctx, base);
loc_822213A4:
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9796(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9796);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822213c8
	if (!ctx.cr6.eq) goto loc_822213C8;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x825fc4b0
	ctx.lr = 0x822213C4;
	sub_825FC4B0(ctx, base);
	// stw r3,-9796(r31)
	REX_STORE_U32(ctx.r31.u32 + -9796, ctx.r3.u32);
loc_822213C8:
	// bl 0x82475238
	ctx.lr = 0x822213CC;
	sub_82475238(ctx, base);
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9808(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9808);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82221408
	if (!ctx.cr6.eq) goto loc_82221408;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// li r4,56
	ctx.r4.s64 = 56;
	// bl 0x825fc4b0
	ctx.lr = 0x822213EC;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221400
	if (ctx.cr0.eq) goto loc_82221400;
	// bl 0x824709d0
	ctx.lr = 0x822213F8;
	sub_824709D0(ctx, base);
	// stw r3,-9808(r31)
	REX_STORE_U32(ctx.r31.u32 + -9808, ctx.r3.u32);
	// b 0x82221408
	goto loc_82221408;
loc_82221400:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9808(r31)
	REX_STORE_U32(ctx.r31.u32 + -9808, ctx.r26.u32);
loc_82221408:
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9804);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82221450
	if (!ctx.cr6.eq) goto loc_82221450;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,80
	ctx.r4.s64 = 80;
	// bl 0x825fc4b0
	ctx.lr = 0x82221428;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221444
	if (ctx.cr0.eq) goto loc_82221444;
	// stw r26,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r26.u32);
	// stw r26,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r26.u32);
	// stw r26,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r26.u32);
	// stw r3,-9804(r31)
	REX_STORE_U32(ctx.r31.u32 + -9804, ctx.r3.u32);
	// b 0x8222144c
	goto loc_8222144C;
loc_82221444:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9804(r31)
	REX_STORE_U32(ctx.r31.u32 + -9804, ctx.r26.u32);
loc_8222144C:
	// bl 0x82470e80
	ctx.lr = 0x82221450;
	sub_82470E80(ctx, base);
loc_82221450:
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9952(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8222148c
	if (!ctx.cr6.eq) goto loc_8222148C;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,176
	ctx.r4.s64 = 176;
	// bl 0x825fc4b0
	ctx.lr = 0x82221470;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221484
	if (ctx.cr0.eq) goto loc_82221484;
	// bl 0x823ccf60
	ctx.lr = 0x8222147C;
	sub_823CCF60(ctx, base);
	// stw r3,-9952(r31)
	REX_STORE_U32(ctx.r31.u32 + -9952, ctx.r3.u32);
	// b 0x8222148c
	goto loc_8222148C;
loc_82221484:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9952(r31)
	REX_STORE_U32(ctx.r31.u32 + -9952, ctx.r26.u32);
loc_8222148C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x825fc4b0
	ctx.lr = 0x8222149C;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822214b4
	if (ctx.cr0.eq) goto loc_822214B4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,1276
	ctx.r11.s64 = ctx.r11.s64 + 1276;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x822214b8
	goto loc_822214B8;
loc_822214B4:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_822214B8:
	// bl 0x825b43a0
	ctx.lr = 0x822214BC;
	sub_825B43A0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x822214CC;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822214e4
	if (ctx.cr0.eq) goto loc_822214E4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,1300
	ctx.r11.s64 = ctx.r11.s64 + 1300;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x822214e8
	goto loc_822214E8;
loc_822214E4:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_822214E8:
	// bl 0x825b43a0
	ctx.lr = 0x822214EC;
	sub_825B43A0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x822214FC;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221514
	if (ctx.cr0.eq) goto loc_82221514;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,1324
	ctx.r11.s64 = ctx.r11.s64 + 1324;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x82221518
	goto loc_82221518;
loc_82221514:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_82221518:
	// bl 0x825b43a0
	ctx.lr = 0x8222151C;
	sub_825B43A0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x8222152C;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221544
	if (ctx.cr0.eq) goto loc_82221544;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,1348
	ctx.r11.s64 = ctx.r11.s64 + 1348;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x82221548
	goto loc_82221548;
loc_82221544:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_82221548:
	// bl 0x825b43a0
	ctx.lr = 0x8222154C;
	sub_825B43A0(ctx, base);
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9956(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9956);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82221588
	if (!ctx.cr6.eq) goto loc_82221588;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x825fc4b0
	ctx.lr = 0x8222156C;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221580
	if (ctx.cr0.eq) goto loc_82221580;
	// bl 0x823cafd8
	ctx.lr = 0x82221578;
	sub_823CAFD8(ctx, base);
	// stw r3,-9956(r31)
	REX_STORE_U32(ctx.r31.u32 + -9956, ctx.r3.u32);
	// b 0x82221588
	goto loc_82221588;
loc_82221580:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9956(r31)
	REX_STORE_U32(ctx.r31.u32 + -9956, ctx.r26.u32);
loc_82221588:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// li r4,188
	ctx.r4.s64 = 188;
	// bl 0x825fc4b0
	ctx.lr = 0x82221598;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822215b0
	if (ctx.cr0.eq) goto loc_822215B0;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r4,r11,-9052
	ctx.r4.s64 = ctx.r11.s64 + -9052;
	// bl 0x823d2280
	ctx.lr = 0x822215AC;
	sub_823D2280(ctx, base);
	// b 0x822215b4
	goto loc_822215B4;
loc_822215B0:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_822215B4:
	// lis r29,-32110
	ctx.r29.s64 = -2104360960;
	// stw r3,80(r23)
	REX_STORE_U32(ctx.r23.u32 + 80, ctx.r3.u32);
	// lwz r3,-9992(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -9992);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82221650
	if (!ctx.cr6.eq) goto loc_82221650;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,72
	ctx.r4.s64 = 72;
	// bl 0x825fc4b0
	ctx.lr = 0x822215D8;
	sub_825FC4B0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82221648
	if (ctx.cr0.eq) goto loc_82221648;
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// bl 0x825fc4b0
	ctx.lr = 0x822215F8;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221608
	if (ctx.cr0.eq) goto loc_82221608;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// b 0x8222160c
	goto loc_8222160C;
loc_82221608:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_8222160C:
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r26,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r26,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r26.u32);
	// stw r26,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r26.u32);
	// stw r26,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r26.u32);
	// stw r26,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r26.u32);
	// stw r26,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r26.u32);
	// stw r26,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r26.u32);
	// stw r26,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r26.u32);
	// stw r26,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r26.u32);
	// stw r26,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r26.u32);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// b 0x8222164c
	goto loc_8222164C;
loc_82221648:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_8222164C:
	// stw r3,-9992(r29)
	REX_STORE_U32(ctx.r29.u32 + -9992, ctx.r3.u32);
loc_82221650:
	// bl 0x823708c0
	ctx.lr = 0x82221654;
	sub_823708C0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,2968
	ctx.r11.s64 = ctx.r11.s64 + 2968;
	// addi r10,r10,4804
	ctx.r10.s64 = ctx.r10.s64 + 4804;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r29,-32110
	ctx.r29.s64 = -2104360960;
	// addi r30,r11,-24024
	ctx.r30.s64 = ctx.r11.s64 + -24024;
loc_8222167C:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_82221688:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82221688
	if (!ctx.cr6.eq) goto loc_82221688;
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// lwz r10,-12436(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + -12436);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x822216B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stwx r3,r31,r30
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, ctx.r3.u32);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r31,8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8, ctx.xer);
	// blt cr6,0x8222167c
	if (ctx.cr6.lt) goto loc_8222167C;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 48);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x825fc4b0
	ctx.lr = 0x822216D0;
	sub_825FC4B0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8222170c
	if (ctx.cr0.eq) goto loc_8222170C;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 48);
	// li r4,108
	ctx.r4.s64 = 108;
	// bl 0x825fc4b0
	ctx.lr = 0x822216E8;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822216f8
	if (ctx.cr0.eq) goto loc_822216F8;
	// bl 0x82232210
	ctx.lr = 0x822216F4;
	sub_82232210(ctx, base);
	// b 0x822216fc
	goto loc_822216FC;
loc_822216F8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_822216FC:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// stw r31,-10000(r11)
	REX_STORE_U32(ctx.r11.u32 + -10000, ctx.r31.u32);
	// b 0x82221718
	goto loc_82221718;
loc_8222170C:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-10000(r10)
	REX_STORE_U32(ctx.r10.u32 + -10000, ctx.r26.u32);
loc_82221718:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x825fc4b0
	ctx.lr = 0x82221728;
	sub_825FC4B0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82221764
	if (ctx.cr0.eq) goto loc_82221764;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// li r4,144
	ctx.r4.s64 = 144;
	// bl 0x825fc4b0
	ctx.lr = 0x82221740;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221750
	if (ctx.cr0.eq) goto loc_82221750;
	// bl 0x822254a8
	ctx.lr = 0x8222174C;
	sub_822254A8(ctx, base);
	// b 0x82221754
	goto loc_82221754;
loc_82221750:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_82221754:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// stw r31,-10012(r11)
	REX_STORE_U32(ctx.r11.u32 + -10012, ctx.r31.u32);
	// b 0x82221770
	goto loc_82221770;
loc_82221764:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-10012(r10)
	REX_STORE_U32(ctx.r10.u32 + -10012, ctx.r26.u32);
loc_82221770:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x825fc4b0
	ctx.lr = 0x82221780;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221798
	if (ctx.cr0.eq) goto loc_82221798;
	// bl 0x825a6c78
	ctx.lr = 0x8222178C;
	sub_825A6C78(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,-9768(r11)
	REX_STORE_U32(ctx.r11.u32 + -9768, ctx.r3.u32);
	// b 0x822217a4
	goto loc_822217A4;
loc_82221798:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9768(r10)
	REX_STORE_U32(ctx.r10.u32 + -9768, ctx.r26.u32);
loc_822217A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825c0558
	ctx.lr = 0x822217AC;
	sub_825C0558(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825c07c8
	ctx.lr = 0x822217B8;
	sub_825C07C8(ctx, base);
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// addi r10,r28,22704
	ctx.r10.s64 = ctx.r28.s64 + 22704;
	// addi r31,r9,-7340
	ctx.r31.s64 = ctx.r9.s64 + -7340;
	// lis r11,256
	ctx.r11.s64 = 16777216;
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r10,-7340(r9)
	REX_STORE_U32(ctx.r9.u32 + -7340, ctx.r10.u32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lis r3,256
	ctx.r3.s64 = 16777216;
	// bl 0x826559d0
	ctx.lr = 0x822217E4;
	sub_826559D0(ctx, base);
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82590ed0
	ctx.lr = 0x822217F0;
	sub_82590ED0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825910f0
	ctx.lr = 0x822217F8;
	sub_825910F0(ctx, base);
loc_822217F8:
	// bl 0x82591728
	ctx.lr = 0x822217FC;
	sub_82591728(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822217f8
	if (!ctx.cr0.eq) goto loc_822217F8;
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lwz r10,7044(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 7044);
	// lwz r11,-9880(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9880);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stw r10,-13436(r9)
	REX_STORE_U32(ctx.r9.u32 + -13436, ctx.r10.u32);
	// bne cr6,0x822218a0
	if (!ctx.cr6.eq) goto loc_822218A0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,44
	ctx.r4.s64 = 44;
	// bl 0x825fc4b0
	ctx.lr = 0x8222183C;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221864
	if (ctx.cr0.eq) goto loc_82221864;
	// stw r26,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r26.u32);
	// stw r26,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r26.u32);
	// stw r26,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r26.u32);
	// stw r26,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r26.u32);
	// stw r26,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r26.u32);
	// stw r26,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r26.u32);
	// stw r3,-9880(r31)
	REX_STORE_U32(ctx.r31.u32 + -9880, ctx.r3.u32);
	// b 0x8222186c
	goto loc_8222186C;
loc_82221864:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9880(r31)
	REX_STORE_U32(ctx.r31.u32 + -9880, ctx.r26.u32);
loc_8222186C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,24
	ctx.r4.s64 = 24;
	// bl 0x825fc4b0
	ctx.lr = 0x8222187C;
	sub_825FC4B0(ctx, base);
	// lwz r11,-9880(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9880);
	// li r9,6
	ctx.r9.s64 = 6;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// stw r3,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r3.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82221890:
	// lwz r9,20(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// stwx r26,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r26.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82221890
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82221890;
loc_822218A0:
	// stb r26,40(r11)
	REX_STORE_U8(ctx.r11.u32 + 40, ctx.r26.u8);
	// bl 0x823c76a0
	ctx.lr = 0x822218A8;
	sub_823C76A0(ctx, base);
	// bl 0x825b5180
	ctx.lr = 0x822218AC;
	sub_825B5180(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,228
	ctx.r4.s64 = 228;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x822218BC;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822218d4
	if (ctx.cr0.eq) goto loc_822218D4;
	// bl 0x825bdfe0
	ctx.lr = 0x822218C8;
	sub_825BDFE0(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,-9744(r11)
	REX_STORE_U32(ctx.r11.u32 + -9744, ctx.r3.u32);
	// b 0x822218e0
	goto loc_822218E0;
loc_822218D4:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9744(r10)
	REX_STORE_U32(ctx.r10.u32 + -9744, ctx.r26.u32);
loc_822218E0:
	// bl 0x822233d8
	ctx.lr = 0x822218E4;
	sub_822233D8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,120
	ctx.r4.s64 = 120;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x822218F4;
	sub_825FC4B0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// li r25,1
	ctx.r25.s64 = 1;
	// beq 0x82221944
	if (ctx.cr0.eq) goto loc_82221944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822232d8
	ctx.lr = 0x82221908;
	sub_822232D8(ctx, base);
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r26,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r26.u32);
	// addi r3,r31,68
	ctx.r3.s64 = ctx.r31.s64 + 68;
	// stw r26,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r26.u32);
	// stw r26,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r26.u32);
	// stb r26,36(r31)
	REX_STORE_U8(ctx.r31.u32 + 36, ctx.r26.u8);
	// stw r26,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r26.u32);
	// bl 0x82756d30
	ctx.lr = 0x8222192C;
	sub_82756D30(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r26,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r26.u32);
	// stw r25,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r25.u32);
	// stw r26,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r26.u32);
	// stw r31,-10008(r11)
	REX_STORE_U32(ctx.r11.u32 + -10008, ctx.r31.u32);
	// b 0x82221950
	goto loc_82221950;
loc_82221944:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-10008(r10)
	REX_STORE_U32(ctx.r10.u32 + -10008, ctx.r26.u32);
loc_82221950:
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9764(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9764);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822219b0
	if (!ctx.cr6.eq) goto loc_822219B0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,1048
	ctx.r4.s64 = 1048;
	// bl 0x825fc4b0
	ctx.lr = 0x82221970;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8222198c
	if (ctx.cr0.eq) goto loc_8222198C;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r26,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r26.u32);
	// stw r26,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r26.u32);
	// stw r26,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r26.u32);
	// b 0x82221990
	goto loc_82221990;
loc_8222198C:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_82221990:
	// stw r11,-9764(r31)
	REX_STORE_U32(ctx.r31.u32 + -9764, ctx.r11.u32);
	// li r5,1032
	ctx.r5.s64 = 1032;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x82655b00
	ctx.lr = 0x822219A4;
	sub_82655B00(ctx, base);
	// lwz r11,-9764(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9764);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822219bc
	if (ctx.cr6.eq) goto loc_822219BC;
loc_822219B0:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825b36a8
	ctx.lr = 0x822219BC;
	sub_825B36A8(ctx, base);
loc_822219BC:
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9784(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9784);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822219fc
	if (!ctx.cr6.eq) goto loc_822219FC;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,272
	ctx.r4.s64 = 272;
	// bl 0x825fc4b0
	ctx.lr = 0x822219DC;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822219f0
	if (ctx.cr0.eq) goto loc_822219F0;
	// bl 0x82592340
	ctx.lr = 0x822219E8;
	sub_82592340(ctx, base);
	// stw r3,-9784(r31)
	REX_STORE_U32(ctx.r31.u32 + -9784, ctx.r3.u32);
	// b 0x822219f8
	goto loc_822219F8;
loc_822219F0:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9784(r31)
	REX_STORE_U32(ctx.r31.u32 + -9784, ctx.r26.u32);
loc_822219F8:
	// bl 0x82592a28
	ctx.lr = 0x822219FC;
	sub_82592A28(ctx, base);
loc_822219FC:
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9996(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9996);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82221a3c
	if (!ctx.cr6.eq) goto loc_82221A3C;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,700
	ctx.r4.s64 = 700;
	// bl 0x825fc4b0
	ctx.lr = 0x82221A1C;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221a30
	if (ctx.cr0.eq) goto loc_82221A30;
	// bl 0x8224b0c0
	ctx.lr = 0x82221A28;
	sub_8224B0C0(ctx, base);
	// stw r3,-9996(r31)
	REX_STORE_U32(ctx.r31.u32 + -9996, ctx.r3.u32);
	// b 0x82221a38
	goto loc_82221A38;
loc_82221A30:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9996(r31)
	REX_STORE_U32(ctx.r31.u32 + -9996, ctx.r26.u32);
loc_82221A38:
	// bl 0x8224ba98
	ctx.lr = 0x82221A3C;
	sub_8224BA98(ctx, base);
loc_82221A3C:
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9788(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82221a7c
	if (!ctx.cr6.eq) goto loc_82221A7C;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,140
	ctx.r4.s64 = 140;
	// bl 0x825fc4b0
	ctx.lr = 0x82221A5C;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221a70
	if (ctx.cr0.eq) goto loc_82221A70;
	// bl 0x82486228
	ctx.lr = 0x82221A68;
	sub_82486228(ctx, base);
	// stw r3,-9788(r31)
	REX_STORE_U32(ctx.r31.u32 + -9788, ctx.r3.u32);
	// b 0x82221a78
	goto loc_82221A78;
loc_82221A70:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9788(r31)
	REX_STORE_U32(ctx.r31.u32 + -9788, ctx.r26.u32);
loc_82221A78:
	// bl 0x82486550
	ctx.lr = 0x82221A7C;
	sub_82486550(ctx, base);
loc_82221A7C:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lfs f11,17956(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 17956);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32227
	ctx.r8.s64 = -2112028672;
	// addi r9,r9,-2512
	ctx.r9.s64 = ctx.r9.s64 + -2512;
	// lwa r11,-12372(r11)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r11.u32 + -12372));
	// lis r7,-32110
	ctx.r7.s64 = -2104360960;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r6,r8,3232
	ctx.r6.s64 = ctx.r8.s64 + 3232;
	// lwa r10,-12360(r10)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r10.u32 + -12360));
	// addi r11,r7,-23940
	ctx.r11.s64 = ctx.r7.s64 + -23940;
	// lfs f10,3232(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 3232);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,15168(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 15168);
	ctx.f9.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// frsp f8,f12
	ctx.f8.f64 = double(float(ctx.f12.f64));
	// lfs f0,456(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 456);
	ctx.f0.f64 = double(temp.f32);
	// fcfid f7,f13
	ctx.f7.f64 = double(ctx.f13.s64);
	// lfs f13,460(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 460);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f8,f0
	ctx.f0.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stfs f0,-232(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + -232, temp.u32);
	// frsp f8,f7
	ctx.f8.f64 = double(float(ctx.f7.f64));
	// fmuls f12,f0,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// stfs f12,24(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// fmuls f13,f8,f13
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f13,-384(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + -384, temp.u32);
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f0,16(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// fmuls f11,f13,f10
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// stfs f11,20(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// fmuls f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f0,12(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// fadds f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f11.f64));
	// stfs f13,-23940(r7)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r7.u32 + -23940, temp.u32);
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// bl 0x823d8b30
	ctx.lr = 0x82221B28;
	sub_823D8B30(ctx, base);
	// lis r30,-32110
	ctx.r30.s64 = -2104360960;
	// lwz r11,-9900(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -9900);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82221b90
	if (!ctx.cr6.eq) goto loc_82221B90;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x825fc4b0
	ctx.lr = 0x82221B48;
	sub_825FC4B0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82221b88
	if (ctx.cr0.eq) goto loc_82221B88;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// li r4,1344
	ctx.r4.s64 = 1344;
	// bl 0x825fc4b0
	ctx.lr = 0x82221B60;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82221b74
	if (ctx.cr0.eq) goto loc_82221B74;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82416d10
	ctx.lr = 0x82221B70;
	sub_82416D10(ctx, base);
	// b 0x82221b78
	goto loc_82221B78;
loc_82221B74:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_82221B78:
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// bl 0x82416e50
	ctx.lr = 0x82221B80;
	sub_82416E50(ctx, base);
	// stw r31,-9900(r30)
	REX_STORE_U32(ctx.r30.u32 + -9900, ctx.r31.u32);
	// b 0x82221b90
	goto loc_82221B90;
loc_82221B88:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,-9900(r30)
	REX_STORE_U32(ctx.r30.u32 + -9900, ctx.r26.u32);
loc_82221B90:
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// addi r31,r11,7864
	ctx.r31.s64 = ctx.r11.s64 + 7864;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// std r26,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r26.u64);
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// std r26,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r26.u64);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// std r26,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r26.u64);
	// stw r26,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// stw r26,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r26.u32);
	// addi r30,r31,336
	ctx.r30.s64 = ctx.r31.s64 + 336;
	// stb r26,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r26.u8);
	// stw r26,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r26.u32);
	// stb r26,36(r31)
	REX_STORE_U8(ctx.r31.u32 + 36, ctx.r26.u8);
	// stw r26,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r26.u32);
	// stw r26,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r26.u32);
	// stw r26,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r26.u32);
	// stw r26,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r26.u32);
	// stw r26,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r26.u32);
	// stw r26,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r26.u32);
	// stw r26,5780(r31)
	REX_STORE_U32(ctx.r31.u32 + 5780, ctx.r26.u32);
	// stw r26,5784(r31)
	REX_STORE_U32(ctx.r31.u32 + 5784, ctx.r26.u32);
	// stw r26,5788(r31)
	REX_STORE_U32(ctx.r31.u32 + 5788, ctx.r26.u32);
	// stw r26,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r26.u32);
	// stw r26,5792(r31)
	REX_STORE_U32(ctx.r31.u32 + 5792, ctx.r26.u32);
	// stw r26,5776(r31)
	REX_STORE_U32(ctx.r31.u32 + 5776, ctx.r26.u32);
loc_82221C10:
	// slw r11,r25,r29
	ctx.r11.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r25.u32 << (ctx.r29.u8 & 0x3F));
	// clrlwi. r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82221c40
	if (ctx.cr0.eq) goto loc_82221C40;
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// li r28,20
	ctx.r28.s64 = 20;
loc_82221C24:
	// li r5,136
	ctx.r5.s64 = 136;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82655b00
	ctx.lr = 0x82221C34;
	sub_82655B00(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r27,r27,136
	ctx.r27.s64 = ctx.r27.s64 + 136;
	// bne 0x82221c24
	if (!ctx.cr0.eq) goto loc_82221C24;
loc_82221C40:
	// addi r30,r30,2720
	ctx.r30.s64 = ctx.r30.s64 + 2720;
	// addi r11,r31,5776
	ctx.r11.s64 = ctx.r31.s64 + 5776;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82221c10
	if (ctx.cr6.lt) goto loc_82221C10;
	// lis r30,-32110
	ctx.r30.s64 = -2104360960;
	// lwz r11,-9772(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -9772);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82221cb4
	if (!ctx.cr6.eq) goto loc_82221CB4;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,224
	ctx.r4.s64 = 224;
	// bl 0x825fc4b0
	ctx.lr = 0x82221C74;
	sub_825FC4B0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82221cac
	if (ctx.cr0.eq) goto loc_82221CAC;
	// stw r26,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// stw r26,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r26.u32);
	// stw r26,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r26.u32);
	// bl 0x825a6f30
	ctx.lr = 0x82221C90;
	sub_825A6F30(ctx, base);
	// addi r3,r31,164
	ctx.r3.s64 = ctx.r31.s64 + 164;
	// bl 0x822232d8
	ctx.lr = 0x82221C98;
	sub_822232D8(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r26,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r26.u32);
	// stw r26,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r26.u32);
	// stw r26,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r26.u32);
	// b 0x82221cb0
	goto loc_82221CB0;
loc_82221CAC:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_82221CB0:
	// stw r11,-9772(r30)
	REX_STORE_U32(ctx.r30.u32 + -9772, ctx.r11.u32);
loc_82221CB4:
	// lis r30,-32110
	ctx.r30.s64 = -2104360960;
	// stw r26,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r26.u32);
	// stw r26,196(r11)
	REX_STORE_U32(ctx.r11.u32 + 196, ctx.r26.u32);
	// stw r26,200(r11)
	REX_STORE_U32(ctx.r11.u32 + 200, ctx.r26.u32);
	// lwz r31,-10004(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + -10004);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82221ce8
	if (!ctx.cr6.eq) goto loc_82221CE8;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// li r4,812
	ctx.r4.s64 = 812;
	// bl 0x825fc4b0
	ctx.lr = 0x82221CE0;
	sub_825FC4B0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r3,-10004(r30)
	REX_STORE_U32(ctx.r30.u32 + -10004, ctx.r3.u32);
loc_82221CE8:
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x82756d30
	ctx.lr = 0x82221CF8;
	sub_82756D30(ctx, base);
	// stw r26,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r26.u32);
	// stw r26,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
	// stw r26,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r26.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x82220a40
	ctx.lr = 0x82221D0C;
	sub_82220A40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82266318) {
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
	// ld r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 88);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x822661c0
	ctx.lr = 0x82266340;
	sub_822661C0(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r9,r9,62480
	ctx.r9.u64 = ctx.r9.u64 | 62480;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,12484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfsx f0,r31,r9
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x822663b0
	if (ctx.cr6.gt) goto loc_822663B0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_822663B0:
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

DEFINE_REX_FUNC(sub_82272450) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x82272458;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r3,11
	ctx.r3.s64 = 11;
	// addi r11,r11,8608
	ctx.r11.s64 = ctx.r11.s64 + 8608;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// bl 0x82441690
	ctx.lr = 0x82272478;
	sub_82441690(ctx, base);
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r11,r11,-2400
	ctx.r11.s64 = ctx.r11.s64 + -2400;
	// lbz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82272494
	if (ctx.cr0.eq) goto loc_82272494;
	// stb r31,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r31.u8);
loc_82272494:
	// bl 0x825fc6d0
	ctx.lr = 0x82272498;
	sub_825FC6D0(ctx, base);
	// addis r28,r30,1
	ctx.r28.s64 = ctx.r30.s64 + 65536;
	// addi r28,r28,-3072
	ctx.r28.s64 = ctx.r28.s64 + -3072;
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822724b0
	if (ctx.cr6.eq) goto loc_822724B0;
	// bl 0x825fc588
	ctx.lr = 0x822724B0;
	sub_825FC588(ctx, base);
loc_822724B0:
	// addis r29,r30,1
	ctx.r29.s64 = ctx.r30.s64 + 65536;
	// stw r31,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
	// stw r31,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r31.u32);
	// addi r29,r29,-3132
	ctx.r29.s64 = ctx.r29.s64 + -3132;
	// stw r31,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r31.u32);
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822724d4
	if (ctx.cr6.eq) goto loc_822724D4;
	// bl 0x825fc588
	ctx.lr = 0x822724D4;
	sub_825FC588(ctx, base);
loc_822724D4:
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// addis r28,r30,1
	ctx.r28.s64 = ctx.r30.s64 + 65536;
	// stw r31,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
	// addi r28,r28,-3148
	ctx.r28.s64 = ctx.r28.s64 + -3148;
	// stw r31,12(r29)
	REX_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// lwz r3,4(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822724f8
	if (ctx.cr6.eq) goto loc_822724F8;
	// bl 0x825fc588
	ctx.lr = 0x822724F8;
	sub_825FC588(ctx, base);
loc_822724F8:
	// stw r31,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r31.u32);
	// stw r31,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r31.u32);
	// bl 0x82241df0
	ctx.lr = 0x8227250C;
	sub_82241DF0(ctx, base);
	// clrlwi. r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8227251c
	if (ctx.cr0.eq) goto loc_8227251C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825fc588
	ctx.lr = 0x8227251C;
	sub_825FC588(ctx, base);
loc_8227251C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8227A4A8) {
	REX_FUNC_PROLOGUE();
	// lbz r3,280(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 280);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8227A6E8) {
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
	// addis r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 65536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r10,r10,-3088
	ctx.r10.s64 = ctx.r10.s64 + -3088;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8227a730
	if (ctx.cr6.eq) goto loc_8227A730;
	// lbz r9,23(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x8227a730
	if (!ctx.cr0.eq) goto loc_8227A730;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r9,23(r11)
	REX_STORE_U8(ctx.r11.u32 + 23, ctx.r9.u8);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_8227A730:
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// addi r31,r31,-3072
	ctx.r31.s64 = ctx.r31.s64 + -3072;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8227a758
	if (ctx.cr6.eq) goto loc_8227A758;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822329c8
	ctx.lr = 0x8227A750;
	sub_822329C8(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8227A758:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82242490
	ctx.lr = 0x8227A760;
	sub_82242490(ctx, base);
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

DEFINE_REX_FUNC(sub_82281580) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756684
	ctx.lr = 0x82281588;
	__savegprlr_15(ctx, base);
	// stfd f31,-152(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -152, ctx.f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,5664
	ctx.r4.s64 = ctx.r11.s64 + 5664;
	// bl 0x8223fbb0
	ctx.lr = 0x822815A0;
	sub_8223FBB0(ctx, base);
	// li r5,3
	ctx.r5.s64 = 3;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r30,0
	ctx.r30.s64 = 0;
	// ori r29,r10,62372
	ctx.r29.u64 = ctx.r10.u64 | 62372;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// ori r9,r3,62388
	ctx.r9.u64 = ctx.r3.u64 | 62388;
	// lis r6,0
	ctx.r6.s64 = 0;
	// addi r7,r11,12252
	ctx.r7.s64 = ctx.r11.s64 + 12252;
	// ori r3,r30,62392
	ctx.r3.u64 = ctx.r30.u64 | 62392;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f31,232(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// ori r6,r6,62380
	ctx.r6.u64 = ctx.r6.u64 | 62380;
	// stwx r30,r31,r29
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, ctx.r30.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stfsx f31,r31,r9
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// ori r8,r8,62376
	ctx.r8.u64 = ctx.r8.u64 | 62376;
	// stfsx f31,r31,r3
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, temp.u32);
	// ori r4,r4,62384
	ctx.r4.u64 = ctx.r4.u64 | 62384;
	// addi r11,r11,9336
	ctx.r11.s64 = ctx.r11.s64 + 9336;
	// addi r10,r10,-3140
	ctx.r10.s64 = ctx.r10.s64 + -3140;
	// li r29,-1
	ctx.r29.s64 = -1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r11,r10,-4
	ctx.r11.s64 = ctx.r10.s64 + -4;
	// stwx r30,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u32);
	// stwx r29,r31,r6
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r29.u32);
	// addi r9,r10,-40
	ctx.r9.s64 = ctx.r10.s64 + -40;
	// stwx r30,r31,r4
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, ctx.r30.u32);
	// lis r6,-32109
	ctx.r6.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
loc_8228162C:
	// ld r8,6848(r10)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r10.u32 + 6848);
	// stdu r8,40(r9)
	ea = 40 + ctx.r9.u32;
	REX_STORE_U64(ea, ctx.r8.u64);
	ctx.r9.u32 = ea;
	// ld r8,6848(r10)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r10.u32 + 6848);
	// std r8,12(r11)
	REX_STORE_U64(ctx.r11.u32 + 12, ctx.r8.u64);
	// ld r8,6848(r10)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r10.u32 + 6848);
	// std r8,20(r11)
	REX_STORE_U64(ctx.r11.u32 + 20, ctx.r8.u64);
	// ld r8,6272(r6)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r6.u32 + 6272);
	// stfs f31,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 36, temp.u32);
	// std r8,28(r11)
	REX_STORE_U64(ctx.r11.u32 + 28, ctx.r8.u64);
	// stfsu f31,40(r11)
	ea = 40 + ctx.r11.u32;
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8228162c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8228162C;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// addi r11,r11,-3023
	ctx.r11.s64 = ctx.r11.s64 + -3023;
loc_82281668:
	// ld r9,6848(r10)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r10.u32 + 6848);
	// stb r30,11(r11)
	REX_STORE_U8(ctx.r11.u32 + 11, ctx.r30.u8);
	// stdx r9,r11,r5
	REX_STORE_U64(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u64);
	// stbu r30,12(r11)
	ea = 12 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r30.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x82281668
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82281668;
	// li r9,30
	ctx.r9.s64 = 30;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2988
	ctx.r11.s64 = ctx.r11.s64 + -2988;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8228168C:
	// ld r9,6848(r10)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r10.u32 + 6848);
	// stfs f31,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// std r9,4(r11)
	REX_STORE_U64(ctx.r11.u32 + 4, ctx.r9.u64);
	// stbu r30,16(r11)
	ea = 16 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r30.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8228168c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8228168C;
	// li r9,2
	ctx.r9.s64 = 2;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2508
	ctx.r11.s64 = ctx.r11.s64 + -2508;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_822816B0:
	// ld r9,6848(r10)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r10.u32 + 6848);
	// stdu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U64(ea, ctx.r9.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x822816b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822816B0;
	// addis r20,r31,1
	ctx.r20.s64 = ctx.r31.s64 + 65536;
	// lfs f0,2640(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// addi r20,r20,-2484
	ctx.r20.s64 = ctx.r20.s64 + -2484;
	// ori r11,r11,63076
	ctx.r11.u64 = ctx.r11.u64 | 63076;
	// ori r10,r10,63080
	ctx.r10.u64 = ctx.r10.u64 | 63080;
	// ori r7,r7,63088
	ctx.r7.u64 = ctx.r7.u64 | 63088;
	// ori r6,r6,63092
	ctx.r6.u64 = ctx.r6.u64 | 63092;
	// lis r3,0
	ctx.r3.s64 = 0;
	// stw r30,4(r20)
	REX_STORE_U32(ctx.r20.u32 + 4, ctx.r30.u32);
	// lis r29,0
	ctx.r29.s64 = 0;
	// stw r30,8(r20)
	REX_STORE_U32(ctx.r20.u32 + 8, ctx.r30.u32);
	// stw r30,12(r20)
	REX_STORE_U32(ctx.r20.u32 + 12, ctx.r30.u32);
	// lis r28,0
	ctx.r28.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// lis r27,0
	ctx.r27.s64 = 0;
	// stfsx f31,r31,r7
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// stfsx f31,r31,r6
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// ori r10,r3,63100
	ctx.r10.u64 = ctx.r3.u64 | 63100;
	// ori r11,r29,63104
	ctx.r11.u64 = ctx.r29.u64 | 63104;
	// ori r9,r9,63084
	ctx.r9.u64 = ctx.r9.u64 | 63084;
	// ori r8,r8,63085
	ctx.r8.u64 = ctx.r8.u64 | 63085;
	// ori r7,r28,63108
	ctx.r7.u64 = ctx.r28.u64 | 63108;
	// ori r6,r27,63116
	ctx.r6.u64 = ctx.r27.u64 | 63116;
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lis r24,0
	ctx.r24.s64 = 0;
	// stfsx f31,r31,r11
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lis r23,0
	ctx.r23.s64 = 0;
	// stbx r30,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u8);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// lis r4,0
	ctx.r4.s64 = 0;
	// stfsx f31,r31,r7
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// lis r26,0
	ctx.r26.s64 = 0;
	// stfsx f31,r31,r6
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// lis r25,0
	ctx.r25.s64 = 0;
	// lis r22,0
	ctx.r22.s64 = 0;
	// lis r21,0
	ctx.r21.s64 = 0;
	// ori r10,r24,63136
	ctx.r10.u64 = ctx.r24.u64 | 63136;
	// ori r11,r23,63140
	ctx.r11.u64 = ctx.r23.u64 | 63140;
	// ori r5,r5,63096
	ctx.r5.u64 = ctx.r5.u64 | 63096;
	// ori r4,r4,63097
	ctx.r4.u64 = ctx.r4.u64 | 63097;
	// ori r9,r26,63124
	ctx.r9.u64 = ctx.r26.u64 | 63124;
	// ori r8,r25,63128
	ctx.r8.u64 = ctx.r25.u64 | 63128;
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// ori r7,r22,63144
	ctx.r7.u64 = ctx.r22.u64 | 63144;
	// stfsx f13,r31,r11
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// ori r6,r21,63148
	ctx.r6.u64 = ctx.r21.u64 | 63148;
	// stbx r30,r31,r5
	REX_STORE_U8(ctx.r31.u32 + ctx.r5.u32, ctx.r30.u8);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stbx r30,r31,r4
	REX_STORE_U8(ctx.r31.u32 + ctx.r4.u32, ctx.r30.u8);
	// stfsx f31,r31,r9
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// stfsx f0,r31,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stfsx f31,r31,r7
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stfsx f31,r31,r6
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r29,r10,63132
	ctx.r29.u64 = ctx.r10.u64 | 63132;
	// ori r28,r11,63152
	ctx.r28.u64 = ctx.r11.u64 | 63152;
	// ori r9,r9,63112
	ctx.r9.u64 = ctx.r9.u64 | 63112;
	// ori r8,r8,63120
	ctx.r8.u64 = ctx.r8.u64 | 63120;
	// ori r7,r7,63156
	ctx.r7.u64 = ctx.r7.u64 | 63156;
	// ori r6,r6,63160
	ctx.r6.u64 = ctx.r6.u64 | 63160;
	// ori r5,r5,63164
	ctx.r5.u64 = ctx.r5.u64 | 63164;
	// li r11,-1
	ctx.r11.s64 = -1;
	// ori r4,r4,63168
	ctx.r4.u64 = ctx.r4.u64 | 63168;
	// ori r3,r3,63172
	ctx.r3.u64 = ctx.r3.u64 | 63172;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// sthx r30,r31,r9
	REX_STORE_U16(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u16);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// lis r8,0
	ctx.r8.s64 = 0;
	// addi r27,r10,28944
	ctx.r27.s64 = ctx.r10.s64 + 28944;
	// stbx r30,r31,r29
	REX_STORE_U8(ctx.r31.u32 + ctx.r29.u32, ctx.r30.u8);
	// ori r10,r9,63176
	ctx.r10.u64 = ctx.r9.u64 | 63176;
	// stwx r11,r31,r28
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, ctx.r11.u32);
	// ori r9,r8,63180
	ctx.r9.u64 = ctx.r8.u64 | 63180;
	// stfsx f31,r31,r7
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// stfsx f31,r31,r5
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// stwx r30,r31,r4
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, ctx.r30.u32);
	// stbx r30,r31,r6
	REX_STORE_U8(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u8);
	// lis r29,0
	ctx.r29.s64 = 0;
	// stwx r30,r31,r3
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, ctx.r30.u32);
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// stwx r11,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stwx r30,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u32);
	// ori r8,r29,63184
	ctx.r8.u64 = ctx.r29.u64 | 63184;
	// lfs f0,5616(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 5616);
	ctx.f0.f64 = double(temp.f32);
	// ori r9,r4,63212
	ctx.r9.u64 = ctx.r4.u64 | 63212;
	// ori r7,r7,63192
	ctx.r7.u64 = ctx.r7.u64 | 63192;
	// ori r5,r5,63196
	ctx.r5.u64 = ctx.r5.u64 | 63196;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r28,0
	ctx.r28.s64 = 0;
	// stfsx f31,r31,r8
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// ori r10,r6,63200
	ctx.r10.u64 = ctx.r6.u64 | 63200;
	// stfsx f31,r31,r9
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// lis r3,0
	ctx.r3.s64 = 0;
	// stfsx f31,r31,r7
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// lis r26,0
	ctx.r26.s64 = 0;
	// stfsx f31,r31,r5
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// lis r25,0
	ctx.r25.s64 = 0;
	// lis r24,0
	ctx.r24.s64 = 0;
	// lis r23,0
	ctx.r23.s64 = 0;
	// stwx r30,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u32);
	// lis r22,0
	ctx.r22.s64 = 0;
	// ori r29,r28,63188
	ctx.r29.u64 = ctx.r28.u64 | 63188;
	// ori r8,r3,63216
	ctx.r8.u64 = ctx.r3.u64 | 63216;
	// ori r6,r26,63217
	ctx.r6.u64 = ctx.r26.u64 | 63217;
	// ori r7,r25,63220
	ctx.r7.u64 = ctx.r25.u64 | 63220;
	// ori r5,r24,63224
	ctx.r5.u64 = ctx.r24.u64 | 63224;
	// ori r4,r23,63228
	ctx.r4.u64 = ctx.r23.u64 | 63228;
	// stfsx f31,r31,r29
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
	// ori r9,r22,63236
	ctx.r9.u64 = ctx.r22.u64 | 63236;
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stbx r30,r31,r6
	REX_STORE_U8(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u8);
	// stwx r30,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u32);
	// lis r29,0
	ctx.r29.s64 = 0;
	// stfsx f0,r31,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stwx r10,r31,r4
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, ctx.r10.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stwx r30,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r28,0
	ctx.r28.s64 = 0;
	// lis r26,0
	ctx.r26.s64 = 0;
	// lis r25,0
	ctx.r25.s64 = 0;
	// lis r24,0
	ctx.r24.s64 = 0;
	// ori r23,r29,63272
	ctx.r23.u64 = ctx.r29.u64 | 63272;
	// ori r8,r8,63240
	ctx.r8.u64 = ctx.r8.u64 | 63240;
	// ori r7,r7,63248
	ctx.r7.u64 = ctx.r7.u64 | 63248;
	// ori r6,r6,63252
	ctx.r6.u64 = ctx.r6.u64 | 63252;
	// ori r5,r5,63256
	ctx.r5.u64 = ctx.r5.u64 | 63256;
	// ori r9,r9,63260
	ctx.r9.u64 = ctx.r9.u64 | 63260;
	// ori r4,r4,63264
	ctx.r4.u64 = ctx.r4.u64 | 63264;
	// ori r3,r3,63268
	ctx.r3.u64 = ctx.r3.u64 | 63268;
	// ori r28,r28,63276
	ctx.r28.u64 = ctx.r28.u64 | 63276;
	// ori r26,r26,63280
	ctx.r26.u64 = ctx.r26.u64 | 63280;
	// ori r25,r25,63281
	ctx.r25.u64 = ctx.r25.u64 | 63281;
	// mr r22,r11
	ctx.r22.u64 = ctx.r11.u64;
	// mr r21,r11
	ctx.r21.u64 = ctx.r11.u64;
	// ori r24,r24,63282
	ctx.r24.u64 = ctx.r24.u64 | 63282;
	// lis r29,-32109
	ctx.r29.s64 = -2104295424;
	// ld r11,6848(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 6848);
	// stfsx f31,r31,r9
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// stbx r30,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u8);
	// lis r20,0
	ctx.r20.s64 = 0;
	// stwx r21,r31,r6
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r21.u32);
	// lis r19,0
	ctx.r19.s64 = 0;
	// lis r18,0
	ctx.r18.s64 = 0;
	// stbx r30,r31,r4
	REX_STORE_U8(ctx.r31.u32 + ctx.r4.u32, ctx.r30.u8);
	// lis r17,0
	ctx.r17.s64 = 0;
	// stdx r11,r31,r8
	REX_STORE_U64(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u64);
	// lis r16,0
	ctx.r16.s64 = 0;
	// stwx r21,r31,r5
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r21.u32);
	// lis r15,0
	ctx.r15.s64 = 0;
	// stwx r10,r31,r3
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, ctx.r10.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stwx r30,r31,r28
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, ctx.r30.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stwx r30,r31,r23
	REX_STORE_U32(ctx.r31.u32 + ctx.r23.u32, ctx.r30.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stbx r30,r31,r26
	REX_STORE_U8(ctx.r31.u32 + ctx.r26.u32, ctx.r30.u8);
	// ori r5,r20,63283
	ctx.r5.u64 = ctx.r20.u64 | 63283;
	// stbx r30,r31,r25
	REX_STORE_U8(ctx.r31.u32 + ctx.r25.u32, ctx.r30.u8);
	// ori r4,r19,63284
	ctx.r4.u64 = ctx.r19.u64 | 63284;
	// stbx r30,r31,r24
	REX_STORE_U8(ctx.r31.u32 + ctx.r24.u32, ctx.r30.u8);
	// ori r11,r18,63285
	ctx.r11.u64 = ctx.r18.u64 | 63285;
	// ori r10,r17,63286
	ctx.r10.u64 = ctx.r17.u64 | 63286;
	// ori r8,r16,63287
	ctx.r8.u64 = ctx.r16.u64 | 63287;
	// ori r3,r15,63288
	ctx.r3.u64 = ctx.r15.u64 | 63288;
	// stbx r30,r31,r5
	REX_STORE_U8(ctx.r31.u32 + ctx.r5.u32, ctx.r30.u8);
	// ori r9,r9,63292
	ctx.r9.u64 = ctx.r9.u64 | 63292;
	// stbx r30,r31,r4
	REX_STORE_U8(ctx.r31.u32 + ctx.r4.u32, ctx.r30.u8);
	// ori r7,r7,63293
	ctx.r7.u64 = ctx.r7.u64 | 63293;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// ori r6,r6,63294
	ctx.r6.u64 = ctx.r6.u64 | 63294;
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// lis r4,-32113
	ctx.r4.s64 = -2104557568;
	// stwx r30,r31,r3
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, ctx.r30.u32);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// stbx r30,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u8);
	// addi r11,r4,22392
	ctx.r11.s64 = ctx.r4.s64 + 22392;
	// stbx r30,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// stbx r30,r31,r6
	REX_STORE_U8(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u8);
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r28,r28,-2240
	ctx.r28.s64 = ctx.r28.s64 + -2240;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x82281A04;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82281a10
	if (ctx.cr0.eq) goto loc_82281A10;
	// stw r3,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r3.u32);
loc_82281A10:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82281a1c
	if (ctx.cr0.eq) goto loc_82281A1C;
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_82281A1C:
	// stw r3,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r3.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// stw r30,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r30.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,63316
	ctx.r11.u64 = ctx.r11.u64 | 63316;
	// ori r9,r9,63308
	ctx.r9.u64 = ctx.r9.u64 | 63308;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r10,r10,63320
	ctx.r10.u64 = ctx.r10.u64 | 63320;
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// addis r6,r31,1
	ctx.r6.s64 = ctx.r31.s64 + 65536;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// ori r8,r8,63312
	ctx.r8.u64 = ctx.r8.u64 | 63312;
	// stwx r30,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u32);
	// addi r7,r7,-2212
	ctx.r7.s64 = ctx.r7.s64 + -2212;
	// addi r6,r6,-2192
	ctx.r6.s64 = ctx.r6.s64 + -2192;
	// stfsx f31,r31,r10
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stwx r30,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u32);
	// stw r30,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r30.u32);
	// addi r9,r9,-2164
	ctx.r9.s64 = ctx.r9.s64 + -2164;
	// stw r30,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r30.u32);
	// ori r8,r10,63400
	ctx.r8.u64 = ctx.r10.u64 | 63400;
	// stw r30,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, ctx.r30.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stw r30,12(r7)
	REX_STORE_U32(ctx.r7.u32 + 12, ctx.r30.u32);
	// stb r30,16(r7)
	REX_STORE_U8(ctx.r7.u32 + 16, ctx.r30.u8);
	// addi r3,r3,-2132
	ctx.r3.s64 = ctx.r3.s64 + -2132;
	// stb r30,17(r7)
	REX_STORE_U8(ctx.r7.u32 + 17, ctx.r30.u8);
	// stb r30,18(r7)
	REX_STORE_U8(ctx.r7.u32 + 18, ctx.r30.u8);
	// stb r30,19(r7)
	REX_STORE_U8(ctx.r7.u32 + 19, ctx.r30.u8);
	// stfs f31,4(r6)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stb r30,0(r6)
	REX_STORE_U8(ctx.r6.u32 + 0, ctx.r30.u8);
	// stb r30,1(r6)
	REX_STORE_U8(ctx.r6.u32 + 1, ctx.r30.u8);
	// stb r30,8(r6)
	REX_STORE_U8(ctx.r6.u32 + 8, ctx.r30.u8);
	// ld r10,6272(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 6272);
	// std r10,12(r6)
	REX_STORE_U64(ctx.r6.u32 + 12, ctx.r10.u64);
	// ld r10,6848(r29)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r29.u32 + 6848);
	// std r10,20(r6)
	REX_STORE_U64(ctx.r6.u32 + 20, ctx.r10.u64);
	// stfs f31,4(r9)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stb r30,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r30.u8);
	// stb r30,1(r9)
	REX_STORE_U8(ctx.r9.u32 + 1, ctx.r30.u8);
	// stb r30,8(r9)
	REX_STORE_U8(ctx.r9.u32 + 8, ctx.r30.u8);
	// ld r11,6272(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 6272);
	// std r11,12(r9)
	REX_STORE_U64(ctx.r9.u32 + 12, ctx.r11.u64);
	// ld r11,6848(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 6848);
	// std r11,20(r9)
	REX_STORE_U64(ctx.r9.u32 + 20, ctx.r11.u64);
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// bl 0x822232d8
	ctx.lr = 0x82281AEC;
	sub_822232D8(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,63436
	ctx.r11.u64 = ctx.r11.u64 | 63436;
	// stb r10,236(r31)
	REX_STORE_U8(ctx.r31.u32 + 236, ctx.r10.u8);
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,13
	ctx.r4.s64 = 13;
	// addi r3,r10,-13632
	ctx.r3.s64 = ctx.r10.s64 + -13632;
	// stfsx f31,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// bl 0x82441618
	ctx.lr = 0x82281B14;
	sub_82441618(ctx, base);
	// bl 0x824bae28
	ctx.lr = 0x82281B18;
	sub_824BAE28(ctx, base);
	// bl 0x824c0e10
	ctx.lr = 0x82281B1C;
	sub_824C0E10(ctx, base);
	// bl 0x824c0e10
	ctx.lr = 0x82281B20;
	sub_824C0E10(ctx, base);
	// lis r30,-32110
	ctx.r30.s64 = -2104360960;
	// lwz r11,-9788(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82281b78
	if (ctx.cr6.eq) goto loc_82281B78;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r29,r11,7088
	ctx.r29.s64 = ctx.r11.s64 + 7088;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82486f58
	ctx.lr = 0x82281B44;
	sub_82486F58(ctx, base);
	// lwz r11,-9788(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82281b78
	if (ctx.cr6.eq) goto loc_82281B78;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82486f58
	ctx.lr = 0x82281B5C;
	sub_82486F58(ctx, base);
	// lwz r11,-9788(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82281b78
	if (ctx.cr6.eq) goto loc_82281B78;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,2940
	ctx.r3.s64 = ctx.r11.s64 + 2940;
	// bl 0x82486f58
	ctx.lr = 0x82281B78;
	sub_82486F58(ctx, base);
loc_82281B78:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x82281B88;
	sub_82371AF8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,-23504
	ctx.r4.s64 = ctx.r11.s64 + -23504;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82484c30
	ctx.lr = 0x82281B9C;
	sub_82484C30(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82281bb0
	if (!ctx.cr6.lt) goto loc_82281BB0;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_82281BB0:
	// lwz r11,-9788(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82281bfc
	if (ctx.cr6.eq) goto loc_82281BFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82486f58
	ctx.lr = 0x82281BC4;
	sub_82486F58(ctx, base);
	// lwz r11,-9788(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82281bfc
	if (ctx.cr6.eq) goto loc_82281BFC;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,-5456
	ctx.r3.s64 = ctx.r11.s64 + -5456;
	// bl 0x82486f58
	ctx.lr = 0x82281BE0;
	sub_82486F58(ctx, base);
	// lwz r11,-9788(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82281bfc
	if (ctx.cr6.eq) goto loc_82281BFC;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,-5488
	ctx.r3.s64 = ctx.r11.s64 + -5488;
	// bl 0x82486f58
	ctx.lr = 0x82281BFC;
	sub_82486F58(ctx, base);
loc_82281BFC:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x82281C0C;
	sub_82371AF8(ctx, base);
	// bl 0x8254b288
	ctx.lr = 0x82281C10;
	sub_8254B288(ctx, base);
	// bl 0x824bbca0
	ctx.lr = 0x82281C14;
	sub_824BBCA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -152);
	// b 0x827566d4
	__restgprlr_15(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822B5690) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x822B5698;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,4(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x822b56c4
	goto loc_822B56C4;
loc_822B56AC:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822b56bc
	if (ctx.cr6.eq) goto loc_822B56BC;
	// bl 0x825fc588
	ctx.lr = 0x822B56BC;
	sub_825FC588(ctx, base);
loc_822B56BC:
	// stw r29,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
loc_822B56C4:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x822b56ac
	if (!ctx.cr6.eq) goto loc_822B56AC;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x822b5700
	if (ctx.cr6.eq) goto loc_822B5700;
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
	// ble 0x822b56fc
	if (!ctx.cr0.gt) goto loc_822B56FC;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82755080
	ctx.lr = 0x822B56FC;
	sub_82755080(ctx, base);
loc_822B56FC:
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
loc_822B5700:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822b5710
	if (ctx.cr6.eq) goto loc_822B5710;
	// bl 0x825fc588
	ctx.lr = 0x822B5710;
	sub_825FC588(ctx, base);
loc_822B5710:
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// bl 0x825fc588
	ctx.lr = 0x822B5724;
	sub_825FC588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822B7FB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x822B7FB8;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,24
	ctx.r4.s64 = 24;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x822B7FE0;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// beq 0x822b8050
	if (ctx.cr0.eq) goto loc_822B8050;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r8,r11,-30000
	ctx.r8.s64 = ctx.r11.s64 + -30000;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stfs f0,8(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,4(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f12,12(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r9,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// b 0x822b8054
	goto loc_822B8054;
loc_822B8050:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_822B8054:
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822b80c0
	if (ctx.cr6.eq) goto loc_822B80C0;
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// addis r3,r30,1
	ctx.r3.s64 = ctx.r30.s64 + 65536;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r3,r3,-2324
	ctx.r3.s64 = ctx.r3.s64 + -2324;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822b8094
	if (ctx.cr6.eq) goto loc_822B8094;
	// lwz r9,12(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r9,r10,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r10.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
loc_822B8094:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r10,r10,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r10.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x822b80b8
	if (!ctx.cr6.lt) goto loc_822B80B8;
	// addi r10,r4,4
	ctx.r10.s64 = ctx.r4.s64 + 4;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// b 0x822b80c0
	goto loc_822B80C0;
loc_822B80B8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823916c0
	ctx.lr = 0x822B80C0;
	sub_823916C0(ctx, base);
loc_822B80C0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822C4AC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x822C4AC8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x822c4bd0
	if (ctx.cr6.eq) goto loc_822C4BD0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x8245cd58
	ctx.lr = 0x822C4AE4;
	sub_8245CD58(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x822c4bd0
	if (ctx.cr0.eq) goto loc_822C4BD0;
	// bl 0x8243f6d0
	ctx.lr = 0x822C4AF0;
	sub_8243F6D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822c4b60
	if (!ctx.cr0.eq) goto loc_822C4B60;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82448730
	ctx.lr = 0x822C4B04;
	sub_82448730(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-9960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9960);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822c4b40
	if (ctx.cr6.eq) goto loc_822C4B40;
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
	// bl 0x823c3150
	ctx.lr = 0x822C4B40;
	sub_823C3150(ctx, base);
loc_822C4B40:
	// lis r11,0
	ctx.r11.s64 = 0;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// ori r11,r11,64188
	ctx.r11.u64 = ctx.r11.u64 | 64188;
	// lbzx r11,r29,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x822c4bd0
	if (!ctx.cr6.eq) goto loc_822C4BD0;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x822c4bd4
	goto loc_822C4BD4;
loc_822C4B60:
	// bl 0x82440f20
	ctx.lr = 0x822C4B64;
	sub_82440F20(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82440e68
	ctx.lr = 0x822C4B6C;
	sub_82440E68(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82440b70
	ctx.lr = 0x822C4B78;
	sub_82440B70(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-9960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9960);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822c4bb4
	if (ctx.cr6.eq) goto loc_822C4BB4;
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
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823c3150
	ctx.lr = 0x822C4BB4;
	sub_823C3150(ctx, base);
loc_822C4BB4:
	// lis r11,0
	ctx.r11.s64 = 0;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// ori r11,r11,64188
	ctx.r11.u64 = ctx.r11.u64 | 64188;
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r11,r29,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x822c4bd4
	if (ctx.cr6.eq) goto loc_822C4BD4;
loc_822C4BD0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C4BD4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822C9BE0) {
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
	// bl 0x82240cb0
	ctx.lr = 0x822C9BF8;
	sub_82240CB0(ctx, base);
	// lbz r11,544(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 544);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822c9c44
	if (ctx.cr0.eq) goto loc_822C9C44;
	// addis r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r31,r31,-3156
	ctx.r31.s64 = ctx.r31.s64 + -3156;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822C9C28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
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
	ctx.lr = 0x822C9C44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822C9C44:
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

DEFINE_REX_FUNC(sub_822CE5B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x822CE5B8;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x827576c0
	ctx.lr = 0x822CE5C0;
	__savefpr_26(ctx, base);
	// li r12,-144
	ctx.r12.s64 = -144;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r5,4(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r30,r11,-29968
	ctx.r30.s64 = ctx.r11.s64 + -29968;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f29,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f29.f64 = double(temp.f32);
	// lfs f31,-24124(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -24124);
	ctx.f31.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// bl 0x825c0958
	ctx.lr = 0x822CE5F8;
	sub_825C0958(ctx, base);
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x825c0958
	ctx.lr = 0x822CE60C;
	sub_825C0958(ctx, base);
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f26,f1
	ctx.fpscr.disableFlushMode();
	ctx.f26.f64 = ctx.f1.f64;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x82454930
	ctx.lr = 0x822CE624;
	sub_82454930(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r29,r11,-30256
	ctx.r29.s64 = ctx.r11.s64 + -30256;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v127,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// bl 0x822400e0
	ctx.lr = 0x822CE660;
	sub_822400E0(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v0,v127,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
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
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822400e0
	ctx.lr = 0x822CE6B8;
	sub_822400E0(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v0,v127,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lwz r11,-9960(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -9960);
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822ce724
	if (ctx.cr6.eq) goto loc_822CE724;
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
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
	// bl 0x823c3150
	ctx.lr = 0x822CE724;
	sub_823C3150(ctx, base);
loc_822CE724:
	// lbz r11,228(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 228);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f29,-23280(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -23280);
	ctx.f29.f64 = double(temp.f32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// beq cr6,0x822ce8f4
	if (ctx.cr6.eq) goto loc_822CE8F4;
	// bl 0x822400e0
	ctx.lr = 0x822CE760;
	sub_822400E0(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f27,-14120(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -14120);
	ctx.f27.f64 = double(temp.f32);
	// beq 0x822ce7ac
	if (ctx.cr0.eq) goto loc_822CE7AC;
	// fadds f0,f28,f31
	ctx.f0.f64 = double(float(ctx.f28.f64 + ctx.f31.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fmuls f28,f0,f27
	ctx.f28.f64 = double(float(ctx.f0.f64 * ctx.f27.f64));
	// b 0x822ce81c
	goto loc_822CE81C;
loc_822CE7AC:
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x822400e0
	ctx.lr = 0x822CE7D4;
	sub_822400E0(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgefp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822ce818
	if (ctx.cr0.eq) goto loc_822CE818;
	// fadds f0,f28,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f28.f64 + ctx.f31.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fmuls f28,f0,f29
	ctx.f28.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// b 0x822ce81c
	goto loc_822CE81C;
loc_822CE818:
	// lfs f28,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f28.f64 = double(temp.f32);
loc_822CE81C:
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x822400e0
	ctx.lr = 0x822CE844;
	sub_822400E0(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822ce888
	if (ctx.cr0.eq) goto loc_822CE888;
	// fadds f0,f26,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f26.f64 + ctx.f31.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fmuls f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f27.f64));
	// b 0x822cea60
	goto loc_822CEA60;
loc_822CE888:
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x822400e0
	ctx.lr = 0x822CE8B0;
	sub_822400E0(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgefp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822cea5c
	if (ctx.cr0.eq) goto loc_822CEA5C;
	// fadds f0,f26,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f26.f64 + ctx.f31.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// b 0x822cea60
	goto loc_822CEA60;
loc_822CE8F4:
	// bl 0x822400e0
	ctx.lr = 0x822CE8F8;
	sub_822400E0(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822ce934
	if (ctx.cr0.eq) goto loc_822CE934;
	// fneg f28,f28
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f28.u64 = ctx.f28.u64 ^ 0x8000000000000000;
	// b 0x822ce994
	goto loc_822CE994;
loc_822CE934:
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x822400e0
	ctx.lr = 0x822CE95C;
	sub_822400E0(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgefp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822ce994
	if (!ctx.cr0.eq) goto loc_822CE994;
	// lfs f28,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f28.f64 = double(temp.f32);
loc_822CE994:
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x822400e0
	ctx.lr = 0x822CE9BC;
	sub_822400E0(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822ce9f8
	if (ctx.cr0.eq) goto loc_822CE9F8;
	// fneg f0,f26
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = ctx.f26.u64 ^ 0x8000000000000000;
	// b 0x822cea60
	goto loc_822CEA60;
loc_822CE9F8:
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x822400e0
	ctx.lr = 0x822CEA20;
	sub_822400E0(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgefp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822cea5c
	if (ctx.cr0.eq) goto loc_822CEA5C;
	// fmr f0,f26
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = ctx.f26.f64;
	// b 0x822cea60
	goto loc_822CEA60;
loc_822CEA5C:
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
loc_822CEA60:
	// fmuls f13,f28,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f28.f64 * ctx.f30.f64));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// addi r28,r28,-3068
	ctx.r28.s64 = ctx.r28.s64 + -3068;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r8,r8,-3064
	ctx.r8.s64 = ctx.r8.s64 + -3064;
	// lfs f12,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// fmuls f13,f13,f29
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f29.f64));
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fmuls f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f12,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f12,152(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// stfs f0,0(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// bl 0x82454930
	ctx.lr = 0x822CEB1C;
	sub_82454930(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r29,-3020
	ctx.r29.s64 = ctx.r29.s64 + -3020;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x82755380
	ctx.lr = 0x822CEB44;
	sub_82755380(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r30,r11,-2036
	ctx.r30.s64 = ctx.r11.s64 + -2036;
	// ori r11,r10,62544
	ctx.r11.u64 = ctx.r10.u64 | 62544;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lfs f0,28604(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 28604);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f13,632(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 632);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fmadds f31,f0,f29,f13
	ctx.f31.f64 = double(float(std::fma(ctx.f0.f64, ctx.f29.f64, ctx.f13.f64)));
	// bl 0x822400e0
	ctx.lr = 0x822CEB84;
	sub_822400E0(ctx, base);
	// lfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f13,84(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
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
	// lfs f0,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r25,r1,176
	ctx.r25.s64 = ctx.r1.s64 + 176;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r24,r1,176
	ctx.r24.s64 = ctx.r1.s64 + 176;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lfs f13,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r27,r1,160
	ctx.r27.s64 = ctx.r1.s64 + 160;
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r26,r1,112
	ctx.r26.s64 = ctx.r1.s64 + 112;
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
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
	// lvx128 v59,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,168(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f31,164(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f31,160(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f0,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stvx128 v61,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v62,v60
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lvx128 v59,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v59,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f10,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f10.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// stvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f9.f64 = double(temp.f32);
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// ld r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r9,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r9.u64);
	// lvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r8,-2512
	ctx.r10.s64 = ctx.r8.s64 + -2512;
	// lfs f0,2184(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x822cef60
	if (!ctx.cr6.gt) goto loc_822CEF60;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82454930
	ctx.lr = 0x822CED38;
	sub_82454930(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f10,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f30,172(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// stfs f10,136(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stfs f10,132(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f31,184(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stfs f31,180(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f31,176(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r27,r1,160
	ctx.r27.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r9,r9,-30528
	ctx.r9.s64 = ctx.r9.s64 + -30528;
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f30,160(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f30,168(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// stfs f30,164(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r28,r28,-30304
	ctx.r28.s64 = ctx.r28.s64 + -30304;
	// stfs f9,124(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
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
	// lvx128 v58,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v58,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v58.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,188(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lvx128 v59,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v58,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
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
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
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
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v60,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,164(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// vmulfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r28,r1,176
	ctx.r28.s64 = ctx.r1.s64 + 176;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f0,168(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f0,188(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_822CEF60:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f30,f29,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f30.f64, ctx.f29.f64, ctx.f0.f64)));
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// addi r11,r11,-3008
	ctx.r11.s64 = ctx.r11.s64 + -3008;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x822cef94
	if (!ctx.cr6.lt) goto loc_822CEF94;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lfs f13,13784(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13784);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f30,f13,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f30.f64, ctx.f13.f64, ctx.f0.f64)));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_822CEF94:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// li r0,-144
	ctx.r0.s64 = -144;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8275770c
	ctx.lr = 0x822CEFA8;
	__restfpr_26(ctx, base);
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8233CB68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8233CB70;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// bl 0x82242798
	ctx.lr = 0x8233CB88;
	sub_82242798(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8233cc90
	if (!ctx.cr0.eq) goto loc_8233CC90;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r29,r29,-3152
	ctx.r29.s64 = ctx.r29.s64 + -3152;
	// ori r30,r11,62372
	ctx.r30.u64 = ctx.r11.u64 | 62372;
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8233cc54
	if (ctx.cr0.eq) goto loc_8233CC54;
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
	// lfs f1,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x8233CBD0;
	sub_8225CEC0(ctx, base);
	// stfsx f1,r31,r30
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x822400e0
	ctx.lr = 0x8233CBE4;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x8233CC00;
	sub_822400E0(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-9960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9960);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8233cc3c
	if (ctx.cr6.eq) goto loc_8233CC3C;
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
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823c3150
	ctx.lr = 0x8233CC38;
	sub_823C3150(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_8233CC3C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lbz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// ori r11,r11,62376
	ctx.r11.u64 = ctx.r11.u64 | 62376;
	// rlwinm r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r9,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r9.u8);
	// stbx r10,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u8);
loc_8233CC54:
	// lfsx f0,r31,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// stfsx f13,r31,r30
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, temp.u32);
	// lfs f0,-28872(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28872);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8233cc90
	if (!ctx.cr6.gt) goto loc_8233CC90;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lbz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// lis r9,-32204
	ctx.r9.s64 = -2110521344;
	// ori r11,r11,62380
	ctx.r11.u64 = ctx.r11.u64 | 62380;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// addi r9,r9,-13152
	ctx.r9.s64 = ctx.r9.s64 + -13152;
	// stb r10,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r10.u8);
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
loc_8233CC90:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823473D0) {
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
	// bl 0x82440f20
	ctx.lr = 0x823473E8;
	sub_82440F20(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lhz r9,552(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 552);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// ori r10,r10,10284
	ctx.r10.u64 = ctx.r10.u64 | 10284;
	// lfs f0,20084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20084);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r8,10288
	ctx.r11.u64 = ctx.r8.u64 | 10288;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// addi r4,r4,10280
	ctx.r4.s64 = ctx.r4.s64 + 10280;
	// li r8,5
	ctx.r8.s64 = 5;
	// li r6,-1
	ctx.r6.s64 = -1;
	// stbx r8,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u8);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r3,15
	ctx.r3.s64 = 15;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// bl 0x82441518
	ctx.lr = 0x8234743C;
	sub_82441518(ctx, base);
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

DEFINE_REX_FUNC(sub_823489B0) {
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
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f31,12484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f31.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8225cec0
	ctx.lr = 0x823489F0;
	sub_8225CEC0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8234a9f8
	ctx.lr = 0x82348A04;
	sub_8234A9F8(ctx, base);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8234ab38
	ctx.lr = 0x82348A10;
	sub_8234AB38(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82348a28
	if (ctx.cr0.eq) goto loc_82348A28;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8234b430
	ctx.lr = 0x82348A20;
	sub_8234B430(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82348a3c
	if (!ctx.cr0.eq) goto loc_82348A3C;
loc_82348A28:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62408
	ctx.r11.u64 = ctx.r11.u64 | 62408;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82348af4
	if (ctx.cr0.eq) goto loc_82348AF4;
loc_82348A3C:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8234a9f8
	ctx.lr = 0x82348A50;
	sub_8234A9F8(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x82348a88
	if (ctx.cr6.gt) goto loc_82348A88;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82348A88:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// beq 0x82348aac
	if (ctx.cr0.eq) goto loc_82348AAC;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82348ad0
	if (ctx.cr0.eq) goto loc_82348AD0;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x82348ab8
	goto loc_82348AB8;
loc_82348AAC:
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82348ad0
	if (ctx.cr0.eq) goto loc_82348AD0;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82348AB8:
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
	ctx.lr = 0x82348AD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82348AD0:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62376
	ctx.r11.u64 = ctx.r11.u64 | 62376;
	// lis r9,-32203
	ctx.r9.s64 = -2110455808;
	// ori r10,r10,62380
	ctx.r10.u64 = ctx.r10.u64 | 62380;
	// addi r9,r9,-29936
	ctx.r9.s64 = ctx.r9.s64 + -29936;
	// li r8,0
	ctx.r8.s64 = 0;
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
	// stwx r8,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u32);
loc_82348AF4:
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

DEFINE_REX_FUNC(sub_8234F7C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x8234F7C8;
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
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r27,r9,62520
	ctx.r27.u64 = ctx.r9.u64 | 62520;
	// ori r28,r8,62524
	ctx.r28.u64 = ctx.r8.u64 | 62524;
	// addi r26,r11,-30976
	ctx.r26.s64 = ctx.r11.s64 + -30976;
	// addi r25,r10,-5780
	ctx.r25.s64 = ctx.r10.s64 + -5780;
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq 0x8234f8f4
	if (ctx.cr0.eq) goto loc_8234F8F4;
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
	// bl 0x8225cec0
	ctx.lr = 0x8234F87C;
	sub_8225CEC0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62412
	ctx.r11.u64 = ctx.r11.u64 | 62412;
	// lfs f0,-3164(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -3164);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// bl 0x82351238
	ctx.lr = 0x8234F89C;
	sub_82351238(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8234ee40
	ctx.lr = 0x8234F8A8;
	sub_8234EE40(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f1,31044(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 31044);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r24,r11,-2512
	ctx.r24.s64 = ctx.r11.s64 + -2512;
	// lfs f2,1000(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 1000);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825c0958
	ctx.lr = 0x8234F8C0;
	sub_825C0958(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// lfs f2,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,980(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 980);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825c0958
	ctx.lr = 0x8234F8D4;
	sub_825C0958(ctx, base);
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
	// stfsx f1,r31,r28
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, temp.u32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfsx f0,r31,r27
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
	// stb r30,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r30.u8);
loc_8234F8F4:
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
	// bl 0x82351238
	ctx.lr = 0x8234F918;
	sub_82351238(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8234ee40
	ctx.lr = 0x8234F924;
	sub_8234EE40(ctx, base);
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,2104(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 2104);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfsx f0,r31,r28
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
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
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f13,r31,r27
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// bl 0x8234ecb0
	ctx.lr = 0x8234F9D0;
	sub_8234ECB0(ctx, base);
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
	// ble cr6,0x8234fa4c
	if (!ctx.cr6.gt) goto loc_8234FA4C;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// addi r5,r11,4344
	ctx.r5.s64 = ctx.r11.s64 + 4344;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824d3cb8
	ctx.lr = 0x8234F9FC;
	sub_824D3CB8(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823201d0
	ctx.lr = 0x8234FA0C;
	sub_823201D0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8228e530
	ctx.lr = 0x8234FA20;
	sub_8228E530(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,4376(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 4376);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8234fa3c
	if (!ctx.cr6.lt) goto loc_8234FA3C;
	// li r30,1
	ctx.r30.s64 = 1;
loc_8234FA3C:
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8234fa4c
	if (ctx.cr0.eq) goto loc_8234FA4C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82351028
	ctx.lr = 0x8234FA4C;
	sub_82351028(ctx, base);
loc_8234FA4C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823510f8
	ctx.lr = 0x8234FA54;
	sub_823510F8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82363918) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82233740
	ctx.lr = 0x82363938;
	sub_82233740(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lfs f31,12484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// beq cr6,0x82363a20
	if (ctx.cr6.eq) goto loc_82363A20;
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82363984
	if (ctx.cr6.lt) goto loc_82363984;
	// bne cr6,0x82363a1c
	if (!ctx.cr6.eq) goto loc_82363A1C;
	// lfs f13,148(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f13,140(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,148(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 148, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82363a1c
	if (!ctx.cr6.lt) goto loc_82363A1C;
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// b 0x82363a20
	goto loc_82363A20;
loc_82363984:
	// lbz r11,165(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 165);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823639c8
	if (ctx.cr0.eq) goto loc_823639C8;
	// lfs f13,160(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,160(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 160, temp.u32);
	// b 0x823639bc
	goto loc_823639BC;
loc_823639A0:
	// lfs f0,160(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,156(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,160(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 160, temp.u32);
	// bl 0x82363098
	ctx.lr = 0x823639B8;
	sub_82363098(ctx, base);
	// lfs f0,160(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
loc_823639BC:
	// lfs f13,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x823639a0
	if (ctx.cr6.gt) goto loc_823639A0;
loc_823639C8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823637d8
	ctx.lr = 0x823639D0;
	sub_823637D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82363670
	ctx.lr = 0x823639D8;
	sub_82363670(ctx, base);
	// lbz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 144);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82363a20
	if (ctx.cr0.eq) goto loc_82363A20;
	// lfs f0,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f13,152(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,148(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 148, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82363a20
	if (!ctx.cr6.gt) goto loc_82363A20;
	// lbz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 136);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82363a1c
	if (ctx.cr0.eq) goto loc_82363A1C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f31,148(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 148, temp.u32);
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// b 0x82363a20
	goto loc_82363A20;
loc_82363A1C:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82363A20:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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

DEFINE_REX_FUNC(sub_8236BD68) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// addi r10,r11,17508
	ctx.r10.s64 = ctx.r11.s64 + 17508;
	// addi r30,r30,-1440
	ctx.r30.s64 = ctx.r30.s64 + -1440;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lfs f30,17508(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17508);
	ctx.f30.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f0,-18912(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -18912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f29,12484(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12484);
	ctx.f29.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x8236bdc8
	if (!ctx.cr6.lt) goto loc_8236BDC8;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x8236bdd4
	goto loc_8236BDD4;
loc_8236BDC8:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x8236bdd4
	if (!ctx.cr6.gt) goto loc_8236BDD4;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
loc_8236BDD4:
	// stfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x825c0958
	ctx.lr = 0x8236BDE8;
	sub_825C0958(ctx, base);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x8236bdfc
	if (!ctx.cr6.gt) goto loc_8236BDFC;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8236bef4
	goto loc_8236BEF4;
loc_8236BDFC:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-32408
	ctx.r9.s64 = ctx.r11.s64 + -32408;
	// ori r10,r10,64104
	ctx.r10.u64 = ctx.r10.u64 | 64104;
	// ld r11,-32408(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + -32408);
	// lwzx r7,r31,r10
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// cmpwi cr6,r7,-1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, -1, ctx.xer);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// beq cr6,0x8236be98
	if (ctx.cr6.eq) goto loc_8236BE98;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,64108
	ctx.r11.u64 = ctx.r11.u64 | 64108;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8236be98
	if (!ctx.cr6.gt) goto loc_8236BE98;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r8,2
	ctx.r8.s64 = 2;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfsx f13,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f12.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// stfsx f0,r11,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, temp.u32);
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
loc_8236BE78:
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// beq cr6,0x8236be8c
	if (ctx.cr6.eq) goto loc_8236BE8C;
	// lfs f13,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f13,0(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
loc_8236BE8C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdnz 0x8236be78
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8236BE78;
loc_8236BE98:
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r31,-1
	ctx.r31.s64 = -1;
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x825c0958
	ctx.lr = 0x8236BEB0;
	sub_825C0958(ctx, base);
	// addi r10,r1,76
	ctx.r10.s64 = ctx.r1.s64 + 76;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8236BEB8:
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// blt cr6,0x8236bed0
	if (ctx.cr6.lt) goto loc_8236BED0;
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x8236bee8
	if (ctx.cr6.lt) goto loc_8236BEE8;
loc_8236BED0:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lfsu f0,4(r10)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// fadds f31,f0,f31
	ctx.f31.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x8236beb8
	if (ctx.cr6.lt) goto loc_8236BEB8;
	// b 0x8236beec
	goto loc_8236BEEC;
loc_8236BEE8:
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_8236BEEC:
	// stfs f29,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8236BEF4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
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

DEFINE_REX_FUNC(sub_82374440) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x82374448;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// li r29,6
	ctx.r29.s64 = 6;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82374694
	if (ctx.cr6.lt) goto loc_82374694;
	// beq cr6,0x823744f0
	if (ctx.cr6.eq) goto loc_823744F0;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x823744c0
	if (ctx.cr6.eq) goto loc_823744C0;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x823746ec
	if (!ctx.cr6.eq) goto loc_823746EC;
	// lfs f0,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fadds f12,f0,f1
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stfs f12,56(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// addi r10,r10,12484
	ctx.r10.s64 = ctx.r10.s64 + 12484;
	// lfs f0,-28872(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x823744b4
	if (ctx.cr6.lt) goto loc_823744B4;
	// li r11,0
	ctx.r11.s64 = 0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// stw r29,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r29.u32);
	// stb r11,129(r3)
	REX_STORE_U8(ctx.r3.u32 + 129, ctx.r11.u8);
loc_823744B4:
	// fsubs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f0,132(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// b 0x823746ec
	goto loc_823746EC;
loc_823744C0:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823746ec
	if (!ctx.cr0.eq) goto loc_823746EC;
	// lfs f0,56(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f9
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f9.f64));
	// lfs f13,60(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x823746ec
	if (ctx.cr6.lt) goto loc_823746EC;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// b 0x823746e0
	goto loc_823746E0;
loc_823744F0:
	// lfs f0,56(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// fadds f13,f0,f9
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f9.f64));
	// stfs f13,56(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// lfs f11,80(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r30,r11,12484
	ctx.r30.s64 = ctx.r11.s64 + 12484;
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f12,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,1908(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,29520(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29520);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwa r11,84(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 84));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x822d2870
	ctx.lr = 0x82374584;
	sub_822D2870(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f12,96(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-8904(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8904);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f6,f9,f0,f13
	ctx.f6.f64 = double(float(std::fma(ctx.f9.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwz r11,-9960(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -9960);
	// fmadds f5,f1,f0,f11
	ctx.f5.f64 = double(float(std::fma(ctx.f1.f64, ctx.f0.f64, ctx.f11.f64)));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// fadds f0,f12,f6
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f6.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x82374638
	if (ctx.cr6.eq) goto loc_82374638;
	// fctiwz f0,f5
	ctx.f0.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823c2d80
	ctx.lr = 0x823745D8;
	sub_823C2D80(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82374638
	if (ctx.cr0.eq) goto loc_82374638;
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stb r11,129(r31)
	REX_STORE_U8(ctx.r31.u32 + 129, ctx.r11.u8);
	// li r11,4
	ctx.r11.s64 = 4;
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f12,88(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lfs f5,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f5.f64 = double(temp.f32);
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// fadds f6,f13,f6
	ctx.f6.f64 = double(float(ctx.f13.f64 + ctx.f6.f64));
loc_82374638:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f5,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f5,80(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f5,92(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f5,88(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f6,96(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f6,100(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f6,108(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f6,104(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
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
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,88(r31)
	REX_STORE_U64(ctx.r31.u32 + 88, ctx.r11.u64);
	// b 0x823746ec
	goto loc_823746EC;
loc_82374694:
	// lwz r3,152(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823746b4
	if (ctx.cr6.eq) goto loc_823746B4;
	// bl 0x823d2520
	ctx.lr = 0x823746A8;
	sub_823D2520(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// bne 0x823746b8
	if (!ctx.cr0.eq) goto loc_823746B8;
loc_823746B4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823746B8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823746ec
	if (!ctx.cr0.eq) goto loc_823746EC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82374e30
	ctx.lr = 0x823746C8;
	sub_82374E30(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823746d8
	if (!ctx.cr0.eq) goto loc_823746D8;
	// stb r30,129(r31)
	REX_STORE_U8(ctx.r31.u32 + 129, ctx.r30.u8);
loc_823746D8:
	// stb r30,128(r31)
	REX_STORE_U8(ctx.r31.u32 + 128, ctx.r30.u8);
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
loc_823746E0:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
loc_823746EC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82374ed0
	ctx.lr = 0x823746F4;
	sub_82374ED0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82374700
	if (ctx.cr0.eq) goto loc_82374700;
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
loc_82374700:
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// addi r11,r11,-6
	ctx.r11.s64 = ctx.r11.s64 + -6;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82389EE0) {
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
	// bl 0x82389f38
	ctx.lr = 0x82389F00;
	sub_82389F38(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82389f18
	if (ctx.cr0.eq) goto loc_82389F18;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82389f18
	if (ctx.cr6.eq) goto loc_82389F18;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x82389F18;
	sub_825FC588(ctx, base);
loc_82389F18:
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

DEFINE_REX_FUNC(sub_8238B4E8) {
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
	// lwz r10,236(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 236);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,28220
	ctx.r9.s64 = ctx.r9.s64 + 28220;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwzx r31,r10,r9
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r10,r10,24472
	ctx.r10.s64 = ctx.r10.s64 + 24472;
loc_8238B520:
	// lbzx r9,r11,r10
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stbx r9,r11,r8
	REX_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne 0x8238b520
	if (!ctx.cr0.eq) goto loc_8238B520;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_8238B540:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8238b540
	if (!ctx.cr6.eq) goto loc_8238B540;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_8238B554:
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
	// bne cr6,0x8238b554
	if (!ctx.cr6.eq) goto loc_8238B554;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,4052
	ctx.r10.s64 = ctx.r10.s64 + 4052;
loc_8238B578:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8238b578
	if (!ctx.cr6.eq) goto loc_8238B578;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_8238B58C:
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
	// bne cr6,0x8238b58c
	if (!ctx.cr6.eq) goto loc_8238B58C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825b5568
	ctx.lr = 0x8238B5AC;
	sub_825B5568(ctx, base);
	// stw r3,244(r30)
	REX_STORE_U32(ctx.r30.u32 + 244, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8238b5c4
	if (ctx.cr6.eq) goto loc_8238B5C4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825b73c0
	ctx.lr = 0x8238B5C0;
	sub_825B73C0(ctx, base);
	// stw r3,248(r30)
	REX_STORE_U32(ctx.r30.u32 + 248, ctx.r3.u32);
loc_8238B5C4:
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

DEFINE_REX_FUNC(sub_8238FE50) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8243f6d0
	ctx.lr = 0x8238FE68;
	sub_8243F6D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8238ff40
	if (ctx.cr0.eq) goto loc_8238FF40;
	// lbz r11,277(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 277);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8238ff40
	if (!ctx.cr0.eq) goto loc_8238FF40;
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,140(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// stb r11,277(r31)
	REX_STORE_U8(ctx.r31.u32 + 277, ctx.r11.u8);
	// li r11,527
	ctx.r11.s64 = 527;
	// addi r8,r8,22424
	ctx.r8.s64 = ctx.r8.s64 + 22424;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// stw r10,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// stw r7,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r7.u32);
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r9,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// bl 0x82441b00
	ctx.lr = 0x8238FEB8;
	sub_82441B00(ctx, base);
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,6272
	ctx.r9.s64 = ctx.r11.s64 + 6272;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,6272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6272);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lfs f13,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stw r9,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r9.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,-9988(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9988);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// beq cr6,0x8238ff40
	if (ctx.cr6.eq) goto loc_8238FF40;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82377978
	ctx.lr = 0x8238FF40;
	sub_82377978(ctx, base);
loc_8238FF40:
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

DEFINE_REX_FUNC(sub_823942A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x823942B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x823943a4
	if (!ctx.cr6.eq) goto loc_823943A4;
	// bl 0x82395468
	ctx.lr = 0x823942C8;
	sub_82395468(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm. r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r11,245(r31)
	REX_STORE_U8(ctx.r31.u32 + 245, ctx.r11.u8);
	// beq 0x823943a4
	if (ctx.cr0.eq) goto loc_823943A4;
	// lwz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x823943a4
	if (!ctx.cr6.eq) goto loc_823943A4;
	// addi r4,r31,256
	ctx.r4.s64 = ctx.r31.s64 + 256;
	// addi r3,r31,248
	ctx.r3.s64 = ctx.r31.s64 + 248;
	// bl 0x82372980
	ctx.lr = 0x823942F4;
	sub_82372980(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// li r29,0
	ctx.r29.s64 = 0;
	// bne 0x82394308
	if (!ctx.cr0.eq) goto loc_82394308;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// b 0x82394314
	goto loc_82394314;
loc_82394308:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823943b0
	ctx.lr = 0x82394314;
	sub_823943B0(ctx, base);
loc_82394314:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823943a4
	if (ctx.cr0.eq) goto loc_823943A4;
	// lbz r11,272(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 272);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82394344
	if (!ctx.cr0.eq) goto loc_82394344;
	// lwz r11,276(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82394344
	if (!ctx.cr6.eq) goto loc_82394344;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r30,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r30.u32);
	// stb r29,280(r31)
	REX_STORE_U8(ctx.r31.u32 + 280, ctx.r29.u8);
	// stb r11,272(r31)
	REX_STORE_U8(ctx.r31.u32 + 272, ctx.r11.u8);
loc_82394344:
	// bl 0x8243f6d0
	ctx.lr = 0x82394348;
	sub_8243F6D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823943a4
	if (ctx.cr0.eq) goto loc_823943A4;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r9,529
	ctx.r9.s64 = 529;
	// stw r29,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// addi r10,r10,22424
	ctx.r10.s64 = ctx.r10.s64 + 22424;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// bl 0x82440e68
	ctx.lr = 0x8239437C;
	sub_82440E68(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lwz r11,-9988(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9988);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823943a4
	if (ctx.cr6.eq) goto loc_823943A4;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82377978
	ctx.lr = 0x823943A4;
	sub_82377978(ctx, base);
loc_823943A4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8239A780) {
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
	// bl 0x8239a7d8
	ctx.lr = 0x8239A7A0;
	sub_8239A7D8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8239a7b8
	if (ctx.cr0.eq) goto loc_8239A7B8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8239a7b8
	if (ctx.cr6.eq) goto loc_8239A7B8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x8239A7B8;
	sub_825FC588(ctx, base);
loc_8239A7B8:
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

DEFINE_REX_FUNC(sub_8239BC78) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,27236
	ctx.r3.s64 = ctx.r11.s64 + 27236;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8239BD98) {
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
	// bl 0x8239bdf0
	ctx.lr = 0x8239BDB8;
	sub_8239BDF0(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8239bdd0
	if (ctx.cr0.eq) goto loc_8239BDD0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8239bdd0
	if (ctx.cr6.eq) goto loc_8239BDD0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x8239BDD0;
	sub_825FC588(ctx, base);
loc_8239BDD0:
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

DEFINE_REX_FUNC(sub_8239E358) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,28116
	ctx.r3.s64 = ctx.r11.s64 + 28116;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8239E408) {
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
	// bl 0x8239e460
	ctx.lr = 0x8239E428;
	sub_8239E460(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8239e440
	if (ctx.cr0.eq) goto loc_8239E440;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8239e440
	if (ctx.cr6.eq) goto loc_8239E440;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x8239E440;
	sub_825FC588(ctx, base);
loc_8239E440:
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

DEFINE_REX_FUNC(sub_8239F420) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// lwa r11,264(r3)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r3.u32 + 264));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f0,292(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,274
	ctx.r3.s64 = 274;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x82599310
	ctx.lr = 0x8239F4AC;
	sub_82599310(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f11,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f0,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r10,15672
	ctx.r8.s64 = ctx.r10.s64 + 15672;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f12
	ctx.f0.f64 = double(ctx.f12.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,15672(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15672);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-1280(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -1280);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x82372ef0
	ctx.lr = 0x8239F5B0;
	sub_82372EF0(ctx, base);
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

DEFINE_REX_FUNC(sub_823AF7F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x823AF7F8;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,372
	ctx.r3.s64 = ctx.r3.s64 + 372;
	// bl 0x82476250
	ctx.lr = 0x823AF808;
	sub_82476250(ctx, base);
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x826166d8
	ctx.lr = 0x823AF810;
	sub_826166D8(ctx, base);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,28(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// rlwimi r9,r10,11,19,21
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0x1C00) | (ctx.r9.u64 & 0xFFFFFFFFFFFFE3FF);
	// stw r9,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r9.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r9,28(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// rlwimi r9,r10,14,16,18
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0xE000) | (ctx.r9.u64 & 0xFFFFFFFFFFFF1FFF);
	// stw r9,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r9.u32);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x82616180
	ctx.lr = 0x823AF83C;
	sub_82616180(ctx, base);
	// addi r3,r31,340
	ctx.r3.s64 = ctx.r31.s64 + 340;
	// bl 0x82476250
	ctx.lr = 0x823AF844;
	sub_82476250(ctx, base);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lhz r5,10(r3)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r3.u32 + 10);
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// extsw r7,r11
	ctx.r7.s64 = ctx.r11.s32;
	// lhz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// lwz r10,244(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// std r7,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfd f13,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lfs f0,808(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 808);
	ctx.f0.f64 = double(temp.f32);
	// srawi r9,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 1;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// extsw r7,r7
	ctx.r7.s64 = ctx.r7.s32;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r7,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fcfid f13,f12
	ctx.f13.f64 = double(ctx.f12.s64);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fcfid f12,f10
	ctx.f12.f64 = double(ctx.f10.s64);
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,252(r31)
	REX_STORE_U64(ctx.r31.u32 + 252, ctx.r10.u64);
	// ld r29,96(r1)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r29,260(r31)
	REX_STORE_U64(ctx.r31.u32 + 260, ctx.r29.u64);
	// lwz r29,296(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// lwz r10,292(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// subf r27,r11,r10
	ctx.r27.u64 = ctx.r10.u64 - ctx.r11.u64;
	// extsw r26,r29
	ctx.r26.s64 = ctx.r29.s32;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// extsw r27,r27
	ctx.r27.s64 = ctx.r27.s32;
	// std r26,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r26.u64);
	// subf r10,r5,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r5.u64;
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r27,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r27.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
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
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fsubs f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f0.f64));
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f10,140(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f10,136(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f10,132(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// std r11,308(r31)
	REX_STORE_U64(ctx.r31.u32 + 308, ctx.r11.u64);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,300(r31)
	REX_STORE_U64(ctx.r31.u32 + 300, ctx.r11.u64);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823C9B70) {
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
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r10,r10,18552
	ctx.r10.s64 = ctx.r10.s64 + 18552;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_823C9B90:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r6,r9
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x823c9bec
	if (ctx.cr6.lt) goto loc_823C9BEC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x823c9b90
	if (ctx.cr6.lt) goto loc_823C9B90;
	// li r7,0
	ctx.r7.s64 = 0;
loc_823C9BB0:
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x823c8be8
	ctx.lr = 0x823C9BB8;
	sub_823C8BE8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r7,15
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 15, ctx.xer);
	// bgt cr6,0x823c9c84
	if (ctx.cr6.gt) goto loc_823C9C84;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-4848
	ctx.r12.s64 = ctx.r12.s64 + -4848;
	// lbzx r0,r12,r7
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r7.u32);
	// lis r12,-32195
	ctx.r12.s64 = -2109931520;
	// nop
	// addi r12,r12,-25620
	ctx.r12.s64 = ctx.r12.s64 + -25620;
	// nop
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr
	switch (ctx.r7.u32) {
	case 0:
		goto loc_823C9BF4;
	case 1:
		goto loc_823C9BF4;
	case 2:
		goto loc_823C9BF4;
	case 3:
		goto loc_823C9C84;
	case 4:
		goto loc_823C9C84;
	case 5:
		goto loc_823C9C84;
	case 6:
		goto loc_823C9C84;
	case 7:
		goto loc_823C9C84;
	case 8:
		goto loc_823C9C84;
	case 9:
		goto loc_823C9C84;
	case 10:
		goto loc_823C9C84;
	case 11:
		goto loc_823C9C84;
	case 12:
		goto loc_823C9C84;
	case 13:
		goto loc_823C9BFC;
	case 14:
		goto loc_823C9C58;
	case 15:
		goto loc_823C9C7C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_823C9BEC:
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// b 0x823c9bb0
	goto loc_823C9BB0;
loc_823C9BF4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823c9c88
	goto loc_823C9C88;
loc_823C9BFC:
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x823ca478
	ctx.lr = 0x823C9C04;
	sub_823CA478(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823c9bf4
	if (!ctx.cr0.eq) goto loc_823C9BF4;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9820(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9820);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c9c38
	if (ctx.cr6.eq) goto loc_823C9C38;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823c9c38
	if (ctx.cr6.eq) goto loc_823C9C38;
	// li r6,58
	ctx.r6.s64 = 58;
loc_823C9C2C:
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// bl 0x8246d8e8
	ctx.lr = 0x823C9C34;
	sub_8246D8E8(ctx, base);
	// b 0x823c9c3c
	goto loc_823C9C3C;
loc_823C9C38:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823C9C3C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823c9c4c
	if (ctx.cr6.eq) goto loc_823C9C4C;
	// lhz r11,14(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 14);
	// b 0x823c9c50
	goto loc_823C9C50;
loc_823C9C4C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823C9C50:
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x823c9c88
	goto loc_823C9C88;
loc_823C9C58:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9832(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9832);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c9c38
	if (ctx.cr6.eq) goto loc_823C9C38;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823c9c38
	if (ctx.cr6.eq) goto loc_823C9C38;
	// li r6,54
	ctx.r6.s64 = 54;
	// b 0x823c9c2c
	goto loc_823C9C2C;
loc_823C9C7C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823c9c88
	goto loc_823C9C88;
loc_823C9C84:
	// li r3,9
	ctx.r3.s64 = 9;
loc_823C9C88:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_823CDC50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x823CDC58;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,25(r5)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r5.u32 + 25);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// stw r5,260(r1)
	REX_STORE_U32(ctx.r1.u32 + 260, ctx.r5.u32);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823cdcbc
	if (ctx.cr0.eq) goto loc_823CDCBC;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,1548
	ctx.r4.s64 = ctx.r11.s64 + 1548;
	// bl 0x82226b70
	ctx.lr = 0x823CDC88;
	sub_82226B70(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x822269f0
	ctx.lr = 0x823CDC94;
	sub_822269F0(ctx, base);
	// bl 0x82227110
	ctx.lr = 0x823CDC98;
	sub_82227110(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,1704
	ctx.r11.s64 = ctx.r11.s64 + 1704;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// bl 0x82227048
	ctx.lr = 0x823CDCAC;
	sub_82227048(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x823CDCBC;
	sub_82371AF8(ctx, base);
loc_823CDCBC:
	// addi r3,r1,260
	ctx.r3.s64 = ctx.r1.s64 + 260;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// bl 0x823ce418
	ctx.lr = 0x823CDCC8;
	sub_823CE418(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r10,25(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 25);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r25,260(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 260);
	// beq 0x823cdce4
	if (ctx.cr0.eq) goto loc_823CDCE4;
	// lwz r28,8(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// b 0x823cdd08
	goto loc_823CDD08;
loc_823CDCE4:
	// lwz r10,8(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lbz r10,25(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 25);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x823cdcfc
	if (ctx.cr0.eq) goto loc_823CDCFC;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// b 0x823cdd08
	goto loc_823CDD08;
loc_823CDCFC:
	// lwz r28,8(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r25,r26
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x823cdde0
	if (!ctx.cr6.eq) goto loc_823CDDE0;
loc_823CDD08:
	// lbz r11,25(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 25);
	// lwz r31,4(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823cdd1c
	if (!ctx.cr0.eq) goto loc_823CDD1C;
	// stw r31,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
loc_823CDD1C:
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r10,r26
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x823cdd34
	if (!ctx.cr6.eq) goto loc_823CDD34;
	// stw r28,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r28.u32);
	// b 0x823cdd4c
	goto loc_823CDD4C;
loc_823CDD34:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x823cdd48
	if (!ctx.cr6.eq) goto loc_823CDD48;
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// b 0x823cdd4c
	goto loc_823CDD4C;
loc_823CDD48:
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
loc_823CDD4C:
	// lwz r9,4(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x823cdd94
	if (!ctx.cr6.eq) goto loc_823CDD94;
	// lbz r11,25(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 25);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823cdd70
	if (ctx.cr0.eq) goto loc_823CDD70;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// b 0x823cdd90
	goto loc_823CDD90;
loc_823CDD70:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// b 0x823cdd84
	goto loc_823CDD84;
loc_823CDD7C:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_823CDD84:
	// lbz r8,25(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 25);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x823cdd7c
	if (ctx.cr0.eq) goto loc_823CDD7C;
loc_823CDD90:
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
loc_823CDD94:
	// lwz r9,4(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x823cde84
	if (!ctx.cr6.eq) goto loc_823CDE84;
	// lbz r11,25(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 25);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823cddb8
	if (ctx.cr0.eq) goto loc_823CDDB8;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// b 0x823cddd8
	goto loc_823CDDD8;
loc_823CDDB8:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// b 0x823cddcc
	goto loc_823CDDCC;
loc_823CDDC4:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
loc_823CDDCC:
	// lbz r8,25(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 25);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x823cddc4
	if (ctx.cr0.eq) goto loc_823CDDC4;
loc_823CDDD8:
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// b 0x823cde84
	goto loc_823CDE84;
loc_823CDDE0:
	// stw r25,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r25.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// cmplw cr6,r25,r11
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823cde00
	if (!ctx.cr6.eq) goto loc_823CDE00;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// b 0x823cde28
	goto loc_823CDE28;
loc_823CDE00:
	// lbz r11,25(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 25);
	// lwz r31,4(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823cde14
	if (!ctx.cr0.eq) goto loc_823CDE14;
	// stw r31,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
loc_823CDE14:
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// stw r11,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r11.u32);
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// stw r25,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r25.u32);
loc_823CDE28:
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r10,r26
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x823cde40
	if (!ctx.cr6.eq) goto loc_823CDE40;
	// stw r25,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r25.u32);
	// b 0x823cde5c
	goto loc_823CDE5C;
loc_823CDE40:
	// lwz r11,4(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r26
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x823cde58
	if (!ctx.cr6.eq) goto loc_823CDE58;
	// stw r25,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
	// b 0x823cde5c
	goto loc_823CDE5C;
loc_823CDE58:
	// stw r25,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r25.u32);
loc_823CDE5C:
	// lwz r9,4(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// addi r11,r26,24
	ctx.r11.s64 = ctx.r26.s64 + 24;
	// addi r10,r25,24
	ctx.r10.s64 = ctx.r25.s64 + 24;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r9,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r9.u32);
	// beq cr6,0x823cde84
	if (ctx.cr6.eq) goto loc_823CDE84;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// stb r8,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
loc_823CDE84:
	// lbz r11,24(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x823ce01c
	if (!ctx.cr6.eq) goto loc_823CE01C;
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823ce018
	if (ctx.cr6.eq) goto loc_823CE018;
	// li r29,0
	ctx.r29.s64 = 0;
loc_823CDEA8:
	// lbz r11,24(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 24);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x823ce018
	if (!ctx.cr6.eq) goto loc_823CE018;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823cdf60
	if (!ctx.cr6.eq) goto loc_823CDF60;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lbz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 24);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x823cdee8
	if (!ctx.cr0.eq) goto loc_823CDEE8;
	// stb r30,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r30.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stb r29,24(r31)
	REX_STORE_U8(ctx.r31.u32 + 24, ctx.r29.u8);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823ce348
	ctx.lr = 0x823CDEE4;
	sub_823CE348(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
loc_823CDEE8:
	// lbz r10,25(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 25);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x823cdfb4
	if (!ctx.cr0.eq) goto loc_823CDFB4;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r9,24(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 24);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x823cdf14
	if (!ctx.cr6.eq) goto loc_823CDF14;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lbz r9,24(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 24);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// beq cr6,0x823cdfb0
	if (ctx.cr6.eq) goto loc_823CDFB0;
loc_823CDF14:
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lbz r9,24(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 24);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x823cdf3c
	if (!ctx.cr6.eq) goto loc_823CDF3C;
	// stb r30,24(r10)
	REX_STORE_U8(ctx.r10.u32 + 24, ctx.r30.u8);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// stb r29,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r29.u8);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823ce3b0
	ctx.lr = 0x823CDF38;
	sub_823CE3B0(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
loc_823CDF3C:
	// lbz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 24);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stb r10,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r10.u8);
	// stb r30,24(r31)
	REX_STORE_U8(ctx.r31.u32 + 24, ctx.r30.u8);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stb r30,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r30.u8);
	// bl 0x823ce348
	ctx.lr = 0x823CDF5C;
	sub_823CE348(ctx, base);
	// b 0x823ce018
	goto loc_823CE018;
loc_823CDF60:
	// lbz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 24);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x823cdf84
	if (!ctx.cr0.eq) goto loc_823CDF84;
	// stb r30,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r30.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stb r29,24(r31)
	REX_STORE_U8(ctx.r31.u32 + 24, ctx.r29.u8);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823ce3b0
	ctx.lr = 0x823CDF80;
	sub_823CE3B0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_823CDF84:
	// lbz r10,25(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 25);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x823cdfb4
	if (!ctx.cr0.eq) goto loc_823CDFB4;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lbz r9,24(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 24);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x823cdfd0
	if (!ctx.cr6.eq) goto loc_823CDFD0;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r9,24(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 24);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x823cdfd0
	if (!ctx.cr6.eq) goto loc_823CDFD0;
loc_823CDFB0:
	// stb r29,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r29.u8);
loc_823CDFB4:
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// mr r28,r31
	ctx.r28.u64 = ctx.r31.u64;
	// lwz r31,4(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823cdea8
	if (!ctx.cr6.eq) goto loc_823CDEA8;
	// b 0x823ce018
	goto loc_823CE018;
loc_823CDFD0:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r9,24(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 24);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x823cdff8
	if (!ctx.cr6.eq) goto loc_823CDFF8;
	// stb r30,24(r10)
	REX_STORE_U8(ctx.r10.u32 + 24, ctx.r30.u8);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// stb r29,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r29.u8);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823ce348
	ctx.lr = 0x823CDFF4;
	sub_823CE348(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_823CDFF8:
	// lbz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 24);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stb r10,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r10.u8);
	// stb r30,24(r31)
	REX_STORE_U8(ctx.r31.u32 + 24, ctx.r30.u8);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stb r30,24(r11)
	REX_STORE_U8(ctx.r11.u32 + 24, ctx.r30.u8);
	// bl 0x823ce3b0
	ctx.lr = 0x823CE018;
	sub_823CE3B0(ctx, base);
loc_823CE018:
	// stb r30,24(r28)
	REX_STORE_U8(ctx.r28.u32 + 24, ctx.r30.u8);
loc_823CE01C:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x825fc588
	ctx.lr = 0x823CE024;
	sub_825FC588(ctx, base);
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823ce038
	if (ctx.cr6.eq) goto loc_823CE038;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
loc_823CE038:
	// stw r25,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r25.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823E56C0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x823e5950
	sub_823E5950(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823E6AF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x823E6B00;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x823d9de8
	ctx.lr = 0x823E6B10;
	sub_823D9DE8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r11,r11,-31816
	ctx.r11.s64 = ctx.r11.s64 + -31816;
	// stw r31,156(r30)
	REX_STORE_U32(ctx.r30.u32 + 156, ctx.r31.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// bl 0x82419f88
	ctx.lr = 0x823E6B2C;
	sub_82419F88(ctx, base);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// li r4,164
	ctx.r4.s64 = 164;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825fc4b0
	ctx.lr = 0x823E6B44;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823e6ba0
	if (ctx.cr0.eq) goto loc_823E6BA0;
	// li r11,27
	ctx.r11.s64 = 27;
	// stw r30,160(r3)
	REX_STORE_U32(ctx.r3.u32 + 160, ctx.r30.u32);
	// stw r31,112(r3)
	REX_STORE_U32(ctx.r3.u32 + 112, ctx.r31.u32);
	// addi r10,r3,-4
	ctx.r10.s64 = ctx.r3.s64 + -4;
	// stw r31,120(r3)
	REX_STORE_U32(ctx.r3.u32 + 120, ctx.r31.u32);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r31,124(r3)
	REX_STORE_U32(ctx.r3.u32 + 124, ctx.r31.u32);
	// stb r31,132(r3)
	REX_STORE_U8(ctx.r3.u32 + 132, ctx.r31.u8);
	// stb r31,133(r3)
	REX_STORE_U8(ctx.r3.u32 + 133, ctx.r31.u8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stb r31,134(r3)
	REX_STORE_U8(ctx.r3.u32 + 134, ctx.r31.u8);
	// stw r31,136(r3)
	REX_STORE_U32(ctx.r3.u32 + 136, ctx.r31.u32);
	// stw r31,140(r3)
	REX_STORE_U32(ctx.r3.u32 + 140, ctx.r31.u32);
	// stw r31,144(r3)
	REX_STORE_U32(ctx.r3.u32 + 144, ctx.r31.u32);
loc_823E6B84:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x823e6b84
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823E6B84;
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r31,108(r3)
	REX_STORE_U32(ctx.r3.u32 + 108, ctx.r31.u32);
	// stw r31,116(r3)
	REX_STORE_U32(ctx.r3.u32 + 116, ctx.r31.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,128(r3)
	REX_STORE_U32(ctx.r3.u32 + 128, ctx.r11.u32);
loc_823E6BA0:
	// stw r31,156(r30)
	REX_STORE_U32(ctx.r30.u32 + 156, ctx.r31.u32);
	// stw r29,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r29.u32);
	// lwz r3,156(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 156);
	// bl 0x823e6d90
	ctx.lr = 0x823E6BB0;
	sub_823E6D90(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823ED808) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x823edfc0
	sub_823EDFC0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823ED898) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x823ED8A0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,272(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 272);
	// bl 0x82470c18
	ctx.lr = 0x823ED8B0;
	sub_82470C18(ctx, base);
	// bl 0x82619bf0
	ctx.lr = 0x823ED8B4;
	sub_82619BF0(ctx, base);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// li r26,0
	ctx.r26.s64 = 0;
	// stw r3,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r3.u32);
	// stw r26,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r26.u32);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// cmpwi cr6,r11,23
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 23, ctx.xer);
	// bgt cr6,0x823ed92c
	if (ctx.cr6.gt) goto loc_823ED92C;
	// beq cr6,0x823ed924
	if (ctx.cr6.eq) goto loc_823ED924;
	// cmpwi cr6,r11,18
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 18, ctx.xer);
	// beq cr6,0x823ed91c
	if (ctx.cr6.eq) goto loc_823ED91C;
	// cmpwi cr6,r11,19
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 19, ctx.xer);
	// beq cr6,0x823ed914
	if (ctx.cr6.eq) goto loc_823ED914;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// beq cr6,0x823ed90c
	if (ctx.cr6.eq) goto loc_823ED90C;
	// cmpwi cr6,r11,21
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 21, ctx.xer);
	// beq cr6,0x823ed904
	if (ctx.cr6.eq) goto loc_823ED904;
	// cmpwi cr6,r11,22
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 22, ctx.xer);
	// bne cr6,0x823ed94c
	if (!ctx.cr6.eq) goto loc_823ED94C;
	// li r11,7
	ctx.r11.s64 = 7;
	// b 0x823ed978
	goto loc_823ED978;
loc_823ED904:
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x823ed978
	goto loc_823ED978;
loc_823ED90C:
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x823ed978
	goto loc_823ED978;
loc_823ED914:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x823ed978
	goto loc_823ED978;
loc_823ED91C:
	// stw r26,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r26.u32);
	// b 0x823ed97c
	goto loc_823ED97C;
loc_823ED924:
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x823ed978
	goto loc_823ED978;
loc_823ED92C:
	// cmpwi cr6,r11,25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 25, ctx.xer);
	// beq cr6,0x823ed974
	if (ctx.cr6.eq) goto loc_823ED974;
	// cmpwi cr6,r11,29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 29, ctx.xer);
	// beq cr6,0x823ed96c
	if (ctx.cr6.eq) goto loc_823ED96C;
	// cmpwi cr6,r11,57
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 57, ctx.xer);
	// beq cr6,0x823ed964
	if (ctx.cr6.eq) goto loc_823ED964;
	// cmpwi cr6,r11,58
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 58, ctx.xer);
	// beq cr6,0x823ed95c
	if (ctx.cr6.eq) goto loc_823ED95C;
loc_823ED94C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r26,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r26.u32);
	// stb r11,304(r31)
	REX_STORE_U8(ctx.r31.u32 + 304, ctx.r11.u8);
	// b 0x823ed97c
	goto loc_823ED97C;
loc_823ED95C:
	// li r11,9
	ctx.r11.s64 = 9;
	// b 0x823ed978
	goto loc_823ED978;
loc_823ED964:
	// li r11,8
	ctx.r11.s64 = 8;
	// b 0x823ed978
	goto loc_823ED978;
loc_823ED96C:
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x823ed978
	goto loc_823ED978;
loc_823ED974:
	// li r11,3
	ctx.r11.s64 = 3;
loc_823ED978:
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
loc_823ED97C:
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// bl 0x82223348
	ctx.lr = 0x823ED984;
	sub_82223348(ctx, base);
	// lbz r28,4033(r3)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
	// li r30,2221
	ctx.r30.s64 = 2221;
loc_823ED98C:
	// bl 0x82223348
	ctx.lr = 0x823ED990;
	sub_82223348(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r30,8331
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 8331, ctx.xer);
	// blt cr6,0x823ed9a4
	if (ctx.cr6.lt) goto loc_823ED9A4;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// b 0x823ed9b0
	goto loc_823ED9B0;
loc_823ED9A4:
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbz r11,1000(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1000);
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
loc_823ED9B0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823ed9d8
	if (ctx.cr0.eq) goto loc_823ED9D8;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823c98b0
	ctx.lr = 0x823ED9C4;
	sub_823C98B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823ed9d8
	if (ctx.cr0.eq) goto loc_823ED9D8;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r29,5
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 5, ctx.xer);
	// bge cr6,0x823ed9e4
	if (!ctx.cr6.lt) goto loc_823ED9E4;
loc_823ED9D8:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,2321
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2321, ctx.xer);
	// blt cr6,0x823ed98c
	if (ctx.cr6.lt) goto loc_823ED98C;
loc_823ED9E4:
	// addic r11,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subfe r11,r11,r29
	temp.u8 = (~ctx.r11.u32 + ctx.r29.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,287(r31)
	REX_STORE_U8(ctx.r31.u32 + 287, ctx.r11.u8);
	// bl 0x823ee488
	ctx.lr = 0x823ED9F8;
	sub_823EE488(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r28,r31,256
	ctx.r28.s64 = ctx.r31.s64 + 256;
	// addi r30,r11,11908
	ctx.r30.s64 = ctx.r11.s64 + 11908;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// li r29,2
	ctx.r29.s64 = 2;
	// addi r27,r11,22392
	ctx.r27.s64 = ctx.r11.s64 + 22392;
loc_823EDA10:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// li r4,188
	ctx.r4.s64 = 188;
	// bl 0x825fc4b0
	ctx.lr = 0x823EDA20;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823eda34
	if (ctx.cr0.eq) goto loc_823EDA34;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x823d2280
	ctx.lr = 0x823EDA30;
	sub_823D2280(ctx, base);
	// b 0x823eda38
	goto loc_823EDA38;
loc_823EDA34:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_823EDA38:
	// li r11,10
	ctx.r11.s64 = 10;
	// stwu r3,4(r28)
	ea = 4 + ctx.r28.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r28.u32 = ea;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r11,120(r3)
	REX_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x823eda10
	if (!ctx.cr0.eq) goto loc_823EDA10;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// sth r26,84(r11)
	REX_STORE_U16(ctx.r11.u32 + 84, ctx.r26.u16);
	// lwz r3,4(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x825fc4b0
	ctx.lr = 0x823EDA68;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823eda78
	if (ctx.cr0.eq) goto loc_823EDA78;
	// bl 0x823dc9a0
	ctx.lr = 0x823EDA74;
	sub_823DC9A0(ctx, base);
	// b 0x823eda7c
	goto loc_823EDA7C;
loc_823EDA78:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_823EDA7C:
	// stw r3,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r3.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,272(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 272);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r4,280(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x823edaa0
	if (ctx.cr6.eq) goto loc_823EDAA0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ef1a0
	ctx.lr = 0x823EDAA0;
	sub_823EF1A0(ctx, base);
loc_823EDAA0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823FC8A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x823FC8A8;
	__savegprlr_26(ctx, base);
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r26,r3,252
	ctx.r26.s64 = ctx.r3.s64 + 252;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82523e48
	ctx.lr = 0x823FC8BC;
	sub_82523E48(ctx, base);
	// lwz r11,208(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 208);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x823fccf8
	if (ctx.cr6.gt) goto loc_823FCCF8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823fcd00
	if (ctx.cr6.eq) goto loc_823FCD00;
	// bdz 0x823fc8f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_823FC8F0;
	// bdz 0x823fcc18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_823FCC18;
	// bdz 0x823fcc20
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_823FCC20;
	// bdz 0x823fcc28
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_823FCC28;
	// bdz 0x823fcc30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_823FCC30;
	// bdz 0x823fcc38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_823FCC38;
	// b 0x823fcb70
	goto loc_823FCB70;
loc_823FC8F0:
	// li r10,1551
	ctx.r10.s64 = 1551;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r9,1651
	ctx.r9.s64 = 1651;
	// li r8,1851
	ctx.r8.s64 = 1851;
	// li r10,1861
	ctx.r10.s64 = 1861;
	// stw r9,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// li r9,2061
	ctx.r9.s64 = 2061;
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// li r7,2161
	ctx.r7.s64 = 2161;
	// lwz r11,-9876(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9876);
	// li r8,2211
	ctx.r8.s64 = 2211;
	// li r10,2221
	ctx.r10.s64 = 2221;
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// stw r7,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r8,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// stw r10,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r10.u32);
	// beq cr6,0x823fc950
	if (ctx.cr6.eq) goto loc_823FC950;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x823FC94C;
	sub_8246D6A8(ctx, base);
	// b 0x823fc954
	goto loc_823FC954;
loc_823FC950:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823FC954:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r10,r3,1551
	ctx.r10.s64 = ctx.r3.s64 + 1551;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lwz r11,-9836(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9836);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fc97c
	if (ctx.cr6.eq) goto loc_823FC97C;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x823FC978;
	sub_8246D6A8(ctx, base);
	// b 0x823fc980
	goto loc_823FC980;
loc_823FC97C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823FC980:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// addi r10,r3,1651
	ctx.r10.s64 = ctx.r3.s64 + 1651;
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// lwz r11,-9860(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9860);
	// lwz r10,-9868(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -9868);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fc9c0
	if (ctx.cr6.eq) goto loc_823FC9C0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823fc9c0
	if (ctx.cr6.eq) goto loc_823FC9C0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fc9c0
	if (ctx.cr6.eq) goto loc_823FC9C0;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x823fc9c4
	goto loc_823FC9C4;
loc_823FC9C0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823FC9C4:
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// addi r11,r11,1851
	ctx.r11.s64 = ctx.r11.s64 + 1851;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// lwz r11,-9848(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -9848);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fc9f0
	if (ctx.cr6.eq) goto loc_823FC9F0;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x823FC9E8;
	sub_8246D6A8(ctx, base);
	// lwz r10,-9868(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -9868);
	// b 0x823fc9f4
	goto loc_823FC9F4;
loc_823FC9F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823FC9F4:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r9,r3,1861
	ctx.r9.s64 = ctx.r3.s64 + 1861;
	// stw r9,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// lwz r11,-9856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9856);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fca20
	if (ctx.cr6.eq) goto loc_823FCA20;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x823FCA18;
	sub_8246D6A8(ctx, base);
	// lwz r10,-9868(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -9868);
	// b 0x823fca24
	goto loc_823FCA24;
loc_823FCA20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823FCA24:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r9,r3,2061
	ctx.r9.s64 = ctx.r3.s64 + 2061;
	// stw r9,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// lwz r11,-9828(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9828);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fca5c
	if (ctx.cr6.eq) goto loc_823FCA5C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823fca5c
	if (ctx.cr6.eq) goto loc_823FCA5C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fca5c
	if (ctx.cr6.eq) goto loc_823FCA5C;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x823fca60
	goto loc_823FCA60;
loc_823FCA5C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823FCA60:
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// addi r11,r11,2161
	ctx.r11.s64 = ctx.r11.s64 + 2161;
	// stw r11,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r11.u32);
	// lwz r11,-9864(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -9864);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fca98
	if (ctx.cr6.eq) goto loc_823FCA98;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823fca98
	if (ctx.cr6.eq) goto loc_823FCA98;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fca98
	if (ctx.cr6.eq) goto loc_823FCA98;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x823fca9c
	goto loc_823FCA9C;
loc_823FCA98:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823FCA9C:
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// addi r11,r11,2211
	ctx.r11.s64 = ctx.r11.s64 + 2211;
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// lwz r11,-9844(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -9844);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fcad4
	if (ctx.cr6.eq) goto loc_823FCAD4;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823fcad4
	if (ctx.cr6.eq) goto loc_823FCAD4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fcad4
	if (ctx.cr6.eq) goto loc_823FCAD4;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x823fcad8
	goto loc_823FCAD8;
loc_823FCAD4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823FCAD8:
	// addi r11,r11,2221
	ctx.r11.s64 = ctx.r11.s64 + 2221;
	// addi r30,r1,100
	ctx.r30.s64 = ctx.r1.s64 + 100;
	// stw r11,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r11.u32);
	// li r28,8
	ctx.r28.s64 = 8;
loc_823FCAE8:
	// lwz r31,-4(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + -4);
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x823fcb54
	goto loc_823FCB54;
loc_823FCAF4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x823FCAFC;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823dc188
	ctx.lr = 0x823FCB0C;
	sub_823DC188(ctx, base);
	// lbz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 160);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823fcb50
	if (ctx.cr0.eq) goto loc_823FCB50;
	// bl 0x82223348
	ctx.lr = 0x823FCB1C;
	sub_82223348(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r31,8331
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8331, ctx.xer);
	// blt cr6,0x823fcb30
	if (ctx.cr6.lt) goto loc_823FCB30;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823fcb3c
	goto loc_823FCB3C;
loc_823FCB30:
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1000(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1000);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
loc_823FCB3C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fcb50
	if (ctx.cr0.eq) goto loc_823FCB50;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x823FCB50;
	sub_824B96F8(ctx, base);
loc_823FCB50:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_823FCB54:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x823fcaf4
	if (ctx.cr6.lt) goto loc_823FCAF4;
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// bne 0x823fcae8
	if (!ctx.cr0.eq) goto loc_823FCAE8;
	// b 0x823fcda4
	goto loc_823FCDA4;
loc_823FCB70:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9820(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9820);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fcb90
	if (ctx.cr6.eq) goto loc_823FCB90;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x823FCB8C;
	sub_8246D6A8(ctx, base);
	// b 0x823fcb94
	goto loc_823FCB94;
loc_823FCB90:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823FCB94:
	// addi r30,r3,2321
	ctx.r30.s64 = ctx.r3.s64 + 2321;
	// li r31,2321
	ctx.r31.s64 = 2321;
	// cmplwi cr6,r30,2321
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2321, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// ble cr6,0x823fcda4
	if (!ctx.cr6.gt) goto loc_823FCDA4;
loc_823FCBA8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x823FCBB0;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823dc188
	ctx.lr = 0x823FCBC0;
	sub_823DC188(ctx, base);
	// lbz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 160);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823fcc04
	if (ctx.cr0.eq) goto loc_823FCC04;
	// bl 0x82223348
	ctx.lr = 0x823FCBD0;
	sub_82223348(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r31,8331
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8331, ctx.xer);
	// blt cr6,0x823fcbe4
	if (ctx.cr6.lt) goto loc_823FCBE4;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823fcbf0
	goto loc_823FCBF0;
loc_823FCBE4:
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1000(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1000);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
loc_823FCBF0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fcc04
	if (ctx.cr0.eq) goto loc_823FCC04;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x823FCC04;
	sub_824B96F8(ctx, base);
loc_823FCC04:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x823fcba8
	if (ctx.cr6.lt) goto loc_823FCBA8;
	// b 0x823fcda4
	goto loc_823FCDA4;
loc_823FCC18:
	// li r29,1
	ctx.r29.s64 = 1;
	// b 0x823fcc3c
	goto loc_823FCC3C;
loc_823FCC20:
	// li r29,2
	ctx.r29.s64 = 2;
	// b 0x823fcc3c
	goto loc_823FCC3C;
loc_823FCC28:
	// li r29,4
	ctx.r29.s64 = 4;
	// b 0x823fcc3c
	goto loc_823FCC3C;
loc_823FCC30:
	// li r29,3
	ctx.r29.s64 = 3;
	// b 0x823fcc3c
	goto loc_823FCC3C;
loc_823FCC38:
	// li r29,5
	ctx.r29.s64 = 5;
loc_823FCC3C:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9852(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9852);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fcc5c
	if (ctx.cr6.eq) goto loc_823FCC5C;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x823FCC58;
	sub_8246D6A8(ctx, base);
	// b 0x823fcc60
	goto loc_823FCC60;
loc_823FCC5C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823FCC60:
	// addi r30,r3,551
	ctx.r30.s64 = ctx.r3.s64 + 551;
	// li r31,551
	ctx.r31.s64 = 551;
	// cmplwi cr6,r30,551
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 551, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// ble cr6,0x823fcda4
	if (!ctx.cr6.gt) goto loc_823FCDA4;
loc_823FCC74:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8be8
	ctx.lr = 0x823FCC7C;
	sub_823C8BE8(ctx, base);
	// bl 0x8246e588
	ctx.lr = 0x823FCC80;
	sub_8246E588(ctx, base);
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x823fcce4
	if (!ctx.cr6.eq) goto loc_823FCCE4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x823FCC90;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823dc188
	ctx.lr = 0x823FCCA0;
	sub_823DC188(ctx, base);
	// lbz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 160);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823fcce4
	if (ctx.cr0.eq) goto loc_823FCCE4;
	// bl 0x82223348
	ctx.lr = 0x823FCCB0;
	sub_82223348(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r31,8331
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8331, ctx.xer);
	// blt cr6,0x823fccc4
	if (ctx.cr6.lt) goto loc_823FCCC4;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823fccd0
	goto loc_823FCCD0;
loc_823FCCC4:
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1000(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1000);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
loc_823FCCD0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fcce4
	if (ctx.cr0.eq) goto loc_823FCCE4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x823FCCE4;
	sub_824B96F8(ctx, base);
loc_823FCCE4:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x823fcc74
	if (ctx.cr6.lt) goto loc_823FCC74;
	// b 0x823fcda4
	goto loc_823FCDA4;
loc_823FCCF8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,208(r27)
	REX_STORE_U32(ctx.r27.u32 + 208, ctx.r11.u32);
loc_823FCD00:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9872);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fcd20
	if (ctx.cr6.eq) goto loc_823FCD20;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x823FCD1C;
	sub_8246D6A8(ctx, base);
	// b 0x823fcd24
	goto loc_823FCD24;
loc_823FCD20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823FCD24:
	// addi r30,r3,51
	ctx.r30.s64 = ctx.r3.s64 + 51;
	// li r31,51
	ctx.r31.s64 = 51;
	// cmplwi cr6,r30,51
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 51, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// ble cr6,0x823fcda4
	if (!ctx.cr6.gt) goto loc_823FCDA4;
loc_823FCD38:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x823FCD40;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823dc188
	ctx.lr = 0x823FCD50;
	sub_823DC188(ctx, base);
	// lbz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 160);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823fcd94
	if (ctx.cr0.eq) goto loc_823FCD94;
	// bl 0x82223348
	ctx.lr = 0x823FCD60;
	sub_82223348(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r31,8331
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8331, ctx.xer);
	// blt cr6,0x823fcd74
	if (ctx.cr6.lt) goto loc_823FCD74;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823fcd80
	goto loc_823FCD80;
loc_823FCD74:
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1000(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1000);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
loc_823FCD80:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fcd94
	if (ctx.cr0.eq) goto loc_823FCD94;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x823FCD94;
	sub_824B96F8(ctx, base);
loc_823FCD94:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x823fcd38
	if (ctx.cr6.lt) goto loc_823FCD38;
loc_823FCDA4:
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// addi r30,r27,300
	ctx.r30.s64 = ctx.r27.s64 + 300;
	// lwz r10,4(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// stw r11,244(r27)
	REX_STORE_U32(ctx.r27.u32 + 244, ctx.r11.u32);
	// lwz r11,308(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 308);
	// lwz r9,304(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 304);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823fcdf4
	if (ctx.cr6.eq) goto loc_823FCDF4;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823fcdf0
	if (ctx.cr6.eq) goto loc_823FCDF0;
loc_823FCDD8:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne cr6,0x823fcdd8
	if (!ctx.cr6.eq) goto loc_823FCDD8;
loc_823FCDF0:
	// stw r9,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
loc_823FCDF4:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ec158
	ctx.lr = 0x823FCE08;
	sub_823EC158(ctx, base);
	// lwz r10,208(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 208);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// bge cr6,0x823fce1c
	if (!ctx.cr6.lt) goto loc_823FCE1C;
	// li r11,1
	ctx.r11.s64 = 1;
loc_823FCE1C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fce38
	if (ctx.cr0.eq) goto loc_823FCE38;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ec158
	ctx.lr = 0x823FCE38;
	sub_823EC158(ctx, base);
loc_823FCE38:
	// lwz r10,208(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 208);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bge cr6,0x823fce4c
	if (!ctx.cr6.lt) goto loc_823FCE4C;
	// li r11,1
	ctx.r11.s64 = 1;
loc_823FCE4C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fce68
	if (ctx.cr0.eq) goto loc_823FCE68;
	// li r11,2
	ctx.r11.s64 = 2;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ec158
	ctx.lr = 0x823FCE68;
	sub_823EC158(ctx, base);
loc_823FCE68:
	// lwz r10,208(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 208);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x823fce7c
	if (!ctx.cr6.eq) goto loc_823FCE7C;
	// li r11,1
	ctx.r11.s64 = 1;
loc_823FCE7C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fce98
	if (ctx.cr0.eq) goto loc_823FCE98;
	// li r11,21
	ctx.r11.s64 = 21;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ec158
	ctx.lr = 0x823FCE98;
	sub_823EC158(ctx, base);
loc_823FCE98:
	// lwz r10,208(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 208);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x823fceac
	if (!ctx.cr6.eq) goto loc_823FCEAC;
	// li r11,1
	ctx.r11.s64 = 1;
loc_823FCEAC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fcee8
	if (ctx.cr0.eq) goto loc_823FCEE8;
	// li r31,3
	ctx.r31.s64 = 3;
loc_823FCEB8:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823e0d30
	ctx.lr = 0x823FCEC4;
	sub_823E0D30(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823fcedc
	if (ctx.cr0.eq) goto loc_823FCEDC;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ec158
	ctx.lr = 0x823FCEDC;
	sub_823EC158(ctx, base);
loc_823FCEDC:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,20
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 20, ctx.xer);
	// ble cr6,0x823fceb8
	if (!ctx.cr6.gt) goto loc_823FCEB8;
loc_823FCEE8:
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r8,22
	ctx.r8.s64 = 22;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r8,292(r27)
	REX_STORE_U32(ctx.r27.u32 + 292, ctx.r8.u32);
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// stw r10,296(r27)
	REX_STORE_U32(ctx.r27.u32 + 296, ctx.r10.u32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// subfc r9,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r9.u64 = ctx.r11.u64 - ctx.r10.u64;
	// eqv r11,r10,r11
	ctx.r11.u64 = ~(ctx.r10.u64 ^ ctx.r11.u64);
	// rlwinm r11,r11,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// stb r11,281(r27)
	REX_STORE_U8(ctx.r27.u32 + 281, ctx.r11.u8);
	// bl 0x823fcf38
	ctx.lr = 0x823FCF2C;
	sub_823FCF38(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82429A68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x82429A70;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,-1
	ctx.r29.s64 = -1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,156(r3)
	REX_STORE_U32(ctx.r3.u32 + 156, ctx.r30.u32);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// stw r30,160(r3)
	REX_STORE_U32(ctx.r3.u32 + 160, ctx.r30.u32);
	// addi r27,r3,224
	ctx.r27.s64 = ctx.r3.s64 + 224;
	// stw r30,164(r3)
	REX_STORE_U32(ctx.r3.u32 + 164, ctx.r30.u32);
	// li r28,9
	ctx.r28.s64 = 9;
	// stw r30,168(r3)
	REX_STORE_U32(ctx.r3.u32 + 168, ctx.r30.u32);
	// stb r30,172(r3)
	REX_STORE_U8(ctx.r3.u32 + 172, ctx.r30.u8);
	// stw r30,176(r3)
	REX_STORE_U32(ctx.r3.u32 + 176, ctx.r30.u32);
	// stw r29,180(r3)
	REX_STORE_U32(ctx.r3.u32 + 180, ctx.r29.u32);
	// stw r29,184(r3)
	REX_STORE_U32(ctx.r3.u32 + 184, ctx.r29.u32);
	// stw r30,188(r3)
	REX_STORE_U32(ctx.r3.u32 + 188, ctx.r30.u32);
	// stb r30,192(r3)
	REX_STORE_U8(ctx.r3.u32 + 192, ctx.r30.u8);
	// stw r30,196(r3)
	REX_STORE_U32(ctx.r3.u32 + 196, ctx.r30.u32);
	// stw r30,200(r3)
	REX_STORE_U32(ctx.r3.u32 + 200, ctx.r30.u32);
	// stw r30,208(r3)
	REX_STORE_U32(ctx.r3.u32 + 208, ctx.r30.u32);
	// stw r30,212(r3)
	REX_STORE_U32(ctx.r3.u32 + 212, ctx.r30.u32);
	// stb r30,216(r3)
	REX_STORE_U8(ctx.r3.u32 + 216, ctx.r30.u8);
	// stb r30,217(r3)
	REX_STORE_U8(ctx.r3.u32 + 217, ctx.r30.u8);
loc_82429ACC:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82429580
	ctx.lr = 0x82429AD4;
	sub_82429580(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r27,r27,64
	ctx.r27.s64 = ctx.r27.s64 + 64;
	// bge 0x82429acc
	if (!ctx.cr0.lt) goto loc_82429ACC;
	// li r11,38
	ctx.r11.s64 = 38;
	// stw r26,868(r31)
	REX_STORE_U32(ctx.r31.u32 + 868, ctx.r26.u32);
	// stw r30,864(r31)
	REX_STORE_U32(ctx.r31.u32 + 864, ctx.r30.u32);
	// addi r10,r31,-4
	ctx.r10.s64 = ctx.r31.s64 + -4;
	// stw r30,872(r31)
	REX_STORE_U32(ctx.r31.u32 + 872, ctx.r30.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// stw r29,876(r31)
	REX_STORE_U32(ctx.r31.u32 + 876, ctx.r29.u32);
	// stw r30,880(r31)
	REX_STORE_U32(ctx.r31.u32 + 880, ctx.r30.u32);
	// stw r30,884(r31)
	REX_STORE_U32(ctx.r31.u32 + 884, ctx.r30.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stb r30,888(r31)
	REX_STORE_U8(ctx.r31.u32 + 888, ctx.r30.u8);
	// stw r30,896(r31)
	REX_STORE_U32(ctx.r31.u32 + 896, ctx.r30.u32);
	// stw r30,900(r31)
	REX_STORE_U32(ctx.r31.u32 + 900, ctx.r30.u32);
	// stw r30,904(r31)
	REX_STORE_U32(ctx.r31.u32 + 904, ctx.r30.u32);
	// stw r30,908(r31)
	REX_STORE_U32(ctx.r31.u32 + 908, ctx.r30.u32);
	// stw r30,912(r31)
	REX_STORE_U32(ctx.r31.u32 + 912, ctx.r30.u32);
loc_82429B20:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82429b20
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82429B20;
	// lis r29,-32110
	ctx.r29.s64 = -2104360960;
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// lwz r3,-9888(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -9888);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82429b6c
	if (!ctx.cr6.eq) goto loc_82429B6C;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// li r4,5264
	ctx.r4.s64 = 5264;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x82429B54;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82429b64
	if (ctx.cr0.eq) goto loc_82429B64;
	// bl 0x824444a8
	ctx.lr = 0x82429B60;
	sub_824444A8(ctx, base);
	// b 0x82429b68
	goto loc_82429B68;
loc_82429B64:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82429B68:
	// stw r3,-9888(r29)
	REX_STORE_U32(ctx.r29.u32 + -9888, ctx.r3.u32);
loc_82429B6C:
	// stb r30,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r30.u8);
	// stw r30,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// stw r30,5232(r3)
	REX_STORE_U32(ctx.r3.u32 + 5232, ctx.r30.u32);
	// stw r30,5236(r3)
	REX_STORE_U32(ctx.r3.u32 + 5236, ctx.r30.u32);
	// bl 0x8243f118
	ctx.lr = 0x82429B80;
	sub_8243F118(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82435418) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x82435420;
	__savegprlr_24(ctx, base);
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r24,0
	ctx.r24.s64 = 0;
	// bl 0x82223348
	ctx.lr = 0x82435430;
	sub_82223348(ctx, base);
	// bl 0x82223348
	ctx.lr = 0x82435434;
	sub_82223348(ctx, base);
	// lbz r11,18142(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 18142);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8243544c
	if (ctx.cr0.eq) goto loc_8243544C;
	// li r24,1
	ctx.r24.s64 = 1;
loc_8243544C:
	// addi r26,r27,400
	ctx.r26.s64 = ctx.r27.s64 + 400;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82523e48
	ctx.lr = 0x82435458;
	sub_82523E48(ctx, base);
	// bl 0x82223348
	ctx.lr = 0x8243545C;
	sub_82223348(ctx, base);
	// lwz r11,356(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 356);
	// lbz r25,4033(r3)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x82435e00
	if (ctx.cr6.gt) goto loc_82435E00;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82435568
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82435568;
	// bdzf 4*cr6+eq,0x824356a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_824356A0;
	// bdzf 4*cr6+eq,0x82435788
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82435788;
	// bdzf 4*cr6+eq,0x82435870
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82435870;
	// bdzf 4*cr6+eq,0x82435958
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82435958;
	// bdzf 4*cr6+eq,0x82435a40
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82435A40;
	// bne cr6,0x82435b28
	if (!ctx.cr6.eq) goto loc_82435B28;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9820(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9820);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824354b0
	if (ctx.cr6.eq) goto loc_824354B0;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x824354AC;
	sub_8246D6A8(ctx, base);
	// b 0x824354b4
	goto loc_824354B4;
loc_824354B0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824354B4:
	// addi r30,r3,2321
	ctx.r30.s64 = ctx.r3.s64 + 2321;
	// li r31,2321
	ctx.r31.s64 = 2321;
	// cmplwi cr6,r30,2321
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2321, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// ble cr6,0x82435e00
	if (!ctx.cr6.gt) goto loc_82435E00;
loc_824354C8:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c98b0
	ctx.lr = 0x824354D4;
	sub_823C98B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435554
	if (ctx.cr0.eq) goto loc_82435554;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8c40
	ctx.lr = 0x824354E4;
	sub_823C8C40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82435554
	if (ctx.cr0.lt) goto loc_82435554;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ca840
	ctx.lr = 0x824354F4;
	sub_823CA840(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82435504
	if (!ctx.cr6.eq) goto loc_82435504;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8243551c
	goto loc_8243551C;
loc_82435504:
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435518
	if (ctx.cr0.eq) goto loc_82435518;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8243551c
	if (ctx.cr6.eq) goto loc_8243551C;
loc_82435518:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8243551C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435554
	if (ctx.cr0.eq) goto loc_82435554;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x8243552C;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823dc188
	ctx.lr = 0x8243553C;
	sub_823DC188(ctx, base);
	// lbz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 176);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82435554
	if (ctx.cr0.eq) goto loc_82435554;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x82435554;
	sub_824B96F8(ctx, base);
loc_82435554:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x824354c8
	if (ctx.cr6.lt) goto loc_824354C8;
	// b 0x82435e00
	goto loc_82435E00;
loc_82435568:
	// addi r28,r27,416
	ctx.r28.s64 = ctx.r27.s64 + 416;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x824f6238
	ctx.lr = 0x82435574;
	sub_824F6238(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9872);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435594
	if (ctx.cr6.eq) goto loc_82435594;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x82435590;
	sub_8246D6A8(ctx, base);
	// b 0x82435598
	goto loc_82435598;
loc_82435594:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82435598:
	// addi r29,r3,51
	ctx.r29.s64 = ctx.r3.s64 + 51;
	// li r31,51
	ctx.r31.s64 = 51;
	// cmplwi cr6,r29,51
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 51, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// ble cr6,0x82435e00
	if (!ctx.cr6.gt) goto loc_82435E00;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r30,r11,-19544
	ctx.r30.s64 = ctx.r11.s64 + -19544;
loc_824355B4:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c98b0
	ctx.lr = 0x824355C0;
	sub_823C98B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8243568c
	if (ctx.cr0.eq) goto loc_8243568C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8c40
	ctx.lr = 0x824355D0;
	sub_823C8C40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8243568c
	if (ctx.cr0.lt) goto loc_8243568C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ca840
	ctx.lr = 0x824355E0;
	sub_823CA840(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x824355f0
	if (!ctx.cr6.eq) goto loc_824355F0;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82435608
	goto loc_82435608;
loc_824355F0:
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435604
	if (ctx.cr0.eq) goto loc_82435604;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82435608
	if (ctx.cr6.eq) goto loc_82435608;
loc_82435604:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82435608:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8243568c
	if (ctx.cr0.eq) goto loc_8243568C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x82435618;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823dc188
	ctx.lr = 0x82435628;
	sub_823DC188(ctx, base);
	// lbz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 176);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8243568c
	if (ctx.cr0.eq) goto loc_8243568C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823e0590
	ctx.lr = 0x8243563C;
	sub_823E0590(ctx, base);
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,420(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 420);
	// lwzx r9,r9,r30
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r30.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// b 0x82435664
	goto loc_82435664;
loc_82435654:
	// lwz r8,8(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x8243566c
	if (ctx.cr6.eq) goto loc_8243566C;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_82435664:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82435654
	if (!ctx.cr6.eq) goto loc_82435654;
loc_8243566C:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82435680
	if (!ctx.cr6.eq) goto loc_82435680;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8228def0
	ctx.lr = 0x82435680;
	sub_8228DEF0(ctx, base);
loc_82435680:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x8243568C;
	sub_824B96F8(ctx, base);
loc_8243568C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x824355b4
	if (ctx.cr6.lt) goto loc_824355B4;
	// b 0x82435e00
	goto loc_82435E00;
loc_824356A0:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9852(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9852);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824356c0
	if (ctx.cr6.eq) goto loc_824356C0;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x824356BC;
	sub_8246D6A8(ctx, base);
	// b 0x824356c4
	goto loc_824356C4;
loc_824356C0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824356C4:
	// addi r30,r3,551
	ctx.r30.s64 = ctx.r3.s64 + 551;
	// li r31,551
	ctx.r31.s64 = 551;
	// cmplwi cr6,r30,551
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 551, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// ble cr6,0x82435e00
	if (!ctx.cr6.gt) goto loc_82435E00;
loc_824356D8:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c98b0
	ctx.lr = 0x824356E4;
	sub_823C98B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435774
	if (ctx.cr0.eq) goto loc_82435774;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c96c8
	ctx.lr = 0x824356F4;
	sub_823C96C8(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x82435774
	if (!ctx.cr6.eq) goto loc_82435774;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8c40
	ctx.lr = 0x82435704;
	sub_823C8C40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82435774
	if (ctx.cr0.lt) goto loc_82435774;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ca840
	ctx.lr = 0x82435714;
	sub_823CA840(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82435724
	if (!ctx.cr6.eq) goto loc_82435724;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8243573c
	goto loc_8243573C;
loc_82435724:
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435738
	if (ctx.cr0.eq) goto loc_82435738;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8243573c
	if (ctx.cr6.eq) goto loc_8243573C;
loc_82435738:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8243573C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435774
	if (ctx.cr0.eq) goto loc_82435774;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x8243574C;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823dc188
	ctx.lr = 0x8243575C;
	sub_823DC188(ctx, base);
	// lbz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 176);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82435774
	if (ctx.cr0.eq) goto loc_82435774;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x82435774;
	sub_824B96F8(ctx, base);
loc_82435774:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x824356d8
	if (ctx.cr6.lt) goto loc_824356D8;
	// b 0x82435e00
	goto loc_82435E00;
loc_82435788:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9852(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9852);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824357a8
	if (ctx.cr6.eq) goto loc_824357A8;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x824357A4;
	sub_8246D6A8(ctx, base);
	// b 0x824357ac
	goto loc_824357AC;
loc_824357A8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824357AC:
	// addi r30,r3,551
	ctx.r30.s64 = ctx.r3.s64 + 551;
	// li r31,551
	ctx.r31.s64 = 551;
	// cmplwi cr6,r30,551
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 551, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// ble cr6,0x82435e00
	if (!ctx.cr6.gt) goto loc_82435E00;
loc_824357C0:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c98b0
	ctx.lr = 0x824357CC;
	sub_823C98B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8243585c
	if (ctx.cr0.eq) goto loc_8243585C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c96c8
	ctx.lr = 0x824357DC;
	sub_823C96C8(ctx, base);
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x8243585c
	if (!ctx.cr6.eq) goto loc_8243585C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8c40
	ctx.lr = 0x824357EC;
	sub_823C8C40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8243585c
	if (ctx.cr0.lt) goto loc_8243585C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ca840
	ctx.lr = 0x824357FC;
	sub_823CA840(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x8243580c
	if (!ctx.cr6.eq) goto loc_8243580C;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82435824
	goto loc_82435824;
loc_8243580C:
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435820
	if (ctx.cr0.eq) goto loc_82435820;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82435824
	if (ctx.cr6.eq) goto loc_82435824;
loc_82435820:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82435824:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8243585c
	if (ctx.cr0.eq) goto loc_8243585C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x82435834;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823dc188
	ctx.lr = 0x82435844;
	sub_823DC188(ctx, base);
	// lbz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 176);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8243585c
	if (ctx.cr0.eq) goto loc_8243585C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x8243585C;
	sub_824B96F8(ctx, base);
loc_8243585C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x824357c0
	if (ctx.cr6.lt) goto loc_824357C0;
	// b 0x82435e00
	goto loc_82435E00;
loc_82435870:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9852(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9852);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435890
	if (ctx.cr6.eq) goto loc_82435890;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x8243588C;
	sub_8246D6A8(ctx, base);
	// b 0x82435894
	goto loc_82435894;
loc_82435890:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82435894:
	// addi r30,r3,551
	ctx.r30.s64 = ctx.r3.s64 + 551;
	// li r31,551
	ctx.r31.s64 = 551;
	// cmplwi cr6,r30,551
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 551, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// ble cr6,0x82435e00
	if (!ctx.cr6.gt) goto loc_82435E00;
loc_824358A8:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c98b0
	ctx.lr = 0x824358B4;
	sub_823C98B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435944
	if (ctx.cr0.eq) goto loc_82435944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c96c8
	ctx.lr = 0x824358C4;
	sub_823C96C8(ctx, base);
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// bne cr6,0x82435944
	if (!ctx.cr6.eq) goto loc_82435944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8c40
	ctx.lr = 0x824358D4;
	sub_823C8C40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82435944
	if (ctx.cr0.lt) goto loc_82435944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ca840
	ctx.lr = 0x824358E4;
	sub_823CA840(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x824358f4
	if (!ctx.cr6.eq) goto loc_824358F4;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8243590c
	goto loc_8243590C;
loc_824358F4:
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435908
	if (ctx.cr0.eq) goto loc_82435908;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8243590c
	if (ctx.cr6.eq) goto loc_8243590C;
loc_82435908:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8243590C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435944
	if (ctx.cr0.eq) goto loc_82435944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x8243591C;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823dc188
	ctx.lr = 0x8243592C;
	sub_823DC188(ctx, base);
	// lbz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 176);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82435944
	if (ctx.cr0.eq) goto loc_82435944;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x82435944;
	sub_824B96F8(ctx, base);
loc_82435944:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x824358a8
	if (ctx.cr6.lt) goto loc_824358A8;
	// b 0x82435e00
	goto loc_82435E00;
loc_82435958:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9852(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9852);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435978
	if (ctx.cr6.eq) goto loc_82435978;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x82435974;
	sub_8246D6A8(ctx, base);
	// b 0x8243597c
	goto loc_8243597C;
loc_82435978:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8243597C:
	// addi r30,r3,551
	ctx.r30.s64 = ctx.r3.s64 + 551;
	// li r31,551
	ctx.r31.s64 = 551;
	// cmplwi cr6,r30,551
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 551, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// ble cr6,0x82435e00
	if (!ctx.cr6.gt) goto loc_82435E00;
loc_82435990:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c98b0
	ctx.lr = 0x8243599C;
	sub_823C98B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435a2c
	if (ctx.cr0.eq) goto loc_82435A2C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c96c8
	ctx.lr = 0x824359AC;
	sub_823C96C8(ctx, base);
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// bne cr6,0x82435a2c
	if (!ctx.cr6.eq) goto loc_82435A2C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8c40
	ctx.lr = 0x824359BC;
	sub_823C8C40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82435a2c
	if (ctx.cr0.lt) goto loc_82435A2C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ca840
	ctx.lr = 0x824359CC;
	sub_823CA840(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x824359dc
	if (!ctx.cr6.eq) goto loc_824359DC;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x824359f4
	goto loc_824359F4;
loc_824359DC:
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824359f0
	if (ctx.cr0.eq) goto loc_824359F0;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x824359f4
	if (ctx.cr6.eq) goto loc_824359F4;
loc_824359F0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_824359F4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435a2c
	if (ctx.cr0.eq) goto loc_82435A2C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x82435A04;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823dc188
	ctx.lr = 0x82435A14;
	sub_823DC188(ctx, base);
	// lbz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 176);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82435a2c
	if (ctx.cr0.eq) goto loc_82435A2C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x82435A2C;
	sub_824B96F8(ctx, base);
loc_82435A2C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x82435990
	if (ctx.cr6.lt) goto loc_82435990;
	// b 0x82435e00
	goto loc_82435E00;
loc_82435A40:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9852(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9852);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435a60
	if (ctx.cr6.eq) goto loc_82435A60;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x82435A5C;
	sub_8246D6A8(ctx, base);
	// b 0x82435a64
	goto loc_82435A64;
loc_82435A60:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82435A64:
	// addi r30,r3,551
	ctx.r30.s64 = ctx.r3.s64 + 551;
	// li r31,551
	ctx.r31.s64 = 551;
	// cmplwi cr6,r30,551
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 551, ctx.xer);
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// ble cr6,0x82435e00
	if (!ctx.cr6.gt) goto loc_82435E00;
loc_82435A78:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c98b0
	ctx.lr = 0x82435A84;
	sub_823C98B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435b14
	if (ctx.cr0.eq) goto loc_82435B14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c96c8
	ctx.lr = 0x82435A94;
	sub_823C96C8(ctx, base);
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// bne cr6,0x82435b14
	if (!ctx.cr6.eq) goto loc_82435B14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8c40
	ctx.lr = 0x82435AA4;
	sub_823C8C40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82435b14
	if (ctx.cr0.lt) goto loc_82435B14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ca840
	ctx.lr = 0x82435AB4;
	sub_823CA840(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82435ac4
	if (!ctx.cr6.eq) goto loc_82435AC4;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82435adc
	goto loc_82435ADC;
loc_82435AC4:
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435ad8
	if (ctx.cr0.eq) goto loc_82435AD8;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82435adc
	if (ctx.cr6.eq) goto loc_82435ADC;
loc_82435AD8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82435ADC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435b14
	if (ctx.cr0.eq) goto loc_82435B14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x82435AEC;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823dc188
	ctx.lr = 0x82435AFC;
	sub_823DC188(ctx, base);
	// lbz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 176);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82435b14
	if (ctx.cr0.eq) goto loc_82435B14;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x82435B14;
	sub_824B96F8(ctx, base);
loc_82435B14:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x82435a78
	if (ctx.cr6.lt) goto loc_82435A78;
	// b 0x82435e00
	goto loc_82435E00;
loc_82435B28:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// li r10,1551
	ctx.r10.s64 = 1551;
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// lwz r11,-9876(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9876);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435b50
	if (ctx.cr6.eq) goto loc_82435B50;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x82435B4C;
	sub_8246D6A8(ctx, base);
	// b 0x82435b54
	goto loc_82435B54;
loc_82435B50:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82435B54:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r10,1651
	ctx.r10.s64 = 1651;
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// lwz r11,-9836(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9836);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435b80
	if (ctx.cr6.eq) goto loc_82435B80;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x82435B7C;
	sub_8246D6A8(ctx, base);
	// b 0x82435b84
	goto loc_82435B84;
loc_82435B80:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82435B84:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// li r10,1851
	ctx.r10.s64 = 1851;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lwz r11,-9860(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9860);
	// lwz r10,-9868(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -9868);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435bc8
	if (ctx.cr6.eq) goto loc_82435BC8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82435bc8
	if (ctx.cr6.eq) goto loc_82435BC8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435bc8
	if (ctx.cr6.eq) goto loc_82435BC8;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82435bcc
	goto loc_82435BCC;
loc_82435BC8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82435BCC:
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// li r11,1861
	ctx.r11.s64 = 1861;
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// lwz r11,-9848(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -9848);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435bfc
	if (ctx.cr6.eq) goto loc_82435BFC;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x82435BF4;
	sub_8246D6A8(ctx, base);
	// lwz r10,-9868(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -9868);
	// b 0x82435c00
	goto loc_82435C00;
loc_82435BFC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82435C00:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// li r9,2061
	ctx.r9.s64 = 2061;
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// lwz r11,-9856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9856);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435c30
	if (ctx.cr6.eq) goto loc_82435C30;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8246d6a8
	ctx.lr = 0x82435C28;
	sub_8246D6A8(ctx, base);
	// lwz r10,-9868(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -9868);
	// b 0x82435c34
	goto loc_82435C34;
loc_82435C30:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82435C34:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r3.u32);
	// li r9,2161
	ctx.r9.s64 = 2161;
	// stw r9,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r9.u32);
	// lwz r11,-9828(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9828);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435c70
	if (ctx.cr6.eq) goto loc_82435C70;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82435c70
	if (ctx.cr6.eq) goto loc_82435C70;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435c70
	if (ctx.cr6.eq) goto loc_82435C70;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82435c74
	goto loc_82435C74;
loc_82435C70:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82435C74:
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// stw r11,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r11.u32);
	// li r11,2211
	ctx.r11.s64 = 2211;
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// lwz r11,-9864(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -9864);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435cb0
	if (ctx.cr6.eq) goto loc_82435CB0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82435cb0
	if (ctx.cr6.eq) goto loc_82435CB0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435cb0
	if (ctx.cr6.eq) goto loc_82435CB0;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82435cb4
	goto loc_82435CB4;
loc_82435CB0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82435CB4:
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// li r11,2221
	ctx.r11.s64 = 2221;
	// stw r11,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r11.u32);
	// lwz r11,-9844(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -9844);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435cf0
	if (ctx.cr6.eq) goto loc_82435CF0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82435cf0
	if (ctx.cr6.eq) goto loc_82435CF0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435cf0
	if (ctx.cr6.eq) goto loc_82435CF0;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82435cf4
	goto loc_82435CF4;
loc_82435CF0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82435CF4:
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// stw r11,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r11.u32);
	// li r11,8321
	ctx.r11.s64 = 8321;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// lwz r11,-9840(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -9840);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435d30
	if (ctx.cr6.eq) goto loc_82435D30;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82435d30
	if (ctx.cr6.eq) goto loc_82435D30;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435d30
	if (ctx.cr6.eq) goto loc_82435D30;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82435d34
	goto loc_82435D34;
loc_82435D30:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82435D34:
	// stw r11,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r11.u32);
	// addi r30,r1,100
	ctx.r30.s64 = ctx.r1.s64 + 100;
	// li r28,9
	ctx.r28.s64 = 9;
loc_82435D40:
	// lwz r11,-4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -4);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// b 0x82435dec
	goto loc_82435DEC;
loc_82435D58:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c98b0
	ctx.lr = 0x82435D64;
	sub_823C98B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435de4
	if (ctx.cr0.eq) goto loc_82435DE4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8c40
	ctx.lr = 0x82435D74;
	sub_823C8C40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82435de4
	if (ctx.cr0.lt) goto loc_82435DE4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ca840
	ctx.lr = 0x82435D84;
	sub_823CA840(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82435d94
	if (!ctx.cr6.eq) goto loc_82435D94;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82435dac
	goto loc_82435DAC;
loc_82435D94:
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435da8
	if (ctx.cr0.eq) goto loc_82435DA8;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82435dac
	if (ctx.cr6.eq) goto loc_82435DAC;
loc_82435DA8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82435DAC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435de4
	if (ctx.cr0.eq) goto loc_82435DE4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c8d50
	ctx.lr = 0x82435DBC;
	sub_823C8D50(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823dc188
	ctx.lr = 0x82435DCC;
	sub_823DC188(ctx, base);
	// lbz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 176);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82435de4
	if (ctx.cr0.eq) goto loc_82435DE4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x824b96f8
	ctx.lr = 0x82435DE4;
	sub_824B96F8(ctx, base);
loc_82435DE4:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
loc_82435DEC:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// blt cr6,0x82435d58
	if (ctx.cr6.lt) goto loc_82435D58;
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// bne 0x82435d40
	if (!ctx.cr0.eq) goto loc_82435D40;
loc_82435E00:
	// lwz r10,4(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// addi r31,r27,500
	ctx.r31.s64 = ctx.r27.s64 + 500;
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,440(r27)
	REX_STORE_U8(ctx.r27.u32 + 440, ctx.r11.u8);
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lwz r10,4(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// stw r11,392(r27)
	REX_STORE_U32(ctx.r27.u32 + 392, ctx.r11.u32);
	// lwz r11,508(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 508);
	// lwz r9,504(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 504);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82435e6c
	if (ctx.cr6.eq) goto loc_82435E6C;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82435e68
	if (ctx.cr6.eq) goto loc_82435E68;
loc_82435E50:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne cr6,0x82435e50
	if (!ctx.cr6.eq) goto loc_82435E50;
loc_82435E68:
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
loc_82435E6C:
	// lbz r11,440(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 440);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82435f48
	if (ctx.cr0.eq) goto loc_82435F48;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ec158
	ctx.lr = 0x82435E8C;
	sub_823EC158(ctx, base);
	// lwz r11,356(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 356);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82435eb0
	if (!ctx.cr6.gt) goto loc_82435EB0;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// ble cr6,0x82435eac
	if (!ctx.cr6.gt) goto loc_82435EAC;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82435eb0
	if (!ctx.cr6.eq) goto loc_82435EB0;
loc_82435EAC:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82435EB0:
	// clrlwi. r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435ecc
	if (ctx.cr0.eq) goto loc_82435ECC;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ec158
	ctx.lr = 0x82435ECC;
	sub_823EC158(ctx, base);
loc_82435ECC:
	// li r11,2
	ctx.r11.s64 = 2;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ec158
	ctx.lr = 0x82435EE0;
	sub_823EC158(ctx, base);
	// lwz r10,356(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 356);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x82435ef4
	if (!ctx.cr6.eq) goto loc_82435EF4;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82435EF4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82435f48
	if (ctx.cr0.eq) goto loc_82435F48;
	// li r30,3
	ctx.r30.s64 = 3;
loc_82435F00:
	// lwz r10,420(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 420);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82435f1c
	goto loc_82435F1C;
loc_82435F0C:
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmpw cr6,r9,r30
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r30.s32, ctx.xer);
	// beq cr6,0x82435f24
	if (ctx.cr6.eq) goto loc_82435F24;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82435F1C:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82435f0c
	if (!ctx.cr6.eq) goto loc_82435F0C;
loc_82435F24:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82435f3c
	if (ctx.cr6.eq) goto loc_82435F3C;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ec158
	ctx.lr = 0x82435F3C;
	sub_823EC158(ctx, base);
loc_82435F3C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,20
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 20, ctx.xer);
	// ble cr6,0x82435f00
	if (!ctx.cr6.gt) goto loc_82435F00;
loc_82435F48:
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lbz r8,440(r27)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r27.u32 + 440);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// subfc r9,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r11,492(r27)
	REX_STORE_U32(ctx.r27.u32 + 492, ctx.r11.u32);
	// eqv r11,r11,r10
	ctx.r11.u64 = ~(ctx.r11.u64 ^ ctx.r10.u64);
	// rlwinm r11,r11,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// stb r11,449(r27)
	REX_STORE_U8(ctx.r27.u32 + 449, ctx.r11.u8);
	// beq 0x82435f94
	if (ctx.cr0.eq) goto loc_82435F94;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8243c050
	ctx.lr = 0x82435F90;
	sub_8243C050(ctx, base);
	// b 0x82435fc8
	goto loc_82435FC8;
loc_82435F94:
	// lis r5,15
	ctx.r5.s64 = 983040;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x823dc188
	ctx.lr = 0x82435FA4;
	sub_823DC188(ctx, base);
	// lwz r11,308(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 308);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,432
	ctx.r4.s64 = ctx.r1.s64 + 432;
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
	ctx.lr = 0x82435FC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82435FC8:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r4,396(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 396);
	// bl 0x82434fe8
	ctx.lr = 0x82435FD4;
	sub_82434FE8(ctx, base);
	// lwz r10,436(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 436);
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r11,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// lbz r11,448(r27)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + 448);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82435ff8
	if (ctx.cr0.eq) goto loc_82435FF8;
	// lwz r11,492(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 492);
	// lwz r10,456(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 456);
	// b 0x82436000
	goto loc_82436000;
loc_82435FF8:
	// lwz r11,392(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 392);
	// lwz r10,396(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 396);
loc_82436000:
	// lwz r9,436(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 436);
	// stw r11,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r11.u32);
	// lwz r11,436(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 436);
	// stw r10,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8248D238) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x8248D240;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r30,r11,12484
	ctx.r30.s64 = ctx.r11.s64 + 12484;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// lfs f31,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// bne cr6,0x8248d278
	if (!ctx.cr6.eq) goto loc_8248D278;
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
loc_8248D278:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r10,r10,-30000
	ctx.r10.s64 = ctx.r10.s64 + -30000;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f13,-11116(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11116);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r7,-32113
	ctx.r7.s64 = -2104557568;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r7,22392
	ctx.r7.s64 = ctx.r7.s64 + 22392;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,384
	ctx.r4.s64 = 384;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,44(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 44);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x825fc4b0
	ctx.lr = 0x8248D2E8;
	sub_825FC4B0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8248d354
	if (ctx.cr0.eq) goto loc_8248D354;
	// addic r11,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r4,r10,5796
	ctx.r4.s64 = ctx.r10.s64 + 5796;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// and r29,r11,r9
	ctx.r29.u64 = ctx.r11.u64 & ctx.r9.u64;
	// bl 0x82481d60
	ctx.lr = 0x8248D318;
	sub_82481D60(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-15136
	ctx.r11.s64 = ctx.r11.s64 + -15136;
	// stfs f0,368(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// stfs f0,372(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 372, temp.u32);
	// stw r10,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r10.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r29,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r29.u32);
	// stw r29,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r29.u32);
	// stw r11,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r11.u32);
	// stfs f31,380(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// stb r27,159(r31)
	REX_STORE_U8(ctx.r31.u32 + 159, ctx.r27.u8);
	// b 0x8248d358
	goto loc_8248D358;
loc_8248D354:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8248D358:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8248d368
	if (!ctx.cr6.eq) goto loc_8248D368;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8248d394
	goto loc_8248D394;
loc_8248D368:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824d3cb8
	ctx.lr = 0x8248D378;
	sub_824D3CB8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// stb r25,158(r31)
	REX_STORE_U8(ctx.r31.u32 + 158, ctx.r25.u8);
loc_8248D394:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8249A680) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,14392(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14392);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,428(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 428, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8249BD68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x8249BD70;
	__savegprlr_25(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,216(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 216);
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
	ctx.lr = 0x8249BD94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,437(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 437);
	// li r29,-1
	ctx.r29.s64 = -1;
	// stw r29,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r29.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8249bfa4
	if (ctx.cr0.eq) goto loc_8249BFA4;
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
	// lfs f0,-14512(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -14512);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8249bfa4
	if (ctx.cr6.lt) goto loc_8249BFA4;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f12,404(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 404);
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
	// lfs f0,15104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15104);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lis r5,-32110
	ctx.r5.s64 = -2104360960;
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lis r25,-32226
	ctx.r25.s64 = -2111963136;
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lwz r30,-9960(r5)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r5.u32 + -9960);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r5,r25,4288
	ctx.r5.s64 = ctx.r25.s64 + 4288;
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// li r25,1
	ctx.r25.s64 = 1;
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v59,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// vaddfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v62,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// beq cr6,0x8249bf58
	if (ctx.cr6.eq) goto loc_8249BF58;
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
	// bl 0x823c3150
	ctx.lr = 0x8249BF54;
	sub_823C3150(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_8249BF58:
	// lfs f0,272(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 272);
	ctx.f0.f64 = double(temp.f32);
	// lbz r10,159(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 159);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lfs f1,276(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 276);
	ctx.f1.f64 = double(temp.f32);
	// lwz r7,164(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// lwz r4,176(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r8,132(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// beq cr6,0x8249bfa0
	if (ctx.cr6.eq) goto loc_8249BFA0;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r31,68
	ctx.r10.s64 = ctx.r31.s64 + 68;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823c4c40
	ctx.lr = 0x8249BF9C;
	sub_823C4C40(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_8249BFA0:
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
loc_8249BFA4:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824BB538) {
	REX_FUNC_PROLOGUE();
	// lbz r11,492(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 492);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr
	if (!ctx.cr0.eq) return;
	// b 0x824827f0
	sub_824827F0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824BBAE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x824BBAF0;
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r28,r11,-30232
	ctx.r28.s64 = ctx.r11.s64 + -30232;
	// addi r27,r10,-2512
	ctx.r27.s64 = ctx.r10.s64 + -2512;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,1360(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1360);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,2660(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 2660);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825c0958
	ctx.lr = 0x824BBB1C;
	sub_825C0958(ctx, base);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// stfs f1,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r9,r11,22392
	ctx.r9.s64 = ctx.r11.s64 + 22392;
	// addi r29,r10,17680
	ctx.r29.s64 = ctx.r10.s64 + 17680;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-13108
	ctx.r10.s64 = -859045888;
	// addi r30,r11,12484
	ctx.r30.s64 = ctx.r11.s64 + 12484;
	// lwz r3,48(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 48);
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f13,-15872(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -15872);
	ctx.f13.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,12484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r10,52479
	ctx.r11.u64 = ctx.r10.u64 | 52479;
	// fmuls f12,f1,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r4,144
	ctx.r4.s64 = 144;
	// lfs f13,1908(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r9,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// bl 0x825fc4b0
	ctx.lr = 0x824BBB8C;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824bbbb8
	if (ctx.cr0.eq) goto loc_824BBBB8;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f0,-2696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-23072(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -23072);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x8222dd18
	ctx.lr = 0x824BBBB0;
	sub_8222DD18(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x824bbbbc
	goto loc_824BBBBC;
loc_824BBBB8:
	// li r31,0
	ctx.r31.s64 = 0;
loc_824BBBBC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824bbc88
	if (ctx.cr6.eq) goto loc_824BBC88;
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
	ctx.lr = 0x824BBBDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f13,1908(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,-2700(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2700);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f2,f0,f13
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmuls f1,f0,f12
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// bl 0x825c0958
	ctx.lr = 0x824BBBFC;
	sub_825C0958(ctx, base);
	// lfs f0,-19084(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -19084);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// lfs f2,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825c0958
	ctx.lr = 0x824BBC14;
	sub_825C0958(ctx, base);
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822d2870
	ctx.lr = 0x824BBC20;
	sub_822D2870(ctx, base);
	// lfs f0,236(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f1,f9
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fadds f1,f30,f0
	ctx.f1.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// bl 0x822d2870
	ctx.lr = 0x824BBC34;
	sub_822D2870(ctx, base);
	// fmuls f0,f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824BBC58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824BBC70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824BBC88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824BBC88:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824C76B0) {
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,408(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 408);
	ctx.f0.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// lfs f12,12484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x824c7700
	if (!ctx.cr6.gt) goto loc_824C7700;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// lfs f13,1176(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1176);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f1,f13,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f1.f64, ctx.f13.f64, -ctx.f0.f64)));
	// stfs f0,408(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 408, temp.u32);
loc_824C7700:
	// lfs f0,408(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 408);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x824c7710
	if (!ctx.cr6.lt) goto loc_824C7710;
	// stfs f12,408(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 408, temp.u32);
loc_824C7710:
	// lfs f0,420(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 420);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r31,356
	ctx.r30.s64 = ctx.r31.s64 + 356;
	// lfs f13,412(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r31,364
	ctx.r4.s64 = ctx.r31.s64 + 364;
	// fmadds f11,f13,f29,f0
	ctx.f11.f64 = double(float(std::fma(ctx.f13.f64, ctx.f29.f64, ctx.f0.f64)));
	// stfs f11,420(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 420, temp.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lfs f10,408(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 408);
	ctx.f10.f64 = double(temp.f32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
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
	// bl 0x82340028
	ctx.lr = 0x824C7748;
	sub_82340028(ctx, base);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r4,r31,372
	ctx.r4.s64 = ctx.r31.s64 + 372;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f30,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f30.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f31.f64 = double(temp.f32);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f30,84(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x82340028
	ctx.lr = 0x824C77D8;
	sub_82340028(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stfs f10,156(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f10,152(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r4,r31,380
	ctx.r4.s64 = ctx.r31.s64 + 380;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f10,148(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f10,144(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// bl 0x82340028
	ctx.lr = 0x824C7868;
	sub_82340028(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stfs f13,144(r1)
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v1,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8222ada8
	ctx.lr = 0x824C78FC;
	sub_8222ADA8(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8236e4f8
	ctx.lr = 0x824C790C;
	sub_8236E4F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824d3cb8
	ctx.lr = 0x824C791C;
	sub_824D3CB8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// bl 0x8236e4f8
	ctx.lr = 0x824C7940;
	sub_8236E4F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824d3cb8
	ctx.lr = 0x824C7950;
	sub_824D3CB8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,372(r31)
	REX_STORE_U32(ctx.r31.u32 + 372, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r11.u32);
	// bl 0x8236e4f8
	ctx.lr = 0x824C7974;
	sub_8236E4F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824d3cb8
	ctx.lr = 0x824C7984;
	sub_824D3CB8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,492(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 492);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fadds f13,f0,f29
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// lfs f0,-30976(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30976);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r10.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f13,492(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 492, temp.u32);
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// bgt cr6,0x824c7a64
	if (ctx.cr6.gt) goto loc_824C7A64;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f31,144(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stfs f31,148(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f30,140(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r9,-30528
	ctx.r9.s64 = ctx.r9.s64 + -30528;
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f30,136(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lis r8,-32228
	ctx.r8.s64 = -2112094208;
	// stfs f30,132(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f30,128(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v0,v0,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lvx128 v6,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1804(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 1804);
	ctx.f0.f64 = double(temp.f32);
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
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x824c7a5c
	if (ctx.cr6.lt) goto loc_824C7A5C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_824C7A5C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824c7a6c
	if (ctx.cr0.eq) goto loc_824C7A6C;
loc_824C7A64:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_824C7A6C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
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

DEFINE_REX_FUNC(sub_824F0DD0) {
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
	// bl 0x82371af8
	ctx.lr = 0x824F0DF0;
	sub_82371AF8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r4,r11,-12464
	ctx.r4.s64 = ctx.r11.s64 + -12464;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82484c30
	ctx.lr = 0x824F0E04;
	sub_82484C30(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x824f0e18
	if (!ctx.cr6.lt) goto loc_824F0E18;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_824F0E18:
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9788(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824f0e68
	if (ctx.cr6.eq) goto loc_824F0E68;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82486f58
	ctx.lr = 0x824F0E30;
	sub_82486F58(ctx, base);
	// lwz r11,-9788(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824f0e68
	if (ctx.cr6.eq) goto loc_824F0E68;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-13556
	ctx.r3.s64 = ctx.r11.s64 + -13556;
	// bl 0x82486f58
	ctx.lr = 0x824F0E4C;
	sub_82486F58(ctx, base);
	// lwz r11,-9788(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824f0e68
	if (ctx.cr6.eq) goto loc_824F0E68;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-12496
	ctx.r3.s64 = ctx.r11.s64 + -12496;
	// bl 0x82486f58
	ctx.lr = 0x824F0E68;
	sub_82486F58(ctx, base);
loc_824F0E68:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x824F0E78;
	sub_82371AF8(ctx, base);
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

DEFINE_REX_FUNC(sub_824F4F10) {
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
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824f4fb4
	if (!ctx.cr0.eq) goto loc_824F4FB4;
	// lbz r11,21(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 21);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824f4fb4
	if (ctx.cr0.eq) goto loc_824F4FB4;
	// lbz r11,377(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 377);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824f4fb4
	if (!ctx.cr0.eq) goto loc_824F4FB4;
	// lbz r11,388(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 388);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824f4f64
	if (ctx.cr0.eq) goto loc_824F4F64;
	// lwz r11,404(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 404);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x824f4fb4
	if (ctx.cr6.eq) goto loc_824F4FB4;
loc_824F4F64:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r30,1
	ctx.r30.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r7,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r7.u32);
	// lfs f0,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stb r30,377(r31)
	REX_STORE_U8(ctx.r31.u32 + 377, ctx.r30.u8);
	// stfs f0,372(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 372, temp.u32);
	// ld r11,6272(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 6272);
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r10,192(r31)
	REX_STORE_U8(ctx.r31.u32 + 192, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r10,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r10.u8);
	// lwz r11,68(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 68);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824F4FB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r30,417(r31)
	REX_STORE_U8(ctx.r31.u32 + 417, ctx.r30.u8);
loc_824F4FB4:
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

DEFINE_REX_FUNC(sub_824F9AE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x824F9AE8;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x824f9b08
	if (!ctx.cr6.eq) goto loc_824F9B08;
	// lwz r11,4(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// b 0x824f9b0c
	goto loc_824F9B0C;
loc_824F9B08:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
loc_824F9B0C:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824f9b2c
	if (ctx.cr0.eq) goto loc_824F9B2C;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824F9B2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824F9B2C:
	// clrlwi. r11,r31,31
	ctx.r11.u64 = ctx.r31.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824f9d54
	if (ctx.cr0.eq) goto loc_824F9D54;
	// addi r5,r28,388
	ctx.r5.s64 = ctx.r28.s64 + 388;
	// addi r4,r28,360
	ctx.r4.s64 = ctx.r28.s64 + 360;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8224e4e8
	ctx.lr = 0x824F9B44;
	sub_8224E4E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r27,1
	ctx.r27.s64 = 1;
	// beq 0x824f9d4c
	if (ctx.cr0.eq) goto loc_824F9D4C;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// clrlwi. r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x824f9d4c
	if (ctx.cr0.eq) goto loc_824F9D4C;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r8,r11,16
	ctx.r8.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r10,-9744(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -9744);
	// lwz r7,172(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r9,r7
	ctx.r10.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwzx r9,r9,r7
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824f9b98
	if (!ctx.cr6.eq) goto loc_824F9B98;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// bne cr6,0x824f9b9c
	if (!ctx.cr6.eq) goto loc_824F9B9C;
loc_824F9B98:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824F9B9C:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x824f9d4c
	if (ctx.cr0.eq) goto loc_824F9D4C;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824f9d4c
	if (!ctx.cr6.eq) goto loc_824F9D4C;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824f9d4c
	if (ctx.cr6.eq) goto loc_824F9D4C;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r9,r10,29,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x824f9c44
	if (!ctx.cr0.eq) goto loc_824F9C44;
	// rlwinm. r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x824f9c44
	if (!ctx.cr0.eq) goto loc_824F9C44;
	// rlwinm. r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x824f9d4c
	if (ctx.cr0.eq) goto loc_824F9D4C;
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824f9d4c
	if (!ctx.cr6.eq) goto loc_824F9D4C;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824f9d4c
	if (ctx.cr6.eq) goto loc_824F9D4C;
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824f9c34
	if (ctx.cr6.eq) goto loc_824F9C34;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 960);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824F9C20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,10
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 10, ctx.xer);
	// beq cr6,0x824f9c54
	if (ctx.cr6.eq) goto loc_824F9C54;
	// cmpwi cr6,r3,22
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 22, ctx.xer);
	// beq cr6,0x824f9c54
	if (ctx.cr6.eq) goto loc_824F9C54;
loc_824F9C34:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824f9d4c
	if (!ctx.cr0.eq) goto loc_824F9D4C;
loc_824F9C44:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x824f97a8
	ctx.lr = 0x824F9C50;
	sub_824F97A8(ctx, base);
	// b 0x824f9d54
	goto loc_824F9D54;
loc_824F9C54:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,32
	ctx.r4.s64 = ctx.r11.s64 + 32;
	// bl 0x82454930
	ctx.lr = 0x824F9C64;
	sub_82454930(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,-28720
	ctx.r10.s64 = ctx.r10.s64 + -28720;
	// stb r27,430(r28)
	REX_STORE_U8(ctx.r28.u32 + 430, ctx.r27.u8);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r10,424(r28)
	REX_STORE_U32(ctx.r28.u32 + 424, ctx.r10.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r31,r28,68
	ctx.r31.s64 = ctx.r28.s64 + 68;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,68(r28)
	REX_STORE_U64(ctx.r28.u32 + 68, ctx.r11.u64);
	// bl 0x824f97a8
	ctx.lr = 0x824F9CFC;
	sub_824F97A8(ctx, base);
	// cmpwi cr6,r30,10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 10, ctx.xer);
	// bne cr6,0x824f9d54
	if (!ctx.cr6.eq) goto loc_824F9D54;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-29744
	ctx.r11.s64 = ctx.r11.s64 + -29744;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r9,r9,-30000
	ctx.r9.s64 = ctx.r9.s64 + -30000;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x82367e00
	ctx.lr = 0x824F9D48;
	sub_82367E00(ctx, base);
	// b 0x824f9d54
	goto loc_824F9D54;
loc_824F9D4C:
	// stb r27,12(r29)
	REX_STORE_U8(ctx.r29.u32 + 12, ctx.r27.u8);
	// stb r27,13(r29)
	REX_STORE_U8(ctx.r29.u32 + 13, ctx.r27.u8);
loc_824F9D54:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82509F30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x82509F38;
	__savegprlr_28(ctx, base);
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
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r4,r10,-23504
	ctx.r4.s64 = ctx.r10.s64 + -23504;
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,8
	ctx.r7.s64 = 8;
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82534a18
	ctx.lr = 0x82509F70;
	sub_82534A18(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// addi r8,r11,-8352
	ctx.r8.s64 = ctx.r11.s64 + -8352;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// addic r10,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r10.s64 = ctx.r29.s64 + -1;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// stw r11,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r11.u32);
	// lfs f0,12484(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r11.u32);
	// subfe r10,r10,r29
	temp.u8 = (~ctx.r10.u32 + ctx.r29.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stfs f0,368(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// stb r8,159(r31)
	REX_STORE_U8(ctx.r31.u32 + 159, ctx.r8.u8);
	// stb r10,372(r31)
	REX_STORE_U8(ctx.r31.u32 + 372, ctx.r10.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,-1
	ctx.r5.s64 = -1;
	// stb r28,158(r31)
	REX_STORE_U8(ctx.r31.u32 + 158, ctx.r28.u8);
	// stw r11,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// clrlwi. r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stb r6,397(r31)
	REX_STORE_U8(ctx.r31.u32 + 397, ctx.r6.u8);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r11,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r11.u32);
	// addi r3,r31,380
	ctx.r3.s64 = ctx.r31.s64 + 380;
	// stw r5,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r5.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// lfs f0,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// beq 0x8250a018
	if (ctx.cr0.eq) goto loc_8250A018;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r11,r11,-30208
	ctx.r11.s64 = ctx.r11.s64 + -30208;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// b 0x8250a040
	goto loc_8250A040;
loc_8250A018:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r10,-30208
	ctx.r10.s64 = ctx.r10.s64 + -30208;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
loc_8250A040:
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// bl 0x82523e48
	ctx.lr = 0x8250A050;
	sub_82523E48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82513BA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x82513BB0;
	__savegprlr_27(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,724(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 724);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r28,560(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 560);
	// bne cr6,0x82513bd4
	if (!ctx.cr6.eq) goto loc_82513BD4;
loc_82513BC8:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x82513e30
	goto loc_82513E30;
loc_82513BD4:
	// bl 0x825b7bf8
	ctx.lr = 0x82513BD8;
	sub_825B7BF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82513bc8
	if (ctx.cr0.eq) goto loc_82513BC8;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82513bc8
	if (ctx.cr6.eq) goto loc_82513BC8;
	// lwz r10,424(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 424);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82513bc8
	if (ctx.cr6.eq) goto loc_82513BC8;
	// lhz r9,10(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 10);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// ld r5,44(r31)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// li r7,24
	ctx.r7.s64 = 24;
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// lwz r8,456(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// addi r11,r11,14392
	ctx.r11.s64 = ctx.r11.s64 + 14392;
	// lwz r6,452(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// subf r8,r6,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r6.u64;
	// lfs f8,-2140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2140);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,-1908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1908);
	ctx.f9.f64 = double(temp.f32);
	// std r5,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r5.u64);
	// divw r29,r8,r7
	ctx.r29.u64 = uint32_t((ctx.r7.s32 && !(ctx.r8.s32 == INT32_MIN && ctx.r7.s32 == -1)) ? ctx.r8.s32 / ctx.r7.s32 : 0);
	// lfs f5,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// stfs f9,136(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// std r5,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfs f6,17512(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17512);
	ctx.f6.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stfs f8,140(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r7,r10,32
	ctx.r7.s64 = ctx.r10.s64 + 32;
	// stfs f9,152(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f8,156(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// fdivs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 / ctx.f0.f64));
loc_82513C68:
	// lfs f13,552(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 552);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f0,424(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 424);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f10,428(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 428);
	ctx.f10.f64 = double(temp.f32);
	// bl 0x82515030
	ctx.lr = 0x82513C88;
	sub_82515030(ctx, base);
	// fcmpu cr6,f10,f6
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f6.f64);
	// bne cr6,0x82513c98
	if (!ctx.cr6.eq) goto loc_82513C98;
	// fmr f0,f5
	ctx.f0.f64 = ctx.f5.f64;
	// b 0x82513cb0
	goto loc_82513CB0;
loc_82513C98:
	// fsubs f0,f10,f6
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f10.f64 - ctx.f6.f64));
	// fcmpu cr6,f0,f9
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// ble cr6,0x82513cac
	if (!ctx.cr6.gt) goto loc_82513CAC;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x82513cb0
	goto loc_82513CB0;
loc_82513CAC:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f9.f64;
loc_82513CB0:
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f13,f7,f13
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stfs f10,132(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r7,40
	ctx.r9.s64 = ctx.r7.s64 + 40;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r6,8(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r6,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// stw r3,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r4,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r4.u32);
	// lwz r11,556(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 556);
	// ld r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r6,0(r7)
	REX_STORE_U64(ctx.r7.u32 + 0, ctx.r6.u64);
	// addi r7,r9,80
	ctx.r7.s64 = ctx.r9.s64 + 80;
	// stw r11,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r11.u32);
	// addi r10,r10,120
	ctx.r10.s64 = ctx.r10.s64 + 120;
loc_82513D10:
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmplw cr6,r8,r29
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x82513d2c
	if (ctx.cr6.lt) goto loc_82513D2C;
	// divwu r11,r8,r29
	ctx.r11.u64 = uint32_t(ctx.r29.u32 ? ctx.r8.u32 / ctx.r29.u32 : 0);
	// twllei r29,0
	if (ctx.r29.s32 == 0 || ctx.r29.u32 < 0u) ppc_trap(ctx, base, 0);
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// subf r11,r11,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r11.u64;
loc_82513D2C:
	// lwz r6,452(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 452);
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// lfs f0,552(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 552);
	ctx.f0.f64 = double(temp.f32);
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f10,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// bl 0x82515030
	ctx.lr = 0x82513D58;
	sub_82515030(ctx, base);
	// fcmpu cr6,f10,f9
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f9.f64);
	// bne cr6,0x82513d68
	if (!ctx.cr6.eq) goto loc_82513D68;
	// fmr f0,f5
	ctx.f0.f64 = ctx.f5.f64;
	// b 0x82513d7c
	goto loc_82513D7C;
loc_82513D68:
	// fcmpu cr6,f10,f9
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f10.f64, ctx.f9.f64);
	// ble cr6,0x82513d78
	if (!ctx.cr6.gt) goto loc_82513D78;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x82513d7c
	goto loc_82513D7C;
loc_82513D78:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f9.f64;
loc_82513D7C:
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r6,r9,-32
	ctx.r6.s64 = ctx.r9.s64 + -32;
	// stfs f10,148(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fmuls f13,f7,f13
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r27,0(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r6,8(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,-28(r9)
	REX_STORE_U32(ctx.r9.u32 + -28, ctx.r11.u32);
	// stw r27,-32(r9)
	REX_STORE_U32(ctx.r9.u32 + -32, ctx.r27.u32);
	// stw r6,-24(r9)
	REX_STORE_U32(ctx.r9.u32 + -24, ctx.r6.u32);
	// stw r4,-20(r9)
	REX_STORE_U32(ctx.r9.u32 + -20, ctx.r4.u32);
	// ld r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r11,556(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 556);
	// std r3,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.r3.u64);
	// stw r11,-4(r9)
	REX_STORE_U32(ctx.r9.u32 + -4, ctx.r11.u32);
	// addi r9,r9,40
	ctx.r9.s64 = ctx.r9.s64 + 40;
	// bne 0x82513d10
	if (!ctx.cr0.eq) goto loc_82513D10;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,96
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 96, ctx.xer);
	// blt cr6,0x82513c68
	if (ctx.cr6.lt) goto loc_82513C68;
	// lfs f13,104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r5,108(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82515898
	ctx.lr = 0x82513E10;
	sub_82515898(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827567d0
	ctx.lr = 0x82513E20;
	sub_827567D0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82472dc8
	ctx.lr = 0x82513E30;
	sub_82472DC8(ctx, base);
loc_82513E30:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825259A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756698
	ctx.lr = 0x825259B0;
	__savegprlr_20(ctx, base);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f1,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f2,116(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r11,r11,14392
	ctx.r11.s64 = ctx.r11.s64 + 14392;
	// stfs f2,132(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r5,40
	ctx.r3.s64 = ctx.r5.s64 + 40;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f13,-1908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1908);
	ctx.f13.f64 = double(temp.f32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f0,-2140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2140);
	ctx.f0.f64 = double(temp.f32);
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
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r29,8(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r28,12(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r3,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r3.u32);
	// lwz r24,4(r8)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r23,8(r8)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// stw r10,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r27,0(r9)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r26,4(r9)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r25,8(r9)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// stw r9,52(r5)
	REX_STORE_U32(ctx.r5.u32 + 52, ctx.r9.u32);
	// lwz r22,0(r4)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r21,4(r4)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r20,8(r4)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r4,12(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// stw r8,92(r5)
	REX_STORE_U32(ctx.r5.u32 + 92, ctx.r8.u32);
	// stw r29,8(r5)
	REX_STORE_U32(ctx.r5.u32 + 8, ctx.r29.u32);
	// stw r28,12(r5)
	REX_STORE_U32(ctx.r5.u32 + 12, ctx.r28.u32);
	// stw r27,40(r5)
	REX_STORE_U32(ctx.r5.u32 + 40, ctx.r27.u32);
	// stw r26,44(r5)
	REX_STORE_U32(ctx.r5.u32 + 44, ctx.r26.u32);
	// stw r25,48(r5)
	REX_STORE_U32(ctx.r5.u32 + 48, ctx.r25.u32);
	// stw r10,80(r5)
	REX_STORE_U32(ctx.r5.u32 + 80, ctx.r10.u32);
	// stw r24,84(r5)
	REX_STORE_U32(ctx.r5.u32 + 84, ctx.r24.u32);
	// stw r23,88(r5)
	REX_STORE_U32(ctx.r5.u32 + 88, ctx.r23.u32);
	// stw r22,120(r5)
	REX_STORE_U32(ctx.r5.u32 + 120, ctx.r22.u32);
	// stw r21,124(r5)
	REX_STORE_U32(ctx.r5.u32 + 124, ctx.r21.u32);
	// stw r20,128(r5)
	REX_STORE_U32(ctx.r5.u32 + 128, ctx.r20.u32);
	// stw r4,132(r5)
	REX_STORE_U32(ctx.r5.u32 + 132, ctx.r4.u32);
	// lwz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// ld r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// stw r10,28(r5)
	REX_STORE_U32(ctx.r5.u32 + 28, ctx.r10.u32);
	// lwz r10,4(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// stw r10,68(r5)
	REX_STORE_U32(ctx.r5.u32 + 68, ctx.r10.u32);
	// lwz r10,8(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// stw r10,108(r5)
	REX_STORE_U32(ctx.r5.u32 + 108, ctx.r10.u32);
	// lwz r10,12(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// ld r8,152(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// ld r6,160(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// stw r10,148(r5)
	REX_STORE_U32(ctx.r5.u32 + 148, ctx.r10.u32);
	// std r9,32(r5)
	REX_STORE_U64(ctx.r5.u32 + 32, ctx.r9.u64);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// std r8,72(r5)
	REX_STORE_U64(ctx.r5.u32 + 72, ctx.r8.u64);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// std r6,112(r5)
	REX_STORE_U64(ctx.r5.u32 + 112, ctx.r6.u64);
	// lis r6,-32110
	ctx.r6.s64 = -2104360960;
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// std r10,152(r5)
	REX_STORE_U64(ctx.r5.u32 + 152, ctx.r10.u64);
	// lfs f11,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vpermwi128 v60,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r28,r1,240
	ctx.r28.s64 = ctx.r1.s64 + 240;
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// addi r29,r1,128
	ctx.r29.s64 = ctx.r1.s64 + 128;
	// lwz r10,-9800(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + -9800);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v57,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v58,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82525b98
	if (ctx.cr6.eq) goto loc_82525B98;
	// lfs f12,664(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 664);
	ctx.f12.f64 = double(temp.f32);
	// b 0x82525b9c
	goto loc_82525B9C;
loc_82525B98:
	// fmr f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f0.f64;
loc_82525B9C:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// fdivs f11,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f0.f64 / ctx.f12.f64));
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vspltw128 v57,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v56,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r11,-12360(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -12360);
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// lwz r10,-12372(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + -12372);
	// vspltw128 v54,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vmulfp128 v8,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vpermwi128 v0,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vmulfp128 v11,v56,v58
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v9,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vmulfp128 v6,v55,v58
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// vmulfp128 v4,v54,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v58.f32)));
	// fcfid f13,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(ctx.f13.s64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// vspltw128 v7,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vspltw128 v5,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// vmaddfp v9,v9,v0,v8
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v10,v12,v0,v11
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vpermwi128 v13,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// vspltw128 v3,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// lfs f10,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// vmaddfp v8,v7,v0,v6
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vspltw128 v2,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vspltw128 v1,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// lfs f9,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f9.f64 = double(temp.f32);
	// vspltw128 v31,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// vspltw128 v30,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// vspltw128 v29,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// vspltw128 v11,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// vspltw128 v12,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v0,v5,v0,v4
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// lwz r11,-12436(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12436);
	// vmaddfp v9,v2,v13,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lis r5,-32226
	ctx.r5.s64 = -2111963136;
	// vmaddfp v10,v3,v13,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r3,r5,2968
	ctx.r3.s64 = ctx.r5.s64 + 2968;
	// vmaddfp v8,v1,v13,v8
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmuls f13,f13,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// vmaddfp v7,v31,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// fmsubs f13,f13,f12,f9
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, -ctx.f9.f64)));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fnmsubs f0,f0,f12,f10
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f12.f64, -ctx.f10.f64)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v10,v30,v0,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v9,v29,v0,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v10,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v13,v11,v0,v8
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v0,v12,v0,v7
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// stvx128 v9,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bctrl
	ctx.lr = 0x82525CCC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x824732e0
	ctx.lr = 0x82525CD0;
	sub_824732E0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// stw r3,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-12332(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12332);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stfs f0,412(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// stw r30,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r30.u32);
	// stb r11,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r11.u8);
	// li r5,64
	ctx.r5.s64 = 64;
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,6988(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 6988);
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r11,r11,448
	ctx.r11.u64 = ctx.r11.u64 | 448;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// bl 0x827567d0
	ctx.lr = 0x82525D20;
	sub_827567D0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82472dc8
	ctx.lr = 0x82525D30;
	sub_82472DC8(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x827566e8
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82546D60) {
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
	// addi r11,r11,368
	ctx.r11.s64 = ctx.r11.s64 + 368;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82483410
	ctx.lr = 0x82546D84;
	sub_82483410(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825c0668
	ctx.lr = 0x82546D8C;
	sub_825C0668(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-2312
	ctx.r11.s64 = ctx.r11.s64 + -2312;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82483320
	ctx.lr = 0x82546DA0;
	sub_82483320(ctx, base);
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

DEFINE_REX_FUNC(sub_825487B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x825487B8;
	__savegprlr_23(ctx, base);
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f29.u64);
	// stfd f30,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f30.u64);
	// stfd f31,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,92(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 92);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825487e0
	if (ctx.cr0.eq) goto loc_825487E0;
loc_825487D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82548a04
	goto loc_82548A04;
loc_825487E0:
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// li r23,1
	ctx.r23.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82548800
	if (ctx.cr6.lt) goto loc_82548800;
	// beq cr6,0x8254880c
	if (ctx.cr6.eq) goto loc_8254880C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82548a00
	if (!ctx.cr6.lt) goto loc_82548A00;
	// b 0x825487d8
	goto loc_825487D8;
loc_82548800:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82548460
	ctx.lr = 0x82548808;
	sub_82548460(ctx, base);
	// stw r23,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r23.u32);
loc_8254880C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r11,12252
	ctx.r29.s64 = ctx.r11.s64 + 12252;
	// lfs f0,1968(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1968);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82548a00
	if (!ctx.cr6.gt) goto loc_82548A00;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82548688
	ctx.lr = 0x8254882C;
	sub_82548688(ctx, base);
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r10,76(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// lfs f31,232(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x82548868
	if (!ctx.cr6.lt) goto loc_82548868;
	// lfs f0,88(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f13,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,88(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 88, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82548868
	if (ctx.cr6.lt) goto loc_82548868;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stfs f31,88(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 88, temp.u32);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
loc_82548868:
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x82548884
	if (!ctx.cr6.eq) goto loc_82548884;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// b 0x82548a04
	goto loc_82548A04;
loc_82548884:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// li r24,0
	ctx.r24.s64 = 0;
	// stw r24,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r24.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82548a00
	if (ctx.cr6.eq) goto loc_82548A00;
	// lbz r11,93(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 93);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825488b0
	if (ctx.cr0.eq) goto loc_825488B0;
	// lwz r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// addi r30,r11,-16
	ctx.r30.s64 = ctx.r11.s64 + -16;
	// b 0x825488b4
	goto loc_825488B4;
loc_825488B0:
	// lwz r30,124(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
loc_825488B4:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mr r25,r24
	ctx.r25.u64 = ctx.r24.u64;
	// ble cr6,0x82548a00
	if (!ctx.cr6.gt) goto loc_82548A00;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lfs f29,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r27,r11,1704
	ctx.r27.s64 = ctx.r11.s64 + 1704;
	// addi r26,r10,3692
	ctx.r26.s64 = ctx.r10.s64 + 3692;
	// lfs f30,-10820(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10820);
	ctx.f30.f64 = double(temp.f32);
loc_825488DC:
	// lbz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 12);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825489b4
	if (!ctx.cr0.eq) goto loc_825489B4;
	// lwz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r28,84(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r29,r31,136
	ctx.r29.s64 = ctx.r31.s64 + 136;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bgt cr6,0x8254894c
	if (ctx.cr6.gt) goto loc_8254894C;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82226b70
	ctx.lr = 0x82548920;
	sub_82226B70(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x822269f0
	ctx.lr = 0x8254892C;
	sub_822269F0(ctx, base);
	// bl 0x82227110
	ctx.lr = 0x82548930;
	sub_82227110(ctx, base);
	// stw r27,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r27.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82227048
	ctx.lr = 0x8254893C;
	sub_82227048(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82371af8
	ctx.lr = 0x8254894C;
	sub_82371AF8(ctx, base);
loc_8254894C:
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f30,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f30.f64, ctx.f0.f64)));
	// stfs f0,4(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82548970
	if (!ctx.cr6.lt) goto loc_82548970;
	// stfs f31,4(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
loc_82548970:
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// stfs f0,8(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// lwa r11,68(r31)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r31.u32 + 68));
	// lfs f13,8(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bne cr6,0x825489c8
	if (!ctx.cr6.eq) goto loc_825489C8;
	// stfs f31,8(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// lbz r11,94(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 94);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825489c8
	if (!ctx.cr0.eq) goto loc_825489C8;
	// stb r23,12(r30)
	REX_STORE_U8(ctx.r30.u32 + 12, ctx.r23.u8);
	// b 0x825489c8
	goto loc_825489C8;
loc_825489B4:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
loc_825489C8:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// cmpw cr6,r11,r24
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r24.s32, ctx.xer);
	// beq cr6,0x82548a00
	if (ctx.cr6.eq) goto loc_82548A00;
	// lbz r11,93(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 93);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825489ec
	if (ctx.cr0.eq) goto loc_825489EC;
	// addi r30,r30,-16
	ctx.r30.s64 = ctx.r30.s64 + -16;
	// b 0x825489f0
	goto loc_825489F0;
loc_825489EC:
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
loc_825489F0:
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// cmpw cr6,r25,r11
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x825488dc
	if (ctx.cr6.lt) goto loc_825488DC;
loc_82548A00:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82548A04:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8255AC80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x8255AC88;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
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
	// bne 0x8255afbc
	if (!ctx.cr0.eq) goto loc_8255AFBC;
	// lwz r11,384(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 384);
	// stfs f1,380(r3)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 380, temp.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8255acdc
	if (!ctx.cr6.eq) goto loc_8255ACDC;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,368(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-29476(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29476);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8255acd4
	if (!ctx.cr6.lt) goto loc_8255ACD4;
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,368(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 368, temp.u32);
	// b 0x8255acdc
	goto loc_8255ACDC;
loc_8255ACD4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8255c698
	ctx.lr = 0x8255ACDC;
	sub_8255C698(ctx, base);
loc_8255ACDC:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r11,12484
	ctx.r30.s64 = ctx.r11.s64 + 12484;
	// lfs f13,1908(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8255acfc
	if (!ctx.cr6.lt) goto loc_8255ACFC;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
loc_8255ACFC:
	// lwz r11,384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8255ade0
	if (ctx.cr6.lt) goto loc_8255ADE0;
	// bne cr6,0x8255ae48
	if (!ctx.cr6.eq) goto loc_8255AE48;
	// lfs f11,372(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 372);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f13
	ctx.cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bge cr6,0x8255ada0
	if (!ctx.cr6.lt) goto loc_8255ADA0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,-8400
	ctx.r11.s64 = ctx.r11.s64 + -8400;
	// lfs f0,-20472(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20472);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f11,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f11.f64, ctx.f0.f64, -ctx.f13.f64)));
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x8255ad40
	if (!ctx.cr6.lt) goto loc_8255AD40;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// b 0x8255ad4c
	goto loc_8255AD4C;
loc_8255AD40:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8255ad4c
	if (!ctx.cr6.gt) goto loc_8255AD4C;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_8255AD4C:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,216(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// li r11,255
	ctx.r11.s64 = 255;
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
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lbz r10,103(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8255AD90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,372(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 372);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,372(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 372, temp.u32);
	// b 0x8255ae48
	goto loc_8255AE48;
loc_8255ADA0:
	// lwz r10,216(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// li r11,255
	ctx.r11.s64 = 255;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
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
	ctx.lr = 0x8255ADD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x8255ae48
	goto loc_8255AE48;
loc_8255ADE0:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r8,-32228
	ctx.r8.s64 = -2112094208;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f0,-17656(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17656);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,376(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,804(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 804);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stfs f13,72(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_8255AE48:
	// lwz r11,384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8255afbc
	if (!ctx.cr6.eq) goto loc_8255AFBC;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lfs f0,2620(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2620);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,376(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lis r5,-32110
	ctx.r5.s64 = -2104360960;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,-9960(r5)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r5.u32 + -9960);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r11,r11,-29072
	ctx.r11.s64 = ctx.r11.s64 + -29072;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r29,100(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r28,100(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// beq cr6,0x8255af28
	if (ctx.cr6.eq) goto loc_8255AF28;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823c31d8
	ctx.lr = 0x8255AF28;
	sub_823C31D8(ctx, base);
loc_8255AF28:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8255af60
	if (ctx.cr0.eq) goto loc_8255AF60;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x8255afbc
	if (ctx.cr6.eq) goto loc_8255AFBC;
	// rlwinm. r10,r11,0,24,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8255afbc
	if (!ctx.cr0.eq) goto loc_8255AFBC;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// beq cr6,0x8255afbc
	if (ctx.cr6.eq) goto loc_8255AFBC;
	// andi. r10,r11,196
	ctx.r10.u64 = ctx.r11.u64 & 196;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8255afb4
	if (!ctx.cr0.eq) goto loc_8255AFB4;
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8255afbc
	if (!ctx.cr0.eq) goto loc_8255AFBC;
	// b 0x8255afb4
	goto loc_8255AFB4;
loc_8255AF60:
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8255af84
	if (ctx.cr6.eq) goto loc_8255AF84;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823c2d80
	ctx.lr = 0x8255AF80;
	sub_823C2D80(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_8255AF84:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8255afa4
	if (ctx.cr6.eq) goto loc_8255AFA4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823c2720
	ctx.lr = 0x8255AFA4;
	sub_823C2720(ctx, base);
loc_8255AFA4:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne cr6,0x8255afb4
	if (!ctx.cr6.eq) goto loc_8255AFB4;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8255afbc
	if (ctx.cr6.eq) goto loc_8255AFBC;
loc_8255AFB4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8255c698
	ctx.lr = 0x8255AFBC;
	sub_8255C698(ctx, base);
loc_8255AFBC:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82570520) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x82570528;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
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
	// bne 0x825708c4
	if (!ctx.cr0.eq) goto loc_825708C4;
	// lwz r11,216(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 216);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,104(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82570560;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,100(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 100);
	// lfs f0,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmadds f1,f0,f31,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f1.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82570578;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x825707c0
	if (ctx.cr6.lt) goto loc_825707C0;
	// beq cr6,0x8257067c
	if (ctx.cr6.eq) goto loc_8257067C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x825708c4
	if (!ctx.cr6.lt) goto loc_825708C4;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f11,368(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 368);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,23536
	ctx.r11.s64 = ctx.r11.s64 + 23536;
	// lfs f0,-18864(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18864);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bge cr6,0x8257063c
	if (!ctx.cr6.lt) goto loc_8257063C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,12484
	ctx.r9.s64 = ctx.r11.s64 + 12484;
	// addi r10,r10,-2512
	ctx.r10.s64 = ctx.r10.s64 + -2512;
	// lfs f12,12484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,408(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 408);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f11,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f11.f64, ctx.f0.f64, -ctx.f13.f64)));
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x825705d8
	if (!ctx.cr6.lt) goto loc_825705D8;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// b 0x825705e4
	goto loc_825705E4;
loc_825705D8:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x825705e4
	if (!ctx.cr6.gt) goto loc_825705E4;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_825705E4:
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,216(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lfs f13,-8400(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8400);
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
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lbz r10,103(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8257062C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,368(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
loc_82570634:
	// stfs f0,368(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// b 0x825708c4
	goto loc_825708C4;
loc_8257063C:
	// lwz r10,216(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// li r11,255
	ctx.r11.s64 = 255;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
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
	ctx.lr = 0x82570670;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82570670:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x825708c4
	goto loc_825708C4;
loc_8257067C:
	// lfs f0,368(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,400(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 400);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82570798
	if (!ctx.cr6.lt) goto loc_82570798;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,368(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r4,r31,68
	ctx.r4.s64 = ctx.r31.s64 + 68;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,384(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 384);
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
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8232e528
	ctx.lr = 0x82570724;
	sub_8232E528(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// lbz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 404);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825708c4
	if (ctx.cr0.eq) goto loc_825708C4;
	// lfs f13,400(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 400);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,368(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// addi r10,r11,12484
	ctx.r10.s64 = ctx.r11.s64 + 12484;
	// lfs f13,12484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -232);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8257076c
	if (!ctx.cr6.lt) goto loc_8257076C;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82570778
	goto loc_82570778;
loc_8257076C:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x82570778
	if (!ctx.cr6.gt) goto loc_82570778;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_82570778:
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// fsubs f1,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82570794;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825708c4
	goto loc_825708C4;
loc_82570798:
	// lbz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 404);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82570670
	if (!ctx.cr0.eq) goto loc_82570670;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r10.u32);
	// stb r9,192(r31)
	REX_STORE_U8(ctx.r31.u32 + 192, ctx.r9.u8);
	// lfs f0,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82570634
	goto loc_82570634;
loc_825707C0:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,368(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,23536(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23536);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8257088c
	if (!ctx.cr6.gt) goto loc_8257088C;
	// lbz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 396);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,368(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825708c4
	if (!ctx.cr0.eq) goto loc_825708C4;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r31,68
	ctx.r4.s64 = ctx.r31.s64 + 68;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f13,384(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 384);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
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
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8232e528
	ctx.lr = 0x82570878;
	sub_8232E528(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// b 0x825708c4
	goto loc_825708C4;
loc_8257088C:
	// lwz r11,388(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 388);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r9,216(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// lfs f1,12484(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x825708B8;
	sub_8225CEC0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f1,368(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
loc_825708C4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8258DD98) {
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
	// bl 0x8258ddf0
	ctx.lr = 0x8258DDB8;
	sub_8258DDF0(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8258ddd0
	if (ctx.cr0.eq) goto loc_8258DDD0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8258ddd0
	if (ctx.cr6.eq) goto loc_8258DDD0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x8258DDD0;
	sub_825FC588(ctx, base);
loc_8258DDD0:
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

DEFINE_REX_FUNC(sub_8258EF88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x8258EF90;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
	// bl 0x82534a18
	ctx.lr = 0x8258EFCC;
	sub_82534A18(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f31,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r30,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r30.u32);
	// addi r28,r11,12488
	ctx.r28.s64 = ctx.r11.s64 + 12488;
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r10,r10,15160
	ctx.r10.s64 = ctx.r10.s64 + 15160;
	// stb r29,392(r31)
	REX_STORE_U8(ctx.r31.u32 + 392, ctx.r29.u8);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// lfs f0,-4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stfs f0,368(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// stb r29,400(r31)
	REX_STORE_U8(ctx.r31.u32 + 400, ctx.r29.u8);
	// stfs f0,372(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 372, temp.u32);
	// stfs f0,380(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// stfs f0,384(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 384, temp.u32);
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// ld r11,6848(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 6848);
	// stfs f0,416(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
	// stw r29,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r29.u32);
	// stb r26,159(r31)
	REX_STORE_U8(ctx.r31.u32 + 159, ctx.r26.u8);
	// std r11,404(r31)
	REX_STORE_U64(ctx.r31.u32 + 404, ctx.r11.u64);
	// bne cr6,0x8258f034
	if (!ctx.cr6.eq) goto loc_8258F034;
	// lfs f0,-236(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8258f038
	goto loc_8258F038;
loc_8258F034:
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
loc_8258F038:
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lwz r8,176(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// li r26,1
	ctx.r26.s64 = 1;
	// lwz r11,-9744(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -9744);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// lwz r7,164(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// rlwimi r8,r26,0,30,31
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x3) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFFC);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f0,372(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 372, temp.u32);
	// rlwinm r10,r7,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFF0;
	// stfs f13,380(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// stw r29,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r29.u32);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// stw r8,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r8.u32);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8258f0e0
	if (!ctx.cr6.eq) goto loc_8258F0E0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f0e0
	if (ctx.cr6.eq) goto loc_8258F0E0;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8258f0e0
	if (ctx.cr0.eq) goto loc_8258F0E0;
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8258f0e0
	if (ctx.cr6.eq) goto loc_8258F0E0;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8258F0D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x8258f0e0
	if (!ctx.cr6.eq) goto loc_8258F0E0;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
loc_8258F0E0:
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f13,372(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 372);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f12,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// bne 0x8258f1c8
	if (!ctx.cr0.eq) goto loc_8258F1C8;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-30000
	ctx.r11.s64 = ctx.r11.s64 + -30000;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,25264(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25264);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,84(r1)
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
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
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// b 0x8258f290
	goto loc_8258F290;
loc_8258F1C8:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r10,-30000
	ctx.r10.s64 = ctx.r10.s64 + -30000;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f0,25264(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25264);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_8258F290:
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r10,376(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 376);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// beq cr6,0x8258f2c8
	if (ctx.cr6.eq) goto loc_8258F2C8;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// beq cr6,0x8258f2c8
	if (ctx.cr6.eq) goto loc_8258F2C8;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r11,r11,24352
	ctx.r11.s64 = ctx.r11.s64 + 24352;
	// lfs f0,-3548(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3548);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-19680(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19680);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,384(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 384, temp.u32);
	// stfs f13,388(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// b 0x8258f2e0
	goto loc_8258F2E0;
loc_8258F2C8:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,-236(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,384(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 384, temp.u32);
	// addi r11,r11,24352
	ctx.r11.s64 = ctx.r11.s64 + 24352;
	// lfs f0,-19680(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19680);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
loc_8258F2E0:
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bge cr6,0x8258f334
	if (!ctx.cr6.lt) goto loc_8258F334;
	// lbz r9,392(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 392);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x8258f334
	if (!ctx.cr0.eq) goto loc_8258F334;
	// lfs f0,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8258f334
	if (!ctx.cr6.gt) goto loc_8258F334;
	// fsubs f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f1,396(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// lbz r9,159(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 159);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r8,356(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// lwz r3,164(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8258eec8
	ctx.lr = 0x8258F330;
	sub_8258EEC8(ctx, base);
	// stb r26,392(r31)
	REX_STORE_U8(ctx.r31.u32 + 392, ctx.r26.u8);
loc_8258F334:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r29,347(r31)
	REX_STORE_U8(ctx.r31.u32 + 347, ctx.r29.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B1540) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756688
	ctx.lr = 0x825B1548;
	__savegprlr_16(ctx, base);
	// addi r12,r1,-136
	ctx.r12.s64 = ctx.r1.s64 + -136;
	// bl 0x827576c0
	ctx.lr = 0x825B1550;
	__savefpr_26(ctx, base);
	// li r12,-208
	ctx.r12.s64 = -208;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r11,-9900(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9900);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b158c
	if (ctx.cr6.eq) goto loc_825B158C;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,916(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 916);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x825b158c
	if (ctx.cr6.lt) goto loc_825B158C;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// ble cr6,0x825b1590
	if (!ctx.cr6.gt) goto loc_825B1590;
loc_825B158C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_825B1590:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825b1ad8
	if (!ctx.cr0.eq) goto loc_825B1AD8;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r30,r11,12484
	ctx.r30.s64 = ctx.r11.s64 + 12484;
	// lwz r11,-9800(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -9800);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b15b8
	if (ctx.cr6.eq) goto loc_825B15B8;
	// lfs f31,664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f31.f64 = double(temp.f32);
	// b 0x825b15bc
	goto loc_825B15BC;
loc_825B15B8:
	// lfs f31,-232(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
loc_825B15BC:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-9780(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9780);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b15d4
	if (ctx.cr6.eq) goto loc_825B15D4;
	// lbz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
loc_825B15D4:
	// clrlwi. r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825b1ad8
	if (ctx.cr0.eq) goto loc_825B1AD8;
	// bl 0x825989e8
	ctx.lr = 0x825B15E0;
	sub_825989E8(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// bgt cr6,0x825b1ad8
	if (ctx.cr6.gt) goto loc_825B1AD8;
	// lbz r11,74(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825b1ad8
	if (ctx.cr0.eq) goto loc_825B1AD8;
	// lbz r11,75(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 75);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825b1ad8
	if (!ctx.cr0.eq) goto loc_825B1AD8;
	// lis r7,-32228
	ctx.r7.s64 = -2112094208;
	// lfs f27,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r5,r7,-6328
	ctx.r5.s64 = ctx.r7.s64 + -6328;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lfs f29,-6328(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -6328);
	ctx.f29.f64 = double(temp.f32);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// lfs f28,-4492(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -4492);
	ctx.f28.f64 = double(temp.f32);
	// lfs f30,8132(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8132);
	ctx.f30.f64 = double(temp.f32);
	// li r21,0
	ctx.r21.s64 = 0;
	// addi r31,r25,108
	ctx.r31.s64 = ctx.r25.s64 + 108;
	// addi r26,r25,156
	ctx.r26.s64 = ctx.r25.s64 + 156;
	// li r18,-1
	ctx.r18.s64 = -1;
	// lis r23,-32109
	ctx.r23.s64 = -2104295424;
	// lis r22,-32109
	ctx.r22.s64 = -2104295424;
	// lis r19,-32109
	ctx.r19.s64 = -2104295424;
	// lis r30,-32109
	ctx.r30.s64 = -2104295424;
	// addi r24,r11,-28592
	ctx.r24.s64 = ctx.r11.s64 + -28592;
	// addi r29,r10,-30256
	ctx.r29.s64 = ctx.r10.s64 + -30256;
	// addi r17,r9,-26672
	ctx.r17.s64 = ctx.r9.s64 + -26672;
	// addi r16,r8,-26688
	ctx.r16.s64 = ctx.r8.s64 + -26688;
	// addi r28,r7,-28048
	ctx.r28.s64 = ctx.r7.s64 + -28048;
	// addi r27,r6,-26912
	ctx.r27.s64 = ctx.r6.s64 + -26912;
loc_825B1668:
	// lwz r5,-72(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + -72);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x825b1ac4
	if (ctx.cr6.eq) goto loc_825B1AC4;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8245cd58
	ctx.lr = 0x825B167C;
	sub_8245CD58(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825b1ac4
	if (ctx.cr0.eq) goto loc_825B1AC4;
	// fmr f31,f27
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f27.f64;
	// bl 0x8245cce8
	ctx.lr = 0x825B168C;
	sub_8245CCE8(ctx, base);
	// cmplw cr6,r5,r3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x825b169c
	if (!ctx.cr6.eq) goto loc_825B169C;
	// lfs f0,5320(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 5320);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f0,f28
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
loc_825B169C:
	// lwz r3,44(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 44);
	// bl 0x825b7bf8
	ctx.lr = 0x825B16A4;
	sub_825B7BF8(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x825b1740
	if (ctx.cr0.eq) goto loc_825B1740;
	// addi r11,r1,304
	ctx.r11.s64 = ctx.r1.s64 + 304;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,316(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// clrldi r10,r21,32
	ctx.r10.u64 = ctx.r21.u64 & 0xFFFFFFFF;
	// stfs f0,312(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// addi r9,r1,496
	ctx.r9.s64 = ctx.r1.s64 + 496;
	// stfs f0,308(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// std r10,352(r1)
	REX_STORE_U64(ctx.r1.u32 + 352, ctx.r10.u64);
	// stfs f0,304(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,400
	ctx.r8.s64 = ctx.r1.s64 + 400;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f12,0(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,220(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f12,216(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f12,212(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f12,208(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,400(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,496(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 496);
	ctx.f13.f64 = double(temp.f32);
	// lfd f0,352(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 352);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,5320(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 5320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,5308(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 5308);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bl 0x825b12e8
	ctx.lr = 0x825B1740;
	sub_825B12E8(ctx, base);
loc_825B1740:
	// lwz r3,52(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 52);
	// bl 0x825b7bf8
	ctx.lr = 0x825B1748;
	sub_825B7BF8(ctx, base);
	// mr. r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq 0x825b1818
	if (ctx.cr0.eq) goto loc_825B1818;
	// lfs f0,68(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// lvx128 v127,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// bl 0x82755380
	ctx.lr = 0x825B1774;
	sub_82755380(ctx, base);
	// addi r11,r1,272
	ctx.r11.s64 = ctx.r1.s64 + 272;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// clrldi r10,r21,32
	ctx.r10.u64 = ctx.r21.u64 & 0xFFFFFFFF;
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// std r10,336(r1)
	REX_STORE_U64(ctx.r1.u32 + 336, ctx.r10.u64);
	// stfs f0,280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// addi r10,r1,528
	ctx.r10.s64 = ctx.r1.s64 + 528;
	// lvx128 v63,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lfd f12,336(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 336);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f13,f29
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f29.f64));
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f0,5320(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 5320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,5308(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 5308);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// lfs f11,528(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 528);
	ctx.f11.f64 = double(temp.f32);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v127.f32)));
	// frsp f12,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f0,f12,f0,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// lfs f10,432(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 432);
	ctx.f10.f64 = double(temp.f32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bl 0x825b12e8
	ctx.lr = 0x825B1818;
	sub_825B12E8(ctx, base);
loc_825B1818:
	// clrldi r11,r21,32
	ctx.r11.u64 = ctx.r21.u64 & 0xFFFFFFFF;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// std r11,344(r1)
	REX_STORE_U64(ctx.r1.u32 + 344, ctx.r11.u64);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// lfd f13,344(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 344);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r8,r1,464
	ctx.r8.s64 = ctx.r1.s64 + 464;
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r5,-256
	ctx.r5.s64 = -16777216;
	// stfs f0,236(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// ori r6,r6,8191
	ctx.r6.u64 = ctx.r6.u64 | 8191;
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// ori r5,r5,255
	ctx.r5.u64 = ctx.r5.u64 | 255;
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lvx128 v61,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,5320(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 5320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f2,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f12,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(ctx.f13.s64);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,5316(r22)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 5316);
	ctx.f13.f64 = double(temp.f32);
	// frsp f26,f12
	ctx.f26.f64 = double(float(ctx.f12.f64));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vaddfp128 v63,v63,v61
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// fmadds f0,f26,f0,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(std::fma(ctx.f26.f64, ctx.f0.f64, ctx.f13.f64)));
	// lfs f12,368(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,464(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 464);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x825b1af0
	ctx.lr = 0x825B18D4;
	sub_825B1AF0(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f13,5312(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 5312);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// lfs f0,5320(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 5320);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// fmadds f0,f26,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f26.f64, ctx.f0.f64, ctx.f13.f64)));
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,416
	ctx.r8.s64 = ctx.r1.s64 + 416;
	// lvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v60,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// lfs f2,48(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 48);
	ctx.f2.f64 = double(temp.f32);
	// mr r6,r18
	ctx.r6.u64 = ctx.r18.u64;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lfs f13,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
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
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v59,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f13,268(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f13,264(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f13,260(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f13,256(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v60
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lfs f13,384(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfs f0,416(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 416);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// ld r4,88(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x825b1af0
	ctx.lr = 0x825B1974;
	sub_825B1AF0(ctx, base);
	// lfs f0,5320(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 5320);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,288
	ctx.r11.s64 = ctx.r1.s64 + 288;
	// lfs f13,5316(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 5316);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// fmadds f0,f26,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f26.f64, ctx.f0.f64, ctx.f13.f64)));
	// lvx128 v61,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,448
	ctx.r8.s64 = ctx.r1.s64 + 448;
	// lvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,480
	ctx.r9.s64 = ctx.r1.s64 + 480;
	// lvx128 v60,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,95
	ctx.r6.s64 = 6225920;
	// lis r5,247
	ctx.r5.s64 = 16187392;
	// lfs f2,24(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 24);
	ctx.f2.f64 = double(temp.f32);
	// ori r6,r6,19967
	ctx.r6.u64 = ctx.r6.u64 | 19967;
	// ori r5,r5,1279
	ctx.r5.u64 = ctx.r5.u64 | 1279;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfs f0,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f0,300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f0,296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f0,292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// lfs f0,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// stfs f0,332(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f0,328(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f0,324(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// lvx128 v59,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v59,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v59,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v59,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vaddfp128 v62,v61,v60
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,448(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 448);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,480(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 480);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r4,104(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x825b1af0
	ctx.lr = 0x825B1A1C;
	sub_825B1AF0(ctx, base);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lis r6,-1793
	ctx.r6.s64 = -117506048;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lis r5,-1793
	ctx.r5.s64 = -117506048;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r9,r1,544
	ctx.r9.s64 = ctx.r1.s64 + 544;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r8,r1,512
	ctx.r8.s64 = ctx.r1.s64 + 512;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,5320(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 5320);
	ctx.f0.f64 = double(temp.f32);
	// ori r6,r6,18943
	ctx.r6.u64 = ctx.r6.u64 | 18943;
	// lfs f13,5312(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 5312);
	ctx.f13.f64 = double(temp.f32);
	// ori r5,r5,18943
	ctx.r5.u64 = ctx.r5.u64 | 18943;
	// fmadds f0,f26,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f26.f64, ctx.f0.f64, ctx.f13.f64)));
	// lvx128 v61,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stfs f12,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f12,188(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f12,180(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v61,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f1,f0,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfs f2,72(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 72);
	ctx.f2.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,512(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 512);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f0,544(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 544);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// ld r4,120(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// bl 0x825b1af0
	ctx.lr = 0x825B1AC4;
	sub_825B1AF0(ctx, base);
loc_825B1AC4:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// cmplwi cr6,r21,6
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 6, ctx.xer);
	// blt cr6,0x825b1668
	if (ctx.cr6.lt) goto loc_825B1668;
loc_825B1AD8:
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// li r0,-208
	ctx.r0.s64 = -208;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-136
	ctx.r12.s64 = ctx.r1.s64 + -136;
	// bl 0x8275770c
	ctx.lr = 0x825B1AEC;
	__restfpr_26(ctx, base);
	// b 0x827566d8
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F7418) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x825F7420;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,40(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// addi r28,r11,25420
	ctx.r28.s64 = ctx.r11.s64 + 25420;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825f745c
	if (!ctx.cr6.eq) goto loc_825F745C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r11,25484
	ctx.r3.s64 = ctx.r11.s64 + 25484;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,128
	ctx.r5.s64 = 128;
	// bl 0x825f62a8
	ctx.lr = 0x825F745C;
	sub_825F62A8(ctx, base);
loc_825F745C:
	// addi r5,r31,8
	ctx.r5.s64 = ctx.r31.s64 + 8;
	// lwz r3,40(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// clrlwi r4,r29,16
	ctx.r4.u64 = ctx.r29.u32 & 0xFFFF;
	// bl 0x825fa070
	ctx.lr = 0x825F746C;
	sub_825FA070(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x825f748c
	if (!ctx.cr0.eq) goto loc_825F748C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r11,25508
	ctx.r3.s64 = ctx.r11.s64 + 25508;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,132
	ctx.r5.s64 = 132;
	// bl 0x825f62a8
	ctx.lr = 0x825F748C;
	sub_825F62A8(ctx, base);
loc_825F748C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// sth r29,0(r31)
	REX_STORE_U16(ctx.r31.u32 + 0, ctx.r29.u16);
	// lhz r10,48(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 48);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// ori r11,r11,43981
	ctx.r11.u64 = ctx.r11.u64 | 43981;
	// sth r10,2(r31)
	REX_STORE_U16(ctx.r31.u32 + 2, ctx.r10.u16);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FC978) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x825FC980;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// addi r10,r11,6888
	ctx.r10.s64 = ctx.r11.s64 + 6888;
	// lwz r11,68(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 68);
	// lbz r9,28(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x825fc9a4
	if (ctx.cr0.eq) goto loc_825FC9A4;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r9.u8);
loc_825FC9A4:
	// lis r9,-32108
	ctx.r9.s64 = -2104229888;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,68(r10)
	REX_STORE_U32(ctx.r10.u32 + 68, ctx.r11.u32);
	// lwz r31,-31940(r9)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + -31940);
	// stw r11,-31940(r9)
	REX_STORE_U32(ctx.r9.u32 + -31940, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi r31,0
	ctx.cr0.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq 0x825fc9d8
	if (ctx.cr0.eq) goto loc_825FC9D8;
loc_825FC9C4:
	// lwz r31,2564(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 2564);
	// bl 0x825fc588
	ctx.lr = 0x825FC9CC;
	sub_825FC588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x825fc9c4
	if (!ctx.cr6.eq) goto loc_825FC9C4;
loc_825FC9D8:
	// lis r10,-32108
	ctx.r10.s64 = -2104229888;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r31,-31944(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + -31944);
	// stw r11,-31944(r10)
	REX_STORE_U32(ctx.r10.u32 + -31944, ctx.r11.u32);
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// cmplwi r31,0
	ctx.cr0.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq 0x825fca28
	if (ctx.cr0.eq) goto loc_825FCA28;
loc_825FC9F4:
	// lwz r31,132(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// addi r29,r30,128
	ctx.r29.s64 = ctx.r30.s64 + 128;
	// li r28,3
	ctx.r28.s64 = 3;
loc_825FCA00:
	// addi r29,r29,-32
	ctx.r29.s64 = ctx.r29.s64 + -32;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82606140
	ctx.lr = 0x825FCA0C;
	sub_82606140(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x825fca00
	if (!ctx.cr0.lt) goto loc_825FCA00;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825fc588
	ctx.lr = 0x825FCA1C;
	sub_825FC588(ctx, base);
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x825fc9f4
	if (!ctx.cr6.eq) goto loc_825FC9F4;
loc_825FCA28:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82601610) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82601630;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_826021F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x82602200;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	ctx.r27.s64 = 0;
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// std r27,0(r4)
	REX_STORE_U64(ctx.r4.u32 + 0, ctx.r27.u64);
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
	// addi r31,r3,12
	ctx.r31.s64 = ctx.r3.s64 + 12;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// and r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 & ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82601910
	ctx.lr = 0x82602238;
	sub_82601910(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x82602278
	if (ctx.cr0.eq) goto loc_82602278;
	// stw r29,32(r4)
	REX_STORE_U32(ctx.r4.u32 + 32, ctx.r29.u32);
	// addi r10,r30,92
	ctx.r10.s64 = ctx.r30.s64 + 92;
	// stw r28,56(r4)
	REX_STORE_U32(ctx.r4.u32 + 56, ctx.r28.u32);
loc_8260224C:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r10
	ea = ctx.r10.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r27,0,r10
	ea = ctx.r10.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r27.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8260224c
	if (!ctx.cr0.eq) goto loc_8260224C;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x82601a60
	ctx.lr = 0x82602278;
	sub_82601A60(ctx, base);
loc_82602278:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82605448) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x82604c88
	sub_82604C88(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82605630) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x82605638;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r10,8(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lhz r9,4(r5)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r5.u32 + 4);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lbz r8,6(r5)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r5.u32 + 6);
	// addi r24,r4,20
	ctx.r24.s64 = ctx.r4.s64 + 20;
	// lbz r7,48(r4)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r4.u32 + 48);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// sth r9,92(r1)
	REX_STORE_U16(ctx.r1.u32 + 92, ctx.r9.u16);
	// stb r8,94(r1)
	REX_STORE_U8(ctx.r1.u32 + 94, ctx.r8.u8);
	// beq 0x82605680
	if (ctx.cr0.eq) goto loc_82605680;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82872dfc
	ctx.lr = 0x82605680;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_82605680:
	// lwz r30,12(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r29,r27,8
	ctx.r29.s64 = ctx.r27.s64 + 8;
	// stw r25,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r25.u32);
	// lwz r31,4(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x826056bc
	goto loc_826056BC;
loc_82605698:
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// bl 0x82605f08
	ctx.lr = 0x826056A4;
	sub_82605F08(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826056b4
	if (ctx.cr0.eq) goto loc_826056B4;
	// lwz r31,8(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// b 0x826056bc
	goto loc_826056BC;
loc_826056B4:
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_826056BC:
	// lbz r11,29(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 29);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82605698
	if (ctx.cr0.eq) goto loc_82605698;
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x826056f4
	if (ctx.cr6.eq) goto loc_826056F4;
	// addi r4,r30,12
	ctx.r4.s64 = ctx.r30.s64 + 12;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82605f08
	ctx.lr = 0x826056E4;
	sub_82605F08(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x826056f4
	if (!ctx.cr0.eq) goto loc_826056F4;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// b 0x826056fc
	goto loc_826056FC;
loc_826056F4:
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
loc_826056FC:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,12(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82605718
	if (ctx.cr6.eq) goto loc_82605718;
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82605b10
	ctx.lr = 0x82605718;
	sub_82605B10(ctx, base);
loc_82605718:
	// lbz r11,28(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8260572c
	if (ctx.cr0.eq) goto loc_8260572C;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82872dec
	ctx.lr = 0x8260572C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8260572C:
	// lwz r3,0(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x82758e00
	ctx.lr = 0x82605734;
	sub_82758E00(ctx, base);
	// lbz r11,6(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 6);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r25,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r25.u32);
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// stb r11,6(r28)
	REX_STORE_U8(ctx.r28.u32 + 6, ctx.r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8260DE70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8260DE78;
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
	// beq cr6,0x8260dec0
	if (ctx.cr6.eq) goto loc_8260DEC0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,56(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8260DEA8;
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
	ctx.lr = 0x8260DEBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
loc_8260DEC0:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8260dee0
	if (ctx.cr6.eq) goto loc_8260DEE0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8260DEDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_8260DEE0:
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8260df18
	if (ctx.cr6.eq) goto loc_8260DF18;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,56(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8260DF00;
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
	ctx.lr = 0x8260DF14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
loc_8260DF18:
	// addi r11,r31,48
	ctx.r11.s64 = ctx.r31.s64 + 48;
loc_8260DF1C:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r29,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r29.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8260df1c
	if (!ctx.cr0.eq) goto loc_8260DF1C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82613038) {
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
	// addi r11,r11,27704
	ctx.r11.s64 = ctx.r11.s64 + 27704;
	// clrlwi. r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq 0x82613064
	if (ctx.cr0.eq) goto loc_82613064;
	// bl 0x825fc588
	ctx.lr = 0x82613064;
	sub_825FC588(ctx, base);
loc_82613064:
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

DEFINE_REX_FUNC(sub_82613CD8) {
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
	// bl 0x82613970
	ctx.lr = 0x82613CF8;
	sub_82613970(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,420(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 420);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82613D10;
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

DEFINE_REX_FUNC(sub_826154C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x826154D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r31,r11,-12400
	ctx.r31.s64 = ctx.r11.s64 + -12400;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8261552c
	if (!ctx.cr6.eq) goto loc_8261552C;
	// lwsync
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r29,r11,-12408
	ctx.r29.s64 = ctx.r11.s64 + -12408;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_826154FC:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r30,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r30.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x826154fc
	if (!ctx.cr0.eq) goto loc_826154FC;
	// bl 0x826239d0
	ctx.lr = 0x82615518;
	sub_826239D0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82615358
	ctx.lr = 0x82615520;
	sub_82615358(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82615578
	if (ctx.cr6.eq) goto loc_82615578;
loc_8261552C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// subf r10,r31,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r31.u64;
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
	// beq 0x82615564
	if (ctx.cr0.eq) goto loc_82615564;
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
loc_82615564:
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// addi r11,r11,-36
	ctx.r11.s64 = ctx.r11.s64 + -36;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and. r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82615580
	if (!ctx.cr0.eq) goto loc_82615580;
loc_82615578:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82615590
	goto loc_82615590;
loc_82615580:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lwz r11,-12416(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -12416);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-12416(r10)
	REX_STORE_U32(ctx.r10.u32 + -12416, ctx.r11.u32);
loc_82615590:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8261DC50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a0
	ctx.lr = 0x8261DC58;
	__savegprlr_22(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
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
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// li r24,72
	ctx.r24.s64 = 72;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8261dc84
	if (!ctx.cr6.eq) goto loc_8261DC84;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8261dc90
	goto loc_8261DC90;
loc_8261DC84:
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// divw r9,r10,r24
	ctx.r9.u64 = uint32_t((ctx.r24.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r24.s32 == -1)) ? ctx.r10.s32 / ctx.r24.s32 : 0);
loc_8261DC90:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8261df3c
	if (ctx.cr6.eq) goto loc_8261DF3C;
	// lwz r30,8(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lis r10,910
	ctx.r10.s64 = 59637760;
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// ori r10,r10,14563
	ctx.r10.u64 = ctx.r10.u64 | 14563;
	// divw r11,r11,r24
	ctx.r11.u64 = uint32_t((ctx.r24.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r24.s32 == -1)) ? ctx.r11.s32 / ctx.r24.s32 : 0);
	// subf r8,r11,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r8,r28
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x8261dd00
	if (!ctx.cr6.lt) goto loc_8261DD00;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r4,r11,1648
	ctx.r4.s64 = ctx.r11.s64 + 1648;
	// bl 0x82226b70
	ctx.lr = 0x8261DCC8;
	sub_82226B70(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x822269f0
	ctx.lr = 0x8261DCD4;
	sub_822269F0(ctx, base);
	// bl 0x82227110
	ctx.lr = 0x8261DCD8;
	sub_82227110(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// addi r11,r11,1704
	ctx.r11.s64 = ctx.r11.s64 + 1704;
	// stw r11,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r11.u32);
	// bl 0x82227048
	ctx.lr = 0x8261DCEC;
	sub_82227048(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82371af8
	ctx.lr = 0x8261DCFC;
	sub_82371AF8(ctx, base);
	// b 0x8261df3c
	goto loc_8261DF3C;
loc_8261DD00:
	// add r8,r11,r28
	ctx.r8.u64 = ctx.r11.u64 + ctx.r28.u64;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8261ddf0
	if (!ctx.cr6.lt) goto loc_8261DDF0;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8261dd24
	if (!ctx.cr6.lt) goto loc_8261DD24;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8261dd28
	goto loc_8261DD28;
loc_8261DD24:
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_8261DD28:
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8261dd34
	if (!ctx.cr6.lt) goto loc_8261DD34;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8261DD34:
	// mulli r27,r11,72
	ctx.r27.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(72));
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x826152a0
	ctx.lr = 0x8261DD40;
	sub_826152A0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// subf r11,r11,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r11.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// divw r26,r11,r24
	ctx.r26.u64 = uint32_t((ctx.r24.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r24.s32 == -1)) ? ctx.r11.s32 / ctx.r24.s32 : 0);
	// mulli r11,r26,72
	ctx.r11.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(72));
	// add r23,r11,r3
	ctx.r23.u64 = ctx.r11.u64 + ctx.r3.u64;
	// beq cr6,0x8261dd98
	if (ctx.cr6.eq) goto loc_8261DD98;
	// mr r22,r28
	ctx.r22.u64 = ctx.r28.u64;
loc_8261DD64:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8261dd8c
	if (ctx.cr6.eq) goto loc_8261DD8C;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x827567d0
	ctx.lr = 0x8261DD7C;
	sub_827567D0(ctx, base);
	// lwz r11,64(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 64);
	// stw r11,64(r23)
	REX_STORE_U32(ctx.r23.u32 + 64, ctx.r11.u32);
	// lwz r11,68(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 68);
	// stw r11,68(r23)
	REX_STORE_U32(ctx.r23.u32 + 68, ctx.r11.u32);
loc_8261DD8C:
	// addic. r22,r22,-1
	ctx.xer.ca = ctx.r22.u32 > 0;
	ctx.r22.s64 = ctx.r22.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// addi r23,r23,72
	ctx.r23.s64 = ctx.r23.s64 + 72;
	// bne 0x8261dd64
	if (!ctx.cr0.eq) goto loc_8261DD64;
loc_8261DD98:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8261e2b0
	ctx.lr = 0x8261DDA8;
	sub_8261E2B0(ctx, base);
	// add r11,r26,r28
	ctx.r11.u64 = ctx.r26.u64 + ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mulli r11,r11,72
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(72));
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x8261e2b0
	ctx.lr = 0x8261DDC0;
	sub_8261E2B0(ctx, base);
	// add r11,r27,r30
	ctx.r11.u64 = ctx.r27.u64 + ctx.r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r24
	ctx.r11.u64 = uint32_t((ctx.r24.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r24.s32 == -1)) ? ctx.r11.s32 / ctx.r24.s32 : 0);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// mulli r11,r11,72
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(72));
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x8261df3c
	goto loc_8261DF3C;
loc_8261DDF0:
	// subf r11,r29,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// divw r11,r11,r24
	ctx.r11.u64 = uint32_t((ctx.r24.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r24.s32 == -1)) ? ctx.r11.s32 / ctx.r24.s32 : 0);
	// li r5,64
	ctx.r5.s64 = 64;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// bge cr6,0x8261deb0
	if (!ctx.cr6.lt) goto loc_8261DEB0;
	// bl 0x827567d0
	ctx.lr = 0x8261DE10;
	sub_827567D0(ctx, base);
	// lwz r26,64(r25)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r25.u32 + 64);
	// lwz r25,68(r25)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r25.u32 + 68);
	// mulli r27,r28,72
	ctx.r27.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(72));
	// stw r26,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r26.u32);
	// stw r25,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r25.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r5,r27,r29
	ctx.r5.u64 = ctx.r27.u64 + ctx.r29.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8261e2b0
	ctx.lr = 0x8261DE34;
	sub_8261E2B0(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r10,r29,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r29.u64;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// divw r11,r10,r24
	ctx.r11.u64 = uint32_t((ctx.r24.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r24.s32 == -1)) ? ctx.r10.s32 / ctx.r24.s32 : 0);
	// subf. r11,r11,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8261de7c
	if (ctx.cr0.eq) goto loc_8261DE7C;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_8261DE50:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8261de70
	if (ctx.cr6.eq) goto loc_8261DE70;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827567d0
	ctx.lr = 0x8261DE68;
	sub_827567D0(ctx, base);
	// stw r26,64(r30)
	REX_STORE_U32(ctx.r30.u32 + 64, ctx.r26.u32);
	// stw r25,68(r30)
	REX_STORE_U32(ctx.r30.u32 + 68, ctx.r25.u32);
loc_8261DE70:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r30,r30,72
	ctx.r30.s64 = ctx.r30.s64 + 72;
	// bne 0x8261de50
	if (!ctx.cr0.eq) goto loc_8261DE50;
loc_8261DE7C:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// subf r30,r27,r11
	ctx.r30.u64 = ctx.r11.u64 - ctx.r27.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x8261dea4
	goto loc_8261DEA4;
loc_8261DE90:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,72
	ctx.r5.s64 = 72;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827567d0
	ctx.lr = 0x8261DEA0;
	sub_827567D0(ctx, base);
	// addi r29,r29,72
	ctx.r29.s64 = ctx.r29.s64 + 72;
loc_8261DEA4:
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8261de90
	if (!ctx.cr6.eq) goto loc_8261DE90;
	// b 0x8261df3c
	goto loc_8261DF3C;
loc_8261DEB0:
	// bl 0x827567d0
	ctx.lr = 0x8261DEB4;
	sub_827567D0(ctx, base);
	// mulli r27,r28,72
	ctx.r27.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(72));
	// lwz r11,64(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 64);
	// lwz r10,68(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 68);
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// stw r10,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// subf r28,r27,r30
	ctx.r28.u64 = ctx.r30.u64 - ctx.r27.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8261e2b0
	ctx.lr = 0x8261DEDC;
	sub_8261E2B0(ctx, base);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8261df10
	if (ctx.cr6.eq) goto loc_8261DF10;
	// add r30,r27,r28
	ctx.r30.u64 = ctx.r27.u64 + ctx.r28.u64;
loc_8261DEF0:
	// addi r31,r31,-72
	ctx.r31.s64 = ctx.r31.s64 + -72;
	// addi r30,r30,-72
	ctx.r30.s64 = ctx.r30.s64 + -72;
	// li r5,72
	ctx.r5.s64 = 72;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827567d0
	ctx.lr = 0x8261DF08;
	sub_827567D0(ctx, base);
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8261def0
	if (!ctx.cr6.eq) goto loc_8261DEF0;
loc_8261DF10:
	// add r30,r27,r29
	ctx.r30.u64 = ctx.r27.u64 + ctx.r29.u64;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8261df3c
	if (ctx.cr6.eq) goto loc_8261DF3C;
loc_8261DF20:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,72
	ctx.r5.s64 = 72;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827567d0
	ctx.lr = 0x8261DF30;
	sub_827567D0(ctx, base);
	// addi r31,r31,72
	ctx.r31.s64 = ctx.r31.s64 + 72;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8261df20
	if (!ctx.cr6.eq) goto loc_8261DF20;
loc_8261DF3C:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82633DC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x82633DD0;
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
	ctx.lr = 0x82633DF8;
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
	// bne cr6,0x82633e70
	if (!ctx.cr6.eq) goto loc_82633E70;
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
	// bge cr6,0x82633ec0
	if (!ctx.cr6.lt) goto loc_82633EC0;
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
	// bl 0x82633b50
	ctx.lr = 0x82633E4C;
	sub_82633B50(ctx, base);
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
	// b 0x82633ec0
	goto loc_82633EC0;
loc_82633E70:
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x82633e88
	if (ctx.cr6.lt) goto loc_82633E88;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// ble cr6,0x82633e8c
	if (!ctx.cr6.gt) goto loc_82633E8C;
loc_82633E88:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82633E8C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82633ec0
	if (ctx.cr0.eq) goto loc_82633EC0;
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
	// blt cr6,0x82633eb8
	if (ctx.cr6.lt) goto loc_82633EB8;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_82633EB8:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
loc_82633EC0:
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
	// beq cr6,0x82633f14
	if (ctx.cr6.eq) goto loc_82633F14;
	// ble cr6,0x82633f1c
	if (!ctx.cr6.gt) goto loc_82633F1C;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x82633f1c
	if (ctx.cr6.gt) goto loc_82633F1C;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82633f0c
	if (ctx.cr6.eq) goto loc_82633F0C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82633f1c
	if (!ctx.cr6.eq) goto loc_82633F1C;
	// b 0x82633f18
	goto loc_82633F18;
loc_82633F0C:
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x82633f1c
	goto loc_82633F1C;
loc_82633F14:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82633F18:
	// li r9,1
	ctx.r9.s64 = 1;
loc_82633F1C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r28,r11,14392
	ctx.r28.s64 = ctx.r11.s64 + 14392;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,28828
	ctx.r11.s64 = ctx.r11.s64 + 28828;
	// lfs f12,-1908(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1908);
	ctx.f12.f64 = double(temp.f32);
	// beq 0x82633f6c
	if (ctx.cr0.eq) goto loc_82633F6C;
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
	// ble cr6,0x82633f6c
	if (!ctx.cr6.gt) goto loc_82633F6C;
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
loc_82633F6C:
	// clrlwi. r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82633fb0
	if (ctx.cr0.eq) goto loc_82633FB0;
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
	// bge cr6,0x82633fb0
	if (!ctx.cr6.lt) goto loc_82633FB0;
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
loc_82633FB0:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lbz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 44);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82633fc8
	if (!ctx.cr0.eq) goto loc_82633FC8;
loc_82633FC0:
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x82633ffc
	goto loc_82633FFC;
loc_82633FC8:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82633FDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82632298
	ctx.lr = 0x82633FE0;
	sub_82632298(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82633fc0
	if (ctx.cr0.eq) goto loc_82633FC0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82633FF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsb r29,r3
	ctx.r29.s64 = ctx.r3.s8;
loc_82633FFC:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82634010;
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
	ctx.lr = 0x82634028;
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
	// bl 0x82633a98
	ctx.lr = 0x82634040;
	sub_82633A98(ctx, base);
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
	ctx.lr = 0x82634068;
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
	// beq cr6,0x8263413c
	if (ctx.cr6.eq) goto loc_8263413C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x826340f4
	if (ctx.cr6.eq) goto loc_826340F4;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8263418c
	if (!ctx.cr6.eq) goto loc_8263418C;
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
	// b 0x82634188
	goto loc_82634188;
loc_826340F4:
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
	// b 0x82634188
	goto loc_82634188;
loc_8263413C:
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
loc_82634188:
	// stfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 12, temp.u32);
loc_8263418C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826564D0) {
	REX_FUNC_PROLOGUE();
	// b 0x82872aec
	__imp__XamShowSigninUI(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826564F0) {
	REX_FUNC_PROLOGUE();
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// b 0x82872b2c
	__imp__XamShowMarketplaceUI(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826565A8) {
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
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x82872c7c
	ctx.lr = 0x826565C4;
	__imp__XexLoadImage(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x826565d8
	if (!ctx.cr0.lt) goto loc_826565D8;
	// bl 0x82658520
	ctx.lr = 0x826565D0;
	sub_82658520(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x826565dc
	goto loc_826565DC;
loc_826565D8:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_826565DC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82657AF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x82657AF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// rlwinm. r11,r4,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82657b68
	if (ctx.cr0.eq) goto loc_82657B68;
	// rlwinm. r11,r4,0,4,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xF000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82657b1c
	if (!ctx.cr0.eq) goto loc_82657B1C;
	// li r11,3
	ctx.r11.s64 = 3;
	// rlwimi r31,r11,26,4,7
	ctx.r31.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xF000000) | (ctx.r31.u64 & 0xFFFFFFFFF0FFFFFF);
loc_82657B1C:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// rlwinm r10,r31,6,28,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 6) & 0xC;
	// addi r11,r11,13224
	ctx.r11.s64 = ctx.r11.s64 + 13224;
	// rlwinm r9,r31,8,28,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 8) & 0xF;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// slw r5,r8,r9
	ctx.r5.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwzx r6,r10,r11
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// bl 0x826559d0
	ctx.lr = 0x82657B44;
	sub_826559D0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82657b78
	if (ctx.cr0.eq) goto loc_82657B78;
	// rlwinm. r11,r31,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82657b78
	if (ctx.cr0.eq) goto loc_82657B78;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82756d30
	ctx.lr = 0x82657B64;
	sub_82756D30(ctx, base);
	// b 0x82657b78
	goto loc_82657B78;
loc_82657B68:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// rlwinm r3,r31,8,25,25
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 8) & 0x40;
	// bl 0x82659e40
	ctx.lr = 0x82657B74;
	sub_82659E40(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82657B78:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8265D910) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8265D918;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// sth r30,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r30.u16);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r30,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r30,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// stw r30,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82872cec
	ctx.lr = 0x8265D954;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8265d964
	if (!ctx.cr0.lt) goto loc_8265D964;
loc_8265D95C:
	// bl 0x82872c3c
	ctx.lr = 0x8265D960;
	__imp__RtlNtStatusToDosError(ctx, base);
	// b 0x8265db28
	goto loc_8265DB28;
loc_8265D964:
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82872cec
	ctx.lr = 0x8265D984;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8265d95c
	if (ctx.cr0.lt) goto loc_8265D95C;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r10,r31,4
	ctx.r10.s64 = ctx.r31.s64 + 4;
	// addi r9,r1,107
	ctx.r9.s64 = ctx.r1.s64 + 107;
	// addi r8,r10,-2
	ctx.r8.s64 = ctx.r10.s64 + -2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8265D9A0:
	// lbzu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// sthu r11,2(r8)
	ea = 2 + ctx.r8.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r8.u32 = ea;
	// bdnz 0x8265d9a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8265D9A0;
	// sth r30,8(r10)
	REX_STORE_U16(ctx.r10.u32 + 8, ctx.r30.u16);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82872cec
	ctx.lr = 0x8265D9C8;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8265d95c
	if (ctx.cr0.lt) goto loc_8265D95C;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r10,r31,88
	ctx.r10.s64 = ctx.r31.s64 + 88;
	// addi r9,r1,111
	ctx.r9.s64 = ctx.r1.s64 + 111;
	// addi r8,r10,-2
	ctx.r8.s64 = ctx.r10.s64 + -2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8265D9E4:
	// lbzu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// sthu r11,2(r8)
	ea = 2 + ctx.r8.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r8.u32 = ea;
	// bdnz 0x8265d9e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8265D9E4;
	// sth r30,8(r10)
	REX_STORE_U16(ctx.r10.u32 + 8, ctx.r30.u16);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82872cec
	ctx.lr = 0x8265DA0C;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8265d95c
	if (ctx.cr0.lt) goto loc_8265D95C;
	// addi r3,r31,68
	ctx.r3.s64 = ctx.r31.s64 + 68;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82756d30
	ctx.lr = 0x8265DA24;
	sub_82756D30(ctx, base);
	// lbz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 84);
	// lbz r8,87(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lbz r10,85(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 85);
	// li r6,4
	ctx.r6.s64 = 4;
	// lbz r9,86(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 86);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,5
	ctx.r4.s64 = 5;
	// sth r11,70(r31)
	REX_STORE_U16(ctx.r31.u32 + 70, ctx.r11.u16);
	// li r3,3
	ctx.r3.s64 = 3;
	// sth r8,76(r31)
	REX_STORE_U16(ctx.r31.u32 + 76, ctx.r8.u16);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// sth r10,74(r31)
	REX_STORE_U16(ctx.r31.u32 + 74, ctx.r10.u16);
	// sth r9,72(r31)
	REX_STORE_U16(ctx.r31.u32 + 72, ctx.r9.u16);
	// bl 0x82872cec
	ctx.lr = 0x8265DA60;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8265d95c
	if (ctx.cr0.lt) goto loc_8265D95C;
	// addi r3,r31,152
	ctx.r3.s64 = ctx.r31.s64 + 152;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82756d30
	ctx.lr = 0x8265DA78;
	sub_82756D30(ctx, base);
	// lbz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 88);
	// lbz r8,91(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 91);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lbz r10,89(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 89);
	// li r6,4
	ctx.r6.s64 = 4;
	// lbz r9,90(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 90);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// sth r11,154(r31)
	REX_STORE_U16(ctx.r31.u32 + 154, ctx.r11.u16);
	// li r3,3
	ctx.r3.s64 = 3;
	// sth r8,160(r31)
	REX_STORE_U16(ctx.r31.u32 + 160, ctx.r8.u16);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// sth r10,158(r31)
	REX_STORE_U16(ctx.r31.u32 + 158, ctx.r10.u16);
	// sth r9,156(r31)
	REX_STORE_U16(ctx.r31.u32 + 156, ctx.r9.u16);
	// bl 0x82872cec
	ctx.lr = 0x8265DAB4;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8265d95c
	if (ctx.cr0.lt) goto loc_8265D95C;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x82872cec
	ctx.lr = 0x8265DADC;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8265d95c
	if (ctx.cr0.lt) goto loc_8265D95C;
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// beq cr6,0x8265db24
	if (ctx.cr6.eq) goto loc_8265DB24;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// li r4,12
	ctx.r4.s64 = 12;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82872cec
	ctx.lr = 0x8265DB0C;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8265d95c
	if (ctx.cr0.lt) goto loc_8265D95C;
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwinm r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_8265DB24:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8265DB28:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82668748) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x82668750;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// mr r23,r10
	ctx.r23.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82668788
	if (!ctx.cr6.eq) goto loc_82668788;
	// li r31,50
	ctx.r31.s64 = 50;
	// b 0x826687d4
	goto loc_826687D4;
loc_82668788:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82668794
	if (!ctx.cr6.eq) goto loc_82668794;
	// li r31,18
	ctx.r31.s64 = 18;
loc_82668794:
	// clrlwi r10,r26,16
	ctx.r10.u64 = ctx.r26.u32 & 0xFFFF;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bgt cr6,0x826687d0
	if (ctx.cr6.gt) goto loc_826687D0;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x826687d0
	if (!ctx.cr6.eq) goto loc_826687D0;
	// clrlwi. r10,r27,16
	ctx.r10.u64 = ctx.r27.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x826687bc
	if (ctx.cr0.eq) goto loc_826687BC;
	// clrlwi r9,r28,16
	ctx.r9.u64 = ctx.r28.u32 & 0xFFFF;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x826687d0
	if (!ctx.cr6.eq) goto loc_826687D0;
loc_826687BC:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x826687d4
	if (!ctx.cr6.eq) goto loc_826687D4;
	// clrlwi r11,r28,16
	ctx.r11.u64 = ctx.r28.u32 & 0xFFFF;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// ble cr6,0x826687d4
	if (!ctx.cr6.gt) goto loc_826687D4;
loc_826687D0:
	// li r31,40
	ctx.r31.s64 = 40;
loc_826687D4:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,16192
	ctx.r3.s64 = ctx.r11.s64 + 16192;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8265e530
	ctx.lr = 0x826687F0;
	sub_8265E530(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82668820
	if (ctx.cr0.eq) goto loc_82668820;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// sth r23,86(r1)
	REX_STORE_U16(ctx.r1.u32 + 86, ctx.r23.u16);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82668588
	ctx.lr = 0x82668820;
	sub_82668588(ctx, base);
loc_82668820:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8266D6A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756690
	ctx.lr = 0x8266D6A8;
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
	// beq cr6,0x8266d6e0
	if (ctx.cr6.eq) goto loc_8266D6E0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8266d728
	goto loc_8266D728;
loc_8266D6E0:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// blt cr6,0x8266d714
	if (ctx.cr6.lt) goto loc_8266D714;
	// cmplwi cr6,r30,64
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 64, ctx.xer);
	// bgt cr6,0x8266d714
	if (ctx.cr6.gt) goto loc_8266D714;
	// cmplwi cr6,r27,1
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 1, ctx.xer);
	// blt cr6,0x8266d714
	if (ctx.cr6.lt) goto loc_8266D714;
	// cmplwi cr6,r27,64
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 64, ctx.xer);
	// bgt cr6,0x8266d714
	if (ctx.cr6.gt) goto loc_8266D714;
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8266d730
	if (ctx.cr6.eq) goto loc_8266D730;
	// cmpwi cr6,r18,3
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 3, ctx.xer);
	// beq cr6,0x8266d730
	if (ctx.cr6.eq) goto loc_8266D730;
loc_8266D714:
	// lis r25,-30569
	ctx.r25.s64 = -2003369984;
	// ori r25,r25,1
	ctx.r25.u64 = ctx.r25.u64 | 1;
loc_8266D71C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8266d4d8
	ctx.lr = 0x8266D724;
	sub_8266D4D8(ctx, base);
loc_8266D724:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
loc_8266D728:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x827566e0
	__restgprlr_18(ctx, base);
	return;
loc_8266D730:
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
	// ble cr6,0x8266d758
	if (!ctx.cr6.gt) goto loc_8266D758;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_8266D758:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,8343
	ctx.r10.s64 = 546766848;
	// addi r29,r11,16192
	ctx.r29.s64 = ctx.r11.s64 + 16192;
	// ori r28,r10,10
	ctx.r28.u64 = ctx.r10.u64 | 10;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8265e530
	ctx.lr = 0x8266D778;
	sub_8265E530(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// beq 0x8266d874
	if (ctx.cr0.eq) goto loc_8266D874;
	// cmplw cr6,r19,r26
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r19,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8266d794
	if (!ctx.cr6.gt) goto loc_8266D794;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_8266D794:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x8265e530
	ctx.lr = 0x8266D7A4;
	sub_8265E530(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r3.u32);
	// beq 0x8266d874
	if (ctx.cr0.eq) goto loc_8266D874;
	// cmplw cr6,r19,r26
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r19,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8266d7c0
	if (!ctx.cr6.gt) goto loc_8266D7C0;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_8266D7C0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x8265e530
	ctx.lr = 0x8266D7D0;
	sub_8265E530(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r3.u32);
	// beq 0x8266d874
	if (ctx.cr0.eq) goto loc_8266D874;
	// cmplw cr6,r19,r26
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r19,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8266d7ec
	if (!ctx.cr6.gt) goto loc_8266D7EC;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_8266D7EC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x8265e530
	ctx.lr = 0x8266D7FC;
	sub_8265E530(ctx, base);
	// stw r3,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8266d874
	if (ctx.cr0.eq) goto loc_8266D874;
	// cmplw cr6,r19,r26
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r19,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8266d818
	if (!ctx.cr6.gt) goto loc_8266D818;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_8266D818:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x8265e530
	ctx.lr = 0x8266D828;
	sub_8265E530(ctx, base);
	// stw r3,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8266d874
	if (ctx.cr0.eq) goto loc_8266D874;
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8266d880
	if (ctx.cr6.eq) goto loc_8266D880;
	// lwz r11,292(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// mullw r11,r30,r11
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r11.s32);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8266d858
	if (!ctx.cr6.gt) goto loc_8266D858;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_8266D858:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x8265e530
	ctx.lr = 0x8266D868;
	sub_8265E530(ctx, base);
	// stw r3,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8266d880
	if (!ctx.cr0.eq) goto loc_8266D880;
loc_8266D874:
	// lis r25,-32761
	ctx.r25.s64 = -2147024896;
	// ori r25,r25,14
	ctx.r25.u64 = ctx.r25.u64 | 14;
	// b 0x8266d71c
	goto loc_8266D71C;
loc_8266D880:
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8266d8c4
	if (ctx.cr6.eq) goto loc_8266D8C4;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r30,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8266d89c
	if (!ctx.cr6.gt) goto loc_8266D89C;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_8266D89C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x8265e530
	ctx.lr = 0x8266D8AC;
	sub_8265E530(ctx, base);
	// stw r3,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8266d874
	if (ctx.cr0.eq) goto loc_8266D874;
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82756d30
	ctx.lr = 0x8266D8C4;
	sub_82756D30(ctx, base);
loc_8266D8C4:
	// lwz r11,260(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8266d908
	if (ctx.cr6.eq) goto loc_8266D908;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// rlwinm r4,r30,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8266d8e0
	if (!ctx.cr6.gt) goto loc_8266D8E0;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
loc_8266D8E0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x8265e530
	ctx.lr = 0x8266D8F0;
	sub_8265E530(ctx, base);
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8266d874
	if (ctx.cr0.eq) goto loc_8266D874;
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82756d30
	ctx.lr = 0x8266D908;
	sub_82756D30(ctx, base);
loc_8266D908:
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
	// bne cr6,0x8266d930
	if (!ctx.cr6.eq) goto loc_8266D930;
	// clrlwi r3,r30,16
	ctx.r3.u64 = ctx.r30.u32 & 0xFFFF;
	// bl 0x82667b78
	ctx.lr = 0x8266D92C;
	sub_82667B78(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
loc_8266D930:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// bne cr6,0x8266d944
	if (!ctx.cr6.eq) goto loc_8266D944;
	// clrlwi r3,r27,16
	ctx.r3.u64 = ctx.r27.u32 & 0xFFFF;
	// bl 0x82667b78
	ctx.lr = 0x8266D940;
	sub_82667B78(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8266D944:
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
	// bl 0x8266cec8
	ctx.lr = 0x8266D95C;
	sub_8266CEC8(ctx, base);
	// mr. r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// blt 0x8266d71c
	if (ctx.cr0.lt) goto loc_8266D71C;
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
	// beq cr6,0x8266d984
	if (ctx.cr6.eq) goto loc_8266D984;
	// li r29,4
	ctx.r29.s64 = 4;
	// li r28,4
	ctx.r28.s64 = 4;
loc_8266D984:
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8266da0c
	if (!ctx.cr6.eq) goto loc_8266DA0C;
	// ori r29,r29,3
	ctx.r29.u64 = ctx.r29.u64 | 3;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8266da0c
	if (ctx.cr6.eq) goto loc_8266DA0C;
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
loc_8266D9AC:
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8266d9fc
	if (ctx.cr6.eq) goto loc_8266D9FC;
	// lwz r9,128(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_8266D9C4:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8266d9e0
	if (ctx.cr6.eq) goto loc_8266D9E0;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x8266d9f0
	if (ctx.cr6.eq) goto loc_8266D9F0;
	// rlwinm r29,r29,0,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFFFFC;
	// b 0x8266d9f0
	goto loc_8266D9F0;
loc_8266D9E0:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// beq cr6,0x8266d9f0
	if (ctx.cr6.eq) goto loc_8266D9F0;
	// rlwinm r29,r29,0,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFFFFE;
loc_8266D9F0:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8266d9c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8266D9C4;
loc_8266D9FC:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// add r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 + ctx.r10.u64;
	// cmplw cr6,r8,r27
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x8266d9ac
	if (ctx.cr6.lt) goto loc_8266D9AC;
loc_8266DA0C:
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
	// bne cr6,0x8266db78
	if (!ctx.cr6.eq) goto loc_8266DB78;
	// cmplwi cr6,r21,4
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 4, ctx.xer);
	// bne cr6,0x8266dab4
	if (!ctx.cr6.eq) goto loc_8266DAB4;
	// cmplwi cr6,r20,32
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 32, ctx.xer);
	// bne cr6,0x8266da5c
	if (!ctx.cr6.eq) goto loc_8266DA5C;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x826839c8
	ctx.lr = 0x8266DA3C;
	sub_826839C8(ctx, base);
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
	// bl 0x826839c8
	ctx.lr = 0x8266DA54;
	sub_826839C8(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x8266db40
	goto loc_8266DB40;
loc_8266DA5C:
	// cmplwi cr6,r20,24
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 24, ctx.xer);
	// bne cr6,0x8266da8c
	if (!ctx.cr6.eq) goto loc_8266DA8C;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x826839c8
	ctx.lr = 0x8266DA6C;
	sub_826839C8(ctx, base);
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
	// bl 0x826839c8
	ctx.lr = 0x8266DA84;
	sub_826839C8(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x8266db40
	goto loc_8266DB40;
loc_8266DA8C:
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x826839c8
	ctx.lr = 0x8266DA94;
	sub_826839C8(ctx, base);
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
	// bl 0x826839c8
	ctx.lr = 0x8266DAAC;
	sub_826839C8(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x8266db40
	goto loc_8266DB40;
loc_8266DAB4:
	// cmplwi cr6,r21,3
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 3, ctx.xer);
	// bne cr6,0x8266db14
	if (!ctx.cr6.eq) goto loc_8266DB14;
	// cmplwi cr6,r20,24
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 24, ctx.xer);
	// bne cr6,0x8266daec
	if (!ctx.cr6.eq) goto loc_8266DAEC;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x826839c8
	ctx.lr = 0x8266DACC;
	sub_826839C8(ctx, base);
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
	// bl 0x826839c8
	ctx.lr = 0x8266DAE4;
	sub_826839C8(ctx, base);
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x8266db40
	goto loc_8266DB40;
loc_8266DAEC:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x826839c8
	ctx.lr = 0x8266DAF4;
	sub_826839C8(ctx, base);
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
	// bl 0x826839c8
	ctx.lr = 0x8266DB0C;
	sub_826839C8(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x8266db40
	goto loc_8266DB40;
loc_8266DB14:
	// cmplwi cr6,r21,2
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 2, ctx.xer);
	// bne cr6,0x8266db4c
	if (!ctx.cr6.eq) goto loc_8266DB4C;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x826839c8
	ctx.lr = 0x8266DB24;
	sub_826839C8(ctx, base);
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
	// bl 0x826839c8
	ctx.lr = 0x8266DB3C;
	sub_826839C8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
loc_8266DB40:
	// stw r3,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r3.u32);
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// b 0x8266dbc4
	goto loc_8266DBC4;
loc_8266DB4C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x826839c8
	ctx.lr = 0x8266DB54;
	sub_826839C8(ctx, base);
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
	// bl 0x826839c8
	ctx.lr = 0x8266DB6C;
	sub_826839C8(ctx, base);
	// stw r3,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r3.u32);
	// stw r26,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r26.u32);
	// b 0x8266dbc4
	goto loc_8266DBC4;
loc_8266DB78:
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x826839c8
	ctx.lr = 0x8266DB80;
	sub_826839C8(ctx, base);
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
	// bl 0x826839c8
	ctx.lr = 0x8266DB98;
	sub_826839C8(ctx, base);
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
	// beq cr6,0x8266dbbc
	if (ctx.cr6.eq) goto loc_8266DBBC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82687b68
	ctx.lr = 0x8266DBB8;
	sub_82687B68(ctx, base);
	// stw r3,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r3.u32);
loc_8266DBBC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
loc_8266DBC4:
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
	// bl 0x827567d0
	ctx.lr = 0x8266DC14;
	sub_827567D0(ctx, base);
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
	// bl 0x827567d0
	ctx.lr = 0x8266DC4C;
	sub_827567D0(ctx, base);
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
	// b 0x8266d724
	goto loc_8266D724;
}

DEFINE_REX_FUNC(sub_8267DB30) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x8267d938
	sub_8267D938(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826A0DA8) {
	REX_FUNC_PROLOGUE();
	// lwz r10,184(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 184);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x826a0dfc
	if (ctx.cr6.eq) goto loc_826A0DFC;
	// lwz r11,28(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// beq cr6,0x826a0e4c
	if (ctx.cr6.eq) goto loc_826A0E4C;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r9,192(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 192);
	// lwz r7,188(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 188);
	// lwz r8,28(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// lwz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// mullw r9,r8,r9
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r8,16(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// subf r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x826a0e50
	if (ctx.cr6.eq) goto loc_826A0E50;
loc_826A0DFC:
	// lwz r9,168(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 168);
	// b 0x826a0e40
	goto loc_826A0E40;
loc_826A0E04:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x826a0e1c
	if (ctx.cr6.eq) goto loc_826A0E1C;
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x826a0e20
	goto loc_826A0E20;
loc_826A0E1C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_826A0E20:
	// lwz r7,32(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// cmplwi cr6,r7,255
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 255, ctx.xer);
	// beq cr6,0x826a0e4c
	if (ctx.cr6.eq) goto loc_826A0E4C;
	// lwz r6,28(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// lwz r8,20(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// mullw r10,r6,r7
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_826A0E40:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x826a0e04
	if (!ctx.cr6.eq) goto loc_826A0E04;
	// b 0x826a0e50
	goto loc_826A0E50;
loc_826A0E4C:
	// li r11,-1
	ctx.r11.s64 = -1;
loc_826A0E50:
	// lwz r10,120(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 120);
	// lhz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// mullw r10,r10,r4
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// subf r5,r11,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r11.u64;
	// bgt cr6,0x826a0e6c
	if (ctx.cr6.gt) goto loc_826A0E6C;
	// li r5,0
	ctx.r5.s64 = 0;
loc_826A0E6C:
	// lwz r3,264(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_826AB418) {
	REX_FUNC_PROLOGUE();
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_826AB590) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r4,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// addi r9,r3,16
	ctx.r9.s64 = ctx.r3.s64 + 16;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r10,10800
	ctx.r8.s64 = ctx.r10.s64 + 10800;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r9,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// addi r9,r3,56
	ctx.r9.s64 = ctx.r3.s64 + 56;
	// stw r11,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// addi r5,r6,10848
	ctx.r5.s64 = ctx.r6.s64 + 10848;
	// stw r11,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// addi r8,r9,8
	ctx.r8.s64 = ctx.r9.s64 + 8;
	// stw r11,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r10,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r9,r7,4
	ctx.r9.s64 = ctx.r7.s64 + 4;
	// lwz r4,16(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// stw r4,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, ctx.r4.u32);
	// stw r9,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// stw r11,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r11.u32);
	// stw r11,80(r3)
	REX_STORE_U32(ctx.r3.u32 + 80, ctx.r11.u32);
	// stw r11,84(r3)
	REX_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
	// stw r11,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// stw r8,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r8.u32);
	// stw r10,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r10.u32);
	// stw r11,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lwz r9,56(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r11,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r11.u32);
	// stw r10,96(r3)
	REX_STORE_U32(ctx.r3.u32 + 96, ctx.r10.u32);
	// lwz r11,10848(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 10848);
	// stw r11,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
	// lwz r11,4(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// stw r11,104(r3)
	REX_STORE_U32(ctx.r3.u32 + 104, ctx.r11.u32);
	// lwz r11,8(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// stw r11,108(r3)
	REX_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// lwz r11,12(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// stw r10,116(r3)
	REX_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// stw r11,112(r3)
	REX_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_826B0D38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756698
	ctx.lr = 0x826B0D40;
	__savegprlr_20(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r24,28(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// addi r22,r4,-24
	ctx.r22.s64 = ctx.r4.s64 + -24;
	// stw r30,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r22,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r22.u32);
	// sth r30,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r30.u16);
	// bctrl
	ctx.lr = 0x826B0D80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// lhz r10,54(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 54);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826b0db4
	if (!ctx.cr6.gt) goto loc_826B0DB4;
loc_826B0DA0:
	// lis r31,-32688
	ctx.r31.s64 = -2142240768;
	// ori r31,r31,12
	ctx.r31.u64 = ctx.r31.u64 | 12;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x827566e8
	__restgprlr_20(ctx, base);
	return;
loc_826B0DB4:
	// cmplwi cr6,r22,2
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 2, ctx.xer);
	// blt cr6,0x826b0da0
	if (ctx.cr6.lt) goto loc_826B0DA0;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x826ad498
	ctx.lr = 0x826B0DD4;
	sub_826AD498(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// lhz r28,80(r1)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// li r27,2
	ctx.r27.s64 = 2;
	// mr r21,r28
	ctx.r21.u64 = ctx.r28.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x826b0e40
	if (!ctx.cr6.eq) goto loc_826B0E40;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subf r10,r11,r22
	ctx.r10.u64 = ctx.r22.u64 - ctx.r11.u64;
	// addic. r30,r10,-2
	ctx.xer.ca = ctx.r10.u32 > 1;
	ctx.r30.s64 = ctx.r10.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x826b1138
	if (ctx.cr0.eq) goto loc_826B1138;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x826B0E1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// ld r11,8(r24)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r24.u32 + 8);
	// clrldi r10,r30,32
	ctx.r10.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// std r11,8(r24)
	REX_STORE_U64(ctx.r24.u32 + 8, ctx.r11.u64);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x827566e8
	__restgprlr_20(ctx, base);
	return;
loc_826B0E40:
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r3,224(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 224);
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x826abc58
	ctx.lr = 0x826B0E54;
	sub_826ABC58(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// rlwinm r11,r21,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r30,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// add r9,r21,r11
	ctx.r9.u64 = ctx.r21.u64 + ctx.r11.u64;
	// rlwinm r29,r9,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r8,4(r24)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// lwz r7,96(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// stw r7,96(r8)
	REX_STORE_U32(ctx.r8.u32 + 96, ctx.r7.u32);
	// lwz r6,96(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// sth r28,0(r6)
	REX_STORE_U16(ctx.r6.u32 + 0, ctx.r28.u16);
	// lwz r3,224(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 224);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// bl 0x826abc58
	ctx.lr = 0x826B0EA8;
	sub_826ABC58(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x82756d30
	ctx.lr = 0x826B0EC8;
	sub_82756D30(ctx, base);
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r20,r30
	ctx.r20.u64 = ctx.r30.u64;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// lwz r26,4(r10)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// beq cr6,0x826b10e4
	if (ctx.cr6.eq) goto loc_826B10E4;
loc_826B0EDC:
	// addi r27,r27,12
	ctx.r27.s64 = ctx.r27.s64 + 12;
	// cmplw cr6,r27,r22
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r22.u32, ctx.xer);
	// bgt cr6,0x826b0da0
	if (ctx.cr6.gt) goto loc_826B0DA0;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x826ad498
	ctx.lr = 0x826B0F00;
	sub_826AD498(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// addi r30,r26,6
	ctx.r30.s64 = ctx.r26.s64 + 6;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r30,-4
	ctx.r4.s64 = ctx.r30.s64 + -4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x826ad498
	ctx.lr = 0x826B0F28;
	sub_826AD498(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// addi r28,r26,4
	ctx.r28.s64 = ctx.r26.s64 + 4;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x826ad498
	ctx.lr = 0x826B0F50;
	sub_826AD498(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x826ad498
	ctx.lr = 0x826B0F74;
	sub_826AD498(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// addi r25,r26,8
	ctx.r25.s64 = ctx.r26.s64 + 8;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x826ad618
	ctx.lr = 0x826B0F9C;
	sub_826AD618(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// lhz r5,0(r28)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x826b1058
	if (ctx.cr6.eq) goto loc_826B1058;
	// addi r30,r26,12
	ctx.r30.s64 = ctx.r26.s64 + 12;
	// lwz r3,224(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 224);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// bl 0x826abc58
	ctx.lr = 0x826B0FC8;
	sub_826ABC58(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r5,0(r28)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82756d30
	ctx.lr = 0x826B0FE4;
	sub_82756D30(ctx, base);
	// lhz r5,0(r28)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// add r29,r27,r5
	ctx.r29.u64 = ctx.r27.u64 + ctx.r5.u64;
	// cmplw cr6,r29,r22
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r22.u32, ctx.xer);
	// bgt cr6,0x826b0da0
	if (ctx.cr6.gt) goto loc_826B0DA0;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x826adb30
	ctx.lr = 0x826B100C;
	sub_826ADB30(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// lwz r11,76(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 76);
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826b1058
	if (ctx.cr6.eq) goto loc_826B1058;
	// lhz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826b1058
	if (!ctx.cr6.gt) goto loc_826B1058;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_826B1044:
	// lbz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// stb r10,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// stbu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x826b1044
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826B1044;
loc_826B1058:
	// lwz r5,0(r25)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x826b10cc
	if (ctx.cr6.eq) goto loc_826B10CC;
	// addi r30,r26,16
	ctx.r30.s64 = ctx.r26.s64 + 16;
	// lwz r3,224(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 224);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// bl 0x826abc58
	ctx.lr = 0x826B1078;
	sub_826ABC58(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,0(r25)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82756d30
	ctx.lr = 0x826B1094;
	sub_82756D30(ctx, base);
	// lwz r5,0(r25)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// add r29,r27,r5
	ctx.r29.u64 = ctx.r27.u64 + ctx.r5.u64;
	// cmplw cr6,r29,r22
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r22.u32, ctx.xer);
	// bgt cr6,0x826b0da0
	if (ctx.cr6.gt) goto loc_826B0DA0;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x826adb30
	ctx.lr = 0x826B10BC;
	sub_826ADB30(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
loc_826B10CC:
	// clrlwi r11,r20,16
	ctx.r11.u64 = ctx.r20.u32 & 0xFFFF;
	// addi r26,r26,20
	ctx.r26.s64 = ctx.r26.s64 + 20;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r20,r11,16
	ctx.r20.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplw cr6,r20,r21
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, ctx.r21.u32, ctx.xer);
	// blt cr6,0x826b0edc
	if (ctx.cr6.lt) goto loc_826B0EDC;
loc_826B10E4:
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// lhz r10,54(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 54);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// sth r9,54(r11)
	REX_STORE_U16(ctx.r11.u32 + 54, ctx.r9.u16);
	// lwz r7,84(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subf r6,r7,r22
	ctx.r6.u64 = ctx.r22.u64 - ctx.r7.u64;
	// subf. r30,r27,r6
	ctx.r30.u64 = ctx.r6.u64 - ctx.r27.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x826b1138
	if (ctx.cr0.eq) goto loc_826B1138;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x826B111C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b1138
	if (ctx.cr6.lt) goto loc_826B1138;
	// ld r10,8(r24)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r24.u32 + 8);
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// std r11,8(r24)
	REX_STORE_U64(ctx.r24.u32 + 8, ctx.r11.u64);
loc_826B1138:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x827566e8
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826DE0A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x826DE0A8;
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
	// bl 0x82756d30
	ctx.lr = 0x826DE0C8;
	sub_82756D30(ctx, base);
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
	// bl 0x82659d20
	ctx.lr = 0x826DE0EC;
	sub_82659D20(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x826de108
	if (!ctx.cr6.eq) goto loc_826DE108;
loc_826DE0FC:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
loc_826DE108:
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
	// bl 0x82756d30
	ctx.lr = 0x826DE120;
	sub_82756D30(ctx, base);
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
	// bl 0x82659d20
	ctx.lr = 0x826DE14C;
	sub_82659D20(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826de0fc
	if (ctx.cr6.eq) goto loc_826DE0FC;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x82756d30
	ctx.lr = 0x826DE168;
	sub_82756D30(ctx, base);
	// srawi r25,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r25.s64 = ctx.r29.s32 >> 1;
	// add r10,r25,r30
	ctx.r10.u64 = ctx.r25.u64 + ctx.r30.u64;
	// clrlwi r11,r10,27
	ctx.r11.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826de180
	if (ctx.cr6.eq) goto loc_826DE180;
	// subfic r11,r11,32
	ctx.xer.ca = ctx.r11.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
loc_826DE180:
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
	// bl 0x82659d20
	ctx.lr = 0x826DE19C;
	sub_82659D20(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826de0fc
	if (ctx.cr6.eq) goto loc_826DE0FC;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x82756d30
	ctx.lr = 0x826DE1B8;
	sub_82756D30(ctx, base);
	// add r10,r25,r30
	ctx.r10.u64 = ctx.r25.u64 + ctx.r30.u64;
	// clrlwi r11,r10,27
	ctx.r11.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826de1cc
	if (ctx.cr6.eq) goto loc_826DE1CC;
	// subfic r11,r11,32
	ctx.xer.ca = ctx.r11.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
loc_826DE1CC:
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
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826E4168) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756680
	ctx.lr = 0x826E4170;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r14,r6
	ctx.r14.u64 = ctx.r6.u64;
	// lwz r11,224(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 224);
	// lwz r9,3744(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 3744);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r8,3748(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 3748);
	// mr r19,r4
	ctx.r19.u64 = ctx.r4.u64;
	// lwz r7,3752(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 3752);
	// mr r16,r5
	ctx.r16.u64 = ctx.r5.u64;
	// lwz r6,15932(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 15932);
	// add r20,r8,r11
	ctx.r20.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r10,220(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 220);
	// add r17,r7,r11
	ctx.r17.u64 = ctx.r7.u64 + ctx.r11.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// add r25,r9,r10
	ctx.r25.u64 = ctx.r9.u64 + ctx.r10.u64;
	// beq cr6,0x826e4250
	if (ctx.cr6.eq) goto loc_826E4250;
	// lwz r11,20640(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20640);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826e4250
	if (!ctx.cr6.eq) goto loc_826E4250;
	// lwz r10,3728(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 3728);
	// li r8,1
	ctx.r8.s64 = 1;
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
	// lwz r6,3712(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 3712);
	// stw r6,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r6.u32);
	// lwz r5,200(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 200);
	// stw r5,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r5.u32);
	// lwz r4,204(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// stw r4,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r4.u32);
	// lwz r3,208(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 208);
	// stw r3,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r3.u32);
	// lwz r10,220(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// stw r10,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// lwz r9,224(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// stw r9,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r9.u32);
	// lwz r8,136(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// stw r8,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r8.u32);
	// lwz r7,140(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// stw r7,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r7.u32);
	// lwz r6,248(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stw r6,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r6.u32);
	// lwz r5,228(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// stw r5,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r5.u32);
	// lwz r4,232(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// stw r4,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r4.u32);
	// lwz r3,15544(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15544);
	// stw r3,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r3.u32);
	// stw r19,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r19.u32);
	// stw r16,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r16.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x827566d0
	__restgprlr_14(ctx, base);
	return;
loc_826E4250:
	// lwz r11,3712(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3712);
	// mr r27,r19
	ctx.r27.u64 = ctx.r19.u64;
	// lwz r10,3728(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3728);
	// cmplw cr6,r19,r16
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r16.u32, ctx.xer);
	// lwz r9,608(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 608);
	// stw r9,608(r10)
	REX_STORE_U32(ctx.r10.u32 + 608, ctx.r9.u32);
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// lwz r6,232(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// lwz r8,3808(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r10,220(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// lwz r9,3800(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// add r26,r10,r9
	ctx.r26.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r7,228(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// add r18,r8,r11
	ctx.r18.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r10,3804(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// add r22,r11,r10
	ctx.r22.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r15,204(r31)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r21,208(r31)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bge cr6,0x826e4350
	if (!ctx.cr6.lt) goto loc_826E4350;
	// lis r24,-32108
	ctx.r24.s64 = -2104229888;
	// lis r23,-32108
	ctx.r23.s64 = -2104229888;
loc_826E42AC:
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// bne cr6,0x826e42bc
	if (!ctx.cr6.eq) goto loc_826E42BC;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
loc_826E42BC:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x826e4330
	if (!ctx.cr6.gt) goto loc_826E4330;
loc_826E42D0:
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// bne cr6,0x826e42f4
	if (!ctx.cr6.eq) goto loc_826E42F4;
	// lwz r11,-10332(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + -10332);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,204(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x826E42F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_826E42F4:
	// lwz r11,-10320(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -10320);
	// mr r8,r15
	ctx.r8.u64 = ctx.r15.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lwz r7,248(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x826E4318;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,16
	ctx.r29.s64 = ctx.r29.s64 + 16;
	// addi r28,r28,16
	ctx.r28.s64 = ctx.r28.s64 + 16;
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x826e42d0
	if (ctx.cr6.lt) goto loc_826E42D0;
loc_826E4330:
	// lwz r11,228(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r26,r10,r26
	ctx.r26.u64 = ctx.r10.u64 + ctx.r26.u64;
	// cmplw cr6,r27,r16
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r16.u32, ctx.xer);
	// blt cr6,0x826e42ac
	if (ctx.cr6.lt) goto loc_826E42AC;
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_826E4350:
	// lis r26,-32108
	ctx.r26.s64 = -2104229888;
	// lis r25,-32108
	ctx.r25.s64 = -2104229888;
	// mr r27,r19
	ctx.r27.u64 = ctx.r19.u64;
	// cmplw cr6,r19,r16
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r16.u32, ctx.xer);
	// bge cr6,0x826e4404
	if (!ctx.cr6.lt) goto loc_826E4404;
loc_826E4364:
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
	// bne cr6,0x826e4374
	if (!ctx.cr6.eq) goto loc_826E4374;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
loc_826E4374:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mr r28,r20
	ctx.r28.u64 = ctx.r20.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x826e43e8
	if (!ctx.cr6.gt) goto loc_826E43E8;
loc_826E4388:
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// bne cr6,0x826e43ac
	if (!ctx.cr6.eq) goto loc_826E43AC;
	// lwz r11,-10328(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -10328);
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,208(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x826E43AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_826E43AC:
	// lwz r11,-10324(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -10324);
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lwz r7,248(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x826E43D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// addi r28,r28,8
	ctx.r28.s64 = ctx.r28.s64 + 8;
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x826e4388
	if (ctx.cr6.lt) goto loc_826E4388;
loc_826E43E8:
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r20,r11,r20
	ctx.r20.u64 = ctx.r11.u64 + ctx.r20.u64;
	// add r22,r6,r22
	ctx.r22.u64 = ctx.r6.u64 + ctx.r22.u64;
	// cmplw cr6,r27,r16
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r16.u32, ctx.xer);
	// blt cr6,0x826e4364
	if (ctx.cr6.lt) goto loc_826E4364;
loc_826E4404:
	// mr r27,r19
	ctx.r27.u64 = ctx.r19.u64;
	// cmplw cr6,r19,r16
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r16.u32, ctx.xer);
	// bge cr6,0x826e44b0
	if (!ctx.cr6.lt) goto loc_826E44B0;
loc_826E4410:
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// mr r29,r17
	ctx.r29.u64 = ctx.r17.u64;
	// bne cr6,0x826e4420
	if (!ctx.cr6.eq) goto loc_826E4420;
	// mr r29,r18
	ctx.r29.u64 = ctx.r18.u64;
loc_826E4420:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mr r28,r17
	ctx.r28.u64 = ctx.r17.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x826e4494
	if (!ctx.cr6.gt) goto loc_826E4494;
loc_826E4434:
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// bne cr6,0x826e4458
	if (!ctx.cr6.eq) goto loc_826E4458;
	// lwz r11,-10328(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + -10328);
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,208(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x826E4458;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_826E4458:
	// lwz r11,-10324(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -10324);
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lwz r7,248(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x826E447C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// addi r28,r28,8
	ctx.r28.s64 = ctx.r28.s64 + 8;
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x826e4434
	if (ctx.cr6.lt) goto loc_826E4434;
loc_826E4494:
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r17,r11,r17
	ctx.r17.u64 = ctx.r11.u64 + ctx.r17.u64;
	// add r18,r6,r18
	ctx.r18.u64 = ctx.r6.u64 + ctx.r18.u64;
	// cmplw cr6,r27,r16
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r16.u32, ctx.xer);
	// blt cr6,0x826e4410
	if (ctx.cr6.lt) goto loc_826E4410;
loc_826E44B0:
	// lwz r11,15544(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15544);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826e4594
	if (ctx.cr6.eq) goto loc_826E4594;
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// mr r27,r19
	ctx.r27.u64 = ctx.r19.u64;
	// lwz r8,220(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// cmplw cr6,r19,r16
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r16.u32, ctx.xer);
	// lwz r7,3800(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// lwz r9,3804(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// lwz r10,3808(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// add r24,r8,r7
	ctx.r24.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r25,r11,r9
	ctx.r25.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r23,r11,r10
	ctx.r23.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bge cr6,0x826e4594
	if (!ctx.cr6.lt) goto loc_826E4594;
	// lis r22,-32108
	ctx.r22.s64 = -2104229888;
loc_826E44EC:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826e4578
	if (ctx.cr6.eq) goto loc_826E4578;
	// subf r26,r25,r23
	ctx.r26.u64 = ctx.r23.u64 - ctx.r25.u64;
loc_826E4508:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x826e455c
	if (ctx.cr6.eq) goto loc_826E455C;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x826e455c
	if (ctx.cr6.eq) goto loc_826E455C;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x826e455c
	if (ctx.cr6.eq) goto loc_826E455C;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x826e455c
	if (ctx.cr6.eq) goto loc_826E455C;
	// lwz r11,-10356(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + -10356);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// lwz r6,248(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// mr r7,r15
	ctx.r7.u64 = ctx.r15.u64;
	// add r5,r26,r30
	ctx.r5.u64 = ctx.r26.u64 + ctx.r30.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x826E455C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_826E455C:
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,16
	ctx.r29.s64 = ctx.r29.s64 + 16;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x826e4508
	if (ctx.cr6.lt) goto loc_826E4508;
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_826E4578:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// add r25,r6,r25
	ctx.r25.u64 = ctx.r6.u64 + ctx.r25.u64;
	// add r24,r11,r24
	ctx.r24.u64 = ctx.r11.u64 + ctx.r24.u64;
	// add r23,r6,r23
	ctx.r23.u64 = ctx.r6.u64 + ctx.r23.u64;
	// cmplw cr6,r27,r16
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r16.u32, ctx.xer);
	// blt cr6,0x826e44ec
	if (ctx.cr6.lt) goto loc_826E44EC;
loc_826E4594:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x827566d0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82708360) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756680
	ctx.lr = 0x82708368;
	__savegprlr_14(ctx, base);
	// li r12,-176
	ctx.r12.s64 = -176;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r8,248(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r23,128(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 128);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lwz r7,228(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// extsh r5,r8
	ctx.r5.s64 = ctx.r8.s16;
	// lwz r10,132(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// lwz r24,112(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 112);
	// srawi r21,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r7.s32 >> 1;
	// rlwinm r6,r23,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r5,112(r1)
	REX_STORE_U16(ctx.r1.u32 + 112, ctx.r5.u16);
	// addi r20,r10,-1
	ctx.r20.s64 = ctx.r10.s64 + -1;
	// sth r5,114(r1)
	REX_STORE_U16(ctx.r1.u32 + 114, ctx.r5.u16);
	// sth r5,116(r1)
	REX_STORE_U16(ctx.r1.u32 + 116, ctx.r5.u16);
	// mr r14,r3
	ctx.r14.u64 = ctx.r3.u64;
	// sth r5,118(r1)
	REX_STORE_U16(ctx.r1.u32 + 118, ctx.r5.u16);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// sth r5,120(r1)
	REX_STORE_U16(ctx.r1.u32 + 120, ctx.r5.u16);
	// addi r29,r4,3
	ctx.r29.s64 = ctx.r4.s64 + 3;
	// sth r5,122(r1)
	REX_STORE_U16(ctx.r1.u32 + 122, ctx.r5.u16);
	// addic. r11,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r11.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// sth r5,124(r1)
	REX_STORE_U16(ctx.r1.u32 + 124, ctx.r5.u16);
	// sth r5,126(r1)
	REX_STORE_U16(ctx.r1.u32 + 126, ctx.r5.u16);
	// lvx128 v127,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,204(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// lwz r30,208(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 208);
	// stw r23,380(r1)
	REX_STORE_U32(ctx.r1.u32 + 380, ctx.r23.u32);
	// stw r21,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r21.u32);
	// stw r20,396(r1)
	REX_STORE_U32(ctx.r1.u32 + 396, ctx.r20.u32);
	// stw r24,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r24.u32);
	// ble 0x82708418
	if (!ctx.cr0.gt) goto loc_82708418;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
loc_827083F8:
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827042c0
	ctx.lr = 0x8270840C;
	sub_827042C0(ctx, base);
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// bne 0x827083f8
	if (!ctx.cr0.eq) goto loc_827083F8;
loc_82708418:
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r16,r26
	ctx.r16.u64 = ctx.r26.u64;
	// subfic r26,r11,-1
	ctx.xer.ca = ctx.r11.u32 <= 4294967295;
	ctx.r26.u64 = static_cast<uint64_t>(-1) - ctx.r11.u64;
	// li r17,0
	ctx.r17.s64 = 0;
	// stw r26,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r26.u32);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// ble cr6,0x82708664
	if (!ctx.cr6.gt) goto loc_82708664;
	// rlwinm r10,r31,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r24,r28
	ctx.r11.u64 = ctx.r24.u64 + ctx.r28.u64;
	// add r10,r10,r21
	ctx.r10.u64 = ctx.r10.u64 + ctx.r21.u64;
	// subf r9,r28,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r28.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r18,r26,-4
	ctx.r18.s64 = ctx.r26.s64 + -4;
	// add r15,r24,r27
	ctx.r15.u64 = ctx.r24.u64 + ctx.r27.u64;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// addi r19,r11,4
	ctx.r19.s64 = ctx.r11.s64 + 4;
loc_82708458:
	// add r29,r16,r21
	ctx.r29.u64 = ctx.r16.u64 + ctx.r21.u64;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// add r28,r11,r16
	ctx.r28.u64 = ctx.r11.u64 + ctx.r16.u64;
	// li r22,8
	ctx.r22.s64 = 8;
	// li r25,-4
	ctx.r25.s64 = -4;
	// bl 0x827040c0
	ctx.lr = 0x82708480;
	sub_827040C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r27,r29,8
	ctx.r27.s64 = ctx.r29.s64 + 8;
	// bl 0x827040c0
	ctx.lr = 0x82708498;
	sub_827040C0(ctx, base);
	// addi r26,r28,8
	ctx.r26.s64 = ctx.r28.s64 + 8;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// bne cr6,0x827084ac
	if (!ctx.cr6.eq) goto loc_827084AC;
	// li r25,-8
	ctx.r25.s64 = -8;
	// b 0x827084bc
	goto loc_827084BC;
loc_827084AC:
	// addi r11,r20,-1
	ctx.r11.s64 = ctx.r20.s64 + -1;
	// cmpw cr6,r17,r11
	ctx.cr6.compare<int32_t>(ctx.r17.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x827084c0
	if (!ctx.cr6.eq) goto loc_827084C0;
	// li r25,-4
	ctx.r25.s64 = -4;
loc_827084BC:
	// li r22,12
	ctx.r22.s64 = 12;
loc_827084C0:
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r19,-4
	ctx.r3.s64 = ctx.r19.s64 + -4;
	// bl 0x827040c0
	ctx.lr = 0x827084D4;
	sub_827040C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// mullw r11,r25,r30
	ctx.r11.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r30.s32);
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// mr r29,r19
	ctx.r29.u64 = ctx.r19.u64;
	// addi r23,r11,-1
	ctx.r23.s64 = ctx.r11.s64 + -1;
	// bl 0x827040c0
	ctx.lr = 0x827084F4;
	sub_827040C0(ctx, base);
	// lwz r11,380(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 380);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r25,r11,-1
	ctx.r25.s64 = ctx.r11.s64 + -1;
	// add r28,r19,r10
	ctx.r28.u64 = ctx.r19.u64 + ctx.r10.u64;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x827085dc
	if (!ctx.cr6.gt) goto loc_827085DC;
loc_8270850C:
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// add r24,r18,r27
	ctx.r24.u64 = ctx.r18.u64 + ctx.r27.u64;
	// add r21,r23,r29
	ctx.r21.u64 = ctx.r23.u64 + ctx.r29.u64;
	// add r20,r28,r23
	ctx.r20.u64 = ctx.r28.u64 + ctx.r23.u64;
	// bl 0x827040c0
	ctx.lr = 0x8270852C;
	sub_827040C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r27,r27,16
	ctx.r27.s64 = ctx.r27.s64 + 16;
	// bl 0x827040c0
	ctx.lr = 0x82708544;
	sub_827040C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r26,r26,16
	ctx.r26.s64 = ctx.r26.s64 + 16;
	// bl 0x827042c0
	ctx.lr = 0x8270855C;
	sub_827042C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827040c0
	ctx.lr = 0x82708570;
	sub_827040C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// bl 0x827040c0
	ctx.lr = 0x82708588;
	sub_827040C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// addi r28,r28,8
	ctx.r28.s64 = ctx.r28.s64 + 8;
	// bl 0x827042c0
	ctx.lr = 0x827085A0;
	sub_827042C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x827042c0
	ctx.lr = 0x827085B4;
	sub_827042C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r24,8
	ctx.r3.s64 = ctx.r24.s64 + 8;
	// bl 0x827042c0
	ctx.lr = 0x827085C8;
	sub_827042C0(ctx, base);
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne 0x8270850c
	if (!ctx.cr0.eq) goto loc_8270850C;
	// lwz r20,396(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 396);
	// lwz r21,88(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r24,92(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
loc_827085DC:
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827040c0
	ctx.lr = 0x827085F0;
	sub_827040C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x827040c0
	ctx.lr = 0x82708604;
	sub_827040C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// add r3,r18,r27
	ctx.r3.u64 = ctx.r18.u64 + ctx.r27.u64;
	// bl 0x827042c0
	ctx.lr = 0x82708618;
	sub_827042C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827040c0
	ctx.lr = 0x8270862C;
	sub_827040C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827040c0
	ctx.lr = 0x82708640;
	sub_827040C0(ctx, base);
	// lwz r11,100(r14)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r14.u32 + 100);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// add r19,r19,r24
	ctx.r19.u64 = ctx.r19.u64 + ctx.r24.u64;
	// add r15,r15,r24
	ctx.r15.u64 = ctx.r15.u64 + ctx.r24.u64;
	// cmpw cr6,r17,r20
	ctx.cr6.compare<int32_t>(ctx.r17.s32, ctx.r20.s32, ctx.xer);
	// add r16,r16,r11
	ctx.r16.u64 = ctx.r16.u64 + ctx.r11.u64;
	// blt cr6,0x82708458
	if (ctx.cr6.lt) goto loc_82708458;
	// lwz r23,380(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 380);
	// lwz r26,96(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
loc_82708664:
	// add r30,r16,r21
	ctx.r30.u64 = ctx.r16.u64 + ctx.r21.u64;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827040c0
	ctx.lr = 0x8270867C;
	sub_827040C0(ctx, base);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x827086f8
	if (!ctx.cr6.gt) goto loc_827086F8;
	// addi r27,r23,-1
	ctx.r27.s64 = ctx.r23.s64 + -1;
	// addi r26,r26,-4
	ctx.r26.s64 = ctx.r26.s64 + -4;
loc_82708694:
	// add r28,r26,r30
	ctx.r28.u64 = ctx.r26.u64 + ctx.r30.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// cmpw cr6,r29,r27
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r27.s32, ctx.xer);
	// bne cr6,0x827086a8
	if (!ctx.cr6.eq) goto loc_827086A8;
	// li r5,8
	ctx.r5.s64 = 8;
loc_827086A8:
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827040c0
	ctx.lr = 0x827086B8;
	sub_827040C0(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// bl 0x827042c0
	ctx.lr = 0x827086D0;
	sub_827042C0(ctx, base);
	// cmpw cr6,r29,r27
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r27.s32, ctx.xer);
	// bge cr6,0x827086ec
	if (!ctx.cr6.lt) goto loc_827086EC;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r28,8
	ctx.r3.s64 = ctx.r28.s64 + 8;
	// bl 0x827042c0
	ctx.lr = 0x827086EC;
	sub_827042C0(ctx, base);
loc_827086EC:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r29,r23
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r23.s32, ctx.xer);
	// blt cr6,0x82708694
	if (ctx.cr6.lt) goto loc_82708694;
loc_827086F8:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// li r0,-176
	ctx.r0.s64 = -176;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x827566d0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8271CE90) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
loc_8271CE94:
	// subf. r3,r4,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r4.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bge 0x8271ce94
	if (!ctx.cr0.lt) goto loc_8271CE94;
	// addi r3,r11,-1
	ctx.r3.s64 = ctx.r11.s64 + -1;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8271E140) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x8271E148;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// bl 0x8271e010
	ctx.lr = 0x8271E178;
	sub_8271E010(ctx, base);
	// lbz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r30.u32 + 8);
	// lwz r31,84(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 84);
	// subfic r11,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// clrldi r10,r11,32
	ctx.r10.u64 = ctx.r11.u64 & 0xFFFFFFFF;
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
	// blt cr6,0x8271e268
	if (ctx.cr6.lt) goto loc_8271E268;
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
	// bge cr6,0x8271e260
	if (!ctx.cr6.lt) goto loc_8271E260;
loc_8271E1C8:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8271e1f4
	if (ctx.cr6.lt) goto loc_8271E1F4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4f30
	ctx.lr = 0x8271E1E4;
	sub_826E4F30(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8271e1c8
	if (ctx.cr6.eq) goto loc_8271E1C8;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8271e2a8
	goto loc_8271E2A8;
loc_8271E1F4:
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
loc_8271E260:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8271e2a8
	goto loc_8271E2A8;
loc_8271E268:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e50c0
	ctx.lr = 0x8271E270;
	sub_826E50C0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r28,r11,32768
	ctx.r28.u64 = ctx.r11.u64 | 32768;
loc_8271E278:
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
	// bl 0x826e50c0
	ctx.lr = 0x8271E290;
	sub_826E50C0(ctx, base);
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
	// blt cr6,0x8271e278
	if (ctx.cr6.lt) goto loc_8271E278;
loc_8271E2A8:
	// lwz r31,84(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 84);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8271e2c4
	if (ctx.cr6.eq) goto loc_8271E2C4;
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
loc_8271E2C4:
	// cmpwi cr6,r30,1099
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1099, ctx.xer);
	// beq cr6,0x8271e2dc
	if (ctx.cr6.eq) goto loc_8271E2DC;
	// lwz r11,244(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 244);
	// lbzx r28,r30,r27
	ctx.r28.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// lbzx r30,r30,r11
	ctx.r30.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// b 0x8271e43c
	goto loc_8271E43C;
loc_8271E2DC:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r30,6
	ctx.r30.s64 = 6;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bge cr6,0x8271e34c
	if (!ctx.cr6.lt) goto loc_8271E34C;
loc_8271E2F4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8271e34c
	if (ctx.cr6.eq) goto loc_8271E34C;
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
	// bge 0x8271e33c
	if (!ctx.cr0.lt) goto loc_8271E33C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x8271E33C;
	sub_826E4FF0(ctx, base);
loc_8271E33C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8271e2f4
	if (ctx.cr6.gt) goto loc_8271E2F4;
loc_8271E34C:
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
	// bge 0x8271e388
	if (!ctx.cr0.lt) goto loc_8271E388;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x8271E388;
	sub_826E4FF0(ctx, base);
loc_8271E388:
	// lwz r31,84(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 84);
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// li r30,6
	ctx.r30.s64 = 6;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bge cr6,0x8271e400
	if (!ctx.cr6.lt) goto loc_8271E400;
loc_8271E3A8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8271e400
	if (ctx.cr6.eq) goto loc_8271E400;
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
	// bge 0x8271e3f0
	if (!ctx.cr0.lt) goto loc_8271E3F0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x8271E3F0;
	sub_826E4FF0(ctx, base);
loc_8271E3F0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8271e3a8
	if (ctx.cr6.gt) goto loc_8271E3A8;
loc_8271E400:
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
	// bge 0x8271e43c
	if (!ctx.cr0.lt) goto loc_8271E43C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x8271E43C;
	sub_826E4FF0(ctx, base);
loc_8271E43C:
	// lbz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r10,244(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 244);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r11,r11,-32
	ctx.r11.s64 = ctx.r11.s64 + -32;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8271e464
	if (!ctx.cr6.gt) goto loc_8271E464;
	// addi r11,r11,-64
	ctx.r11.s64 = ctx.r11.s64 + -64;
	// stb r11,0(r25)
	REX_STORE_U8(ctx.r25.u32 + 0, ctx.r11.u8);
	// b 0x8271e480
	goto loc_8271E480;
loc_8271E464:
	// lwz r10,240(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 240);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8271e47c
	if (!ctx.cr6.lt) goto loc_8271E47C;
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// stb r11,0(r25)
	REX_STORE_U8(ctx.r25.u32 + 0, ctx.r11.u8);
	// b 0x8271e480
	goto loc_8271E480;
loc_8271E47C:
	// stb r11,0(r25)
	REX_STORE_U8(ctx.r25.u32 + 0, ctx.r11.u8);
loc_8271E480:
	// lbz r11,81(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lwz r10,244(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 244);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r11,r11,-32
	ctx.r11.s64 = ctx.r11.s64 + -32;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8271e4a8
	if (!ctx.cr6.gt) goto loc_8271E4A8;
	// addi r11,r11,-64
	ctx.r11.s64 = ctx.r11.s64 + -64;
	// stb r11,1(r25)
	REX_STORE_U8(ctx.r25.u32 + 1, ctx.r11.u8);
	// b 0x8271e4c4
	goto loc_8271E4C4;
loc_8271E4A8:
	// lwz r10,240(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 240);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8271e4c0
	if (!ctx.cr6.lt) goto loc_8271E4C0;
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// stb r11,1(r25)
	REX_STORE_U8(ctx.r25.u32 + 1, ctx.r11.u8);
	// b 0x8271e4c4
	goto loc_8271E4C4;
loc_8271E4C0:
	// stb r11,1(r25)
	REX_STORE_U8(ctx.r25.u32 + 1, ctx.r11.u8);
loc_8271E4C4:
	// lwz r11,452(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 452);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// stw r10,332(r26)
	REX_STORE_U32(ctx.r26.u32 + 332, ctx.r10.u32);
	// bne cr6,0x8271e5ac
	if (!ctx.cr6.eq) goto loc_8271E5AC;
	// lbz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8271e4f8
	if (!ctx.cr6.eq) goto loc_8271E4F8;
	// lbz r11,1(r25)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + 1);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8271e5ac
	if (ctx.cr6.eq) goto loc_8271E5AC;
loc_8271E4F8:
	// lwz r31,84(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 84);
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
	// bge cr6,0x8271e56c
	if (!ctx.cr6.lt) goto loc_8271E56C;
loc_8271E514:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8271e56c
	if (ctx.cr6.eq) goto loc_8271E56C;
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
	// bge 0x8271e55c
	if (!ctx.cr0.lt) goto loc_8271E55C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x8271E55C;
	sub_826E4FF0(ctx, base);
loc_8271E55C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8271e514
	if (ctx.cr6.gt) goto loc_8271E514;
loc_8271E56C:
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
	// bge 0x8271e5a8
	if (!ctx.cr0.lt) goto loc_8271E5A8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x8271E5A8;
	sub_826E4FF0(ctx, base);
loc_8271E5A8:
	// stw r30,332(r26)
	REX_STORE_U32(ctx.r26.u32 + 332, ctx.r30.u32);
loc_8271E5AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82744F20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756684
	ctx.lr = 0x82744F28;
	__savegprlr_15(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r5,36(r1)
	REX_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// stw r7,52(r1)
	REX_STORE_U32(ctx.r1.u32 + 52, ctx.r7.u32);
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r21,r10,25680
	ctx.r21.s64 = ctx.r10.s64 + 25680;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r21,-272(r1)
	REX_STORE_U32(ctx.r1.u32 + -272, ctx.r21.u32);
	// beq cr6,0x8274542c
	if (ctx.cr6.eq) goto loc_8274542C;
	// stw r7,-176(r1)
	REX_STORE_U32(ctx.r1.u32 + -176, ctx.r7.u32);
	// subf r10,r8,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r8.u64;
	// add r31,r4,r8
	ctx.r31.u64 = ctx.r4.u64 + ctx.r8.u64;
	// lvlx128 v63,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// subf r3,r8,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r8.u64;
	// lvlx128 v62,r4,r8
	temp.u32 = ctx.r4.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r5,r1,-176
	ctx.r5.s64 = ctx.r1.s64 + -176;
	// lvrx128 v61,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// add r9,r31,r8
	ctx.r9.u64 = ctx.r31.u64 + ctx.r8.u64;
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// subf r6,r8,r3
	ctx.r6.u64 = ctx.r3.u64 - ctx.r8.u64;
	// lvlx128 v60,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r30,r9,r8
	ctx.r30.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lvlx128 v59,r31,r8
	temp.u32 = ctx.r31.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// subf r29,r8,r6
	ctx.r29.u64 = ctx.r6.u64 - ctx.r8.u64;
	// lvrx128 v58,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v57,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v21,v63,v61
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// lvlx128 v56,r9,r8
	temp.u32 = ctx.r9.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v20,v62,v58
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8)));
	// lvlx128 v55,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r31,r10,r8
	ctx.r31.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lvrx128 v54,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vspltisb v14,-1
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_set1_epi8(char(0xFF)));
	// lvlx128 v53,r0,r29
	temp.u32 = ctx.r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v24,v55,v54
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8)));
	// lvrx128 v52,r11,r29
	temp.u32 = ctx.r11.u32 + ctx.r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vspltish v13,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x3)));
	// lvrx128 v51,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v25,v53,v52
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v52.u8)));
	// lvrx128 v50,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v23,v57,v51
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8)));
	// lvrx128 v49,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v22,v60,v50
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v50.u8)));
	// lvrx128 v48,r11,r30
	temp.u32 = ctx.r11.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v19,v59,v49
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8)));
	// vor128 v18,v56,v48
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8)));
	// lvx128 v1,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltish v26,4
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_set1_epi16(short(0x4)));
	// li r26,0
	ctx.r26.s64 = 0;
	// lvx128 v12,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_82745024:
	// vsubshs v3,v6,v12
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// addi r5,r1,-176
	ctx.r5.s64 = ctx.r1.s64 + -176;
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
	// stvx128 v4,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v7,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// mfocrf r25,2
	ctx.r25.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r5,r25,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x20;
	// vor128 v12,v47,v47
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v47.u8));
	// vor128 v11,v46,v46
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v46.u8));
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// vor128 v10,v45,v45
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v45.u8));
	// vor128 v9,v44,v44
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v44.u8));
	// vor128 v8,v43,v43
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v43.u8));
	// vor128 v7,v42,v42
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v42.u8));
	// beq cr6,0x82745354
	if (ctx.cr6.eq) goto loc_82745354;
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
	// mfocrf r5,2
	ctx.r5.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupklsh v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsw. v2,v3,v17
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.u32), simde_mm_load_si128((simde__m128i*)ctx.v17.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v2.u32)), 0xF);
	// mfocrf r29,2
	ctx.r29.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r5,r5,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x20;
	// vor128 v0,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v41.u8));
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// beq cr6,0x82745188
	if (ctx.cr6.eq) goto loc_82745188;
	// rlwinm r5,r30,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// bne cr6,0x827451a0
	if (!ctx.cr6.eq) goto loc_827451A0;
loc_82745188:
	// rlwinm r5,r29,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// beq cr6,0x82745354
	if (ctx.cr6.eq) goto loc_82745354;
	// rlwinm r5,r28,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// beq cr6,0x82745354
	if (ctx.cr6.eq) goto loc_82745354;
loc_827451A0:
	// vsubshs v31,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// addi r28,r1,-192
	ctx.r28.s64 = ctx.r1.s64 + -192;
	// vsubshs v3,v12,v6
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// addi r24,r1,-208
	ctx.r24.s64 = ctx.r1.s64 + -208;
	// vaddshs v30,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// addi r23,r1,-160
	ctx.r23.s64 = ctx.r1.s64 + -160;
	// vaddshs v2,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// addi r5,r1,-240
	ctx.r5.s64 = ctx.r1.s64 + -240;
	// vmaxsh v4,v31,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// addi r30,r1,-224
	ctx.r30.s64 = ctx.r1.s64 + -224;
	// vsubshs v28,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// addi r29,r1,-256
	ctx.r29.s64 = ctx.r1.s64 + -256;
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
	// stvx128 v3,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v30,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v4,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v0,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v31,v11,v3
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v2,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// lvx128 v0,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v0,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vsrah v31,v31,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// lvx128 v12,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v52,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,-232(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -232);
	// lwz r28,-240(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -240);
	// vpkshus128 v47,v48,v49
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v49.s16), simde_mm_load_si128((simde__m128i*)ctx.v48.s16)));
	// vpkshus128 v46,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// stvx128 v47,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r28.u32);
	// stvx128 v46,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,-216(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -216);
	// lwz r28,-256(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// vor128 v0,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// lwz r24,-248(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + -248);
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v60.u8));
	// stw r5,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// vor128 v11,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// lwz r30,-224(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -224);
	// stw r30,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r30.u32);
	// stw r29,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r29.u32);
	// stwx r28,r27,r31
	REX_STORE_U32(ctx.r27.u32 + ctx.r31.u32, ctx.r28.u32);
	// lwz r29,-252(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -252);
	// lwz r28,-244(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -244);
	// lwz r23,-236(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -236);
	// lwz r22,-228(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -228);
	// stw r24,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r24.u32);
	// lwz r5,-220(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -220);
	// lwz r30,-212(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -212);
	// stw r23,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r23.u32);
	// stw r22,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r22.u32);
	// stw r5,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stwx r29,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r29.u32);
	// stw r28,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r28.u32);
	// b 0x8274535c
	goto loc_8274535C;
loc_82745354:
	// vor v3,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vor v4,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
loc_8274535C:
	// rlwinm r5,r25,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,128
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 128, ctx.xer);
	// beq cr6,0x827453e4
	if (ctx.cr6.eq) goto loc_827453E4;
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
	// blt cr6,0x827453e4
	if (ctx.cr6.lt) goto loc_827453E4;
	// vspltish v29,2
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_set1_epi16(short(0x2)));
	// addi r5,r1,-256
	ctx.r5.s64 = ctx.r1.s64 + -256;
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
	// stvx128 v43,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r28,-252(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -252);
	// lwz r30,-248(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -248);
	// lwz r29,-244(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -244);
	// lwz r5,-256(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// stw r5,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// stw r28,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r28.u32);
	// stw r30,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r30.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_827453E4:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x82745420
	if (!ctx.cr6.eq) goto loc_82745420;
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
loc_82745420:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmpwi cr6,r26,2
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 2, ctx.xer);
	// blt cr6,0x82745024
	if (ctx.cr6.lt) goto loc_82745024;
loc_8274542C:
	// stw r7,-176(r1)
	REX_STORE_U32(ctx.r1.u32 + -176, ctx.r7.u32);
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r5,r1,-176
	ctx.r5.s64 = ctx.r1.s64 + -176;
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// lvx128 v1,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisb v14,-1
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_set1_epi8(char(0xFF)));
	// li r25,0
	ctx.r25.s64 = 0;
	// subf r6,r8,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r8.u64;
	// vspltish v13,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x3)));
	// add r30,r10,r8
	ctx.r30.u64 = ctx.r10.u64 + ctx.r8.u64;
	// vspltish v16,4
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_set1_epi16(short(0x4)));
	// subf r31,r8,r6
	ctx.r31.u64 = ctx.r6.u64 - ctx.r8.u64;
	// vspltisw v15,4
	simde_mm_store_si128((simde__m128i*)ctx.v15.u32, simde_mm_set1_epi32(int(0x4)));
	// add r9,r30,r8
	ctx.r9.u64 = ctx.r30.u64 + ctx.r8.u64;
	// lvlx128 v42,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// subf r3,r8,r31
	ctx.r3.u64 = ctx.r31.u64 - ctx.r8.u64;
	// lvlx128 v41,r10,r8
	temp.u32 = ctx.r10.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r29,r9,r8
	ctx.r29.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lvlx128 v40,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// subf r28,r8,r3
	ctx.r28.u64 = ctx.r3.u64 - ctx.r8.u64;
	// lvlx128 v39,r30,r8
	temp.u32 = ctx.r30.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v38,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v37,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvrx128 v36,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v24,v38,v37
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v38.u8), simde_mm_load_si128((simde__m128i*)ctx.v37.u8)));
	// lvlx128 v35,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v34,r11,r28
	temp.u32 = ctx.r11.u32 + ctx.r28.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v25,v35,v36
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v35.u8), simde_mm_load_si128((simde__m128i*)ctx.v36.u8)));
	// lvlx128 v33,r0,r28
	temp.u32 = ctx.r28.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v32,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v26,v33,v34
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v33.u8), simde_mm_load_si128((simde__m128i*)ctx.v34.u8)));
	// lvrx128 v63,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v23,v40,v32
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v40.u8), simde_mm_load_si128((simde__m128i*)ctx.v32.u8)));
	// lvrx128 v62,r11,r30
	temp.u32 = ctx.r11.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v22,v42,v63
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v42.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lvx128 v12,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v21,v41,v62
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// vsplth v27,v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u16), simde_mm_set1_epi16(short(0xD0C))));
	// lvrx128 v61,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvrx128 v60,r11,r29
	temp.u32 = ctx.r11.u32 + ctx.r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v20,v39,v61
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// lvlx128 v59,r9,r8
	temp.u32 = ctx.r9.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmrghb v6,v0,v26
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vor128 v19,v59,v60
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// vmrghb v12,v0,v25
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddshs v18,v27,v27
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// vmrghb v9,v0,v24
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v11,v0,v23
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v10,v0,v22
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v8,v0,v21
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v7,v0,v20
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v5,v0,v19
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vupkhsh v17,v18
	simde_mm_store_si128((simde__m128i*)ctx.v17.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v18.s16))));
loc_82745504:
	// vsubshs v3,v6,v12
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// addi r5,r1,-160
	ctx.r5.s64 = ctx.r1.s64 + -160;
	// vsubshs v2,v12,v9
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vsubshs v30,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vsubshs v29,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vsubshs v4,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vsubshs v28,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vsubshs v31,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vor128 v58,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// stvx128 v4,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v57,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vor128 v56,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vor128 v54,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vsubshs v12,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vsubshs v11,v0,v29
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vsubshs v10,v0,v28
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vsubshs v8,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vor128 v55,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vsubshs v4,v7,v5
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vsubshs v9,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vor128 v53,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// vmaxsh v30,v12,v30
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vmaxsh v29,v11,v29
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vmaxsh v28,v10,v28
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vmaxsh v2,v8,v2
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vmaxsh v31,v9,v31
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vsubshs v12,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vcmpgtuh v28,v13,v28
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vcmpgtuh v29,v13,v29
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// vcmpgtuh v2,v13,v2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// lvx128 v7,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// vcmpgtsh. v30,v3,v16
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v16.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), 0xFFFF);
	// mfocrf r26,2
	ctx.r26.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r5,r26,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x20;
	// vor128 v12,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v58.u8));
	// vor128 v11,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v57.u8));
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// vor128 v10,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v56.u8));
	// vor128 v9,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v55.u8));
	// vor128 v8,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v54.u8));
	// vor128 v7,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v53.u8));
	// beq cr6,0x82745830
	if (ctx.cr6.eq) goto loc_82745830;
	// vminsh v31,v12,v9
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vminsh v2,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vmaxsh v28,v12,v9
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vmaxsh v29,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vor128 v52,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vminsh v2,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vminsh v0,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vmaxsh v29,v28,v29
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vmaxsh v31,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vminsh v28,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vmaxsh v2,v31,v29
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vsubshs v2,v2,v28
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vcmpgtsh. v29,v18,v2
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), 0xFFFF);
	// vupkhsh v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16))));
	// vcmpgtsw. v28,v17,v31
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v17.u32), simde_mm_load_si128((simde__m128i*)ctx.v31.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v28.u32)), 0xF);
	// vand128 v63,v29,v30
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// mfocrf r29,2
	ctx.r29.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupklsh v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v2.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vcmpgtsw. v31,v17,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v17.u32), simde_mm_load_si128((simde__m128i*)ctx.v2.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v31.u32)), 0xF);
	// mfocrf r27,2
	ctx.r27.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupkhsh v29,v3
	simde_mm_store_si128((simde__m128i*)ctx.v29.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16))));
	// vcmpgtsw. v28,v29,v15
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v29.u32), simde_mm_load_si128((simde__m128i*)ctx.v15.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v28.u32)), 0xF);
	// mfocrf r5,2
	ctx.r5.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupklsh v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsw. v2,v3,v15
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.u32), simde_mm_load_si128((simde__m128i*)ctx.v15.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v2.u32)), 0xF);
	// mfocrf r28,2
	ctx.r28.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r5,r5,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x20;
	// vor128 v0,v52,v52
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v52.u8));
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// beq cr6,0x82745668
	if (ctx.cr6.eq) goto loc_82745668;
	// rlwinm r5,r29,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// bne cr6,0x82745680
	if (!ctx.cr6.eq) goto loc_82745680;
loc_82745668:
	// rlwinm r5,r28,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// beq cr6,0x82745830
	if (ctx.cr6.eq) goto loc_82745830;
	// rlwinm r5,r27,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// beq cr6,0x82745830
	if (ctx.cr6.eq) goto loc_82745830;
loc_82745680:
	// vsubshs v31,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// addi r24,r1,-192
	ctx.r24.s64 = ctx.r1.s64 + -192;
	// vaddshs v29,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// addi r27,r1,-176
	ctx.r27.s64 = ctx.r1.s64 + -176;
	// vsubshs v3,v12,v6
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// addi r5,r1,-224
	ctx.r5.s64 = ctx.r1.s64 + -224;
	// vaddshs v2,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// addi r29,r1,-256
	ctx.r29.s64 = ctx.r1.s64 + -256;
	// vmaxsh v4,v31,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// addi r28,r1,-240
	ctx.r28.s64 = ctx.r1.s64 + -240;
	// vaddshs v31,v29,v16
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// vsubshs v28,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vor128 v41,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vcmpgtsh v29,v27,v4
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vaddshs v4,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vmaxsh v3,v28,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vandc128 v43,v11,v63
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vandc128 v47,v7,v29
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vand128 v46,v5,v29
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v29.u8)));
	// stvx128 v4,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtsh v28,v27,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vor128 v39,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vaddshs v29,v12,v10
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vxor128 v5,v46,v47
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8)));
	// vandc128 v45,v12,v28
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// vand128 v44,v6,v28
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8)));
	// vandc128 v42,v10,v63
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// vaddshs v3,v8,v5
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v4,v7,v5
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vxor128 v6,v44,v45
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)ctx.v45.u8)));
	// vsubshs v28,v5,v9
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// stvx128 v3,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v38,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vaddshs v11,v2,v4
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v3,v6,v12
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vsubshs v0,v6,v8
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v28,v28,v4
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v4,v31,v11
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v10,v3,v31
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vaddshs v0,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vandc128 v50,v12,v63
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// vor128 v40,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vaddshs v3,v10,v2
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vaddshs v12,v6,v9
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vaddshs v2,v28,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vandc128 v51,v9,v63
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)));
	// vaddshs v28,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v31,v12,v3
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vsrah v2,v2,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vandc128 v49,v7,v63
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vsrah v28,v28,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v31,v31,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// lvx128 v0,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vandc128 v48,v8,v63
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)));
	// vaddshs v0,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vand128 v35,v28,v63
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v36,v31,v63
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v37,v2,v63
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vsrah v0,v0,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v0.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v4,v29,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// lvx128 v29,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v32,v36,v51
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v36.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8)));
	// vxor128 v62,v35,v50
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v35.u8), simde_mm_load_si128((simde__m128i*)ctx.v50.u8)));
	// vand128 v34,v0,v63
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vaddshs v28,v29,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vxor128 v33,v37,v49
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v37.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8)));
	// vpkshus128 v60,v62,v32
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v32.s16), simde_mm_load_si128((simde__m128i*)ctx.v62.s16)));
	// vsrah v4,v4,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vxor128 v61,v34,v48
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v34.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8)));
	// vsrah v3,v28,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vand128 v58,v4,v63
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vpkshus128 v59,v61,v33
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v33.s16), simde_mm_load_si128((simde__m128i*)ctx.v61.s16)));
	// vand128 v57,v3,v63
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,-224(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -224);
	// stw r5,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// vxor128 v3,v58,v42
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v42.u8)));
	// stvx128 v59,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,-216(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -216);
	// lwz r29,-256(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// vxor128 v4,v57,v43
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v43.u8)));
	// vpkshus128 v56,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// stw r5,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// lwz r27,-248(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -248);
	// vor128 v0,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v41.u8));
	// lwz r24,-220(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + -220);
	// vor128 v12,v40,v40
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v40.u8));
	// lwz r23,-212(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -212);
	// vor128 v11,v39,v39
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v39.u8));
	// vor128 v10,v38,v38
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v38.u8));
	// stvx128 v56,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r28,-232(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -232);
	// lwz r5,-240(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -240);
	// stw r5,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// lwz r5,-236(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -236);
	// stw r28,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r28.u32);
	// stw r29,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// stw r27,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r27.u32);
	// lwz r29,-252(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -252);
	// lwz r27,-244(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -244);
	// stw r24,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r24.u32);
	// stw r23,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r23.u32);
	// lwz r28,-228(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -228);
	// stw r5,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// stw r28,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r28.u32);
	// stw r29,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r29.u32);
	// stw r27,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r27.u32);
	// b 0x82745838
	goto loc_82745838;
loc_82745830:
	// vor v3,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vor v4,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
loc_82745838:
	// rlwinm r5,r26,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,128
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 128, ctx.xer);
	// beq cr6,0x827458c0
	if (ctx.cr6.eq) goto loc_827458C0;
	// vsubshs v2,v10,v11
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vxor128 v55,v14,v30
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vsubshs v31,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vmaxsh v31,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vcmpgtsh v30,v27,v31
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v31.u16)));
	// vcmpgtsh v29,v31,v13
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// vand128 v54,v29,v30
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vand128 v30,v54,v55
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8)));
	// vcmpequh. v28,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v28.u16), 0xFFFF);
	// blt cr6,0x827458c0
	if (ctx.cr6.lt) goto loc_827458C0;
	// vspltish v29,2
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_set1_epi16(short(0x2)));
	// addi r5,r1,-256
	ctx.r5.s64 = ctx.r1.s64 + -256;
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
	// vpkshus128 v53,v30,v31
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// stvx128 v53,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,-256(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// lwz r29,-244(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -244);
	// lwz r28,-252(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -252);
	// stw r28,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r28.u32);
	// lwz r28,-248(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -248);
	// stw r5,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// stw r29,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r29.u32);
	// stw r28,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r28.u32);
loc_827458C0:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x82745900
	if (!ctx.cr6.eq) goto loc_82745900;
	// vmrglb v6,v0,v26
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// vmrglb v12,v0,v25
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// vmrglb v9,v0,v24
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// vmrglb v11,v0,v23
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// vmrglb v10,v0,v22
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// vmrglb v8,v0,v21
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// vmrglb v7,v0,v20
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrglb v5,v0,v19
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
loc_82745900:
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// cmpwi cr6,r25,2
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 2, ctx.xer);
	// blt cr6,0x82745504
	if (ctx.cr6.lt) goto loc_82745504;
	// addi r9,r4,4
	ctx.r9.s64 = ctx.r4.s64 + 4;
	// stw r7,-176(r1)
	REX_STORE_U32(ctx.r1.u32 + -176, ctx.r7.u32);
	// addi r5,r1,-176
	ctx.r5.s64 = ctx.r1.s64 + -176;
	// lvx128 v1,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r6,r8
	ctx.r3.u64 = ctx.r6.u64 + ctx.r8.u64;
	// lvlx128 v52,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r22,0
	ctx.r22.s64 = 0;
	// add r31,r3,r8
	ctx.r31.u64 = ctx.r3.u64 + ctx.r8.u64;
	// lvrx128 v51,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v50,r9,r8
	temp.u32 = ctx.r9.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v12,v52,v51
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8)));
	// add r30,r31,r8
	ctx.r30.u64 = ctx.r31.u64 + ctx.r8.u64;
	// lvrx128 v49,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v48,r6,r8
	temp.u32 = ctx.r6.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v11,v50,v49
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8)));
	// add r29,r30,r8
	ctx.r29.u64 = ctx.r30.u64 + ctx.r8.u64;
	// lvrx128 v47,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v46,r3,r8
	temp.u32 = ctx.r3.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v10,v48,v47
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8)));
	// add r28,r29,r8
	ctx.r28.u64 = ctx.r29.u64 + ctx.r8.u64;
	// lvrx128 v45,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v44,r31,r8
	temp.u32 = ctx.r31.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v9,v46,v45
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v45.u8)));
	// add r27,r28,r8
	ctx.r27.u64 = ctx.r28.u64 + ctx.r8.u64;
	// lvrx128 v43,r11,r30
	temp.u32 = ctx.r11.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v42,r30,r8
	temp.u32 = ctx.r30.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v8,v44,v43
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)ctx.v43.u8)));
	// lvrx128 v41,r11,r29
	temp.u32 = ctx.r11.u32 + ctx.r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vmrghb v12,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvlx128 v40,r29,r8
	temp.u32 = ctx.r29.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v7,v42,v41
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v42.u8), simde_mm_load_si128((simde__m128i*)ctx.v41.u8)));
	// lvrx128 v39,r11,r28
	temp.u32 = ctx.r11.u32 + ctx.r28.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vmrghb v11,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvlx128 v38,r28,r8
	temp.u32 = ctx.r28.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v6,v40,v39
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v40.u8), simde_mm_load_si128((simde__m128i*)ctx.v39.u8)));
	// lvrx128 v37,r11,r27
	temp.u32 = ctx.r11.u32 + ctx.r27.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vmrghb v8,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vor128 v5,v38,v37
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v38.u8), simde_mm_load_si128((simde__m128i*)ctx.v37.u8)));
	// vmrghb v7,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v10,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v30,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v6,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v9,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v5,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
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
	// vaddshs v25,v27,v27
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
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
	// vupkhsh v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v24.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v25.s16))));
loc_82745A30:
	// vsubshs v3,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsubshs v29,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vsubshs v28,v6,v5
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vsubshs v2,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vsubshs v31,v7,v10
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vsubshs v30,v10,v9
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vsubshs v26,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vsubshs v22,v0,v29
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vsubshs v21,v0,v28
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vsubshs v23,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vsubshs v20,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vsubshs v19,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vsubshs v4,v5,v8
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vmaxsh v18,v26,v3
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vmaxsh v17,v21,v28
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vmaxsh v3,v22,v29
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vmaxsh v30,v23,v30
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vmaxsh v29,v20,v31
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vmaxsh v28,v19,v2
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vsubshs v26,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vcmpgtuh v23,v13,v17
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// vcmpgtuh v22,v13,v3
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vcmpgtuh v21,v13,v30
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	// vmaxsh v17,v26,v4
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vcmpgtuh v20,v13,v29
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// vcmpgtuh v19,v13,v28
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vcmpgtuh v18,v13,v18
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v18.u16)));
	// vaddshs v3,v22,v23
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v23.s16)));
	// vaddshs v2,v20,v21
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v21.s16)));
	// vcmpgtuh v30,v13,v17
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// vaddshs v31,v18,v19
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vaddshs v29,v2,v3
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v28,v30,v31
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vaddshs v26,v28,v29
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vsubshs v3,v0,v26
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v26.s16)));
	// vperm v3,v3,v3,v1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// vcmpgtsh. v26,v3,v16
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v16.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v26.u16), 0xFFFF);
	// mfocrf r23,2
	ctx.r23.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r5,r23,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// beq cr6,0x82745d3c
	if (ctx.cr6.eq) goto loc_82745D3C;
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
	// vminsh v23,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vmaxsh v22,v6,v5
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vmaxsh v21,v29,v30
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vminsh v20,v28,v23
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v23.s16)));
	// vmaxsh v19,v22,v21
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v21.s16)));
	// vsubshs v2,v19,v20
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v20.s16)));
	// vcmpgtsh. v17,v25,v2
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v17.u16), 0xFFFF);
	// vupkhsh v18,v2
	simde_mm_store_si128((simde__m128i*)ctx.v18.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16))));
	// vcmpgtsw. v31,v24,v18
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v24.u32), simde_mm_load_si128((simde__m128i*)ctx.v18.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v31.u32)), 0xF);
	// vand128 v63,v17,v26
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v26.u8)));
	// mfocrf r26,2
	ctx.r26.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupklsh v30,v2
	simde_mm_store_si128((simde__m128i*)ctx.v30.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vcmpgtsw. v29,v24,v30
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v24.u32), simde_mm_load_si128((simde__m128i*)ctx.v30.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v29.u32)), 0xF);
	// mfocrf r24,2
	ctx.r24.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupkhsh v28,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16))));
	// vcmpgtsw. v23,v28,v15
	simde_mm_store_si128((simde__m128i*)ctx.v23.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v28.u32), simde_mm_load_si128((simde__m128i*)ctx.v15.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v23.u32)), 0xF);
	// mfocrf r5,2
	ctx.r5.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupklsh v22,v3
	simde_mm_store_si128((simde__m128i*)ctx.v22.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsw. v21,v22,v15
	simde_mm_store_si128((simde__m128i*)ctx.v21.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v22.u32), simde_mm_load_si128((simde__m128i*)ctx.v15.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v21.u32)), 0xF);
	// mfocrf r25,2
	ctx.r25.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r5,r5,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// beq cr6,0x82745b50
	if (ctx.cr6.eq) goto loc_82745B50;
	// rlwinm r5,r26,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// bne cr6,0x82745b68
	if (!ctx.cr6.eq) goto loc_82745B68;
loc_82745B50:
	// rlwinm r5,r25,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// beq cr6,0x82745d3c
	if (ctx.cr6.eq) goto loc_82745D3C;
	// rlwinm r5,r24,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// beq cr6,0x82745d3c
	if (ctx.cr6.eq) goto loc_82745D3C;
loc_82745B68:
	// vsubshs v3,v11,v12
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// addi r7,r1,-208
	ctx.r7.s64 = ctx.r1.s64 + -208;
	// vsubshs v2,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// addi r5,r1,-256
	ctx.r5.s64 = ctx.r1.s64 + -256;
	// vor128 v36,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// addi r26,r1,-224
	ctx.r26.s64 = ctx.r1.s64 + -224;
	// vaddshs v31,v7,v10
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// addi r25,r1,-240
	ctx.r25.s64 = ctx.r1.s64 + -240;
	// vsubshs v30,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vmaxsh v29,v2,v4
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vor128 v35,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vaddshs v2,v31,v16
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// vmaxsh v28,v30,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsh v23,v27,v29
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// vaddshs v31,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v22,v10,v5
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vcmpgtsh v21,v27,v28
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vandc128 v33,v5,v23
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vand128 v32,v8,v23
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v23.u8)));
	// vaddshs v20,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vandc128 v61,v11,v21
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vand128 v60,v12,v21
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v21.u8)));
	// vxor128 v8,v32,v33
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v32.u8), simde_mm_load_si128((simde__m128i*)ctx.v33.u8)));
	// vandc128 v34,v10,v63
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// vandc128 v62,v11,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vxor128 v12,v60,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// vaddshs v3,v5,v8
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vsubshs v19,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v18,v6,v8
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v30,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsubshs v17,v12,v6
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v4,v31,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v29,v19,v3
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v28,v30,v2
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vaddshs v23,v17,v30
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vaddshs v21,v12,v7
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v4,v2,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v3,v28,v31
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vandc128 v59,v7,v63
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vandc128 v58,v9,v63
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)));
	// vaddshs v31,v29,v4
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v19,v22,v3
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v17,v23,v3
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v3,v21,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v2,v18,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v20,v20,v4
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vsrah v30,v19,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v19.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v28,v3,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v29,v17,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v17.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v22,v2,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v23,v20,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v21,v31,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vand128 v55,v30,v63
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v54,v29,v63
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v53,v28,v63
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vandc128 v57,v6,v63
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vandc128 v56,v5,v63
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vand128 v52,v23,v63
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v51,v22,v63
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v50,v21,v63
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vxor128 v29,v55,v34
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v34.u8)));
	// vxor128 v49,v54,v62
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// vxor128 v48,v53,v59
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// vxor128 v28,v52,v58
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8)));
	// vxor128 v47,v51,v57
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8)));
	// vxor128 v46,v50,v56
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8)));
	// vpkshus128 v4,v36,v49
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v49.s16), simde_mm_load_si128((simde__m128i*)ctx.v36.s16)));
	// vpkshus128 v3,v48,v29
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v48.s16)));
	// vpkshus128 v2,v28,v47
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v47.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vpkshus128 v31,v46,v35
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v35.s16), simde_mm_load_si128((simde__m128i*)ctx.v46.s16)));
	// vmrghb v30,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vmrglb v4,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vmrghb v3,v2,v31
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vmrglb v2,v2,v31
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vmrghb v20,v30,v4
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vmrglb v19,v30,v4
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vmrglb v18,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// vmrghb v17,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// stvx128 v20,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v18,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,-252(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -252);
	// stvx128 v17,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r19,-240(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + -240);
	// lwz r18,-236(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + -236);
	// stvx128 v19,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r17,-232(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -232);
	// lwz r15,-256(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// lwz r5,-248(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -248);
	// lwz r26,-244(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -244);
	// lwz r25,-224(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -224);
	// stw r15,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r15.u32);
	// stw r7,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// stw r5,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r25,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
	// lwz r24,-220(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + -220);
	// lwz r21,-216(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + -216);
	// lwz r20,-212(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + -212);
	// lwz r16,-228(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + -228);
	// lwz r7,-208(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -208);
	// stw r24,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r24.u32);
	// stw r21,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r21.u32);
	// stw r20,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r20.u32);
	// lwz r5,-204(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -204);
	// stw r19,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r19.u32);
	// lwz r26,-200(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -200);
	// stw r18,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r18.u32);
	// lwz r25,-196(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -196);
	// stw r17,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r17.u32);
	// stw r16,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r16.u32);
	// stw r7,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r7.u32);
	// stw r5,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r5.u32);
	// stw r26,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r26.u32);
	// lwz r21,-272(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + -272);
	// lwz r7,52(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 52);
	// stw r25,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r25.u32);
	// b 0x82745d44
	goto loc_82745D44;
loc_82745D3C:
	// vor v28,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vor v29,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
loc_82745D44:
	// rlwinm r5,r23,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,128
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 128, ctx.xer);
	// beq cr6,0x82745e04
	if (ctx.cr6.eq) goto loc_82745E04;
	// vsubshs v3,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vxor128 v45,v14,v26
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v26.u8)));
	// vsubshs v4,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vmaxsh v4,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsh v2,v27,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vcmpgtsh v31,v4,v13
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// vand128 v44,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vand128 v2,v44,v45
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)ctx.v45.u8)));
	// vcmpequh. v30,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), 0xFFFF);
	// blt cr6,0x82745e04
	if (ctx.cr6.lt) goto loc_82745E04;
	// vspltish v31,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_set1_epi16(short(0x2)));
	// addi r5,r1,-176
	ctx.r5.s64 = ctx.r1.s64 + -176;
	// vspltish v30,15
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_set1_epi16(short(0xF)));
	// addi r26,r1,-192
	ctx.r26.s64 = ctx.r1.s64 + -192;
	// vsrah v4,v4,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v26,v3,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v23,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vand v22,v26,v23
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v23.u8)));
	// vsubshs v21,v4,v22
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v22.s16)));
	// vand v4,v21,v2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vaddshs v20,v29,v4
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vsubshs v19,v28,v4
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vpkshus v18,v20,v20
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v20.s16)));
	// vpkshus v17,v19,v19
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vmrghb v4,v18,v17
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)));
	// vmrghh v3,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrglh v2,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// stvx128 v3,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r25,-168(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -168);
	// stvx128 v2,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r26,-164(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -164);
	// lwz r24,-192(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + -192);
	// lwz r23,-188(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -188);
	// lwz r20,-184(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + -184);
	// lwz r19,-180(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + -180);
	// lwz r18,-176(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + -176);
	// sth r18,3(r9)
	REX_STORE_U16(ctx.r9.u32 + 3, ctx.r18.u16);
	// lwz r5,-172(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -172);
	// sth r5,3(r6)
	REX_STORE_U16(ctx.r6.u32 + 3, ctx.r5.u16);
	// sth r25,3(r3)
	REX_STORE_U16(ctx.r3.u32 + 3, ctx.r25.u16);
	// sth r26,3(r31)
	REX_STORE_U16(ctx.r31.u32 + 3, ctx.r26.u16);
	// sth r24,3(r30)
	REX_STORE_U16(ctx.r30.u32 + 3, ctx.r24.u16);
	// sth r23,3(r29)
	REX_STORE_U16(ctx.r29.u32 + 3, ctx.r23.u16);
	// sth r20,3(r28)
	REX_STORE_U16(ctx.r28.u32 + 3, ctx.r20.u16);
	// sth r19,3(r27)
	REX_STORE_U16(ctx.r27.u32 + 3, ctx.r19.u16);
loc_82745E04:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne cr6,0x82745f0c
	if (!ctx.cr6.eq) goto loc_82745F0C;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 + ctx.r10.u64;
	// add r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 + ctx.r10.u64;
	// add r31,r31,r10
	ctx.r31.u64 = ctx.r31.u64 + ctx.r10.u64;
	// add r30,r30,r10
	ctx.r30.u64 = ctx.r30.u64 + ctx.r10.u64;
	// add r29,r29,r10
	ctx.r29.u64 = ctx.r29.u64 + ctx.r10.u64;
	// lvlx128 v43,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r28,r28,r10
	ctx.r28.u64 = ctx.r28.u64 + ctx.r10.u64;
	// lvlx128 v42,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r27,r27,r10
	ctx.r27.u64 = ctx.r27.u64 + ctx.r10.u64;
	// lvlx128 v41,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v40,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v39,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v38,r0,r29
	temp.u32 = ctx.r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v37,r0,r28
	temp.u32 = ctx.r28.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v36,r0,r27
	temp.u32 = ctx.r27.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v35,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvrx128 v34,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v12,v43,v35
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v43.u8), simde_mm_load_si128((simde__m128i*)ctx.v35.u8)));
	// lvrx128 v33,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v11,v42,v34
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v42.u8), simde_mm_load_si128((simde__m128i*)ctx.v34.u8)));
	// lvrx128 v32,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v10,v41,v33
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)ctx.v33.u8)));
	// lvrx128 v63,r11,r30
	temp.u32 = ctx.r11.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v9,v40,v32
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v40.u8), simde_mm_load_si128((simde__m128i*)ctx.v32.u8)));
	// lvrx128 v62,r11,r29
	temp.u32 = ctx.r11.u32 + ctx.r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v8,v39,v63
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lvrx128 v61,r11,r28
	temp.u32 = ctx.r11.u32 + ctx.r28.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v7,v38,v62
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v38.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// lvrx128 v60,r11,r27
	temp.u32 = ctx.r11.u32 + ctx.r27.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v6,v37,v61
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v37.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// vor128 v5,v36,v60
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v36.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
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
loc_82745F0C:
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// cmpwi cr6,r22,2
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 2, ctx.xer);
	// blt cr6,0x82745a30
	if (ctx.cr6.lt) goto loc_82745A30;
	// lwz r9,36(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 36);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82746538
	if (ctx.cr6.eq) goto loc_82746538;
	// addi r9,r4,-4
	ctx.r9.s64 = ctx.r4.s64 + -4;
	// stw r7,-176(r1)
	REX_STORE_U32(ctx.r1.u32 + -176, ctx.r7.u32);
	// addi r7,r1,-176
	ctx.r7.s64 = ctx.r1.s64 + -176;
	// lvx128 v1,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// add r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 + ctx.r8.u64;
	// lvlx128 v59,r9,r8
	temp.u32 = ctx.r9.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stw r26,-272(r1)
	REX_STORE_U32(ctx.r1.u32 + -272, ctx.r26.u32);
	// add r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 + ctx.r8.u64;
	// lvlx128 v58,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v57,r6,r8
	temp.u32 = ctx.r6.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 + ctx.r8.u64;
	// lvrx128 v56,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v55,r5,r8
	temp.u32 = ctx.r5.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v12,v58,v56
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8)));
	// add r31,r3,r8
	ctx.r31.u64 = ctx.r3.u64 + ctx.r8.u64;
	// lvrx128 v54,r11,r5
	temp.u32 = ctx.r11.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvrx128 v53,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v11,v57,v54
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8)));
	// add r30,r31,r8
	ctx.r30.u64 = ctx.r31.u64 + ctx.r8.u64;
	// lvrx128 v52,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvrx128 v51,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v4,v55,v52
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v52.u8)));
	// add r8,r30,r8
	ctx.r8.u64 = ctx.r30.u64 + ctx.r8.u64;
	// lvlx128 v50,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v49,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v7,v50,v51
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8)));
	// lvlx128 v48,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v8,v59,v53
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8)));
	// lvrx128 v47,r11,r30
	temp.u32 = ctx.r11.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v3,v48,v49
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8)));
	// lvlx128 v46,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmrghb v12,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvrx128 v45,r11,r8
	temp.u32 = ctx.r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v2,v46,v47
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8)));
	// lvlx128 v44,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmrghb v10,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vor128 v31,v44,v45
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)ctx.v45.u8)));
	// vmrghb v11,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v6,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v30,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v9,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v8,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v5,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v7,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghh v4,v12,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrghh v3,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vmrglh v12,v12,v10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrglh v11,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v11.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vmrghh v10,v8,v6
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vmrghh v9,v7,v5
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v7.u16)));
	// vmrglh v8,v8,v6
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vmrglh v7,v7,v5
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v7.u16)));
	// vmrghh v6,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vmrglh v5,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vsplth v27,v30,1
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_set1_epi16(short(0xD0C))));
	// vmrghh v4,v10,v9
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vmrglh v10,v10,v9
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vmrghh v31,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v31.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vmrglh v2,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vaddshs v25,v27,v27
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// vmrglh v8,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vmrghh v3,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrghh v7,v5,v10
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v5.u16)));
	// vmrglh v10,v5,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v5.u16)));
	// vmrghh v12,v6,v4
	simde_mm_store_si128((simde__m128i*)ctx.v12.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vmrglh v11,v6,v4
	simde_mm_store_si128((simde__m128i*)ctx.v11.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v6.u16)));
	// vmrghh v5,v2,v8
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vmrghh v9,v3,v31
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vmrglh v6,v3,v31
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vmrglh v8,v2,v8
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vupkhsh v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v24.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v25.s16))));
loc_82746048:
	// vsubshs v3,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsubshs v29,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vsubshs v28,v6,v5
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vsubshs v2,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vsubshs v31,v7,v10
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vsubshs v30,v10,v9
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vsubshs v26,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vsubshs v22,v0,v29
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vsubshs v21,v0,v28
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vsubshs v23,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vsubshs v20,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vsubshs v19,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vsubshs v4,v5,v8
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vmaxsh v18,v26,v3
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vmaxsh v17,v21,v28
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vmaxsh v3,v22,v29
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vmaxsh v30,v23,v30
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vmaxsh v29,v20,v31
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vmaxsh v28,v19,v2
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vsubshs v26,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vcmpgtuh v23,v13,v17
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// vcmpgtuh v22,v13,v3
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vcmpgtuh v21,v13,v30
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	// vmaxsh v17,v26,v4
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vcmpgtuh v20,v13,v29
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// vcmpgtuh v19,v13,v28
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vcmpgtuh v18,v13,v18
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v18.u16)));
	// vaddshs v3,v22,v23
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v23.s16)));
	// vaddshs v2,v20,v21
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v21.s16)));
	// vcmpgtuh v30,v13,v17
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// vaddshs v31,v18,v19
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vaddshs v29,v2,v3
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v28,v30,v31
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vaddshs v26,v28,v29
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// vsubshs v3,v0,v26
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v26.s16)));
	// vperm v3,v3,v3,v1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// vcmpgtsh. v26,v3,v16
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v16.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v26.u16), 0xFFFF);
	// mfocrf r27,2
	ctx.r27.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r7,r27,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r7,32
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32, ctx.xer);
	// beq cr6,0x82746354
	if (ctx.cr6.eq) goto loc_82746354;
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
	// vminsh v23,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vmaxsh v22,v6,v5
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vmaxsh v21,v29,v30
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vminsh v20,v28,v23
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_min_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v23.s16)));
	// vmaxsh v19,v22,v21
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v21.s16)));
	// vsubshs v2,v19,v20
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v20.s16)));
	// vcmpgtsh. v17,v25,v2
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v17.u16), 0xFFFF);
	// vupkhsh v18,v2
	simde_mm_store_si128((simde__m128i*)ctx.v18.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16))));
	// vcmpgtsw. v31,v24,v18
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v24.u32), simde_mm_load_si128((simde__m128i*)ctx.v18.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v31.u32)), 0xF);
	// vand128 v63,v17,v26
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v26.u8)));
	// mfocrf r7,2
	ctx.r7.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupklsh v30,v2
	simde_mm_store_si128((simde__m128i*)ctx.v30.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vcmpgtsw. v29,v24,v30
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v24.u32), simde_mm_load_si128((simde__m128i*)ctx.v30.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v29.u32)), 0xF);
	// mfocrf r28,2
	ctx.r28.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupkhsh v28,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16))));
	// vcmpgtsw. v23,v28,v15
	simde_mm_store_si128((simde__m128i*)ctx.v23.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v28.u32), simde_mm_load_si128((simde__m128i*)ctx.v15.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v23.u32)), 0xF);
	// mfocrf r29,2
	ctx.r29.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// vupklsh v22,v3
	simde_mm_store_si128((simde__m128i*)ctx.v22.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsw. v21,v22,v15
	simde_mm_store_si128((simde__m128i*)ctx.v21.u32, simde_mm_cmpgt_epi32(simde_mm_load_si128((simde__m128i*)ctx.v22.u32), simde_mm_load_si128((simde__m128i*)ctx.v15.u32)));
	ctx.cr6.setFromMask(simde_mm_castsi128_ps(simde_mm_load_si128((simde__m128i*)ctx.v21.u32)), 0xF);
	// mfocrf r25,2
	ctx.r25.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm r24,r29,0,26,26
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x20;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// cmplwi cr6,r24,32
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 32, ctx.xer);
	// beq cr6,0x8274616c
	if (ctx.cr6.eq) goto loc_8274616C;
	// rlwinm r7,r7,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r7,32
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32, ctx.xer);
	// bne cr6,0x82746184
	if (!ctx.cr6.eq) goto loc_82746184;
loc_8274616C:
	// rlwinm r7,r29,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r7,32
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32, ctx.xer);
	// beq cr6,0x82746354
	if (ctx.cr6.eq) goto loc_82746354;
	// rlwinm r7,r28,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r7,32
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32, ctx.xer);
	// beq cr6,0x82746354
	if (ctx.cr6.eq) goto loc_82746354;
loc_82746184:
	// vsubshs v3,v11,v12
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// addi r7,r1,-176
	ctx.r7.s64 = ctx.r1.s64 + -176;
	// vsubshs v2,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// addi r26,r1,-192
	ctx.r26.s64 = ctx.r1.s64 + -192;
	// vor128 v43,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// addi r29,r1,-208
	ctx.r29.s64 = ctx.r1.s64 + -208;
	// vaddshs v31,v7,v10
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// addi r28,r1,-224
	ctx.r28.s64 = ctx.r1.s64 + -224;
	// vsubshs v30,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vmaxsh v29,v2,v4
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vor128 v42,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vaddshs v2,v31,v16
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// vmaxsh v28,v30,v3
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsh v23,v27,v29
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// vaddshs v31,v9,v6
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v22,v10,v5
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vcmpgtsh v21,v27,v28
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vandc128 v40,v5,v23
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vand128 v39,v8,v23
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v23.u8)));
	// vaddshs v20,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vandc128 v37,v11,v21
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vand128 v36,v12,v21
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v21.u8)));
	// vxor128 v8,v39,v40
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)ctx.v40.u8)));
	// vandc128 v41,v10,v63
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// vandc128 v38,v11,v63
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vxor128 v12,v36,v37
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v36.u8), simde_mm_load_si128((simde__m128i*)ctx.v37.u8)));
	// vaddshs v3,v5,v8
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vsubshs v19,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v18,v6,v8
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v30,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsubshs v17,v12,v6
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v29,v19,v3
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v4,v31,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v28,v30,v2
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vaddshs v23,v17,v30
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vaddshs v21,v12,v7
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v4,v2,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v3,v28,v31
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vandc128 v35,v7,v63
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vandc128 v34,v9,v63
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)));
	// vaddshs v20,v20,v4
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v19,v22,v3
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v17,v23,v3
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v3,v21,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v2,v18,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vsrah v31,v19,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v19.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v30,v17,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v17.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v28,v3,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v23,v29,v4
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vand128 v62,v31,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v61,v30,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vand128 v60,v28,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vsrah v22,v20,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v21,v2,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v20,v23,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v23.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vxor128 v29,v62,v41
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v41.u8)));
	// vxor128 v59,v61,v38
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v38.u8)));
	// vxor128 v58,v60,v35
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v35.u8)));
	// vandc128 v33,v6,v63
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vandc128 v32,v5,v63
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vand128 v57,v22,v63
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vpkshus128 v4,v43,v59
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v59.s16), simde_mm_load_si128((simde__m128i*)ctx.v43.s16)));
	// vand128 v56,v21,v63
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vpkshus128 v3,v58,v29
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v58.s16)));
	// vand128 v55,v20,v63
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vxor128 v28,v57,v34
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v34.u8)));
	// vxor128 v54,v56,v33
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v33.u8)));
	// vmrghb v30,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vxor128 v53,v55,v32
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v32.u8)));
	// vmrglb v4,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vpkshus128 v2,v28,v54
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v54.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// vpkshus128 v31,v53,v42
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v42.s16), simde_mm_load_si128((simde__m128i*)ctx.v53.s16)));
	// vmrglb v19,v30,v4
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vmrghb v18,v30,v4
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// vmrghb v3,v2,v31
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vmrglb v2,v2,v31
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// stvx128 v19,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v18,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,-180(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -180);
	// vmrghb v17,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// vmrglb v4,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// lwz r21,-192(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + -192);
	// stvx128 v4,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r20,-188(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + -188);
	// stvx128 v17,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r22,-184(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -184);
	// lwz r28,-176(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -176);
	// lwz r25,-172(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -172);
	// stw r21,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r21.u32);
	// stw r20,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r20.u32);
	// stw r22,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r22.u32);
	// stw r7,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r7.u32);
	// stw r28,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// lwz r7,-224(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -224);
	// stw r25,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r25.u32);
	// lwz r28,-220(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -220);
	// lwz r25,-216(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -216);
	// lwz r24,-168(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + -168);
	// lwz r23,-164(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -164);
	// lwz r29,-204(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -204);
	// lwz r26,-272(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -272);
	// stw r24,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r24.u32);
	// stw r23,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r23.u32);
	// lwz r19,-208(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + -208);
	// lwz r18,-200(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + -200);
	// lwz r17,-196(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -196);
	// stw r19,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r19.u32);
	// stw r29,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r29.u32);
	// stw r18,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r18.u32);
	// stw r17,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r17.u32);
	// stw r7,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// lwz r29,-212(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -212);
	// stw r25,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r25.u32);
	// stw r29,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r29.u32);
	// b 0x8274635c
	goto loc_8274635C;
loc_82746354:
	// vor v28,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vor v29,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
loc_8274635C:
	// rlwinm r7,r27,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,128
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 128, ctx.xer);
	// beq cr6,0x82746420
	if (ctx.cr6.eq) goto loc_82746420;
	// vsubshs v3,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vxor128 v52,v14,v26
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v26.u8)));
	// vsubshs v4,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vmaxsh v4,v4,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_max_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vcmpgtsh v2,v27,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vcmpgtsh v31,v4,v13
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_cmpgt_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// vand128 v51,v31,v2
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vand128 v2,v51,v52
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v52.u8)));
	// vcmpequh. v30,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_cmpeq_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), 0xFFFF);
	// blt cr6,0x82746420
	if (ctx.cr6.lt) goto loc_82746420;
	// vspltish v31,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_set1_epi16(short(0x2)));
	// addi r29,r1,-240
	ctx.r29.s64 = ctx.r1.s64 + -240;
	// vspltish v30,15
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_set1_epi16(short(0xF)));
	// addi r7,r1,-256
	ctx.r7.s64 = ctx.r1.s64 + -256;
	// vsrah v4,v4,v31
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v26,v3,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v23,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vand v22,v26,v23
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v23.u8)));
	// vsubshs v21,v4,v22
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v22.s16)));
	// vand v4,v21,v2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vaddshs v20,v29,v4
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vsubshs v19,v28,v4
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vpkshus v18,v20,v20
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v20.s16)));
	// vpkshus v17,v19,v19
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vmrghb v4,v18,v17
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)));
	// vmrghh v2,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// vmrglh v3,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// stvx128 v2,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r28,-236(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -236);
	// stvx128 v3,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,-252(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -252);
	// lwz r29,-240(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -240);
	// lwz r25,-228(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -228);
	// lwz r27,-232(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -232);
	// lwz r24,-256(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// sth r29,3(r9)
	REX_STORE_U16(ctx.r9.u32 + 3, ctx.r29.u16);
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// lwz r25,-248(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -248);
	// sth r28,3(r6)
	REX_STORE_U16(ctx.r6.u32 + 3, ctx.r28.u16);
	// sth r27,3(r5)
	REX_STORE_U16(ctx.r5.u32 + 3, ctx.r27.u16);
	// sth r29,3(r4)
	REX_STORE_U16(ctx.r4.u32 + 3, ctx.r29.u16);
	// sth r24,3(r3)
	REX_STORE_U16(ctx.r3.u32 + 3, ctx.r24.u16);
	// sth r7,3(r31)
	REX_STORE_U16(ctx.r31.u32 + 3, ctx.r7.u16);
	// lwz r28,-244(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -244);
	// sth r25,3(r30)
	REX_STORE_U16(ctx.r30.u32 + 3, ctx.r25.u16);
	// sth r28,3(r8)
	REX_STORE_U16(ctx.r8.u32 + 3, ctx.r28.u16);
loc_82746420:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x82746528
	if (!ctx.cr6.eq) goto loc_82746528;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 + ctx.r10.u64;
	// add r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 + ctx.r10.u64;
	// add r4,r4,r10
	ctx.r4.u64 = ctx.r4.u64 + ctx.r10.u64;
	// add r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 + ctx.r10.u64;
	// add r31,r31,r10
	ctx.r31.u64 = ctx.r31.u64 + ctx.r10.u64;
	// lvlx128 v50,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r30,r30,r10
	ctx.r30.u64 = ctx.r30.u64 + ctx.r10.u64;
	// lvlx128 v49,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lvlx128 v48,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v47,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v46,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v45,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v44,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v43,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v42,r11,r9
	temp.u32 = ctx.r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvrx128 v41,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v12,v50,v42
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v42.u8)));
	// lvrx128 v40,r11,r5
	temp.u32 = ctx.r11.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v11,v49,v41
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v41.u8)));
	// lvrx128 v39,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v10,v48,v40
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v40.u8)));
	// lvrx128 v38,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v9,v47,v39
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v39.u8)));
	// lvrx128 v37,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v8,v46,v38
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v38.u8)));
	// lvrx128 v36,r11,r30
	temp.u32 = ctx.r11.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v7,v45,v37
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)ctx.v37.u8)));
	// lvrx128 v35,r11,r8
	temp.u32 = ctx.r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(REX_LOAD_VECTOR(temp.u32 & ~0xF), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v6,v44,v36
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)ctx.v36.u8)));
	// vor128 v5,v43,v35
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v43.u8), simde_mm_load_si128((simde__m128i*)ctx.v35.u8)));
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
loc_82746528:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// stw r26,-272(r1)
	REX_STORE_U32(ctx.r1.u32 + -272, ctx.r26.u32);
	// cmpwi cr6,r26,2
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 2, ctx.xer);
	// blt cr6,0x82746048
	if (ctx.cr6.lt) goto loc_82746048;
loc_82746538:
	// b 0x827566d4
	__restgprlr_15(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827CB7F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,23060(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23060);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6468(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6468, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D06D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,24176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4124(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4124, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D7BC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,25792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,-680(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -680, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D8CB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,26120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-284(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -284);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-172(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -172, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E1298) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,28476(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28476);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3788(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3788, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F5C10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,32348(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32348);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13484(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13484, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F9F88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-32568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,15416(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15416);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,15476(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 15476, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FAEF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-32424
	ctx.r9.s64 = ctx.r11.s64 + -32424;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-32424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,15928(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 15928, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FFAA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,18152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18156(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18156, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280A438) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-20168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,22772(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 22772);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,22912(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 22912, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280B868) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-18844(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18844);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23464(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23464, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280E640) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-16972(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16972);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24732(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24732, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828107A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-15504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25664(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25664, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82812620) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-14560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26772(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26772, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82817E68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-8360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29108(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29108);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29220(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29220, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281EF00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-7192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10208(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10208);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32416(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32416);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32504(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32504, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82823708) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-6420(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6420);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30936(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30936, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82826BA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-29400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29396(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29396, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82832108) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-3208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-24100(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -24100);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23992(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23992, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82837318) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-1636(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1636);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21540, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283B3D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,-536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19720(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19720);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19604(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19604, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283D1B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-18732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18732);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18728(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18728, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82842970) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-16120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16116(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16116, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82848E68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,2760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-13248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -13248);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13144(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13144, temp.u32);
	// blr
	return;
}

