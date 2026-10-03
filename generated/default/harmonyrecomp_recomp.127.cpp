#include "harmonyrecomp_funcs.127.h"

DEFINE_REX_FUNC(sub_82223170) {
	REX_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r12)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r12.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82223190) {
	REX_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,44(r12)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r12.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_822231C0) {
	REX_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r12)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r12.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_8223B5E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8223B5F0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r4,r11,2940
	ctx.r4.s64 = ctx.r11.s64 + 2940;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x822334a8
	ctx.lr = 0x8223B608;
	sub_822334A8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r10,502
	ctx.r10.s64 = 502;
	// addi r11,r11,4608
	ctx.r11.s64 = ctx.r11.s64 + 4608;
	// sth r10,96(r31)
	REX_STORE_U16(ctx.r31.u32 + 96, ctx.r10.u16);
	// lis r10,-32113
	ctx.r10.s64 = -2104557568;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r10,22392
	ctx.r11.s64 = ctx.r10.s64 + 22392;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r30,r31,100
	ctx.r30.s64 = ctx.r31.s64 + 100;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825fc4b0
	ctx.lr = 0x8223B638;
	sub_825FC4B0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8223b64c
	if (ctx.cr0.eq) goto loc_8223B64C;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// b 0x8223b650
	goto loc_8223B650;
loc_8223B64C:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_8223B650:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stw r11,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// addi r7,r10,12252
	ctx.r7.s64 = ctx.r10.s64 + 12252;
	// stw r11,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// addi r9,r9,4436
	ctx.r9.s64 = ctx.r9.s64 + 4436;
	// stw r11,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r11.u32);
	// stw r8,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r8.u32);
	// lfs f13,12252(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12252);
	ctx.f13.f64 = double(temp.f32);
	// stw r9,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r9.u32);
	// addi r10,r31,132
	ctx.r10.s64 = ctx.r31.s64 + 132;
	// stb r11,140(r31)
	REX_STORE_U8(ctx.r31.u32 + 140, ctx.r11.u8);
	// lfs f0,232(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
	// stw r11,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r10,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r10.u32);
	// stfs f0,168(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 168, temp.u32);
	// stfs f13,172(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 172, temp.u32);
	// stb r11,164(r31)
	REX_STORE_U8(ctx.r31.u32 + 164, ctx.r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82240348) {
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
	// clrlwi. r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82240374
	if (!ctx.cr0.eq) goto loc_82240374;
	// lbz r11,293(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 293);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82240374
	if (ctx.cr0.eq) goto loc_82240374;
	// lbz r3,294(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 294);
	// b 0x822403c8
	goto loc_822403C8;
loc_82240374:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lfs f0,88(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,92(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// li r31,1
	ctx.r31.s64 = 1;
	// lwz r11,-9960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9960);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822403c4
	if (ctx.cr6.eq) goto loc_822403C4;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// bl 0x823c2d80
	ctx.lr = 0x822403B8;
	sub_823C2D80(ctx, base);
	// rlwinm r11,r3,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// and r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 & ctx.r31.u64;
loc_822403C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_822403C8:
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

DEFINE_REX_FUNC(sub_82247F68) {
	REX_FUNC_PROLOGUE();
	// lwz r9,592(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 592);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r10,r3,600
	ctx.r10.s64 = ctx.r3.s64 + 600;
loc_82247F7C:
	// lbz r8,-4(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + -4);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x82247f94
	if (ctx.cr0.eq) goto loc_82247F94;
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x82247fa8
	if (ctx.cr6.eq) goto loc_82247FA8;
loc_82247F94:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,3856
	ctx.r10.s64 = ctx.r10.s64 + 3856;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82247f7c
	if (ctx.cr6.lt) goto loc_82247F7C;
	// blr
	return;
loc_82247FA8:
	// mulli r11,r11,3856
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(3856));
	// add r10,r11,r3
	ctx.r10.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r10,4448(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4448);
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// addi r10,r5,11
	ctx.r10.s64 = ctx.r5.s64 + 11;
	// mulli r10,r10,60
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(60));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stwx r4,r11,r3
	REX_STORE_U32(ctx.r11.u32 + ctx.r3.u32, ctx.r4.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8224B250) {
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
	// lwz r6,4(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,0(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// bl 0x8224e460
	ctx.lr = 0x8224B278;
	sub_8224E460(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8224b288
	if (ctx.cr6.eq) goto loc_8224B288;
	// bl 0x825fc588
	ctx.lr = 0x8224B288;
	sub_825FC588(ctx, base);
loc_8224B288:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_8224D6F0) {
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
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x8224d758
	goto loc_8224D758;
loc_8224D718:
	// lwz r10,116(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8224d74c
	if (!ctx.cr6.gt) goto loc_8224D74C;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// bl 0x825b65c0
	ctx.lr = 0x8224D738;
	sub_825B65C0(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,44
	ctx.r4.s64 = ctx.r31.s64 + 44;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x825bd9a0
	ctx.lr = 0x8224D748;
	sub_825BD9A0(ctx, base);
	// b 0x8224d750
	goto loc_8224D750;
loc_8224D74C:
	// bl 0x825b65c0
	ctx.lr = 0x8224D750;
	sub_825B65C0(ctx, base);
loc_8224D750:
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8224D758:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8224d718
	if (!ctx.cr6.eq) goto loc_8224D718;
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x8224d7b0
	goto loc_8224D7B0;
loc_8224D770:
	// lwz r10,116(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8224d7a4
	if (!ctx.cr6.gt) goto loc_8224D7A4;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// bl 0x825b65c0
	ctx.lr = 0x8224D790;
	sub_825B65C0(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,56
	ctx.r4.s64 = ctx.r31.s64 + 56;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x825bd9a0
	ctx.lr = 0x8224D7A0;
	sub_825BD9A0(ctx, base);
	// b 0x8224d7a8
	goto loc_8224D7A8;
loc_8224D7A4:
	// bl 0x825b65c0
	ctx.lr = 0x8224D7A8;
	sub_825B65C0(ctx, base);
loc_8224D7A8:
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8224D7B0:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8224d770
	if (!ctx.cr6.eq) goto loc_8224D770;
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// b 0x8224d820
	goto loc_8224D820;
loc_8224D7C8:
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8224d810
	if (!ctx.cr6.gt) goto loc_8224D810;
	// lwz r3,16(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8224d7ec
	if (ctx.cr6.eq) goto loc_8224D7EC;
	// bl 0x825fc588
	ctx.lr = 0x8224D7EC;
	sub_825FC588(ctx, base);
loc_8224D7EC:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// bl 0x825b65c0
	ctx.lr = 0x8224D7FC;
	sub_825B65C0(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,104
	ctx.r4.s64 = ctx.r31.s64 + 104;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x825bd9a0
	ctx.lr = 0x8224D80C;
	sub_825BD9A0(ctx, base);
	// b 0x8224d818
	goto loc_8224D818;
loc_8224D810:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825b65c0
	ctx.lr = 0x8224D818;
	sub_825B65C0(ctx, base);
loc_8224D818:
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8224D820:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8224d7c8
	if (!ctx.cr6.eq) goto loc_8224D7C8;
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

DEFINE_REX_FUNC(sub_82259888) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a0
	ctx.lr = 0x82259890;
	__savegprlr_22(ctx, base);
	// stfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f30.u64);
	// stfd f31,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r27,r3,1
	ctx.r27.s64 = ctx.r3.s64 + 65536;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// addi r27,r27,-3112
	ctx.r27.s64 = ctx.r27.s64 + -3112;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,476(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 476);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822598BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,68
	ctx.r11.s64 = 68;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// divw. r11,r10,r11
	ctx.r11.u64 = uint32_t((ctx.r11.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r10.s32 / ctx.r11.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82259bdc
	if (ctx.cr0.eq) goto loc_82259BDC;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,476(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 476);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822598E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,476(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 476);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82259908;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r23,8(r11)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x82371af8
	ctx.lr = 0x82259920;
	sub_82371AF8(ctx, base);
	// cmplw cr6,r30,r23
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r23.u32, ctx.xer);
	// beq cr6,0x82259b74
	if (ctx.cr6.eq) goto loc_82259B74;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// addi r29,r11,-28872
	ctx.r29.s64 = ctx.r11.s64 + -28872;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r26,-32113
	ctx.r26.s64 = -2104557568;
	// lfs f31,12484(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12484);
	ctx.f31.f64 = double(temp.f32);
	// lis r25,-32110
	ctx.r25.s64 = -2104360960;
	// lfs f30,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// addi r28,r11,22392
	ctx.r28.s64 = ctx.r11.s64 + 22392;
	// addi r24,r10,2940
	ctx.r24.s64 = ctx.r10.s64 + 2940;
loc_82259954:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82259970
	if (!ctx.cr6.eq) goto loc_82259970;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x822491d0
	ctx.lr = 0x8225996C;
	sub_822491D0(ctx, base);
	// b 0x822599dc
	goto loc_822599DC;
loc_82259970:
	// lbz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 4);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82259994
	if (ctx.cr0.eq) goto loc_82259994;
	// addis r4,r22,1
	ctx.r4.s64 = ctx.r22.s64 + 65536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,-3148
	ctx.r4.s64 = ctx.r4.s64 + -3148;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x822490e8
	ctx.lr = 0x82259994;
	sub_822490E8(ctx, base);
loc_82259994:
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,368(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 368);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822599AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x822599dc
	if (ctx.cr0.eq) goto loc_822599DC;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_822599B8:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x822599b8
	if (!ctx.cr6.eq) goto loc_822599B8;
	// subf r11,r4,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r4.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x822492f8
	ctx.lr = 0x822599DC;
	sub_822492F8(ctx, base);
loc_822599DC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// li r4,120
	ctx.r4.s64 = 120;
	// bl 0x825fc4b0
	ctx.lr = 0x822599EC;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82259a70
	if (ctx.cr0.eq) goto loc_82259A70;
	// lfs f0,60(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82259a0c
	if (!ctx.cr6.lt) goto loc_82259A0C;
	// lfs f0,-3736(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -3736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24328(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 24328);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
loc_82259A0C:
	// lhz r11,6(r22)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r22.u32 + 6);
	// lfs f12,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r10,152(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfs f13,21708(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 21708);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,16(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f12,112(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// bge cr6,0x82259a50
	if (!ctx.cr6.lt) goto loc_82259A50;
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
loc_82259A50:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lfs f2,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 48);
	ctx.f2.f64 = double(temp.f32);
	// ld r7,88(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x822501b0
	ctx.lr = 0x82259A68;
	sub_822501B0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82259a74
	goto loc_82259A74;
loc_82259A70:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82259A74:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82259b68
	if (ctx.cr6.eq) goto loc_82259B68;
	// lfs f0,36(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f13,32(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82259AA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,44(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lfs f13,40(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82259ACC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82259AE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 52);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 112, temp.u32);
	// lfs f0,56(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 116, temp.u32);
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// stb r11,90(r31)
	REX_STORE_U8(ctx.r31.u32 + 90, ctx.r11.u8);
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// lfs f0,48(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfs f0,108(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// lwz r11,64(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82259b20
	if (!ctx.cr6.lt) goto loc_82259B20;
	// li r11,3
	ctx.r11.s64 = 3;
loc_82259B20:
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
	ctx.lr = 0x82259B38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822328e8
	ctx.lr = 0x82259B44;
	sub_822328E8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82259b68
	if (!ctx.cr6.eq) goto loc_82259B68;
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
	ctx.lr = 0x82259B68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82259B68:
	// addi r30,r30,68
	ctx.r30.s64 = ctx.r30.s64 + 68;
	// cmplw cr6,r30,r23
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r23.u32, ctx.xer);
	// bne cr6,0x82259954
	if (!ctx.cr6.eq) goto loc_82259954;
loc_82259B74:
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,476(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 476);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82259B88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,4(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r31,8(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82259bcc
	if (ctx.cr6.eq) goto loc_82259BCC;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r31
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82259bc8
	if (ctx.cr6.eq) goto loc_82259BC8;
loc_82259BA8:
	// li r5,68
	ctx.r5.s64 = 68;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827567d0
	ctx.lr = 0x82259BB8;
	sub_827567D0(ctx, base);
	// addi r30,r30,68
	ctx.r30.s64 = ctx.r30.s64 + 68;
	// addi r29,r29,68
	ctx.r29.s64 = ctx.r29.s64 + 68;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x82259ba8
	if (!ctx.cr6.eq) goto loc_82259BA8;
loc_82259BC8:
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
loc_82259BCC:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82371af8
	ctx.lr = 0x82259BDC;
	sub_82371AF8(ctx, base);
loc_82259BDC:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822759C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x822759C8;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r24,r3,1
	ctx.r24.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r24,r24,-3160
	ctx.r24.s64 = ctx.r24.s64 + -3160;
	// lwz r10,0(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// bgt cr6,0x82276538
	if (ctx.cr6.gt) goto loc_82276538;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,13184
	ctx.r8.s64 = ctx.r11.s64 + 13184;
	// ori r11,r9,63168
	ctx.r11.u64 = ctx.r9.u64 | 63168;
	// lfs f1,-700(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -700);
	ctx.f1.f64 = double(temp.f32);
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// rlwinm r0,r10,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r12,r12,-4592
	ctx.r12.s64 = ctx.r12.s64 + -4592;
	// lhzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32217
	ctx.r12.s64 = -2111373312;
	// addi r12,r12,23080
	ctx.r12.s64 = ctx.r12.s64 + 23080;
	// nop
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr
	switch (ctx.r10.u32) {
	case 0:
		goto loc_82275A28;
	case 1:
		goto loc_82275A5C;
	case 2:
		goto loc_82275CAC;
	case 3:
		goto loc_82275CDC;
	case 4:
		goto loc_82275D30;
	case 5:
		goto loc_82275D64;
	case 6:
		goto loc_82275F34;
	case 7:
		goto loc_82275F84;
	case 8:
		goto loc_822763AC;
	case 9:
		goto loc_82276498;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82275A28:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,264(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r11,r11,13184
	ctx.r11.s64 = ctx.r11.s64 + 13184;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f1,-700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -700);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8225cec0
	ctx.lr = 0x82275A50;
	sub_8225CEC0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
loc_82275A54:
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// b 0x82276538
	goto loc_82276538;
loc_82275A5C:
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r28,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r28.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r28,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r28.u32);
	// bl 0x8243f6d0
	ctx.lr = 0x82275A74;
	sub_8243F6D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82275b6c
	if (ctx.cr0.eq) goto loc_82275B6C;
	// bl 0x8243f6d0
	ctx.lr = 0x82275A80;
	sub_8243F6D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82275aa8
	if (ctx.cr0.eq) goto loc_82275AA8;
	// bl 0x82441b00
	ctx.lr = 0x82275A8C;
	sub_82441B00(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82275a9c
	if (!ctx.cr0.eq) goto loc_82275A9C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x82275aa0
	goto loc_82275AA0;
loc_82275A9C:
	// bl 0x82441f48
	ctx.lr = 0x82275AA0;
	sub_82441F48(ctx, base);
loc_82275AA0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82275b6c
	if (!ctx.cr0.eq) goto loc_82275B6C;
loc_82275AA8:
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// addi r31,r31,-2412
	ctx.r31.s64 = ctx.r31.s64 + -2412;
	// lbz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82276538
	if (ctx.cr0.eq) goto loc_82276538;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62506
	ctx.r11.u64 = ctx.r11.u64 | 62506;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82276538
	if (ctx.cr0.eq) goto loc_82276538;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62507
	ctx.r11.u64 = ctx.r11.u64 | 62507;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82275af0
	if (ctx.cr0.eq) goto loc_82275AF0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,8528
	ctx.r3.s64 = ctx.r11.s64 + 8528;
	// b 0x82275af8
	goto loc_82275AF8;
loc_82275AF0:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,8544
	ctx.r3.s64 = ctx.r11.s64 + 8544;
loc_82275AF8:
	// bl 0x82599468
	ctx.lr = 0x82275AFC;
	sub_82599468(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addis r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 65536;
	// stb r28,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// ori r11,r11,62576
	ctx.r11.u64 = ctx.r11.u64 | 62576;
	// addi r10,r10,-3112
	ctx.r10.s64 = ctx.r10.s64 + -3112;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r8,r8,62508
	ctx.r8.u64 = ctx.r8.u64 | 62508;
	// stwx r3,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r3.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f12,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r11,13184
	ctx.r9.s64 = ctx.r11.s64 + 13184;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lfs f0,-932(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -932);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,-9776(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9776);
	// lfs f13,-700(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -700);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfsx f0,r30,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r8.u32, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82275b54
	if (ctx.cr6.eq) goto loc_82275B54;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82599f08
	ctx.lr = 0x82275B54;
	sub_82599F08(ctx, base);
loc_82275B54:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82224210
	ctx.lr = 0x82275B60;
	sub_82224210(ctx, base);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r9.u32);
	// b 0x82275c90
	goto loc_82275C90;
loc_82275B6C:
	// addi r4,r1,148
	ctx.r4.s64 = ctx.r1.s64 + 148;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82278960
	ctx.lr = 0x82275B78;
	sub_82278960(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82276538
	if (ctx.cr0.eq) goto loc_82276538;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r10,148(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// li r8,2
	ctx.r8.s64 = 2;
	// rlwinm r9,r10,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFF0;
	// stw r8,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r8.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// lwz r11,-9744(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9744);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82275be8
	if (!ctx.cr6.eq) goto loc_82275BE8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82275be8
	if (ctx.cr6.eq) goto loc_82275BE8;
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82275be8
	if (ctx.cr6.eq) goto loc_82275BE8;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,576(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 576);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82275BDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x82275be8
	if (!ctx.cr6.eq) goto loc_82275BE8;
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
loc_82275BE8:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62506
	ctx.r11.u64 = ctx.r11.u64 | 62506;
	// ori r10,r10,62507
	ctx.r10.u64 = ctx.r10.u64 | 62507;
	// clrlwi. r9,r28,24
	ctx.r9.u64 = ctx.r28.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stbx r29,r30,r11
	REX_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r29.u8);
	// stbx r28,r30,r10
	REX_STORE_U8(ctx.r30.u32 + ctx.r10.u32, ctx.r28.u8);
	// beq 0x82275c14
	if (ctx.cr0.eq) goto loc_82275C14;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,8528
	ctx.r3.s64 = ctx.r11.s64 + 8528;
	// b 0x82275c1c
	goto loc_82275C1C;
loc_82275C14:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,8544
	ctx.r3.s64 = ctx.r11.s64 + 8544;
loc_82275C1C:
	// bl 0x82599468
	ctx.lr = 0x82275C20;
	sub_82599468(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62576
	ctx.r11.u64 = ctx.r11.u64 | 62576;
	// stwx r3,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r3.u32);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9776(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9776);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82275c44
	if (ctx.cr6.eq) goto loc_82275C44;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82599f08
	ctx.lr = 0x82275C44;
	sub_82599F08(ctx, base);
loc_82275C44:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82224210
	ctx.lr = 0x82275C50;
	sub_82224210(ctx, base);
	// bl 0x8243f6d0
	ctx.lr = 0x82275C54;
	sub_8243F6D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82275c78
	if (ctx.cr0.eq) goto loc_82275C78;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822796e0
	ctx.lr = 0x82275C68;
	sub_822796E0(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,13184
	ctx.r11.s64 = ctx.r11.s64 + 13184;
	// lfs f0,-932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -932);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82275c84
	goto loc_82275C84;
loc_82275C78:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,13184
	ctx.r11.s64 = ctx.r11.s64 + 13184;
	// lfs f0,-700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -700);
	ctx.f0.f64 = double(temp.f32);
loc_82275C84:
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,62508
	ctx.r10.u64 = ctx.r10.u64 | 62508;
	// stfsx f0,r30,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, temp.u32);
loc_82275C90:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// ori r10,r10,63168
	ctx.r10.u64 = ctx.r10.u64 | 63168;
	// lfs f0,1764(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1764);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r30,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, temp.u32);
	// b 0x82276538
	goto loc_82276538;
loc_82275CAC:
	// addis r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 65536;
	// lfsx f0,r30,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfsx f0,r30,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, temp.u32);
	// addi r10,r10,-3028
	ctx.r10.s64 = ctx.r10.s64 + -3028;
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bgt cr6,0x82275cdc
	if (ctx.cr6.gt) goto loc_82275CDC;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
loc_82275CDC:
	// lfsx f0,r30,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// add r31,r30,r11
	ctx.r31.u64 = ctx.r30.u64 + ctx.r11.u64;
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfsx f0,r30,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, temp.u32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bge cr6,0x82276538
	if (!ctx.cr6.lt) goto loc_82276538;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x82275D10;
	sub_8225CEC0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// stfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// ori r11,r11,62576
	ctx.r11.u64 = ctx.r11.u64 | 62576;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
	// stwx r9,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r9.u32);
	// b 0x82276538
	goto loc_82276538;
loc_82275D30:
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r10,r10,-2040
	ctx.r10.s64 = ctx.r10.s64 + -2040;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,-4288(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4288);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f13,104(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82276538
	if (!ctx.cr6.gt) goto loc_82276538;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82278bf8
	ctx.lr = 0x82275D5C;
	sub_82278BF8(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x82275a54
	goto loc_82275A54;
loc_82275D64:
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,73(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 73);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82276538
	if (!ctx.cr0.eq) goto loc_82276538;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r11,-30336
	ctx.r11.s64 = ctx.r11.s64 + -30336;
	// addi r10,r10,-30000
	ctx.r10.s64 = ctx.r10.s64 + -30000;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// li r31,255
	ctx.r31.s64 = 255;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,128
	ctx.r11.s64 = 128;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r31,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r31.u8);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,91(r1)
	REX_STORE_U8(ctx.r1.u32 + 91, ctx.r11.u8);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,131(r1)
	REX_STORE_U8(ctx.r1.u32 + 131, ctx.r11.u8);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stb r31,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r31.u8);
	// stb r31,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r31.u8);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,13184
	ctx.r11.s64 = ctx.r11.s64 + 13184;
	// stb r31,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r31.u8);
	// stb r31,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r31.u8);
	// li r10,6
	ctx.r10.s64 = 6;
	// stb r31,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r31.u8);
	// addi r27,r30,88
	ctx.r27.s64 = ctx.r30.s64 + 88;
	// stb r31,90(r1)
	REX_STORE_U8(ctx.r1.u32 + 90, ctx.r31.u8);
	// li r29,1
	ctx.r29.s64 = 1;
	// stb r31,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r31.u8);
	// stb r31,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r31.u8);
	// lfs f11,-700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -700);
	ctx.f11.f64 = double(temp.f32);
	// stb r31,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r31.u8);
	// lfs f10,1208(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1208);
	ctx.f10.f64 = double(temp.f32);
	// stb r31,104(r1)
	REX_STORE_U8(ctx.r1.u32 + 104, ctx.r31.u8);
	// stb r31,105(r1)
	REX_STORE_U8(ctx.r1.u32 + 105, ctx.r31.u8);
	// stb r31,106(r1)
	REX_STORE_U8(ctx.r1.u32 + 106, ctx.r31.u8);
	// stb r31,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r31.u8);
	// stb r31,113(r1)
	REX_STORE_U8(ctx.r1.u32 + 113, ctx.r31.u8);
	// stb r31,114(r1)
	REX_STORE_U8(ctx.r1.u32 + 114, ctx.r31.u8);
	// stb r31,115(r1)
	REX_STORE_U8(ctx.r1.u32 + 115, ctx.r31.u8);
	// stb r31,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r31.u8);
	// stb r31,129(r1)
	REX_STORE_U8(ctx.r1.u32 + 129, ctx.r31.u8);
	// stb r31,130(r1)
	REX_STORE_U8(ctx.r1.u32 + 130, ctx.r31.u8);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stb r31,144(r1)
	REX_STORE_U8(ctx.r1.u32 + 144, ctx.r31.u8);
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stb r31,145(r1)
	REX_STORE_U8(ctx.r1.u32 + 145, ctx.r31.u8);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stb r31,146(r1)
	REX_STORE_U8(ctx.r1.u32 + 146, ctx.r31.u8);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stb r31,148(r1)
	REX_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// stb r31,149(r1)
	REX_STORE_U8(ctx.r1.u32 + 149, ctx.r31.u8);
	// stb r31,150(r1)
	REX_STORE_U8(ctx.r1.u32 + 150, ctx.r31.u8);
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// stw r10,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
	// li r30,2
	ctx.r30.s64 = 2;
	// addi r31,r31,-2856
	ctx.r31.s64 = ctx.r31.s64 + -2856;
	// stb r28,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r28.u8);
	// stb r28,107(r1)
	REX_STORE_U8(ctx.r1.u32 + 107, ctx.r28.u8);
	// stb r28,147(r1)
	REX_STORE_U8(ctx.r1.u32 + 147, ctx.r28.u8);
	// stb r28,151(r1)
	REX_STORE_U8(ctx.r1.u32 + 151, ctx.r28.u8);
loc_82275E68:
	// stfs f11,-76(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + -76, temp.u32);
	// stb r29,-52(r31)
	REX_STORE_U8(ctx.r31.u32 + -52, ctx.r29.u8);
	// stfs f11,-72(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + -72, temp.u32);
	// addi r5,r1,152
	ctx.r5.s64 = ctx.r1.s64 + 152;
	// stfs f11,-48(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + -48, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x824d3cb8
	ctx.lr = 0x82275E88;
	sub_824D3CB8(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r8,104(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r5,128(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r4,144(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r26,148(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// stw r7,-92(r31)
	REX_STORE_U32(ctx.r31.u32 + -92, ctx.r7.u32);
	// lwz r7,4(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f11,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// stw r7,-88(r31)
	REX_STORE_U32(ctx.r31.u32 + -88, ctx.r7.u32);
	// stfs f11,40(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// ld r7,-92(r31)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r31.u32 + -92);
	// stfs f10,64(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// stw r11,-68(r31)
	REX_STORE_U32(ctx.r31.u32 + -68, ctx.r11.u32);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// stw r10,-64(r31)
	REX_STORE_U32(ctx.r31.u32 + -64, ctx.r10.u32);
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// stw r9,-60(r31)
	REX_STORE_U32(ctx.r31.u32 + -60, ctx.r9.u32);
	// stw r8,-56(r31)
	REX_STORE_U32(ctx.r31.u32 + -56, ctx.r8.u32);
	// stb r28,60(r31)
	REX_STORE_U8(ctx.r31.u32 + 60, ctx.r28.u8);
	// std r7,20(r31)
	REX_STORE_U64(ctx.r31.u32 + 20, ctx.r7.u64);
	// std r7,-84(r31)
	REX_STORE_U64(ctx.r31.u32 + -84, ctx.r7.u64);
	// std r7,28(r31)
	REX_STORE_U64(ctx.r31.u32 + 28, ctx.r7.u64);
	// stw r6,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// stw r5,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r5.u32);
	// stw r4,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r4.u32);
	// stwu r26,56(r31)
	ea = 56 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r26.u32);
	ctx.r31.u32 = ea;
	// bne 0x82275e68
	if (!ctx.cr0.eq) goto loc_82275E68;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,8432
	ctx.r3.s64 = ctx.r11.s64 + 8432;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x825993b0
	ctx.lr = 0x82275F1C;
	sub_825993B0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,8560
	ctx.r3.s64 = ctx.r11.s64 + 8560;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x825993b0
	ctx.lr = 0x82275F30;
	sub_825993B0(ctx, base);
	// b 0x82276538
	goto loc_82276538;
loc_82275F34:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,13184
	ctx.r11.s64 = ctx.r11.s64 + 13184;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r10,r10,62448
	ctx.r10.u64 = ctx.r10.u64 | 62448;
	// ori r9,r9,62440
	ctx.r9.u64 = ctx.r9.u64 | 62440;
	// lfs f0,-700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -700);
	ctx.f0.f64 = double(temp.f32);
	// ori r8,r8,62436
	ctx.r8.u64 = ctx.r8.u64 | 62436;
	// ori r7,r7,62450
	ctx.r7.u64 = ctx.r7.u64 | 62450;
	// li r6,7
	ctx.r6.s64 = 7;
	// li r11,255
	ctx.r11.s64 = 255;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfsx f0,r30,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r9.u32, temp.u32);
	// stfsx f0,r30,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r8.u32, temp.u32);
	// stw r6,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r6.u32);
	// sthx r11,r30,r10
	REX_STORE_U16(ctx.r30.u32 + ctx.r10.u32, ctx.r11.u16);
	// stbx r5,r30,r7
	REX_STORE_U8(ctx.r30.u32 + ctx.r7.u32, ctx.r5.u8);
	// b 0x82276538
	goto loc_82276538;
loc_82275F84:
	// addis r29,r30,1
	ctx.r29.s64 = ctx.r30.s64 + 65536;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r29,r29,-3088
	ctx.r29.s64 = ctx.r29.s64 + -3088;
	// addi r26,r11,13184
	ctx.r26.s64 = ctx.r11.s64 + 13184;
	// addis r25,r30,1
	ctx.r25.s64 = ctx.r30.s64 + 65536;
	// addis r27,r30,1
	ctx.r27.s64 = ctx.r30.s64 + 65536;
	// addi r25,r25,-3100
	ctx.r25.s64 = ctx.r25.s64 + -3100;
	// lha r11,0(r29)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r29.u32 + 0));
	// addi r27,r27,-3096
	ctx.r27.s64 = ctx.r27.s64 + -3096;
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f0,f31
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfs f13,1920(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 1920);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r28,0
	ctx.r28.s64 = 0;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f12,0(r25)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r25.u32 + 0, temp.u32);
	// stfs f0,0(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// lfd f11,152(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fnmsubs f13,f12,f13,f11
	ctx.f13.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f13.f64, -ctx.f11.f64)));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.f13.u64);
	// lhz r11,158(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 158);
	// extsh. r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sth r11,0(r29)
	REX_STORE_U16(ctx.r29.u32 + 0, ctx.r11.u16);
	// bge 0x82275ff8
	if (!ctx.cr0.lt) goto loc_82275FF8;
	// sth r28,0(r29)
	REX_STORE_U16(ctx.r29.u32 + 0, ctx.r28.u16);
loc_82275FF8:
	// lfs f13,-932(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -932);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82276040
	if (!ctx.cr6.gt) goto loc_82276040;
	// sth r28,0(r29)
	REX_STORE_U16(ctx.r29.u32 + 0, ctx.r28.u16);
	// lwz r11,268(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 268);
	// lwz r10,264(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82276038
	if (ctx.cr0.eq) goto loc_82276038;
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
	ctx.lr = 0x82276038;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82276038:
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
loc_82276040:
	// lwz r10,264(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// li r31,255
	ctx.r31.s64 = 255;
	// lhz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 0);
	// stb r31,148(r1)
	REX_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// stb r31,149(r1)
	REX_STORE_U8(ctx.r1.u32 + 149, ctx.r31.u8);
	// stb r31,150(r1)
	REX_STORE_U8(ctx.r1.u32 + 150, ctx.r31.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stb r11,151(r1)
	REX_STORE_U8(ctx.r1.u32 + 151, ctx.r11.u8);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82276074;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1708(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 1708);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x822761a0
	if (!ctx.cr6.lt) goto loc_822761A0;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r11,r11,-30000
	ctx.r11.s64 = ctx.r11.s64 + -30000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r29,r8,62604
	ctx.r29.u64 = ctx.r8.u64 | 62604;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f8,7600(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7600);
	ctx.f8.f64 = double(temp.f32);
	// addi r10,r10,-28872
	ctx.r10.s64 = ctx.r10.s64 + -28872;
	// lfs f9,-2040(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2040);
	ctx.f9.f64 = double(temp.f32);
	// addi r11,r11,-2040
	ctx.r11.s64 = ctx.r11.s64 + -2040;
	// lfs f11,8524(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8524);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
loc_822760CC:
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r28,1118
	ctx.r11.s64 = ctx.r28.s64 + 1118;
	// fmuls f0,f0,f8
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
	// mulli r11,r11,56
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(56));
	// stfsx f0,r11,r30
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r30.u32, temp.u32);
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x822760ec
	if (!ctx.cr6.gt) goto loc_822760EC;
	// stfsx f11,r11,r30
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r30.u32, temp.u32);
loc_822760EC:
	// lfsx f0,r11,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mulli r11,r28,56
	ctx.r11.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(56));
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// add r31,r11,r30
	ctx.r31.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r5,r1,152
	ctx.r5.s64 = ctx.r1.s64 + 152;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r4,r4,-2948
	ctx.r4.s64 = ctx.r4.s64 + -2948;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// bl 0x824d3cb8
	ctx.lr = 0x82276138;
	sub_824D3CB8(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// addi r11,r11,-2940
	ctx.r11.s64 = ctx.r11.s64 + -2940;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// bne cr6,0x82276178
	if (!ctx.cr6.eq) goto loc_82276178;
	// fmuls f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// stfsx f0,r30,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r29.u32, temp.u32);
	// add r11,r30,r29
	ctx.r11.u64 = ctx.r30.u64 + ctx.r29.u64;
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x82276190
	if (!ctx.cr6.lt) goto loc_82276190;
	// stfs f10,0(r11)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x82276190
	goto loc_82276190;
loc_82276178:
	// fmuls f0,f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// stfsx f0,r31,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// fcmpu cr6,f0,f9
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// ble cr6,0x82276190
	if (!ctx.cr6.gt) goto loc_82276190;
	// stfs f9,0(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_82276190:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplwi cr6,r28,2
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 2, ctx.xer);
	// blt cr6,0x822760cc
	if (ctx.cr6.lt) goto loc_822760CC;
	// b 0x82276538
	goto loc_82276538;
loc_822761A0:
	// lfs f13,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82276368
	if (!ctx.cr6.lt) goto loc_82276368;
	// addis r9,r30,1
	ctx.r9.s64 = ctx.r30.s64 + 65536;
	// addi r9,r9,-3086
	ctx.r9.s64 = ctx.r9.s64 + -3086;
	// lbz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82276214
	if (!ctx.cr0.eq) goto loc_82276214;
	// li r10,2
	ctx.r10.s64 = 2;
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r11,r11,-2852
	ctx.r11.s64 = ctx.r11.s64 + -2852;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_822761D4:
	// stbu r29,56(r11)
	ea = 56 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r29.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x822761d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822761D4;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stb r29,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r29.u8);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,-700(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -700);
	ctx.f0.f64 = double(temp.f32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stfs f0,0(r25)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r25.u32 + 0, temp.u32);
	// addi r9,r11,-2040
	ctx.r9.s64 = ctx.r11.s64 + -2040;
	// ori r10,r10,62716
	ctx.r10.u64 = ctx.r10.u64 | 62716;
	// ori r8,r8,62772
	ctx.r8.u64 = ctx.r8.u64 | 62772;
	// lfs f13,-2040(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2040);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r30,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, temp.u32);
	// stfsx f13,r30,r8
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + ctx.r8.u32, temp.u32);
	// b 0x82276538
	goto loc_82276538;
loc_82276214:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stb r31,144(r1)
	REX_STORE_U8(ctx.r1.u32 + 144, ctx.r31.u8);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stb r31,145(r1)
	REX_STORE_U8(ctx.r1.u32 + 145, ctx.r31.u8);
	// addi r11,r11,-30000
	ctx.r11.s64 = ctx.r11.s64 + -30000;
	// stb r31,146(r1)
	REX_STORE_U8(ctx.r1.u32 + 146, ctx.r31.u8);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// stb r31,148(r1)
	REX_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// addis r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 65536;
	// stb r31,149(r1)
	REX_STORE_U8(ctx.r1.u32 + 149, ctx.r31.u8);
	// li r29,2
	ctx.r29.s64 = 2;
	// stb r31,150(r1)
	REX_STORE_U8(ctx.r1.u32 + 150, ctx.r31.u8);
	// addi r30,r30,-2924
	ctx.r30.s64 = ctx.r30.s64 + -2924;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,-28872
	ctx.r11.s64 = ctx.r11.s64 + -28872;
	// lfs f11,-17652(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17652);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f31,f11
	ctx.f10.f64 = double(float(ctx.f31.f64 * ctx.f11.f64));
	// lfs f9,8524(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8524);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
loc_8227626C:
	// lbz r11,7(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 7);
	// lbz r10,3(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 3);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// std r10,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fsubs f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f10.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// fsubs f0,f13,f10
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// lhz r9,102(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lhz r10,110(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 110);
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// rlwinm r11,r11,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// rlwinm r11,r8,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// and r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r10,151(r1)
	REX_STORE_U8(ctx.r1.u32 + 151, ctx.r10.u8);
	// and r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ctx.r9.u64;
	// stb r11,147(r1)
	REX_STORE_U8(ctx.r1.u32 + 147, ctx.r11.u8);
	// lwz r10,144(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r11,148(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lfs f0,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f0,108(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 108, temp.u32);
	// fcmpu cr6,f0,f9
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// ble cr6,0x82276304
	if (!ctx.cr6.gt) goto loc_82276304;
	// stfs f9,108(r30)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r30.u32 + 108, temp.u32);
loc_82276304:
	// lfs f0,108(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r5,r1,152
	ctx.r5.s64 = ctx.r1.s64 + 152;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r4,r30,88
	ctx.r4.s64 = ctx.r30.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// bl 0x824d3cb8
	ctx.lr = 0x82276344;
	sub_824D3CB8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r30,96
	ctx.r11.s64 = ctx.r30.s64 + 96;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,56
	ctx.r30.s64 = ctx.r30.s64 + 56;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bne 0x8227626c
	if (!ctx.cr0.eq) goto loc_8227626C;
	// b 0x82276538
	goto loc_82276538;
loc_82276368:
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// li r10,2
	ctx.r10.s64 = 2;
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-2792
	ctx.r11.s64 = ctx.r11.s64 + -2792;
	// lfs f0,-28872(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28872);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f31,f0
	ctx.f13.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f0,-700(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -700);
	ctx.f0.f64 = double(temp.f32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82276388:
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x822763a0
	if (!ctx.cr6.lt) goto loc_822763A0;
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_822763A0:
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// bdnz 0x82276388
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82276388;
	// b 0x82276538
	goto loc_82276538;
loc_822763AC:
	// li r11,2
	ctx.r11.s64 = 2;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// li r31,255
	ctx.r31.s64 = 255;
	// stb r31,148(r1)
	REX_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// lfs f0,-17652(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -17652);
	ctx.f0.f64 = double(temp.f32);
	// stb r31,149(r1)
	REX_STORE_U8(ctx.r1.u32 + 149, ctx.r31.u8);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// stb r31,150(r1)
	REX_STORE_U8(ctx.r1.u32 + 150, ctx.r31.u8);
	// addi r11,r11,-2864
	ctx.r11.s64 = ctx.r11.s64 + -2864;
	// stb r31,144(r1)
	REX_STORE_U8(ctx.r1.u32 + 144, ctx.r31.u8);
	// stb r31,145(r1)
	REX_STORE_U8(ctx.r1.u32 + 145, ctx.r31.u8);
	// stb r31,146(r1)
	REX_STORE_U8(ctx.r1.u32 + 146, ctx.r31.u8);
loc_822763E4:
	// lbz r10,59(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 59);
	// lbz r9,55(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 55);
	// std r10,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r10.u64);
	// std r9,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r9.u64);
	// lfd f12,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lfd f13,152(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lhz r9,118(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 118);
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// fctiwz f13,f12
	ctx.f13.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f13.u64);
	// lhz r8,110(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 110);
	// rlwinm r10,r10,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r7,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// and r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 & ctx.r9.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stb r9,147(r1)
	REX_STORE_U8(ctx.r1.u32 + 147, ctx.r9.u8);
	// and r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
	// stb r10,151(r1)
	REX_STORE_U8(ctx.r1.u32 + 151, ctx.r10.u8);
	// lwz r10,148(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// stw r10,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r10.u32);
	// lwz r10,144(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// stwu r10,56(r11)
	ea = 56 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x822763e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822763E4;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62727
	ctx.r11.u64 = ctx.r11.u64 | 62727;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82276538
	if (!ctx.cr0.eq) goto loc_82276538;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62783
	ctx.r11.u64 = ctx.r11.u64 | 62783;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82276538
	if (!ctx.cr0.eq) goto loc_82276538;
	// li r11,9
	ctx.r11.s64 = 9;
	// b 0x82275a54
	goto loc_82275A54;
loc_82276498:
	// lbz r10,466(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 466);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r28,0
	ctx.r28.s64 = 0;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x822764bc
	if (ctx.cr0.eq) goto loc_822764BC;
	// lwzx r10,r30,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 7, ctx.xer);
	// beq cr6,0x822764c8
	if (ctx.cr6.eq) goto loc_822764C8;
loc_822764BC:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r28,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r28.u32);
	// stwx r10,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r10.u32);
loc_822764C8:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r27,r30,88
	ctx.r27.s64 = ctx.r30.s64 + 88;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lfs f1,1760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1760);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8224ecc8
	ctx.lr = 0x822764E0;
	sub_8224ECC8(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addis r26,r30,1
	ctx.r26.s64 = ctx.r30.s64 + 65536;
	// addi r29,r11,-2540
	ctx.r29.s64 = ctx.r11.s64 + -2540;
	// addi r26,r26,-3072
	ctx.r26.s64 = ctx.r26.s64 + -3072;
	// li r31,5
	ctx.r31.s64 = 5;
loc_822764F4:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// bl 0x824d3cb8
	ctx.lr = 0x82276504;
	sub_824D3CB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8224ade0
	ctx.lr = 0x82276510;
	sub_8224ADE0(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// bne 0x822764f4
	if (!ctx.cr0.eq) goto loc_822764F4;
	// li r10,2
	ctx.r10.s64 = 2;
	// addis r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 65536;
	// addi r11,r11,-2852
	ctx.r11.s64 = ctx.r11.s64 + -2852;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8227652C:
	// stb r28,-56(r11)
	REX_STORE_U8(ctx.r11.u32 + -56, ctx.r28.u8);
	// stbu r28,56(r11)
	ea = 56 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r28.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8227652c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8227652C;
loc_82276538:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822DA008) {
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
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3044
	ctx.r30.s64 = ctx.r30.s64 + -3044;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x822da0bc
	if (ctx.cr6.eq) goto loc_822DA0BC;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r11,r11,-3040
	ctx.r11.s64 = ctx.r11.s64 + -3040;
	// lfs f13,12252(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12252);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x822da0bc
	if (ctx.cr6.lt) goto loc_822DA0BC;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x822400e0
	ctx.lr = 0x822DA078;
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
	ctx.lr = 0x822DA094;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x822d8700
	ctx.lr = 0x822DA0BC;
	sub_822D8700(ctx, base);
loc_822DA0BC:
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

DEFINE_REX_FUNC(sub_822DD060) {
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
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-3064
	ctx.r11.s64 = ctx.r11.s64 + -3064;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x822dd188
	if (ctx.cr0.eq) goto loc_822DD188;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822400e0
	ctx.lr = 0x822DD0A8;
	sub_822400E0(ctx, base);
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
	ctx.lr = 0x822DD0C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x822dd0d4
	if (!ctx.cr0.eq) goto loc_822DD0D4;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f0,25264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25264);
	ctx.f0.f64 = double(temp.f32);
	// b 0x822dd0dc
	goto loc_822DD0DC;
loc_822DD0D4:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f0,-17776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17776);
	ctx.f0.f64 = double(temp.f32);
loc_822DD0DC:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822DD13C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lwz r31,4(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,412
	ctx.r4.s64 = 412;
	// rlwinm r30,r10,27,31,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x822DD160;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822dd188
	if (ctx.cr0.eq) goto loc_822DD188;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824c85c0
	ctx.lr = 0x822DD188;
	sub_824C85C0(ctx, base);
loc_822DD188:
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

DEFINE_REX_FUNC(sub_822E3E90) {
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
	ctx.lr = 0x822E3EA8;
	sub_82240CB0(ctx, base);
	// lbz r11,544(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 544);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822e3ed4
	if (ctx.cr0.eq) goto loc_822E3ED4;
	// addis r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 65536;
	// addi r31,r31,-3100
	ctx.r31.s64 = ctx.r31.s64 + -3100;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822e3ed4
	if (ctx.cr6.eq) goto loc_822E3ED4;
	// bl 0x82487e28
	ctx.lr = 0x822E3ECC;
	sub_82487E28(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_822E3ED4:
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

DEFINE_REX_FUNC(sub_822E6210) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x822E6218;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r9,264(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r10,r10,62388
	ctx.r10.u64 = ctx.r10.u64 | 62388;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r29,r11,12252
	ctx.r29.s64 = ctx.r11.s64 + 12252;
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwzx r11,r31,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// lfs f1,232(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8225cec0
	ctx.lr = 0x822E6254;
	sub_8225CEC0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r28,-32110
	ctx.r28.s64 = -2104360960;
	// addi r30,r11,-8400
	ctx.r30.s64 = ctx.r11.s64 + -8400;
	// lfs f13,468(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1236(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1236);
	ctx.f0.f64 = double(temp.f32);
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// fmadds f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822E629C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
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
	ctx.lr = 0x822E62B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f0,1236(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,468(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 468);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,26440(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26440);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmadds f0,f11,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f13.f64)));
	// fadds f1,f0,f12
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// bctrl
	ctx.lr = 0x822E6300;
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
	ctx.lr = 0x822E631C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822400e0
	ctx.lr = 0x822E6330;
	sub_822400E0(ctx, base);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r28,r28,-3144
	ctx.r28.s64 = ctx.r28.s64 + -3144;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// bl 0x822400e0
	ctx.lr = 0x822E6360;
	sub_822400E0(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r11,r11,-3136
	ctx.r11.s64 = ctx.r11.s64 + -3136;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822E6390;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x822e63a0
	if (!ctx.cr0.eq) goto loc_822E63A0;
	// lfs f13,236(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 236);
	ctx.f13.f64 = double(temp.f32);
	// b 0x822e63a4
	goto loc_822E63A4;
loc_822E63A0:
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
loc_822E63A4:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// ori r10,r10,62440
	ctx.r10.u64 = ctx.r10.u64 | 62440;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r9,r9,62452
	ctx.r9.u64 = ctx.r9.u64 | 62452;
	// lfs f0,880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 880);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lfsx f1,r31,r9
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82755380
	ctx.lr = 0x822E63D0;
	sub_82755380(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r10,r10,62444
	ctx.r10.u64 = ctx.r10.u64 | 62444;
	// ori r9,r9,62448
	ctx.r9.u64 = ctx.r9.u64 | 62448;
	// lfs f0,-29476(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29476);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lfsx f1,r31,r9
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82755380
	ctx.lr = 0x822E63FC;
	sub_82755380(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// ori r11,r11,62456
	ctx.r11.u64 = ctx.r11.u64 | 62456;
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f0,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.f0.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822E6434;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// lwz r30,4(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,420
	ctx.r4.s64 = 420;
	// rlwinm r29,r10,27,31,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x822E6458;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822e647c
	if (ctx.cr0.eq) goto loc_822E647C;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x824f4460
	ctx.lr = 0x822E6478;
	sub_824F4460(ctx, base);
	// b 0x822e6480
	goto loc_822E6480;
loc_822E647C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822E6480:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x822e6490
	if (ctx.cr6.eq) goto loc_822E6490;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
loc_822E6490:
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,62424
	ctx.r10.u64 = ctx.r10.u64 | 62424;
	// stwx r11,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822F9C18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756680
	ctx.lr = 0x822F9C20;
	__savegprlr_14(ctx, base);
	// stwu r1,-1120(r1)
	ea = -1120 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822fa1fc
	if (ctx.cr6.eq) goto loc_822FA1FC;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822F9C4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822fa1fc
	if (ctx.cr0.eq) goto loc_822FA1FC;
	// li r22,-1
	ctx.r22.s64 = -1;
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// stw r22,452(r30)
	REX_STORE_U32(ctx.r30.u32 + 452, ctx.r22.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x823d4098
	ctx.lr = 0x822F9C70;
	sub_823D4098(ctx, base);
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,232(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 232);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822F9C94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r21,r3,16
	ctx.r21.u64 = ctx.r3.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// beq 0x822fa1fc
	if (ctx.cr0.eq) goto loc_822FA1FC;
	// li r23,0
	ctx.r23.s64 = 0;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x822fa1fc
	if (ctx.cr6.eq) goto loc_822FA1FC;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lis r28,-32240
	ctx.r28.s64 = -2112880640;
	// lis r25,-32110
	ctx.r25.s64 = -2104360960;
	// addi r27,r11,-29856
	ctx.r27.s64 = ctx.r11.s64 + -29856;
	// addi r24,r10,4268
	ctx.r24.s64 = ctx.r10.s64 + 4268;
	// addi r26,r9,6472
	ctx.r26.s64 = ctx.r9.s64 + 6472;
	// addi r29,r8,6272
	ctx.r29.s64 = ctx.r8.s64 + 6272;
loc_822F9CD0:
	// lwz r11,264(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 264);
	// li r7,0
	ctx.r7.s64 = 0;
	// clrlwi r6,r23,16
	ctx.r6.u64 = ctx.r23.u32 & 0xFFFF;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x822F9CF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822fa1f0
	if (ctx.cr0.eq) goto loc_822FA1F0;
	// lwa r6,248(r1)
	ctx.r6.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 248));
	// addi r8,r1,272
	ctx.r8.s64 = ctx.r1.s64 + 272;
	// std r6,576(r1)
	REX_STORE_U64(ctx.r1.u32 + 576, ctx.r6.u64);
	// lfd f11,576(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 576);
	// lwa r9,240(r1)
	ctx.r9.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 240));
	// addi r10,r1,464
	ctx.r10.s64 = ctx.r1.s64 + 464;
	// lwa r7,252(r1)
	ctx.r7.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 252));
	// addi r4,r1,912
	ctx.r4.s64 = ctx.r1.s64 + 912;
	// std r9,600(r1)
	REX_STORE_U64(ctx.r1.u32 + 600, ctx.r9.u64);
	// addi r9,r1,400
	ctx.r9.s64 = ctx.r1.s64 + 400;
	// std r7,584(r1)
	REX_STORE_U64(ctx.r1.u32 + 584, ctx.r7.u64);
	// addi r18,r1,864
	ctx.r18.s64 = ctx.r1.s64 + 864;
	// lwa r11,244(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 244));
	// lis r5,0
	ctx.r5.s64 = 0;
	// std r11,592(r1)
	REX_STORE_U64(ctx.r1.u32 + 592, ctx.r11.u64);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// ld r7,88(r30)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r30.u32 + 88);
	// lfd f0,600(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 600);
	// addi r6,r1,432
	ctx.r6.s64 = ctx.r1.s64 + 432;
	// lfd f12,584(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 584);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// addi r11,r1,304
	ctx.r11.s64 = ctx.r1.s64 + 304;
	// addi r3,r1,944
	ctx.r3.s64 = ctx.r1.s64 + 944;
	// ori r5,r5,62424
	ctx.r5.u64 = ctx.r5.u64 | 62424;
	// std r7,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// addi r31,r1,736
	ctx.r31.s64 = ctx.r1.s64 + 736;
	// addi r19,r1,832
	ctx.r19.s64 = ctx.r1.s64 + 832;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// stfs f11,412(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// stfs f11,408(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// stfs f11,404(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stfs f0,280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,444(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 444, temp.u32);
	// stfs f12,440(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 440, temp.u32);
	// stfs f12,436(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 436, temp.u32);
	// stfs f11,400(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f13,592(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 592);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// stfs f12,432(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 432, temp.u32);
	// lfsx f10,r30,r5
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r5.u32);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,524(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 524, temp.u32);
	// fneg f10,f10
	ctx.f10.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// stfs f0,520(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 520, temp.u32);
	// stfs f0,516(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 516, temp.u32);
	// stfs f0,512(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 512, temp.u32);
	// stfs f11,348(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// stfs f11,344(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// stfs f11,340(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f11,336(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,476(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 476, temp.u32);
	// stfs f13,472(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 472, temp.u32);
	// stfs f13,468(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 468, temp.u32);
	// stfs f13,464(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,896
	ctx.r10.s64 = ctx.r1.s64 + 896;
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,316(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f13,312(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f13,308(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// stfs f13,304(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// stvx128 v61,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,336
	ctx.r11.s64 = ctx.r1.s64 + 336;
	// lfs f0,864(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 864);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,380(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// stfs f12,376(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// stfs f12,372(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// stfs f12,368(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// stvx128 v63,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,368
	ctx.r11.s64 = ctx.r1.s64 + 368;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,512
	ctx.r9.s64 = ctx.r1.s64 + 512;
	// lfs f0,912(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 912);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,704
	ctx.r8.s64 = ctx.r1.s64 + 704;
	// lfs f13,944(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 944);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// ld r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,928
	ctx.r10.s64 = ctx.r1.s64 + 928;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// stvx128 v62,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,832(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 832);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,896(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 896);
	ctx.f0.f64 = double(temp.f32);
	// std r11,544(r1)
	REX_STORE_U64(ctx.r1.u32 + 544, ctx.r11.u64);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// ld r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// stfs f10,220(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f10,216(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f10,212(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f10,208(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lvx128 v58,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,736(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 736);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,928(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 928);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f11,704(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 704);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,148(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// ld r10,144(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r10,568(r1)
	REX_STORE_U64(ctx.r1.u32 + 568, ctx.r10.u64);
	// lvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// vaddfp128 v1,v63,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v58.f32)));
	// std r11,560(r1)
	REX_STORE_U64(ctx.r1.u32 + 560, ctx.r11.u64);
	// std r10,552(r1)
	REX_STORE_U64(ctx.r1.u32 + 552, ctx.r10.u64);
	// bl 0x8222acc0
	ctx.lr = 0x822F9EF0;
	sub_8222ACC0(ctx, base);
	// addi r11,r1,768
	ctx.r11.s64 = ctx.r1.s64 + 768;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v1,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v58.u8));
	// bl 0x8222acc0
	ctx.lr = 0x822F9F00;
	sub_8222ACC0(ctx, base);
	// addi r8,r1,656
	ctx.r8.s64 = ctx.r1.s64 + 656;
	// stvx128 v1,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r9,r1,768
	ctx.r9.s64 = ctx.r1.s64 + 768;
	// lfs f12,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// li r10,4
	ctx.r10.s64 = 4;
	// lfs f11,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r1,536
	ctx.r11.s64 = ctx.r1.s64 + 536;
	// stfs f12,540(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// addi r7,r1,800
	ctx.r7.s64 = ctx.r1.s64 + 800;
	// stfs f12,536(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 536, temp.u32);
	// lfs f0,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,532(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// stfs f12,528(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stfs f11,204(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// vxor128 v63,v1,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stfs f11,200(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f11,196(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f11,192(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f0,332(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f0,328(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f0,324(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// stfs f0,300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f0,296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f0,292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// lfs f10,656(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 656);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f10,364(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// stfs f10,360(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,800(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 800);
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
	// stfs f10,356(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// stfs f10,352(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
loc_822F9FA4:
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// lfs f13,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,264(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// addi r10,r1,384
	ctx.r10.s64 = ctx.r1.s64 + 384;
	// stfs f13,260(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// addi r8,r1,672
	ctx.r8.s64 = ctx.r1.s64 + 672;
	// lfs f0,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,688
	ctx.r7.s64 = ctx.r1.s64 + 688;
	// stfs f0,388(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stfs f13,268(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// addi r6,r1,416
	ctx.r6.s64 = ctx.r1.s64 + 416;
	// stfs f13,256(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// stfs f0,396(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stfs f0,392(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// addi r31,r1,352
	ctx.r31.s64 = ctx.r1.s64 + 352;
	// stfs f0,384(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// addi r19,r1,752
	ctx.r19.s64 = ctx.r1.s64 + 752;
	// addi r18,r1,496
	ctx.r18.s64 = ctx.r1.s64 + 496;
	// std r30,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r30.u64);
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r17,r1,816
	ctx.r17.s64 = ctx.r1.s64 + 816;
	// addi r16,r1,176
	ctx.r16.s64 = ctx.r1.s64 + 176;
	// addi r15,r1,480
	ctx.r15.s64 = ctx.r1.s64 + 480;
	// addi r14,r1,880
	ctx.r14.s64 = ctx.r1.s64 + 880;
	// addi r30,r1,848
	ctx.r30.s64 = ctx.r1.s64 + 848;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,720
	ctx.r8.s64 = ctx.r1.s64 + 720;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,448
	ctx.r10.s64 = ctx.r1.s64 + 448;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,784
	ctx.r7.s64 = ctx.r1.s64 + 784;
	// lfs f0,672(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 672);
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
	// lfs f0,688(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 688);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,428(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 428, temp.u32);
	// stfs f0,424(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 424, temp.u32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v12,v62,v63
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,420(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 420, temp.u32);
	// stfs f0,416(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// lvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v13,v63,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lvx128 v62,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddcfp128 v0,v62,v0,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v13,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,720(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 720);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,452(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stvx128 v0,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,752(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 752);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,460(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 460, temp.u32);
	// stfs f0,456(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// stfs f0,448(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,508(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 508, temp.u32);
	// stfs f13,504(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// stfs f13,500(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// stfs f13,496(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 496, temp.u32);
	// lvx128 v63,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,816(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 816);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,784(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 784);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
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
	// lvx128 v63,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,12(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lfs f0,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,528
	ctx.r9.s64 = ctx.r1.s64 + 528;
	// stfs f0,488(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// stfs f0,492(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// stfs f0,484(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// stfs f0,480(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r30,96(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lvx128 v63,r0,r15
	ea = (ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,848(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 848);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,880(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 880);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x822f9fa4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822F9FA4;
	// ld r11,544(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 544);
	// li r10,3
	ctx.r10.s64 = 3;
	// ld r9,552(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 552);
	// li r5,0
	ctx.r5.s64 = 0;
	// ld r8,560(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 560);
	// ld r7,568(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 568);
	// lwz r31,-9960(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + -9960);
	// std r11,616(r1)
	REX_STORE_U64(ctx.r1.u32 + 616, ctx.r11.u64);
	// std r9,624(r1)
	REX_STORE_U64(ctx.r1.u32 + 624, ctx.r9.u64);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// std r8,632(r1)
	REX_STORE_U64(ctx.r1.u32 + 632, ctx.r8.u64);
	// stw r10,612(r1)
	REX_STORE_U32(ctx.r1.u32 + 612, ctx.r10.u32);
	// stw r26,608(r1)
	REX_STORE_U32(ctx.r1.u32 + 608, ctx.r26.u32);
	// std r7,640(r1)
	REX_STORE_U64(ctx.r1.u32 + 640, ctx.r7.u64);
	// beq cr6,0x822fa1a0
	if (ctx.cr6.eq) goto loc_822FA1A0;
	// fctiwz f0,f12
	ctx.f0.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// fctiwz f0,f11
	ctx.f0.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r5,108(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x823c3150
	ctx.lr = 0x822FA19C;
	sub_823C3150(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_822FA1A0:
	// lfs f0,168(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,4(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lwz r8,108(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// beq cr6,0x822fa1e8
	if (ctx.cr6.eq) goto loc_822FA1E8;
	// lis r4,16384
	ctx.r4.s64 = 1073741824;
	// lfs f1,12252(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 12252);
	ctx.f1.f64 = double(temp.f32);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// bl 0x823c4c40
	ctx.lr = 0x822FA1E4;
	sub_823C4C40(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_822FA1E8:
	// stw r11,452(r30)
	REX_STORE_U32(ctx.r30.u32 + 452, ctx.r11.u32);
	// stw r24,608(r1)
	REX_STORE_U32(ctx.r1.u32 + 608, ctx.r24.u32);
loc_822FA1F0:
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// cmplw cr6,r23,r21
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r21.u32, ctx.xer);
	// blt cr6,0x822f9cd0
	if (ctx.cr6.lt) goto loc_822F9CD0;
loc_822FA1FC:
	// addi r1,r1,1120
	ctx.r1.s64 = ctx.r1.s64 + 1120;
	// b 0x827566d0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82337A00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756690
	ctx.lr = 0x82337A08;
	__savegprlr_18(ctx, base);
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x827576c8
	ctx.lr = 0x82337A10;
	__savefpr_28(ctx, base);
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82240348
	ctx.lr = 0x82337A28;
	sub_82240348(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r20,r11,12288
	ctx.r20.s64 = ctx.r11.s64 + 12288;
	// beq 0x82337af0
	if (ctx.cr0.eq) goto loc_82337AF0;
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// lfs f0,5412(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5412);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stfs f12,204(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// stfs f12,200(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f12,196(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f12,192(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// ld r11,168(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 168);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_82337AF0:
	// addis r22,r31,1
	ctx.r22.s64 = ctx.r31.s64 + 65536;
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// addi r22,r22,-3120
	ctx.r22.s64 = ctx.r22.s64 + -3120;
	// lwz r9,264(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// stw r11,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// stw r10,4(r22)
	REX_STORE_U32(ctx.r22.u32 + 4, ctx.r10.u32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82337B20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addis r21,r31,1
	ctx.r21.s64 = ctx.r31.s64 + 65536;
	// addi r25,r11,15196
	ctx.r25.s64 = ctx.r11.s64 + 15196;
	// addi r21,r21,-3080
	ctx.r21.s64 = ctx.r21.s64 + -3080;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lfs f13,-2944(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2944);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r21)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r21.u32 + 0, temp.u32);
	// bne 0x82337b48
	if (!ctx.cr0.eq) goto loc_82337B48;
	// lfs f0,-2708(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2708);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r21)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r21.u32 + 0, temp.u32);
loc_82337B48:
	// addis r18,r31,1
	ctx.r18.s64 = ctx.r31.s64 + 65536;
	// addi r18,r18,-3164
	ctx.r18.s64 = ctx.r18.s64 + -3164;
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x82339714
	if (ctx.cr6.gt) goto loc_82339714;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// rlwinm r0,r11,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r12,r12,-3632
	ctx.r12.s64 = ctx.r12.s64 + -3632;
	// lhzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32205
	ctx.r12.s64 = -2110586880;
	// addi r12,r12,31620
	ctx.r12.s64 = ctx.r12.s64 + 31620;
	// nop
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82337B84;
	case 1:
		goto loc_82337C2C;
	case 2:
		goto loc_82337CA0;
	case 3:
		goto loc_82338390;
	case 4:
		goto loc_82338C88;
	case 5:
		goto loc_82339078;
	case 6:
		goto loc_823391E0;
	case 7:
		goto loc_82339288;
	case 8:
		goto loc_82339714;
	case 9:
		goto loc_82339388;
	case 10:
		goto loc_823395E8;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82337B84:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32113
	ctx.r10.s64 = -2104557568;
	// stw r11,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r10,22392
	ctx.r11.s64 = ctx.r10.s64 + 22392;
	// li r4,124
	ctx.r4.s64 = 124;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825fc4b0
	ctx.lr = 0x82337BA4;
	sub_825FC4B0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82337bdc
	if (ctx.cr0.eq) goto loc_82337BDC;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82337BC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lfs f1,-23384(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -23384);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82250a78
	ctx.lr = 0x82337BD4;
	sub_82250A78(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82337be0
	goto loc_82337BE0;
loc_82337BDC:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82337BE0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82339714
	if (ctx.cr6.eq) goto loc_82339714;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// bl 0x822328e8
	ctx.lr = 0x82337BF4;
	sub_822328E8(ctx, base);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r10,-3052
	ctx.r10.s64 = ctx.r10.s64 + -3052;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82339714
	if (!ctx.cr6.eq) goto loc_82339714;
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
	ctx.lr = 0x82337C28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82339714
	goto loc_82339714;
loc_82337C2C:
	// lfs f31,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f31.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f31,128(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// bl 0x822400e0
	ctx.lr = 0x82337C48;
	sub_822400E0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f2,-10604(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -10604);
	ctx.f2.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// addi r11,r11,-8400
	ctx.r11.s64 = ctx.r11.s64 + -8400;
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f4,-25740(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25740);
	ctx.f4.f64 = double(temp.f32);
	// fmr f3,f4
	ctx.f3.f64 = ctx.f4.f64;
	// bl 0x8224eeb8
	ctx.lr = 0x82337C6C;
	sub_8224EEB8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82339714
	if (ctx.cr0.eq) goto loc_82339714;
	// li r11,2
	ctx.r11.s64 = 2;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// stw r11,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x82337C9C;
	sub_8225CEC0(ctx, base);
	// b 0x82339714
	goto loc_82339714;
loc_82337CA0:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f0,-92(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -92);
	ctx.f0.f64 = double(temp.f32);
	// addis r19,r31,1
	ctx.r19.s64 = ctx.r31.s64 + 65536;
	// ori r11,r11,62469
	ctx.r11.u64 = ctx.r11.u64 | 62469;
	// addi r19,r19,-3092
	ctx.r19.s64 = ctx.r19.s64 + -3092;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stbx r28,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r28.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,0(r19)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r19.u32 + 0, temp.u32);
	// addi r3,r1,504
	ctx.r3.s64 = ctx.r1.s64 + 504;
	// bl 0x822400e0
	ctx.lr = 0x82337CD4;
	sub_822400E0(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
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
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r10,-28912
	ctx.r10.s64 = ctx.r10.s64 + -28912;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r30,r30,-3112
	ctx.r30.s64 = ctx.r30.s64 + -3112;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x82337d54
	if (ctx.cr0.eq) goto loc_82337D54;
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// b 0x82337d58
	goto loc_82337D58;
loc_82337D54:
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
loc_82337D58:
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,520
	ctx.r3.s64 = ctx.r1.s64 + 520;
	// bl 0x822400e0
	ctx.lr = 0x82337D78;
	sub_822400E0(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ori r9,r9,62428
	ctx.r9.u64 = ctx.r9.u64 | 62428;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,536
	ctx.r3.s64 = ctx.r1.s64 + 536;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// bl 0x822400e0
	ctx.lr = 0x82337DC0;
	sub_822400E0(ctx, base);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f12,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f28,-2712(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f28.f64 = double(temp.f32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vsubfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// stfs f28,132(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// bl 0x82240348
	ctx.lr = 0x82337E7C;
	sub_82240348(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ori r27,r10,62448
	ctx.r27.u64 = ctx.r10.u64 | 62448;
	// ori r29,r9,62432
	ctx.r29.u64 = ctx.r9.u64 | 62432;
	// bne 0x82338024
	if (!ctx.cr0.eq) goto loc_82338024;
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-92(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -92);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fsqrts f0,f0
	ctx.f0.f64 = double(float(sqrt(ctx.f0.f64)));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82337f74
	if (!ctx.cr6.gt) goto loc_82337F74;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfsx f12,r31,r29
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// lfsx f13,r31,r27
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
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
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// b 0x82338014
	goto loc_82338014;
loc_82337F74:
	// lfs f13,-2944(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2944);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82338020
	if (!ctx.cr6.gt) goto loc_82338020;
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// lfs f13,0(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r31,r27
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfsx f11,r31,r29
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	ctx.f11.f64 = double(temp.f32);
	// fadds f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f13,-900(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -900);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f10,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f10,92(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
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
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_82338014:
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// b 0x82338024
	goto loc_82338024;
loc_82338020:
	// stfs f28,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
loc_82338024:
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// ble cr6,0x82338044
	if (!ctx.cr6.gt) goto loc_82338044;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// ble cr6,0x82338054
	if (!ctx.cr6.gt) goto loc_82338054;
loc_82338044:
	// cmpwi cr6,r11,43
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 43, ctx.xer);
	// ble cr6,0x8233805c
	if (!ctx.cr6.gt) goto loc_8233805C;
	// cmpwi cr6,r11,60
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 60, ctx.xer);
	// bgt cr6,0x8233805c
	if (ctx.cr6.gt) goto loc_8233805C;
loc_82338054:
	// stfsx f28,r31,r27
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
	// b 0x8233806c
	goto loc_8233806C;
loc_8233805C:
	// lfsx f13,r31,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,272(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 272);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f29,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfsx f0,r31,r27
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
loc_8233806C:
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lis r9,0
	ctx.r9.s64 = 0;
	// add r23,r31,r27
	ctx.r23.u64 = ctx.r31.u64 + ctx.r27.u64;
	// ori r30,r9,62468
	ctx.r30.u64 = ctx.r9.u64 | 62468;
	// lbz r10,74(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 74);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8233808c
	if (!ctx.cr0.eq) goto loc_8233808C;
	// stbx r28,r31,r30
	REX_STORE_U8(ctx.r31.u32 + ctx.r30.u32, ctx.r28.u8);
loc_8233808C:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// ble cr6,0x82338368
	if (!ctx.cr6.gt) goto loc_82338368;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x82338368
	if (ctx.cr6.gt) goto loc_82338368;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82242a88
	ctx.lr = 0x823380A8;
	sub_82242A88(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82454930
	ctx.lr = 0x823380B4;
	sub_82454930(ctx, base);
	// lbzx r10,r31,r30
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r30.u32);
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// add r24,r31,r30
	ctx.r24.u64 = ctx.r31.u64 + ctx.r30.u64;
	// stwx r10,r31,r29
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, ctx.r10.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bne 0x82338368
	if (!ctx.cr0.eq) goto loc_82338368;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,552
	ctx.r3.s64 = ctx.r1.s64 + 552;
	// bl 0x822400e0
	ctx.lr = 0x823380EC;
	sub_822400E0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f2,-10604(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -10604);
	ctx.f2.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// addi r30,r11,-8400
	ctx.r30.s64 = ctx.r11.s64 + -8400;
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f4,-25740(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -25740);
	ctx.f4.f64 = double(temp.f32);
	// fmr f3,f4
	ctx.f3.f64 = ctx.f4.f64;
	// bl 0x8224eeb8
	ctx.lr = 0x82338110;
	sub_8224EEB8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82338368
	if (ctx.cr0.eq) goto loc_82338368;
	// lfs f0,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmr f30,f28
	ctx.f30.f64 = ctx.f28.f64;
	// lfs f13,-2944(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2944);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// ble cr6,0x82338130
	if (!ctx.cr6.gt) goto loc_82338130;
	// fmr f30,f13
	ctx.f30.f64 = ctx.f13.f64;
loc_82338130:
	// fmr f31,f28
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f28.f64;
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bge cr6,0x82338140
	if (!ctx.cr6.lt) goto loc_82338140;
	// fmr f31,f13
	ctx.f31.f64 = ctx.f13.f64;
loc_82338140:
	// li r4,10000
	ctx.r4.s64 = 10000;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825c08c8
	ctx.lr = 0x82338150;
	sub_825C08C8(ctx, base);
	// li r21,3
	ctx.r21.s64 = 3;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// divw r10,r3,r21
	ctx.r10.u64 = uint32_t((ctx.r21.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r21.s32 == -1)) ? ctx.r3.s32 / ctx.r21.s32 : 0);
	// li r4,10000
	ctx.r4.s64 = 10000;
	// mulli r10,r10,3
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(3));
	// li r3,0
	ctx.r3.s64 = 0;
	// subf r29,r10,r11
	ctx.r29.u64 = ctx.r11.u64 - ctx.r10.u64;
	// bl 0x825c08c8
	ctx.lr = 0x82338174;
	sub_825C08C8(ctx, base);
	// li r26,5
	ctx.r26.s64 = 5;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// divw r11,r3,r26
	ctx.r11.u64 = uint32_t((ctx.r26.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r26.s32 == -1)) ? ctx.r3.s32 / ctx.r26.s32 : 0);
	// mulli r11,r11,5
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(5));
	// subf r27,r11,r3
	ctx.r27.u64 = ctx.r3.u64 - ctx.r11.u64;
	// bne cr6,0x823381e8
	if (!ctx.cr6.eq) goto loc_823381E8;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne cr6,0x823381e8
	if (!ctx.cr6.eq) goto loc_823381E8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x822400e0
	ctx.lr = 0x823381A8;
	sub_822400E0(ctx, base);
	// lfs f0,-22448(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -22448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,5220(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5220);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,5188(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5188);
	ctx.f2.f64 = double(temp.f32);
	// lfs f4,5412(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5412);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fmuls f3,f30,f13
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// bl 0x8224eeb8
	ctx.lr = 0x823381CC;
	sub_8224EEB8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823381e8
	if (ctx.cr0.eq) goto loc_823381E8;
	// li r9,4
	ctx.r9.s64 = 4;
loc_823381D8:
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r9,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r9.u32);
	// stb r8,0(r24)
	REX_STORE_U8(ctx.r24.u32 + 0, ctx.r8.u8);
	// b 0x8233834c
	goto loc_8233834C;
loc_823381E8:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82240348
	ctx.lr = 0x823381F8;
	sub_82240348(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82338368
	if (!ctx.cr6.eq) goto loc_82338368;
	// bne 0x82338254
	if (!ctx.cr0.eq) goto loc_82338254;
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// bne cr6,0x82338254
	if (!ctx.cr6.eq) goto loc_82338254;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// bl 0x822400e0
	ctx.lr = 0x82338224;
	sub_822400E0(ctx, base);
	// lfs f4,5220(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5220);
	ctx.f4.f64 = double(temp.f32);
	// lfs f0,-22448(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -22448);
	ctx.f0.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,-10604(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -10604);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f3,f30,f4
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f4.f64));
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// bl 0x8224eeb8
	ctx.lr = 0x82338244;
	sub_8224EEB8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82338368
	if (ctx.cr0.eq) goto loc_82338368;
	// stw r26,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r26.u32);
	// b 0x82338344
	goto loc_82338344;
loc_82338254:
	// cmpwi cr6,r27,2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 2, ctx.xer);
	// bne cr6,0x823382a4
	if (!ctx.cr6.eq) goto loc_823382A4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x822400e0
	ctx.lr = 0x82338270;
	sub_822400E0(ctx, base);
	// lfs f0,24640(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 24640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24596(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 24596);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,-22448(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -22448);
	ctx.f2.f64 = double(temp.f32);
	// lfs f4,5220(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5220);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fmuls f3,f30,f13
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// bl 0x8224eeb8
	ctx.lr = 0x82338294;
	sub_8224EEB8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82338368
	if (ctx.cr0.eq) goto loc_82338368;
	// li r9,6
	ctx.r9.s64 = 6;
	// b 0x823381d8
	goto loc_823381D8;
loc_823382A4:
	// cmpwi cr6,r27,3
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 3, ctx.xer);
	// bne cr6,0x823382f8
	if (!ctx.cr6.eq) goto loc_823382F8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x822400e0
	ctx.lr = 0x823382C0;
	sub_822400E0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f13,5392(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5392);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,-22448(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -22448);
	ctx.f2.f64 = double(temp.f32);
	// lfs f4,5220(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5220);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f30,f13
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// lfs f0,11152(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11152);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// bl 0x8224eeb8
	ctx.lr = 0x823382E8;
	sub_8224EEB8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82338368
	if (ctx.cr0.eq) goto loc_82338368;
	// li r9,7
	ctx.r9.s64 = 7;
	// b 0x823381d8
	goto loc_823381D8;
loc_823382F8:
	// cmpwi cr6,r27,4
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4, ctx.xer);
	// bne cr6,0x82338368
	if (!ctx.cr6.eq) goto loc_82338368;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x822400e0
	ctx.lr = 0x82338314;
	sub_822400E0(ctx, base);
	// lfs f0,24568(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 24568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-13360(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -13360);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,-22448(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -22448);
	ctx.f2.f64 = double(temp.f32);
	// lfs f4,5220(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5220);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fmuls f3,f30,f13
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// bl 0x8224eeb8
	ctx.lr = 0x82338338;
	sub_8224EEB8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82338368
	if (ctx.cr0.eq) goto loc_82338368;
	// stw r21,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r21.u32);
loc_82338344:
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,0(r24)
	REX_STORE_U8(ctx.r24.u32 + 0, ctx.r9.u8);
loc_8233834C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// stfs f28,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r23.u32 + 0, temp.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62440
	ctx.r11.u64 = ctx.r11.u64 | 62440;
	// ori r10,r10,62452
	ctx.r10.u64 = ctx.r10.u64 | 62452;
	// stwx r28,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r28.u32);
	// stfsx f28,r31,r10
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
loc_82338368:
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8233af50
	ctx.lr = 0x8233837C;
	sub_8233AF50(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82339714
	if (!ctx.cr0.eq) goto loc_82339714;
	// stfs f28,0(r19)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r19.u32 + 0, temp.u32);
	// stfs f28,0(r23)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r23.u32 + 0, temp.u32);
	// b 0x82339714
	goto loc_82339714;
loc_82338390:
	// addis r23,r31,1
	ctx.r23.s64 = ctx.r31.s64 + 65536;
	// addi r23,r23,-3096
	ctx.r23.s64 = ctx.r23.s64 + -3096;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82338c48
	if (ctx.cr6.lt) goto loc_82338C48;
	// beq cr6,0x82338a54
	if (ctx.cr6.eq) goto loc_82338A54;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x823388c4
	if (ctx.cr6.lt) goto loc_823388C4;
	// bne cr6,0x82339714
	if (!ctx.cr6.eq) goto loc_82339714;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,544
	ctx.r3.s64 = ctx.r1.s64 + 544;
	// bl 0x822400e0
	ctx.lr = 0x823383C8;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x823383E4;
	sub_822400E0(ctx, base);
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r27,r27,-3052
	ctx.r27.s64 = ctx.r27.s64 + -3052;
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f31,220(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8233842c
	if (ctx.cr6.eq) goto loc_8233842C;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82232ba0
	ctx.lr = 0x82338410;
	sub_82232BA0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8233842c
	if (ctx.cr0.eq) goto loc_8233842C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,216
	ctx.r4.s64 = ctx.r1.s64 + 216;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8233842C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8233842C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82240348
	ctx.lr = 0x8233843C;
	sub_82240348(ctx, base);
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lfs f28,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f28.f64 = double(temp.f32);
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r28,0
	ctx.r28.s64 = 0;
	// li r24,1
	ctx.r24.s64 = 1;
	// ori r26,r9,62472
	ctx.r26.u64 = ctx.r9.u64 | 62472;
	// addi r29,r11,6272
	ctx.r29.s64 = ctx.r11.s64 + 6272;
	// bne 0x82338500
	if (!ctx.cr0.eq) goto loc_82338500;
	// lbzx r11,r31,r26
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r26.u32);
	// add r30,r31,r26
	ctx.r30.u64 = ctx.r31.u64 + ctx.r26.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823384cc
	if (!ctx.cr0.eq) goto loc_823384CC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x822400e0
	ctx.lr = 0x82338484;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x823384A0;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// li r3,118
	ctx.r3.s64 = 118;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82250ad8
	ctx.lr = 0x823384C8;
	sub_82250AD8(ctx, base);
	// stb r24,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r24.u8);
loc_823384CC:
	// ld r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// stfs f28,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// std r10,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r10.u64);
	// beq cr6,0x82338500
	if (ctx.cr6.eq) goto loc_82338500;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82232ba0
	ctx.lr = 0x823384F0;
	sub_82232BA0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82338500
	if (ctx.cr0.eq) goto loc_82338500;
	// stb r28,84(r3)
	REX_STORE_U8(ctx.r3.u32 + 84, ctx.r28.u8);
	// stb r28,85(r3)
	REX_STORE_U8(ctx.r3.u32 + 85, ctx.r28.u8);
loc_82338500:
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bgt cr6,0x82338514
	if (ctx.cr6.gt) goto loc_82338514;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x8233851c
	goto loc_8233851C;
loc_82338514:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822403e0
	ctx.lr = 0x8233851C;
	sub_822403E0(ctx, base);
loc_8233851C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8233857c
	if (ctx.cr0.eq) goto loc_8233857C;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r8,r8,-30000
	ctx.r8.s64 = ctx.r8.s64 + -30000;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_8233857C:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82338618
	if (ctx.cr0.eq) goto loc_82338618;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// bne 0x8233861c
	if (!ctx.cr0.eq) goto loc_8233861C;
loc_82338618:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8233861C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ori r29,r10,62460
	ctx.r29.u64 = ctx.r10.u64 | 62460;
	// beq 0x82338844
	if (ctx.cr0.eq) goto loc_82338844;
	// lwzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// add r30,r31,r29
	ctx.r30.u64 = ctx.r31.u64 + ctx.r29.u64;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bge cr6,0x82338844
	if (!ctx.cr6.lt) goto loc_82338844;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r11,-8400
	ctx.r11.s64 = ctx.r11.s64 + -8400;
	// lfs f31,-22576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22576);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,-20444(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20444);
	ctx.f30.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x825c0958
	ctx.lr = 0x8233865C;
	sub_825C0958(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,496
	ctx.r3.s64 = ctx.r1.s64 + 496;
	// bl 0x822400e0
	ctx.lr = 0x82338674;
	sub_822400E0(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
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
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r25,r10,-26448
	ctx.r25.s64 = ctx.r10.s64 + -26448;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822400e0
	ctx.lr = 0x823386BC;
	sub_822400E0(ctx, base);
	// lfs f12,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,-3936(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -3936);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f13,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r4,r1,232
	ctx.r4.s64 = ctx.r1.s64 + 232;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f29,80(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f29,88(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f29,92(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f29,84(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,236(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// lfs f29,-7616(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -7616);
	ctx.f29.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// bl 0x823397e8
	ctx.lr = 0x82338748;
	sub_823397E8(ctx, base);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x825c0958
	ctx.lr = 0x82338758;
	sub_825C0958(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x822400e0
	ctx.lr = 0x82338770;
	sub_822400E0(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822400e0
	ctx.lr = 0x823387B0;
	sub_822400E0(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f13,0(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,184
	ctx.r4.s64 = ctx.r1.s64 + 184;
	// lfs f0,-21192(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -21192);
	ctx.f0.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// lfs f12,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vaddfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// bl 0x823397e8
	ctx.lr = 0x82338838;
	sub_823397E8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_82338844:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r10,74(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 74);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82339714
	if (!ctx.cr0.eq) goto loc_82339714;
	// stb r24,285(r31)
	REX_STORE_U8(ctx.r31.u32 + 285, ctx.r24.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stbx r28,r31,r26
	REX_STORE_U8(ctx.r31.u32 + ctx.r26.u32, ctx.r28.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f28.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x8233887C;
	sub_8225CEC0(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,62452
	ctx.r10.u64 = ctx.r10.u64 | 62452;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r28,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r28.u32);
	// stwx r28,r31,r29
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, ctx.r28.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// stw r9,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r9.u32);
	// stfsx f28,r31,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// beq cr6,0x82339714
	if (ctx.cr6.eq) goto loc_82339714;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82232ba0
	ctx.lr = 0x823388B0;
	sub_82232BA0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82339714
	if (ctx.cr0.eq) goto loc_82339714;
	// stb r28,84(r3)
	REX_STORE_U8(ctx.r3.u32 + 84, ctx.r28.u8);
	// stb r28,85(r3)
	REX_STORE_U8(ctx.r3.u32 + 85, ctx.r28.u8);
	// b 0x82339714
	goto loc_82339714;
loc_823388C4:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82240348
	ctx.lr = 0x823388D4;
	sub_82240348(ctx, base);
	// lfs f31,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f31.f64 = double(temp.f32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r21,3
	ctx.r21.s64 = 3;
	// bne 0x82338940
	if (!ctx.cr0.eq) goto loc_82338940;
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82338924
	if (!ctx.cr6.lt) goto loc_82338924;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82338924:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82338940
	if (ctx.cr0.eq) goto loc_82338940;
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// ld r11,6272(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 6272);
	// stfs f31,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// stw r21,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r21.u32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_82338940:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x822400e0
	ctx.lr = 0x82338954;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// lfs f30,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x82338970;
	sub_822400E0(ctx, base);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r30,-3052
	ctx.r30.s64 = ctx.r30.s64 + -3052;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f30,180(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x823389b0
	if (ctx.cr6.eq) goto loc_823389B0;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82232ba0
	ctx.lr = 0x8233899C;
	sub_82232BA0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x823389B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823389B0:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,74(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82339714
	if (!ctx.cr0.eq) goto loc_82339714;
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x8225cec0
	ctx.lr = 0x823389DC;
	sub_8225CEC0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// bl 0x822400e0
	ctx.lr = 0x823389EC;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x82338A08;
	sub_822400E0(ctx, base);
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,121
	ctx.r3.s64 = 121;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82250ad8
	ctx.lr = 0x82338A30;
	sub_82250AD8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82338a4c
	if (ctx.cr6.eq) goto loc_82338A4C;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82232ba0
	ctx.lr = 0x82338A48;
	sub_82232BA0(ctx, base);
	// stw r21,112(r3)
	REX_STORE_U32(ctx.r3.u32 + 112, ctx.r21.u32);
loc_82338A4C:
	// stw r21,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r21.u32);
	// b 0x82339714
	goto loc_82339714;
loc_82338A54:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// bl 0x822400e0
	ctx.lr = 0x82338A68;
	sub_822400E0(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x822400e0
	ctx.lr = 0x82338A7C;
	sub_822400E0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r11,72
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 72, ctx.xer);
	// ble cr6,0x82339714
	if (!ctx.cr6.gt) goto loc_82339714;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62469
	ctx.r11.u64 = ctx.r11.u64 | 62469;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,248
	ctx.r3.s64 = ctx.r1.s64 + 248;
	// stbx r10,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u8);
	// bl 0x822400e0
	ctx.lr = 0x82338AB8;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,264
	ctx.r3.s64 = ctx.r1.s64 + 264;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x82338AD4;
	sub_822400E0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r29,2
	ctx.r29.s64 = 2;
	// ori r11,r11,62484
	ctx.r11.u64 = ctx.r11.u64 | 62484;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f31,164(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82338b90
	if (ctx.cr6.eq) goto loc_82338B90;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82232ba0
	ctx.lr = 0x82338B04;
	sub_82232BA0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82338b90
	if (ctx.cr0.eq) goto loc_82338B90;
	// stw r29,112(r30)
	REX_STORE_U32(ctx.r30.u32 + 112, ctx.r29.u32);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lis r9,-32113
	ctx.r9.s64 = -2104557568;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,3484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3484);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f13,28120(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28120);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82338B38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// ori r11,r11,65408
	ctx.r11.u64 = ctx.r11.u64 | 65408;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,104(r30)
	REX_STORE_U32(ctx.r30.u32 + 104, ctx.r11.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82338B5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r30,60
	ctx.r3.s64 = ctx.r30.s64 + 60;
	// lfs f3,-900(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -900);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-2944(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2944);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-10556(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -10556);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82233d28
	ctx.lr = 0x82338B70;
	sub_82233D28(ctx, base);
	// lfs f0,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82338b88
	if (!ctx.cr6.gt) goto loc_82338B88;
	// stb r29,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r29.u8);
	// b 0x82338b90
	goto loc_82338B90;
loc_82338B88:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r11.u8);
loc_82338B90:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,280
	ctx.r3.s64 = ctx.r1.s64 + 280;
	// bl 0x822400e0
	ctx.lr = 0x82338BA4;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,296
	ctx.r3.s64 = ctx.r1.s64 + 296;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x82338BC0;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// li r3,120
	ctx.r3.s64 = 120;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82250ad8
	ctx.lr = 0x82338BE8;
	sub_82250AD8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,0(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f12,0(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,-26416
	ctx.r11.s64 = ctx.r11.s64 + -26416;
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r29,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r29.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
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
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// ld r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// b 0x82339714
	goto loc_82339714;
loc_82338C48:
	// lfs f1,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f1.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stfs f1,128(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x82338C6C;
	sub_8225CEC0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62460
	ctx.r11.u64 = ctx.r11.u64 | 62460;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r9.u32);
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// b 0x82339714
	goto loc_82339714;
loc_82338C88:
	// addis r23,r31,1
	ctx.r23.s64 = ctx.r31.s64 + 65536;
	// addi r23,r23,-3096
	ctx.r23.s64 = ctx.r23.s64 + -3096;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8233902c
	if (ctx.cr6.lt) goto loc_8233902C;
	// bne cr6,0x82339714
	if (!ctx.cr6.eq) goto loc_82339714;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lfs f0,5220(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5220);
	ctx.f0.f64 = double(temp.f32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lfs f30,-2712(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f30.f64 = double(temp.f32);
	// ori r27,r10,62448
	ctx.r27.u64 = ctx.r10.u64 | 62448;
	// ori r26,r9,62472
	ctx.r26.u64 = ctx.r9.u64 | 62472;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// ori r29,r8,62460
	ctx.r29.u64 = ctx.r8.u64 | 62460;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwa r11,20(r11)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r11.u32 + 20));
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82338fc4
	if (!ctx.cr6.gt) goto loc_82338FC4;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lbzx r10,r31,r26
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r26.u32);
	// li r24,1
	ctx.r24.s64 = 1;
	// ori r11,r11,62469
	ctx.r11.u64 = ctx.r11.u64 | 62469;
	// add r30,r31,r26
	ctx.r30.u64 = ctx.r31.u64 + ctx.r26.u64;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stbx r24,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r24.u8);
	// bne 0x82338d64
	if (!ctx.cr0.eq) goto loc_82338D64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,312
	ctx.r3.s64 = ctx.r1.s64 + 312;
	// bl 0x822400e0
	ctx.lr = 0x82338D1C;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,328
	ctx.r3.s64 = ctx.r1.s64 + 328;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x82338D38;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// li r3,122
	ctx.r3.s64 = 122;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82250ad8
	ctx.lr = 0x82338D60;
	sub_82250AD8(ctx, base);
	// stb r24,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r24.u8);
loc_82338D64:
	// lfsx f13,r31,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	ctx.f13.f64 = double(temp.f32);
	// add r30,r31,r27
	ctx.r30.u64 = ctx.r31.u64 + ctx.r27.u64;
	// lfs f0,272(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 272);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f29,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, ctx.f13.f64)));
	// lfs f31,0(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// stfsx f0,r31,r27
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x82338d8c
	if (!ctx.cr6.gt) goto loc_82338D8C;
	// stfs f31,0(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// b 0x82338f44
	goto loc_82338F44;
loc_82338D8C:
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x825c08c8
	ctx.lr = 0x82338D9C;
	sub_825C08C8(ctx, base);
	// lwzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// li r10,6
	ctx.r10.s64 = 6;
	// divw r10,r11,r10
	ctx.r10.u64 = uint32_t((ctx.r10.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r11.s32 / ctx.r10.s32 : 0);
	// mulli r10,r10,6
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(6));
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmpw cr6,r11,r3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r3.s32, ctx.xer);
	// bne cr6,0x82338f44
	if (!ctx.cr6.eq) goto loc_82338F44;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,344
	ctx.r3.s64 = ctx.r1.s64 + 344;
	// bl 0x822400e0
	ctx.lr = 0x82338DCC;
	sub_822400E0(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
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
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r28,r10,-26448
	ctx.r28.s64 = ctx.r10.s64 + -26448;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,360
	ctx.r3.s64 = ctx.r1.s64 + 360;
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822400e0
	ctx.lr = 0x82338E14;
	sub_822400E0(ctx, base);
	// lfs f13,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,-3936(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -3936);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f12,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// bl 0x823397e8
	ctx.lr = 0x82338E80;
	sub_823397E8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,376
	ctx.r3.s64 = ctx.r1.s64 + 376;
	// bl 0x822400e0
	ctx.lr = 0x82338E94;
	sub_822400E0(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,392
	ctx.r3.s64 = ctx.r1.s64 + 392;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822400e0
	ctx.lr = 0x82338ED4;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lfs f13,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-21192(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -21192);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
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
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// bl 0x823397e8
	ctx.lr = 0x82338F44;
	sub_823397E8(ctx, base);
loc_82338F44:
	// ld r10,128(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// lfs f13,0(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r11,r31,r29
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, ctx.r11.u32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
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
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
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
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_82338FC4:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r30,r10,62452
	ctx.r30.u64 = ctx.r10.u64 | 62452;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r10,74(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 74);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8233901c
	if (!ctx.cr0.eq) goto loc_8233901C;
	// li r28,0
	ctx.r28.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// li r7,1
	ctx.r7.s64 = 1;
	// stbx r28,r31,r26
	REX_STORE_U8(ctx.r31.u32 + ctx.r26.u32, ctx.r28.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x82339004;
	sub_8225CEC0(ctx, base);
	// stfsx f30,r31,r27
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
	// stw r28,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r28.u32);
	// stfsx f30,r31,r30
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, temp.u32);
loc_82339010:
	// li r11,2
	ctx.r11.s64 = 2;
	// stwx r28,r31,r29
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, ctx.r28.u32);
	// stw r11,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r11.u32);
loc_8233901C:
	// lfsx f0,r31,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// stfsx f0,r31,r30
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, temp.u32);
	// b 0x82339714
	goto loc_82339714;
loc_8233902C:
	// lfs f1,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f1.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stfs f1,128(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x82339050;
	sub_8225CEC0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62448
	ctx.r11.u64 = ctx.r11.u64 | 62448;
	// ori r10,r10,62460
	ctx.r10.u64 = ctx.r10.u64 | 62460;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// stfsx f1,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stw r8,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r8.u32);
	// stwx r9,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// b 0x82339714
	goto loc_82339714;
loc_82339078:
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// addi r27,r27,-3096
	ctx.r27.s64 = ctx.r27.s64 + -3096;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x823391a0
	if (ctx.cr6.lt) goto loc_823391A0;
	// bne cr6,0x82339714
	if (!ctx.cr6.eq) goto loc_82339714;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lfs f0,5220(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5220);
	ctx.f0.f64 = double(temp.f32);
	// ori r26,r10,62472
	ctx.r26.u64 = ctx.r10.u64 | 62472;
	// ori r29,r9,62460
	ctx.r29.u64 = ctx.r9.u64 | 62460;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwa r11,20(r11)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r11.u32 + 20));
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82339154
	if (!ctx.cr6.gt) goto loc_82339154;
	// lwzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bge cr6,0x82339154
	if (!ctx.cr6.lt) goto loc_82339154;
	// lbzx r11,r31,r26
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r26.u32);
	// li r24,1
	ctx.r24.s64 = 1;
	// add r30,r31,r26
	ctx.r30.u64 = ctx.r31.u64 + ctx.r26.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82339148
	if (!ctx.cr0.eq) goto loc_82339148;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,408
	ctx.r3.s64 = ctx.r1.s64 + 408;
	// bl 0x822400e0
	ctx.lr = 0x82339100;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,424
	ctx.r3.s64 = ctx.r1.s64 + 424;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x8233911C;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// li r3,119
	ctx.r3.s64 = 119;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82250ad8
	ctx.lr = 0x82339144;
	sub_82250AD8(ctx, base);
	// stb r24,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r24.u8);
loc_82339148:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62473
	ctx.r11.u64 = ctx.r11.u64 | 62473;
	// stbx r24,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r24.u8);
loc_82339154:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r30,r10,62452
	ctx.r30.u64 = ctx.r10.u64 | 62452;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r10,74(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 74);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8233901c
	if (!ctx.cr0.eq) goto loc_8233901C;
	// li r28,0
	ctx.r28.s64 = 0;
	// lfs f1,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f1.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stbx r28,r31,r26
	REX_STORE_U8(ctx.r31.u32 + ctx.r26.u32, ctx.r28.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x82339194;
	sub_8225CEC0(ctx, base);
	// stfsx f1,r31,r30
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, temp.u32);
	// stw r28,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r28.u32);
	// b 0x82339010
	goto loc_82339010;
loc_823391A0:
	// lfs f1,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f1.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stfs f1,128(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x823391C4;
	sub_8225CEC0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62460
	ctx.r11.u64 = ctx.r11.u64 | 62460;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
	// b 0x82339714
	goto loc_82339714;
loc_823391E0:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3096
	ctx.r30.s64 = ctx.r30.s64 + -3096;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8233924c
	if (ctx.cr6.eq) goto loc_8233924C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82339714
	if (!ctx.cr6.eq) goto loc_82339714;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lfs f0,0(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-3084
	ctx.r11.s64 = ctx.r11.s64 + -3084;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f29,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,20(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// cmplwi cr6,r10,120
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 120, ctx.xer);
	// bge cr6,0x82339238
	if (!ctx.cr6.lt) goto loc_82339238;
	// lfs f13,272(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82339714
	if (ctx.cr6.lt) goto loc_82339714;
loc_82339238:
	// li r10,3
	ctx.r10.s64 = 3;
	// lfs f0,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82339714
	goto loc_82339714;
loc_8233924C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f1,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,128(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// ori r11,r11,62452
	ctx.r11.u64 = ctx.r11.u64 | 62452;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// stfsx f1,r31,r11
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x8233927C;
	sub_8225CEC0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x82339714
	goto loc_82339714;
loc_82339288:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r29,r29,-3096
	ctx.r29.s64 = ctx.r29.s64 + -3096;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82339358
	if (ctx.cr6.lt) goto loc_82339358;
	// bne cr6,0x82339714
	if (!ctx.cr6.eq) goto loc_82339714;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f0,-92(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -92);
	ctx.f0.f64 = double(temp.f32);
	// li r24,1
	ctx.r24.s64 = 1;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,20(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x823392e4
	if (!ctx.cr6.gt) goto loc_823392E4;
	// stb r24,545(r31)
	REX_STORE_U8(ctx.r31.u32 + 545, ctx.r24.u8);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r28,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r28.u32);
loc_823392E4:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-8400
	ctx.r11.s64 = ctx.r11.s64 + -8400;
	// addi r30,r30,-3084
	ctx.r30.s64 = ctx.r30.s64 + -3084;
	// lfs f0,-20472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82339314
	if (!ctx.cr6.gt) goto loc_82339314;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r24,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r24.u32);
	// stb r28,545(r31)
	REX_STORE_U8(ctx.r31.u32 + 545, ctx.r28.u8);
loc_82339314:
	// cmpwi cr6,r10,34
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 34, ctx.xer);
	// blt cr6,0x8233934c
	if (ctx.cr6.lt) goto loc_8233934C;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f1.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x8233933C;
	sub_8225CEC0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// stw r28,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// stw r11,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r11.u32);
loc_8233934C:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// b 0x82339710
	goto loc_82339710;
loc_82339358:
	// lfs f1,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f1.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stfs f1,128(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x8233937C;
	sub_8225CEC0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x82339714
	goto loc_82339714;
loc_82339388:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3096
	ctx.r30.s64 = ctx.r30.s64 + -3096;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82339500
	if (ctx.cr6.lt) goto loc_82339500;
	// bne cr6,0x82339714
	if (!ctx.cr6.eq) goto loc_82339714;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8233b450
	ctx.lr = 0x823393A8;
	sub_8233B450(ctx, base);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3084
	ctx.r30.s64 = ctx.r30.s64 + -3084;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// srawi r10,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 3;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// subf. r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8233942c
	if (!ctx.cr0.eq) goto loc_8233942C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,440
	ctx.r3.s64 = ctx.r1.s64 + 440;
	// bl 0x822400e0
	ctx.lr = 0x823393E8;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,456
	ctx.r3.s64 = ctx.r1.s64 + 456;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x82339404;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// li r3,171
	ctx.r3.s64 = 171;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82250ad8
	ctx.lr = 0x8233942C;
	sub_82250AD8(ctx, base);
loc_8233942C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82240348
	ctx.lr = 0x8233943C;
	sub_82240348(ctx, base);
	// lfs f31,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f31.f64 = double(temp.f32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r28,0
	ctx.r28.s64 = 0;
	// bne 0x82339498
	if (!ctx.cr0.eq) goto loc_82339498;
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8233948c
	if (!ctx.cr6.lt) goto loc_8233948C;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8233948C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82339498
	if (ctx.cr0.eq) goto loc_82339498;
	// stfs f31,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
loc_82339498:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x823394B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f0,0(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f29,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,20(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmplwi cr6,r10,125
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 125, ctx.xer);
	// bge cr6,0x823394ec
	if (!ctx.cr6.lt) goto loc_823394EC;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r10,r10,-2512
	ctx.r10.s64 = ctx.r10.s64 + -2512;
	// lfs f13,2800(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2800);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82339714
	if (ctx.cr6.lt) goto loc_82339714;
loc_823394EC:
	// li r10,10
	ctx.r10.s64 = 10;
	// stw r28,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r28.u32);
	// stfs f31,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// stw r10,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r10.u32);
	// b 0x82339714
	goto loc_82339714;
loc_82339500:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,472
	ctx.r3.s64 = ctx.r1.s64 + 472;
	// bl 0x822400e0
	ctx.lr = 0x82339514;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,488
	ctx.r3.s64 = ctx.r1.s64 + 488;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x82339530;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// li r3,116
	ctx.r3.s64 = 116;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82250ad8
	ctx.lr = 0x82339558;
	sub_82250AD8(ctx, base);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lfs f1,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f1.f64 = double(temp.f32);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r29,-3076
	ctx.r29.s64 = ctx.r29.s64 + -3076;
	// stb r28,545(r31)
	REX_STORE_U8(ctx.r31.u32 + 545, ctx.r28.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,18
	ctx.r4.s64 = 18;
	// stw r28,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// stfs f1,128(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8225cec0
	ctx.lr = 0x82339590;
	sub_8225CEC0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// stw r28,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62484
	ctx.r11.u64 = ctx.r11.u64 | 62484;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r10,r10,62452
	ctx.r10.u64 = ctx.r10.u64 | 62452;
	// ori r9,r9,62471
	ctx.r9.u64 = ctx.r9.u64 | 62471;
	// li r24,1
	ctx.r24.s64 = 1;
	// stfsx f1,r31,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stbx r24,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r24.u8);
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x823395e0
	if (ctx.cr6.eq) goto loc_823395E0;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82232ba0
	ctx.lr = 0x823395D0;
	sub_82232BA0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823395e0
	if (ctx.cr0.eq) goto loc_823395E0;
	// stb r28,84(r3)
	REX_STORE_U8(ctx.r3.u32 + 84, ctx.r28.u8);
	// stb r28,85(r3)
	REX_STORE_U8(ctx.r3.u32 + 85, ctx.r28.u8);
loc_823395E0:
	// stw r24,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r24.u32);
	// b 0x82339714
	goto loc_82339714;
loc_823395E8:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r29,r29,-3084
	ctx.r29.s64 = ctx.r29.s64 + -3084;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f12,f0
	ctx.f12.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f12,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// srawi r10,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 3;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// subf. r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82339674
	if (!ctx.cr0.eq) goto loc_82339674;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82339674
	if (!ctx.cr6.gt) goto loc_82339674;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x822400e0
	ctx.lr = 0x82339630;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x822400e0
	ctx.lr = 0x8233964C;
	sub_822400E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// li r3,171
	ctx.r3.s64 = 171;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82250ad8
	ctx.lr = 0x82339674;
	sub_82250AD8(ctx, base);
loc_82339674:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// lfs f13,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r30,r30,-3072
	ctx.r30.s64 = ctx.r30.s64 + -3072;
	// lfs f0,-8400(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x823396d4
	if (!ctx.cr6.gt) goto loc_823396D4;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// lbz r10,103(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stb r10,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r10.u8);
	// stb r10,130(r1)
	REX_STORE_U8(ctx.r1.u32 + 130, ctx.r10.u8);
	// stb r10,131(r1)
	REX_STORE_U8(ctx.r1.u32 + 131, ctx.r10.u8);
	// stb r10,129(r1)
	REX_STORE_U8(ctx.r1.u32 + 129, ctx.r10.u8);
	// lwz r4,128(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// bctrl
	ctx.lr = 0x823396D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x823396f4
	goto loc_823396F4;
loc_823396D4:
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
	ctx.lr = 0x823396F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823396F4:
	// lfs f11,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,0(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f29,f13,f11
	ctx.f13.f64 = double(float(std::fma(ctx.f29.f64, ctx.f13.f64, ctx.f11.f64)));
	// lfs f0,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r29)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// fmadds f0,f29,f0,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, ctx.f12.f64)));
loc_82339710:
	// stfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
loc_82339714:
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x82757714
	ctx.lr = 0x82339720;
	__restfpr_28(ctx, base);
	// b 0x827566e0
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82413F98) {
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
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mulli r8,r11,52
	ctx.r8.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(52));
	// lwz r10,-9752(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -9752);
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r9,24(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82413fe8
	if (ctx.cr6.eq) goto loc_82413FE8;
	// cmpwi cr6,r9,5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 5, ctx.xer);
	// beq cr6,0x82413fe8
	if (ctx.cr6.eq) goto loc_82413FE8;
	// cmpwi cr6,r9,7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 7, ctx.xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// bne cr6,0x82413fec
	if (!ctx.cr6.eq) goto loc_82413FEC;
loc_82413FE8:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82413FEC:
	// clrlwi. r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x824140a0
	if (!ctx.cr0.eq) goto loc_824140A0;
	// lwz r10,24(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// mulli r11,r11,144
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(144));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lbz r10,142(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 142);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r4,r11,17
	ctx.r4.s64 = ctx.r11.s64 + 17;
	// bl 0x82249098
	ctx.lr = 0x82414014;
	sub_82249098(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-32272
	ctx.r4.s64 = ctx.r11.s64 + -32272;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82413698
	ctx.lr = 0x82414028;
	sub_82413698(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82371af8
	ctx.lr = 0x8241403C;
	sub_82371AF8(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x822490e8
	ctx.lr = 0x82414050;
	sub_822490E8(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822490e8
	ctx.lr = 0x82414064;
	sub_822490E8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82371af8
	ctx.lr = 0x82414074;
	sub_82371AF8(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x82414088
	if (!ctx.cr6.lt) goto loc_82414088;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_82414088:
	// bl 0x825b7440
	ctx.lr = 0x8241408C;
	sub_825B7440(ctx, base);
	// stw r3,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x824140A0;
	sub_82371AF8(ctx, base);
loc_824140A0:
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

DEFINE_REX_FUNC(sub_8241B230) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x8241B238;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8241b3b8
	if (ctx.cr6.eq) goto loc_8241B3B8;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8241b3b8
	if (ctx.cr6.eq) goto loc_8241B3B8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8225b198
	ctx.lr = 0x8241B264;
	sub_8225B198(ctx, base);
	// lwz r27,20(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,1
	ctx.r28.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8241b2c4
	if (ctx.cr6.eq) goto loc_8241B2C4;
	// addi r26,r3,4
	ctx.r26.s64 = ctx.r3.s64 + 4;
loc_8241B280:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bgt cr6,0x8241b290
	if (ctx.cr6.gt) goto loc_8241B290;
	// bl 0x82754c98
	ctx.lr = 0x8241B290;
	sub_82754C98(ctx, base);
loc_8241B290:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8241b2a4
	if (ctx.cr6.lt) goto loc_8241B2A4;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// b 0x8241b2a8
	goto loc_8241B2A8;
loc_8241B2A4:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8241B2A8:
	// lbzx r11,r11,r29
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bne cr6,0x8241b2b8
	if (!ctx.cr6.eq) goto loc_8241B2B8;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_8241B2B8:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x8241b280
	if (ctx.cr6.lt) goto loc_8241B280;
loc_8241B2C4:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82371af8
	ctx.lr = 0x8241B2D4;
	sub_82371AF8(ctx, base);
	// cmplw cr6,r28,r25
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r25.u32, ctx.xer);
	// bgt cr6,0x8241b2fc
	if (ctx.cr6.gt) goto loc_8241B2FC;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x822490e8
	ctx.lr = 0x8241B2F0;
	sub_822490E8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ed540
	ctx.lr = 0x8241B2F8;
	sub_823ED540(ctx, base);
	// b 0x8241b3b8
	goto loc_8241B3B8;
loc_8241B2FC:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// li r27,0
	ctx.r27.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addic. r29,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r29.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x8241b360
	if (ctx.cr0.eq) goto loc_8241B360;
loc_8241B314:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x8241b324
	if (ctx.cr6.gt) goto loc_8241B324;
	// bl 0x82754c98
	ctx.lr = 0x8241B324;
	sub_82754C98(ctx, base);
loc_8241B324:
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8241b338
	if (ctx.cr6.lt) goto loc_8241B338;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x8241b33c
	goto loc_8241B33C;
loc_8241B338:
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
loc_8241B33C:
	// lbzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bne cr6,0x8241b354
	if (!ctx.cr6.eq) goto loc_8241B354;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmplw cr6,r27,r25
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x8241b360
	if (ctx.cr6.eq) goto loc_8241B360;
loc_8241B354:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x8241b314
	if (ctx.cr6.lt) goto loc_8241B314;
loc_8241B360:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x8241B370;
	sub_82371AF8(ctx, base);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822490e8
	ctx.lr = 0x8241B384;
	sub_822490E8(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x822490e8
	ctx.lr = 0x8241B398;
	sub_822490E8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x8241B3A8;
	sub_82371AF8(ctx, base);
	// addi r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82249440
	ctx.lr = 0x8241B3B8;
	sub_82249440(ctx, base);
loc_8241B3B8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82426768) {
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
	// lwz r31,156(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lbz r11,153(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 153);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82426804
	if (!ctx.cr0.eq) goto loc_82426804;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-9904(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9904);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824267b4
	if (ctx.cr6.eq) goto loc_824267B4;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824267b4
	if (ctx.cr6.eq) goto loc_824267B4;
	// bl 0x82400cf0
	ctx.lr = 0x824267AC;
	sub_82400CF0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82426804
	if (!ctx.cr0.eq) goto loc_82426804;
loc_824267B4:
	// bl 0x82223348
	ctx.lr = 0x824267B8;
	sub_82223348(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,14
	ctx.r3.s64 = 14;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x82445228
	ctx.lr = 0x824267C8;
	sub_82445228(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82426804
	if (ctx.cr0.eq) goto loc_82426804;
	// lwz r10,80(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stb r11,153(r10)
	REX_STORE_U8(ctx.r10.u32 + 153, ctx.r11.u8);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,132(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,136(r11)
	REX_STORE_U64(ctx.r11.u32 + 136, ctx.r10.u64);
	// bl 0x823dc270
	ctx.lr = 0x824267FC;
	sub_823DC270(ctx, base);
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x823dc270
	ctx.lr = 0x82426804;
	sub_823DC270(ctx, base);
loc_82426804:
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

DEFINE_REX_FUNC(sub_8242CC70) {
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
	// lwz r3,40(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// bl 0x823dcb20
	ctx.lr = 0x8242CC94;
	sub_823DCB20(ctx, base);
	// lwz r10,68(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,52(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8242ccbc
	if (!ctx.cr6.eq) goto loc_8242CCBC;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lfs f13,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,15672(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15672);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8242cce0
	if (!ctx.cr6.lt) goto loc_8242CCE0;
loc_8242CCBC:
	// lwz r11,64(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r9,52(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x8242cce8
	if (!ctx.cr6.eq) goto loc_8242CCE8;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lfs f13,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,18812(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18812);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8242cce8
	if (ctx.cr6.gt) goto loc_8242CCE8;
loc_8242CCE0:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8242ccec
	goto loc_8242CCEC;
loc_8242CCE8:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8242CCEC:
	// lbz r9,152(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x8242cd10
	if (ctx.cr0.eq) goto loc_8242CD10;
	// lbz r9,153(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 153);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x8242cd10
	if (!ctx.cr0.eq) goto loc_8242CD10;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x8242cd14
	if (!ctx.cr0.eq) goto loc_8242CD14;
loc_8242CD10:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8242CD14:
	// lwz r3,60(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stb r11,57(r31)
	REX_STORE_U8(ctx.r31.u32 + 57, ctx.r11.u8);
	// lbz r11,152(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stb r11,56(r31)
	REX_STORE_U8(ctx.r31.u32 + 56, ctx.r11.u8);
	// beq cr6,0x8242cd34
	if (ctx.cr6.eq) goto loc_8242CD34;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823ddc08
	ctx.lr = 0x8242CD34;
	sub_823DDC08(ctx, base);
loc_8242CD34:
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

DEFINE_REX_FUNC(sub_82434FE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a8
	ctx.lr = 0x82434FF0;
	__savegprlr_24(ctx, base);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,356(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 356);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r10,-28460
	ctx.r10.s64 = ctx.r10.s64 + -28460;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwzx r5,r11,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x823dc188
	ctx.lr = 0x8243501C;
	sub_823DC188(ctx, base);
	// lwz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
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
	ctx.lr = 0x82435040;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 440);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824350b8
	if (!ctx.cr0.eq) goto loc_824350B8;
	// addi r31,r31,244
	ctx.r31.s64 = ctx.r31.s64 + 244;
	// li r30,12
	ctx.r30.s64 = 12;
loc_82435054:
	// lis r5,15
	ctx.r5.s64 = 983040;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823dc188
	ctx.lr = 0x82435064;
	sub_823DC188(ctx, base);
	// lwz r11,-44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -44);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
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
	ctx.lr = 0x82435088;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwzu r11,4(r31)
	ea = 4 + ctx.r31.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
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
	ctx.lr = 0x824350AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82435054
	if (!ctx.cr0.eq) goto loc_82435054;
	// b 0x824351a0
	goto loc_824351A0;
loc_824350B8:
	// stw r30,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r30.u32);
	// li r27,12
	ctx.r27.s64 = 12;
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// cmpwi cr6,r11,12
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 12, ctx.xer);
	// bgt cr6,0x824350d0
	if (ctx.cr6.gt) goto loc_824350D0;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
loc_824350D0:
	// li r26,0
	ctx.r26.s64 = 0;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r29,r31,244
	ctx.r29.s64 = ctx.r31.s64 + 244;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// addi r28,r11,-31904
	ctx.r28.s64 = ctx.r11.s64 + -31904;
loc_824350E4:
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// bge cr6,0x8243513c
	if (!ctx.cr6.lt) goto loc_8243513C;
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r10,404(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r25,r11,r10
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x823c8d50
	ctx.lr = 0x82435108;
	sub_823C8D50(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x823c9c98
	ctx.lr = 0x82435114;
	sub_823C9C98(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823dc188
	ctx.lr = 0x82435128;
	sub_823DC188(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827551c0
	ctx.lr = 0x82435138;
	sub_827551C0(ctx, base);
	// b 0x82435144
	goto loc_82435144;
loc_8243513C:
	// stb r26,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r26.u8);
	// stb r26,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r26.u8);
loc_82435144:
	// lwz r11,-44(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -44);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
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
	ctx.lr = 0x82435168;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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
	ctx.lr = 0x8243518C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,12
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 12, ctx.xer);
	// blt cr6,0x824350e4
	if (ctx.cr6.lt) goto loc_824350E4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824351a8
	ctx.lr = 0x824351A0;
	sub_824351A8(ctx, base);
loc_824351A0:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x827566f8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82442830) {
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
	// bl 0x82442750
	ctx.lr = 0x82442850;
	sub_82442750(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82442868
	if (ctx.cr0.eq) goto loc_82442868;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82442868
	if (ctx.cr6.eq) goto loc_82442868;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x82442868;
	sub_825FC588(ctx, base);
loc_82442868:
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

DEFINE_REX_FUNC(sub_82445C68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x82445C70;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,-28112
	ctx.r11.s64 = ctx.r11.s64 + -28112;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82446620
	ctx.lr = 0x82445C88;
	sub_82446620(ctx, base);
	// lwz r11,2332(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2332);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82445cbc
	if (ctx.cr6.eq) goto loc_82445CBC;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82445CAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r31,2340(r30)
	REX_STORE_U32(ctx.r30.u32 + 2340, ctx.r31.u32);
	// lwz r3,2332(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2332);
	// bl 0x82656530
	ctx.lr = 0x82445CB8;
	sub_82656530(ctx, base);
	// stw r31,2332(r30)
	REX_STORE_U32(ctx.r30.u32 + 2332, ctx.r31.u32);
loc_82445CBC:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x825c0668
	ctx.lr = 0x82445CC4;
	sub_825C0668(ctx, base);
	// lwz r3,2788(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2788);
	// addi r28,r30,2784
	ctx.r28.s64 = ctx.r30.s64 + 2784;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82445cd8
	if (ctx.cr6.eq) goto loc_82445CD8;
	// bl 0x825fc588
	ctx.lr = 0x82445CD8;
	sub_825FC588(ctx, base);
loc_82445CD8:
	// stw r31,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
	// addi r29,r30,2760
	ctx.r29.s64 = ctx.r30.s64 + 2760;
	// stw r31,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r31.u32);
	// stw r31,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r31.u32);
	// lwz r3,2764(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2764);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82445cf8
	if (ctx.cr6.eq) goto loc_82445CF8;
	// bl 0x825fc588
	ctx.lr = 0x82445CF8;
	sub_825FC588(ctx, base);
loc_82445CF8:
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// addi r28,r30,2708
	ctx.r28.s64 = ctx.r30.s64 + 2708;
	// stw r31,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
	// stw r31,12(r29)
	REX_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// lwz r3,2712(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2712);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82445d18
	if (ctx.cr6.eq) goto loc_82445D18;
	// bl 0x825fc588
	ctx.lr = 0x82445D18;
	sub_825FC588(ctx, base);
loc_82445D18:
	// stw r31,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
	// addi r29,r30,2548
	ctx.r29.s64 = ctx.r30.s64 + 2548;
	// stw r31,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r31.u32);
	// stw r31,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r31.u32);
	// lwz r3,2552(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2552);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82445d38
	if (ctx.cr6.eq) goto loc_82445D38;
	// bl 0x825fc588
	ctx.lr = 0x82445D38;
	sub_825FC588(ctx, base);
loc_82445D38:
	// stw r31,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// addi r28,r30,2412
	ctx.r28.s64 = ctx.r30.s64 + 2412;
	// stw r31,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
	// stw r31,12(r29)
	REX_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x824f6238
	ctx.lr = 0x82445D50;
	sub_824F6238(ctx, base);
	// lwz r3,2416(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2416);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82445d60
	if (ctx.cr6.eq) goto loc_82445D60;
	// bl 0x825fc588
	ctx.lr = 0x82445D60;
	sub_825FC588(ctx, base);
loc_82445D60:
	// stw r31,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825bd700
	ctx.lr = 0x82445D6C;
	sub_825BD700(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8244FBC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8244FBC8;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8245cd58
	ctx.lr = 0x8244FBDC;
	sub_8245CD58(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x8244fd2c
	if (ctx.cr0.eq) goto loc_8244FD2C;
	// clrlwi. r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244fc2c
	if (ctx.cr0.eq) goto loc_8244FC2C;
	// lwz r11,2340(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8244fc00
	if (!ctx.cr6.eq) goto loc_8244FC00;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8244fc18
	goto loc_8244FC18;
loc_8244FC00:
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,576(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 576);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8244FC14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8244FC18:
	// lwz r11,2340(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8244fc64
	if (ctx.cr6.eq) goto loc_8244FC64;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// b 0x8244fc70
	goto loc_8244FC70;
loc_8244FC2C:
	// lwz r11,2340(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8244fc40
	if (!ctx.cr6.eq) goto loc_8244FC40;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8244fc58
	goto loc_8244FC58;
loc_8244FC40:
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,576(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 576);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8244FC54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8244FC58:
	// lwz r11,2340(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8244fc6c
	if (!ctx.cr6.eq) goto loc_8244FC6C;
loc_8244FC64:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8244fc80
	goto loc_8244FC80;
loc_8244FC6C:
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
loc_8244FC70:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,576(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 576);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8244FC80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8244FC80:
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// blt cr6,0x8244fcc0
	if (ctx.cr6.lt) goto loc_8244FCC0;
	// cmpwi cr6,r31,9
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 9, ctx.xer);
	// bgt cr6,0x8244fcc0
	if (ctx.cr6.gt) goto loc_8244FCC0;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// blt cr6,0x8244fcc0
	if (ctx.cr6.lt) goto loc_8244FCC0;
	// cmpwi cr6,r3,9
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 9, ctx.xer);
	// bgt cr6,0x8244fcc0
	if (ctx.cr6.gt) goto loc_8244FCC0;
	// mulli r11,r31,9
	ctx.r11.s64 = static_cast<int64_t>(ctx.r31.u64 * static_cast<uint64_t>(9));
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r11,r11,-10
	ctx.r11.s64 = ctx.r11.s64 + -10;
	// addi r10,r10,-24648
	ctx.r10.s64 = ctx.r10.s64 + -24648;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// b 0x8244fcc4
	goto loc_8244FCC4;
loc_8244FCC0:
	// li r3,8
	ctx.r3.s64 = 8;
loc_8244FCC4:
	// bl 0x8246ef10
	ctx.lr = 0x8244FCC8;
	sub_8246EF10(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8244fcd8
	if (ctx.cr0.eq) goto loc_8244FCD8;
	// lhz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 20);
	// b 0x8244fcdc
	goto loc_8244FCDC;
loc_8244FCD8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8244FCDC:
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f31,f0
	ctx.f31.f64 = double(float(ctx.f0.f64));
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8244FD04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// bgt cr6,0x8244fd2c
	if (ctx.cr6.gt) goto loc_8244FD2C;
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8244FD20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// li r3,1
	ctx.r3.s64 = 1;
	// ble cr6,0x8244fd30
	if (!ctx.cr6.gt) goto loc_8244FD30;
loc_8244FD2C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244FD30:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82459D78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// addi r11,r3,96
	ctx.r11.s64 = ctx.r3.s64 + 96;
	// li r10,44
	ctx.r10.s64 = 44;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,44
	ctx.r11.s64 = ctx.r11.s64 + 44;
	// lfs f0,12484(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stfs f0,8(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f0,48(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f0,52(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f0,56(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f0,60(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f0,64(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f0,68(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f0,72(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f0,76(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f0,80(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f0,84(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f0,88(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f0,92(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// stw r9,116(r3)
	REX_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
	// stfs f0,96(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stb r9,120(r3)
	REX_STORE_U8(ctx.r3.u32 + 120, ctx.r9.u8);
	// stfs f0,100(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stfs f0,104(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stfs f0,108(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stfs f0,112(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// stfs f0,124(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// stfs f0,128(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// stfs f0,132(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// stfs f0,136(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 136, temp.u32);
loc_82459E24:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82459e24
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82459E24;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82460138) {
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
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x827567d0
	ctx.lr = 0x8246016C;
	sub_827567D0(ctx, base);
	// addi r4,r30,260
	ctx.r4.s64 = ctx.r30.s64 + 260;
	// addi r3,r31,260
	ctx.r3.s64 = ctx.r31.s64 + 260;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x827567d0
	ctx.lr = 0x8246017C;
	sub_827567D0(ctx, base);
	// addi r4,r30,324
	ctx.r4.s64 = ctx.r30.s64 + 324;
	// addi r3,r31,324
	ctx.r3.s64 = ctx.r31.s64 + 324;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x827567d0
	ctx.lr = 0x8246018C;
	sub_827567D0(ctx, base);
	// addi r4,r30,388
	ctx.r4.s64 = ctx.r30.s64 + 388;
	// addi r3,r31,388
	ctx.r3.s64 = ctx.r31.s64 + 388;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x827567d0
	ctx.lr = 0x8246019C;
	sub_827567D0(ctx, base);
	// addi r4,r30,452
	ctx.r4.s64 = ctx.r30.s64 + 452;
	// addi r3,r31,452
	ctx.r3.s64 = ctx.r31.s64 + 452;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x827567d0
	ctx.lr = 0x824601AC;
	sub_827567D0(ctx, base);
	// addi r4,r30,516
	ctx.r4.s64 = ctx.r30.s64 + 516;
	// addi r3,r31,516
	ctx.r3.s64 = ctx.r31.s64 + 516;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x827567d0
	ctx.lr = 0x824601BC;
	sub_827567D0(ctx, base);
	// addi r4,r30,580
	ctx.r4.s64 = ctx.r30.s64 + 580;
	// addi r3,r31,580
	ctx.r3.s64 = ctx.r31.s64 + 580;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x827567d0
	ctx.lr = 0x824601CC;
	sub_827567D0(ctx, base);
	// lbz r11,644(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 644);
	// addi r4,r30,684
	ctx.r4.s64 = ctx.r30.s64 + 684;
	// addi r3,r31,684
	ctx.r3.s64 = ctx.r31.s64 + 684;
	// li r5,28
	ctx.r5.s64 = 28;
	// stb r11,644(r31)
	REX_STORE_U8(ctx.r31.u32 + 644, ctx.r11.u8);
	// lwz r11,648(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 648);
	// stw r11,648(r31)
	REX_STORE_U32(ctx.r31.u32 + 648, ctx.r11.u32);
	// lfs f0,652(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 652);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,652(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 652, temp.u32);
	// lhz r11,656(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 656);
	// sth r11,656(r31)
	REX_STORE_U16(ctx.r31.u32 + 656, ctx.r11.u16);
	// lhz r11,658(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 658);
	// sth r11,658(r31)
	REX_STORE_U16(ctx.r31.u32 + 658, ctx.r11.u16);
	// lhz r11,660(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 660);
	// sth r11,660(r31)
	REX_STORE_U16(ctx.r31.u32 + 660, ctx.r11.u16);
	// lhz r11,662(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 662);
	// sth r11,662(r31)
	REX_STORE_U16(ctx.r31.u32 + 662, ctx.r11.u16);
	// lwz r11,664(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 664);
	// stw r11,664(r31)
	REX_STORE_U32(ctx.r31.u32 + 664, ctx.r11.u32);
	// lwz r11,668(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 668);
	// stw r11,668(r31)
	REX_STORE_U32(ctx.r31.u32 + 668, ctx.r11.u32);
	// lwz r11,672(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 672);
	// stw r11,672(r31)
	REX_STORE_U32(ctx.r31.u32 + 672, ctx.r11.u32);
	// lwz r11,676(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 676);
	// stw r11,676(r31)
	REX_STORE_U32(ctx.r31.u32 + 676, ctx.r11.u32);
	// lwz r11,680(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 680);
	// stw r11,680(r31)
	REX_STORE_U32(ctx.r31.u32 + 680, ctx.r11.u32);
	// bl 0x827567d0
	ctx.lr = 0x8246023C;
	sub_827567D0(ctx, base);
	// lwz r11,712(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 712);
	// addi r3,r31,728
	ctx.r3.s64 = ctx.r31.s64 + 728;
	// addi r4,r30,728
	ctx.r4.s64 = ctx.r30.s64 + 728;
	// li r5,60
	ctx.r5.s64 = 60;
	// stw r11,712(r31)
	REX_STORE_U32(ctx.r31.u32 + 712, ctx.r11.u32);
	// lwz r11,716(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 716);
	// stw r11,716(r31)
	REX_STORE_U32(ctx.r31.u32 + 716, ctx.r11.u32);
	// lwz r11,720(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 720);
	// stw r11,720(r31)
	REX_STORE_U32(ctx.r31.u32 + 720, ctx.r11.u32);
	// lhz r11,724(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 724);
	// sth r11,724(r31)
	REX_STORE_U16(ctx.r31.u32 + 724, ctx.r11.u16);
	// lbz r11,726(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 726);
	// stb r11,726(r31)
	REX_STORE_U8(ctx.r31.u32 + 726, ctx.r11.u8);
	// bl 0x827567d0
	ctx.lr = 0x82460274;
	sub_827567D0(ctx, base);
	// lhz r11,788(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 788);
	// addi r3,r31,792
	ctx.r3.s64 = ctx.r31.s64 + 792;
	// addi r4,r30,792
	ctx.r4.s64 = ctx.r30.s64 + 792;
	// sth r11,788(r31)
	REX_STORE_U16(ctx.r31.u32 + 788, ctx.r11.u16);
	// lhz r11,790(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 790);
	// sth r11,790(r31)
	REX_STORE_U16(ctx.r31.u32 + 790, ctx.r11.u16);
	// bl 0x8224e138
	ctx.lr = 0x82460290;
	sub_8224E138(ctx, base);
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

DEFINE_REX_FUNC(sub_82469598) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82469980
	if (ctx.cr6.eq) goto loc_82469980;
	// lwz r3,2340(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824695D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82469980
	if (!ctx.cr0.eq) goto loc_82469980;
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
	ctx.lr = 0x824695F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82469980
	if (!ctx.cr0.eq) goto loc_82469980;
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82469998
	if (ctx.cr6.eq) goto loc_82469998;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x824648f8
	ctx.lr = 0x82469618;
	sub_824648F8(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r30,0
	ctx.r30.s64 = 0;
	// stb r30,64(r31)
	REX_STORE_U8(ctx.r31.u32 + 64, ctx.r30.u8);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// cmpwi cr6,r10,31
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 31, ctx.xer);
	// bne cr6,0x82469638
	if (!ctx.cr6.eq) goto loc_82469638;
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
loc_82469638:
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r10,10
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 10, ctx.xer);
	// bgt cr6,0x82469888
	if (ctx.cr6.gt) goto loc_82469888;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-4264
	ctx.r12.s64 = ctx.r12.s64 + -4264;
	// lbzx r0,r12,r10
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r10.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32185
	ctx.r12.s64 = -2109276160;
	// nop
	// addi r12,r12,-27024
	ctx.r12.s64 = ctx.r12.s64 + -27024;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr
	switch (ctx.r10.u32) {
	case 0:
		goto loc_82469670;
	case 1:
		goto loc_82469804;
	case 2:
		goto loc_82469714;
	case 3:
		goto loc_82469888;
	case 4:
		goto loc_82469888;
	case 5:
		goto loc_82469714;
	case 6:
		goto loc_824696A8;
	case 7:
		goto loc_824696E0;
	case 8:
		goto loc_82469714;
	case 9:
		goto loc_82469858;
	case 10:
		goto loc_82469714;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82469670:
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82469698
	if (ctx.cr6.eq) goto loc_82469698;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82469690;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x824696a0
	if (ctx.cr6.eq) goto loc_824696A0;
loc_82469698:
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x82469884
	goto loc_82469884;
loc_824696A0:
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x82469884
	goto loc_82469884;
loc_824696A8:
	// lbz r10,65(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 65);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82469880
	if (!ctx.cr0.eq) goto loc_82469880;
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82469888
	if (ctx.cr6.eq) goto loc_82469888;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824696D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82469888
	if (!ctx.cr6.eq) goto loc_82469888;
	// b 0x82469880
	goto loc_82469880;
loc_824696E0:
	// lbz r10,65(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 65);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82469880
	if (!ctx.cr0.eq) goto loc_82469880;
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82469880
	if (ctx.cr6.eq) goto loc_82469880;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8246970C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// b 0x8246987c
	goto loc_8246987C;
loc_82469714:
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8246973c
	if (ctx.cr6.eq) goto loc_8246973C;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82469734;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82469880
	if (!ctx.cr0.eq) goto loc_82469880;
loc_8246973C:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,68(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82469754
	if (ctx.cr6.eq) goto loc_82469754;
	// stw r30,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// b 0x82469888
	goto loc_82469888;
loc_82469754:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82469880
	if (ctx.cr6.eq) goto loc_82469880;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 960);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82469778;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x824697d8
	if (ctx.cr6.eq) goto loc_824697D8;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// beq cr6,0x824697a0
	if (ctx.cr6.eq) goto loc_824697A0;
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// beq cr6,0x824697d0
	if (ctx.cr6.eq) goto loc_824697D0;
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// beq cr6,0x824697a0
	if (ctx.cr6.eq) goto loc_824697A0;
	// cmpwi cr6,r3,21
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 21, ctx.xer);
	// bne cr6,0x82469880
	if (!ctx.cr6.eq) goto loc_82469880;
loc_824697A0:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,2340(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,628(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 628);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824697B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// beq cr6,0x82469880
	if (ctx.cr6.eq) goto loc_82469880;
loc_824697C8:
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x82469884
	goto loc_82469884;
loc_824697D0:
	// li r11,9
	ctx.r11.s64 = 9;
	// b 0x82469884
	goto loc_82469884;
loc_824697D8:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x824697f4
	if (ctx.cr6.eq) goto loc_824697F4;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x824697f4
	if (ctx.cr6.eq) goto loc_824697F4;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82469884
	goto loc_82469884;
loc_824697F4:
	// lbz r11,65(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 65);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82469888
	if (ctx.cr0.eq) goto loc_82469888;
	// b 0x824697c8
	goto loc_824697C8;
loc_82469804:
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8246982c
	if (ctx.cr6.eq) goto loc_8246982C;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82469824;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82469880
	if (!ctx.cr0.eq) goto loc_82469880;
loc_8246982C:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,68(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82469848
	if (ctx.cr6.eq) goto loc_82469848;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,64(r31)
	REX_STORE_U8(ctx.r31.u32 + 64, ctx.r11.u8);
	// b 0x82469888
	goto loc_82469888;
loc_82469848:
	// lbz r11,65(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 65);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82469888
	if (ctx.cr0.eq) goto loc_82469888;
	// b 0x82469880
	goto loc_82469880;
loc_82469858:
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82469880
	if (ctx.cr6.eq) goto loc_82469880;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82469878;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
loc_8246987C:
	// beq cr6,0x82469888
	if (ctx.cr6.eq) goto loc_82469888;
loc_82469880:
	// li r11,7
	ctx.r11.s64 = 7;
loc_82469884:
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
loc_82469888:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// bl 0x82448730
	ctx.lr = 0x8246989C;
	sub_82448730(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x82469968
	if (!ctx.cr6.eq) goto loc_82469968;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r11,r11,-30000
	ctx.r11.s64 = ctx.r11.s64 + -30000;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r10,r10,-29952
	ctx.r10.s64 = ctx.r10.s64 + -29952;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_82469968:
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// std r11,76(r31)
	REX_STORE_U64(ctx.r31.u32 + 76, ctx.r11.u64);
	// bl 0x8246a138
	ctx.lr = 0x8246997C;
	sub_8246A138(ctx, base);
	// b 0x82469998
	goto loc_82469998;
loc_82469980:
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
	ctx.lr = 0x82469998;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82469998:
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

DEFINE_REX_FUNC(sub_8246E290) {
	REX_FUNC_PROLOGUE();
	// lwz r11,220(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 220);
	// lwz r10,216(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 216);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8246e2ac
	if (!ctx.cr0.eq) {
		sub_8246E2AC(ctx, base);
		return;
	}
	// li r3,0
	ctx.r3.s64 = 0;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8248D988) {
	REX_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,356(r3)
	REX_STORE_U8(ctx.r3.u32 + 356, ctx.r11.u8);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8248E1C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8275668c
	ctx.lr = 0x8248E1D0;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// li r6,12
	ctx.r6.s64 = 12;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// mr r19,r8
	ctx.r19.u64 = ctx.r8.u64;
	// mr r17,r9
	ctx.r17.u64 = ctx.r9.u64;
	// mr r18,r10
	ctx.r18.u64 = ctx.r10.u64;
	// bl 0x82481d60
	ctx.lr = 0x8248E204;
	sub_82481D60(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r10,292(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-24184
	ctx.r11.s64 = ctx.r11.s64 + -24184;
	// addi r29,r31,404
	ctx.r29.s64 = ctx.r31.s64 + 404;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r27,r31,388
	ctx.r27.s64 = ctx.r31.s64 + 388;
	// stw r30,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r30.u32);
	// addi r22,r31,424
	ctx.r22.s64 = ctx.r31.s64 + 424;
	// stw r30,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r30.u32);
	// stw r30,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r30.u32);
	// stw r30,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r30.u32);
	// stw r30,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r30.u32);
	// stw r30,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r30.u32);
	// stw r30,428(r31)
	REX_STORE_U32(ctx.r31.u32 + 428, ctx.r30.u32);
	// stw r30,432(r31)
	REX_STORE_U32(ctx.r31.u32 + 432, ctx.r30.u32);
	// stw r30,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r30.u32);
	// stb r10,159(r31)
	REX_STORE_U8(ctx.r31.u32 + 159, ctx.r10.u8);
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// lwz r28,396(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8248e290
	if (ctx.cr6.eq) goto loc_8248E290;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
	// cmplw cr6,r28,r28
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8248e28c
	if (ctx.cr6.eq) goto loc_8248E28C;
loc_8248E26C:
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x827567d0
	ctx.lr = 0x8248E27C;
	sub_827567D0(ctx, base);
	// addi r26,r26,44
	ctx.r26.s64 = ctx.r26.s64 + 44;
	// addi r25,r25,44
	ctx.r25.s64 = ctx.r25.s64 + 44;
	// cmplw cr6,r26,r28
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x8248e26c
	if (!ctx.cr6.eq) goto loc_8248E26C;
loc_8248E28C:
	// stw r25,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r25.u32);
loc_8248E290:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82523e48
	ctx.lr = 0x8248E298;
	sub_82523E48(ctx, base);
	// stw r30,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r30.u32);
	// stw r30,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r30.u32);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// stw r30,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r30.u32);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82486ab0
	ctx.lr = 0x8248E2B0;
	sub_82486AB0(ctx, base);
	// lis r29,-32110
	ctx.r29.s64 = -2104360960;
	// li r27,424
	ctx.r27.s64 = 424;
	// stw r3,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r3.u32);
	// lwz r11,-9788(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8248e2f4
	if (ctx.cr6.eq) goto loc_8248E2F4;
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// lwz r9,68(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// divw r10,r10,r27
	ctx.r10.u64 = uint32_t((ctx.r27.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r10.s32 / ctx.r27.s32 : 0);
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8248e2f4
	if (!ctx.cr6.lt) goto loc_8248E2F4;
	// mulli r10,r3,424
	ctx.r10.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(424));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,85
	ctx.r3.s64 = ctx.r11.s64 + 85;
	// b 0x8248e2f8
	goto loc_8248E2F8;
loc_8248E2F4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8248E2F8:
	// stw r3,372(r31)
	REX_STORE_U32(ctx.r31.u32 + 372, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8248e74c
	if (ctx.cr6.eq) goto loc_8248E74C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826565f0
	ctx.lr = 0x8248E30C;
	sub_826565F0(ctx, base);
	// stw r3,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8248e74c
	if (ctx.cr0.eq) goto loc_8248E74C;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82656568
	ctx.lr = 0x8248E320;
	sub_82656568(ctx, base);
	// stw r3,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r3.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32186
	ctx.r10.s64 = -2109341696;
	// lis r9,-32188
	ctx.r9.s64 = -2109472768;
	// addi r4,r10,-16784
	ctx.r4.s64 = ctx.r10.s64 + -16784;
	// addi r3,r9,5376
	ctx.r3.s64 = ctx.r9.s64 + 5376;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E340;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8248e74c
	if (ctx.cr0.eq) goto loc_8248E74C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1240(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1240);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E35C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r28,-32110
	ctx.r28.s64 = -2104360960;
	// beq 0x8248e3a0
	if (ctx.cr0.eq) goto loc_8248E3A0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825c0558
	ctx.lr = 0x8248E370;
	sub_825C0558(ctx, base);
	// lwz r11,-9744(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -9744);
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x825c07c8
	ctx.lr = 0x8248E388;
	sub_825C07C8(ctx, base);
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1220(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1220);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E3A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8248E3A0:
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lis r11,-32164
	ctx.r11.s64 = -2107899904;
	// addi r4,r11,2392
	ctx.r4.s64 = ctx.r11.s64 + 2392;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1216(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1216);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E3BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lis r11,-32164
	ctx.r11.s64 = -2107899904;
	// addi r4,r11,2248
	ctx.r4.s64 = ctx.r11.s64 + 2248;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1212(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1212);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E3D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lis r11,-32164
	ctx.r11.s64 = -2107899904;
	// addi r4,r11,2072
	ctx.r4.s64 = ctx.r11.s64 + 2072;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1208(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1208);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E3F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lis r11,-32196
	ctx.r11.s64 = -2109997056;
	// addi r4,r11,8960
	ctx.r4.s64 = ctx.r11.s64 + 8960;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E410;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lis r11,-32196
	ctx.r11.s64 = -2109997056;
	// addi r4,r11,8520
	ctx.r4.s64 = ctx.r11.s64 + 8520;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1108(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1108);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E42C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lis r11,-32196
	ctx.r11.s64 = -2109997056;
	// addi r4,r11,8568
	ctx.r4.s64 = ctx.r11.s64 + 8568;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E448;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-9788(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -9788);
	// lwz r10,364(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8248e480
	if (ctx.cr6.eq) goto loc_8248E480;
	// lwz r9,72(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// lwz r8,68(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// divw r9,r9,r27
	ctx.r9.u64 = uint32_t((ctx.r27.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r9.s32 / ctx.r27.s32 : 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8248e480
	if (!ctx.cr6.lt) goto loc_8248E480;
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// mulli r10,r10,424
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(424));
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x8248e484
	goto loc_8248E484;
loc_8248E480:
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
loc_8248E484:
	// stw r19,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r19.u32);
	// rlwinm r10,r24,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 4) & 0xFFFF0;
	// stw r9,456(r31)
	REX_STORE_U32(ctx.r31.u32 + 456, ctx.r9.u32);
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// lwz r11,4(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 4);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// lwz r11,-9744(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -9744);
	// stb r18,158(r31)
	REX_STORE_U8(ctx.r31.u32 + 158, ctx.r18.u8);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r24
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x8248e52c
	if (!ctx.cr6.eq) goto loc_8248E52C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8248e52c
	if (ctx.cr6.eq) goto loc_8248E52C;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8248e52c
	if (ctx.cr0.eq) goto loc_8248E52C;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82533088
	ctx.lr = 0x8248E4E8;
	sub_82533088(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r3,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r3.u32);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// lbz r6,158(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 158);
	// rlwimi r11,r10,3,27,28
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x18) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFE7);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82533878
	ctx.lr = 0x8248E510;
	sub_82533878(ctx, base);
	// stfs f1,272(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 272, temp.u32);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82533c60
	ctx.lr = 0x8248E524;
	sub_82533C60(ctx, base);
	// stfs f1,276(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 276, temp.u32);
	// b 0x8248e554
	goto loc_8248E554;
loc_8248E52C:
	// lwz r8,8(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// rlwimi r11,r10,4,27,28
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0x18) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r8,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r8.u32);
	// lfs f0,12(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,272(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 272, temp.u32);
	// lfs f0,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,276(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 276, temp.u32);
loc_8248E554:
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,352(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 352);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E56C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lwz r11,456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,356(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 356);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E588;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lwz r11,456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,360(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 360);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E5A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lwz r11,456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,364(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 364);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E5C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82223348
	ctx.lr = 0x8248E5C4;
	sub_82223348(ctx, base);
	// lwz r10,384(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lwz r11,4024(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4024);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// lwz r11,1248(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 1248);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E5EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// stb r30,356(r31)
	REX_STORE_U8(ctx.r31.u32 + 356, ctx.r30.u8);
	// stb r30,357(r31)
	REX_STORE_U8(ctx.r31.u32 + 357, ctx.r30.u8);
	// lbz r10,412(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 412);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8248e610
	if (ctx.cr0.eq) goto loc_8248E610;
	// lwz r11,416(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 416);
	// addi r11,r11,1861
	ctx.r11.s64 = ctx.r11.s64 + 1861;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
loc_8248E610:
	// stw r30,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r30.u32);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82523e48
	ctx.lr = 0x8248E61C;
	sub_82523E48(ctx, base);
	// li r11,4
	ctx.r11.s64 = 4;
	// lwz r10,-9744(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + -9744);
	// stw r11,444(r31)
	REX_STORE_U32(ctx.r31.u32 + 444, ctx.r11.u32);
	// lwz r8,172(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwzx r9,r9,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8248e654
	if (!ctx.cr6.eq) goto loc_8248E654;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8248e654
	if (ctx.cr6.eq) goto loc_8248E654;
	// li r30,1
	ctx.r30.s64 = 1;
loc_8248E654:
	// clrlwi. r10,r30,24
	ctx.r10.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8248e6a0
	if (ctx.cr0.eq) goto loc_8248E6A0;
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8248e6a0
	if (!ctx.cr6.eq) goto loc_8248E6A0;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8248e6a0
	if (ctx.cr6.eq) goto loc_8248E6A0;
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1400(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1400);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// beq 0x8248e6b0
	if (ctx.cr0.eq) goto loc_8248E6B0;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8248e6b4
	goto loc_8248E6B4;
loc_8248E6A0:
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1400(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1400);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8248E6B0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8248E6B4:
	// bctrl
	ctx.lr = 0x8248E6B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E6CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,384(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1200(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1200);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8248E6E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r30,4(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// b 0x8248e6fc
	goto loc_8248E6FC;
loc_8248E6EC:
	// lwz r4,20(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r3,16(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x8248a690
	ctx.lr = 0x8248E6F8;
	sub_8248A690(ctx, base);
	// addi r30,r30,60
	ctx.r30.s64 = ctx.r30.s64 + 60;
loc_8248E6FC:
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8248e6ec
	if (!ctx.cr6.eq) goto loc_8248E6EC;
	// lwz r28,4(r27)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// rotlwi r30,r11,0
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplw cr6,r28,r30
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8248e754
	if (ctx.cr6.eq) goto loc_8248E754;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r30
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8248e744
	if (ctx.cr6.eq) goto loc_8248E744;
loc_8248E724:
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827567d0
	ctx.lr = 0x8248E734;
	sub_827567D0(ctx, base);
	// addi r29,r29,60
	ctx.r29.s64 = ctx.r29.s64 + 60;
	// addi r28,r28,60
	ctx.r28.s64 = ctx.r28.s64 + 60;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8248e724
	if (!ctx.cr6.eq) goto loc_8248E724;
loc_8248E744:
	// stw r28,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r28.u32);
	// b 0x8248e754
	goto loc_8248E754;
loc_8248E74C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_8248E754:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x827566dc
	__restgprlr_17(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824B9CD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x824B9CE0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82481d60
	ctx.lr = 0x824B9CFC;
	sub_82481D60(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r8,r11,12484
	ctx.r8.s64 = ctx.r11.s64 + 12484;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r7,-32227
	ctx.r7.s64 = -2112028672;
	// lis r6,-32228
	ctx.r6.s64 = -2112094208;
	// lfs f0,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// li r31,0
	ctx.r31.s64 = 0;
	// stfs f0,364(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 364, temp.u32);
	// addi r11,r10,-19992
	ctx.r11.s64 = ctx.r10.s64 + -19992;
	// stfs f0,368(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 368, temp.u32);
	// li r10,128
	ctx.r10.s64 = 128;
	// stw r31,356(r30)
	REX_STORE_U32(ctx.r30.u32 + 356, ctx.r31.u32);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lfs f13,-232(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// stw r31,372(r30)
	REX_STORE_U32(ctx.r30.u32 + 372, ctx.r31.u32);
	// lfs f12,-22760(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -22760);
	ctx.f12.f64 = double(temp.f32);
	// stb r31,376(r30)
	REX_STORE_U8(ctx.r30.u32 + 376, ctx.r31.u8);
	// lfs f11,-2036(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -2036);
	ctx.f11.f64 = double(temp.f32);
	// ld r11,6848(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 6848);
	// stfs f0,428(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 428, temp.u32);
	// std r11,380(r30)
	REX_STORE_U64(ctx.r30.u32 + 380, ctx.r11.u64);
	// stfs f13,432(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 432, temp.u32);
	// stfs f12,436(r30)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r30.u32 + 436, temp.u32);
	// stw r10,468(r30)
	REX_STORE_U32(ctx.r30.u32 + 468, ctx.r10.u32);
	// stfs f13,460(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 460, temp.u32);
	// stw r29,472(r30)
	REX_STORE_U32(ctx.r30.u32 + 472, ctx.r29.u32);
	// stfs f0,464(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 464, temp.u32);
	// stfs f11,476(r30)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r30.u32 + 476, temp.u32);
	// stw r31,388(r30)
	REX_STORE_U32(ctx.r30.u32 + 388, ctx.r31.u32);
	// stw r31,392(r30)
	REX_STORE_U32(ctx.r30.u32 + 392, ctx.r31.u32);
	// stw r31,396(r30)
	REX_STORE_U32(ctx.r30.u32 + 396, ctx.r31.u32);
	// stw r31,400(r30)
	REX_STORE_U32(ctx.r30.u32 + 400, ctx.r31.u32);
	// stw r31,404(r30)
	REX_STORE_U32(ctx.r30.u32 + 404, ctx.r31.u32);
	// stw r31,408(r30)
	REX_STORE_U32(ctx.r30.u32 + 408, ctx.r31.u32);
	// stw r31,412(r30)
	REX_STORE_U32(ctx.r30.u32 + 412, ctx.r31.u32);
	// stw r31,416(r30)
	REX_STORE_U32(ctx.r30.u32 + 416, ctx.r31.u32);
	// stw r31,420(r30)
	REX_STORE_U32(ctx.r30.u32 + 420, ctx.r31.u32);
	// stw r31,424(r30)
	REX_STORE_U32(ctx.r30.u32 + 424, ctx.r31.u32);
	// stw r31,440(r30)
	REX_STORE_U32(ctx.r30.u32 + 440, ctx.r31.u32);
	// stw r31,444(r30)
	REX_STORE_U32(ctx.r30.u32 + 444, ctx.r31.u32);
	// stw r31,448(r30)
	REX_STORE_U32(ctx.r30.u32 + 448, ctx.r31.u32);
	// stw r31,452(r30)
	REX_STORE_U32(ctx.r30.u32 + 452, ctx.r31.u32);
	// stw r31,456(r30)
	REX_STORE_U32(ctx.r30.u32 + 456, ctx.r31.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,176(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 176);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// ori r11,r11,8456
	ctx.r11.u64 = ctx.r11.u64 | 8456;
	// stw r11,176(r30)
	REX_STORE_U32(ctx.r30.u32 + 176, ctx.r11.u32);
	// bl 0x825c0558
	ctx.lr = 0x824B9DC4;
	sub_825C0558(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,-9744(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9744);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x825c07c8
	ctx.lr = 0x824B9DE0;
	sub_825C07C8(ctx, base);
	// stb r31,347(r30)
	REX_STORE_U8(ctx.r30.u32 + 347, ctx.r31.u8);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824BED38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x824BED40;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,6(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,220(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 220);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r8,216(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 216);
	// addi r31,r3,212
	ctx.r31.s64 = ctx.r3.s64 + 212;
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
	// lfs f0,-7164(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7164);
	ctx.f0.f64 = double(temp.f32);
	// li r28,0
	ctx.r28.s64 = 0;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// beq 0x824bee0c
	if (ctx.cr0.eq) goto loc_824BEE0C;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r27,-32109
	ctx.r27.s64 = -2104295424;
loc_824BED94:
	// lwz r11,216(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 216);
	// lfs f0,-22812(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -22812);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824BEDB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,216(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 216);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824BEDD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,216(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 216);
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
	ctx.lr = 0x824BEDEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x824bed94
	if (ctx.cr6.lt) goto loc_824BED94;
loc_824BEE0C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824C6818) {
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
	// bl 0x824c6870
	ctx.lr = 0x824C6838;
	sub_824C6870(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824c6850
	if (ctx.cr0.eq) goto loc_824C6850;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824c6850
	if (ctx.cr6.eq) goto loc_824C6850;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x824C6850;
	sub_825FC588(ctx, base);
loc_824C6850:
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

DEFINE_REX_FUNC(sub_824C8520) {
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
	ctx.lr = 0x824C8540;
	sub_82371AF8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,6048
	ctx.r4.s64 = ctx.r11.s64 + 6048;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82484c30
	ctx.lr = 0x824C8554;
	sub_82484C30(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x824c8568
	if (!ctx.cr6.lt) goto loc_824C8568;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_824C8568:
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,-9788(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824c859c
	if (ctx.cr6.eq) goto loc_824C859C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82486f58
	ctx.lr = 0x824C8580;
	sub_82486F58(ctx, base);
	// lwz r11,-9788(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -9788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824c859c
	if (ctx.cr6.eq) goto loc_824C859C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,13288
	ctx.r3.s64 = ctx.r11.s64 + 13288;
	// bl 0x82486f58
	ctx.lr = 0x824C859C;
	sub_82486F58(ctx, base);
loc_824C859C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x824C85AC;
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

DEFINE_REX_FUNC(sub_824CA930) {
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
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lwz r11,408(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 408);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r10,-16992
	ctx.r10.s64 = ctx.r10.s64 + -16992;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// beq cr6,0x824ca988
	if (ctx.cr6.eq) goto loc_824CA988;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82232ab0
	ctx.lr = 0x824CA968;
	sub_82232AB0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824ca980
	if (ctx.cr0.eq) goto loc_824CA980;
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x822329c8
	ctx.lr = 0x824CA980;
	sub_822329C8(ctx, base);
loc_824CA980:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
loc_824CA988:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82483320
	ctx.lr = 0x824CA990;
	sub_82483320(ctx, base);
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

DEFINE_REX_FUNC(sub_824CD538) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x824CD540;
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
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22392
	ctx.r11.s64 = ctx.r11.s64 + 22392;
	// li r4,140
	ctx.r4.s64 = 140;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825fc4b0
	ctx.lr = 0x824CD564;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824cd588
	if (ctx.cr0.eq) goto loc_824CD588;
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r4,r10,2940
	ctx.r4.s64 = ctx.r10.s64 + 2940;
	// lfs f1,-21588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21588);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82233840
	ctx.lr = 0x824CD580;
	sub_82233840(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x824cd58c
	goto loc_824CD58C;
loc_824CD588:
	// li r31,0
	ctx.r31.s64 = 0;
loc_824CD58C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824cd6d8
	if (ctx.cr6.eq) goto loc_824CD6D8;
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
	ctx.lr = 0x824CD5AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-1744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1744);
	ctx.f2.f64 = double(temp.f32);
	// fneg f1,f2
	ctx.f1.u64 = ctx.f2.u64 ^ 0x8000000000000000;
	// bl 0x825c0958
	ctx.lr = 0x824CD5C0;
	sub_825C0958(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r30,r11,1732
	ctx.r30.s64 = ctx.r11.s64 + 1732;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-21760(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -21760);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,15948(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 15948);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825c0958
	ctx.lr = 0x824CD5E0;
	sub_825C0958(ctx, base);
	// lfs f0,17080(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 17080);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// lfs f2,76(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 76);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825c0958
	ctx.lr = 0x824CD5F8;
	sub_825C0958(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x822d2870
	ctx.lr = 0x824CD600;
	sub_822D2870(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// lfs f0,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// bl 0x822d2870
	ctx.lr = 0x824CD61C;
	sub_822D2870(ctx, base);
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824CD640;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824CD658;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,115
	ctx.r10.s64 = 115;
	// li r9,59
	ctx.r9.s64 = 59;
	// sth r10,88(r31)
	REX_STORE_U16(ctx.r31.u32 + 88, ctx.r10.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// sth r9,102(r31)
	REX_STORE_U16(ctx.r31.u32 + 102, ctx.r9.u16);
	// beq cr6,0x824cd678
	if (ctx.cr6.eq) goto loc_824CD678;
	// sth r10,84(r11)
	REX_STORE_U16(ctx.r11.u32 + 84, ctx.r10.u16);
loc_824CD678:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,91(r31)
	REX_STORE_U8(ctx.r31.u32 + 91, ctx.r10.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824cd690
	if (ctx.cr6.eq) goto loc_824CD690;
	// stb r10,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r10.u8);
loc_824CD690:
	// lis r28,-32240
	ctx.r28.s64 = -2112880640;
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r28,12484
	ctx.r11.s64 = ctx.r28.s64 + 12484;
	// lfs f2,2820(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2820);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825c0958
	ctx.lr = 0x824CD6AC;
	sub_825C0958(ctx, base);
	// lwz r11,40(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824CD6BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f1,12484(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 12484);
	ctx.f1.f64 = double(temp.f32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822338e0
	ctx.lr = 0x824CD6D0;
	sub_822338E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x824cd6dc
	goto loc_824CD6DC;
loc_824CD6D8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824CD6DC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824D6F60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x824D6F68;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824D6F84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824d70bc
	if (!ctx.cr0.eq) goto loc_824D70BC;
	// lhz r11,6(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 6);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,204(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r31,r30,196
	ctx.r31.s64 = ctx.r30.s64 + 196;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r8,200(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 200);
	// lis r27,-32109
	ctx.r27.s64 = -2104295424;
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
	// lfs f0,-7164(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7164);
	ctx.f0.f64 = double(temp.f32);
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r28,0
	ctx.r28.s64 = 0;
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// beq 0x824d7014
	if (ctx.cr0.eq) goto loc_824D7014;
	// li r29,0
	ctx.r29.s64 = 0;
loc_824D6FD4:
	// lwz r11,200(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 200);
	// lfs f0,-20608(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -20608);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824D6FF4;
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
	// blt cr6,0x824d6fd4
	if (ctx.cr6.lt) goto loc_824D6FD4;
loc_824D7014:
	// lwz r11,220(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// addi r31,r30,212
	ctx.r31.s64 = ctx.r30.s64 + 212;
	// lwz r10,216(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
	// li r28,0
	ctx.r28.s64 = 0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824d7074
	if (ctx.cr0.eq) goto loc_824D7074;
	// li r29,0
	ctx.r29.s64 = 0;
loc_824D7034:
	// lwz r11,216(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
	// lfs f0,-20608(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -20608);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824D7054;
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
	// blt cr6,0x824d7034
	if (ctx.cr6.lt) goto loc_824D7034;
loc_824D7074:
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82485f88
	ctx.lr = 0x824D7080;
	sub_82485F88(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f1,4672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4672);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,216(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824D70A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,216(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 216);
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
	ctx.lr = 0x824D70BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824D70BC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824E06B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x824E06B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// stb r10,269(r3)
	REX_STORE_U8(ctx.r3.u32 + 269, ctx.r10.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,22392
	ctx.r30.s64 = ctx.r11.s64 + 22392;
	// li r4,84
	ctx.r4.s64 = 84;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x824E06E0;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824e06f0
	if (ctx.cr0.eq) goto loc_824E06F0;
	// bl 0x8223fa60
	ctx.lr = 0x824E06EC;
	sub_8223FA60(ctx, base);
	// b 0x824e06f4
	goto loc_824E06F4;
loc_824E06F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824E06F4:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r3,440(r31)
	REX_STORE_U32(ctx.r31.u32 + 440, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r29,r11,-20592
	ctx.r29.s64 = ctx.r11.s64 + -20592;
	// beq cr6,0x824e0738
	if (ctx.cr6.eq) goto loc_824E0738;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824E0720;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,440(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 440);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824E0738;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824E0738:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
	// li r4,72
	ctx.r4.s64 = 72;
	// bl 0x825fc4b0
	ctx.lr = 0x824E0748;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824e0758
	if (ctx.cr0.eq) goto loc_824E0758;
	// bl 0x8223f810
	ctx.lr = 0x824E0754;
	sub_8223F810(ctx, base);
	// b 0x824e075c
	goto loc_824E075C;
loc_824E0758:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824E075C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,4112(r31)
	REX_STORE_U32(ctx.r31.u32 + 4112, ctx.r3.u32);
	// beq cr6,0x824e07d8
	if (ctx.cr6.eq) goto loc_824E07D8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824E0780;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,4112(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4112);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824E0798;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r3,4112(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4112);
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-7164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7164);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-19508(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -19508);
	ctx.f13.f64 = double(temp.f32);
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmadds f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// bctrl
	ctx.lr = 0x824E07D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824E07D8:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-20356
	ctx.r3.s64 = ctx.r11.s64 + -20356;
	// bl 0x825b5568
	ctx.lr = 0x824E07E4;
	sub_825B5568(ctx, base);
	// stw r3,4140(r31)
	REX_STORE_U32(ctx.r31.u32 + 4140, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x824e0800
	if (ctx.cr6.eq) goto loc_824E0800;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-20324
	ctx.r3.s64 = ctx.r11.s64 + -20324;
	// bl 0x825b73c0
	ctx.lr = 0x824E07FC;
	sub_825B73C0(ctx, base);
	// stw r3,4144(r31)
	REX_STORE_U32(ctx.r31.u32 + 4144, ctx.r3.u32);
loc_824E0800:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,8284
	ctx.r3.s64 = ctx.r11.s64 + 8284;
	// bl 0x825b5568
	ctx.lr = 0x824E080C;
	sub_825B5568(ctx, base);
	// stw r3,4148(r31)
	REX_STORE_U32(ctx.r31.u32 + 4148, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x824e0828
	if (ctx.cr6.eq) goto loc_824E0828;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,8316
	ctx.r3.s64 = ctx.r11.s64 + 8316;
	// bl 0x825b73c0
	ctx.lr = 0x824E0824;
	sub_825B73C0(ctx, base);
	// stw r3,4152(r31)
	REX_STORE_U32(ctx.r31.u32 + 4152, ctx.r3.u32);
loc_824E0828:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-20396
	ctx.r3.s64 = ctx.r11.s64 + -20396;
	// bl 0x825b5568
	ctx.lr = 0x824E0834;
	sub_825B5568(ctx, base);
	// stw r3,4156(r31)
	REX_STORE_U32(ctx.r31.u32 + 4156, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x824e0850
	if (ctx.cr6.eq) goto loc_824E0850;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-20364
	ctx.r3.s64 = ctx.r11.s64 + -20364;
	// bl 0x825b73c0
	ctx.lr = 0x824E084C;
	sub_825B73C0(ctx, base);
	// stw r3,4160(r31)
	REX_STORE_U32(ctx.r31.u32 + 4160, ctx.r3.u32);
loc_824E0850:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-20476
	ctx.r3.s64 = ctx.r11.s64 + -20476;
	// bl 0x825b5568
	ctx.lr = 0x824E085C;
	sub_825B5568(ctx, base);
	// stw r3,4164(r31)
	REX_STORE_U32(ctx.r31.u32 + 4164, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x824e0878
	if (ctx.cr6.eq) goto loc_824E0878;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-20444
	ctx.r3.s64 = ctx.r11.s64 + -20444;
	// bl 0x825b73c0
	ctx.lr = 0x824E0874;
	sub_825B73C0(ctx, base);
	// stw r3,4168(r31)
	REX_STORE_U32(ctx.r31.u32 + 4168, ctx.r3.u32);
loc_824E0878:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-20436
	ctx.r3.s64 = ctx.r11.s64 + -20436;
	// bl 0x825b5568
	ctx.lr = 0x824E0884;
	sub_825B5568(ctx, base);
	// stw r3,4172(r31)
	REX_STORE_U32(ctx.r31.u32 + 4172, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x824e08a0
	if (ctx.cr6.eq) goto loc_824E08A0;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-20404
	ctx.r3.s64 = ctx.r11.s64 + -20404;
	// bl 0x825b73c0
	ctx.lr = 0x824E089C;
	sub_825B73C0(ctx, base);
	// stw r3,4176(r31)
	REX_STORE_U32(ctx.r31.u32 + 4176, ctx.r3.u32);
loc_824E08A0:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-20560
	ctx.r3.s64 = ctx.r11.s64 + -20560;
	// bl 0x825b5568
	ctx.lr = 0x824E08AC;
	sub_825B5568(ctx, base);
	// stw r3,4180(r31)
	REX_STORE_U32(ctx.r31.u32 + 4180, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x824e08c8
	if (ctx.cr6.eq) goto loc_824E08C8;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-20528
	ctx.r3.s64 = ctx.r11.s64 + -20528;
	// bl 0x825b73c0
	ctx.lr = 0x824E08C4;
	sub_825B73C0(ctx, base);
	// stw r3,4184(r31)
	REX_STORE_U32(ctx.r31.u32 + 4184, ctx.r3.u32);
loc_824E08C8:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r3,r10,2968
	ctx.r3.s64 = ctx.r10.s64 + 2968;
	// lwz r11,-12436(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12436);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x824E08E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82617220
	ctx.lr = 0x824E08E8;
	sub_82617220(ctx, base);
	// li r11,400
	ctx.r11.s64 = 400;
	// stw r3,4188(r31)
	REX_STORE_U32(ctx.r31.u32 + 4188, ctx.r3.u32);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824F3FE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x824F3FE8;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82454930
	ctx.lr = 0x824F3FF8;
	sub_82454930(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lfs f0,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r4,r11,12484
	ctx.r4.s64 = ctx.r11.s64 + 12484;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r27,0
	ctx.r27.s64 = 0;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// li r26,1
	ctx.r26.s64 = 1;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r31,-9960(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + -9960);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
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
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// lfs f6,12484(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,1736(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 1736);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f6
	ctx.f3.f64 = ctx.f6.f64;
	// lfs f1,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// fmr f4,f6
	ctx.f4.f64 = ctx.f6.f64;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f13,f5
	ctx.cr6.compare(ctx.f13.f64, ctx.f5.f64);
	// lfs f2,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f2.f64 = double(temp.f32);
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x824f4160
	if (!ctx.cr6.gt) goto loc_824F4160;
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// li r3,0
	ctx.r3.s64 = 0;
	// ble cr6,0x824f4120
	if (!ctx.cr6.gt) goto loc_824F4120;
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824f4110
	if (ctx.cr6.eq) goto loc_824F4110;
	// fctiwz f0,f1
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f13,f2
	ctx.f13.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823c2720
	ctx.lr = 0x824F4110;
	sub_823C2720(ctx, base);
loc_824F4110:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x824f4158
	goto loc_824F4158;
loc_824F4120:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824f414c
	if (ctx.cr6.eq) goto loc_824F414C;
	// fctiwz f0,f2
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// fctiwz f0,f1
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823c2468
	ctx.lr = 0x824F414C;
	sub_823C2468(ctx, base);
loc_824F414C:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
loc_824F4158:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f3,f0
	ctx.f3.f64 = double(float(ctx.f0.f64));
loc_824F4160:
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f5
	ctx.cr6.compare(ctx.f13.f64, ctx.f5.f64);
	// ble cr6,0x824f41f8
	if (!ctx.cr6.gt) goto loc_824F41F8;
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// li r3,0
	ctx.r3.s64 = 0;
	// ble cr6,0x824f41bc
	if (!ctx.cr6.gt) goto loc_824F41BC;
	// li r27,1
	ctx.r27.s64 = 1;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824f41ac
	if (ctx.cr6.eq) goto loc_824F41AC;
	// fctiwz f0,f1
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// fctiwz f0,f2
	ctx.f0.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823c2d80
	ctx.lr = 0x824F41AC;
	sub_823C2D80(ctx, base);
loc_824F41AC:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// b 0x824f41f0
	goto loc_824F41F0;
loc_824F41BC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824f41e4
	if (ctx.cr6.eq) goto loc_824F41E4;
	// fctiwz f0,f2
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// fctiwz f0,f1
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823c29c8
	ctx.lr = 0x824F41E4;
	sub_823C29C8(ctx, base);
loc_824F41E4:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
loc_824F41F0:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f4,f0
	ctx.f4.f64 = double(float(ctx.f0.f64));
loc_824F41F8:
	// fabs f0,f3
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f3.u64 & ~0x8000000000000000;
	// fabs f13,f4
	ctx.f13.u64 = ctx.f4.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f5
	ctx.cr6.compare(ctx.f0.f64, ctx.f5.f64);
	// ble cr6,0x824f42ec
	if (!ctx.cr6.gt) goto loc_824F42EC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f2,104(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f2,108(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r11,-30224
	ctx.r30.s64 = ctx.r11.s64 + -30224;
	// stfs f2,96(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824f426c
	if (ctx.cr6.eq) goto loc_824F426C;
	// fctiwz f11,f1
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fctiwz f12,f12
	ctx.f12.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823c31d8
	ctx.lr = 0x824F4268;
	sub_823C31D8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_824F426C:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f2,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f2,108(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,0
	ctx.r3.s64 = 0;
	// stfs f2,104(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stfs f2,96(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824f42c4
	if (ctx.cr6.eq) goto loc_824F42C4;
	// lfs f12,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// fctiwz f11,f1
	ctx.f11.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// fctiwz f12,f12
	ctx.f12.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823c31d8
	ctx.lr = 0x824F42C4;
	sub_823C31D8(ctx, base);
loc_824F42C4:
	// clrlwi. r10,r29,24
	ctx.r10.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x824f42ec
	if (ctx.cr0.eq) goto loc_824F42EC;
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824f42ec
	if (ctx.cr0.eq) goto loc_824F42EC;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// beq cr6,0x824f42ec
	if (ctx.cr6.eq) goto loc_824F42EC;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// beq cr6,0x824f42ec
	if (ctx.cr6.eq) goto loc_824F42EC;
	// fmr f0,f6
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f6.f64;
	// li r26,0
	ctx.r26.s64 = 0;
loc_824F42EC:
	// clrlwi. r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824f42fc
	if (ctx.cr0.eq) goto loc_824F42FC;
	// clrlwi. r10,r27,24
	ctx.r10.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x824f4318
	if (!ctx.cr0.eq) goto loc_824F4318;
loc_824F42FC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824f4314
	if (ctx.cr6.eq) goto loc_824F4314;
	// clrlwi. r10,r27,24
	ctx.r10.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x824f4318
	if (ctx.cr0.eq) goto loc_824F4318;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824f4318
	if (!ctx.cr6.eq) goto loc_824F4318;
loc_824F4314:
	// clrlwi. r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
loc_824F4318:
	// clrlwi. r11,r26,24
	ctx.r11.u64 = ctx.r26.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824f432c
	if (ctx.cr0.eq) goto loc_824F432C;
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// li r3,1
	ctx.r3.s64 = 1;
	// ble cr6,0x824f4330
	if (!ctx.cr6.gt) goto loc_824F4330;
loc_824F432C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824F4330:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8250DF50) {
	REX_FUNC_PROLOGUE();
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8250DF58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8250DF60;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// beq 0x8250e084
	if (ctx.cr0.eq) goto loc_8250E084;
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm. r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8250df90
	if (!ctx.cr0.eq) goto loc_8250DF90;
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8250e084
	if (ctx.cr0.eq) goto loc_8250E084;
loc_8250DF90:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823c70a8
	ctx.lr = 0x8250DF9C;
	sub_823C70A8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,1132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1132);
	// addi r11,r11,12488
	ctx.r11.s64 = ctx.r11.s64 + 12488;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f12,-236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f12.f64 = double(temp.f32);
	// beq cr6,0x8250dfb8
	if (ctx.cr6.eq) goto loc_8250DFB8;
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_8250DFB8:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f11,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f13,-1404(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1404);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,92(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// vsubfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,1116(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1116, temp.u32);
	// stb r4,1205(r31)
	REX_STORE_U8(ctx.r31.u32 + 1205, ctx.r4.u8);
	// lfs f0,1184(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1184);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// stfs f0,1192(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 1192, temp.u32);
loc_8250E084:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82484918
	ctx.lr = 0x8250E094;
	sub_82484918(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82518140) {
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
	// bl 0x82518198
	ctx.lr = 0x82518160;
	sub_82518198(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82518178
	if (ctx.cr0.eq) goto loc_82518178;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82518178
	if (ctx.cr6.eq) goto loc_82518178;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x82518178;
	sub_825FC588(ctx, base);
loc_82518178:
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

DEFINE_REX_FUNC(sub_82519FA8) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r4,15460(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 15460);
	// bl 0x82483720
	ctx.lr = 0x82519FCC;
	sub_82483720(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,269(r31)
	REX_STORE_U8(ctx.r31.u32 + 269, ctx.r11.u8);
	// stb r10,192(r31)
	REX_STORE_U8(ctx.r31.u32 + 192, ctx.r10.u8);
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

DEFINE_REX_FUNC(sub_8251C370) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8251c500
	if (!ctx.cr0.eq) goto loc_8251C500;
	// lfs f0,368(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f13,368(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 368, temp.u32);
	// lfs f0,12288(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12288);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8251c3b8
	if (!ctx.cr6.gt) goto loc_8251C3B8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
loc_8251C3B8:
	// lwz r11,416(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x8251c4f0
	if (ctx.cr6.eq) goto loc_8251C4F0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8251c4f0
	if (ctx.cr6.eq) goto loc_8251C4F0;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r9,164(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// ld r8,44(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,-9744(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9744);
	// std r8,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r8.u64);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8251c4f0
	if (!ctx.cr6.eq) goto loc_8251C4F0;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8251c4f0
	if (ctx.cr6.eq) goto loc_8251C4F0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82448dc8
	ctx.lr = 0x8251C410;
	sub_82448DC8(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f11,152(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f11,148(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
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
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x825ff700
	ctx.lr = 0x8251C4D0;
	sub_825FF700(ctx, base);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r31,400
	ctx.r3.s64 = ctx.r31.s64 + 400;
	// bl 0x82600008
	ctx.lr = 0x8251C4E0;
	sub_82600008(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8251c4f0
	if (ctx.cr0.eq) goto loc_8251C4F0;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r11.u32);
loc_8251C4F0:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// stw r11,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// stw r10,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
loc_8251C500:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

DEFINE_REX_FUNC(sub_82529C98) {
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
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82529da4
	if (!ctx.cr0.eq) goto loc_82529DA4;
	// lbz r11,404(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 404);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82529d6c
	if (ctx.cr0.eq) goto loc_82529D6C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,388(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 388);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lfs f12,400(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 400);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r10,12484
	ctx.r9.s64 = ctx.r10.s64 + 12484;
	// lfs f0,-28872(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28872);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f11,f1,f0,f13
	ctx.f11.f64 = double(float(-std::fma(ctx.f1.f64, ctx.f0.f64, -ctx.f13.f64)));
	// lfs f0,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stfs f11,388(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 388, temp.u32);
	// lfs f13,1908(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f1,f1,f13,f12
	ctx.f1.f64 = double(float(std::fma(ctx.f1.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f1,400(r3)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 400, temp.u32);
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bge cr6,0x82529d08
	if (!ctx.cr6.lt) goto loc_82529D08;
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f0,388(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 388, temp.u32);
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
loc_82529D08:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82529D20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 388);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// lfs f0,412(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 412);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r9,r9,-256
	ctx.xer.ca = ctx.r9.u32 <= 4294967040;
	ctx.r9.u64 = static_cast<uint64_t>(-256) - ctx.r9.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82529D68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82529da4
	goto loc_82529DA4;
loc_82529D6C:
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lfs f0,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,396(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f12,f1,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f1.f64, ctx.f0.f64)));
	// stfs f0,392(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// lfs f13,376(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-11552(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11552);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f1,f0,f1,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f1.f64, ctx.f13.f64)));
	// stfs f1,376(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// bl 0x82755380
	ctx.lr = 0x82529D94;
	sub_82755380(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,392(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_82529DA4:
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

DEFINE_REX_FUNC(sub_82532528) {
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
	// bl 0x827576c4
	ctx.lr = 0x82532540;
	__savefpr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// std r5,240(r1)
	REX_STORE_U64(ctx.r1.u32 + 240, ctx.r5.u64);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// addi r4,r10,-2636
	ctx.r4.s64 = ctx.r10.s64 + -2636;
	// fmr f29,f3
	ctx.f29.f64 = ctx.f3.f64;
	// li r8,12
	ctx.r8.s64 = 12;
	// fmr f28,f4
	ctx.f28.f64 = ctx.f4.f64;
	// li r7,7
	ctx.r7.s64 = 7;
	// fmr f27,f5
	ctx.f27.f64 = ctx.f5.f64;
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82534a18
	ctx.lr = 0x82532584;
	sub_82534A18(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,244(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 244);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r6,308(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,300(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 300);
	// lfs f13,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// lwz r4,292(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lis r3,-32225
	ctx.r3.s64 = -2111897600;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r3,r3,-2464
	ctx.r3.s64 = ctx.r3.s64 + -2464;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stb r11,396(r31)
	REX_STORE_U8(ctx.r31.u32 + 396, ctx.r11.u8);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r5.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stb r6,159(r31)
	REX_STORE_U8(ctx.r31.u32 + 159, ctx.r6.u8);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stb r4,158(r31)
	REX_STORE_U8(ctx.r31.u32 + 158, ctx.r4.u8);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lfs f0,12484(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// stfs f0,368(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// stfs f31,372(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 372, temp.u32);
	// stfs f30,380(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// stfs f29,384(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 384, temp.u32);
	// stfs f27,388(r31)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// stfs f28,392(r31)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// bl 0x822d2870
	ctx.lr = 0x8253263C;
	sub_822D2870(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// lfs f6,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f6.f64 = double(temp.f32);
	// fadds f1,f30,f6
	ctx.f1.f64 = double(float(ctx.f30.f64 + ctx.f6.f64));
	// bl 0x822d2870
	ctx.lr = 0x82532654;
	sub_822D2870(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r30,r11,808
	ctx.r30.s64 = ctx.r11.s64 + 808;
	// lfs f0,996(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 996);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f13,52(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// fmuls f0,f9,f0
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// lwz r11,376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 376);
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// bge cr6,0x82532748
	if (!ctx.cr6.lt) goto loc_82532748;
	// lfs f0,392(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,388(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 388);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82532748
	if (!ctx.cr6.gt) goto loc_82532748;
	// ld r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 52);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// ld r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,392(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// bl 0x824d3cb8
	ctx.lr = 0x825326B4;
	sub_824D3CB8(ctx, base);
	// ld r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// bl 0x82532c90
	ctx.lr = 0x825326BC;
	sub_82532C90(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82532740
	if (!ctx.cr0.eq) goto loc_82532740;
	// lfs f0,380(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f0.f64 = double(temp.f32);
	// lfs f3,384(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 384);
	ctx.f3.f64 = double(temp.f32);
	// lfs f8,372(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 372);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f2,f8,f3,f0
	ctx.f2.f64 = double(float(std::fma(ctx.f8.f64, ctx.f3.f64, ctx.f0.f64)));
	// fadds f1,f2,f6
	ctx.f1.f64 = double(float(ctx.f2.f64 + ctx.f6.f64));
	// bl 0x822d2870
	ctx.lr = 0x825326DC;
	sub_822D2870(ctx, base);
	// lfs f9,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f0,f1,f9
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x822d2870
	ctx.lr = 0x825326F0;
	sub_822D2870(ctx, base);
	// fmuls f0,f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// bl 0x824d3cb8
	ctx.lr = 0x82532710;
	sub_824D3CB8(ctx, base);
	// lbz r9,159(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 159);
	// lwz r11,376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 376);
	// lfs f5,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 388);
	ctx.f5.f64 = double(temp.f32);
	// lbz r10,158(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 158);
	// lfs f4,392(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f4.f64 = double(temp.f32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r3,164(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// fmr f1,f8
	ctx.f1.f64 = ctx.f8.f64;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// ld r4,128(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// bl 0x82532478
	ctx.lr = 0x82532740;
	sub_82532478(ctx, base);
loc_82532740:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,396(r31)
	REX_STORE_U8(ctx.r31.u32 + 396, ctx.r11.u8);
loc_82532748:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x82757710
	ctx.lr = 0x82532758;
	__restfpr_27(ctx, base);
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

DEFINE_REX_FUNC(sub_825455F0) {
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
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lwz r11,852(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 852);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,-9744(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -9744);
	// lwz r8,172(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwzx r9,r9,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8254563c
	if (!ctx.cr6.eq) goto loc_8254563C;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x82545640
	if (!ctx.cr6.eq) goto loc_82545640;
loc_8254563C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82545640:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825456b8
	if (ctx.cr0.eq) goto loc_825456B8;
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x825456b8
	if (!ctx.cr6.eq) goto loc_825456B8;
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825456b8
	if (ctx.cr6.eq) goto loc_825456B8;
	// lbz r11,911(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 911);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825456a4
	if (ctx.cr0.eq) goto loc_825456A4;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r10,r11,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8254569c
	if (ctx.cr0.eq) goto loc_8254569C;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,-3204
	ctx.r11.s64 = ctx.r11.s64 + -3204;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,856(r31)
	REX_STORE_U32(ctx.r31.u32 + 856, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,860(r31)
	REX_STORE_U32(ctx.r31.u32 + 860, ctx.r11.u32);
	// b 0x825456b4
	goto loc_825456B4;
loc_8254569C:
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825456b8
	if (ctx.cr0.eq) goto loc_825456B8;
loc_825456A4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82448730
	ctx.lr = 0x825456AC;
	sub_82448730(ctx, base);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,856(r31)
	REX_STORE_U64(ctx.r31.u32 + 856, ctx.r11.u64);
loc_825456B4:
	// li r7,1
	ctx.r7.s64 = 1;
loc_825456B8:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
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

DEFINE_REX_FUNC(sub_82549EB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x82549EC0;
	__savegprlr_27(ctx, base);
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
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82549ee4
	if (!ctx.cr6.eq) goto loc_82549EE4;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x82549ef0
	goto loc_82549EF0;
loc_82549EE4:
	// lwz r10,12(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r8,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 4;
loc_82549EF0:
	// lwz r9,8(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lis r10,4095
	ctx.r10.s64 = 268369920;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// srawi r11,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 4;
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// bge cr6,0x82549f58
	if (!ctx.cr6.lt) goto loc_82549F58;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,1648
	ctx.r4.s64 = ctx.r11.s64 + 1648;
	// bl 0x82226b70
	ctx.lr = 0x82549F20;
	sub_82226B70(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x822269f0
	ctx.lr = 0x82549F2C;
	sub_822269F0(ctx, base);
	// bl 0x82227110
	ctx.lr = 0x82549F30;
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
	ctx.lr = 0x82549F44;
	sub_82227048(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82371af8
	ctx.lr = 0x82549F54;
	sub_82371AF8(ctx, base);
	// b 0x8254a27c
	goto loc_8254A27C;
loc_82549F58:
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8254a0c4
	if (!ctx.cr6.lt) goto loc_8254A0C4;
	// rlwinm r11,r8,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82549f7c
	if (!ctx.cr6.lt) goto loc_82549F7C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82549f80
	goto loc_82549F80;
loc_82549F7C:
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
loc_82549F80:
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82549f8c
	if (!ctx.cr6.lt) goto loc_82549F8C;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_82549F8C:
	// lis r10,-32113
	ctx.r10.s64 = -2104557568;
	// rlwinm r28,r11,4,0,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r11,r10,22392
	ctx.r11.s64 = ctx.r10.s64 + 22392;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825fc4b0
	ctx.lr = 0x82549FA8;
	sub_825FC4B0(ctx, base);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srawi r9,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 4;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add. r11,r8,r3
	ctx.r11.u64 = ctx.r8.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82549fe4
	if (ctx.cr0.eq) goto loc_82549FE4;
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r7,4(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r6,8(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r5,12(r27)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r7,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r6,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// stw r5,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
loc_82549FE4:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// b 0x8254a020
	goto loc_8254A020;
loc_82549FF0:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8254a018
	if (ctx.cr6.eq) goto loc_8254A018;
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r7,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r7,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
loc_8254A018:
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
loc_8254A020:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82549ff0
	if (!ctx.cr6.eq) goto loc_82549FF0;
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// lwz r9,8(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplw cr6,r30,r9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r9.u32, ctx.xer);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// beq cr6,0x8254a088
	if (ctx.cr6.eq) goto loc_8254A088;
	// subf r10,r8,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r8.u64;
	// subf r10,r31,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r31.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
loc_8254A050:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8254a078
	if (ctx.cr6.eq) goto loc_8254A078;
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// lwz r8,8(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// lwz r8,12(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
loc_8254A078:
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8254a050
	if (!ctx.cr6.eq) goto loc_8254A050;
loc_8254A088:
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// srawi r11,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 4;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x8254a0a8
	if (ctx.cr6.eq) goto loc_8254A0A8;
	// bl 0x825fc588
	ctx.lr = 0x8254A0A8;
	sub_825FC588(ctx, base);
loc_8254A0A8:
	// rlwinm r11,r30,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 4) & 0xFFFFFFF0;
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
	// b 0x8254a27c
	goto loc_8254A27C;
loc_8254A0C4:
	// subf r11,r30,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r30.u64;
	// srawi r11,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 4;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8254a1b4
	if (!ctx.cr6.lt) goto loc_8254A1B4;
	// addi r11,r30,16
	ctx.r11.s64 = ctx.r30.s64 + 16;
	// cmplw cr6,r30,r9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8254a11c
	if (ctx.cr6.eq) goto loc_8254A11C;
	// addi r10,r11,-16
	ctx.r10.s64 = ctx.r11.s64 + -16;
loc_8254A0E4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8254a10c
	if (ctx.cr6.eq) goto loc_8254A10C;
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// lwz r8,8(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// lwz r8,12(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
loc_8254A10C:
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8254a0e4
	if (!ctx.cr6.eq) goto loc_8254A0E4;
loc_8254A11C:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// srawi r10,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 4;
	// subfic r10,r10,1
	ctx.xer.ca = ctx.r10.u32 <= 1;
	ctx.r10.u64 = static_cast<uint64_t>(1) - ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8254a168
	if (ctx.cr6.eq) goto loc_8254A168;
loc_8254A134:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8254a15c
	if (ctx.cr6.eq) goto loc_8254A15C;
	// lwz r9,0(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r8,4(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r7,8(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r6,12(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// stw r6,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
loc_8254A15C:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bne 0x8254a134
	if (!ctx.cr0.eq) goto loc_8254A134;
loc_8254A168:
	// lwz r10,8(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r9,r10,-16
	ctx.r9.s64 = ctx.r10.s64 + -16;
	// stw r10,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r10.u32);
	// cmplw cr6,r30,r9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8254a27c
	if (ctx.cr6.eq) goto loc_8254A27C;
loc_8254A184:
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r8,4(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r7,8(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r6,12(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// stw r6,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8254a184
	if (!ctx.cr6.eq) goto loc_8254A184;
	// b 0x8254a27c
	goto loc_8254A27C;
loc_8254A1B4:
	// addi r11,r9,-16
	ctx.r11.s64 = ctx.r9.s64 + -16;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8254a200
	if (ctx.cr6.eq) goto loc_8254A200;
loc_8254A1C8:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8254a1f0
	if (ctx.cr6.eq) goto loc_8254A1F0;
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r7,4(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r7,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lwz r7,8(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// stw r7,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// lwz r7,12(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// stw r7,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
loc_8254A1F0:
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8254a1c8
	if (!ctx.cr6.eq) goto loc_8254A1C8;
loc_8254A200:
	// stw r10,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r10.u32);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8254a240
	if (ctx.cr6.eq) goto loc_8254A240;
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
loc_8254A210:
	// addi r11,r11,-16
	ctx.r11.s64 = ctx.r11.s64 + -16;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// bne cr6,0x8254a210
	if (!ctx.cr6.eq) goto loc_8254A210;
loc_8254A240:
	// addi r10,r30,16
	ctx.r10.s64 = ctx.r30.s64 + 16;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8254a27c
	if (ctx.cr6.eq) goto loc_8254A27C;
loc_8254A250:
	// lwz r9,0(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r8,4(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r7,8(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r6,12(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// stw r6,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8254a250
	if (!ctx.cr6.eq) goto loc_8254A250;
loc_8254A27C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8255FCF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x8255FCF8;
	__savegprlr_28(ctx, base);
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
	ctx.lr = 0x8255FD10;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8255fe6c
	if (!ctx.cr0.eq) goto loc_8255FE6C;
	// lwz r11,388(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 388);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8255fe6c
	if (ctx.cr6.eq) goto loc_8255FE6C;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lwz r28,-9960(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + -9960);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r30,84(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r29,100(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8255fddc
	if (ctx.cr6.eq) goto loc_8255FDDC;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823c4300
	ctx.lr = 0x8255FD74;
	sub_823C4300(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8255fddc
	if (ctx.cr0.eq) goto loc_8255FDDC;
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x823c33d0
	ctx.lr = 0x8255FD84;
	sub_823C33D0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8255fddc
	if (ctx.cr0.eq) goto loc_8255FDDC;
	// lwz r11,388(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 388);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8255fe6c
	if (ctx.cr6.eq) goto loc_8255FE6C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r10,220(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8255fdcc
	if (ctx.cr0.eq) goto loc_8255FDCC;
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r10.u32);
loc_8255FDCC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stfs f0,372(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 372, temp.u32);
	// stw r11,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r11.u32);
	// b 0x8255fe6c
	goto loc_8255FE6C;
loc_8255FDDC:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8255fdfc
	if (ctx.cr6.eq) goto loc_8255FDFC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823c2d80
	ctx.lr = 0x8255FDFC;
	sub_823C2D80(ctx, base);
loc_8255FDFC:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8255fe6c
	if (!ctx.cr6.lt) goto loc_8255FE6C;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f12,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
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
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,72(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
loc_8255FE6C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8256B6B0) {
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
	// lwz r11,380(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 380);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8256b6fc
	if (ctx.cr6.eq) goto loc_8256B6FC;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82232ab0
	ctx.lr = 0x8256B6DC;
	sub_82232AB0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8256b6f4
	if (ctx.cr0.eq) goto loc_8256B6F4;
	// lwz r11,380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 380);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x822329c8
	ctx.lr = 0x8256B6F4;
	sub_822329C8(ctx, base);
loc_8256B6F4:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r11.u32);
loc_8256B6FC:
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

DEFINE_REX_FUNC(sub_8256CC68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8256CC70;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8256cdfc
	if (!ctx.cr0.eq) goto loc_8256CDFC;
	// lwz r11,388(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 388);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8256cca4
	if (ctx.cr6.lt) goto loc_8256CCA4;
	// bne cr6,0x8256cdfc
	if (!ctx.cr6.eq) goto loc_8256CDFC;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,192(r3)
	REX_STORE_U8(ctx.r3.u32 + 192, ctx.r11.u8);
	// stb r10,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r10.u8);
	// b 0x8256cdfc
	goto loc_8256CDFC;
loc_8256CCA4:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,368(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8020(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8020);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8256cdcc
	if (!ctx.cr6.lt) goto loc_8256CDCC;
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,368(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 368, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f13,68(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,380(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 380);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r31,r1,112
	ctx.r31.s64 = ctx.r1.s64 + 112;
	// addi r29,r1,112
	ctx.r29.s64 = ctx.r1.s64 + 112;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f13,384(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 384);
	ctx.f13.f64 = double(temp.f32);
	// stfs f1,108(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f1,100(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f1,96(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,72(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vmulfp128 v63,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v59,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,68(r3)
	REX_STORE_U64(ctx.r3.u32 + 68, ctx.r11.u64);
	// b 0x8256cdfc
	goto loc_8256CDFC;
loc_8256CDCC:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,216(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 216);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,388(r3)
	REX_STORE_U32(ctx.r3.u32 + 388, ctx.r9.u32);
	// lfs f0,12484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12484);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,368(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 368, temp.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8256CDFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8256CDFC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8257C858) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8257C860;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	ctx.lr = 0x8257C87C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8257c9d4
	if (!ctx.cr0.eq) goto loc_8257C9D4;
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,216(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// li r4,0
	ctx.r4.s64 = 0;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,-7164(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7164);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8257C8C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lis r29,-32109
	ctx.r29.s64 = -2104295424;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfs f0,8392(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8392);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lfs f13,-1200(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1200);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bctrl
	ctx.lr = 0x8257C910;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r4,372(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8257C92C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// lfs f0,8392(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8392);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-1200(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1200);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bctrl
	ctx.lr = 0x8257C970;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r4,372(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8257C98C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
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
	ctx.lr = 0x8257C9A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,216(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8257C9C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// stb r11,140(r3)
	REX_STORE_U8(ctx.r3.u32 + 140, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82485f88
	ctx.lr = 0x8257C9D4;
	sub_82485F88(ctx, base);
loc_8257C9D4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82586198) {
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
	// addi r30,r11,13184
	ctx.r30.s64 = ctx.r11.s64 + 13184;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82483918
	ctx.lr = 0x825861C4;
	sub_82483918(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825861e4
	if (ctx.cr0.eq) goto loc_825861E4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82483918
	ctx.lr = 0x825861DC;
	sub_82483918(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825861ec
	if (!ctx.cr0.eq) goto loc_825861EC;
loc_825861E4:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_825861EC:
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

DEFINE_REX_FUNC(sub_825897F0) {
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
	// bl 0x82589848
	ctx.lr = 0x82589810;
	sub_82589848(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82589828
	if (ctx.cr0.eq) goto loc_82589828;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82589828
	if (ctx.cr6.eq) goto loc_82589828;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825fc588
	ctx.lr = 0x82589828;
	sub_825FC588(ctx, base);
loc_82589828:
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

DEFINE_REX_FUNC(sub_8258BF80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x8258BF88;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r7,67
	ctx.r7.s64 = 67;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82534a18
	ctx.lr = 0x8258BFB8;
	sub_82534A18(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stb r28,159(r31)
	REX_STORE_U8(ctx.r31.u32 + 159, ctx.r28.u8);
	// addi r11,r11,12488
	ctx.r11.s64 = ctx.r11.s64 + 12488;
	// addi r10,r10,14400
	ctx.r10.s64 = ctx.r10.s64 + 14400;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,368(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 368, temp.u32);
	// bne cr6,0x8258bfe8
	if (!ctx.cr6.eq) goto loc_8258BFE8;
	// lfs f0,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8258bfec
	goto loc_8258BFEC;
loc_8258BFE8:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
loc_8258BFEC:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,176(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r7,164(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// ori r6,r10,32
	ctx.r6.u64 = ctx.r10.u64 | 32;
	// li r30,0
	ctx.r30.s64 = 0;
	// stfs f0,376(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// rlwimi r9,r8,0,30,31
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x3) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFFC);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// lwz r11,-9744(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -9744);
	// rlwinm r10,r7,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFF0;
	// stw r30,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r30.u32);
	// stw r9,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r9.u32);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8258c07c
	if (!ctx.cr6.eq) goto loc_8258C07C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258c07c
	if (ctx.cr6.eq) goto loc_8258C07C;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8258c07c
	if (ctx.cr0.eq) goto loc_8258C07C;
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8258c07c
	if (ctx.cr6.eq) goto loc_8258C07C;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8258C070;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x8258c07c
	if (!ctx.cr6.eq) goto loc_8258C07C;
	// li r30,1
	ctx.r30.s64 = 1;
loc_8258C07C:
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f13,376(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 376);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f12,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,-30976(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30976);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bne 0x8258c160
	if (!ctx.cr0.eq) goto loc_8258C160;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r7,-29120
	ctx.r7.s64 = ctx.r7.s64 + -29120;
	// lfs f13,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x8258c21c
	goto loc_8258C21C;
loc_8258C160:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f0,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r7,r7,-28208
	ctx.r7.s64 = ctx.r7.s64 + -28208;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
loc_8258C21C:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825A31F8) {
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
	// lwz r30,64(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x825a322c
	if (!ctx.cr6.eq) goto loc_825A322C;
loc_825A3220:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,18(r7)
	REX_STORE_U8(ctx.r7.u32 + 18, ctx.r11.u8);
	// b 0x825a3670
	goto loc_825A3670;
loc_825A322C:
	// lwz r6,424(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 424);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x825a3220
	if (ctx.cr6.eq) goto loc_825A3220;
	// lwz r11,40(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 40);
	// li r10,20
	ctx.r10.s64 = 20;
	// lwz r9,36(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// divw. r11,r11,r10
	ctx.r11.u64 = uint32_t((ctx.r10.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r11.s32 / ctx.r10.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825a3220
	if (ctx.cr0.eq) goto loc_825A3220;
	// lwz r11,28(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x825a3524
	if (ctx.cr6.eq) goto loc_825A3524;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x825a33f0
	if (ctx.cr6.eq) goto loc_825A33F0;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x825a3660
	if (!ctx.cr6.eq) goto loc_825A3660;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,20(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r11,r11,-8400
	ctx.r11.s64 = ctx.r11.s64 + -8400;
	// addi r10,r10,12488
	ctx.r10.s64 = ctx.r10.s64 + 12488;
	// lfs f0,-22576(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22576);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f10,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-236(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -236);
	ctx.f9.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x825a32a0
	if (!ctx.cr6.lt) goto loc_825A32A0;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x825a32ac
	goto loc_825A32AC;
loc_825A32A0:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// ble cr6,0x825a32ac
	if (!ctx.cr6.gt) goto loc_825A32AC;
	// fmr f0,f9
	ctx.f0.f64 = ctx.f9.f64;
loc_825A32AC:
	// fsubs f8,f9,f0
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lwz r4,36(r7)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lfs f12,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f8,f13
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fmadds f7,f0,f12,f8
	ctx.f7.f64 = double(float(std::fma(ctx.f0.f64, ctx.f12.f64, ctx.f8.f64)));
	// fmr f2,f8
	ctx.f2.f64 = ctx.f8.f64;
	// fctidz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lbz r11,103(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// fmr f1,f7
	ctx.f1.f64 = ctx.f7.f64;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x825a3890
	ctx.lr = 0x825A32FC;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,40
	ctx.r3.s64 = ctx.r6.s64 + 40;
	// fmr f2,f8
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f8.f64;
	// addi r4,r11,20
	ctx.r4.s64 = ctx.r11.s64 + 20;
	// fmr f1,f7
	ctx.f1.f64 = ctx.f7.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A3314;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,80
	ctx.r3.s64 = ctx.r6.s64 + 80;
	// fmr f2,f8
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f8.f64;
	// addi r4,r11,40
	ctx.r4.s64 = ctx.r11.s64 + 40;
	// fmr f1,f7
	ctx.f1.f64 = ctx.f7.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A332C;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,120
	ctx.r3.s64 = ctx.r6.s64 + 120;
	// fmr f2,f8
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f8.f64;
	// addi r4,r11,40
	ctx.r4.s64 = ctx.r11.s64 + 40;
	// fmr f1,f7
	ctx.f1.f64 = ctx.f7.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A3344;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,160
	ctx.r3.s64 = ctx.r6.s64 + 160;
	// fmr f2,f8
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f8.f64;
	// addi r4,r11,20
	ctx.r4.s64 = ctx.r11.s64 + 20;
	// fmr f1,f7
	ctx.f1.f64 = ctx.f7.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A335C;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,200
	ctx.r3.s64 = ctx.r6.s64 + 200;
	// fmr f2,f8
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f8.f64;
	// addi r4,r11,60
	ctx.r4.s64 = ctx.r11.s64 + 60;
	// fmr f1,f7
	ctx.f1.f64 = ctx.f7.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A3374;
	sub_825A3890(ctx, base);
	// lwz r11,68(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// li r10,6
	ctx.r10.s64 = 6;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// ble cr6,0x825a3660
	if (!ctx.cr6.gt) goto loc_825A3660;
	// stfs f10,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r6,272
	ctx.r11.s64 = ctx.r6.s64 + 272;
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f9,108(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_825A33A0:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// ld r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r6,r11,-32
	ctx.r6.s64 = ctx.r11.s64 + -32;
	// stw r5,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r5.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r5,4(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r4,0(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r3,8(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// std r8,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r8.u64);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// stw r5,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// stw r4,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// stw r3,8(r6)
	REX_STORE_U32(ctx.r6.u32 + 8, ctx.r3.u32);
	// stw r9,12(r6)
	REX_STORE_U32(ctx.r6.u32 + 12, ctx.r9.u32);
	// lwz r9,68(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x825a33a0
	if (ctx.cr6.lt) goto loc_825A33A0;
	// b 0x825a3660
	goto loc_825A3660;
loc_825A33F0:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lwz r4,36(r7)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// li r11,255
	ctx.r11.s64 = 255;
	// addi r31,r10,12488
	ctx.r31.s64 = ctx.r10.s64 + 12488;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// lfs f9,12488(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12488);
	ctx.f9.f64 = double(temp.f32);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// fmr f2,f9
	ctx.f2.f64 = ctx.f9.f64;
	// lfs f10,-236(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -236);
	ctx.f10.f64 = double(temp.f32);
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// fmr f1,f10
	ctx.f1.f64 = ctx.f10.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A342C;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,40
	ctx.r3.s64 = ctx.r6.s64 + 40;
	// fmr f2,f9
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f9.f64;
	// addi r4,r11,20
	ctx.r4.s64 = ctx.r11.s64 + 20;
	// fmr f1,f10
	ctx.f1.f64 = ctx.f10.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A3444;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,80
	ctx.r3.s64 = ctx.r6.s64 + 80;
	// fmr f2,f9
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f9.f64;
	// addi r4,r11,40
	ctx.r4.s64 = ctx.r11.s64 + 40;
	// fmr f1,f10
	ctx.f1.f64 = ctx.f10.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A345C;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,120
	ctx.r3.s64 = ctx.r6.s64 + 120;
	// fmr f2,f9
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f9.f64;
	// addi r4,r11,40
	ctx.r4.s64 = ctx.r11.s64 + 40;
	// fmr f1,f10
	ctx.f1.f64 = ctx.f10.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A3474;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,160
	ctx.r3.s64 = ctx.r6.s64 + 160;
	// fmr f2,f9
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f9.f64;
	// addi r4,r11,20
	ctx.r4.s64 = ctx.r11.s64 + 20;
	// fmr f1,f10
	ctx.f1.f64 = ctx.f10.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A348C;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,200
	ctx.r3.s64 = ctx.r6.s64 + 200;
	// fmr f2,f9
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f9.f64;
	// addi r4,r11,60
	ctx.r4.s64 = ctx.r11.s64 + 60;
	// fmr f1,f10
	ctx.f1.f64 = ctx.f10.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A34A4;
	sub_825A3890(ctx, base);
	// lwz r11,68(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// li r10,6
	ctx.r10.s64 = 6;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// ble cr6,0x825a3660
	if (!ctx.cr6.gt) goto loc_825A3660;
	// lfs f0,-4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r6,272
	ctx.r11.s64 = ctx.r6.s64 + 272;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_825A34D4:
	// ld r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stw r5,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r5.u32);
	// addi r6,r11,-32
	ctx.r6.s64 = ctx.r11.s64 + -32;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// std r8,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r8.u64);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// lwz r5,12(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r4,4(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,8(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,12(r6)
	REX_STORE_U32(ctx.r6.u32 + 12, ctx.r5.u32);
	// stw r4,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r4.u32);
	// stw r3,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
	// stw r9,8(r6)
	REX_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lwz r9,68(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x825a34d4
	if (ctx.cr6.lt) goto loc_825A34D4;
	// b 0x825a3660
	goto loc_825A3660;
loc_825A3524:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// li r11,255
	ctx.r11.s64 = 255;
	// addi r10,r10,12488
	ctx.r10.s64 = ctx.r10.s64 + 12488;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// addi r6,r6,80
	ctx.r6.s64 = ctx.r6.s64 + 80;
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r31,10
	ctx.r31.s64 = 10;
	// lfs f3,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f3.f64 = double(temp.f32);
	// addi r11,r11,-8400
	ctx.r11.s64 = ctx.r11.s64 + -8400;
	// lfs f9,-236(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -236);
	ctx.f9.f64 = double(temp.f32);
	// fmr f8,f3
	ctx.f8.f64 = ctx.f3.f64;
	// lfs f10,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// addi r10,r9,-2512
	ctx.r10.s64 = ctx.r9.s64 + -2512;
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lfs f7,-22576(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22576);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,1932(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1932);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,21352(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 21352);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,408(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 408);
	ctx.f4.f64 = double(temp.f32);
loc_825A3578:
	// lfs f0,20(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f8,f5,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f8.f64, ctx.f5.f64, -ctx.f0.f64)));
	// fmuls f0,f0,f4
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f4.f64));
	// fcmpu cr6,f0,f3
	ctx.cr6.compare(ctx.f0.f64, ctx.f3.f64);
	// bge cr6,0x825a3594
	if (!ctx.cr6.lt) goto loc_825A3594;
	// fmr f0,f3
	ctx.f0.f64 = ctx.f3.f64;
	// b 0x825a35a0
	goto loc_825A35A0;
loc_825A3594:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f9.f64);
	// ble cr6,0x825a35a0
	if (!ctx.cr6.gt) goto loc_825A35A0;
	// fmr f0,f9
	ctx.f0.f64 = ctx.f9.f64;
loc_825A35A0:
	// fmuls f13,f8,f6
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// addi r3,r6,-80
	ctx.r3.s64 = ctx.r6.s64 + -80;
	// fsubs f12,f9,f0
	ctx.f12.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// lwz r4,36(r7)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// fmr f2,f10
	ctx.f2.f64 = ctx.f10.f64;
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmadds f31,f12,f7,f0
	ctx.f31.f64 = double(float(std::fma(ctx.f12.f64, ctx.f7.f64, ctx.f0.f64)));
	// fctidz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lbz r11,103(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x825a3890
	ctx.lr = 0x825A35D8;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,-40
	ctx.r3.s64 = ctx.r6.s64 + -40;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r4,r11,20
	ctx.r4.s64 = ctx.r11.s64 + 20;
	// fmr f2,f10
	ctx.f2.f64 = ctx.f10.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A35F0;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r4,r11,40
	ctx.r4.s64 = ctx.r11.s64 + 40;
	// fmr f2,f10
	ctx.f2.f64 = ctx.f10.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A3608;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,40
	ctx.r3.s64 = ctx.r6.s64 + 40;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r4,r11,40
	ctx.r4.s64 = ctx.r11.s64 + 40;
	// fmr f2,f10
	ctx.f2.f64 = ctx.f10.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A3620;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,80
	ctx.r3.s64 = ctx.r6.s64 + 80;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r4,r11,20
	ctx.r4.s64 = ctx.r11.s64 + 20;
	// fmr f2,f10
	ctx.f2.f64 = ctx.f10.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A3638;
	sub_825A3890(ctx, base);
	// lwz r11,36(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r3,r6,120
	ctx.r3.s64 = ctx.r6.s64 + 120;
	// fmr f2,f10
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f10.f64;
	// addi r4,r11,60
	ctx.r4.s64 = ctx.r11.s64 + 60;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825a3890
	ctx.lr = 0x825A3650;
	sub_825A3890(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r6,r6,240
	ctx.r6.s64 = ctx.r6.s64 + 240;
	// fadds f8,f8,f9
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// bne 0x825a3578
	if (!ctx.cr0.eq) goto loc_825A3578;
loc_825A3660:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82472dc8
	ctx.lr = 0x825A3670;
	sub_82472DC8(ctx, base);
loc_825A3670:
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

DEFINE_REX_FUNC(sub_825C305C) {
	REX_FUNC_PROLOGUE();
	// blr
	return;
}

DEFINE_REX_FUNC(sub_825C3078) {
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
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825C30A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,24
	ctx.r5.s64 = 24;
	// bl 0x827567d0
	ctx.lr = 0x825C30C0;
	sub_827567D0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x825C30D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

DEFINE_REX_FUNC(sub_825C7210) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a0
	ctx.lr = 0x825C7218;
	__savegprlr_22(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82622d30
	ctx.lr = 0x825C7224;
	sub_82622D30(ctx, base);
	// lis r22,-32110
	ctx.r22.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// lbz r8,101(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 101);
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-32110
	ctx.r7.s64 = -2104360960;
	// stw r11,-13212(r22)
	REX_STORE_U32(ctx.r22.u32 + -13212, ctx.r11.u32);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r6,-32110
	ctx.r6.s64 = -2104360960;
	// stw r10,-13208(r9)
	REX_STORE_U32(ctx.r9.u32 + -13208, ctx.r10.u32);
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// stb r8,-9905(r11)
	REX_STORE_U8(ctx.r11.u32 + -9905, ctx.r8.u8);
	// lbz r10,102(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 102);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mulli r5,r11,9
	ctx.r5.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(9));
	// stb r10,-9906(r9)
	REX_STORE_U8(ctx.r9.u32 + -9906, ctx.r10.u8);
	// stw r11,-13216(r7)
	REX_STORE_U32(ctx.r7.u32 + -13216, ctx.r11.u32);
	// rlwinm r9,r5,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xFFFFFFF;
	// stw r9,-13220(r6)
	REX_STORE_U32(ctx.r6.u32 + -13220, ctx.r9.u32);
	// bne 0x825c72ac
	if (!ctx.cr0.eq) goto loc_825C72AC;
	// lbz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 100);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825c72ac
	if (ctx.cr0.eq) goto loc_825C72AC;
	// lis r7,-32110
	ctx.r7.s64 = -2104360960;
	// lis r6,-32110
	ctx.r6.s64 = -2104360960;
	// lis r5,-32110
	ctx.r5.s64 = -2104360960;
	// li r11,1280
	ctx.r11.s64 = 1280;
	// li r10,720
	ctx.r10.s64 = 720;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,-13200(r7)
	REX_STORE_U32(ctx.r7.u32 + -13200, ctx.r11.u32);
	// stw r10,-13204(r6)
	REX_STORE_U32(ctx.r6.u32 + -13204, ctx.r10.u32);
	// stb r9,-9672(r5)
	REX_STORE_U8(ctx.r5.u32 + -9672, ctx.r9.u8);
	// b 0x825c72c4
	goto loc_825C72C4;
loc_825C72AC:
	// lis r7,-32110
	ctx.r7.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// li r10,1080
	ctx.r10.s64 = 1080;
	// li r11,1920
	ctx.r11.s64 = 1920;
	// stw r10,-13204(r7)
	REX_STORE_U32(ctx.r7.u32 + -13204, ctx.r10.u32);
	// stw r11,-13200(r9)
	REX_STORE_U32(ctx.r9.u32 + -13200, ctx.r11.u32);
loc_825C72C4:
	// clrlwi. r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825c72d4
	if (!ctx.cr0.eq) goto loc_825C72D4;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,-13212(r22)
	REX_STORE_U32(ctx.r22.u32 + -13212, ctx.r11.u32);
loc_825C72D4:
	// bl 0x825c6378
	ctx.lr = 0x825C72D8;
	sub_825C6378(ctx, base);
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r24,r11,22392
	ctx.r24.s64 = ctx.r11.s64 + 22392;
	// li r4,148
	ctx.r4.s64 = 148;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x825C72F0;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825c730c
	if (ctx.cr0.eq) goto loc_825C730C;
	// bl 0x825c65e0
	ctx.lr = 0x825C72FC;
	sub_825C65E0(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r31,r11,-9668
	ctx.r31.s64 = ctx.r11.s64 + -9668;
	// stw r3,-9668(r11)
	REX_STORE_U32(ctx.r11.u32 + -9668, ctx.r3.u32);
	// b 0x825c731c
	goto loc_825C731C;
loc_825C730C:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r31,r10,-9668
	ctx.r31.s64 = ctx.r10.s64 + -9668;
	// stw r11,-9668(r10)
	REX_STORE_U32(ctx.r10.u32 + -9668, ctx.r11.u32);
loc_825C731C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,19828
	ctx.r3.s64 = ctx.r11.s64 + 19828;
	// bl 0x825b5568
	ctx.lr = 0x825C7328;
	sub_825B5568(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// stw r3,-13224(r11)
	REX_STORE_U32(ctx.r11.u32 + -13224, ctx.r3.u32);
	// bl 0x825b5180
	ctx.lr = 0x825C7334;
	sub_825B5180(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,40
	ctx.r4.s64 = 40;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// bl 0x825fc4b0
	ctx.lr = 0x825C7344;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825c7360
	if (ctx.cr0.eq) goto loc_825C7360;
	// bl 0x825c5df8
	ctx.lr = 0x825C7350;
	sub_825C5DF8(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r23,r11,-9676
	ctx.r23.s64 = ctx.r11.s64 + -9676;
	// stw r3,-9676(r11)
	REX_STORE_U32(ctx.r11.u32 + -9676, ctx.r3.u32);
	// b 0x825c7370
	goto loc_825C7370;
loc_825C7360:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r23,r10,-9676
	ctx.r23.s64 = ctx.r10.s64 + -9676;
	// stw r11,-9676(r10)
	REX_STORE_U32(ctx.r10.u32 + -9676, ctx.r11.u32);
loc_825C7370:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// li r4,40
	ctx.r4.s64 = 40;
	// bl 0x825fc4b0
	ctx.lr = 0x825C7380;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825c739c
	if (ctx.cr0.eq) goto loc_825C739C;
	// bl 0x825c5538
	ctx.lr = 0x825C738C;
	sub_825C5538(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r26,r11,-9684
	ctx.r26.s64 = ctx.r11.s64 + -9684;
	// stw r3,-9684(r11)
	REX_STORE_U32(ctx.r11.u32 + -9684, ctx.r3.u32);
	// b 0x825c73ac
	goto loc_825C73AC;
loc_825C739C:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r26,r10,-9684
	ctx.r26.s64 = ctx.r10.s64 + -9684;
	// stw r11,-9684(r10)
	REX_STORE_U32(ctx.r10.u32 + -9684, ctx.r11.u32);
loc_825C73AC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// li r4,40
	ctx.r4.s64 = 40;
	// bl 0x825fc4b0
	ctx.lr = 0x825C73BC;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825c73d8
	if (ctx.cr0.eq) goto loc_825C73D8;
	// bl 0x825c5888
	ctx.lr = 0x825C73C8;
	sub_825C5888(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r28,r11,-9680
	ctx.r28.s64 = ctx.r11.s64 + -9680;
	// stw r3,-9680(r11)
	REX_STORE_U32(ctx.r11.u32 + -9680, ctx.r3.u32);
	// b 0x825c73e8
	goto loc_825C73E8;
loc_825C73D8:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r28,r10,-9680
	ctx.r28.s64 = ctx.r10.s64 + -9680;
	// stw r11,-9680(r10)
	REX_STORE_U32(ctx.r10.u32 + -9680, ctx.r11.u32);
loc_825C73E8:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// li r4,188
	ctx.r4.s64 = 188;
	// bl 0x825fc4b0
	ctx.lr = 0x825C73F8;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825c7414
	if (ctx.cr0.eq) goto loc_825C7414;
	// bl 0x825c53a8
	ctx.lr = 0x825C7404;
	sub_825C53A8(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r25,r11,-9688
	ctx.r25.s64 = ctx.r11.s64 + -9688;
	// stw r3,-9688(r11)
	REX_STORE_U32(ctx.r11.u32 + -9688, ctx.r3.u32);
	// b 0x825c7424
	goto loc_825C7424;
loc_825C7414:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r25,r10,-9688
	ctx.r25.s64 = ctx.r10.s64 + -9688;
	// stw r11,-9688(r10)
	REX_STORE_U32(ctx.r10.u32 + -9688, ctx.r11.u32);
loc_825C7424:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// li r4,188
	ctx.r4.s64 = 188;
	// bl 0x825fc4b0
	ctx.lr = 0x825C7434;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825c7450
	if (ctx.cr0.eq) goto loc_825C7450;
	// bl 0x825c51b0
	ctx.lr = 0x825C7440;
	sub_825C51B0(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r27,r11,-9692
	ctx.r27.s64 = ctx.r11.s64 + -9692;
	// stw r3,-9692(r11)
	REX_STORE_U32(ctx.r11.u32 + -9692, ctx.r3.u32);
	// b 0x825c7460
	goto loc_825C7460;
loc_825C7450:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r27,r10,-9692
	ctx.r27.s64 = ctx.r10.s64 + -9692;
	// stw r11,-9692(r10)
	REX_STORE_U32(ctx.r10.u32 + -9692, ctx.r11.u32);
loc_825C7460:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// li r4,208
	ctx.r4.s64 = 208;
	// lwz r30,-13212(r22)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r22.u32 + -13212);
	// bl 0x825fc4b0
	ctx.lr = 0x825C7474;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825c7494
	if (ctx.cr0.eq) goto loc_825C7494;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x825c8280
	ctx.lr = 0x825C7484;
	sub_825C8280(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r29,r11,-9656
	ctx.r29.s64 = ctx.r11.s64 + -9656;
	// stw r3,-9656(r11)
	REX_STORE_U32(ctx.r11.u32 + -9656, ctx.r3.u32);
	// b 0x825c74a4
	goto loc_825C74A4;
loc_825C7494:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r29,r10,-9656
	ctx.r29.s64 = ctx.r10.s64 + -9656;
	// stw r11,-9656(r10)
	REX_STORE_U32(ctx.r10.u32 + -9656, ctx.r11.u32);
loc_825C74A4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 32);
	// li r4,208
	ctx.r4.s64 = 208;
	// lwz r30,-13212(r22)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r22.u32 + -13212);
	// bl 0x825fc4b0
	ctx.lr = 0x825C74B8;
	sub_825FC4B0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825c74d8
	if (ctx.cr0.eq) goto loc_825C74D8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x825c7d68
	ctx.lr = 0x825C74C8;
	sub_825C7D68(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r30,r11,-9660
	ctx.r30.s64 = ctx.r11.s64 + -9660;
	// stw r3,-9660(r11)
	REX_STORE_U32(ctx.r11.u32 + -9660, ctx.r3.u32);
	// b 0x825c74e8
	goto loc_825C74E8;
loc_825C74D8:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r10,-9660
	ctx.r30.s64 = ctx.r10.s64 + -9660;
	// stw r11,-9660(r10)
	REX_STORE_U32(ctx.r10.u32 + -9660, ctx.r11.u32);
loc_825C74E8:
	// bl 0x825c7a90
	ctx.lr = 0x825C74EC;
	sub_825C7A90(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// li r5,102
	ctx.r5.s64 = 102;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x826177a8
	ctx.lr = 0x825C7508;
	sub_826177A8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,103
	ctx.r5.s64 = 103;
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// addi r4,r10,12
	ctx.r4.s64 = ctx.r10.s64 + 12;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x826177a8
	ctx.lr = 0x825C7520;
	sub_826177A8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,111
	ctx.r5.s64 = 111;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x826177a8
	ctx.lr = 0x825C753C;
	sub_826177A8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,101
	ctx.r5.s64 = 101;
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x826177a8
	ctx.lr = 0x825C7558;
	sub_826177A8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,102
	ctx.r5.s64 = 102;
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r4,r10,12
	ctx.r4.s64 = ctx.r10.s64 + 12;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x826177a8
	ctx.lr = 0x825C7570;
	sub_826177A8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,104
	ctx.r5.s64 = 104;
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x826177a8
	ctx.lr = 0x825C758C;
	sub_826177A8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,104
	ctx.r5.s64 = 104;
	// lwz r10,0(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x826177a8
	ctx.lr = 0x825C75A8;
	sub_826177A8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,103
	ctx.r5.s64 = 103;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r4,r10,32
	ctx.r4.s64 = ctx.r10.s64 + 32;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x826177a8
	ctx.lr = 0x825C75C0;
	sub_826177A8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,108
	ctx.r5.s64 = 108;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r4,r11,32
	ctx.r4.s64 = ctx.r11.s64 + 32;
	// lwz r3,12(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// bl 0x826177a8
	ctx.lr = 0x825C75D8;
	sub_826177A8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r5,114
	ctx.r5.s64 = 114;
	// lwz r4,-13188(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + -13188);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x826177a8
	ctx.lr = 0x825C75F0;
	sub_826177A8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825CF458) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x825cf470
	if (!ctx.cr6.eq) goto loc_825CF470;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr
	return;
loc_825CF470:
	// lwz r3,40(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_825DDB60) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x825dd8b8
	sub_825DD8B8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825DDD80) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,22872
	ctx.r10.s64 = ctx.r11.s64 + 22872;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x825dddd8
	if (ctx.cr6.eq) goto loc_825DDDD8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825DDDC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,72(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl
	ctx.lr = 0x825DDDD8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825DDDD8:
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

DEFINE_REX_FUNC(sub_825E0F80) {
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
	// lwz r31,32(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825E0FA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lhz r3,12(r8)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r8.u32 + 12);
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

DEFINE_REX_FUNC(sub_825E2FC8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x825e1778
	sub_825E1778(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825E3138) {
	REX_FUNC_PROLOGUE();
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// addi r3,r11,10
	ctx.r3.s64 = ctx.r11.s64 + 10;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_825E3628) {
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
	// lwz r3,28(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,23400
	ctx.r10.s64 = ctx.r11.s64 + 23400;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x825e3668
	if (ctx.cr6.eq) goto loc_825E3668;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825E3668;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E3668:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825e3688
	if (ctx.cr6.eq) goto loc_825E3688;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825E3688;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E3688:
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825e36cc
	if (ctx.cr6.eq) goto loc_825E36CC;
	// lwz r10,-4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// addi r3,r11,-4
	ctx.r3.s64 = ctx.r11.s64 + -4;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825e36c0
	if (ctx.cr6.eq) goto loc_825E36C0;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl
	ctx.lr = 0x825E36BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825e36cc
	goto loc_825E36CC;
loc_825E36C0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825e36cc
	if (ctx.cr6.eq) goto loc_825E36CC;
	// bl 0x825fc588
	ctx.lr = 0x825E36CC;
	sub_825FC588(ctx, base);
loc_825E36CC:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r11,20844
	ctx.r10.s64 = ctx.r11.s64 + 20844;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_825E98B8) {
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
	// lwz r10,108(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825E98DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,132(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 132);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl
	ctx.lr = 0x825E98F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x825e9920
	if (ctx.cr6.eq) goto loc_825E9920;
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r4,20(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r3,56(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 56);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,92(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 92);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl
	ctx.lr = 0x825E9920;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E9920:
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

DEFINE_REX_FUNC(sub_825ED1A0) {
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
	// bl 0x825ed1f8
	ctx.lr = 0x825ED1C0;
	sub_825ED1F8(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825ed1e0
	if (ctx.cr6.eq) goto loc_825ED1E0;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32783
	ctx.r4.u64 = ctx.r4.u64 | 32783;
	// bl 0x82657b88
	ctx.lr = 0x825ED1DC;
	sub_82657B88(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825ED1E0:
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

DEFINE_REX_FUNC(sub_825F0BF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a0
	ctx.lr = 0x825F0C00;
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
	// bl 0x825f03b8
	ctx.lr = 0x825F0C48;
	sub_825F03B8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825f0d94
	if (ctx.cr6.eq) goto loc_825F0D94;
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r3,-8
	ctx.r11.s64 = ctx.r3.s64 + -8;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_825F0C64:
	// stdu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U64(ea, ctx.r9.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x825f0c64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825F0C64;
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
	// bne cr6,0x825f0c98
	if (!ctx.cr6.eq) goto loc_825F0C98;
	// stw r23,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r23.u32);
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// b 0x825f0cc4
	goto loc_825F0CC4;
loc_825F0C98:
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
loc_825F0CC4:
	// cmpwi cr6,r29,16
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 16, ctx.xer);
	// bge cr6,0x825f0cd4
	if (!ctx.cr6.lt) goto loc_825F0CD4;
	// li r27,16
	ctx.r27.s64 = 16;
	// b 0x825f0ce4
	goto loc_825F0CE4;
loc_825F0CD4:
	// lis r11,256
	ctx.r11.s64 = 16777216;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x825f0ce4
	if (!ctx.cr6.gt) goto loc_825F0CE4;
	// lis r27,256
	ctx.r27.s64 = 16777216;
loc_825F0CE4:
	// lis r11,2047
	ctx.r11.s64 = 134152192;
	// ori r10,r11,65535
	ctx.r10.u64 = ctx.r11.u64 | 65535;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x825f0d6c
	if (ctx.cr6.lt) goto loc_825F0D6C;
	// lis r28,2047
	ctx.r28.s64 = 134152192;
	// ori r28,r28,65534
	ctx.r28.u64 = ctx.r28.u64 | 65534;
loc_825F0CFC:
	// cmpw cr6,r27,r28
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r28.s32, ctx.xer);
	// ble cr6,0x825f0d08
	if (!ctx.cr6.gt) goto loc_825F0D08;
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
loc_825F0D08:
	// addi r29,r31,52
	ctx.r29.s64 = ctx.r31.s64 + 52;
	// stw r27,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// beq cr6,0x825f0da0
	if (ctx.cr6.eq) goto loc_825F0DA0;
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
	// bl 0x82765088
	ctx.lr = 0x825F0D34;
	sub_82765088(ctx, base);
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825f0da0
	if (!ctx.cr6.eq) goto loc_825F0DA0;
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f0d80
	if (ctx.cr6.eq) goto loc_825F0D80;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825F0D60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
loc_825F0D6C:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bgt cr6,0x825f0cfc
	if (ctx.cr6.gt) goto loc_825F0CFC;
	// li r28,-1
	ctx.r28.s64 = -1;
	// mr r25,r23
	ctx.r25.u64 = ctx.r23.u64;
	// b 0x825f0d08
	goto loc_825F0D08;
loc_825F0D80:
	// bl 0x8265d608
	ctx.lr = 0x825F0D84;
	sub_8265D608(ctx, base);
	// bl 0x8265d608
	ctx.lr = 0x825F0D88;
	sub_8265D608(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// bl 0x8265ca30
	ctx.lr = 0x825F0D94;
	sub_8265CA30(ctx, base);
loc_825F0D94:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
loc_825F0DA0:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x825f0e08
	if (ctx.cr6.eq) goto loc_825F0E08;
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
	// bl 0x82765088
	ctx.lr = 0x825F0DC0;
	sub_82765088(ctx, base);
	// stw r3,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825f0e08
	if (!ctx.cr6.eq) goto loc_825F0E08;
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825f0ddc
	if (ctx.cr6.eq) goto loc_825F0DDC;
	// bl 0x82656df0
	ctx.lr = 0x825F0DDC;
	sub_82656DF0(ctx, base);
loc_825F0DDC:
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f0d80
	if (ctx.cr6.eq) goto loc_825F0D80;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825F0DFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
loc_825F0E08:
	// lwz r28,48(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
loc_825F0E0C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x825f0e68
	if (ctx.cr6.lt) goto loc_825F0E68;
	// beq cr6,0x825f0fa0
	if (ctx.cr6.eq) goto loc_825F0FA0;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x825f0e28
	if (!ctx.cr6.gt) goto loc_825F0E28;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_825F0E28:
	// lwsync
	// subf r10,r28,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r28.u64;
loc_825F0E30:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x825f0e54
	if (!ctx.cr6.eq) goto loc_825F0E54;
	// stwcx. r10,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825f0e30
	if (!ctx.cr0.eq) goto loc_825F0E30;
	// b 0x825f0e5c
	goto loc_825F0E5C;
loc_825F0E54:
	// stwcx. r9,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_825F0E5C:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x825f0e0c
	if (!ctx.cr6.eq) goto loc_825F0E0C;
loc_825F0E68:
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
	// bl 0x825f0478
	ctx.lr = 0x825F0E80;
	sub_825F0478(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825f0e90
	if (!ctx.cr6.eq) goto loc_825F0E90;
	// stw r23,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r23.u32);
	// b 0x825f0fa0
	goto loc_825F0FA0;
loc_825F0E90:
	// addi r11,r31,56
	ctx.r11.s64 = ctx.r31.s64 + 56;
loc_825F0E94:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r28,r10
	ctx.r9.u64 = ctx.r28.u64 + ctx.r10.u64;
	// stwcx. r9,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825f0e94
	if (!ctx.cr0.eq) goto loc_825F0E94;
	// addi r7,r28,-1
	ctx.r7.s64 = ctx.r28.s64 + -1;
	// add r9,r30,r3
	ctx.r9.u64 = ctx.r30.u64 + ctx.r3.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x825f0f2c
	if (ctx.cr6.eq) goto loc_825F0F2C;
loc_825F0EC4:
	// addi r9,r9,-16
	ctx.r9.s64 = ctx.r9.s64 + -16;
	// rldicr r8,r9,32,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF00000000;
loc_825F0ECC:
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
loc_825F0EEC:
	// mfmsr r3
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r3.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// ldarx r4,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u64 = REX_LOAD_RESERVED_U64(ea);
	ctx.r4.u64 = __builtin_bswap64(ctx.reserved.u64);
	// cmpd cr6,r4,r11
	ctx.cr6.compare<int64_t>(ctx.r4.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825f0f10
	if (!ctx.cr6.eq) goto loc_825F0F10;
	// stdcx. r10,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U64(ea, ctx.reserved.s64, __builtin_bswap64(ctx.r10.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r3,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r3.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825f0eec
	if (!ctx.cr0.eq) goto loc_825F0EEC;
	// b 0x825f0f18
	goto loc_825F0F18;
loc_825F0F10:
	// stdcx. r4,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U64(ea, ctx.reserved.s64, __builtin_bswap64(ctx.r4.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r3,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r3.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_825F0F18:
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmpd cr6,r4,r11
	ctx.cr6.compare<int64_t>(ctx.r4.s64, ctx.r11.s64, ctx.xer);
	// bne cr6,0x825f0ecc
	if (!ctx.cr6.eq) goto loc_825F0ECC;
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x825f0ec4
	if (!ctx.cr0.eq) goto loc_825F0EC4;
loc_825F0F2C:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// addi r30,r9,-16
	ctx.r30.s64 = ctx.r9.s64 + -16;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f0f98
	if (ctx.cr6.eq) goto loc_825F0F98;
	// addi r11,r31,24
	ctx.r11.s64 = ctx.r31.s64 + 24;
loc_825F0F40:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r28,r10
	ctx.r9.u64 = ctx.r28.u64 + ctx.r10.u64;
	// stwcx. r9,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825f0f40
	if (!ctx.cr0.eq) goto loc_825F0F40;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bge cr6,0x825f0f98
	if (!ctx.cr6.lt) goto loc_825F0F98;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x825f0f98
	if (!ctx.cr6.gt) goto loc_825F0F98;
	// not r4,r10
	ctx.r4.u64 = ~ctx.r10.u64;
	// cmpw cr6,r4,r7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x825f0f80
	if (!ctx.cr6.gt) goto loc_825F0F80;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
loc_825F0F80:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x82765120
	ctx.lr = 0x825F0F8C;
	sub_82765120(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825f0f98
	if (!ctx.cr6.eq) goto loc_825F0F98;
	// bl 0x826563c8
	ctx.lr = 0x825F0F98;
	sub_826563C8(ctx, base);
loc_825F0F98:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x825f0fec
	if (!ctx.cr6.eq) goto loc_825F0FEC;
loc_825F0FA0:
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825f0fb0
	if (ctx.cr6.eq) goto loc_825F0FB0;
	// bl 0x82656df0
	ctx.lr = 0x825F0FB0;
	sub_82656DF0(ctx, base);
loc_825F0FB0:
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825f0fc0
	if (ctx.cr6.eq) goto loc_825F0FC0;
	// bl 0x82656df0
	ctx.lr = 0x825F0FC0;
	sub_82656DF0(ctx, base);
loc_825F0FC0:
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f0d80
	if (ctx.cr6.eq) goto loc_825F0D80;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl
	ctx.lr = 0x825F0FE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
loc_825F0FEC:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f1004
	if (ctx.cr6.eq) goto loc_825F1004;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_825F1004:
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
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826139E8) {
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
	// bl 0x82613970
	ctx.lr = 0x826139F8;
	sub_82613970(ctx, base);
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,-9596(r10)
	REX_STORE_U32(ctx.r10.u32 + -9596, ctx.r3.u32);
	// beq 0x82613a3c
	if (ctx.cr0.eq) goto loc_82613A3C;
	// lis r10,-32161
	ctx.r10.s64 = -2107703296;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lis r9,-32161
	ctx.r9.s64 = -2107703296;
	// stw r11,392(r3)
	REX_STORE_U32(ctx.r3.u32 + 392, ctx.r11.u32);
	// lis r8,-32161
	ctx.r8.s64 = -2107703296;
	// stw r11,408(r3)
	REX_STORE_U32(ctx.r3.u32 + 408, ctx.r11.u32);
	// addi r10,r10,16752
	ctx.r10.s64 = ctx.r10.s64 + 16752;
	// addi r9,r9,16752
	ctx.r9.s64 = ctx.r9.s64 + 16752;
	// addi r8,r8,16752
	ctx.r8.s64 = ctx.r8.s64 + 16752;
	// stw r10,396(r3)
	REX_STORE_U32(ctx.r3.u32 + 396, ctx.r10.u32);
	// stw r9,400(r3)
	REX_STORE_U32(ctx.r3.u32 + 400, ctx.r9.u32);
	// stw r8,404(r3)
	REX_STORE_U32(ctx.r3.u32 + 404, ctx.r8.u32);
loc_82613A3C:
	// sth r11,432(r3)
	REX_STORE_U16(ctx.r3.u32 + 432, ctx.r11.u16);
	// stw r11,428(r3)
	REX_STORE_U32(ctx.r3.u32 + 428, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82615598) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// li r11,0
	ctx.r11.s64 = 0;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// addi r7,r3,112
	ctx.r7.s64 = ctx.r3.s64 + 112;
	// sth r11,8(r3)
	REX_STORE_U16(ctx.r3.u32 + 8, ctx.r11.u16);
	// sth r11,10(r3)
	REX_STORE_U16(ctx.r3.u32 + 10, ctx.r11.u16);
	// stb r11,14(r3)
	REX_STORE_U8(ctx.r3.u32 + 14, ctx.r11.u8);
	// stb r11,15(r3)
	REX_STORE_U8(ctx.r3.u32 + 15, ctx.r11.u8);
	// stw r10,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r11,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r11,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
loc_826155D0:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r7
	ea = ctx.r7.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r11,0,r7
	ea = ctx.r7.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x826155d0
	if (!ctx.cr0.eq) goto loc_826155D0;
	// lwsync
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r7,-32110
	ctx.r7.s64 = -2104360960;
	// addi r10,r3,36
	ctx.r10.s64 = ctx.r3.s64 + 36;
	// lwz r11,-12400(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12400);
	// lwz r8,-12416(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + -12416);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// stw r9,-12416(r7)
	REX_STORE_U32(ctx.r7.u32 + -12416, ctx.r9.u32);
	// stw r8,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8261A780) {
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
	// lwz r3,24(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// bl 0x8262bf80
	ctx.lr = 0x8261A79C;
	sub_8262BF80(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r31,28
	ctx.r8.s64 = ctx.r31.s64 + 28;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_8261A7B4:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r8
	ea = ctx.r8.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r11,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8261a7b4
	if (!ctx.cr0.eq) goto loc_8261A7B4;
	// lwsync
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r7,-32110
	ctx.r7.s64 = -2104360960;
	// addi r10,r31,12
	ctx.r10.s64 = ctx.r31.s64 + 12;
	// lwz r11,-12336(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12336);
	// lwz r8,-12324(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + -12324);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r9,-12324(r7)
	REX_STORE_U32(ctx.r7.u32 + -12324, ctx.r9.u32);
	// stw r8,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_82621490) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566ac
	ctx.lr = 0x82621498;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,36(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// li r25,0
	ctx.r25.s64 = 0;
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x826214d4
	if (!ctx.cr6.gt) goto loc_826214D4;
	// addi r29,r11,-16
	ctx.r29.s64 = ctx.r11.s64 + -16;
loc_826214BC:
	// lwzu r3,52(r29)
	ea = 52 + ctx.r29.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// bl 0x82630f60
	ctx.lr = 0x826214C4;
	sub_82630F60(ctx, base);
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x826214bc
	if (ctx.cr6.lt) goto loc_826214BC;
loc_826214D4:
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// mr r26,r25
	ctx.r26.u64 = ctx.r25.u64;
	// lwz r31,100(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82621550
	if (!ctx.cr6.gt) goto loc_82621550;
loc_826214E8:
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// addi r27,r31,8
	ctx.r27.s64 = ctx.r31.s64 + 8;
loc_826214F0:
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// slw r28,r11,r29
	ctx.r28.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r29.u8 & 0x3F));
	// and. r11,r10,r28
	ctx.r11.u64 = ctx.r10.u64 & ctx.r28.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82621518
	if (ctx.cr0.eq) goto loc_82621518;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x826270d8
	ctx.lr = 0x8262150C;
	sub_826270D8(ctx, base);
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// andc r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 & ~ctx.r28.u64;
	// sth r11,4(r31)
	REX_STORE_U16(ctx.r31.u32 + 4, ctx.r11.u16);
loc_82621518:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r27,r27,12
	ctx.r27.s64 = ctx.r27.s64 + 12;
	// cmpwi cr6,r29,16
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 16, ctx.xer);
	// blt cr6,0x826214f0
	if (ctx.cr6.lt) goto loc_826214F0;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8262153c
	if (ctx.cr6.eq) goto loc_8262153C;
	// bl 0x826277c0
	ctx.lr = 0x82621538;
	sub_826277C0(ctx, base);
	// stw r25,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r25.u32);
loc_8262153C:
	// lwz r11,48(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r31,r31,200
	ctx.r31.s64 = ctx.r31.s64 + 200;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x826214e8
	if (ctx.cr6.lt) goto loc_826214E8;
loc_82621550:
	// lwz r11,60(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82621584
	if (!ctx.cr6.gt) goto loc_82621584;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
loc_82621564:
	// lwz r11,108(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x82630f60
	ctx.lr = 0x82621570;
	sub_82630F60(ctx, base);
	// lwz r11,60(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82621564
	if (ctx.cr6.lt) goto loc_82621564;
loc_82621584:
	// lwz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x826215b8
	if (!ctx.cr6.gt) goto loc_826215B8;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
loc_82621598:
	// lwz r11,112(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 112);
	// lwzx r3,r11,r31
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// bl 0x826270d8
	ctx.lr = 0x826215A4;
	sub_826270D8(ctx, base);
	// lwz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82621598
	if (ctx.cr6.lt) goto loc_82621598;
loc_826215B8:
	// lwz r3,64(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// bl 0x82615228
	ctx.lr = 0x826215C0;
	sub_82615228(ctx, base);
	// stw r25,64(r30)
	REX_STORE_U32(ctx.r30.u32 + 64, ctx.r25.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x827566fc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8262B730) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566bc
	ctx.lr = 0x8262B738;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r11,-11888
	ctx.r29.s64 = ctx.r11.s64 + -11888;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82615358
	ctx.lr = 0x8262B754;
	sub_82615358(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,-11880(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -11880);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8262B76C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwsync
	// li r10,0
	ctx.r10.s64 = 0;
loc_8262B774:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r10,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8262b774
	if (!ctx.cr0.eq) goto loc_8262B774;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8275670c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8262E980) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756694
	ctx.lr = 0x8262E988;
	__savegprlr_19(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// li r20,136
	ctx.r20.s64 = 136;
	// lwz r10,8(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// mr r19,r4
	ctx.r19.u64 = ctx.r4.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r27,r4,4
	ctx.r27.s64 = ctx.r4.s64 + 4;
	// divw. r11,r11,r20
	ctx.r11.u64 = uint32_t((ctx.r20.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r20.s32 == -1)) ? ctx.r11.s32 / ctx.r20.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8262e9bc
	if (!ctx.cr0.eq) goto loc_8262E9BC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
	// b 0x8262eaa4
	goto loc_8262EAA4;
loc_8262E9BC:
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// li r22,0
	ctx.r22.s64 = 0;
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r31,100(r21)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r21.u32 + 100);
	// mr r23,r22
	ctx.r23.u64 = ctx.r22.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw. r11,r11,r20
	ctx.r11.u64 = uint32_t((ctx.r20.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r20.s32 == -1)) ? ctx.r11.s32 / ctx.r20.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8262eaa4
	if (ctx.cr0.eq) goto loc_8262EAA4;
	// mr r24,r22
	ctx.r24.u64 = ctx.r22.u64;
loc_8262E9E0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8262ea0c
	if (ctx.cr6.eq) goto loc_8262EA0C;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8262E9F4:
	// stw r22,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r22.u32);
	// stw r22,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r22.u32);
	// stwu r22,12(r11)
	ea = 12 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r22.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8262e9f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262E9F4;
	// stw r22,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r22.u32);
	// sth r22,4(r31)
	REX_STORE_U16(ctx.r31.u32 + 4, ctx.r22.u16);
loc_8262EA0C:
	// lwz r11,8(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 8);
	// add r28,r24,r11
	ctx.r28.u64 = ctx.r24.u64 + ctx.r11.u64;
	// lwzx r3,r24,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + ctx.r11.u32);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// bl 0x82627728
	ctx.lr = 0x8262EA20;
	sub_82627728(ctx, base);
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// addi r29,r28,72
	ctx.r29.s64 = ctx.r28.s64 + 72;
loc_8262EA2C:
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,4(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// slw r25,r11,r26
	ctx.r25.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r26.u8 & 0x3F));
	// and. r11,r25,r10
	ctx.r11.u64 = ctx.r25.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8262ea6c
	if (ctx.cr0.eq) goto loc_8262EA6C;
	// lwz r11,112(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 112);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// bl 0x82627040
	ctx.lr = 0x8262EA50;
	sub_82627040(ctx, base);
	// lwz r11,-64(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -64);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// lhz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// or r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 | ctx.r25.u64;
	// sth r11,4(r31)
	REX_STORE_U16(ctx.r31.u32 + 4, ctx.r11.u16);
loc_8262EA6C:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r30,r30,12
	ctx.r30.s64 = ctx.r30.s64 + 12;
	// cmpwi cr6,r26,16
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 16, ctx.xer);
	// blt cr6,0x8262ea2c
	if (ctx.cr6.lt) goto loc_8262EA2C;
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// addi r24,r24,136
	ctx.r24.s64 = ctx.r24.s64 + 136;
	// addi r31,r31,200
	ctx.r31.s64 = ctx.r31.s64 + 200;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r20
	ctx.r11.u64 = uint32_t((ctx.r20.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r20.s32 == -1)) ? ctx.r11.s32 / ctx.r20.s32 : 0);
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8262e9e0
	if (ctx.cr6.lt) goto loc_8262E9E0;
loc_8262EAA4:
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r20
	ctx.r11.u64 = uint32_t((ctx.r20.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r20.s32 == -1)) ? ctx.r11.s32 / ctx.r20.s32 : 0);
	// stw r11,48(r21)
	REX_STORE_U32(ctx.r21.u32 + 48, ctx.r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x827566e4
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826379C0) {
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
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,29068
	ctx.r11.s64 = ctx.r11.s64 + 29068;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x82637a10
	if (ctx.cr6.eq) goto loc_82637A10;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826379f8
	if (ctx.cr6.eq) goto loc_826379F8;
	// bl 0x825fc588
	ctx.lr = 0x826379F8;
	sub_825FC588(ctx, base);
loc_826379F8:
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// bl 0x825fc588
	ctx.lr = 0x82637A10;
	sub_825FC588(ctx, base);
loc_82637A10:
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

DEFINE_REX_FUNC(sub_82638D40) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,12,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0x7;
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82638E10) {
	REX_FUNC_PROLOGUE();
	// stb r4,10498(r3)
	REX_STORE_U8(ctx.r3.u32 + 10498, ctx.r4.u8);
	// ld r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 268435456;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_826391F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stw r4,28(r1)
	REX_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// li r12,1
	ctx.r12.s64 = 1;
	// stfs f0,12068(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 12068, temp.u32);
	// lfs f13,808(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// rldicr r12,r12,54,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 54) & 0xFFFFFFFFFFFFFFFF;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r11,10598(r3)
	REX_STORE_U16(ctx.r3.u32 + 10598, ctx.r11.u16);
	// sth r11,10596(r3)
	REX_STORE_U16(ctx.r3.u32 + 10596, ctx.r11.u16);
	// ld r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8263B038) {
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
	// stwu r1,-1648(r1)
	ea = -1648 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8264b3c8
	ctx.lr = 0x8263B05C;
	sub_8264B3C8(ctx, base);
	// addi r30,r31,15212
	ctx.r30.s64 = ctx.r31.s64 + 15212;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// addi r8,r11,1536
	ctx.r8.s64 = ctx.r11.s64 + 1536;
loc_8263B06C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8263b08c
	if (!ctx.cr0.eq) goto loc_8263B08C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x8263b06c
	if (!ctx.cr6.eq) goto loc_8263B06C;
loc_8263B08C:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8263b0ec
	if (ctx.cr0.eq) goto loc_8263B0EC;
	// bl 0x82872c1c
	ctx.lr = 0x8263B098;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8263b0d0
	if (ctx.cr6.eq) goto loc_8263B0D0;
	// lwz r3,24164(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24164);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8263b0c4
	if (ctx.cr6.eq) goto loc_8263B0C4;
	// lwz r11,24168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24168);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8263b0c4
	if (!ctx.cr0.eq) goto loc_8263B0C4;
	// li r5,1536
	ctx.r5.s64 = 1536;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82656938
	ctx.lr = 0x8263B0C4;
	sub_82656938(ctx, base);
loc_8263B0C4:
	// lwz r11,24168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24168);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,24168(r31)
	REX_STORE_U32(ctx.r31.u32 + 24168, ctx.r11.u32);
loc_8263B0D0:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,1536
	ctx.r5.s64 = 1536;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827567d0
	ctx.lr = 0x8263B0E0;
	sub_827567D0(ctx, base);
	// lwz r11,16916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16916);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stw r11,16916(r31)
	REX_STORE_U32(ctx.r31.u32 + 16916, ctx.r11.u32);
loc_8263B0EC:
	// addi r1,r1,1648
	ctx.r1.s64 = ctx.r1.s64 + 1648;
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

DEFINE_REX_FUNC(sub_826446E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x826446F0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82655438
	ctx.lr = 0x82644704;
	sub_82655438(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82647f88
	ctx.lr = 0x82644710;
	sub_82647F88(ctx, base);
	// li r28,-1
	ctx.r28.s64 = -1;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82644798
	if (!ctx.cr6.eq) goto loc_82644798;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82644734
	if (!ctx.cr6.gt) goto loc_82644734;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82643938
	ctx.lr = 0x82644734;
	sub_82643938(ctx, base);
loc_82644734:
	// li r11,1401
	ctx.r11.s64 = 1401;
	// li r10,1
	ctx.r10.s64 = 1;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// lis r11,-16380
	ctx.r11.s64 = -1073479680;
	// li r9,19
	ctx.r9.s64 = 19;
	// ori r11,r11,15360
	ctx.r11.u64 = ctx.r11.u64 | 15360;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r6,256
	ctx.r6.s64 = 256;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// lwz r11,10900(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10900);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r11,r11,3
	ctx.r11.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
loc_82644798:
	// lwz r11,13804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13804);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826447d4
	if (ctx.cr6.eq) goto loc_826447D4;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x826447d4
	if (ctx.cr6.eq) goto loc_826447D4;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x826447cc
	if (ctx.cr6.eq) goto loc_826447CC;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// li r10,3
	ctx.r10.s64 = 3;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// b 0x826447d8
	goto loc_826447D8;
loc_826447CC:
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x826447d8
	goto loc_826447D8;
loc_826447D4:
	// li r11,1
	ctx.r11.s64 = 1;
loc_826447D8:
	// lwz r10,12028(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12028);
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r4,48(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm r10,r10,9,25,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x7F;
	// lwz r9,56(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// or r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 | ctx.r29.u64;
	// ble cr6,0x82644808
	if (!ctx.cr6.gt) goto loc_82644808;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82643938
	ctx.lr = 0x82644804;
	sub_82643938(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82644808:
	// lis r11,-32156
	ctx.r11.s64 = -2107375616;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// addi r6,r11,17720
	ctx.r6.s64 = ctx.r11.s64 + 17720;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82643b30
	ctx.lr = 0x82644820;
	sub_82643B30(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
	// bne cr6,0x82644890
	if (!ctx.cr6.eq) goto loc_82644890;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82644840
	if (!ctx.cr6.gt) goto loc_82644840;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82643938
	ctx.lr = 0x82644840;
	sub_82643938(ctx, base);
loc_82644840:
	// lis r11,-16380
	ctx.r11.s64 = -1073479680;
	// li r10,19
	ctx.r10.s64 = 19;
	// ori r11,r11,15360
	ctx.r11.u64 = ctx.r11.u64 | 15360;
	// li r9,0
	ctx.r9.s64 = 0;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// li r8,256
	ctx.r8.s64 = 256;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r11,10900(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10900);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r11,r11,3
	ctx.r11.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
loc_82644890:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82655438
	ctx.lr = 0x8264489C;
	sub_82655438(ctx, base);
	// lbz r11,10941(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10941);
	// ori r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 16;
	// stb r11,10941(r31)
	REX_STORE_U8(ctx.r31.u32 + 10941, ctx.r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82655438) {
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
	// lwz r11,21856(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21856);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x826554f8
	if (!ctx.cr6.eq) goto loc_826554F8;
	// lwz r11,21864(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21864);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82655470
	if (!ctx.cr6.eq) goto loc_82655470;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82655474
	goto loc_82655474;
loc_82655470:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82655474:
	// lwz r10,21860(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21860);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x826554f8
	if (ctx.cr6.eq) goto loc_826554F8;
	// rlwinm r30,r11,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x82655490
	if (!ctx.cr6.eq) goto loc_82655490;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_82655490:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x826554a8
	if (!ctx.cr6.gt) goto loc_826554A8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82643938
	ctx.lr = 0x826554A8;
	sub_82643938(ctx, base);
loc_826554A8:
	// lis r11,-16382
	ctx.r11.s64 = -1073610752;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// ori r11,r11,22528
	ctx.r11.u64 = ctx.r11.u64 | 22528;
	// ori r10,r10,3
	ctx.r10.u64 = ctx.r10.u64 | 3;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-8531
	ctx.r9.s64 = -559087616;
	// ori r8,r9,48879
	ctx.r8.u64 = ctx.r9.u64 | 48879;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r10,21852(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21852);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
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
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
loc_826554F8:
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

DEFINE_REX_FUNC(sub_82658BE4) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// li r6,-32
	ctx.r6.s64 = -32;
	// li r7,-48
	ctx.r7.s64 = -48;
	// stvlx128 v64,r1,r6
	ea = ctx.r1.u32 + ctx.r6.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v64.u8[15 - i]);
	// stvlx128 v65,r1,r7
	ea = ctx.r1.u32 + ctx.r7.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v65.u8[15 - i]);
	// li r0,0
	ctx.r0.s64 = 0;
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
	// dcbt r4,r0
	// lvx128 v65,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v65.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// lvsl v0,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// cmplwi cr6,r5,1024
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1024, ctx.xer);
	// blt cr6,0x82659018
	if (ctx.cr6.lt) goto loc_82659018;
	// li r0,128
	ctx.r0.s64 = 128;
	// dcbt r4,r0
	// li r0,256
	ctx.r0.s64 = 256;
	// dcbt r4,r0
	// li r0,384
	ctx.r0.s64 = 384;
	// dcbt r4,r0
	// li r0,512
	ctx.r0.s64 = 512;
	// dcbt r4,r0
	// li r0,640
	ctx.r0.s64 = 640;
	// dcbt r4,r0
	// li r0,768
	ctx.r0.s64 = 768;
	// dcbt r4,r0
	// li r0,896
	ctx.r0.s64 = 896;
	// dcbt r4,r0
loc_82658C6C:
	// addi r0,r5,-1024
	ctx.r0.s64 = ctx.r5.s64 + -1024;
	// cmplwi cr6,r0,1024
	ctx.cr6.compare<uint32_t>(ctx.r0.u32, 1024, ctx.xer);
	// blt cr6,0x82658c7c
	if (ctx.cr6.lt) goto loc_82658C7C;
	// li r0,1024
	ctx.r0.s64 = 1024;
loc_82658C7C:
	// lvx128 v1,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v9,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v14,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v15,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v16,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v17,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v18,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v19,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v20,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v21,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v22,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v23,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v24,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v25,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v26,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v27,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v28,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v29,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v30,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v31,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v33,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v35,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v41,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v49,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// lvx128 v57,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v64,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v64.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbt r4,r0
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// vperm128 v65,v65,v1,v0
	simde_mm_store_si128((simde__m128i*)ctx.v65.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v65.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v1,v1,v2,v0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v2,v2,v3,v0
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v3,v3,v4,v0
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v4,v4,v5,v0
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v5,v5,v6,v0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v6,v6,v7,v0
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v7,v7,v8,v0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvlx128 v65,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v65.u8[15 - i]);
	// stvlx128 v1,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v1.u8[15 - i]);
	// stvlx128 v2,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v2.u8[15 - i]);
	// stvlx128 v3,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v3.u8[15 - i]);
	// stvlx128 v4,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v4.u8[15 - i]);
	// stvlx128 v5,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v5.u8[15 - i]);
	// stvlx128 v6,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v6.u8[15 - i]);
	// stvlx128 v7,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v7.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// vperm128 v8,v8,v9,v0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v9,v9,v10,v0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v10,v10,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v11,v11,v12,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v12,v12,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v13,v13,v14,v0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v14,v14,v15,v0
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v15.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v15,v15,v16,v0
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v15.u8), simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvlx128 v8,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v8.u8[15 - i]);
	// stvlx128 v9,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v9.u8[15 - i]);
	// stvlx128 v10,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v10.u8[15 - i]);
	// stvlx128 v11,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v11.u8[15 - i]);
	// stvlx128 v12,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v12.u8[15 - i]);
	// stvlx128 v13,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v13.u8[15 - i]);
	// stvlx128 v14,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v14.u8[15 - i]);
	// stvlx128 v15,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v15.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// vperm128 v16,v16,v17,v0
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v17,v17,v18,v0
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v18,v18,v19,v0
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v19,v19,v20,v0
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v20,v20,v21,v0
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v21,v21,v22,v0
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v22,v22,v23,v0
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v23,v23,v24,v0
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvlx128 v16,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v16.u8[15 - i]);
	// stvlx128 v17,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v17.u8[15 - i]);
	// stvlx128 v18,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v18.u8[15 - i]);
	// stvlx128 v19,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v19.u8[15 - i]);
	// stvlx128 v20,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v20.u8[15 - i]);
	// stvlx128 v21,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v21.u8[15 - i]);
	// stvlx128 v22,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v22.u8[15 - i]);
	// stvlx128 v23,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v23.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// vperm128 v24,v24,v25,v0
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v25,v25,v26,v0
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v26,v26,v27,v0
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v27,v27,v28,v0
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v28,v28,v29,v0
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v29,v29,v30,v0
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v30,v30,v31,v0
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v31,v31,v32,v0
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v32.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvlx128 v24,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v24.u8[15 - i]);
	// stvlx128 v25,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v25.u8[15 - i]);
	// stvlx128 v26,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v26.u8[15 - i]);
	// stvlx128 v27,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v27.u8[15 - i]);
	// stvlx128 v28,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v28.u8[15 - i]);
	// stvlx128 v29,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v29.u8[15 - i]);
	// stvlx128 v30,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v30.u8[15 - i]);
	// stvlx128 v31,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v31.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// vperm128 v32,v32,v33,v0
	simde_mm_store_si128((simde__m128i*)ctx.v32.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v32.u8), simde_mm_load_si128((simde__m128i*)ctx.v33.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v33,v33,v34,v0
	simde_mm_store_si128((simde__m128i*)ctx.v33.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v33.u8), simde_mm_load_si128((simde__m128i*)ctx.v34.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v34,v34,v35,v0
	simde_mm_store_si128((simde__m128i*)ctx.v34.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v34.u8), simde_mm_load_si128((simde__m128i*)ctx.v35.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v35,v35,v36,v0
	simde_mm_store_si128((simde__m128i*)ctx.v35.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v35.u8), simde_mm_load_si128((simde__m128i*)ctx.v36.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v36,v36,v37,v0
	simde_mm_store_si128((simde__m128i*)ctx.v36.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v36.u8), simde_mm_load_si128((simde__m128i*)ctx.v37.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v37,v37,v38,v0
	simde_mm_store_si128((simde__m128i*)ctx.v37.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v37.u8), simde_mm_load_si128((simde__m128i*)ctx.v38.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v38,v38,v39,v0
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v38.u8), simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v39,v39,v40,v0
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)ctx.v40.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvlx128 v32,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v32.u8[15 - i]);
	// stvlx128 v33,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v33.u8[15 - i]);
	// stvlx128 v34,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v34.u8[15 - i]);
	// stvlx128 v35,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v35.u8[15 - i]);
	// stvlx128 v36,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v36.u8[15 - i]);
	// stvlx128 v37,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v37.u8[15 - i]);
	// stvlx128 v38,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v38.u8[15 - i]);
	// stvlx128 v39,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v39.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// vperm128 v40,v40,v41,v0
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v40.u8), simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v41,v41,v42,v0
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)ctx.v42.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v42,v42,v43,v0
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v42.u8), simde_mm_load_si128((simde__m128i*)ctx.v43.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v43,v43,v44,v0
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v43.u8), simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v44,v44,v45,v0
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v44.u8), simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v45,v45,v46,v0
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v46,v46,v47,v0
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v47,v47,v48,v0
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvlx128 v40,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v40.u8[15 - i]);
	// stvlx128 v41,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v41.u8[15 - i]);
	// stvlx128 v42,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v42.u8[15 - i]);
	// stvlx128 v43,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v43.u8[15 - i]);
	// stvlx128 v44,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v44.u8[15 - i]);
	// stvlx128 v45,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v45.u8[15 - i]);
	// stvlx128 v46,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v46.u8[15 - i]);
	// stvlx128 v47,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v47.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// vperm128 v48,v48,v49,v0
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v49,v49,v50,v0
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v50,v50,v51,v0
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v51,v51,v52,v0
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v52,v52,v53,v0
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v53,v53,v54,v0
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v54,v54,v55,v0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v55,v55,v56,v0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvlx128 v48,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v48.u8[15 - i]);
	// stvlx128 v49,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v49.u8[15 - i]);
	// stvlx128 v50,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v50.u8[15 - i]);
	// stvlx128 v51,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v51.u8[15 - i]);
	// stvlx128 v52,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v52.u8[15 - i]);
	// stvlx128 v53,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v53.u8[15 - i]);
	// stvlx128 v54,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v54.u8[15 - i]);
	// stvlx128 v55,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v55.u8[15 - i]);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// vperm128 v56,v56,v57,v0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v57,v57,v58,v0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v58,v58,v59,v0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v59,v59,v60,v0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v60,v60,v61,v0
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v61,v61,v62,v0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v62,v62,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v63,v63,v64,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v64.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvlx128 v56,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v56.u8[15 - i]);
	// stvlx128 v57,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v57.u8[15 - i]);
	// stvlx128 v58,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v58.u8[15 - i]);
	// stvlx128 v59,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v59.u8[15 - i]);
	// stvlx128 v60,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v60.u8[15 - i]);
	// stvlx128 v61,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v61.u8[15 - i]);
	// stvlx128 v62,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v62.u8[15 - i]);
	// stvlx128 v63,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// vor128 v65,v64,v64
	simde_mm_store_si128((simde__m128i*)ctx.v65.u8, simde_mm_load_si128((simde__m128i*)ctx.v64.u8));
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// addi r5,r5,-1024
	ctx.r5.s64 = ctx.r5.s64 + -1024;
	// cmplwi cr6,r5,1024
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1024, ctx.xer);
	// bge cr6,0x82658c6c
	if (!ctx.cr6.lt) goto loc_82658C6C;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x82659018
	if (!ctx.cr6.eq) goto loc_82659018;
	// b 0x82659094
	goto loc_82659094;
loc_82659018:
	// lvx128 v1,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r12,r4
	ea = (ctx.r12.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// dcbf r0,r4
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// vperm128 v65,v65,v1,v0
	simde_mm_store_si128((simde__m128i*)ctx.v65.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v65.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v1,v1,v2,v0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v2,v2,v3,v0
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v3,v3,v4,v0
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v4,v4,v5,v0
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v5,v5,v6,v0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v6,v6,v7,v0
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v7,v7,v8,v0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvlx128 v65,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v65.u8[15 - i]);
	// stvlx128 v1,r6,r3
	ea = ctx.r6.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v1.u8[15 - i]);
	// stvlx128 v2,r7,r3
	ea = ctx.r7.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v2.u8[15 - i]);
	// stvlx128 v3,r8,r3
	ea = ctx.r8.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v3.u8[15 - i]);
	// stvlx128 v4,r9,r3
	ea = ctx.r9.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v4.u8[15 - i]);
	// stvlx128 v5,r10,r3
	ea = ctx.r10.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v5.u8[15 - i]);
	// stvlx128 v6,r11,r3
	ea = ctx.r11.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v6.u8[15 - i]);
	// stvlx128 v7,r12,r3
	ea = ctx.r12.u32 + ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v7.u8[15 - i]);
	// vor128 v65,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v65.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// addi r5,r5,-128
	ctx.r5.s64 = ctx.r5.s64 + -128;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bgt cr6,0x82659018
	if (ctx.cr6.gt) goto loc_82659018;
loc_82659094:
	// li r6,-32
	ctx.r6.s64 = -32;
	// li r7,-48
	ctx.r7.s64 = -48;
	// lvx128 v64,r1,r6
	ea = (ctx.r1.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v64.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v65,r1,r7
	ea = (ctx.r1.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v65.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_826BA468) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x826BA470;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,32(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r28,r9
	ctx.r28.u64 = ctx.r9.u64;
	// lwz r10,108(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x826ba4a8
	if (!ctx.cr6.gt) goto loc_826BA4A8;
loc_826BA498:
	// lis r3,-32688
	ctx.r3.s64 = -2142240768;
	// ori r3,r3,6
	ctx.r3.u64 = ctx.r3.u64 | 6;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
loc_826BA4A8:
	// lwz r10,36(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x826ba498
	if (!ctx.cr6.eq) goto loc_826BA498;
	// lwz r8,32(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// rlwinm r26,r8,31,1,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// mullw r6,r10,r8
	ctx.r6.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// mullw r9,r10,r26
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r26.s32);
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// li r4,1
	ctx.r4.s64 = 1;
	// add r7,r9,r6
	ctx.r7.u64 = ctx.r9.u64 + ctx.r6.u64;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// bl 0x826c29a8
	ctx.lr = 0x826BA4F4;
	sub_826C29A8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826ba514
	if (ctx.cr6.eq) goto loc_826BA514;
	// cmpwi cr6,r3,9
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 9, ctx.xer);
	// bne cr6,0x826ba524
	if (!ctx.cr6.eq) goto loc_826BA524;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// b 0x826ba524
	goto loc_826BA524;
loc_826BA514:
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
loc_826BA524:
	// ld r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 72);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// std r11,0(r27)
	REX_STORE_U64(ctx.r27.u32 + 0, ctx.r11.u64);
	// beq cr6,0x826ba53c
	if (ctx.cr6.eq) goto loc_826BA53C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_826BA53C:
	// bl 0x826b9f68
	ctx.lr = 0x826BA540;
	sub_826B9F68(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826C9AE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a0
	ctx.lr = 0x826C9AF0;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,84(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// li r23,0
	ctx.r23.s64 = 0;
	// lwz r11,15504(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 15504);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r22,r4
	ctx.r22.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// bne cr6,0x826ca268
	if (!ctx.cr6.eq) goto loc_826CA268;
	// li r30,8
	ctx.r30.s64 = 8;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x826c9b90
	if (!ctx.cr6.lt) goto loc_826C9B90;
loc_826C9B38:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826c9b90
	if (ctx.cr6.eq) goto loc_826C9B90;
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
	// bge 0x826c9b80
	if (!ctx.cr0.lt) goto loc_826C9B80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826C9B80;
	sub_826E4FF0(ctx, base);
loc_826C9B80:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826c9b38
	if (ctx.cr6.gt) goto loc_826C9B38;
loc_826C9B90:
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
	// bge 0x826c9bcc
	if (!ctx.cr0.lt) goto loc_826C9BCC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826C9BCC;
	sub_826E4FF0(ctx, base);
loc_826C9BCC:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x826cb698
	if (!ctx.cr6.eq) goto loc_826CB698;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// li r30,8
	ctx.r30.s64 = 8;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x826c9c48
	if (!ctx.cr6.lt) goto loc_826C9C48;
loc_826C9BF0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826c9c48
	if (ctx.cr6.eq) goto loc_826C9C48;
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
	// bge 0x826c9c38
	if (!ctx.cr0.lt) goto loc_826C9C38;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826C9C38;
	sub_826E4FF0(ctx, base);
loc_826C9C38:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826c9bf0
	if (ctx.cr6.gt) goto loc_826C9BF0;
loc_826C9C48:
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
	// bge 0x826c9c84
	if (!ctx.cr0.lt) goto loc_826C9C84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826C9C84;
	sub_826E4FF0(ctx, base);
loc_826C9C84:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x826cb698
	if (!ctx.cr6.eq) goto loc_826CB698;
loc_826C9C8C:
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// li r30,8
	ctx.r30.s64 = 8;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x826c9d00
	if (!ctx.cr6.lt) goto loc_826C9D00;
loc_826C9CA8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826c9d00
	if (ctx.cr6.eq) goto loc_826C9D00;
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
	// bge 0x826c9cf0
	if (!ctx.cr0.lt) goto loc_826C9CF0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826C9CF0;
	sub_826E4FF0(ctx, base);
loc_826C9CF0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826c9ca8
	if (ctx.cr6.gt) goto loc_826C9CA8;
loc_826C9D00:
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
	// bge 0x826c9d3c
	if (!ctx.cr0.lt) goto loc_826C9D3C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826C9D3C;
	sub_826E4FF0(ctx, base);
loc_826C9D3C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x826c9c8c
	if (ctx.cr6.eq) goto loc_826C9C8C;
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// bne cr6,0x826cb698
	if (!ctx.cr6.eq) goto loc_826CB698;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// li r30,8
	ctx.r30.s64 = 8;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x826c9dc0
	if (!ctx.cr6.lt) goto loc_826C9DC0;
loc_826C9D68:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826c9dc0
	if (ctx.cr6.eq) goto loc_826C9DC0;
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
	// bge 0x826c9db0
	if (!ctx.cr0.lt) goto loc_826C9DB0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826C9DB0;
	sub_826E4FF0(ctx, base);
loc_826C9DB0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826c9d68
	if (ctx.cr6.gt) goto loc_826C9D68;
loc_826C9DC0:
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
	// bge 0x826c9dfc
	if (!ctx.cr0.lt) goto loc_826C9DFC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826C9DFC;
	sub_826E4FF0(ctx, base);
loc_826C9DFC:
	// cmpwi cr6,r30,15
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 15, ctx.xer);
	// bne cr6,0x826cb698
	if (!ctx.cr6.eq) goto loc_826CB698;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x826c7d08
	ctx.lr = 0x826C9E20;
	sub_826C7D08(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826cb69c
	if (!ctx.cr6.eq) goto loc_826CB69C;
	// lwz r10,22284(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 22284);
	// li r27,1
	ctx.r27.s64 = 1;
	// lwz r11,22280(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 22280);
	// lwz r9,22104(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 22104);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x826c9e5c
	if (ctx.cr6.gt) goto loc_826C9E5C;
	// lwz r9,22120(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 22120);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x826c9e5c
	if (ctx.cr6.gt) goto loc_826C9E5C;
	// lwz r11,22124(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 22124);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x826c9ed4
	if (!ctx.cr6.gt) goto loc_826C9ED4;
loc_826C9E5C:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x826bab68
	ctx.lr = 0x826C9E64;
	sub_826BAB68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826c9e78
	if (!ctx.cr6.eq) goto loc_826C9E78;
	// li r3,14
	ctx.r3.s64 = 14;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
loc_826C9E78:
	// lwz r11,22284(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 22284);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r10,22280(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 22280);
	// stw r27,3700(r24)
	REX_STORE_U32(ctx.r24.u32 + 3700, ctx.r27.u32);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r9,22104(r24)
	REX_STORE_U32(ctx.r24.u32 + 22104, ctx.r9.u32);
	// stw r10,22120(r24)
	REX_STORE_U32(ctx.r24.u32 + 22120, ctx.r10.u32);
	// stw r11,22124(r24)
	REX_STORE_U32(ctx.r24.u32 + 22124, ctx.r11.u32);
	// bl 0x826dc7e8
	ctx.lr = 0x826C9E9C;
	sub_826DC7E8(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r5,22284(r24)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r24.u32 + 22284);
	// lwz r4,22280(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 22280);
	// bl 0x826dd870
	ctx.lr = 0x826C9EAC;
	sub_826DD870(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826cb69c
	if (!ctx.cr6.eq) goto loc_826CB69C;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r5,22284(r24)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r24.u32 + 22284);
	// lwz r4,22280(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 22280);
	// bl 0x826de1f0
	ctx.lr = 0x826C9EC4;
	sub_826DE1F0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826cb69c
	if (!ctx.cr6.eq) goto loc_826CB69C;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x826d9310
	ctx.lr = 0x826C9ED4;
	sub_826D9310(ctx, base);
loc_826C9ED4:
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826c9f60
	if (ctx.cr6.eq) goto loc_826C9F60;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826c9f38
	if (!ctx.cr6.lt) goto loc_826C9F38;
loc_826C9EF8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826c9f38
	if (ctx.cr6.eq) goto loc_826C9F38;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// sld r6,r9,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// std r6,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r6.u64);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge 0x826c9f28
	if (!ctx.cr0.lt) goto loc_826C9F28;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826C9F28;
	sub_826E4FF0(ctx, base);
loc_826C9F28:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826c9ef8
	if (ctx.cr6.gt) goto loc_826C9EF8;
loc_826C9F38:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r10,r30,32
	ctx.r10.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// sld r8,r11,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r10.u8 & 0x7F));
	// subf. r7,r30,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge 0x826c9f60
	if (!ctx.cr0.lt) goto loc_826C9F60;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826C9F60;
	sub_826E4FF0(ctx, base);
loc_826C9F60:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// clrlwi r4,r11,29
	ctx.r4.u64 = ctx.r11.u32 & 0x7;
	// bl 0x826e50c0
	ctx.lr = 0x826C9F70;
	sub_826E50C0(ctx, base);
	// li r30,8
	ctx.r30.s64 = 8;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x826c9fe4
	if (!ctx.cr6.lt) goto loc_826C9FE4;
loc_826C9F8C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826c9fe4
	if (ctx.cr6.eq) goto loc_826C9FE4;
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
	// bge 0x826c9fd4
	if (!ctx.cr0.lt) goto loc_826C9FD4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826C9FD4;
	sub_826E4FF0(ctx, base);
loc_826C9FD4:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826c9f8c
	if (ctx.cr6.gt) goto loc_826C9F8C;
loc_826C9FE4:
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
	// bge 0x826ca020
	if (!ctx.cr0.lt) goto loc_826CA020;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA020;
	sub_826E4FF0(ctx, base);
loc_826CA020:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x826cb698
	if (!ctx.cr6.eq) goto loc_826CB698;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// li r30,8
	ctx.r30.s64 = 8;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x826ca09c
	if (!ctx.cr6.lt) goto loc_826CA09C;
loc_826CA044:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca09c
	if (ctx.cr6.eq) goto loc_826CA09C;
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
	// bge 0x826ca08c
	if (!ctx.cr0.lt) goto loc_826CA08C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA08C;
	sub_826E4FF0(ctx, base);
loc_826CA08C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca044
	if (ctx.cr6.gt) goto loc_826CA044;
loc_826CA09C:
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
	// bge 0x826ca0d8
	if (!ctx.cr0.lt) goto loc_826CA0D8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA0D8;
	sub_826E4FF0(ctx, base);
loc_826CA0D8:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x826cb698
	if (!ctx.cr6.eq) goto loc_826CB698;
loc_826CA0E0:
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// li r30,8
	ctx.r30.s64 = 8;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x826ca154
	if (!ctx.cr6.lt) goto loc_826CA154;
loc_826CA0FC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca154
	if (ctx.cr6.eq) goto loc_826CA154;
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
	// bge 0x826ca144
	if (!ctx.cr0.lt) goto loc_826CA144;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA144;
	sub_826E4FF0(ctx, base);
loc_826CA144:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca0fc
	if (ctx.cr6.gt) goto loc_826CA0FC;
loc_826CA154:
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
	// bge 0x826ca190
	if (!ctx.cr0.lt) goto loc_826CA190;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA190;
	sub_826E4FF0(ctx, base);
loc_826CA190:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x826ca0e0
	if (ctx.cr6.eq) goto loc_826CA0E0;
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// bne cr6,0x826cb698
	if (!ctx.cr6.eq) goto loc_826CB698;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// li r30,8
	ctx.r30.s64 = 8;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x826ca214
	if (!ctx.cr6.lt) goto loc_826CA214;
loc_826CA1BC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca214
	if (ctx.cr6.eq) goto loc_826CA214;
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
	// bge 0x826ca204
	if (!ctx.cr0.lt) goto loc_826CA204;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA204;
	sub_826E4FF0(ctx, base);
loc_826CA204:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca1bc
	if (ctx.cr6.gt) goto loc_826CA1BC;
loc_826CA214:
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
	// bge 0x826ca250
	if (!ctx.cr0.lt) goto loc_826CA250;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA250;
	sub_826E4FF0(ctx, base);
loc_826CA250:
	// cmpwi cr6,r30,14
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 14, ctx.xer);
	// bne cr6,0x826cb698
	if (!ctx.cr6.eq) goto loc_826CB698;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x826c1800
	ctx.lr = 0x826CA260;
	sub_826C1800(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
loc_826CA268:
	// li r30,2
	ctx.r30.s64 = 2;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x826ca2cc
	if (!ctx.cr6.lt) goto loc_826CA2CC;
loc_826CA274:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca2cc
	if (ctx.cr6.eq) goto loc_826CA2CC;
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
	// bge 0x826ca2bc
	if (!ctx.cr0.lt) goto loc_826CA2BC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA2BC;
	sub_826E4FF0(ctx, base);
loc_826CA2BC:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca274
	if (ctx.cr6.gt) goto loc_826CA274;
loc_826CA2CC:
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
	// bge 0x826ca308
	if (!ctx.cr0.lt) goto loc_826CA308;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA308;
	sub_826E4FF0(ctx, base);
loc_826CA308:
	// li r27,1
	ctx.r27.s64 = 1;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x826ca31c
	if (!ctx.cr6.eq) goto loc_826CA31C;
	// stw r23,3932(r24)
	REX_STORE_U32(ctx.r24.u32 + 3932, ctx.r23.u32);
	// b 0x826ca33c
	goto loc_826CA33C;
loc_826CA31C:
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// bne cr6,0x826ca32c
	if (!ctx.cr6.eq) goto loc_826CA32C;
	// stw r27,3932(r24)
	REX_STORE_U32(ctx.r24.u32 + 3932, ctx.r27.u32);
	// b 0x826ca33c
	goto loc_826CA33C;
loc_826CA32C:
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// bne cr6,0x826ca33c
	if (!ctx.cr6.eq) goto loc_826CA33C;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,3932(r24)
	REX_STORE_U32(ctx.r24.u32 + 3932, ctx.r11.u32);
loc_826CA33C:
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826ca3b0
	if (!ctx.cr6.lt) goto loc_826CA3B0;
loc_826CA358:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca3b0
	if (ctx.cr6.eq) goto loc_826CA3B0;
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
	// bge 0x826ca3a0
	if (!ctx.cr0.lt) goto loc_826CA3A0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA3A0;
	sub_826E4FF0(ctx, base);
loc_826CA3A0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca358
	if (ctx.cr6.gt) goto loc_826CA358;
loc_826CA3B0:
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
	// bge 0x826ca3ec
	if (!ctx.cr0.lt) goto loc_826CA3EC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA3EC;
	sub_826E4FF0(ctx, base);
loc_826CA3EC:
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// stw r28,3948(r24)
	REX_STORE_U32(ctx.r24.u32 + 3948, ctx.r28.u32);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826ca464
	if (!ctx.cr6.lt) goto loc_826CA464;
loc_826CA40C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca464
	if (ctx.cr6.eq) goto loc_826CA464;
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
	// bge 0x826ca454
	if (!ctx.cr0.lt) goto loc_826CA454;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA454;
	sub_826E4FF0(ctx, base);
loc_826CA454:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca40c
	if (ctx.cr6.gt) goto loc_826CA40C;
loc_826CA464:
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
	// bge 0x826ca4a0
	if (!ctx.cr0.lt) goto loc_826CA4A0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA4A0;
	sub_826E4FF0(ctx, base);
loc_826CA4A0:
	// lwz r11,3948(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3948);
	// lwz r10,3960(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 3960);
	// stw r30,15332(r24)
	REX_STORE_U32(ctx.r24.u32 + 15332, ctx.r30.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x826cb698
	if (!ctx.cr6.eq) goto loc_826CB698;
	// lwz r11,3964(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3964);
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x826cb698
	if (!ctx.cr6.eq) goto loc_826CB698;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// li r30,3
	ctx.r30.s64 = 3;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x826ca534
	if (!ctx.cr6.lt) goto loc_826CA534;
loc_826CA4DC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca534
	if (ctx.cr6.eq) goto loc_826CA534;
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
	// bge 0x826ca524
	if (!ctx.cr0.lt) goto loc_826CA524;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA524;
	sub_826E4FF0(ctx, base);
loc_826CA524:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca4dc
	if (ctx.cr6.gt) goto loc_826CA4DC;
loc_826CA534:
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
	// bge 0x826ca570
	if (!ctx.cr0.lt) goto loc_826CA570;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA570;
	sub_826E4FF0(ctx, base);
loc_826CA570:
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// li r30,5
	ctx.r30.s64 = 5;
	// stw r28,3680(r24)
	REX_STORE_U32(ctx.r24.u32 + 3680, ctx.r28.u32);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x826ca5e8
	if (!ctx.cr6.lt) goto loc_826CA5E8;
loc_826CA590:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca5e8
	if (ctx.cr6.eq) goto loc_826CA5E8;
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
	// bge 0x826ca5d8
	if (!ctx.cr0.lt) goto loc_826CA5D8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA5D8;
	sub_826E4FF0(ctx, base);
loc_826CA5D8:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca590
	if (ctx.cr6.gt) goto loc_826CA590;
loc_826CA5E8:
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
	// bge 0x826ca624
	if (!ctx.cr0.lt) goto loc_826CA624;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA624;
	sub_826E4FF0(ctx, base);
loc_826CA624:
	// lwz r11,3680(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3680);
	// rlwinm r10,r30,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r27,3924(r24)
	REX_STORE_U32(ctx.r24.u32 + 3924, ctx.r27.u32);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// stw r10,3684(r24)
	REX_STORE_U32(ctx.r24.u32 + 3684, ctx.r10.u32);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// stw r9,3680(r24)
	REX_STORE_U32(ctx.r24.u32 + 3680, ctx.r9.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826ca6b8
	if (!ctx.cr6.lt) goto loc_826CA6B8;
loc_826CA660:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca6b8
	if (ctx.cr6.eq) goto loc_826CA6B8;
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
	// bge 0x826ca6a8
	if (!ctx.cr0.lt) goto loc_826CA6A8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA6A8;
	sub_826E4FF0(ctx, base);
loc_826CA6A8:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca660
	if (ctx.cr6.gt) goto loc_826CA660;
loc_826CA6B8:
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
	// bge 0x826ca6f4
	if (!ctx.cr0.lt) goto loc_826CA6F4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA6F4;
	sub_826E4FF0(ctx, base);
loc_826CA6F4:
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// stw r28,3916(r24)
	REX_STORE_U32(ctx.r24.u32 + 3916, ctx.r28.u32);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826ca76c
	if (!ctx.cr6.lt) goto loc_826CA76C;
loc_826CA714:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca76c
	if (ctx.cr6.eq) goto loc_826CA76C;
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
	// bge 0x826ca75c
	if (!ctx.cr0.lt) goto loc_826CA75C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA75C;
	sub_826E4FF0(ctx, base);
loc_826CA75C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca714
	if (ctx.cr6.gt) goto loc_826CA714;
loc_826CA76C:
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
	// bge 0x826ca7a8
	if (!ctx.cr0.lt) goto loc_826CA7A8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA7A8;
	sub_826E4FF0(ctx, base);
loc_826CA7A8:
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// stw r28,3908(r24)
	REX_STORE_U32(ctx.r24.u32 + 3908, ctx.r28.u32);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826ca820
	if (!ctx.cr6.lt) goto loc_826CA820;
loc_826CA7C8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca820
	if (ctx.cr6.eq) goto loc_826CA820;
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
	// bge 0x826ca810
	if (!ctx.cr0.lt) goto loc_826CA810;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA810;
	sub_826E4FF0(ctx, base);
loc_826CA810:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca7c8
	if (ctx.cr6.gt) goto loc_826CA7C8;
loc_826CA820:
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
	// bge 0x826ca85c
	if (!ctx.cr0.lt) goto loc_826CA85C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA85C;
	sub_826E4FF0(ctx, base);
loc_826CA85C:
	// stw r28,14852(r24)
	REX_STORE_U32(ctx.r24.u32 + 14852, ctx.r28.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826ca8d4
	if (!ctx.cr6.lt) goto loc_826CA8D4;
loc_826CA87C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca8d4
	if (ctx.cr6.eq) goto loc_826CA8D4;
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
	// bge 0x826ca8c4
	if (!ctx.cr0.lt) goto loc_826CA8C4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA8C4;
	sub_826E4FF0(ctx, base);
loc_826CA8C4:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca87c
	if (ctx.cr6.gt) goto loc_826CA87C;
loc_826CA8D4:
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
	// bge 0x826ca910
	if (!ctx.cr0.lt) goto loc_826CA910;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA910;
	sub_826E4FF0(ctx, base);
loc_826CA910:
	// stw r28,1788(r24)
	REX_STORE_U32(ctx.r24.u32 + 1788, ctx.r28.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826ca988
	if (!ctx.cr6.lt) goto loc_826CA988;
loc_826CA930:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826ca988
	if (ctx.cr6.eq) goto loc_826CA988;
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
	// bge 0x826ca978
	if (!ctx.cr0.lt) goto loc_826CA978;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA978;
	sub_826E4FF0(ctx, base);
loc_826CA978:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca930
	if (ctx.cr6.gt) goto loc_826CA930;
loc_826CA988:
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
	// bge 0x826ca9c4
	if (!ctx.cr0.lt) goto loc_826CA9C4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CA9C4;
	sub_826E4FF0(ctx, base);
loc_826CA9C4:
	// stw r28,1792(r24)
	REX_STORE_U32(ctx.r24.u32 + 1792, ctx.r28.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826caa3c
	if (!ctx.cr6.lt) goto loc_826CAA3C;
loc_826CA9E4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826caa3c
	if (ctx.cr6.eq) goto loc_826CAA3C;
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
	// bge 0x826caa2c
	if (!ctx.cr0.lt) goto loc_826CAA2C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAA2C;
	sub_826E4FF0(ctx, base);
loc_826CAA2C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826ca9e4
	if (ctx.cr6.gt) goto loc_826CA9E4;
loc_826CAA3C:
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
	// bge 0x826caa78
	if (!ctx.cr0.lt) goto loc_826CAA78;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAA78;
	sub_826E4FF0(ctx, base);
loc_826CAA78:
	// stw r28,21792(r24)
	REX_STORE_U32(ctx.r24.u32 + 21792, ctx.r28.u32);
	// li r30,2
	ctx.r30.s64 = 2;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x826caaf0
	if (!ctx.cr6.lt) goto loc_826CAAF0;
loc_826CAA98:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826caaf0
	if (ctx.cr6.eq) goto loc_826CAAF0;
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
	// bge 0x826caae0
	if (!ctx.cr0.lt) goto loc_826CAAE0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAAE0;
	sub_826E4FF0(ctx, base);
loc_826CAAE0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826caa98
	if (ctx.cr6.gt) goto loc_826CAA98;
loc_826CAAF0:
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
	// bge 0x826cab2c
	if (!ctx.cr0.lt) goto loc_826CAB2C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAB2C;
	sub_826E4FF0(ctx, base);
loc_826CAB2C:
	// stw r28,4008(r24)
	REX_STORE_U32(ctx.r24.u32 + 4008, ctx.r28.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826caba4
	if (!ctx.cr6.lt) goto loc_826CABA4;
loc_826CAB4C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826caba4
	if (ctx.cr6.eq) goto loc_826CABA4;
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
	// bge 0x826cab94
	if (!ctx.cr0.lt) goto loc_826CAB94;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAB94;
	sub_826E4FF0(ctx, base);
loc_826CAB94:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826cab4c
	if (ctx.cr6.gt) goto loc_826CAB4C;
loc_826CABA4:
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
	// bge 0x826cabe0
	if (!ctx.cr0.lt) goto loc_826CABE0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CABE0;
	sub_826E4FF0(ctx, base);
loc_826CABE0:
	// stw r28,436(r24)
	REX_STORE_U32(ctx.r24.u32 + 436, ctx.r28.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826cac58
	if (!ctx.cr6.lt) goto loc_826CAC58;
loc_826CAC00:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826cac58
	if (ctx.cr6.eq) goto loc_826CAC58;
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
	// bge 0x826cac48
	if (!ctx.cr0.lt) goto loc_826CAC48;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAC48;
	sub_826E4FF0(ctx, base);
loc_826CAC48:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826cac00
	if (ctx.cr6.gt) goto loc_826CAC00;
loc_826CAC58:
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
	// bge 0x826cac94
	if (!ctx.cr0.lt) goto loc_826CAC94;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAC94;
	sub_826E4FF0(ctx, base);
loc_826CAC94:
	// stw r28,396(r24)
	REX_STORE_U32(ctx.r24.u32 + 396, ctx.r28.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826cad0c
	if (!ctx.cr6.lt) goto loc_826CAD0C;
loc_826CACB4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826cad0c
	if (ctx.cr6.eq) goto loc_826CAD0C;
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
	// bge 0x826cacfc
	if (!ctx.cr0.lt) goto loc_826CACFC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CACFC;
	sub_826E4FF0(ctx, base);
loc_826CACFC:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826cacb4
	if (ctx.cr6.gt) goto loc_826CACB4;
loc_826CAD0C:
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
	// bge 0x826cad48
	if (!ctx.cr0.lt) goto loc_826CAD48;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAD48;
	sub_826E4FF0(ctx, base);
loc_826CAD48:
	// stw r29,2996(r24)
	REX_STORE_U32(ctx.r24.u32 + 2996, ctx.r29.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826cadc0
	if (!ctx.cr6.lt) goto loc_826CADC0;
loc_826CAD68:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826cadc0
	if (ctx.cr6.eq) goto loc_826CADC0;
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
	// bge 0x826cadb0
	if (!ctx.cr0.lt) goto loc_826CADB0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CADB0;
	sub_826E4FF0(ctx, base);
loc_826CADB0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826cad68
	if (ctx.cr6.gt) goto loc_826CAD68;
loc_826CADC0:
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
	// bge 0x826cadfc
	if (!ctx.cr0.lt) goto loc_826CADFC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CADFC;
	sub_826E4FF0(ctx, base);
loc_826CADFC:
	// stw r28,3956(r24)
	REX_STORE_U32(ctx.r24.u32 + 3956, ctx.r28.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826cae74
	if (!ctx.cr6.lt) goto loc_826CAE74;
loc_826CAE1C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826cae74
	if (ctx.cr6.eq) goto loc_826CAE74;
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
	// bge 0x826cae64
	if (!ctx.cr0.lt) goto loc_826CAE64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAE64;
	sub_826E4FF0(ctx, base);
loc_826CAE64:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826cae1c
	if (ctx.cr6.gt) goto loc_826CAE1C;
loc_826CAE74:
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
	// bge 0x826caeb0
	if (!ctx.cr0.lt) goto loc_826CAEB0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAEB0;
	sub_826E4FF0(ctx, base);
loc_826CAEB0:
	// stw r28,14824(r24)
	REX_STORE_U32(ctx.r24.u32 + 14824, ctx.r28.u32);
	// li r30,3
	ctx.r30.s64 = 3;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x826caf28
	if (!ctx.cr6.lt) goto loc_826CAF28;
loc_826CAED0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826caf28
	if (ctx.cr6.eq) goto loc_826CAF28;
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
	// bge 0x826caf18
	if (!ctx.cr0.lt) goto loc_826CAF18;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAF18;
	sub_826E4FF0(ctx, base);
loc_826CAF18:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826caed0
	if (ctx.cr6.gt) goto loc_826CAED0;
loc_826CAF28:
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
	// bge 0x826caf64
	if (!ctx.cr0.lt) goto loc_826CAF64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAF64;
	sub_826E4FF0(ctx, base);
loc_826CAF64:
	// stw r28,14804(r24)
	REX_STORE_U32(ctx.r24.u32 + 14804, ctx.r28.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826cafdc
	if (!ctx.cr6.lt) goto loc_826CAFDC;
loc_826CAF84:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826cafdc
	if (ctx.cr6.eq) goto loc_826CAFDC;
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
	// bge 0x826cafcc
	if (!ctx.cr0.lt) goto loc_826CAFCC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CAFCC;
	sub_826E4FF0(ctx, base);
loc_826CAFCC:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826caf84
	if (ctx.cr6.gt) goto loc_826CAF84;
loc_826CAFDC:
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
	// bge 0x826cb018
	if (!ctx.cr0.lt) goto loc_826CB018;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB018;
	sub_826E4FF0(ctx, base);
loc_826CB018:
	// stw r30,3460(r24)
	REX_STORE_U32(ctx.r24.u32 + 3460, ctx.r30.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// beq cr6,0x826cb0e4
	if (ctx.cr6.eq) goto loc_826CB0E4;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826cb098
	if (!ctx.cr6.lt) goto loc_826CB098;
loc_826CB040:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826cb098
	if (ctx.cr6.eq) goto loc_826CB098;
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
	// bge 0x826cb088
	if (!ctx.cr0.lt) goto loc_826CB088;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB088;
	sub_826E4FF0(ctx, base);
loc_826CB088:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826cb040
	if (ctx.cr6.gt) goto loc_826CB040;
loc_826CB098:
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
	// bge 0x826cb0d4
	if (!ctx.cr0.lt) goto loc_826CB0D4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB0D4;
	sub_826E4FF0(ctx, base);
loc_826CB0D4:
	// addi r11,r30,2
	ctx.r11.s64 = ctx.r30.s64 + 2;
	// stw r30,3452(r24)
	REX_STORE_U32(ctx.r24.u32 + 3452, ctx.r30.u32);
	// stw r11,22452(r24)
	REX_STORE_U32(ctx.r24.u32 + 22452, ctx.r11.u32);
	// b 0x826cb188
	goto loc_826CB188;
loc_826CB0E4:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826cb144
	if (!ctx.cr6.lt) goto loc_826CB144;
loc_826CB0EC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826cb144
	if (ctx.cr6.eq) goto loc_826CB144;
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
	// bge 0x826cb134
	if (!ctx.cr0.lt) goto loc_826CB134;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB134;
	sub_826E4FF0(ctx, base);
loc_826CB134:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826cb0ec
	if (ctx.cr6.gt) goto loc_826CB0EC;
loc_826CB144:
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
	// bge 0x826cb180
	if (!ctx.cr0.lt) goto loc_826CB180;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB180;
	sub_826E4FF0(ctx, base);
loc_826CB180:
	// stw r30,3464(r24)
	REX_STORE_U32(ctx.r24.u32 + 3464, ctx.r30.u32);
	// stw r30,22452(r24)
	REX_STORE_U32(ctx.r24.u32 + 22452, ctx.r30.u32);
loc_826CB188:
	// lwz r11,3460(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3460);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb1a4
	if (!ctx.cr6.eq) goto loc_826CB1A4;
	// lwz r11,3464(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3464);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// beq cr6,0x826cb1a8
	if (ctx.cr6.eq) goto loc_826CB1A8;
loc_826CB1A4:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_826CB1A8:
	// stw r11,3456(r24)
	REX_STORE_U32(ctx.r24.u32 + 3456, ctx.r11.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826cb220
	if (!ctx.cr6.lt) goto loc_826CB220;
loc_826CB1C8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826cb220
	if (ctx.cr6.eq) goto loc_826CB220;
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
	// bge 0x826cb210
	if (!ctx.cr0.lt) goto loc_826CB210;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB210;
	sub_826E4FF0(ctx, base);
loc_826CB210:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826cb1c8
	if (ctx.cr6.gt) goto loc_826CB1C8;
loc_826CB220:
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
	// bge 0x826cb25c
	if (!ctx.cr0.lt) goto loc_826CB25C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB25C;
	sub_826E4FF0(ctx, base);
loc_826CB25C:
	// lwz r11,15332(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 15332);
	// stw r30,3468(r24)
	REX_STORE_U32(ctx.r24.u32 + 3468, ctx.r30.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb328
	if (!ctx.cr6.eq) goto loc_826CB328;
	// lwz r11,3932(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3932);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb2fc
	if (!ctx.cr6.eq) goto loc_826CB2FC;
	// lwz r11,3908(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3908);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb31c
	if (!ctx.cr6.eq) goto loc_826CB31C;
	// lwz r11,1788(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 1788);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826cb31c
	if (!ctx.cr6.eq) goto loc_826CB31C;
	// lwz r11,1792(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 1792);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826cb31c
	if (!ctx.cr6.eq) goto loc_826CB31C;
	// lwz r11,3956(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3956);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb31c
	if (!ctx.cr6.eq) goto loc_826CB31C;
	// lwz r11,21792(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 21792);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb31c
	if (!ctx.cr6.eq) goto loc_826CB31C;
	// lwz r11,3916(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb31c
	if (!ctx.cr6.eq) goto loc_826CB31C;
	// lwz r11,3948(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3948);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb31c
	if (!ctx.cr6.eq) goto loc_826CB31C;
	// lwz r11,14852(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 14852);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb31c
	if (!ctx.cr6.eq) goto loc_826CB31C;
	// lwz r11,4008(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4008);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb31c
	if (!ctx.cr6.eq) goto loc_826CB31C;
	// lwz r11,14804(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 14804);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb31c
	if (!ctx.cr6.eq) goto loc_826CB31C;
	// lwz r11,14824(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 14824);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// b 0x826cb318
	goto loc_826CB318;
loc_826CB2FC:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826cb328
	if (!ctx.cr6.eq) goto loc_826CB328;
	// lwz r11,3908(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3908);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb31c
	if (!ctx.cr6.eq) goto loc_826CB31C;
	// lwz r11,1788(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 1788);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
loc_826CB318:
	// beq cr6,0x826cb328
	if (ctx.cr6.eq) goto loc_826CB328;
loc_826CB31C:
	// li r3,6
	ctx.r3.s64 = 6;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
loc_826CB328:
	// lwz r11,14804(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 14804);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r9,3948(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 3948);
	// addi r8,r10,8976
	ctx.r8.s64 = ctx.r10.s64 + 8976;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwzx r6,r7,r8
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// stw r6,14808(r24)
	REX_STORE_U32(ctx.r24.u32 + 14808, ctx.r6.u32);
	// beq cr6,0x826cb354
	if (ctx.cr6.eq) goto loc_826CB354;
	// stw r23,3972(r24)
	REX_STORE_U32(ctx.r24.u32 + 3972, ctx.r23.u32);
	// stw r23,3908(r24)
	REX_STORE_U32(ctx.r24.u32 + 3908, ctx.r23.u32);
loc_826CB354:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x826dabd8
	ctx.lr = 0x826CB360;
	sub_826DABD8(ctx, base);
	// lwz r11,1788(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 1788);
	// stw r23,444(r24)
	REX_STORE_U32(ctx.r24.u32 + 444, ctx.r23.u32);
	// stw r23,3912(r24)
	REX_STORE_U32(ctx.r24.u32 + 3912, ctx.r23.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826cb3a8
	if (ctx.cr6.eq) goto loc_826CB3A8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x826dac40
	ctx.lr = 0x826CB380;
	sub_826DAC40(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x826dad70
	ctx.lr = 0x826CB388;
	sub_826DAD70(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x826daed8
	ctx.lr = 0x826CB390;
	sub_826DAED8(ctx, base);
	// lwz r9,1988(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 1988);
	// lwz r8,3204(r24)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r24.u32 + 3204);
	// lis r11,-32142
	ctx.r11.s64 = -2106458112;
	// addi r10,r11,19680
	ctx.r10.s64 = ctx.r11.s64 + 19680;
	// stw r8,52(r9)
	REX_STORE_U32(ctx.r9.u32 + 52, ctx.r8.u32);
	// stw r10,3180(r24)
	REX_STORE_U32(ctx.r24.u32 + 3180, ctx.r10.u32);
loc_826CB3A8:
	// lwz r11,15332(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 15332);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826cb478
	if (ctx.cr6.eq) goto loc_826CB478;
	// lwz r11,3908(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3908);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,396(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,3948(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3948);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,3916(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,21792(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 21792);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,14852(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 14852);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,1792(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 1792);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,4008(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4008);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,436(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 436);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,3956(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3956);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,14824(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 14824);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,3460(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3460);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,3452(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3452);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// lwz r11,3464(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 3464);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826cb46c
	if (!ctx.cr6.eq) goto loc_826CB46C;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x826c78b0
	ctx.lr = 0x826CB464;
	sub_826C78B0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
loc_826CB46C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
loc_826CB478:
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// stw r27,3388(r24)
	REX_STORE_U32(ctx.r24.u32 + 3388, ctx.r27.u32);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826cb4f0
	if (!ctx.cr6.lt) goto loc_826CB4F0;
loc_826CB498:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826cb4f0
	if (ctx.cr6.eq) goto loc_826CB4F0;
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
	// bge 0x826cb4e0
	if (!ctx.cr0.lt) goto loc_826CB4E0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB4E0;
	sub_826E4FF0(ctx, base);
loc_826CB4E0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826cb498
	if (ctx.cr6.gt) goto loc_826CB498;
loc_826CB4F0:
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
	// bge 0x826cb52c
	if (!ctx.cr0.lt) goto loc_826CB52C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB52C;
	sub_826E4FF0(ctx, base);
loc_826CB52C:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// bne cr6,0x826cb550
	if (!ctx.cr6.eq) goto loc_826CB550;
	// lwz r11,84(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x826cb550
	if (!ctx.cr6.eq) goto loc_826CB550;
	// stw r27,3396(r24)
	REX_STORE_U32(ctx.r24.u32 + 3396, ctx.r27.u32);
	// stw r23,3392(r24)
	REX_STORE_U32(ctx.r24.u32 + 3392, ctx.r23.u32);
	// stw r23,3388(r24)
	REX_STORE_U32(ctx.r24.u32 + 3388, ctx.r23.u32);
loc_826CB550:
	// cmplwi cr6,r22,5
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 5, ctx.xer);
	// bne cr6,0x826cb68c
	if (!ctx.cr6.eq) goto loc_826CB68C;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826cb5cc
	if (!ctx.cr6.lt) goto loc_826CB5CC;
loc_826CB574:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826cb5cc
	if (ctx.cr6.eq) goto loc_826CB5CC;
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
	// bge 0x826cb5bc
	if (!ctx.cr0.lt) goto loc_826CB5BC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB5BC;
	sub_826E4FF0(ctx, base);
loc_826CB5BC:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826cb574
	if (ctx.cr6.gt) goto loc_826CB574;
loc_826CB5CC:
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
	// bge 0x826cb608
	if (!ctx.cr0.lt) goto loc_826CB608;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB608;
	sub_826E4FF0(ctx, base);
loc_826CB608:
	// stw r29,21796(r24)
	REX_STORE_U32(ctx.r24.u32 + 21796, ctx.r29.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r31,84(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + 84);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826cb664
	if (!ctx.cr6.lt) goto loc_826CB664;
loc_826CB624:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826cb664
	if (ctx.cr6.eq) goto loc_826CB664;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// sld r6,r9,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// std r6,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r6.u64);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge 0x826cb654
	if (!ctx.cr0.lt) goto loc_826CB654;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB654;
	sub_826E4FF0(ctx, base);
loc_826CB654:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826cb624
	if (ctx.cr6.gt) goto loc_826CB624;
loc_826CB664:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r10,r30,32
	ctx.r10.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// sld r8,r11,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r10.u8 & 0x7F));
	// subf. r7,r30,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge 0x826cb68c
	if (!ctx.cr0.lt) goto loc_826CB68C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e4ff0
	ctx.lr = 0x826CB68C;
	sub_826E4FF0(ctx, base);
loc_826CB68C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
loc_826CB698:
	// li r3,4
	ctx.r3.s64 = 4;
loc_826CB69C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x827566f0
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827869E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566a4
	ctx.lr = 0x827869F0;
	__savegprlr_23(ctx, base);
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r24,0
	ctx.r24.s64 = 0;
	// li r11,4
	ctx.r11.s64 = 4;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r24,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r24.u32);
	// mr r23,r24
	ctx.r23.u64 = ctx.r24.u64;
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r24,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r24.u32);
	// bge cr6,0x82786a20
	if (!ctx.cr6.lt) goto loc_82786A20;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// b 0x82786dbc
	goto loc_82786DBC;
loc_82786A20:
	// addi r25,r31,380
	ctx.r25.s64 = ctx.r31.s64 + 380;
	// mr r26,r24
	ctx.r26.u64 = ctx.r24.u64;
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// addi r27,r1,224
	ctx.r27.s64 = ctx.r1.s64 + 224;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
loc_82786A38:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82786a7c
	if (ctx.cr6.eq) goto loc_82786A7C;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827849c8
	ctx.lr = 0x82786A54;
	sub_827849C8(ctx, base);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// stwx r30,r29,r11
	REX_STORE_U32(ctx.r29.u32 + ctx.r11.u32, ctx.r30.u32);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r11,396(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm r11,r11,3,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x1;
	// stwx r11,r29,r10
	REX_STORE_U32(ctx.r29.u32 + ctx.r10.u32, ctx.r11.u32);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// b 0x82786a8c
	goto loc_82786A8C;
loc_82786A7C:
	// li r5,42
	ctx.r5.s64 = 42;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82756d30
	ctx.lr = 0x82786A8C;
	sub_82756D30(ctx, base);
loc_82786A8C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// addi r27,r27,42
	ctx.r27.s64 = ctx.r27.s64 + 42;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x82786a38
	if (ctx.cr6.lt) goto loc_82786A38;
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82786af0
	if (ctx.cr6.eq) goto loc_82786AF0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x827521d0
	ctx.lr = 0x82786AC0;
	sub_827521D0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82786ae4
	if (ctx.cr0.eq) goto loc_82786AE4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82656390
	ctx.lr = 0x82786AD0;
	sub_82656390(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82786dbc
	if (ctx.cr0.lt) goto loc_82786DBC;
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,16389
	ctx.r30.u64 = ctx.r30.u64 | 16389;
	// b 0x82786dbc
	goto loc_82786DBC;
loc_82786AE4:
	// lwz r11,740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 740);
	// oris r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 16777216;
	// stw r11,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r11.u32);
loc_82786AF0:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82786ce0
	if (ctx.cr6.eq) goto loc_82786CE0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82786b0c
	if (!ctx.cr6.eq) goto loc_82786B0C;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82786b10
	goto loc_82786B10;
loc_82786B0C:
	// bl 0x82750e38
	ctx.lr = 0x82786B10;
	sub_82750E38(ctx, base);
loc_82786B10:
	// lwz r11,420(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 420);
	// rlwinm r9,r3,2,24,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFC;
	// stb r9,392(r1)
	REX_STORE_U8(ctx.r1.u32 + 392, ctx.r9.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82786b2c
	if (ctx.cr6.eq) goto loc_82786B2C;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x82786b30
	goto loc_82786B30;
loc_82786B2C:
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
loc_82786B30:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stb r10,392(r1)
	REX_STORE_U8(ctx.r1.u32 + 392, ctx.r10.u8);
	// beq cr6,0x82786b54
	if (ctx.cr6.eq) goto loc_82786B54;
	// lwz r11,60(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// rlwinm r11,r11,2,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1;
	// b 0x82786b58
	goto loc_82786B58;
loc_82786B54:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_82786B58:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82786b68
	if (ctx.cr6.eq) goto loc_82786B68;
	// ori r11,r10,16
	ctx.r11.u64 = ctx.r10.u64 | 16;
	// stb r11,392(r1)
	REX_STORE_U8(ctx.r1.u32 + 392, ctx.r11.u8);
loc_82786B68:
	// li r11,1000
	ctx.r11.s64 = 1000;
	// stw r24,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r24.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,116(r1)
	REX_STORE_U16(ctx.r1.u32 + 116, ctx.r11.u16);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82783930
	ctx.lr = 0x82786B98;
	sub_82783930(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82786da4
	if (ctx.cr0.lt) goto loc_82786DA4;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827810a8
	ctx.lr = 0x82786BAC;
	sub_827810A8(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// li r6,8
	ctx.r6.s64 = 8;
	// lwz r23,100(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r5,5
	ctx.r5.s64 = 5;
	// lwz r8,108(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// addi r29,r31,400
	ctx.r29.s64 = ctx.r31.s64 + 400;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r24,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r24.u32);
	// sth r6,96(r1)
	REX_STORE_U16(ctx.r1.u32 + 96, ctx.r6.u16);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// sth r5,98(r1)
	REX_STORE_U16(ctx.r1.u32 + 98, ctx.r5.u16);
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// li r6,31
	ctx.r6.s64 = 31;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// li r5,169
	ctx.r5.s64 = 169;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8278e5b8
	ctx.lr = 0x82786BF4;
	sub_8278E5B8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827811f8
	ctx.lr = 0x82786C04;
	sub_827811F8(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82786da8
	if (ctx.cr6.lt) goto loc_82786DA8;
	// li r8,4
	ctx.r8.s64 = 4;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r7,r31,560
	ctx.r7.s64 = ctx.r31.s64 + 560;
	// li r6,20
	ctx.r6.s64 = 20;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8278e750
	ctx.lr = 0x82786C28;
	sub_8278E750(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82786c68
	if (!ctx.cr6.eq) goto loc_82786C68;
	// addi r29,r31,408
	ctx.r29.s64 = ctx.r31.s64 + 408;
	// li r6,1199
	ctx.r6.s64 = 1199;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// li r5,1001
	ctx.r5.s64 = 1001;
	// addi r4,r31,92
	ctx.r4.s64 = ctx.r31.s64 + 92;
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// bl 0x82791f00
	ctx.lr = 0x82786C50;
	sub_82791F00(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82786da8
	if (ctx.cr0.lt) goto loc_82786DA8;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r5,104(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x827919a8
	ctx.lr = 0x82786C68;
	sub_827919A8(ctx, base);
loc_82786C68:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x8278e7e8
	ctx.lr = 0x82786C74;
	sub_8278E7E8(ctx, base);
	// li r7,5
	ctx.r7.s64 = 5;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,524(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// lwz r4,520(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// bl 0x82752c70
	ctx.lr = 0x82786C8C;
	sub_82752C70(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82786cb0
	if (ctx.cr0.eq) goto loc_82786CB0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bgt cr6,0x82786ca4
	if (ctx.cr6.gt) goto loc_82786CA4;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82786dbc
	goto loc_82786DBC;
loc_82786CA4:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r30,r11,32775
	ctx.r30.u64 = ctx.r11.u64 | 2147942400;
	// b 0x82786dbc
	goto loc_82786DBC;
loc_82786CB0:
	// lwz r11,740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 740);
	// oris r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 33554432;
	// rlwinm. r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r11.u32);
	// beq 0x82786d9c
	if (ctx.cr0.eq) goto loc_82786D9C;
	// rlwinm r11,r11,0,23,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r11.u32);
	// bl 0x82786888
	ctx.lr = 0x82786CD4;
	sub_82786888(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82786dbc
	if (ctx.cr0.lt) goto loc_82786DBC;
	// b 0x82786d9c
	goto loc_82786D9C;
loc_82786CE0:
	// lwz r11,740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 740);
	// rlwinm. r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82786d04
	if (ctx.cr0.eq) goto loc_82786D04;
	// rlwinm r11,r11,0,23,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r11.u32);
	// bl 0x82786888
	ctx.lr = 0x82786CFC;
	sub_82786888(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82786da8
	if (ctx.cr0.lt) goto loc_82786DA8;
loc_82786D04:
	// li r11,3
	ctx.r11.s64 = 3;
	// lwz r4,20(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r24,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r24.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82786D30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// li r29,4
	ctx.r29.s64 = 4;
loc_82786D38:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82786d90
	if (ctx.cr6.eq) goto loc_82786D90;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// bl 0x82752d18
	ctx.lr = 0x82786D4C;
	sub_82752D18(ctx, base);
	// li r5,255
	ctx.r5.s64 = 255;
	// addi r3,r31,256
	ctx.r3.s64 = ctx.r31.s64 + 256;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8278ecb8
	ctx.lr = 0x82786D5C;
	sub_8278ECB8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r10.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x82786D90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82786D90:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x82786d38
	if (!ctx.cr0.eq) goto loc_82786D38;
loc_82786D9C:
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x827566f4
	__restgprlr_23(ctx, base);
	return;
loc_82786DA4:
	// lwz r23,100(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_82786DA8:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x82786dbc
	if (ctx.cr6.eq) goto loc_82786DBC;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x8278e7e8
	ctx.lr = 0x82786DBC;
	sub_8278E7E8(ctx, base);
loc_82786DBC:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82785f08
	ctx.lr = 0x82786DC8;
	sub_82785F08(ctx, base);
	// b 0x82786d9c
	goto loc_82786D9C;
}

DEFINE_REX_FUNC(sub_8279BA70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82756694
	ctx.lr = 0x8279BA78;
	__savegprlr_19(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// li r4,15
	ctx.r4.s64 = 15;
	// li r3,19
	ctx.r3.s64 = 19;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r19,r7
	ctx.r19.u64 = ctx.r7.u64;
	// mr r22,r8
	ctx.r22.u64 = ctx.r8.u64;
	// bl 0x827a55e0
	ctx.lr = 0x8279BAA0;
	sub_827A55E0(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x8279bab4
	if (!ctx.cr0.eq) goto loc_8279BAB4;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x8279bd94
	goto loc_8279BD94;
loc_8279BAB4:
	// lwz r11,60(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 60);
	// stw r11,69(r29)
	REX_STORE_U32(ctx.r29.u32 + 69, ctx.r11.u32);
	// lwz r11,64(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 64);
	// stw r11,73(r29)
	REX_STORE_U32(ctx.r29.u32 + 73, ctx.r11.u32);
	// lhz r11,68(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 68);
	// sth r11,77(r29)
	REX_STORE_U16(ctx.r29.u32 + 77, ctx.r11.u16);
	// lhz r11,70(r26)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r26.u32 + 70);
	// sth r22,81(r29)
	REX_STORE_U16(ctx.r29.u32 + 81, ctx.r22.u16);
	// sth r11,79(r29)
	REX_STORE_U16(ctx.r29.u32 + 79, ctx.r11.u16);
	// lwz r11,92(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279bb38
	if (ctx.cr6.eq) goto loc_8279BB38;
loc_8279BAE4:
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
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwcx. r10,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279bae4
	if (!ctx.cr0.eq) goto loc_8279BAE4;
	// lwz r10,32(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// stw r9,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r9.u32);
	// lwz r10,32(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// addi r10,r10,5
	ctx.r10.s64 = ctx.r10.s64 + 5;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r8,r10,r29
	REX_STORE_U32(ctx.r10.u32 + ctx.r29.u32, ctx.r8.u32);
	// stw r11,16(r29)
	REX_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lwz r11,32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,32(r29)
	REX_STORE_U32(ctx.r29.u32 + 32, ctx.r11.u32);
loc_8279BB38:
	// rlwinm r11,r24,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// li r23,0
	ctx.r23.s64 = 0;
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x8279bd50
	if (ctx.cr6.eq) goto loc_8279BD50;
	// addi r21,r11,-4
	ctx.r21.s64 = ctx.r11.s64 + -4;
loc_8279BB50:
	// lwzu r31,4(r21)
	ea = 4 + ctx.r21.u32;
	ctx.r31.u64 = REX_LOAD_U32(ea);
	ctx.r21.u32 = ea;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8279bdb0
	if (ctx.cr6.eq) goto loc_8279BDB0;
	// lwz r11,60(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 60);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8279bdb0
	if (ctx.cr6.eq) goto loc_8279BDB0;
	// lwz r11,24(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 24);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8279bdb0
	if (ctx.cr6.eq) goto loc_8279BDB0;
	// lwz r11,208(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 208);
	// addi r10,r25,208
	ctx.r10.s64 = ctx.r25.s64 + 208;
	// b 0x8279bb94
	goto loc_8279BB94;
loc_8279BB80:
	// lwz r9,56(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// addi r30,r11,-4
	ctx.r30.s64 = ctx.r11.s64 + -4;
	// cmplw cr6,r9,r31
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8279bba8
	if (ctx.cr6.eq) goto loc_8279BBA8;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_8279BB94:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8279bba4
	if (ctx.cr6.eq) goto loc_8279BBA4;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8279bb80
	if (!ctx.cr0.eq) goto loc_8279BB80;
loc_8279BBA4:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8279BBA8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8279bdb0
	if (ctx.cr6.eq) goto loc_8279BDB0;
	// addi r27,r26,196
	ctx.r27.s64 = ctx.r26.s64 + 196;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827a0c60
	ctx.lr = 0x8279BBC0;
	sub_827A0C60(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8279bdb0
	if (!ctx.cr0.eq) goto loc_8279BDB0;
	// addi r28,r30,184
	ctx.r28.s64 = ctx.r30.s64 + 184;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827a0c60
	ctx.lr = 0x8279BBD8;
	sub_827A0C60(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8279bdb0
	if (!ctx.cr0.eq) goto loc_8279BDB0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8279bc0c
	if (ctx.cr6.eq) goto loc_8279BC0C;
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
loc_8279BBF0:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r9,r31
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8279bdb0
	if (ctx.cr6.eq) goto loc_8279BDB0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r10,r24
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r24.u32, ctx.xer);
	// blt cr6,0x8279bbf0
	if (ctx.cr6.lt) goto loc_8279BBF0;
loc_8279BC0C:
	// lwz r11,232(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 232);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8279bcf8
	if (!ctx.cr6.eq) goto loc_8279BCF8;
	// lwz r11,316(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 316);
	// lwz r10,320(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 320);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8279bcf8
	if (!ctx.cr6.lt) goto loc_8279BCF8;
	// lwz r11,72(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279bcf8
	if (ctx.cr6.eq) goto loc_8279BCF8;
	// lwz r11,288(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 288);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8279bc50
	if (!ctx.cr0.eq) goto loc_8279BC50;
	// lwz r11,288(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 288);
	// li r7,1155
	ctx.r7.s64 = 1155;
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8279bc54
	if (ctx.cr0.eq) goto loc_8279BC54;
loc_8279BC50:
	// li r7,131
	ctx.r7.s64 = 131;
loc_8279BC54:
	// addi r5,r29,36
	ctx.r5.s64 = ctx.r29.s64 + 36;
	// lwz r6,32(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827a17d8
	ctx.lr = 0x8279BC68;
	sub_827A17D8(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827a1bf0
	ctx.lr = 0x8279BC84;
	sub_827A1BF0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827a0ca8
	ctx.lr = 0x8279BC90;
	sub_827A0CA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8279bdb8
	if (!ctx.cr0.eq) goto loc_8279BDB8;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827a0ca8
	ctx.lr = 0x8279BCA4;
	sub_827A0CA8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8279bcb8
	if (!ctx.cr0.eq) goto loc_8279BCB8;
	// lwz r11,176(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 176);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,176(r30)
	REX_STORE_U32(ctx.r30.u32 + 176, ctx.r11.u32);
loc_8279BCB8:
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8279bda0
	if (!ctx.cr6.eq) goto loc_8279BDA0;
	// lwz r11,320(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 320);
	// lwz r10,396(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 396);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// oris r10,r10,256
	ctx.r10.u64 = ctx.r10.u64 | 16777216;
	// stw r11,320(r25)
	REX_STORE_U32(ctx.r25.u32 + 320, ctx.r11.u32);
	// stw r10,396(r25)
	REX_STORE_U32(ctx.r25.u32 + 396, ctx.r10.u32);
	// lwz r11,288(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 288);
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8279bd44
	if (!ctx.cr0.eq) goto loc_8279BD44;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827a1b58
	ctx.lr = 0x8279BCF4;
	sub_827A1B58(ctx, base);
	// b 0x8279bd3c
	goto loc_8279BD3C;
loc_8279BCF8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827a0ca8
	ctx.lr = 0x8279BD04;
	sub_827A0CA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8279bdb8
	if (!ctx.cr0.eq) goto loc_8279BDB8;
	// lwz r11,232(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 232);
	// lis r7,-32646
	ctx.r7.s64 = -2139488256;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279bd24
	if (ctx.cr6.eq) goto loc_8279BD24;
	// ori r7,r7,4120
	ctx.r7.u64 = ctx.r7.u64 | 4120;
	// b 0x8279bd28
	goto loc_8279BD28;
loc_8279BD24:
	// ori r7,r7,4101
	ctx.r7.u64 = ctx.r7.u64 | 4101;
loc_8279BD28:
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8279ba10
	ctx.lr = 0x8279BD3C;
	sub_8279BA10(ctx, base);
loc_8279BD3C:
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8279bdb8
	if (ctx.cr0.lt) goto loc_8279BDB8;
loc_8279BD44:
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// cmplw cr6,r23,r19
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r19.u32, ctx.xer);
	// blt cr6,0x8279bb50
	if (ctx.cr6.lt) goto loc_8279BB50;
loc_8279BD50:
	// addi r11,r29,4
	ctx.r11.s64 = ctx.r29.s64 + 4;
loc_8279BD54:
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
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279bd54
	if (!ctx.cr0.eq) goto loc_8279BD54;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8279bd90
	if (!ctx.cr6.eq) goto loc_8279BD90;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8279BD90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8279BD90:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8279BD94:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x827566e4
	__restgprlr_19(ctx, base);
	return;
loc_8279BDA0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827a0dc0
	ctx.lr = 0x8279BDAC;
	sub_827A0DC0(ctx, base);
	// b 0x8279bdb8
	goto loc_8279BDB8;
loc_8279BDB0:
	// lis r31,-32646
	ctx.r31.s64 = -2139488256;
	// ori r31,r31,4106
	ctx.r31.u64 = ctx.r31.u64 | 4106;
loc_8279BDB8:
	// addi r11,r29,4
	ctx.r11.s64 = ctx.r29.s64 + 4;
loc_8279BDBC:
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
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279bdbc
	if (!ctx.cr0.eq) goto loc_8279BDBC;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8279bd94
	if (!ctx.cr6.eq) goto loc_8279BD94;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8279BDF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8279bd94
	goto loc_8279BD94;
}

DEFINE_REX_FUNC(sub_8279D800) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8275669c
	ctx.lr = 0x8279D808;
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
	// ble cr6,0x8279d854
	if (!ctx.cr6.gt) goto loc_8279D854;
loc_8279D848:
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4102
	ctx.r30.u64 = ctx.r30.u64 | 4102;
	// b 0x8279dc28
	goto loc_8279DC28;
loc_8279D854:
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8279d848
	if (ctx.cr6.gt) goto loc_8279D848;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82792258
	ctx.lr = 0x8279D864;
	sub_82792258(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8279dc18
	if (ctx.cr0.lt) goto loc_8279DC18;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lwz r6,340(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 340);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x8279b430
	ctx.lr = 0x8279D880;
	sub_8279B430(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8279d894
	if (!ctx.cr0.eq) goto loc_8279D894;
loc_8279D888:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x8279dbb4
	goto loc_8279DBB4;
loc_8279D894:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r22,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r22.u32);
	// beq cr6,0x8279d8e0
	if (ctx.cr6.eq) goto loc_8279D8E0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// li r3,258
	ctx.r3.s64 = 258;
	// bl 0x82794900
	ctx.lr = 0x8279D8B0;
	sub_82794900(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r3.u32);
	// beq 0x8279d888
	if (ctx.cr0.eq) goto loc_8279D888;
loc_8279D8BC:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r3
	ea = ctx.r3.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r3
	ea = ctx.r3.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279d8bc
	if (!ctx.cr0.eq) goto loc_8279D8BC;
	// lwz r11,184(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
loc_8279D8E0:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8279d928
	if (ctx.cr6.eq) goto loc_8279D928;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r3,257
	ctx.r3.s64 = 257;
	// bl 0x82794900
	ctx.lr = 0x8279D8F8;
	sub_82794900(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r3.u32);
	// beq 0x8279d888
	if (ctx.cr0.eq) goto loc_8279D888;
loc_8279D904:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r3
	ea = ctx.r3.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r3
	ea = ctx.r3.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279d904
	if (!ctx.cr0.eq) goto loc_8279D904;
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// stw r11,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
loc_8279D928:
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
	// blt 0x8279dbb4
	if (ctx.cr0.lt) goto loc_8279DBB4;
	// addi r27,r31,168
	ctx.r27.s64 = ctx.r31.s64 + 168;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x827a5150
	ctx.lr = 0x8279D958;
	sub_827A5150(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8279dbb4
	if (ctx.cr0.lt) goto loc_8279DBB4;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x8279d9d4
	if (!ctx.cr6.eq) goto loc_8279D9D4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x827a5158
	ctx.lr = 0x8279D974;
	sub_827A5158(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8279dbb4
	if (ctx.cr0.lt) goto loc_8279DBB4;
	// addi r30,r31,108
	ctx.r30.s64 = ctx.r31.s64 + 108;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82872dfc
	ctx.lr = 0x8279D988;
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
	// bl 0x827a2cb8
	ctx.lr = 0x8279D9B8;
	sub_827A2CB8(ctx, base);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// oris r11,r11,20480
	ctx.r11.u64 = ctx.r11.u64 | 1342177280;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// bl 0x8279cd90
	ctx.lr = 0x8279D9CC;
	sub_8279CD90(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x8279dc70
	goto loc_8279DC70;
loc_8279D9D4:
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82792518
	ctx.lr = 0x8279D9E4;
	sub_82792518(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8279dbb4
	if (!ctx.cr0.eq) goto loc_8279DBB4;
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
	// bl 0x827a1220
	ctx.lr = 0x8279DA10;
	sub_827A1220(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x8279da20
	if (!ctx.cr0.eq) goto loc_8279DA20;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// b 0x8279db00
	goto loc_8279DB00;
loc_8279DA20:
	// addi r28,r31,108
	ctx.r28.s64 = ctx.r31.s64 + 108;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82872dfc
	ctx.lr = 0x8279DA2C;
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
	// ble cr6,0x8279da6c
	if (!ctx.cr6.gt) goto loc_8279DA6C;
	// li r11,128
	ctx.r11.s64 = 128;
	// b 0x8279da70
	goto loc_8279DA70;
loc_8279DA6C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_8279DA70:
	// stb r11,102(r1)
	REX_STORE_U8(ctx.r1.u32 + 102, ctx.r11.u8);
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279da8c
	if (ctx.cr6.eq) goto loc_8279DA8C;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,103(r1)
	REX_STORE_U32(ctx.r1.u32 + 103, ctx.r11.u32);
	// b 0x8279da90
	goto loc_8279DA90;
loc_8279DA8C:
	// stw r22,103(r1)
	REX_STORE_U32(ctx.r1.u32 + 103, ctx.r22.u32);
loc_8279DA90:
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
	// bl 0x827a5160
	ctx.lr = 0x8279DAB0;
	sub_827A5160(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8279db00
	if (ctx.cr0.lt) goto loc_8279DB00;
loc_8279DAB8:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279dab8
	if (!ctx.cr0.eq) goto loc_8279DAB8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,72(r29)
	REX_STORE_U32(ctx.r29.u32 + 72, ctx.r11.u32);
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279dc34
	if (ctx.cr6.eq) goto loc_8279DC34;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82792b10
	ctx.lr = 0x8279DAF8;
	sub_82792B10(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8279dc34
	if (ctx.cr0.eq) goto loc_8279DC34;
loc_8279DB00:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8279dbb4
	if (ctx.cr6.eq) goto loc_8279DBB4;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279db88
	if (ctx.cr6.eq) goto loc_8279DB88;
loc_8279DB14:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279db14
	if (!ctx.cr0.eq) goto loc_8279DB14;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8279db40
	if (!ctx.cr6.eq) goto loc_8279DB40;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827a12d8
	ctx.lr = 0x8279DB40;
	sub_827A12D8(ctx, base);
loc_8279DB40:
	// stw r22,72(r29)
	REX_STORE_U32(ctx.r29.u32 + 72, ctx.r22.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827a5210
	ctx.lr = 0x8279DB4C;
	sub_827A5210(ctx, base);
	// stw r22,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r22.u32);
	// lwz r4,192(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8279db88
	if (ctx.cr6.eq) goto loc_8279DB88;
loc_8279DB5C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r4
	ea = ctx.r4.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r4
	ea = ctx.r4.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279db5c
	if (!ctx.cr0.eq) goto loc_8279DB5C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8279db88
	if (!ctx.cr6.eq) goto loc_8279DB88;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x8278e7e8
	ctx.lr = 0x8279DB88;
	sub_8278E7E8(ctx, base);
loc_8279DB88:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = REX_LOAD_RESERVED_U32(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = REX_COMPARE_EXCHANGE_U32(ea, ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8279db88
	if (!ctx.cr0.eq) goto loc_8279DB88;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8279dbb4
	if (!ctx.cr6.eq) goto loc_8279DBB4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827a12d8
	ctx.lr = 0x8279DBB4;
	sub_827A12D8(ctx, base);
loc_8279DBB4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8279dc18
	if (ctx.cr6.eq) goto loc_8279DC18;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// bne cr6,0x8279dbcc
	if (!ctx.cr6.eq) goto loc_8279DBCC;
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// bl 0x82872dfc
	ctx.lr = 0x8279DBCC;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8279DBCC:
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// addi r3,r31,108
	ctx.r3.s64 = ctx.r31.s64 + 108;
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// bl 0x82872dec
	ctx.lr = 0x8279DBE0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r3,168(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8279dbf4
	if (ctx.cr6.eq) goto loc_8279DBF4;
	// bl 0x827a5210
	ctx.lr = 0x8279DBF0;
	sub_827A5210(ctx, base);
	// stw r22,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r22.u32);
loc_8279DBF4:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8279dc04
	if (ctx.cr6.eq) goto loc_8279DC04;
	// stw r22,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r22.u32);
loc_8279DC04:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82796140
	ctx.lr = 0x8279DC0C;
	sub_82796140(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x8278e7e8
	ctx.lr = 0x8279DC18;
	sub_8278E7E8(ctx, base);
loc_8279DC18:
	// lwz r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8279dc28
	if (ctx.cr6.eq) goto loc_8279DC28;
	// bl 0x827920d8
	ctx.lr = 0x8279DC28;
	sub_827920D8(ctx, base);
loc_8279DC28:
	// lwz r11,348(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 348);
	// stw r22,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r22.u32);
	// b 0x8279dc84
	goto loc_8279DC84;
loc_8279DC34:
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
loc_8279DC70:
	// bl 0x82872dec
	ctx.lr = 0x8279DC74;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r11,348(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 348);
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8279DC84:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x827566ec
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A5158) {
	REX_FUNC_PROLOGUE();
	// b 0x827a6b60
	sub_827A6B60(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827B42E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r11,r3,48
	ctx.r11.s64 = ctx.r3.s64 + 48;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
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
	// addi r3,r11,-4
	ctx.r3.s64 = ctx.r11.s64 + -4;
	// b 0x827b7f40
	sub_827B7F40(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827C19A8) {
	REX_FUNC_PROLOGUE();
	// b 0x827c18e8
	sub_827C18E8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827C1CE8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r11,92(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 92);
	// stb r11,0(r4)
	REX_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827C2340) {
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
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x827c23b4
	if (ctx.cr6.eq) goto loc_827C23B4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827c7020
	ctx.lr = 0x827C2368;
	sub_827C7020(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x827c3fc0
	ctx.lr = 0x827C2370;
	sub_827C3FC0(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = ctx.r31.s64 + 20;
	// bl 0x827c40b8
	ctx.lr = 0x827C2378;
	sub_827C40B8(ctx, base);
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// bl 0x827c3fc0
	ctx.lr = 0x827C2380;
	sub_827C3FC0(ctx, base);
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lis r30,-32110
	ctx.r30.s64 = -2104360960;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827c23a4
	if (ctx.cr6.eq) goto loc_827C23A4;
	// lwz r11,-24508(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -24508);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x827C239C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
loc_827C23A4:
	// lwz r11,-24508(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -24508);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x827C23B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_827C23B4:
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

DEFINE_REX_FUNC(sub_827C7118) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8275668c
	ctx.lr = 0x827C7120;
	__savegprlr_17(ctx, base);
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x827576bc
	ctx.lr = 0x827C7128;
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
	// lfs f30,7972(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7972);
	ctx.f30.f64 = double(temp.f32);
	// mr r19,r5
	ctx.r19.u64 = ctx.r5.u64;
	// fmuls f13,f1,f30
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// mr r17,r6
	ctx.r17.u64 = ctx.r6.u64;
	// lfs f0,11236(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 11236);
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
	// blt cr6,0x827c71a8
	if (ctx.cr6.lt) goto loc_827C71A8;
	// addi r30,r30,-1
	ctx.r30.s64 = ctx.r30.s64 + -1;
loc_827C71A8:
	// cmpwi cr6,r30,100
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 100, ctx.xer);
	// ble cr6,0x827c71b4
	if (!ctx.cr6.gt) goto loc_827C71B4;
	// li r30,100
	ctx.r30.s64 = 100;
loc_827C71B4:
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lfs f13,-20544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20544);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f2,f13
	ctx.f0.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x827c71d8
	if (!ctx.cr6.lt) goto loc_827C71D8;
	// li r11,100
	ctx.r11.s64 = 100;
	// twllei r30,0
	if (ctx.r30.s32 == 0 || ctx.r30.u32 < 0u) ppc_trap(ctx, base, 0);
	// divw r27,r11,r30
	ctx.r27.u64 = uint32_t((ctx.r30.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r30.s32 == -1)) ? ctx.r11.s32 / ctx.r30.s32 : 0);
	// b 0x827c71dc
	goto loc_827C71DC;
loc_827C71D8:
	// li r27,1
	ctx.r27.s64 = 1;
loc_827C71DC:
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
	// lfs f0,-14880(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -14880);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// addi r22,r11,-14948
	ctx.r22.s64 = ctx.r11.s64 + -14948;
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
loc_827C7228:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f29,f0
	ctx.cr6.compare(ctx.f29.f64, ctx.f0.f64);
	// bgt cr6,0x827c724c
	if (ctx.cr6.gt) goto loc_827C724C;
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
	// blt cr6,0x827c7228
	if (ctx.cr6.lt) goto loc_827C7228;
loc_827C724C:
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f27.f64;
	// bl 0x827c5308
	ctx.lr = 0x827C7254;
	sub_827C5308(ctx, base);
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
	// lfs f0,-14896(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -14896);
	ctx.f0.f64 = double(temp.f32);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fsubs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// bl 0x827c8d88
	ctx.lr = 0x827C72A4;
	sub_827C8D88(ctx, base);
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
	// lfs f0,-14884(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14884);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,-14900(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -14900);
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
	// ble cr6,0x827c72ec
	if (!ctx.cr6.gt) goto loc_827C72EC;
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// b 0x827c72fc
	goto loc_827C72FC;
loc_827C72EC:
	// fsubs f0,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
loc_827C72FC:
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
	// lfs f0,28080(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28080);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f1,f12,f0,f13
	ctx.f1.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
	// stfs f1,0(r26)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// bl 0x827c7070
	ctx.lr = 0x827C7338;
	sub_827C7070(ctx, base);
	// addi r11,r30,-1
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// addi r10,r21,-1
	ctx.r10.s64 = ctx.r21.s64 + -1;
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x827c73a8
	if (ctx.cr6.lt) goto loc_827C73A8;
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
loc_827C736C:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble cr6,0x827c739c
	if (!ctx.cr6.gt) goto loc_827C739C;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
	// subf r10,r27,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r27.u64;
	// subf r8,r5,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r5.u64;
loc_827C7384:
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
	// bdnz 0x827c7384
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827C7384;
loc_827C739C:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// bne 0x827c736c
	if (!ctx.cr0.eq) goto loc_827C736C;
loc_827C73A8:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x827c740c
	if (ctx.cr6.lt) goto loc_827C740C;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r31,r25
	ctx.r6.u64 = ctx.r25.u64 - ctx.r31.u64;
	// add r8,r9,r31
	ctx.r8.u64 = ctx.r9.u64 + ctx.r31.u64;
loc_827C73BC:
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
	// ble cr6,0x827c7400
	if (!ctx.cr6.gt) goto loc_827C7400;
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
loc_827C73F0:
	// stfsx f10,r7,r6
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r7.u32 + ctx.r6.u32, temp.u32);
	// stfs f10,0(r7)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// bdnz 0x827c73f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827C73F0;
loc_827C7400:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// bge 0x827c73bc
	if (!ctx.cr0.lt) goto loc_827C73BC;
loc_827C740C:
	// cmpw cr6,r20,r21
	ctx.cr6.compare<int32_t>(ctx.r20.s32, ctx.r21.s32, ctx.xer);
	// bge cr6,0x827c7490
	if (!ctx.cr6.lt) goto loc_827C7490;
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
loc_827C7430:
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
	// bdnz 0x827c7430
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827C7430;
loc_827C7490:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// lfs f13,5864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5864);
	ctx.f13.f64 = double(temp.f32);
	// ble cr6,0x827c74e8
	if (!ctx.cr6.gt) goto loc_827C74E8;
	// addi r11,r25,-4
	ctx.r11.s64 = ctx.r25.s64 + -4;
	// mtctr r21
	ctx.ctr.u64 = ctx.r21.u64;
loc_827C74A8:
	// lfsu f0,4(r11)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fadds f10,f0,f10
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f10.f64));
	// bdnz 0x827c74a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827C74A8;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lfs f0,-30488(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30488);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// ble cr6,0x827c74c8
	if (!ctx.cr6.gt) goto loc_827C74C8;
	// fdivs f13,f0,f10
	ctx.f13.f64 = double(float(ctx.f0.f64 / ctx.f10.f64));
loc_827C74C8:
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// ble cr6,0x827c74e8
	if (!ctx.cr6.gt) goto loc_827C74E8;
	// mtctr r21
	ctx.ctr.u64 = ctx.r21.u64;
	// addi r11,r25,-4
	ctx.r11.s64 = ctx.r25.s64 + -4;
loc_827C74D8:
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
	// bdnz 0x827c74d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827C74D8;
loc_827C74E8:
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
	// bl 0x827c31c0
	ctx.lr = 0x827C7514;
	sub_827C31C0(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x82757708
	ctx.lr = 0x827C7520;
	__restfpr_25(ctx, base);
	// b 0x827566dc
	__restgprlr_17(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827CFDA8) {
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
	// lfs f0,23976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23976);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10208(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10208);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4476(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4476);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4388(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4388, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D2EC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,24684(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24684);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2936(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2936, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827D6088) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,25356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1500(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1500, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DA200) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,452(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 452, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DC5A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,27008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1504(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1504, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827DE6F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,2340(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,2464(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 2464, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E0D78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,3620(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3620);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3624(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3624, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E2780) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,4396(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4396);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4400(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4400, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E3670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,4736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4736);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4860(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4860, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E42E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,5252(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5252);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5256(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5256, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E55E8) {
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
	// lfs f0,29592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13444(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5692(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5692);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5812(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5812, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E6B40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,29848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6392);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6440(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6440, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E7F30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,7040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7040);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7044(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7044, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827E93C8) {
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
	// lfs f0,30232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7560(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7560);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7644(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7644, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EA7A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,30440
	ctx.r9.s64 = ctx.r11.s64 + 30440;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,30440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8224(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8224, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EC048) {
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
	// lfs f0,30696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10208(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10208);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8852(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8852);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8940(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8940, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EC720) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,9136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9136);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,9140(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 9140, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827ED7A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,30976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30976);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9624(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9624, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EE4E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,31080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9964(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9964);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10012(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10012, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EE950) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,10132(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10132);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10136(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10136, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827EFAA8) {
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
	// lfs f0,31272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10528(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10528);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10644(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10644, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F1310) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,11352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11352);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,11356(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 11356, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F1FB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// addi r9,r11,31656
	ctx.r9.s64 = ctx.r11.s64 + 31656;
	// lfs f0,31656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11724(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 11724, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F3300) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,31848
	ctx.r9.s64 = ctx.r11.s64 + 31848;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,31848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12288(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12288, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F39A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,31912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12372(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12372);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12480(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12480, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F4A28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,32112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12912(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12912);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12964(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12964, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F5BB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,13468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13472(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13472, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F6DA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,32452(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32452);
	ctx.f0.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,13992(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 13992, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F7970) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,32584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14240(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14240);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,14340(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 14340, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827F9318) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// addi r9,r11,-32696
	ctx.r9.s64 = ctx.r11.s64 + -32696;
	// lfs f0,-32696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15092(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 15092, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FA4E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,15628(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15628);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15632(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15632, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FB910) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,16220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16220);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16224(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16224, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FBE68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f13,16364(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 16364);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,960(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 960);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,16376(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16376, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FCE30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-32072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16792(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16792);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16840(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16840, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FE390) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,17476(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17476);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,17480(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 17480, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FF390) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,17952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17956(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17956, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_827FFB40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,18172(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18172);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18176(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18176, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82800AA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,18612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18612);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18616(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18616, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82801EC0) {
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
	// lfs f0,-30904(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30904);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30788(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30788);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19100(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19100);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19180(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19180, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828032F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,19756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19760(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19760, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82803500) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-28296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,19772(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 19772);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19824, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828046B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,20296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20296);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20300(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 20300, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82805430) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-24872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20632(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20632);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20680(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20680, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82805B78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,20892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20892);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20896, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82806AB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,21312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21316(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21316, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82806EF8) {
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
	// lfs f0,-22616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,21372(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 21372);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,21436(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 21436, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82807E00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-21752
	ctx.r9.s64 = ctx.r11.s64 + -21752;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-21752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,21860(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 21860, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828095C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,22508(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22508);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22512(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22512, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280A938) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,23044(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23044);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23048(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23048, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280B318) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,23308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23308);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-19176(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -19176);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14392);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,23324(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 23324, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280BDB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,23612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23612);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23616(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23616, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280D150) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-17752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24104);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24156(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24156, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280E358) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-17032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24552(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24552);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24656(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24656, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280F6D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,25200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25204(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25204, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8280F930) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-16072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25264(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25264, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82810980) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,25720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25724(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25724, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82810BE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-15512
	ctx.r9.s64 = ctx.r11.s64 + -15512;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-15512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25792(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25792, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82812208) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lfs f0,26596(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26596);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,26600(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 26600, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82812D90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-14260(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14260);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26976(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26976, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82813E10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-12936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12936);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27440(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27440, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82814D70) {
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
	// lfs f0,-12408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12408);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27776(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27776);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27836(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27836, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828154E0) {
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
	// lfs f0,-11016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27988(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27988);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28044(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28044, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82816C70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32110
	ctx.r7.s64 = -2104360960;
	// lfs f0,28672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28672);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-2512
	ctx.r11.s64 = ctx.r8.s64 + -2512;
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8888(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8888);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,28696(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 28696, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828192B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,-8100(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8100);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29808, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82819AE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,30048(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30048);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30052(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30052, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281A6E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,30396(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30396);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30400(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30400, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281B8F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,30920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30924(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30924, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281C0C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32110
	ctx.r9.s64 = -2104360960;
	// lfs f0,31152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31156(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31156, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281CEB0) {
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
	// lfs f0,-7512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10820);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31488(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31488);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31560(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31560, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281E920) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-7256
	ctx.r9.s64 = ctx.r11.s64 + -7256;
	// lis r8,-32110
	ctx.r8.s64 = -2104360960;
	// lfs f0,-7256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32332(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32332, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8281F6B0) {
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
	// lfs f0,-7128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32612(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32612);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32728(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32728, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82820160) {
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
	// lfs f0,-7000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10820);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32568(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32568);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-32496(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -32496, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82821568) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-31916(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31916);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-31912(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -31912, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82821F08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-31636(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31636);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31632(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31632, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82822E70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-31188(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31188);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-31184(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -31184, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828239B8) {
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
	// lfs f0,-6424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30912(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30912);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30852(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30852, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82824D88) {
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
	// lfs f0,-6232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30360(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30360);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30276(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30276, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828267E0) {
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
	// lfs f0,-5976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5976);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29612(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29612);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-29508(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -29508, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82827DD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-5700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5700);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28868(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28868, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82829428) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-5456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5456);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28208(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28208, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282A618) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-27680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27680);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-27676(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -27676, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282B060) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-27376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27372(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27372, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282BA48) {
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
	// lfs f0,-5016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-27200(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -27200);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-27084(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -27084, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282CB00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-26596(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26596);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26592(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26592, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282DC40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-26080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26076(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26076, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8282F200) {
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
	// lfs f0,-4168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25524);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25440(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25440, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828301A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-24980(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24980);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-24976(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -24976, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828308C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-24764(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24764);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-24756(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -24756, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828314E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-3344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24356(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24356, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82832238) {
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
	// lfs f0,-3208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24076(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24076);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23960(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23960, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82833030) {
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
	// lfs f0,-2952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23660(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23660);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23544(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23544, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82834680) {
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
	// lfs f0,-2616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23004(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23004);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22888(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22888, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828353A0) {
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
	// lfs f0,-2216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10208(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10208);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22564(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22564);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22476(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22476, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82835F88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-22128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22124(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22124, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828362F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-22028(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22028);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-22024(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -22024, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82837418) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// addi r11,r11,-2512
	ctx.r11.s64 = ctx.r11.s64 + -2512;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-21556(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -21556);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1544(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1544);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,-21508(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21508, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82839118) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-20656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20652(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20652, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283A160) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-20152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20148(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20148, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283B8F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19448(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19448, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283C9C8) {
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
	// lfs f0,-200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19072(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19072);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18960(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18960, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283E740) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-18096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18092(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18092, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8283FAF0) {
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
	// lfs f0,520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17564(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17564);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17516(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17516, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82840CC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-16988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16988);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16984(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16984, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828414C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,1024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16744(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16744, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82841FE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-16428(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16428);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16424, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82842838) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,1408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1408);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16156(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16156, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82843CC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,1708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15552(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15552, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82845488) {
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
	// lfs f0,1944(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1944);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14976(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14976);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14856(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14856, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82846CB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-14148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14144(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14144, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82848088) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,2604(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2604);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13560(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13560, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82849450) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lfs f0,-12976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12976);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-12972(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -12972, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82849FF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,3016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12688(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12688);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12632(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12632, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284B680) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,3256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12080(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12080);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11968(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11968, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284BC00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// addi r9,r11,3328
	ctx.r9.s64 = ctx.r11.s64 + 3328;
	// lfs f0,3328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3328);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11808(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -11808, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284CA60) {
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
	// lfs f0,3496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11488(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11488);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11388(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11388, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284D088) {
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
	// lfs f0,3568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11328(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11328);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11208(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11208, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284E9C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-10464(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10464);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10460(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10460, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8284FDD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,4376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-9904(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9904);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9852(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9852, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828513F8) {
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
	// lfs f0,4696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9256(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9256);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9196(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9196, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82852CC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-8468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8464(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8464, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82853E00) {
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
	// lfs f0,5192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8060(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8060);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7956(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7956, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82854030) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-7900(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7900);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7896, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828556A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-7236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7232(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7232, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828565C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lis r8,-32109
	ctx.r8.s64 = -2104295424;
	// lfs f0,5760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30788(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30788);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6868(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6868);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6788(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6788, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828578F0) {
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
	// lfs f0,6032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10820);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6300(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6300);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6228(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6228, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82858CD0) {
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
	// lfs f0,6272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5732(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5732);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5648(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5648, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285A0F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// addi r9,r11,6528
	ctx.r9.s64 = ctx.r11.s64 + 6528;
	// lfs f0,6528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5060(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -5060, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285B100) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,6800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4592(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4592, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285C028) {
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
	// lfs f0,6944(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6944);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6328(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4208(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4208);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4148(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4148, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285D3D0) {
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
	// lfs f0,7264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7264);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3668(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3668);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3564(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3564, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285E8D8) {
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
	// lfs f0,7504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3068(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3068);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2952(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2952, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8285FD50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-2356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2352(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2352, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82860BD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-1928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1924(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1924, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82861C70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-1428(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1428);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1424, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82862B30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -988);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-984(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -984, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82863AB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,-528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-524(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -524, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82864B30) {
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
	// lfs f0,8944(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8944);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12484(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12484);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-148(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -148);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-44(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -44, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82865F68) {
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
	// lfs f0,9184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1804(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1804);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,440(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 440);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,560(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 560, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828673C0) {
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
	// lfs f0,9456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9456);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1036(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1036);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1152(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1152, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82868780) {
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
	// lfs f0,9696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13444(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1608(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1608);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1728(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1728, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82869B70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,10036(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10036);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2308(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2308, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286A9B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,2724(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2724);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2728(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2728, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286B8C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32109
	ctx.r10.s64 = -2104295424;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,10456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10456);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,3088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 3088);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3192(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3192, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286C760) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,3632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3636(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3636, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286D858) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,4144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4148(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4148, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286E9C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,4652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4656(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4656, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8286F880) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,5076(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5076);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5080(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5080, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_828707D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32109
	ctx.r9.s64 = -2104295424;
	// lfs f0,5536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15112(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5540, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_82871C98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r6,r1,-16
	ctx.r6.s64 = ctx.r1.s64 + -16;
	// addi r11,r11,-30032
	ctx.r11.s64 = ctx.r11.s64 + -30032;
	// addi r4,r1,-16
	ctx.r4.s64 = ctx.r1.s64 + -16;
	// addi r10,r1,-80
	ctx.r10.s64 = ctx.r1.s64 + -80;
	// addi r8,r1,-48
	ctx.r8.s64 = ctx.r1.s64 + -48;
	// addi r7,r1,-32
	ctx.r7.s64 = ctx.r1.s64 + -32;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32109
	ctx.r5.s64 = -2104295424;
	// vor128 v59,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lfs f13,-80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f13.f64 = double(temp.f32);
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r3,r5,6496
	ctx.r3.s64 = ctx.r5.s64 + 6496;
	// stvx128 v59,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f9.f64 = double(temp.f32);
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-48(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-32(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	REX_STORE_VECTOR(ea, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-64(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,12(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f11,16(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f10,8(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f9,6496(r5)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r5.u32 + 6496, temp.u32);
	// blr
	return;
}

DEFINE_REX_FUNC(sub_8289B8E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x8289B8F0;
	__savegprlr_28(ctx, base);
	// stwu r1,-912(r1)
	ea = -912 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,996(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 996);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cntlzw r6,r11
	ctx.r6.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r11,r6,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// li r8,4
	ctx.r8.s64 = 4;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// slw r29,r8,r10
	ctx.r29.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// slw r28,r7,r9
	ctx.r28.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r9.u8 & 0x3F));
	// subfic r10,r5,8
	ctx.xer.ca = ctx.r5.u32 <= 8;
	ctx.r10.u64 = static_cast<uint64_t>(8) - ctx.r5.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// bl 0x82891318
	ctx.lr = 0x8289B93C;
	sub_82891318(ctx, base);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(REX_LOAD_VECTOR(ea), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vsplth v1,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_set1_epi16(short(0xD0C))));
	// bl 0x82898980
	ctx.lr = 0x8289B960;
	sub_82898980(ctx, base);
	// addi r1,r1,912
	ctx.r1.s64 = ctx.r1.s64 + 912;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_828A8A68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b0
	ctx.lr = 0x828A8A70;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// add r11,r3,r5
	ctx.r11.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// lbz r10,668(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 668);
	// dcbzl r0,r7
	ea = (ctx.r7.u32) & ~127;
	REX_FILL_BYTES(ea, 0, 128);
	// clrlwi r28,r10,30
	ctx.r28.u64 = ctx.r10.u32 & 0x3;
	// lwz r11,24(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 24);
	// addi r5,r3,232
	ctx.r5.s64 = ctx.r3.s64 + 232;
	// lwz r4,632(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 632);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r26,r11,1
	ctx.r26.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r30,4(r8)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r31,40(r6)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r6.u32 + 40);
	// lbz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 20);
	// stw r26,24(r6)
	REX_STORE_U32(ctx.r6.u32 + 24, ctx.r26.u32);
	// dcbzl r0,r31
	ea = (ctx.r31.u32) & ~127;
	REX_FILL_BYTES(ea, 0, 128);
	// cmplwi cr6,r29,128
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 128, ctx.xer);
	// blt cr6,0x828a8adc
	if (ctx.cr6.lt) goto loc_828A8ADC;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// bl 0x826f0bb0
	ctx.lr = 0x828A8AD4;
	sub_826F0BB0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x828a8b34
	goto loc_828A8B34;
loc_828A8ADC:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x828a8b30
	if (!ctx.cr6.gt) goto loc_828A8B30;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
loc_828A8AE8:
	// lhz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r3,26
	ctx.r8.u64 = ctx.r3.u32 & 0x3F;
	// rlwinm r29,r3,24,8,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r29,r7
	ctx.r8.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r7.s32);
	// lbzx r29,r10,r4
	ctx.r29.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r26,r29,r5
	ctx.r26.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r5.u32);
	// rlwinm r3,r3,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 25) & 0x1;
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + ctx.r30.u64;
	// neg r3,r3
	ctx.r3.s64 = static_cast<int64_t>(-ctx.r3.u64);
	// rotlwi r29,r29,1
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r29.u32, 1);
	// xor r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// or r9,r26,r9
	ctx.r9.u64 = ctx.r26.u64 | ctx.r9.u64;
	// subf r3,r3,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r3.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r3,r29,r31
	REX_STORE_U16(ctx.r29.u32 + ctx.r31.u32, ctx.r3.u16);
	// bdnz 0x828a8ae8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_828A8AE8;
loc_828A8B30:
	// stw r11,20(r6)
	REX_STORE_U32(ctx.r6.u32 + 20, ctx.r11.u32);
loc_828A8B34:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrlwi r10,r28,31
	ctx.r10.u64 = ctx.r28.u32 & 0x1;
	// bne cr6,0x828a8ba4
	if (!ctx.cr6.eq) goto loc_828A8BA4;
	// lhz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// rlwinm r9,r28,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0x8;
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
	// add r11,r9,r27
	ctx.r11.u64 = ctx.r9.u64 + ctx.r27.u64;
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
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
loc_828A8BA4:
	// rlwinm r11,r28,2,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0x8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r27
	ctx.r4.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x8288e730
	ctx.lr = 0x828A8BBC;
	sub_8288E730(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82756700
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_828ADEC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b8
	ctx.lr = 0x828ADED0;
	__savegprlr_28(ctx, base);
	// stwu r1,-1664(r1)
	ea = -1664 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,15952
	ctx.r30.s64 = ctx.r3.s64 + 15952;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x828aba28
	ctx.lr = 0x828ADEE4;
	sub_828ABA28(ctx, base);
	// lis r11,-32108
	ctx.r11.s64 = -2104229888;
	// addi r28,r31,22640
	ctx.r28.s64 = ctx.r31.s64 + 22640;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,-10360(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -10360);
	// bl 0x828b1328
	ctx.lr = 0x828ADEF8;
	sub_828B1328(ctx, base);
	// lhz r10,16004(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 16004);
	// addi r29,r31,17360
	ctx.r29.s64 = ctx.r31.s64 + 17360;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r8,r10,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// bl 0x828abb98
	ctx.lr = 0x828ADF1C;
	sub_828ABB98(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x828adfcc
	if (!ctx.cr6.eq) goto loc_828ADFCC;
	// lhz r11,16004(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 16004);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x828ab200
	ctx.lr = 0x828ADF44;
	sub_828AB200(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x828adfcc
	if (!ctx.cr6.eq) goto loc_828ADFCC;
	// lwz r11,3916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x828adfb4
	if (ctx.cr6.eq) goto loc_828ADFB4;
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,204(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,17320(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 17320);
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// srawi r29,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r29.s64 = ctx.r10.s32 >> 1;
	// lwz r10,224(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// lwz r7,3752(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// mullw r11,r9,r3
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r3.s32);
	// lwz r6,3748(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// lwz r30,3744(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// lwz r5,220(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// lwz r9,140(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mullw r3,r29,r3
	ctx.r3.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r3.s32);
	// add r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 + ctx.r10.u64;
	// add r10,r3,r30
	ctx.r10.u64 = ctx.r3.u64 + ctx.r30.u64;
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826f1158
	ctx.lr = 0x828ADFB4;
	sub_826F1158(ctx, base);
loc_828ADFB4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x828b1670
	ctx.lr = 0x828ADFC0;
	sub_828B1670(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r11.u32);
loc_828ADFCC:
	// addi r1,r1,1664
	ctx.r1.s64 = ctx.r1.s64 + 1664;
	// b 0x82756708
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_828B0F38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x827566b4
	ctx.lr = 0x828B0F40;
	__savegprlr_27(ctx, base);
	// stwu r1,-1664(r1)
	ea = -1664 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,21928(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21928);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mulli r11,r11,2336
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(2336));
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r30,r11,15952
	ctx.r30.s64 = ctx.r11.s64 + 15952;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82878d88
	ctx.lr = 0x828B0F60;
	sub_82878D88(ctx, base);
	// lis r10,-32108
	ctx.r10.s64 = -2104229888;
	// addi r28,r31,22640
	ctx.r28.s64 = ctx.r31.s64 + 22640;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,-10360(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -10360);
	// bl 0x828b1328
	ctx.lr = 0x828B0F74;
	sub_828B1328(ctx, base);
	// addi r29,r30,1408
	ctx.r29.s64 = ctx.r30.s64 + 1408;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82888ef8
	ctx.lr = 0x828B0F88;
	sub_82888EF8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x828b10c0
	if (!ctx.cr6.eq) goto loc_828B10C0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x828aa950
	ctx.lr = 0x828B0FA0;
	sub_828AA950(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x828b10c0
	if (!ctx.cr6.eq) goto loc_828B10C0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x828c2ac0
	ctx.lr = 0x828B0FB8;
	sub_828C2AC0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x828b10c0
	if (!ctx.cr6.eq) goto loc_828B10C0;
	// lhz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 52);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// bl 0x8288d900
	ctx.lr = 0x828B0FE0;
	sub_8288D900(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x828b10c0
	if (!ctx.cr6.eq) goto loc_828B10C0;
	// lwz r11,3916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x828b1070
	if (ctx.cr6.eq) goto loc_828B1070;
	// lhz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 52);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r7,r11,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826f2c78
	ctx.lr = 0x828B1010;
	sub_826F2C78(ctx, base);
	// lwz r10,208(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r9,204(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// lwz r7,3752(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// srawi r9,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 1;
	// lwz r6,3748(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r5,220(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r27,1368(r30)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r30.u32 + 1368);
	// lwz r29,3744(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// mullw r10,r10,r27
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r27.s32);
	// lhz r30,52(r30)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r30.u32 + 52);
	// mullw r9,r9,r27
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r27.s32);
	// add r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 + ctx.r10.u64;
	// add r10,r9,r29
	ctx.r10.u64 = ctx.r9.u64 + ctx.r29.u64;
	// rlwinm r9,r30,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x7FFFFFFF;
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// bl 0x826f19e0
	ctx.lr = 0x828B1070;
	sub_826F19E0(ctx, base);
loc_828B1070:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x828b1670
	ctx.lr = 0x828B107C;
	sub_828B1670(ctx, base);
	// lwz r11,3916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x828b10a4
	if (!ctx.cr6.eq) goto loc_828B10A4;
	// lwz r11,14856(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 14856);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x828b10a4
	if (!ctx.cr6.eq) goto loc_828B10A4;
	// lwz r11,15228(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15228);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x828b10a8
	if (ctx.cr6.eq) goto loc_828B10A8;
loc_828B10A4:
	// li r11,1
	ctx.r11.s64 = 1;
loc_828B10A8:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,15592(r31)
	REX_STORE_U32(ctx.r31.u32 + 15592, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r9,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r9.u32);
loc_828B10C0:
	// addi r1,r1,1664
	ctx.r1.s64 = ctx.r1.s64 + 1664;
	// b 0x82756704
	__restgprlr_27(ctx, base);
	return;
}

