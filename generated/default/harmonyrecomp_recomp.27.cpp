#include "harmonyrecomp_funcs.27.h"

DEFINE_REX_FUNC(sub_822130C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
loc_822130CC:
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
	// bne 0x822130cc
	if (!ctx.cr0.eq) goto loc_822130CC;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_8221B9B0) {
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
	// bl 0x8221af30
	ctx.lr = 0x8221B9D0;
	sub_8221AF30(ctx, base);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r9,736
	ctx.r9.s64 = ctx.r9.s64 + 736;
	// addi r8,r8,8604
	ctx.r8.s64 = ctx.r8.s64 + 8604;
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stfs f0,88(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 88, temp.u32);
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// stfs f0,92(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 92, temp.u32);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stw r8,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r8.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lfs f13,16(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x8221ba44
	if (!ctx.cr6.lt) goto loc_8221BA44;
	// stfs f0,88(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 88, temp.u32);
	// stfs f0,80(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// b 0x8221ba68
	goto loc_8221BA68;
loc_8221BA44:
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// stfs f13,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fdivs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// stfs f13,88(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 88, temp.u32);
loc_8221BA68:
	// stfs f0,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 92, temp.u32);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_82223A30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// stfs f1,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f1,72(r3)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stfs f1,40(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// stfs f1,44(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82224EE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82224EE8;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,88(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// ble cr6,0x82224f98
	if (!ctx.cr6.gt) goto loc_82224F98;
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r29,8(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82224f98
	if (ctx.cr6.eq) goto loc_82224F98;
	// lwz r6,48(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// lfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8222c8c0
	ctx.lr = 0x82224F2C;
	sub_8222C8C0(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x82224f98
	if (ctx.cr0.eq) goto loc_82224F98;
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lwz r30,84(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lfs f13,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// fsubs f2,f0,f13
	ctx.f2.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f0,76(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r7,60(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r6,64(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// fsubs f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 - ctx.f0.f64));
	// bl 0x82225978
	ctx.lr = 0x82224F64;
	sub_82225978(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x8273a030
	ctx.lr = 0x82224F74;
	sub_8273A030(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82224f98
	if (ctx.cr6.eq) goto loc_82224F98;
loc_82224F80:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// bl 0x82225aa0
	ctx.lr = 0x82224F8C;
	sub_82225AA0(ctx, base);
	// lwz r5,0(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// cmplw cr6,r5,r30
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82224f80
	if (!ctx.cr6.eq) goto loc_82224F80;
loc_82224F98:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8222C0E8) {
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
	// lwz r3,132(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// bl 0x824443c8
	ctx.lr = 0x8222C104;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8222c13c
	if (ctx.cr0.eq) goto loc_8222C13C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x8222C114;
	sub_82430A88(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8222C13C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8222C13C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82240088
	ctx.lr = 0x8222C144;
	sub_82240088(ctx, base);
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

DEFINE_REX_FUNC(sub_82230010) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82230018;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x82230aa8
	ctx.lr = 0x8223003C;
	sub_82230AA8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223007c
	if (ctx.cr0.eq) goto loc_8223007C;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82230054
	if (!ctx.cr6.eq) goto loc_82230054;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// b 0x82230060
	goto loc_82230060;
loc_82230054:
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// bne cr6,0x8223007c
	if (!ctx.cr6.eq) goto loc_8223007C;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
loc_82230060:
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8223007C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8223007C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82233998) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82232628
	ctx.lr = 0x822339B8;
	sub_82232628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82233a08
	if (!ctx.cr0.eq) goto loc_82233A08;
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82233a08
	if (ctx.cr0.eq) goto loc_82233A08;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822339FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82233a20
	ctx.lr = 0x82233A08;
	sub_82233A20(ctx, base);
loc_82233A08:
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

DEFINE_REX_FUNC(sub_8223B2D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8223B2D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// stw r30,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r28,r11,22072
	ctx.r28.s64 = ctx.r11.s64 + 22072;
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// li r4,24
	ctx.r4.s64 = 24;
	// stw r30,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// stw r30,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r30.u32);
	// lwz r3,44(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8223B314;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8223b320
	if (ctx.cr0.eq) goto loc_8223B320;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
loc_8223B320:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223b32c
	if (ctx.cr0.eq) goto loc_8223B32C;
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_8223B32C:
	// addic. r11,r3,8
	ctx.xer.ca = ctx.r3.u32 > 4294967287;
	ctx.r11.s64 = ctx.r3.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223b338
	if (ctx.cr0.eq) goto loc_8223B338;
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_8223B338:
	// li r29,1
	ctx.r29.s64 = 1;
	// stb r30,21(r3)
	REX_STORE_U8(ctx.r3.u32 + 21, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r29,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r29.u8);
	// li r4,24
	ctx.r4.s64 = 24;
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// stb r29,21(r3)
	REX_STORE_U8(ctx.r3.u32 + 21, ctx.r29.u8);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// stw r11,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r11.u32);
	// stw r30,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// lwz r3,44(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8223B378;
	sub_825E02A0(ctx, base);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223b384
	if (ctx.cr0.eq) goto loc_8223B384;
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_8223B384:
	// addic. r10,r11,4
	ctx.xer.ca = ctx.r11.u32 > 4294967291;
	ctx.r10.s64 = ctx.r11.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8223b390
	if (ctx.cr0.eq) goto loc_8223B390;
	// stw r30,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r30.u32);
loc_8223B390:
	// addic. r10,r11,8
	ctx.xer.ca = ctx.r11.u32 > 4294967287;
	ctx.r10.s64 = ctx.r11.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8223b39c
	if (ctx.cr0.eq) goto loc_8223B39C;
	// stw r30,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r30.u32);
loc_8223B39C:
	// stb r29,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r29.u8);
	// addi r3,r31,56
	ctx.r3.s64 = ctx.r31.s64 + 56;
	// stb r30,21(r11)
	REX_STORE_U8(ctx.r11.u32 + 21, ctx.r30.u8);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// stb r29,21(r11)
	REX_STORE_U8(ctx.r11.u32 + 21, ctx.r29.u8);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// stw r11,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r11.u32);
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// bl 0x822230e8
	ctx.lr = 0x8223B3D0;
	sub_822230E8(ctx, base);
	// stw r30,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// stw r30,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// addi r3,r31,92
	ctx.r3.s64 = ctx.r31.s64 + 92;
	// stw r30,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// bl 0x822230e8
	ctx.lr = 0x8223B3E4;
	sub_822230E8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,24
	ctx.r4.s64 = 24;
	// lwz r3,44(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8223B3F4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8223b400
	if (ctx.cr0.eq) goto loc_8223B400;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
loc_8223B400:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223b40c
	if (ctx.cr0.eq) goto loc_8223B40C;
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_8223B40C:
	// addic. r11,r3,8
	ctx.xer.ca = ctx.r3.u32 > 4294967287;
	ctx.r11.s64 = ctx.r3.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8223b418
	if (ctx.cr0.eq) goto loc_8223B418;
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_8223B418:
	// stb r29,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r29.u8);
	// stb r30,21(r3)
	REX_STORE_U8(ctx.r3.u32 + 21, ctx.r30.u8);
	// stw r3,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r3.u32);
	// stb r29,21(r3)
	REX_STORE_U8(ctx.r3.u32 + 21, ctx.r29.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// stw r11,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// stw r11,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// stw r11,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r11.u32);
	// stw r30,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// stw r30,668(r31)
	REX_STORE_U32(ctx.r31.u32 + 668, ctx.r30.u32);
	// stw r30,672(r31)
	REX_STORE_U32(ctx.r31.u32 + 672, ctx.r30.u32);
	// stw r30,676(r31)
	REX_STORE_U32(ctx.r31.u32 + 676, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82249368) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82249370;
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
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,188
	ctx.r4.s64 = 188;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82249398;
	sub_825E02A0(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822493b0
	if (ctx.cr0.eq) goto loc_822493B0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x823bdc58
	ctx.lr = 0x822493AC;
	sub_823BDC58(ctx, base);
	// b 0x822493b4
	goto loc_822493B4;
loc_822493B0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_822493B4:
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x822493cc
	if (!ctx.cr6.eq) goto loc_822493CC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82249308
	ctx.lr = 0x822493C8;
	sub_82249308(ctx, base);
	// b 0x822493fc
	goto loc_822493FC;
loc_822493CC:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stw r29,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r29.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r29,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r29.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r11,86(r3)
	REX_STORE_U16(ctx.r3.u32 + 86, ctx.r11.u16);
	// stb r9,28(r3)
	REX_STORE_U8(ctx.r3.u32 + 28, ctx.r9.u8);
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
	// stfs f0,108(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stfs f0,104(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// sth r28,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r28.u16);
loc_822493FC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8224B7B0) {
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
	// bl 0x8224c078
	ctx.lr = 0x8224B7CC;
	sub_8224C078(ctx, base);
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// li r3,-16
	ctx.r3.s64 = -16;
	// bl 0x825a49b0
	ctx.lr = 0x8224B7E0;
	sub_825A49B0(ctx, base);
	// stw r3,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r3.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,140(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// lfs f0,3188(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 3188);
	ctx.f0.f64 = double(temp.f32);
	// fadds f2,f13,f0
	ctx.f2.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// fsubs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// bl 0x825a4a40
	ctx.lr = 0x8224B804;
	sub_825A4A40(ctx, base);
	// lbz r11,144(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 144);
	// stfs f1,136(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 136, temp.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mulli r10,r11,28
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(28));
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r10,52(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 52);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8224b840
	if (ctx.cr6.eq) goto loc_8224B840;
	// stb r11,144(r31)
	REX_STORE_U8(ctx.r31.u32 + 144, ctx.r11.u8);
loc_8224B840:
	// lbz r11,145(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 145);
	// li r10,0
	ctx.r10.s64 = 0;
loc_8224B848:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// addi r9,r11,27
	ctx.r9.s64 = ctx.r11.s64 + 27;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8224b888
	if (!ctx.cr6.eq) goto loc_8224B888;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// blt cr6,0x8224b848
	if (ctx.cr6.lt) goto loc_8224B848;
	// b 0x8224b88c
	goto loc_8224B88C;
loc_8224B888:
	// stb r11,145(r31)
	REX_STORE_U8(ctx.r31.u32 + 145, ctx.r11.u8);
loc_8224B88C:
	// lbz r11,145(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 145);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x8224b8f4
	if (ctx.cr6.eq) goto loc_8224B8F4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8224c2b0
	ctx.lr = 0x8224B8A0;
	sub_8224C2B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8224b8f4
	if (!ctx.cr0.eq) goto loc_8224B8F4;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x825a4a90
	ctx.lr = 0x8224B8B8;
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
	ctx.lr = 0x8224B8CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r3,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3FFFFFFF;
	// li r10,100
	ctx.r10.s64 = 100;
	// divwu r10,r11,r10
	ctx.r10.u64 = uint32_t(ctx.r10.u32 ? ctx.r11.u32 / ctx.r10.u32 : 0);
	// mulli r10,r10,100
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(100));
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// bge cr6,0x8224b8f4
	if (!ctx.cr6.lt) goto loc_8224B8F4;
	// lis r11,-32219
	ctx.r11.s64 = -2111504384;
	// addi r11,r11,-17240
	ctx.r11.s64 = ctx.r11.s64 + -17240;
	// b 0x8224b8fc
	goto loc_8224B8FC;
loc_8224B8F4:
	// lis r11,-32219
	ctx.r11.s64 = -2111504384;
	// addi r11,r11,-18136
	ctx.r11.s64 = ctx.r11.s64 + -18136;
loc_8224B8FC:
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// stb r10,128(r31)
	REX_STORE_U8(ctx.r31.u32 + 128, ctx.r10.u8);
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

DEFINE_REX_FUNC(sub_8225DDB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8225DDC0;
	__savegprlr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x824281d8
	ctx.lr = 0x8225DDCC;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8225dfcc
	if (ctx.cr0.eq) goto loc_8225DFCC;
	// bl 0x8242a5e0
	ctx.lr = 0x8225DDD8;
	sub_8242A5E0(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8225ddec
	if (!ctx.cr0.eq) goto loc_8225DDEC;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// b 0x8225ddf0
	goto loc_8225DDF0;
loc_8225DDEC:
	// bl 0x8242aa28
	ctx.lr = 0x8225DDF0;
	sub_8242AA28(ctx, base);
loc_8225DDF0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8225dfcc
	if (!ctx.cr0.eq) goto loc_8225DFCC;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3072
	ctx.r30.s64 = ctx.r30.s64 + -3072;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8225de14
	if (ctx.cr0.eq) goto loc_8225DE14;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8225DE14;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8225DE14:
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r28,r28,-3100
	ctx.r28.s64 = ctx.r28.s64 + -3100;
	// li r5,28
	ctx.r5.s64 = 28;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x8273a030
	ctx.lr = 0x8225DE2C;
	sub_8273A030(ctx, base);
	// stb r29,0(r28)
	REX_STORE_U8(ctx.r28.u32 + 0, ctx.r29.u8);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8225de44
	if (ctx.cr0.eq) goto loc_8225DE44;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8225DE44;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8225DE44:
	// lbz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r28,r10,62380
	ctx.r28.u64 = ctx.r10.u64 | 62380;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8225df4c
	if (ctx.cr0.eq) goto loc_8225DF4C;
	// lbz r3,121(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + 121);
	// bl 0x824299b8
	ctx.lr = 0x8225DE60;
	sub_824299B8(ctx, base);
	// lwz r11,124(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lwz r10,136(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// rlwinm r7,r11,16,16,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF;
	// lwz r6,116(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r4,r10,16,16,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF;
	// lbz r5,120(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 120);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// std r7,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r6,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// addi r10,r9,14280
	ctx.r10.s64 = ctx.r9.s64 + 14280;
	// fcfid f7,f0
	ctx.f7.f64 = double(ctx.f0.s64);
	// lfs f13,-8644(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -8644);
	ctx.f13.f64 = double(temp.f32);
	// frsp f8,f12
	ctx.f8.f64 = double(float(ctx.f12.f64));
	// lfs f12,-2044(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2044);
	ctx.f12.f64 = double(temp.f32);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// lis r11,0
	ctx.r11.s64 = 0;
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// lfs f0,14280(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14280);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r8,132(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// stw r3,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// ori r11,r11,62588
	ctx.r11.u64 = ctx.r11.u64 | 62588;
	// stwx r5,r31,r28
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, ctx.r5.u32);
	// ori r10,r10,62780
	ctx.r10.u64 = ctx.r10.u64 | 62780;
	// addi r9,r9,-2720
	ctx.r9.s64 = ctx.r9.s64 + -2720;
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// fnmsubs f13,f8,f13,f12
	ctx.f13.f64 = double(float(-std::fma(ctx.f8.f64, ctx.f13.f64, -ctx.f12.f64)));
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// frsp f12,f7
	ctx.f12.f64 = double(float(ctx.f7.f64));
	// addi r7,r7,-2772
	ctx.r7.s64 = ctx.r7.s64 + -2772;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// stwx r8,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u32);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// stfsx f13,r31,r11
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// fmuls f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f13,4(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fmuls f13,f11,f0
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fmuls f13,f10,f0
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f13,0(r7)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fmuls f0,f9,f0
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
loc_8225DF4C:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3028
	ctx.r30.s64 = ctx.r30.s64 + -3028;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8225df68
	if (ctx.cr0.eq) goto loc_8225DF68;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8225DF68;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8225DF68:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3040
	ctx.r11.s64 = ctx.r11.s64 + -3040;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stb r29,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r29.u8);
	// lbz r8,28(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r29,4(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// beq 0x8225df9c
	if (ctx.cr0.eq) goto loc_8225DF9C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8225DF9C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8225DF9C:
	// lbz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 88);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8225dfcc
	if (ctx.cr0.eq) goto loc_8225DFCC;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lbz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r11,r11,62772
	ctx.r11.u64 = ctx.r11.u64 | 62772;
	// ori r9,r9,62384
	ctx.r9.u64 = ctx.r9.u64 | 62384;
	// li r8,1
	ctx.r8.s64 = 1;
	// stwx r10,r31,r28
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, ctx.r10.u32);
	// stwx r29,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r29.u32);
	// stbx r8,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r8.u8);
loc_8225DFCC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82272970) {
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
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// ori r11,r11,63400
	ctx.r11.u64 = ctx.r11.u64 | 63400;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f31,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// lbzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r11.u32);
	// stfs f31,128(r3)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822729d8
	if (!ctx.cr0.eq) goto loc_822729D8;
	// bl 0x824281d8
	ctx.lr = 0x822729AC;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822729d8
	if (ctx.cr0.eq) goto loc_822729D8;
	// bl 0x82444358
	ctx.lr = 0x822729B8;
	sub_82444358(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r11,r11,63276
	ctx.r11.u64 = ctx.r11.u64 | 63276;
	// li r4,4
	ctx.r4.s64 = 4;
	// stwx r3,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8227a0c8
	ctx.lr = 0x822729D4;
	sub_8227A0C8(ctx, base);
	// b 0x822729f4
	goto loc_822729F4;
loc_822729D8:
	// bl 0x824281d8
	ctx.lr = 0x822729DC;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822729f4
	if (!ctx.cr0.eq) goto loc_822729F4;
	// bl 0x82444358
	ctx.lr = 0x822729E8;
	sub_82444358(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,63276
	ctx.r11.u64 = ctx.r11.u64 | 63276;
	// stwx r3,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u32);
loc_822729F4:
	// li r6,1
	ctx.r6.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8226f4b8
	ctx.lr = 0x82272A08;
	sub_8226F4B8(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r11,63096
	ctx.r9.u64 = ctx.r11.u64 | 63096;
	// ori r10,r10,63112
	ctx.r10.u64 = ctx.r10.u64 | 63112;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r8,255
	ctx.r8.s64 = 255;
	// stb r11,466(r31)
	REX_STORE_U8(ctx.r31.u32 + 466, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r11,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u8);
	// sthx r8,r31,r10
	REX_STORE_U16(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u16);
	// bl 0x82237858
	ctx.lr = 0x82272A34;
	sub_82237858(ctx, base);
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82272a84
	if (ctx.cr6.eq) goto loc_82272A84;
	// bl 0x82213210
	ctx.lr = 0x82272A44;
	sub_82213210(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r31,r3,4120
	ctx.r31.s64 = ctx.r3.s64 + 4120;
	// addi r3,r11,4072
	ctx.r3.s64 = ctx.r11.s64 + 4072;
	// bl 0x8223bb20
	ctx.lr = 0x82272A54;
	sub_8223BB20(ctx, base);
	// cmplwi cr6,r3,256
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 256, ctx.xer);
	// bge cr6,0x82272a84
	if (!ctx.cr6.lt) goto loc_82272A84;
	// addi r11,r3,3520
	ctx.r11.s64 = ctx.r3.s64 + 3520;
	// lis r10,15
	ctx.r10.s64 = 983040;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r9,r10,16959
	ctx.r9.u64 = ctx.r10.u64 | 16959;
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x82272a84
	if (!ctx.cr6.gt) goto loc_82272A84;
	// stwx r9,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r9.u32);
loc_82272A84:
	// bl 0x82213210
	ctx.lr = 0x82272A88;
	sub_82213210(ctx, base);
	// lbz r11,4036(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4036);
	// li r3,12
	ctx.r3.s64 = 12;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82272a9c
	if (!ctx.cr0.eq) goto loc_82272A9C;
	// li r3,6
	ctx.r3.s64 = 6;
loc_82272A9C:
	// bl 0x82217158
	ctx.lr = 0x82272AA0;
	sub_82217158(ctx, base);
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

DEFINE_REX_FUNC(sub_8227C608) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8227C610;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r8,r3,1
	ctx.r8.s64 = ctx.r3.s64 + 65536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r8,r8,-3032
	ctx.r8.s64 = ctx.r8.s64 + -3032;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8227c674
	if (ctx.cr6.eq) goto loc_8227C674;
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
	// bne cr6,0x8227c670
	if (!ctx.cr6.eq) goto loc_8227C670;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8227c670
	if (ctx.cr6.eq) goto loc_8227C670;
	// lbz r10,23(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8227c670
	if (!ctx.cr0.eq) goto loc_8227C670;
	// stb r7,23(r11)
	REX_STORE_U8(ctx.r11.u32 + 23, ctx.r7.u8);
loc_8227C670:
	// stw r29,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r29.u32);
loc_8227C674:
	// addis r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 65536;
	// addi r10,r10,-3040
	ctx.r10.s64 = ctx.r10.s64 + -3040;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8227c69c
	if (ctx.cr6.eq) goto loc_8227C69C;
	// lbz r9,23(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x8227c69c
	if (!ctx.cr0.eq) goto loc_8227C69C;
	// stb r7,23(r11)
	REX_STORE_U8(ctx.r11.u32 + 23, ctx.r7.u8);
	// stw r29,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r29.u32);
loc_8227C69C:
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// addi r31,r31,-3024
	ctx.r31.s64 = ctx.r31.s64 + -3024;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8227c6c8
	if (ctx.cr6.eq) goto loc_8227C6C8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227C6C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_8227C6C8:
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// addi r31,r31,-3028
	ctx.r31.s64 = ctx.r31.s64 + -3028;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8227c6f4
	if (ctx.cr6.eq) goto loc_8227C6F4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8227C6F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_8227C6F4:
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// addi r31,r31,-3048
	ctx.r31.s64 = ctx.r31.s64 + -3048;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8227c720
	if (ctx.cr6.eq) goto loc_8227C720;
	// bl 0x823bb108
	ctx.lr = 0x8227C70C;
	sub_823BB108(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8227c71c
	if (ctx.cr6.eq) goto loc_8227C71C;
	// bl 0x8227c728
	ctx.lr = 0x8227C71C;
	sub_8227C728(ctx, base);
loc_8227C71C:
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_8227C720:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82289980) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82289988;
	__savegprlr_25(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r26,r3,1
	ctx.r26.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r26,r26,440
	ctx.r26.s64 = ctx.r26.s64 + 440;
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,0(r26)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// bl 0x8242a5e0
	ctx.lr = 0x822899A8;
	sub_8242A5E0(ctx, base);
	// li r27,0
	ctx.r27.s64 = 0;
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822899bc
	if (!ctx.cr0.eq) goto loc_822899BC;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// b 0x822899c0
	goto loc_822899C0;
loc_822899BC:
	// bl 0x8242aa28
	ctx.lr = 0x822899C0;
	sub_8242AA28(ctx, base);
loc_822899C0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82289c90
	if (!ctx.cr0.eq) goto loc_82289C90;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r25,r11,12468
	ctx.r25.s64 = ctx.r11.s64 + 12468;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lfs f11,-232(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -232);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x82289b74
	if (!ctx.cr6.gt) goto loc_82289B74;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// addi r8,r8,400
	ctx.r8.s64 = ctx.r8.s64 + 400;
	// ori r11,r11,388
	ctx.r11.u64 = ctx.r11.u64 | 388;
	// ori r10,r10,389
	ctx.r10.u64 = ctx.r10.u64 | 389;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ld r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r8.u32 + 0);
	// lbzx r7,r31,r11
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// lbzx r28,r31,r10
	ctx.r28.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r10.u32);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// bl 0x8225f588
	ctx.lr = 0x82289A10;
	sub_8225F588(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82289b64
	if (ctx.cr0.eq) goto loc_82289B64;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r5,-32111
	ctx.r5.s64 = -2104426496;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r30,-3048
	ctx.r30.s64 = ctx.r30.s64 + -3048;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,1
	ctx.r6.s64 = 65536;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// ori r6,r6,392
	ctx.r6.u64 = ctx.r6.u64 | 392;
	// stfs f0,88(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 88, temp.u32);
	// ld r11,3456(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// std r11,0(r8)
	REX_STORE_U64(ctx.r8.u32 + 0, ctx.r11.u64);
	// clrlwi. r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ld r11,2880(r5)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r5.u32 + 2880);
	// li r29,1
	ctx.r29.s64 = 1;
	// stdx r11,r31,r6
	REX_STORE_U64(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u64);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// beq 0x82289ab8
	if (ctx.cr0.eq) goto loc_82289AB8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82289b04
	if (!ctx.cr6.eq) goto loc_82289B04;
	// stw r27,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r27.u32);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82289b04
	if (ctx.cr0.eq) goto loc_82289B04;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82289aec
	goto loc_82289AEC;
loc_82289AB8:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x82289b04
	if (!ctx.cr6.eq) goto loc_82289B04;
	// stw r29,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r29.u32);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82289b04
	if (ctx.cr0.eq) goto loc_82289B04;
	// li r4,2
	ctx.r4.s64 = 2;
loc_82289AEC:
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
	ctx.lr = 0x82289B04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82289B04:
	// clrlwi. r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// beq 0x82289b30
	if (ctx.cr0.eq) goto loc_82289B30;
	// stb r29,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r29.u8);
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82289b64
	if (ctx.cr0.eq) goto loc_82289B64;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82289b4c
	goto loc_82289B4C;
loc_82289B30:
	// stb r27,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r27.u8);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r10,268(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82289b64
	if (ctx.cr0.eq) goto loc_82289B64;
	// li r4,1
	ctx.r4.s64 = 1;
loc_82289B4C:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82289B64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82289B64:
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stfs f0,0(r26)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// b 0x82289c94
	goto loc_82289C94;
loc_82289B74:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// ori r11,r11,400
	ctx.r11.u64 = ctx.r11.u64 | 400;
	// addi r30,r30,392
	ctx.r30.s64 = ctx.r30.s64 + 392;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// ldx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + ctx.r11.u32);
	// ld r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// bl 0x8225f588
	ctx.lr = 0x82289B98;
	sub_8225F588(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82289c90
	if (ctx.cr0.eq) goto loc_82289C90;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82239588
	ctx.lr = 0x82289BA8;
	sub_82239588(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82289bcc
	if (ctx.cr0.eq) goto loc_82289BCC;
	// addi r5,r31,88
	ctx.r5.s64 = ctx.r31.s64 + 88;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82322d08
	ctx.lr = 0x82289BC0;
	sub_82322D08(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
loc_82289BCC:
	// lfs f12,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x82289be0
	if (!ctx.cr6.lt) goto loc_82289BE0;
	// fmr f12,f0
	ctx.f12.f64 = ctx.f0.f64;
loc_82289BE0:
	// fcmpu cr6,f12,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// ble cr6,0x82289bec
	if (!ctx.cr6.gt) goto loc_82289BEC;
	// fmr f12,f11
	ctx.f12.f64 = ctx.f11.f64;
loc_82289BEC:
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// fsubs f0,f11,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// bl 0x82322d08
	ctx.lr = 0x82289C80;
	sub_82322D08(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
loc_82289C90:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82289C94:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822A4F00) {
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
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r8,3
	ctx.r8.s64 = 3;
	// ld r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r7,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// li r4,100
	ctx.r4.s64 = 100;
	// lfs f0,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14280(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14280);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x822A4F60;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822a4f90
	if (ctx.cr0.eq) goto loc_822A4F90;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f0,-4740(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4740);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1072(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1072);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x82218490
	ctx.lr = 0x822A4F88;
	sub_82218490(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x822a4f94
	goto loc_822A4F94;
loc_822A4F90:
	// li r31,0
	ctx.r31.s64 = 0;
loc_822A4F94:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822a4ff0
	if (ctx.cr6.eq) goto loc_822A4FF0;
	// lis r11,-32222
	ctx.r11.s64 = -2111700992;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r11,r11,-31312
	ctx.r11.s64 = ctx.r11.s64 + -31312;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// lwz r11,56(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822A4FC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x822A4FCC;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822a4ff0
	if (!ctx.cr6.eq) goto loc_822A4FF0;
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
	ctx.lr = 0x822A4FF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822A4FF0:
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

DEFINE_REX_FUNC(sub_822AA7A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x822AA7A8;
	__savegprlr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x823bfa70
	ctx.lr = 0x822AA7C4;
	sub_823BFA70(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822AA7EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq 0x822aa9e4
	if (ctx.cr0.eq) goto loc_822AA9E4;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r29,r29,-3092
	ctx.r29.s64 = ctx.r29.s64 + -3092;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222c98
	ctx.lr = 0x822AA80C;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822aa81c
	if (!ctx.cr0.eq) goto loc_822AA81C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x822afde8
	ctx.lr = 0x822AA81C;
	sub_822AFDE8(ctx, base);
loc_822AA81C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222d88
	ctx.lr = 0x822AA82C;
	sub_82222D88(ctx, base);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r29,r29,-3144
	ctx.r29.s64 = ctx.r29.s64 + -3144;
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// bne 0x822aa848
	if (!ctx.cr0.eq) goto loc_822AA848;
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
loc_822AA848:
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwa r9,116(r1)
	ctx.r9.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 116));
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f0,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
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
	// lfs f0,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfs f11,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fadds f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fadds f0,f13,f12
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82225838
	ctx.lr = 0x822AA8D8;
	sub_82225838(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822AA8FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq 0x822aa9fc
	if (ctx.cr0.eq) goto loc_822AA9FC;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3088
	ctx.r30.s64 = ctx.r30.s64 + -3088;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222c98
	ctx.lr = 0x822AA91C;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822aa92c
	if (!ctx.cr0.eq) goto loc_822AA92C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822afde8
	ctx.lr = 0x822AA92C;
	sub_822AFDE8(ctx, base);
loc_822AA92C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222d88
	ctx.lr = 0x822AA93C;
	sub_82222D88(ctx, base);
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// bne 0x822aa950
	if (!ctx.cr0.eq) goto loc_822AA950;
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
loc_822AA950:
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwa r9,116(r1)
	ctx.r9.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 116));
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f12,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfs f11,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82225838
	ctx.lr = 0x822AA9E0;
	sub_82225838(ctx, base);
	// b 0x822aaa10
	goto loc_822AAA10;
loc_822AA9E4:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62444
	ctx.r11.u64 = ctx.r11.u64 | 62444;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x822AA9F8;
	sub_82222BB0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
loc_822AA9FC:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62448
	ctx.r11.u64 = ctx.r11.u64 | 62448;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x822AAA10;
	sub_82222BB0(ctx, base);
loc_822AAA10:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822C28F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x822C2900;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r30,r11,14280
	ctx.r30.s64 = ctx.r11.s64 + 14280;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f31,-2044(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2044);
	ctx.f31.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C2934;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x822c2940
	if (!ctx.cr0.eq) goto loc_822C2940;
	// lfs f31,-1808(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -1808);
	ctx.f31.f64 = double(temp.f32);
loc_822C2940:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f2,-1812(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -1812);
	ctx.f2.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f1,30752(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30752);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822C2954;
	sub_825A4A40(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// bl 0x82738be0
	ctx.lr = 0x822C295C;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x822C2978;
	sub_82738CC0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
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
	// li r4,212
	ctx.r4.s64 = 212;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r3,48(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 48);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x822C29D8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822c29f0
	if (ctx.cr0.eq) goto loc_822C29F0;
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x822c35c0
	ctx.lr = 0x822C29E8;
	sub_822C35C0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x822c29f4
	goto loc_822C29F4;
loc_822C29F0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_822C29F4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822c2b60
	if (ctx.cr6.eq) goto loc_822C2B60;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,100
	ctx.r4.s64 = 100;
	// li r3,-100
	ctx.r3.s64 = -100;
	// bl 0x825a49b0
	ctx.lr = 0x822C2A0C;
	sub_825A49B0(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lfs f31,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r4,100
	ctx.r4.s64 = 100;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// li r3,-100
	ctx.r3.s64 = -100;
	// fmuls f30,f0,f31
	ctx.f30.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x825a49b0
	ctx.lr = 0x822C2A38;
	sub_825A49B0(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// li r6,0
	ctx.r6.s64 = 0;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r5,0
	ctx.r5.s64 = 0;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmuls f31,f0,f31
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x8222ff78
	ctx.lr = 0x822C2A64;
	sub_8222FF78(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r9,r9,-31120
	ctx.r9.s64 = ctx.r9.s64 + -31120;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x822C2AC8;
	sub_8222FF78(ctx, base);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f30,128(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f30,140(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f30,136(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f30,132(r1)
	temp.f32 = float(ctx.f30.f64);
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
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C2B30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x822C2B3C;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822c2b60
	if (!ctx.cr6.eq) goto loc_822C2B60;
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
	ctx.lr = 0x822C2B60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822C2B60:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822D1B88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,62412
	ctx.r11.u64 = ctx.r11.u64 | 62412;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// ori r10,r10,62396
	ctx.r10.u64 = ctx.r10.u64 | 62396;
	// lbzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r11.u32);
	// lfs f13,12236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12236);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfsx f13,r3,r10
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + ctx.r10.u32, temp.u32);
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// bne 0x822d1c2c
	if (!ctx.cr0.eq) goto loc_822D1C2C;
	// addi r11,r11,-3152
	ctx.r11.s64 = ctx.r11.s64 + -3152;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,92(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// addi r9,r11,32640
	ctx.r9.s64 = ctx.r11.s64 + 32640;
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x822d1c40
	goto loc_822D1C40;
loc_822D1C2C:
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r10,5
	ctx.r10.s64 = 5;
loc_822D1C40:
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822D5F78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x822D5F80;
	__savegprlr_25(ctx, base);
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f29.u64);
	// stfd f30,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addis r27,r3,1
	ctx.r27.s64 = ctx.r3.s64 + 65536;
	// addi r10,r10,-3120
	ctx.r10.s64 = ctx.r10.s64 + -3120;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r27,r27,-3108
	ctx.r27.s64 = ctx.r27.s64 + -3108;
	// addi r25,r11,12236
	ctx.r25.s64 = ctx.r11.s64 + 12236;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2852(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 2852);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,0(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bgt cr6,0x822d645c
	if (ctx.cr6.gt) goto loc_822D645C;
	// addis r26,r3,1
	ctx.r26.s64 = ctx.r3.s64 + 65536;
	// addi r26,r26,-3156
	ctx.r26.s64 = ctx.r26.s64 + -3156;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// beq cr6,0x822d647c
	if (ctx.cr6.eq) goto loc_822D647C;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x822d6684
	if (!ctx.cr6.eq) goto loc_822D6684;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x8222ff78
	ctx.lr = 0x822D6004;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,232
	ctx.r3.s64 = ctx.r1.s64 + 232;
	// lfs f30,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x822D6020;
	sub_8222FF78(ctx, base);
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r11,-13032(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822d6060
	if (ctx.cr6.eq) goto loc_822D6060;
	// fctiwz f13,f30
	ctx.f13.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aebd8
	ctx.lr = 0x822D605C;
	sub_823AEBD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_822D6060:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8222ff78
	ctx.lr = 0x822D6074;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lfs f30,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x822D6090;
	sub_8222FF78(ctx, base);
	// lwz r11,-13032(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -13032);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822d60c8
	if (ctx.cr6.eq) goto loc_822D60C8;
	// fctiwz f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823af008
	ctx.lr = 0x822D60C4;
	sub_823AF008(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_822D60C8:
	// rlwinm. r11,r10,0,24,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xC0;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// ori r11,r11,62420
	ctx.r11.u64 = ctx.r11.u64 | 62420;
	// addi r29,r29,-3128
	ctx.r29.s64 = ctx.r29.s64 + -3128;
	// beq 0x822d6138
	if (ctx.cr0.eq) goto loc_822D6138;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfsx f13,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r11,r8,-32512
	ctx.r11.s64 = ctx.r8.s64 + -32512;
	// stfs f0,84(r1)
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822d6174
	goto loc_822D6174;
loc_822D6138:
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfsx f0,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822D6174:
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// lfs f30,232(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 232);
	ctx.f30.f64 = double(temp.f32);
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// beq cr6,0x822d622c
	if (ctx.cr6.eq) goto loc_822D622C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8222ff78
	ctx.lr = 0x822D619C;
	sub_8222FF78(ctx, base);
	// extsw r11,r28
	ctx.r11.s64 = ctx.r28.s32;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// li r5,0
	ctx.r5.s64 = 0;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// fadds f29,f0,f13
	ctx.f29.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x8222ff78
	ctx.lr = 0x822D61CC;
	sub_8222FF78(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f29,96(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f29,100(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f29,108(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f29,104(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,88(r31)
	REX_STORE_U64(ctx.r31.u32 + 88, ctx.r11.u64);
	// b 0x822d623c
	goto loc_822D623C;
loc_822D622C:
	// li r11,9
	ctx.r11.s64 = 9;
	// stfs f30,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// stfs f30,132(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_822D623C:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bgt cr6,0x822d6274
	if (ctx.cr6.gt) goto loc_822D6274;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D6274:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// beq 0x822d6344
	if (ctx.cr0.eq) goto loc_822D6344;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8222ff78
	ctx.lr = 0x822D6290;
	sub_8222FF78(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r29,r10,32432
	ctx.r29.s64 = ctx.r10.s64 + 32432;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
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
	// bl 0x8222ff78
	ctx.lr = 0x822D62D8;
	sub_8222FF78(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,-13032(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -13032);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822d63fc
	if (ctx.cr6.eq) goto loc_822D63FC;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823ae578
	ctx.lr = 0x822D6340;
	sub_823AE578(ctx, base);
	// b 0x822d63fc
	goto loc_822D63FC;
loc_822D6344:
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x8222ff78
	ctx.lr = 0x822D634C;
	sub_8222FF78(ctx, base);
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
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r29,r10,32432
	ctx.r29.s64 = ctx.r10.s64 + 32432;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
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
	// bl 0x8222ff78
	ctx.lr = 0x822D6394;
	sub_8222FF78(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
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
	// lwz r11,-13032(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -13032);
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,0
	ctx.r3.s64 = 0;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822d63fc
	if (ctx.cr6.eq) goto loc_822D63FC;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823ae2c0
	ctx.lr = 0x822D63FC;
	sub_823AE2C0(ctx, base);
loc_822D63FC:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r30,-3100
	ctx.r30.s64 = ctx.r30.s64 + -3100;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x822d6454
	if (!ctx.cr6.lt) goto loc_822D6454;
	// lfs f2,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f1,2140(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 2140);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822D642C;
	sub_825A4A40(ctx, base);
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// bl 0x8222ff78
	ctx.lr = 0x822D6444;
	sub_8222FF78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,175
	ctx.r3.s64 = 175;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8257d438
	ctx.lr = 0x822D6454;
	sub_8257D438(ctx, base);
loc_822D6454:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x822d6684
	if (ctx.cr6.eq) goto loc_822D6684;
loc_822D645C:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d6684
	if (!ctx.cr6.eq) goto loc_822D6684;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x822d6684
	goto loc_822D6684;
loc_822D647C:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f11,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 232);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r10,r11,27412
	ctx.r10.s64 = ctx.r11.s64 + 27412;
	// lfs f9,132(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 132);
	ctx.f9.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f31,2140(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 2140);
	ctx.f31.f64 = double(temp.f32);
	// stfs f9,124(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f12,27412(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27412);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f13,-9032(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9032);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f12,f10,f12
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmadds f0,f0,f31,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f12.f64)));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// bl 0x8222ff78
	ctx.lr = 0x822D6508;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// lfs f30,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x822D6524;
	sub_8222FF78(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822d6684
	if (ctx.cr6.eq) goto loc_822D6684;
	// fctiwz f13,f30
	ctx.f13.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aebd8
	ctx.lr = 0x822D655C;
	sub_823AEBD8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x822d6684
	if (ctx.cr0.eq) goto loc_822D6684;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// bl 0x8222ff78
	ctx.lr = 0x822D6580;
	sub_8222FF78(ctx, base);
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// li r5,0
	ctx.r5.s64 = 0;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// fadds f30,f0,f13
	ctx.f30.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x8222ff78
	ctx.lr = 0x822D65B0;
	sub_8222FF78(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f30,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f30,88(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stfs f30,80(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r7,-30128
	ctx.r5.s64 = ctx.r7.s64 + -30128;
	// stfs f30,84(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r3,-32224
	ctx.r3.s64 = -2111832064;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ori r6,r6,62420
	ctx.r6.u64 = ctx.r6.u64 | 62420;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f0,-10784(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -10784);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r3,-30848
	ctx.r5.s64 = ctx.r3.s64 + -30848;
	// stfsx f0,r31,r6
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,-30128(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// lis r4,0
	ctx.r4.s64 = 0;
	// lfs f2,0(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// ori r4,r4,62408
	ctx.r4.u64 = ctx.r4.u64 | 62408;
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,88(r31)
	REX_STORE_U64(ctx.r31.u32 + 88, ctx.r11.u64);
	// stfs f0,132(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// lfsx f0,r31,r4
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r4.u32);
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4a40
	ctx.lr = 0x822D6680;
	sub_825A4A40(ctx, base);
	// stfs f1,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
loc_822D6684:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f30,-80(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82317C20) {
	REX_FUNC_PROLOGUE();
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62384
	ctx.r11.u64 = ctx.r11.u64 | 62384;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62392
	ctx.r11.u64 = ctx.r11.u64 | 62392;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62540
	ctx.r11.u64 = ctx.r11.u64 | 62540;
	// stbx r10,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r10.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8231BA00) {
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
	// addi r11,r11,15920
	ctx.r11.s64 = ctx.r11.s64 + 15920;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82231c80
	ctx.lr = 0x8231BA2C;
	sub_82231C80(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8231ba3c
	if (ctx.cr0.eq) goto loc_8231BA3C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8231BA3C;
	sub_825E0378(ctx, base);
loc_8231BA3C:
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

DEFINE_REX_FUNC(sub_8231E7F0) {
	REX_FUNC_PROLOGUE();
	// clrlwi. r11,r4,28
	ctx.r11.u64 = ctx.r4.u32 & 0xF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// bne 0x8231e810
	if (!ctx.cr0.eq) goto loc_8231E810;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62646
	ctx.r11.u64 = ctx.r11.u64 | 62646;
	// stbx r10,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r10.u8);
	// b 0x8231e824
	goto loc_8231E824;
loc_8231E810:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8231e824
	if (!ctx.cr6.eq) goto loc_8231E824;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62646
	ctx.r11.u64 = ctx.r11.u64 | 62646;
	// stbx r9,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r9.u8);
loc_8231E824:
	// rlwinm. r11,r4,28,28,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8231e83c
	if (!ctx.cr0.eq) goto loc_8231E83C;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62647
	ctx.r11.u64 = ctx.r11.u64 | 62647;
	// stbx r10,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r10.u8);
	// b 0x8231e850
	goto loc_8231E850;
loc_8231E83C:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8231e850
	if (!ctx.cr6.eq) goto loc_8231E850;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62647
	ctx.r11.u64 = ctx.r11.u64 | 62647;
	// stbx r9,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r9.u8);
loc_8231E850:
	// rlwinm. r11,r4,24,28,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8231e868
	if (!ctx.cr0.eq) goto loc_8231E868;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62648
	ctx.r11.u64 = ctx.r11.u64 | 62648;
	// stbx r10,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r10.u8);
	// blr 
	return;
loc_8231E868:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62648
	ctx.r11.u64 = ctx.r11.u64 | 62648;
	// stbx r9,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r9.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82322C60) {
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
	// bl 0x82429a18
	ctx.lr = 0x82322C80;
	sub_82429A18(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lhz r9,552(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 552);
	// clrlwi r10,r30,24
	ctx.r10.u64 = ctx.r30.u32 & 0xFF;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lfs f0,20068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20068);
	ctx.f0.f64 = double(temp.f32);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// ori r3,r6,62708
	ctx.r3.u64 = ctx.r6.u64 | 62708;
	// addic r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// addi r4,r4,-2852
	ctx.r4.s64 = ctx.r4.s64 + -2852;
	// ori r8,r8,62688
	ctx.r8.u64 = ctx.r8.u64 | 62688;
	// ori r7,r7,62692
	ctx.r7.u64 = ctx.r7.u64 | 62692;
	// subfe r11,r11,r10
	temp.u8 = (~ctx.r11.u32 + ctx.r10.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r10,4
	ctx.r10.s64 = 4;
	// stbx r11,r31,r3
	REX_STORE_U8(ctx.r31.u32 + ctx.r3.u32, ctx.r11.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// li r5,28
	ctx.r5.s64 = 28;
	// stbx r10,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r10.u8);
	// li r3,15
	ctx.r3.s64 = 15;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u32);
	// bl 0x82429ff8
	ctx.lr = 0x82322CEC;
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

DEFINE_REX_FUNC(sub_82329F68) {
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
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r11,21(r3)
	REX_STORE_U8(ctx.r3.u32 + 21, ctx.r11.u8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,68(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 68);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82329F98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
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
	ctx.lr = 0x82329FB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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
	ctx.lr = 0x82329FD0;
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
	ctx.lr = 0x82329FEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,108(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8232A008;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// ori r10,r10,62409
	ctx.r10.u64 = ctx.r10.u64 | 62409;
	// addi r11,r11,-3152
	ctx.r11.s64 = ctx.r11.s64 + -3152;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// stbx r5,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r5.u8);
	// ori r9,r9,62372
	ctx.r9.u64 = ctx.r9.u64 | 62372;
	// ori r8,r8,62380
	ctx.r8.u64 = ctx.r8.u64 | 62380;
	// lfs f0,12468(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lis r6,-32205
	ctx.r6.s64 = -2110586880;
	// addi r7,r6,-24472
	ctx.r7.s64 = ctx.r6.s64 + -24472;
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// stwx r7,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r7.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
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

DEFINE_REX_FUNC(sub_823308E8) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x82230b40
	ctx.lr = 0x8233090C;
	sub_82230B40(ctx, base);
	// lbz r11,544(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 544);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8233093c
	if (ctx.cr0.eq) goto loc_8233093C;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,10276
	ctx.r30.s64 = ctx.r30.s64 + 10276;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8233093c
	if (ctx.cr6.eq) goto loc_8233093C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825765f0
	ctx.lr = 0x82330934;
	sub_825765F0(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_8233093C:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,10252
	ctx.r11.s64 = ctx.r11.s64 + 10252;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// bl 0x824281d8
	ctx.lr = 0x82330954;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82330a14
	if (ctx.cr0.eq) goto loc_82330A14;
	// bl 0x8242a5e0
	ctx.lr = 0x82330960;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82330970
	if (!ctx.cr0.eq) goto loc_82330970;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82330974
	goto loc_82330974;
loc_82330970:
	// bl 0x8242aa28
	ctx.lr = 0x82330974;
	sub_8242AA28(ctx, base);
loc_82330974:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82330a24
	if (ctx.cr0.eq) goto loc_82330A24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82333dd8
	ctx.lr = 0x82330984;
	sub_82333DD8(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,10420
	ctx.r11.s64 = ctx.r11.s64 + 10420;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82330a24
	if (ctx.cr6.eq) goto loc_82330A24;
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// bl 0x82429a18
	ctx.lr = 0x823309A4;
	sub_82429A18(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lhz r9,552(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 552);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// ori r10,r10,10284
	ctx.r10.u64 = ctx.r10.u64 | 10284;
	// lfs f0,20068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20068);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r8,10288
	ctx.r11.u64 = ctx.r8.u64 | 10288;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// addi r4,r4,10280
	ctx.r4.s64 = ctx.r4.s64 + 10280;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stbx r8,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u8);
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
	// bl 0x82429960
	ctx.lr = 0x823309F0;
	sub_82429960(ctx, base);
	// lis r11,1
	ctx.r11.s64 = 65536;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// ori r11,r11,10292
	ctx.r11.u64 = ctx.r11.u64 | 10292;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r3,15
	ctx.r3.s64 = 15;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// bl 0x82429ff8
	ctx.lr = 0x82330A10;
	sub_82429FF8(ctx, base);
	// b 0x82330a24
	goto loc_82330A24;
loc_82330A14:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// ori r11,r11,10420
	ctx.r11.u64 = ctx.r11.u64 | 10420;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
loc_82330A24:
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

DEFINE_REX_FUNC(sub_823389F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x823389F8;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// bl 0x824443c8
	ctx.lr = 0x82338A08;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82338b3c
	if (ctx.cr0.eq) goto loc_82338B3C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x82338A18;
	sub_82430A88(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,-3204
	ctx.r11.s64 = ctx.r11.s64 + -3204;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r29,84(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// li r25,0
	ctx.r25.s64 = 0;
	// lwz r28,92(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// ld r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lwz r31,-13032(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r27,84(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lwz r26,100(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82338a9c
	if (ctx.cr6.eq) goto loc_82338A9C;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823aefa8
	ctx.lr = 0x82338A98;
	sub_823AEFA8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82338A9C:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82338ab8
	if (ctx.cr6.eq) goto loc_82338AB8;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823aefa8
	ctx.lr = 0x82338AB8;
	sub_823AEFA8(ctx, base);
loc_82338AB8:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = ctx.r30.u32 & 0xFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82338ad0
	if (!ctx.cr6.eq) goto loc_82338AD0;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82338b3c
	goto loc_82338B3C;
loc_82338AD0:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stw r25,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// addi r9,r11,23536
	ctx.r9.s64 = ctx.r11.s64 + 23536;
	// stw r25,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r25.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stw r25,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r25.u32);
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// std r11,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r11.u64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82338b30
	if (ctx.cr6.eq) goto loc_82338B30;
	// li r8,3
	ctx.r8.s64 = 3;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823af5b0
	ctx.lr = 0x82338B30;
	sub_823AF5B0(ctx, base);
loc_82338B30:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
loc_82338B3C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8233F700) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8233F708;
	__savegprlr_23(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
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
	// li r23,44
	ctx.r23.s64 = 44;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8233f730
	if (!ctx.cr6.eq) goto loc_8233F730;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8233f73c
	goto loc_8233F73C;
loc_8233F730:
	// lwz r10,12(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// divw r9,r10,r23
	ctx.r9.u64 = uint32_t((ctx.r23.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r10.s32 / ctx.r23.s32 : 0);
loc_8233F73C:
	// lwz r31,8(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lis r10,1489
	ctx.r10.s64 = 97583104;
	// subf r11,r11,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r11.u64;
	// ori r10,r10,29789
	ctx.r10.u64 = ctx.r10.u64 | 29789;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// subf r8,r11,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bge cr6,0x8233f7a4
	if (!ctx.cr6.lt) goto loc_8233F7A4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,56
	ctx.r4.s64 = ctx.r11.s64 + 56;
	// bl 0x822167f8
	ctx.lr = 0x8233F76C;
	sub_822167F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82216678
	ctx.lr = 0x8233F778;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x8233F77C;
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
	ctx.lr = 0x8233F790;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8233F7A0;
	sub_8235EC48(ctx, base);
	// b 0x8233fa54
	goto loc_8233FA54;
loc_8233F7A4:
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8233f8dc
	if (!ctx.cr6.lt) goto loc_8233F8DC;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8233f7c8
	if (!ctx.cr6.lt) goto loc_8233F7C8;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8233f7cc
	goto loc_8233F7CC;
loc_8233F7C8:
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_8233F7CC:
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8233f7d8
	if (!ctx.cr6.lt) goto loc_8233F7D8;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8233F7D8:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mulli r24,r11,44
	ctx.r24.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(44));
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8233F7F4;
	sub_825E02A0(ctx, base);
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// divw r26,r11,r23
	ctx.r26.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// mulli r25,r26,44
	ctx.r25.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(44));
	// add. r3,r25,r3
	ctx.r3.u64 = ctx.r25.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8233f81c
	if (ctx.cr0.eq) goto loc_8233F81C;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8233F81C;
	sub_8273A030(ctx, base);
loc_8233F81C:
	// lwz r29,4(r28)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mr r27,r31
	ctx.r27.u64 = ctx.r31.u64;
	// b 0x8233f848
	goto loc_8233F848;
loc_8233F828:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8233f840
	if (ctx.cr6.eq) goto loc_8233F840;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273a030
	ctx.lr = 0x8233F840;
	sub_8273A030(ctx, base);
loc_8233F840:
	// addi r29,r29,44
	ctx.r29.s64 = ctx.r29.s64 + 44;
	// addi r27,r27,44
	ctx.r27.s64 = ctx.r27.s64 + 44;
loc_8233F848:
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8233f828
	if (!ctx.cr6.eq) goto loc_8233F828;
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// lwz r27,8(r28)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// mulli r11,r11,44
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(44));
	// add r29,r11,r31
	ctx.r29.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8233f8a0
	if (ctx.cr6.eq) goto loc_8233F8A0;
	// subf r11,r25,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r25.u64;
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r30,r11,-44
	ctx.r30.s64 = ctx.r11.s64 + -44;
loc_8233F878:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8233f890
	if (ctx.cr6.eq) goto loc_8233F890;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8233F890;
	sub_8273A030(ctx, base);
loc_8233F890:
	// addi r30,r30,44
	ctx.r30.s64 = ctx.r30.s64 + 44;
	// addi r29,r29,44
	ctx.r29.s64 = ctx.r29.s64 + 44;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8233f878
	if (!ctx.cr6.eq) goto loc_8233F878;
loc_8233F8A0:
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
	// beq cr6,0x8233f8c0
	if (ctx.cr6.eq) goto loc_8233F8C0;
	// bl 0x825e0378
	ctx.lr = 0x8233F8C0;
	sub_825E0378(ctx, base);
loc_8233F8C0:
	// mulli r11,r30,44
	ctx.r11.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(44));
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
	// b 0x8233fa54
	goto loc_8233FA54;
loc_8233F8DC:
	// subf r11,r30,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// li r5,44
	ctx.r5.s64 = 44;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bge cr6,0x8233f9b4
	if (!ctx.cr6.lt) goto loc_8233F9B4;
	// bl 0x8273a030
	ctx.lr = 0x8233F8FC;
	sub_8273A030(ctx, base);
	// addi r29,r30,44
	ctx.r29.s64 = ctx.r30.s64 + 44;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8233f934
	if (ctx.cr6.eq) goto loc_8233F934;
	// addi r27,r29,-44
	ctx.r27.s64 = ctx.r29.s64 + -44;
loc_8233F90C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8233f924
	if (ctx.cr6.eq) goto loc_8233F924;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8233F924;
	sub_8273A030(ctx, base);
loc_8233F924:
	// addi r27,r27,44
	ctx.r27.s64 = ctx.r27.s64 + 44;
	// addi r29,r29,44
	ctx.r29.s64 = ctx.r29.s64 + 44;
	// cmplw cr6,r27,r31
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x8233f90c
	if (!ctx.cr6.eq) goto loc_8233F90C;
loc_8233F934:
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
	// beq cr6,0x8233f978
	if (ctx.cr6.eq) goto loc_8233F978;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_8233F954:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8233f96c
	if (ctx.cr6.eq) goto loc_8233F96C;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x8233F96C;
	sub_8273A030(ctx, base);
loc_8233F96C:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,44
	ctx.r31.s64 = ctx.r31.s64 + 44;
	// bne 0x8233f954
	if (!ctx.cr0.eq) goto loc_8233F954;
loc_8233F978:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// addi r11,r11,44
	ctx.r11.s64 = ctx.r11.s64 + 44;
	// addi r29,r11,-44
	ctx.r29.s64 = ctx.r11.s64 + -44;
	// stw r11,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r11.u32);
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8233fa54
	if (ctx.cr6.eq) goto loc_8233FA54;
loc_8233F994:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x8233F9A4;
	sub_8273A030(ctx, base);
	// addi r31,r31,44
	ctx.r31.s64 = ctx.r31.s64 + 44;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8233f994
	if (!ctx.cr6.eq) goto loc_8233F994;
	// b 0x8233fa54
	goto loc_8233FA54;
loc_8233F9B4:
	// bl 0x8273a030
	ctx.lr = 0x8233F9B8;
	sub_8273A030(ctx, base);
	// addi r27,r31,-44
	ctx.r27.s64 = ctx.r31.s64 + -44;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
	// cmplw cr6,r27,r31
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8233f9f4
	if (ctx.cr6.eq) goto loc_8233F9F4;
loc_8233F9CC:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8233f9e4
	if (ctx.cr6.eq) goto loc_8233F9E4;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8233F9E4;
	sub_8273A030(ctx, base);
loc_8233F9E4:
	// addi r26,r26,44
	ctx.r26.s64 = ctx.r26.s64 + 44;
	// addi r29,r29,44
	ctx.r29.s64 = ctx.r29.s64 + 44;
	// cmplw cr6,r26,r31
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x8233f9cc
	if (!ctx.cr6.eq) goto loc_8233F9CC;
loc_8233F9F4:
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8233fa28
	if (ctx.cr6.eq) goto loc_8233FA28;
	// addi r29,r27,44
	ctx.r29.s64 = ctx.r27.s64 + 44;
loc_8233FA08:
	// addi r31,r31,-44
	ctx.r31.s64 = ctx.r31.s64 + -44;
	// addi r29,r29,-44
	ctx.r29.s64 = ctx.r29.s64 + -44;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8233FA20;
	sub_8273A030(ctx, base);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8233fa08
	if (!ctx.cr6.eq) goto loc_8233FA08;
loc_8233FA28:
	// addi r29,r30,44
	ctx.r29.s64 = ctx.r30.s64 + 44;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8233fa54
	if (ctx.cr6.eq) goto loc_8233FA54;
loc_8233FA38:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x8233FA48;
	sub_8273A030(ctx, base);
	// addi r31,r31,44
	ctx.r31.s64 = ctx.r31.s64 + 44;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8233fa38
	if (!ctx.cr6.eq) goto loc_8233FA38;
loc_8233FA54:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82354398) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// ld r10,88(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 88);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r11,r11,32624
	ctx.r11.s64 = ctx.r11.s64 + 32624;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r30,r8,32720
	ctx.r30.s64 = ctx.r8.s64 + 32720;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82354400;
	sub_8255F918(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r11,r11,62392
	ctx.r11.u64 = ctx.r11.u64 | 62392;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,26612(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 26612);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfsx f13,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// fmuls f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82354468;
	sub_8255F918(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
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
	// lwz r31,-13032(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823544a4
	if (ctx.cr6.eq) goto loc_823544A4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823af008
	ctx.lr = 0x823544A4;
	sub_823AF008(ctx, base);
loc_823544A4:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x823544d8
	if (ctx.cr6.eq) goto loc_823544D8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823544c8
	if (ctx.cr6.eq) goto loc_823544C8;
	// addi r5,r5,12
	ctx.r5.s64 = ctx.r5.s64 + 12;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823af008
	ctx.lr = 0x823544C8;
	sub_823AF008(ctx, base);
loc_823544C8:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
loc_823544D8:
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

DEFINE_REX_FUNC(sub_8235F0F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8235F0F8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// bge cr6,0x8235f11c
	if (!ctx.cr6.lt) goto loc_8235F11C;
	// bl 0x82738500
	ctx.lr = 0x8235F11C;
	sub_82738500(ctx, base);
loc_8235F11C:
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// subf r29,r27,r11
	ctx.r29.u64 = ctx.r11.u64 - ctx.r27.u64;
	// cmplw cr6,r28,r29
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x8235f130
	if (!ctx.cr6.lt) goto loc_8235F130;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_8235F130:
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bne cr6,0x8235f15c
	if (!ctx.cr6.eq) goto loc_8235F15C;
	// li r5,-1
	ctx.r5.s64 = -1;
	// add r4,r29,r27
	ctx.r4.u64 = ctx.r29.u64 + ctx.r27.u64;
	// bl 0x82216868
	ctx.lr = 0x8235F148;
	sub_82216868(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82216868
	ctx.lr = 0x8235F158;
	sub_82216868(ctx, base);
	// b 0x8235f1c8
	goto loc_8235F1C8;
loc_8235F15C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8235f1d8
	ctx.lr = 0x8235F164;
	sub_8235F1D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8235f1c8
	if (ctx.cr0.eq) goto loc_8235F1C8;
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8235f180
	if (ctx.cr6.lt) goto loc_8235F180;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x8235f184
	goto loc_8235F184;
loc_8235F180:
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
loc_8235F184:
	// lwz r4,24(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r4,16
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 16, ctx.xer);
	// blt cr6,0x8235f19c
	if (ctx.cr6.lt) goto loc_8235F19C;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8235f1a0
	goto loc_8235F1A0;
loc_8235F19C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8235F1A0:
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x82738810
	ctx.lr = 0x8235F1AC;
	sub_82738810(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stw r29,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8235f1c0
	if (ctx.cr6.lt) goto loc_8235F1C0;
	// lwz r30,0(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8235F1C0:
	// li r11,0
	ctx.r11.s64 = 0;
	// stbx r11,r30,r29
	REX_STORE_U8(ctx.r30.u32 + ctx.r29.u32, ctx.r11.u8);
loc_8235F1C8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82362EE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82362EE8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,52(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,-13060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13060);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82362f44
	if (ctx.cr6.eq) goto loc_82362F44;
	// lwz r9,288(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// lwz r8,284(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 284);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x82362f38
	if (!ctx.cr6.lt) goto loc_82362F38;
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82362f38
	if (ctx.cr6.eq) goto loc_82362F38;
	// bl 0x8245d190
	ctx.lr = 0x82362F34;
	sub_8245D190(ctx, base);
	// b 0x82362f3c
	goto loc_82362F3C;
loc_82362F38:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82362F3C:
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// b 0x82362f48
	goto loc_82362F48;
loc_82362F44:
	// li r28,0
	ctx.r28.s64 = 0;
loc_82362F48:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82362fac
	if (ctx.cr6.eq) goto loc_82362FAC;
	// addi r31,r27,100
	ctx.r31.s64 = ctx.r27.s64 + 100;
	// li r29,2
	ctx.r29.s64 = 2;
loc_82362F58:
	// lwz r11,-36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -36);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82362f84
	if (ctx.cr6.eq) goto loc_82362F84;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82362fa0
	if (!ctx.cr6.eq) goto loc_82362FA0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82362fa0
	if (ctx.cr6.eq) goto loc_82362FA0;
	// addi r3,r31,-8
	ctx.r3.s64 = ctx.r31.s64 + -8;
	// bl 0x82367980
	ctx.lr = 0x82362F80;
	sub_82367980(ctx, base);
	// b 0x82362fa0
	goto loc_82362FA0;
loc_82362F84:
	// addi r30,r31,-40
	ctx.r30.s64 = ctx.r31.s64 + -40;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82362fb8
	ctx.lr = 0x82362F94;
	sub_82362FB8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82363428
	ctx.lr = 0x82362FA0;
	sub_82363428(ctx, base);
loc_82362FA0:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,124
	ctx.r31.s64 = ctx.r31.s64 + 124;
	// bne 0x82362f58
	if (!ctx.cr0.eq) goto loc_82362F58;
loc_82362FAC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82367618) {
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
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82367654
	goto loc_82367654;
loc_8236763C:
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8236764c
	if (ctx.cr6.eq) goto loc_8236764C;
	// bl 0x825e0378
	ctx.lr = 0x8236764C;
	sub_825E0378(ctx, base);
loc_8236764C:
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
loc_82367654:
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8236763c
	if (!ctx.cr6.eq) goto loc_8236763C;
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// li r10,0
	ctx.r10.s64 = 0;
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
	// stw r10,40(r30)
	REX_STORE_U32(ctx.r30.u32 + 40, ctx.r10.u32);
	// beq cr6,0x823676a0
	if (ctx.cr6.eq) goto loc_823676A0;
loc_82367688:
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825e0378
	ctx.lr = 0x82367690;
	sub_825E0378(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82367688
	if (!ctx.cr6.eq) goto loc_82367688;
loc_823676A0:
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

DEFINE_REX_FUNC(sub_8236A720) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8236A728;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	ctx.lr = 0x8236A740;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8236a7dc
	if (ctx.cr0.eq) goto loc_8236A7DC;
	// lbz r11,233(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 233);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8236a7dc
	if (!ctx.cr0.eq) goto loc_8236A7DC;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r28,0
	ctx.r28.s64 = 0;
	// stb r10,233(r31)
	REX_STORE_U8(ctx.r31.u32 + 233, ctx.r10.u8);
	// lwz r3,-13032(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8236a79c
	if (ctx.cr6.eq) goto loc_8236A79C;
	// lfs f0,236(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lfs f0,240(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r5,r11,80
	ctx.r5.s64 = ctx.r11.s64 + 80;
	// bl 0x823aefa8
	ctx.lr = 0x8236A798;
	sub_823AEFA8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_8236A79C:
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r31,324
	ctx.r30.s64 = ctx.r31.s64 + 324;
loc_8236A7A4:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8236bf30
	ctx.lr = 0x8236A7B4;
	sub_8236BF30(ctx, base);
	// lis r5,8192
	ctx.r5.s64 = 536870912;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fe48
	ctx.lr = 0x8236A7C8;
	sub_8235FE48(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stw r3,-36(r30)
	REX_STORE_U32(ctx.r30.u32 + -36, ctx.r3.u32);
	// addi r30,r30,64
	ctx.r30.s64 = ctx.r30.s64 + 64;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// blt cr6,0x8236a7a4
	if (ctx.cr6.lt) goto loc_8236A7A4;
loc_8236A7DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8236DE80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8236DE88;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// addi r11,r11,-13056
	ctx.r11.s64 = ctx.r11.s64 + -13056;
	// std r10,244(r31)
	REX_STORE_U64(ctx.r31.u32 + 244, ctx.r10.u64);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lwz r8,0(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r5,r10,28480
	ctx.r5.s64 = ctx.r10.s64 + 28480;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subfc r9,r9,r8
	ctx.xer.ca = ctx.r8.u32 >= ctx.r9.u32;
	ctx.r9.u64 = ctx.r8.u64 - ctx.r9.u64;
	// lwz r29,4(r6)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r25,r9,r8
	ctx.r25.u64 = ctx.r9.u64 & ctx.r8.u64;
	// bne cr6,0x8236df60
	if (!ctx.cr6.eq) goto loc_8236DF60;
	// li r9,51
	ctx.r9.s64 = 51;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// li r10,255
	ctx.r10.s64 = 255;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r27,0
	ctx.r27.s64 = 0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8236DEF8:
	// lbz r28,0(r26)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// mr r24,r28
	ctx.r24.u64 = ctx.r28.u64;
	// cmplw cr6,r28,r9
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8236df34
	if (ctx.cr6.eq) goto loc_8236DF34;
	// cmplwi cr6,r9,255
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 255, ctx.xer);
	// beq cr6,0x8236df24
	if (ctx.cr6.eq) goto loc_8236DF24;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// stwx r30,r10,r11
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r30.u32);
	// stwx r8,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
loc_8236DF24:
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// b 0x8236df38
	goto loc_8236DF38;
loc_8236DF34:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_8236DF38:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r26,r26,8
	ctx.r26.s64 = ctx.r26.s64 + 8;
	// bdnz 0x8236def8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8236DEF8;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// beq cr6,0x8236df60
	if (ctx.cr6.eq) goto loc_8236DF60;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// stwx r30,r10,r11
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r30.u32);
	// stwx r8,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
loc_8236DF60:
	// rlwinm r10,r25,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 3) & 0xFFFFFFF8;
	// li r9,0
	ctx.r9.s64 = 0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// subfc r11,r8,r29
	ctx.xer.ca = ctx.r29.u32 >= ctx.r8.u32;
	ctx.r11.u64 = ctx.r29.u64 - ctx.r8.u64;
	// stw r9,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r9.u32);
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r11,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// add r11,r10,r5
	ctx.r11.u64 = ctx.r10.u64 + ctx.r5.u64;
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// bne cr6,0x8236dfa4
	if (!ctx.cr6.eq) goto loc_8236DFA4;
	// li r10,-1
	ctx.r10.s64 = -1;
loc_8236DFA4:
	// stw r10,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r10.u32);
	// cmplwi cr6,r7,8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 8, ctx.xer);
	// lbz r10,3(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// stw r10,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r10.u32);
	// lbz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// stw r10,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r10.u32);
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// stb r10,280(r31)
	REX_STORE_U8(ctx.r31.u32 + 280, ctx.r10.u8);
	// lbz r10,5(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// stw r10,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r10.u32);
	// lbz r10,6(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// stw r10,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r10.u32);
	// lbz r11,7(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// stw r11,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
	// ble cr6,0x8236dff0
	if (!ctx.cr6.gt) goto loc_8236DFF0;
	// lwz r11,8(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// stw r11,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r11.u32);
loc_8236DFF0:
	// cmplwi cr6,r25,1
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 1, ctx.xer);
	// beq cr6,0x8236e00c
	if (ctx.cr6.eq) goto loc_8236E00C;
	// cmplwi cr6,r25,2
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 2, ctx.xer);
	// bne cr6,0x8236e018
	if (!ctx.cr6.eq) goto loc_8236E018;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x82363d90
	ctx.lr = 0x8236E008;
	sub_82363D90(ctx, base);
	// b 0x8236e014
	goto loc_8236E014;
loc_8236E00C:
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x82363e20
	ctx.lr = 0x8236E014;
	sub_82363E20(ctx, base);
loc_8236E014:
	// stw r3,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r3.u32);
loc_8236E018:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82378BE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// li r11,16
	ctx.r11.s64 = 16;
	// li r10,8
	ctx.r10.s64 = 8;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// lvx128 v63,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-32
	ctx.r11.s64 = ctx.r1.s64 + -32;
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r10,r9,12468
	ctx.r10.s64 = ctx.r9.s64 + 12468;
	// vperm128 v62,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r6,r1,-32
	ctx.r6.s64 = ctx.r1.s64 + -32;
	// lvsl v0,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lvsl v7,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v61,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v63,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lfs f12,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f12.f64 = double(temp.f32);
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// lfs f13,1908(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// vspltw128 v61,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-32(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f13,f11,f13,f0
	ctx.f13.f64 = double(float(std::fma(ctx.f11.f64, ctx.f13.f64, ctx.f0.f64)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x82378cc4
	if (!ctx.cr6.gt) goto loc_82378CC4;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f12,-32(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fabs f12,f12
	ctx.f12.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lwz r11,-15444(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15444);
	// lwz r10,-15432(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -15432);
	// lfs f13,18652(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18652);
	ctx.f13.f64 = double(temp.f32);
	// std r11,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r11.u64);
	// lfd f11,-32(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// std r10,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r10.u64);
	// lfd f10,-32(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fdivs f11,f10,f11
	ctx.f11.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// fmuls f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fcmpu cr6,f12,f11
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bgt cr6,0x82378cc4
	if (ctx.cr6.gt) goto loc_82378CC4;
	// lfs f12,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// fabs f12,f12
	ctx.f12.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blelr cr6
	if (!ctx.cr6.gt) return;
loc_82378CC4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8237EDC0) {
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
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,516
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 516, ctx.xer);
	// beq cr6,0x8237ede4
	if (ctx.cr6.eq) goto loc_8237EDE4;
	// bl 0x8235f668
	ctx.lr = 0x8237EDE0;
	sub_8235F668(ctx, base);
	// b 0x8237edf8
	goto loc_8237EDF8;
loc_8237EDE4:
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,260
	ctx.r3.s64 = ctx.r3.s64 + 260;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8237fdd0
	ctx.lr = 0x8237EDF8;
	sub_8237FDD0(ctx, base);
loc_8237EDF8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8237F548) {
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
	// lwz r3,292(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 292);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8237f570
	if (ctx.cr6.eq) goto loc_8237F570;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825765f0
	ctx.lr = 0x8237F570;
	sub_825765F0(ctx, base);
loc_8237F570:
	// li r11,-1
	ctx.r11.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
	// bl 0x8237fd40
	ctx.lr = 0x8237F580;
	sub_8237FD40(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fb40
	ctx.lr = 0x8237F588;
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

DEFINE_REX_FUNC(sub_82381128) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,88(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// addi r11,r3,80
	ctx.r11.s64 = ctx.r3.s64 + 80;
	// lwz r9,84(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi. r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82381148
	if (!ctx.cr0.eq) goto loc_82381148;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82381150
	goto loc_82381150;
loc_82381148:
	// lwz r10,84(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_82381150:
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,120(r10)
	REX_STORE_U32(ctx.r10.u32 + 120, ctx.r9.u32);
	// lfs f12,30056(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 30056);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,6816(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 6816);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f13,96(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bgt cr6,0x82381190
	if (ctx.cr6.gt) goto loc_82381190;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82381198
	goto loc_82381198;
loc_82381190:
	// lwz r10,84(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
loc_82381198:
	// stfs f0,96(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// stw r9,120(r10)
	REX_STORE_U32(ctx.r10.u32 + 120, ctx.r9.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bgt cr6,0x823811c0
	if (ctx.cr6.gt) goto loc_823811C0;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x823811c8
	goto loc_823811C8;
loc_823811C0:
	// lwz r10,84(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
loc_823811C8:
	// lbz r8,246(r3)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + 246);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x823811e0
	if (ctx.cr0.eq) goto loc_823811E0;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,6824(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 6824);
	ctx.f0.f64 = double(temp.f32);
	// b 0x823811ec
	goto loc_823811EC;
loc_823811E0:
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lfs f13,-30128(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f13,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f0.f64)));
loc_823811EC:
	// stfs f0,96(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// stw r9,120(r10)
	REX_STORE_U32(ctx.r10.u32 + 120, ctx.r9.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82381214
	if (ctx.cr6.gt) goto loc_82381214;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8238121c
	goto loc_8238121C;
loc_82381214:
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
loc_8238121C:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r9,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r9.u32);
	// lfs f0,6848(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6848);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82387740) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lfs f13,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f12.f64 = double(temp.f32);
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// lfs f13,164(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// blt cr6,0x82387790
	if (ctx.cr6.lt) goto loc_82387790;
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x823877ac
	if (ctx.cr6.gt) goto loc_823877AC;
	// b 0x823877a0
	goto loc_823877A0;
loc_82387790:
	// fneg f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x823877ac
	if (ctx.cr6.lt) goto loc_823877AC;
loc_823877A0:
	// li r10,1
	ctx.r10.s64 = 1;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
	// stb r10,168(r3)
	REX_STORE_U8(ctx.r3.u32 + 168, ctx.r10.u8);
loc_823877AC:
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// addi r10,r10,31600
	ctx.r10.s64 = ctx.r10.s64 + 31600;
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// li r8,64
	ctx.r8.s64 = 64;
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// lvsr v7,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// lvx128 v63,r10,r8
	ea = (ctx.r10.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v12,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v13,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8238CE80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8238CE88;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
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
	ctx.lr = 0x8238CEA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8238cfc0
	if (ctx.cr0.eq) goto loc_8238CFC0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238CEBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8238cfc0
	if (ctx.cr0.eq) goto loc_8238CFC0;
	// lwz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// addi r4,r31,296
	ctx.r4.s64 = ctx.r31.s64 + 296;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238CEDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r25,0
	ctx.r25.s64 = 0;
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r30,-13032(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + -13032);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8238cf64
	if (ctx.cr6.eq) goto loc_8238CF64;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
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
	ctx.lr = 0x8238CF60;
	sub_823AEFA8(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_8238CF64:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// addi r29,r31,272
	ctx.r29.s64 = ctx.r31.s64 + 272;
	// li r24,3
	ctx.r24.s64 = 3;
	// lis r26,-32115
	ctx.r26.s64 = -2104688640;
	// addi r27,r11,2880
	ctx.r27.s64 = ctx.r11.s64 + 2880;
loc_8238CF78:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8238cfb4
	if (ctx.cr6.eq) goto loc_8238CFB4;
	// lis r4,3
	ctx.r4.s64 = 196608;
	// lfs f1,30856(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 30856);
	ctx.f1.f64 = double(temp.f32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// li r8,10
	ctx.r8.s64 = 10;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// ori r4,r4,33
	ctx.r4.u64 = ctx.r4.u64 | 33;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823b0938
	ctx.lr = 0x8238CFB0;
	sub_823B0938(ctx, base);
	// lwz r30,-13032(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + -13032);
loc_8238CFB4:
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// addi r29,r29,24
	ctx.r29.s64 = ctx.r29.s64 + 24;
	// bne 0x8238cf78
	if (!ctx.cr0.eq) goto loc_8238CF78;
loc_8238CFC0:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82396D20) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,28368
	ctx.r3.s64 = ctx.r11.s64 + 28368;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82396EA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// extsw r11,r5
	ctx.r11.s64 = ctx.r5.s32;
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f13,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,240(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 240, temp.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stfs f12,236(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 236, temp.u32);
	// lfs f0,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x82396eec
	if (ctx.cr6.gt) goto loc_82396EEC;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,17132(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17132);
	ctx.f0.f64 = double(temp.f32);
loc_82396EEC:
	// stfs f0,244(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 244, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8239A0C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8239A0C8;
	__savegprlr_24(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,404(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 404);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r25,1
	ctx.r25.s64 = 1;
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8239a194
	if (!ctx.cr0.eq) goto loc_8239A194;
	// bl 0x82444358
	ctx.lr = 0x8239A0E8;
	sub_82444358(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8239a194
	if (ctx.cr0.eq) goto loc_8239A194;
	// bl 0x824443c8
	ctx.lr = 0x8239A0F4;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8239a194
	if (ctx.cr0.eq) goto loc_8239A194;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82430508
	ctx.lr = 0x8239A104;
	sub_82430508(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stb r25,404(r31)
	REX_STORE_U8(ctx.r31.u32 + 404, ctx.r25.u8);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r30,r31,228
	ctx.r30.s64 = ctx.r31.s64 + 228;
	// li r28,2
	ctx.r28.s64 = 2;
	// addi r29,r11,22072
	ctx.r29.s64 = ctx.r11.s64 + 22072;
	// addi r26,r10,-30464
	ctx.r26.s64 = ctx.r10.s64 + -30464;
loc_8239A124:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 44);
	// li r4,188
	ctx.r4.s64 = 188;
	// bl 0x825e02a0
	ctx.lr = 0x8239A134;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8239a148
	if (ctx.cr0.eq) goto loc_8239A148;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x823bdc58
	ctx.lr = 0x8239A144;
	sub_823BDC58(ctx, base);
	// b 0x8239a14c
	goto loc_8239A14C;
loc_8239A148:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
loc_8239A14C:
	// stw r3,44(r30)
	REX_STORE_U32(ctx.r30.u32 + 44, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,188
	ctx.r4.s64 = 188;
	// lwz r3,44(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8239A160;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8239a174
	if (ctx.cr0.eq) goto loc_8239A174;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x823bdc58
	ctx.lr = 0x8239A170;
	sub_823BDC58(ctx, base);
	// b 0x8239a178
	goto loc_8239A178;
loc_8239A174:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
loc_8239A178:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// stwu r3,48(r30)
	ea = 48 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r30.u32 = ea;
	// bne 0x8239a124
	if (!ctx.cr0.eq) goto loc_8239A124;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8239a194
	if (ctx.cr6.eq) goto loc_8239A194;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x825e0378
	ctx.lr = 0x8239A194;
	sub_825E0378(ctx, base);
loc_8239A194:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8239A1A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8239a368
	if (ctx.cr0.eq) goto loc_8239A368;
	// stb r24,405(r31)
	REX_STORE_U8(ctx.r31.u32 + 405, ctx.r24.u8);
	// bl 0x82444358
	ctx.lr = 0x8239A1B8;
	sub_82444358(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8239a2c8
	if (ctx.cr0.eq) goto loc_8239A2C8;
	// bl 0x824443c8
	ctx.lr = 0x8239A1C4;
	sub_824443C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8239a2c8
	if (ctx.cr0.eq) goto loc_8239A2C8;
	// addi r4,r31,388
	ctx.r4.s64 = ctx.r31.s64 + 388;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82430a88
	ctx.lr = 0x8239A1D8;
	sub_82430A88(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,64(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
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
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,68(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 68);
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,396(r31)
	REX_STORE_U64(ctx.r31.u32 + 396, ctx.r11.u64);
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8239A24C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r3,240(r31)
	REX_STORE_U8(ctx.r31.u32 + 240, ctx.r3.u8);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhz r10,96(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 96);
	// sth r10,418(r31)
	REX_STORE_U16(ctx.r31.u32 + 418, ctx.r10.u16);
	// beq 0x8239a268
	if (ctx.cr0.eq) goto loc_8239A268;
	// lwz r3,52(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// b 0x8239a26c
	goto loc_8239A26C;
loc_8239A268:
	// lwz r3,44(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 44);
loc_8239A26C:
	// lwz r4,92(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 92);
	// lfs f1,100(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 100);
	ctx.f1.f64 = double(temp.f32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x8239a2c8
	if (ctx.cr6.lt) goto loc_8239A2C8;
	// bl 0x823be7d0
	ctx.lr = 0x8239A280;
	sub_823BE7D0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8239a290
	if (!ctx.cr0.eq) goto loc_8239A290;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// b 0x8239a29c
	goto loc_8239A29C;
loc_8239A290:
	// lhz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r10,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r10.u32);
loc_8239A29C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8239a2c8
	if (ctx.cr0.eq) goto loc_8239A2C8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x824321a8
	ctx.lr = 0x8239A2AC;
	sub_824321A8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r25,405(r31)
	REX_STORE_U8(ctx.r31.u32 + 405, ctx.r25.u8);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// stb r11,416(r31)
	REX_STORE_U8(ctx.r31.u32 + 416, ctx.r11.u8);
loc_8239A2C8:
	// lwz r11,228(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8239a360
	if (!ctx.cr6.eq) goto loc_8239A360;
	// lwz r11,236(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8239a360
	if (ctx.cr6.eq) goto loc_8239A360;
	// li r10,-1
	ctx.r10.s64 = -1;
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r10.u32);
	// ble cr6,0x8239a360
	if (!ctx.cr6.gt) goto loc_8239A360;
	// addi r29,r31,252
	ctx.r29.s64 = ctx.r31.s64 + 252;
loc_8239A2F8:
	// addi r4,r29,8
	ctx.r4.s64 = ctx.r29.s64 + 8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8235fad0
	ctx.lr = 0x8239A304;
	sub_8235FAD0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8239a324
	if (!ctx.cr0.eq) goto loc_8239A324;
	// lwz r11,236(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,48
	ctx.r29.s64 = ctx.r29.s64 + 48;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8239a2f8
	if (ctx.cr6.lt) goto loc_8239A2F8;
	// b 0x8239a360
	goto loc_8239A360;
loc_8239A324:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r9,268
	ctx.r9.s64 = 268;
	// stw r3,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// addi r29,r10,20580
	ctx.r29.s64 = ctx.r10.s64 + 20580;
	// stw r30,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r30.u32);
	// stw r9,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r29,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r29.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// stw r24,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r24.u32);
	// lwz r3,-12816(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
	// bl 0x825a2f98
	ctx.lr = 0x8239A35C;
	sub_825A2F98(ctx, base);
	// stw r29,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r29.u32);
loc_8239A360:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8239a370
	ctx.lr = 0x8239A368;
	sub_8239A370(ctx, base);
loc_8239A368:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823B08A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823B08A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x823b08f0
	goto loc_823B08F0;
loc_823B08B8:
	// lwz r30,0(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r3,12(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823b08dc
	if (ctx.cr6.eq) goto loc_823B08DC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823B08DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823B08DC:
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// bl 0x825e0378
	ctx.lr = 0x823B08EC;
	sub_825E0378(ctx, base);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_823B08F0:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823b08b8
	if (!ctx.cr6.eq) goto loc_823B08B8;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x823b092c
	if (ctx.cr6.eq) goto loc_823B092C;
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
	// ble 0x823b0928
	if (!ctx.cr0.gt) goto loc_823B0928;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x823B0928;
	sub_827388E8(ctx, base);
loc_823B0928:
	// stw r31,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
loc_823B092C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823B29E0) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,40
	ctx.r4.s64 = 40;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823B2A10;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x823b2a50
	if (ctx.cr0.eq) goto loc_823B2A50;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,2668
	ctx.r11.s64 = ctx.r11.s64 + 2668;
	// addi r10,r10,4864
	ctx.r10.s64 = ctx.r10.s64 + 4864;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r4,r30,8
	ctx.r4.s64 = ctx.r30.s64 + 8;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x8273a030
	ctx.lr = 0x823B2A48;
	sub_8273A030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x823b2a54
	goto loc_823B2A54;
loc_823B2A50:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823B2A54:
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

DEFINE_REX_FUNC(sub_823B5FE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823B5FF0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 5, ctx.xer);
	// beq cr6,0x823b6044
	if (ctx.cr6.eq) goto loc_823B6044;
	// ble cr6,0x823b6014
	if (!ctx.cr6.gt) goto loc_823B6014;
	// cmpwi cr6,r4,8
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 8, ctx.xer);
	// ble cr6,0x823b601c
	if (!ctx.cr6.gt) goto loc_823B601C;
	// cmpwi cr6,r4,11
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 11, ctx.xer);
	// ble cr6,0x823b6044
	if (!ctx.cr6.gt) goto loc_823B6044;
loc_823B6014:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823b6148
	goto loc_823B6148;
loc_823B601C:
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// bne cr6,0x823b6048
	if (!ctx.cr6.eq) goto loc_823B6048;
	// cmpwi cr6,r4,6
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 6, ctx.xer);
	// bne cr6,0x823b6048
	if (!ctx.cr6.eq) goto loc_823B6048;
	// cmplwi cr6,r5,3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 3, ctx.xer);
	// bne cr6,0x823b6048
	if (!ctx.cr6.eq) goto loc_823B6048;
	// li r4,7
	ctx.r4.s64 = 7;
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x823b6048
	goto loc_823B6048;
loc_823B6044:
	// li r28,1
	ctx.r28.s64 = 1;
loc_823B6048:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r11,17432
	ctx.r30.s64 = ctx.r11.s64 + 17432;
	// lwzx r11,r10,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	// add r31,r11,r5
	ctx.r31.u64 = ctx.r11.u64 + ctx.r5.u64;
	// bl 0x82213210
	ctx.lr = 0x823B6060;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r31,8331
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8331, ctx.xer);
	// blt cr6,0x823b6074
	if (ctx.cr6.lt) goto loc_823B6074;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823b6080
	goto loc_823B6080;
loc_823B6074:
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1000(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1000);
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
loc_823B6080:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823b6014
	if (ctx.cr0.eq) goto loc_823B6014;
	// clrlwi. r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823b610c
	if (ctx.cr0.eq) goto loc_823B610C;
	// bl 0x82213210
	ctx.lr = 0x823B6094;
	sub_82213210(ctx, base);
	// addi r6,r3,4120
	ctx.r6.s64 = ctx.r3.s64 + 4120;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r7,r29,-1
	ctx.r7.s64 = ctx.r29.s64 + -1;
	// bl 0x823b47e8
	ctx.lr = 0x823B60A4;
	sub_823B47E8(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// bge cr6,0x823b60cc
	if (!ctx.cr6.lt) goto loc_823B60CC;
	// cmplwi cr6,r3,50
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 50, ctx.xer);
	// bge cr6,0x823b60cc
	if (!ctx.cr6.lt) goto loc_823B60CC;
	// mulli r11,r7,50
	ctx.r11.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(50));
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r11,r11,2446
	ctx.r11.s64 = ctx.r11.s64 + 2446;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r6
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
loc_823B60CC:
	// addi r11,r30,-36
	ctx.r11.s64 = ctx.r30.s64 + -36;
	// li r3,9
	ctx.r3.s64 = 9;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_823B60DC:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x823b6104
	if (ctx.cr6.lt) goto loc_823B6104;
	// addi r9,r30,-36
	ctx.r9.s64 = ctx.r30.s64 + -36;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r9,r9,36
	ctx.r9.s64 = ctx.r9.s64 + 36;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x823b60dc
	if (ctx.cr6.lt) goto loc_823B60DC;
	// b 0x823b6148
	goto loc_823B6148;
loc_823B6104:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// b 0x823b6134
	goto loc_823B6134;
loc_823B610C:
	// bl 0x82213210
	ctx.lr = 0x823B6110;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r31,8331
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8331, ctx.xer);
	// blt cr6,0x823b6124
	if (ctx.cr6.lt) goto loc_823B6124;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823b6130
	goto loc_823B6130;
loc_823B6124:
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1000(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1000);
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
loc_823B6130:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
loc_823B6134:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x823b6014
	if (ctx.cr6.lt) goto loc_823B6014;
	// cmpwi cr6,r3,9
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 9, ctx.xer);
	// ble cr6,0x823b6148
	if (!ctx.cr6.gt) goto loc_823B6148;
	// li r3,9
	ctx.r3.s64 = 9;
loc_823B6148:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823BAFB8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x823bb000
	if (!ctx.cr6.eq) goto loc_823BB000;
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x823bb000
	if (ctx.cr6.lt) goto loc_823BB000;
	// lwz r10,140(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// lbz r9,42(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 42);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x823bb000
	if (!ctx.cr6.lt) goto loc_823BB000;
	// lbz r9,38(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 38);
	// lwz r10,148(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// lbzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,255
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 255, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_823BB000:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823BE020) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x823BE028;
	__savegprlr_14(ctx, base);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r6,476(r1)
	REX_STORE_U32(ctx.r1.u32 + 476, ctx.r6.u32);
	// mr r22,r4
	ctx.r22.u64 = ctx.r4.u64;
	// mr r17,r5
	ctx.r17.u64 = ctx.r5.u64;
	// mr r16,r6
	ctx.r16.u64 = ctx.r6.u64;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// mr r18,r8
	ctx.r18.u64 = ctx.r8.u64;
	// mr r27,r9
	ctx.r27.u64 = ctx.r9.u64;
	// bl 0x823bd038
	ctx.lr = 0x823BE050;
	sub_823BD038(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x823be060
	if (!ctx.cr0.eq) goto loc_823BE060;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823be7c8
	goto loc_823BE7C8;
loc_823BE060:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r19,0
	ctx.r19.s64 = 0;
	// lwz r20,96(r11)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// lwz r21,104(r11)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x823be0cc
	if (ctx.cr6.eq) goto loc_823BE0CC;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x823be0cc
	if (ctx.cr6.eq) goto loc_823BE0CC;
	// clrlwi r11,r22,16
	ctx.r11.u64 = ctx.r22.u32 & 0xFFFF;
	// li r19,1
	ctx.r19.s64 = 1;
	// mulli r11,r11,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(12));
	// add r11,r11,r21
	ctx.r11.u64 = ctx.r11.u64 + ctx.r21.u64;
	// lhz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// lhz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// lhz r8,10(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// lhz r7,6(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// lhz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r26,2(r11)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// subf r11,r7,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r7.u64;
	// clrlwi r23,r10,16
	ctx.r23.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r24,r11,16
	ctx.r24.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r23,124(r1)
	REX_STORE_U16(ctx.r1.u32 + 124, ctx.r23.u16);
	// sth r28,120(r1)
	REX_STORE_U16(ctx.r1.u32 + 120, ctx.r28.u16);
	// sth r26,122(r1)
	REX_STORE_U16(ctx.r1.u32 + 122, ctx.r26.u16);
	// sth r24,126(r1)
	REX_STORE_U16(ctx.r1.u32 + 126, ctx.r24.u16);
	// b 0x823be0f0
	goto loc_823BE0F0;
loc_823BE0CC:
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823bd1a8
	ctx.lr = 0x823BE0E0;
	sub_823BD1A8(ctx, base);
	// lhz r24,126(r1)
	ctx.r24.u64 = REX_LOAD_U16(ctx.r1.u32 + 126);
	// lhz r23,124(r1)
	ctx.r23.u64 = REX_LOAD_U16(ctx.r1.u32 + 124);
	// lhz r26,122(r1)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r1.u32 + 122);
	// lhz r28,120(r1)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r1.u32 + 120);
loc_823BE0F0:
	// lbz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 164);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823be110
	if (!ctx.cr0.eq) goto loc_823BE110;
	// lwz r11,160(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823be110
	if (ctx.cr6.eq) goto loc_823BE110;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// b 0x823be148
	goto loc_823BE148;
loc_823BE110:
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x823BE11C;
	sub_825F8D38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x823be144
	if (ctx.cr0.eq) goto loc_823BE144;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8b88
	ctx.lr = 0x823BE12C;
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
	ctx.lr = 0x823BE140;
	sub_825F8BF8(ctx, base);
	// b 0x823be148
	goto loc_823BE148;
loc_823BE144:
	// li r30,0
	ctx.r30.s64 = 0;
loc_823BE148:
	// lwz r11,408(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// ori r11,r11,384
	ctx.r11.u64 = ctx.r11.u64 | 384;
	// stw r11,408(r30)
	REX_STORE_U32(ctx.r30.u32 + 408, ctx.r11.u32);
	// lbz r10,141(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 141);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x823be168
	if (!ctx.cr0.eq) goto loc_823BE168;
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// b 0x823be16c
	goto loc_823BE16C;
loc_823BE168:
	// rlwinm r11,r11,0,26,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
loc_823BE16C:
	// stw r11,408(r30)
	REX_STORE_U32(ctx.r30.u32 + 408, ctx.r11.u32);
	// lfs f0,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,412(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 412, temp.u32);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r17
	ctx.r5.u64 = ctx.r17.u64;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823c23b8
	ctx.lr = 0x823BE18C;
	sub_823C23B8(ctx, base);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x823BE19C;
	sub_8273A030(ctx, base);
	// lwz r6,424(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 424);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x823be1ac
	if (ctx.cr6.eq) goto loc_823BE1AC;
	// stw r6,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r6.u32);
loc_823BE1AC:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stb r25,60(r31)
	REX_STORE_U8(ctx.r31.u32 + 60, ctx.r25.u8);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r5,r11,14376
	ctx.r5.s64 = ctx.r11.s64 + 14376;
	// lwz r11,-12872(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -12872);
	// lfs f6,-2140(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -2140);
	ctx.f6.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823be1d4
	if (ctx.cr6.eq) goto loc_823BE1D4;
	// lfs f5,664(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f5.f64 = double(temp.f32);
	// b 0x823be1d8
	goto loc_823BE1D8;
loc_823BE1D4:
	// fmr f5,f6
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f6.f64;
loc_823BE1D8:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// blt cr6,0x823be1f8
	if (ctx.cr6.lt) goto loc_823BE1F8;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x823be1f8
	if (ctx.cr6.gt) goto loc_823BE1F8;
	// clrlwi r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	// fmr f5,f6
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f6.f64;
	// xori r25,r11,1
	ctx.r25.u64 = ctx.r11.u64 ^ 1;
loc_823BE1F8:
	// rlwinm. r4,r25,0,30,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// clrlwi r8,r25,24
	ctx.r8.u64 = ctx.r25.u32 & 0xFF;
	// beq 0x823be230
	if (ctx.cr0.eq) goto loc_823BE230;
	// lha r10,33(r29)
	ctx.r10.s64 = int16_t(REX_LOAD_U16(ctx.r29.u32 + 33));
	// clrlwi r9,r23,16
	ctx.r9.u64 = ctx.r23.u32 & 0xFFFF;
	// lha r7,116(r31)
	ctx.r7.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 116));
	// extsh r3,r28
	ctx.r3.s64 = ctx.r28.s16;
	// add r11,r10,r7
	ctx.r11.u64 = ctx.r10.u64 + ctx.r7.u64;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x823be250
	goto loc_823BE250;
loc_823BE230:
	// lha r11,33(r29)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r29.u32 + 33));
	// extsh r10,r28
	ctx.r10.s64 = ctx.r28.s16;
	// lha r9,116(r31)
	ctx.r9.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 116));
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
loc_823BE250:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// clrlwi. r28,r8,31
	ctx.r28.u64 = ctx.r8.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// beq 0x823be28c
	if (ctx.cr0.eq) goto loc_823BE28C;
	// lha r10,35(r29)
	ctx.r10.s64 = int16_t(REX_LOAD_U16(ctx.r29.u32 + 35));
	// clrlwi r11,r24,16
	ctx.r11.u64 = ctx.r24.u32 & 0xFFFF;
	// lha r7,118(r31)
	ctx.r7.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 118));
	// extsh r9,r26
	ctx.r9.s64 = ctx.r26.s16;
	// subf r10,r10,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r10.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x823be2ac
	goto loc_823BE2AC;
loc_823BE28C:
	// lha r11,35(r29)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r29.u32 + 35));
	// extsh r10,r26
	ctx.r10.s64 = ctx.r26.s16;
	// lha r9,118(r31)
	ctx.r9.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 118));
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
loc_823BE2AC:
	// clrlwi r11,r23,16
	ctx.r11.u64 = ctx.r23.u32 & 0xFFFF;
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// clrlwi r10,r24,16
	ctx.r10.u64 = ctx.r24.u32 & 0xFFFF;
	// lfs f7,-1908(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -1908);
	ctx.f7.f64 = double(temp.f32);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f12,112(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// frsp f4,f0
	ctx.f4.f64 = double(float(ctx.f0.f64));
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// fcfid f0,f12
	ctx.f0.f64 = double(ctx.f12.s64);
	// fsubs f2,f4,f13
	ctx.f2.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f3,f0,f1
	ctx.f3.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// beq cr6,0x823be450
	if (ctx.cr6.eq) goto loc_823BE450;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x823be450
	if (ctx.cr6.eq) goto loc_823BE450;
	// clrlwi r11,r22,16
	ctx.r11.u64 = ctx.r22.u32 & 0xFFFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mulli r11,r11,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(12));
	// add r7,r11,r21
	ctx.r7.u64 = ctx.r11.u64 + ctx.r21.u64;
	// bl 0x823bd9c0
	ctx.lr = 0x823BE30C;
	sub_823BD9C0(ctx, base);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f10,-1208(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -1208);
	ctx.f10.f64 = double(temp.f32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// lfs f0,3048(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 3048);
	ctx.f0.f64 = double(temp.f32);
	// beq 0x823be33c
	if (ctx.cr0.eq) goto loc_823BE33C;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x823be334
	if (ctx.cr6.eq) goto loc_823BE334;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// b 0x823be340
	goto loc_823BE340;
loc_823BE334:
	// fmr f13,f10
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f10.f64;
	// b 0x823be340
	goto loc_823BE340;
loc_823BE33C:
	// fmr f13,f7
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f7.f64;
loc_823BE340:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823be358
	if (ctx.cr6.eq) goto loc_823BE358;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x823be35c
	if (ctx.cr6.eq) goto loc_823BE35C;
	// fmr f10,f0
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f0.f64;
	// b 0x823be35c
	goto loc_823BE35C;
loc_823BE358:
	// fmr f10,f7
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f7.f64;
loc_823BE35C:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x823be36c
	if (ctx.cr6.eq) goto loc_823BE36C;
	// lhz r11,8(r7)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + 8);
	// b 0x823be370
	goto loc_823BE370;
loc_823BE36C:
	// lhz r11,4(r7)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + 4);
loc_823BE370:
	// lhz r10,8(r20)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r20.u32 + 8);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fadds f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// fdivs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// beq cr6,0x823be3b4
	if (ctx.cr6.eq) goto loc_823BE3B4;
	// lhz r11,4(r7)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + 4);
	// b 0x823be3b8
	goto loc_823BE3B8;
loc_823BE3B4:
	// lhz r11,8(r7)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + 8);
loc_823BE3B8:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fsubs f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fdivs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// beq cr6,0x823be3e4
	if (ctx.cr6.eq) goto loc_823BE3E4;
	// lhz r11,10(r7)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + 10);
	// b 0x823be3e8
	goto loc_823BE3E8;
loc_823BE3E4:
	// lhz r11,6(r7)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + 6);
loc_823BE3E8:
	// lhz r10,10(r20)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r20.u32 + 10);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f13,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fadds f13,f13,f10
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f10.f64));
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fdivs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// beq cr6,0x823be42c
	if (ctx.cr6.eq) goto loc_823BE42C;
	// lhz r11,6(r7)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + 6);
	// b 0x823be430
	goto loc_823BE430;
loc_823BE42C:
	// lhz r11,10(r7)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + 10);
loc_823BE430:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f9,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// fsubs f10,f9,f10
	ctx.f10.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fdivs f0,f10,f0
	ctx.f0.f64 = double(float(ctx.f10.f64 / ctx.f0.f64));
	// b 0x823be4ac
	goto loc_823BE4AC;
loc_823BE450:
	// lfs f12,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f11,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f0,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,17288
	ctx.r11.s64 = ctx.r11.s64 + 17288;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r7,r11,12
	ctx.r7.s64 = ctx.r11.s64 + 12;
	// lfsx f11,r10,r11
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f9,r10,r8
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f12,f12,f5
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f5.f64));
	// lfsx f10,r10,r9
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f13,f13,f5
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f5.f64));
	// lfsx f8,r10,r7
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	ctx.f8.f64 = double(temp.f32);
	// fdivs f12,f0,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 / ctx.f12.f64));
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fadds f11,f11,f12
	ctx.f11.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// fadds f13,f9,f0
	ctx.f13.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// fadds f12,f10,f12
	ctx.f12.f64 = double(float(ctx.f10.f64 + ctx.f12.f64));
	// fadds f0,f8,f0
	ctx.f0.f64 = double(float(ctx.f8.f64 + ctx.f0.f64));
loc_823BE4AC:
	// stfs f1,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// stfs f4,196(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stw r18,148(r6)
	REX_STORE_U32(ctx.r6.u32 + 148, ctx.r18.u32);
	// stfs f7,200(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stw r18,108(r6)
	REX_STORE_U32(ctx.r6.u32 + 108, ctx.r18.u32);
	// stfs f6,204(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stw r18,68(r6)
	REX_STORE_U32(ctx.r6.u32 + 68, ctx.r18.u32);
	// stfs f1,160(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stw r18,28(r6)
	REX_STORE_U32(ctx.r6.u32 + 28, ctx.r18.u32);
	// stfs f2,164(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f7,168(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f6,172(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f3,128(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f2,132(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f7,136(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f6,140(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f3,96(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f4,100(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f7,104(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f6,108(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f11,176(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r7,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// lwz r7,4(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r29,8(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r28,0(r9)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r27,4(r9)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r26,8(r9)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r25,0(r8)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r24,4(r8)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r23,8(r8)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r8,12(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// ld r18,144(r1)
	ctx.r18.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// ld r16,176(r1)
	ctx.r16.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// ld r15,112(r1)
	ctx.r15.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// ld r14,80(r1)
	ctx.r14.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stw r5,4(r6)
	REX_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// stw r4,8(r6)
	REX_STORE_U32(ctx.r6.u32 + 8, ctx.r4.u32);
	// stw r11,12(r6)
	REX_STORE_U32(ctx.r6.u32 + 12, ctx.r11.u32);
	// std r18,32(r6)
	REX_STORE_U64(ctx.r6.u32 + 32, ctx.r18.u64);
	// stw r3,40(r6)
	REX_STORE_U32(ctx.r6.u32 + 40, ctx.r3.u32);
	// stw r7,44(r6)
	REX_STORE_U32(ctx.r6.u32 + 44, ctx.r7.u32);
	// stw r29,48(r6)
	REX_STORE_U32(ctx.r6.u32 + 48, ctx.r29.u32);
	// stw r10,52(r6)
	REX_STORE_U32(ctx.r6.u32 + 52, ctx.r10.u32);
	// std r16,72(r6)
	REX_STORE_U64(ctx.r6.u32 + 72, ctx.r16.u64);
	// stw r28,80(r6)
	REX_STORE_U32(ctx.r6.u32 + 80, ctx.r28.u32);
	// stw r27,84(r6)
	REX_STORE_U32(ctx.r6.u32 + 84, ctx.r27.u32);
	// stw r26,88(r6)
	REX_STORE_U32(ctx.r6.u32 + 88, ctx.r26.u32);
	// stw r9,92(r6)
	REX_STORE_U32(ctx.r6.u32 + 92, ctx.r9.u32);
	// std r15,112(r6)
	REX_STORE_U64(ctx.r6.u32 + 112, ctx.r15.u64);
	// stw r25,120(r6)
	REX_STORE_U32(ctx.r6.u32 + 120, ctx.r25.u32);
	// stw r24,124(r6)
	REX_STORE_U32(ctx.r6.u32 + 124, ctx.r24.u32);
	// stw r23,128(r6)
	REX_STORE_U32(ctx.r6.u32 + 128, ctx.r23.u32);
	// stw r8,132(r6)
	REX_STORE_U32(ctx.r6.u32 + 132, ctx.r8.u32);
	// std r14,152(r6)
	REX_STORE_U64(ctx.r6.u32 + 152, ctx.r14.u64);
	// lhz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 92);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x823be76c
	if (!ctx.cr6.eq) goto loc_823BE76C;
	// extsw r11,r17
	ctx.r11.s64 = ctx.r17.s32;
	// lwa r10,476(r1)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 476));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// stfs f1,128(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,32576
	ctx.r11.s64 = ctx.r11.s64 + 32576;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// vspltw128 v10,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v4,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vspltw128 v8,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// vmaddfp v10,v0,v10,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f4,132(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f7,136(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f6,140(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vspltw128 v7,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vmaddfp v4,v4,v12,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// frsp f0,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vspltw128 v6,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vspltw128 v9,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vmaddfp v3,v0,v7,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f3,96(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f7,104(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f6,108(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v5,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// vmaddfp v0,v0,v5,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vspltw128 v7,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmaddfp v13,v6,v12,v3
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// stfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vmaddfp v0,v7,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vspltw128 v10,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v11,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v12,v8,v11,v4
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v13,v9,v11,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v0,v10,v11,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8245a130
	ctx.lr = 0x823BE71C;
	sub_8245A130(ctx, base);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lfs f11,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f9,f13,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lfs f11,164(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fsubs f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f10,f5,f12
	ctx.f10.f64 = double(float(std::fma(ctx.f10.f64, ctx.f5.f64, ctx.f12.f64)));
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmadds f10,f9,f5,f11
	ctx.f10.f64 = double(float(std::fma(ctx.f9.f64, ctx.f5.f64, ctx.f11.f64)));
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmadds f0,f0,f5,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f5.f64, ctx.f12.f64)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f0,f13,f5,f11
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f5.f64, ctx.f11.f64)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_823BE76C:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// beq cr6,0x823be784
	if (ctx.cr6.eq) goto loc_823BE784;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// bne cr6,0x823be798
	if (!ctx.cr6.eq) goto loc_823BE798;
loc_823BE784:
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823bfc88
	ctx.lr = 0x823BE798;
	sub_823BFC88(ctx, base);
loc_823BE798:
	// mr r8,r19
	ctx.r8.u64 = ctx.r19.u64;
	// lwz r5,144(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823bd310
	ctx.lr = 0x823BE7B4;
	sub_823BD310(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lbz r5,164(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 164);
	// lwz r4,120(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x82459d08
	ctx.lr = 0x823BE7C4;
	sub_82459D08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_823BE7C8:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823FDC28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x823FDC30;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r31,156(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r11,r11,32412
	ctx.r11.s64 = ctx.r11.s64 + 32412;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x823fdcac
	if (ctx.cr6.eq) goto loc_823FDCAC;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,-12824(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x823FDC64;
	sub_82599798(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r28,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addi r30,r31,-4
	ctx.r30.s64 = ctx.r31.s64 + -4;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// li r29,4
	ctx.r29.s64 = 4;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
loc_823FDC7C:
	// lwz r11,-13064(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -13064);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823fdc98
	if (ctx.cr6.eq) goto loc_823FDC98;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823fdc98
	if (ctx.cr6.eq) goto loc_823FDC98;
	// bl 0x8235d960
	ctx.lr = 0x823FDC98;
	sub_8235D960(ctx, base);
loc_823FDC98:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stwu r28,4(r30)
	ea = 4 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r30.u32 = ea;
	// bne 0x823fdc7c
	if (!ctx.cr0.eq) goto loc_823FDC7C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x823FDCAC;
	sub_825E0378(ctx, base);
loc_823FDCAC:
	// stw r28,156(r26)
	REX_STORE_U32(ctx.r26.u32 + 156, ctx.r28.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x823c4360
	ctx.lr = 0x823FDCB8;
	sub_823C4360(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82401FB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82401FB8;
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
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r27,r3,800
	ctx.r27.s64 = ctx.r3.s64 + 800;
	// addi r10,r11,12472
	ctx.r10.s64 = ctx.r11.s64 + 12472;
	// li r26,4
	ctx.r26.s64 = 4;
	// lis r30,-32227
	ctx.r30.s64 = -2112028672;
	// lfs f31,12472(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f31.f64 = double(temp.f32);
	// lis r28,-32226
	ctx.r28.s64 = -2111963136;
	// lis r29,-32114
	ctx.r29.s64 = -2104623104;
	// lfs f30,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f30.f64 = double(temp.f32);
loc_82401FE8:
	// lwz r31,0(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8240207c
	if (ctx.cr6.eq) goto loc_8240207C;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240201c
	if (ctx.cr6.eq) goto loc_8240201C;
	// lfs f3,17244(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 17244);
	ctx.f3.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f2,-12348(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -12348);
	ctx.f2.f64 = double(temp.f32);
	// fmr f5,f31
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x823c5a58
	ctx.lr = 0x8240201C;
	sub_823C5A58(ctx, base);
loc_8240201C:
	// lwz r3,124(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82402044
	if (ctx.cr6.eq) goto loc_82402044;
	// lfs f2,-32568(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -32568);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f3,17244(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 17244);
	ctx.f3.f64 = double(temp.f32);
	// fmr f5,f31
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x823c5a58
	ctx.lr = 0x82402044;
	sub_823C5A58(ctx, base);
loc_82402044:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82402058;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x823c51b0
	ctx.lr = 0x82402060;
	sub_823C51B0(ctx, base);
	// addi r3,r31,64
	ctx.r3.s64 = ctx.r31.s64 + 64;
	// bl 0x823c51b0
	ctx.lr = 0x82402068;
	sub_823C51B0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8240207C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8240207C:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r27,r27,8
	ctx.r27.s64 = ctx.r27.s64 + 8;
	// bne 0x82401fe8
	if (!ctx.cr0.eq) goto loc_82401FE8;
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

DEFINE_REX_FUNC(sub_82409BA0) {
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
	// bl 0x823f99c8
	ctx.lr = 0x82409BB8;
	sub_823F99C8(ctx, base);
	// lwz r11,160(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// lbz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 36);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82409bdc
	if (ctx.cr0.eq) goto loc_82409BDC;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82409bdc
	if (ctx.cr6.eq) goto loc_82409BDC;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x823c8690
	ctx.lr = 0x82409BDC;
	sub_823C8690(ctx, base);
loc_82409BDC:
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

DEFINE_REX_FUNC(sub_8240BF68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,156(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lbz r9,153(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 153);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lfs f0,52(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 52);
	ctx.f0.f64 = double(temp.f32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f13,52(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 52, temp.u32);
	// lfs f0,-30128(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,2
	ctx.r8.s64 = 2;
	// stb r9,153(r10)
	REX_STORE_U8(ctx.r10.u32 + 153, ctx.r9.u8);
	// stw r9,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r9.u32);
	// stw r8,-12(r1)
	REX_STORE_U32(ctx.r1.u32 + -12, ctx.r8.u32);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// ld r10,-16(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// std r10,136(r11)
	REX_STORE_U64(ctx.r11.u32 + 136, ctx.r10.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8240E380) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8240E388;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x823c5778
	ctx.lr = 0x8240E398;
	sub_823C5778(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r11,r11,-31108
	ctx.r11.s64 = ctx.r11.s64 + -31108;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82404240
	ctx.lr = 0x8240E3AC;
	sub_82404240(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r29,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r29.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r30.u32);
	// stw r30,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r30.u32);
	// bl 0x82457b58
	ctx.lr = 0x8240E3C4;
	sub_82457B58(ctx, base);
	// bl 0x825fd7a0
	ctx.lr = 0x8240E3C8;
	sub_825FD7A0(ctx, base);
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r3,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r3.u32);
	// addi r11,r31,252
	ctx.r11.s64 = ctx.r31.s64 + 252;
	// stb r30,164(r31)
	REX_STORE_U8(ctx.r31.u32 + 164, ctx.r30.u8);
	// stb r30,165(r31)
	REX_STORE_U8(ctx.r31.u32 + 165, ctx.r30.u8);
	// stw r30,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r30.u32);
	// stw r30,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r30.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8240E3E8:
	// stw r30,-60(r11)
	REX_STORE_U32(ctx.r11.u32 + -60, ctx.r30.u32);
	// stwu r30,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r30.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8240e3e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8240E3E8;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r31,264
	ctx.r11.s64 = ctx.r31.s64 + 264;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8240E400:
	// stw r30,-36(r11)
	REX_STORE_U32(ctx.r11.u32 + -36, ctx.r30.u32);
	// stwu r30,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r30.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8240e400
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8240E400;
	// stw r30,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r30.u32);
	// addi r11,r31,284
	ctx.r11.s64 = ctx.r31.s64 + 284;
	// stw r30,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r30.u32);
	// stw r30,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r30.u32);
	// stw r30,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r30.u32);
	// stw r30,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r30.u32);
	// stw r30,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r30.u32);
	// stw r30,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r30.u32);
	// bl 0x82213210
	ctx.lr = 0x8240E430;
	sub_82213210(ctx, base);
	// lbz r11,4153(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4153);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r11,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// bl 0x82213210
	ctx.lr = 0x8240E440;
	sub_82213210(ctx, base);
	// lbz r11,4154(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4154);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r11,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r11.u32);
	// bl 0x82213210
	ctx.lr = 0x8240E450;
	sub_82213210(ctx, base);
	// lbz r11,4155(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4155);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r11,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r11.u32);
	// bl 0x82213210
	ctx.lr = 0x8240E460;
	sub_82213210(ctx, base);
	// lbz r11,4156(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4156);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// bl 0x82213210
	ctx.lr = 0x8240E470;
	sub_82213210(ctx, base);
	// lbz r11,4153(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4153);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r11,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r11.u32);
	// bl 0x82213210
	ctx.lr = 0x8240E480;
	sub_82213210(ctx, base);
	// lbz r11,4154(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4154);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r11,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
	// bl 0x82213210
	ctx.lr = 0x8240E490;
	sub_82213210(ctx, base);
	// lbz r11,4155(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4155);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r11,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// bl 0x82213210
	ctx.lr = 0x8240E4A0;
	sub_82213210(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// lbz r9,4156(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 4156);
	// addi r10,r31,340
	ctx.r10.s64 = ctx.r31.s64 + 340;
	// addi r10,r31,360
	ctx.r10.s64 = ctx.r31.s64 + 360;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r9,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r9.u32);
	// stw r30,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r30.u32);
	// stw r30,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r30.u32);
	// stw r30,348(r31)
	REX_STORE_U32(ctx.r31.u32 + 348, ctx.r30.u32);
	// lfs f0,12472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f0.f64 = double(temp.f32);
loc_8240E4D0:
	// stw r30,-4(r10)
	REX_STORE_U32(ctx.r10.u32 + -4, ctx.r30.u32);
	// stfsu f0,4(r10)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8240e4d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8240E4D0;
	// stw r30,352(r31)
	REX_STORE_U32(ctx.r31.u32 + 352, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,372(r31)
	REX_STORE_U32(ctx.r31.u32 + 372, ctx.r30.u32);
	// bl 0x8240fc20
	ctx.lr = 0x8240E4EC;
	sub_8240FC20(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8240fb78
	ctx.lr = 0x8240E4F4;
	sub_8240FB78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8241B358) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x82419be8
	sub_82419BE8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8241B4E0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x8241c4f8
	sub_8241C4F8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8241C158) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8241C160;
	__savegprlr_26(ctx, base);
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r28,r3,324
	ctx.r28.s64 = ctx.r3.s64 + 324;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,3
	ctx.r30.s64 = 3;
	// addi r29,r28,-4
	ctx.r29.s64 = ctx.r28.s64 + -4;
loc_8241C180:
	// lwzu r3,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// bl 0x823bdef8
	ctx.lr = 0x8241C188;
	sub_823BDEF8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8241c180
	if (!ctx.cr0.eq) goto loc_8241C180;
	// lwz r3,336(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c73f0
	ctx.lr = 0x8241C19C;
	sub_823C73F0(ctx, base);
	// lwz r3,340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c8488
	ctx.lr = 0x8241C1A8;
	sub_823C8488(ctx, base);
	// lwz r9,548(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 548);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r27,r11,12236
	ctx.r27.s64 = ctx.r11.s64 + 12236;
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8241c1d8
	if (!ctx.cr6.eq) goto loc_8241C1D8;
	// lfs f13,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3420(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 3420);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8241c29c
	if (!ctx.cr6.lt) goto loc_8241C29C;
loc_8241C1D8:
	// lwz r11,64(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 64);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r29,r10,27412
	ctx.r29.s64 = ctx.r10.s64 + 27412;
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8241c200
	if (!ctx.cr6.eq) goto loc_8241C200;
	// lfs f13,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-9032(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -9032);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8241c2a4
	if (!ctx.cr6.gt) goto loc_8241C2A4;
loc_8241C200:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8241C204:
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lbz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8241c238
	if (!ctx.cr0.eq) goto loc_8241C238;
	// lbz r10,152(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 152);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8241c238
	if (ctx.cr0.eq) goto loc_8241C238;
	// lbz r10,153(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 153);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8241c238
	if (!ctx.cr0.eq) goto loc_8241C238;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x8241c23c
	if (!ctx.cr0.eq) goto loc_8241C23C;
loc_8241C238:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8241C23C:
	// lwz r10,332(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// stb r11,429(r31)
	REX_STORE_U8(ctx.r31.u32 + 429, ctx.r11.u8);
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8241c270
	if (!ctx.cr0.eq) goto loc_8241C270;
	// lwz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8241c270
	if (!ctx.cr0.eq) goto loc_8241C270;
	// lbz r11,152(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 152);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x8241c274
	if (!ctx.cr0.eq) goto loc_8241C274;
loc_8241C270:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8241C274:
	// lwz r10,436(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// li r9,12
	ctx.r9.s64 = 12;
	// stb r11,428(r31)
	REX_STORE_U8(ctx.r31.u32 + 428, ctx.r11.u8);
	// stw r9,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// lbz r11,448(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 448);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8241c2ac
	if (ctx.cr0.eq) goto loc_8241C2AC;
	// lwz r11,492(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 492);
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// b 0x8241c2b4
	goto loc_8241C2B4;
loc_8241C29C:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r29,r11,27412
	ctx.r29.s64 = ctx.r11.s64 + 27412;
loc_8241C2A4:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// b 0x8241c204
	goto loc_8241C204;
loc_8241C2AC:
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// lwz r10,396(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
loc_8241C2B4:
	// lwz r9,436(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// stw r11,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r11.u32);
	// lwz r11,436(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// stw r10,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r11,436(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x823bdef8
	ctx.lr = 0x8241C2D0;
	sub_823BDEF8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r30,r11,31384
	ctx.r30.s64 = ctx.r11.s64 + 31384;
	// lwz r11,532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 532);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8241c37c
	if (ctx.cr6.eq) goto loc_8241C37C;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c9fd0
	ctx.lr = 0x8241C2F0;
	sub_823C9FD0(ctx, base);
	// lwz r11,532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 532);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// bl 0x82524ba8
	ctx.lr = 0x8241C300;
	sub_82524BA8(ctx, base);
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
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
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x823b56a0
	ctx.lr = 0x8241C320;
	sub_823B56A0(ctx, base);
	// lwz r11,532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 532);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mullw r5,r11,r10
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// bl 0x82738a28
	ctx.lr = 0x8241C340;
	sub_82738A28(ctx, base);
	// lwz r11,532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 532);
	// lfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x823c9ec0
	ctx.lr = 0x8241C358;
	sub_823C9EC0(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// addi r4,r10,-30716
	ctx.r4.s64 = ctx.r10.s64 + -30716;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,2664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2664);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,532(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 532);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x823c9ec0
	ctx.lr = 0x8241C37C;
	sub_823C9EC0(ctx, base);
loc_8241C37C:
	// lbz r11,540(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 540);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8241c4e8
	if (ctx.cr0.eq) goto loc_8241C4E8;
	// lfs f0,544(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 544);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fadds f12,f0,f31
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfs f0,232(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f30,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// stfs f12,544(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 544, temp.u32);
	// lfs f13,-32216(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f31,f12,f13
	ctx.f31.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bge cr6,0x8241c3b8
	if (!ctx.cr6.lt) goto loc_8241C3B8;
	// fmr f31,f0
	ctx.f31.f64 = ctx.f0.f64;
	// b 0x8241c3c4
	goto loc_8241C3C4;
loc_8241C3B8:
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// ble cr6,0x8241c3c4
	if (!ctx.cr6.gt) goto loc_8241C3C4;
	// fmr f31,f30
	ctx.f31.f64 = ctx.f30.f64;
loc_8241C3C4:
	// bl 0x82213210
	ctx.lr = 0x8241C3C8;
	sub_82213210(ctx, base);
	// lwz r11,536(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 536);
	// lwz r10,13452(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 13452);
	// fsubs f0,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f31.f64));
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82738a28
	ctx.lr = 0x8241C414;
	sub_82738A28(ctx, base);
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
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
	ctx.lr = 0x8241C438;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,232(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,544(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 544);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8241c4e8
	if (ctx.cr6.lt) goto loc_8241C4E8;
	// lfs f12,2044(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 2044);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x8241c470
	if (!ctx.cr6.lt) goto loc_8241C470;
	// lbz r11,541(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 541);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8241c4e8
	if (ctx.cr0.eq) goto loc_8241C4E8;
	// li r3,232
	ctx.r3.s64 = 232;
	// bl 0x825762c8
	ctx.lr = 0x8241C468;
	sub_825762C8(ctx, base);
	// stb r26,541(r31)
	REX_STORE_U8(ctx.r31.u32 + 541, ctx.r26.u8);
	// b 0x8241c4e8
	goto loc_8241C4E8;
loc_8241C470:
	// lfs f12,3420(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 3420);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x8241c4a4
	if (!ctx.cr6.lt) goto loc_8241C4A4;
	// lbz r11,541(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 541);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8241c4e8
	if (!ctx.cr0.eq) goto loc_8241C4E8;
	// li r3,372
	ctx.r3.s64 = 372;
	// bl 0x825762c8
	ctx.lr = 0x8241C490;
	sub_825762C8(ctx, base);
	// li r3,232
	ctx.r3.s64 = 232;
	// bl 0x825762c8
	ctx.lr = 0x8241C498;
	sub_825762C8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,541(r31)
	REX_STORE_U8(ctx.r31.u32 + 541, ctx.r11.u8);
	// b 0x8241c4e8
	goto loc_8241C4E8;
loc_8241C4A4:
	// stfs f13,544(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 544, temp.u32);
	// stb r26,540(r31)
	REX_STORE_U8(ctx.r31.u32 + 540, ctx.r26.u8);
	// bl 0x82213210
	ctx.lr = 0x8241C4B0;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// lwz r5,9332(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 9332);
	// bl 0x82738a28
	ctx.lr = 0x8241C4C4;
	sub_82738A28(ctx, base);
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
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
	ctx.lr = 0x8241C4E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8241C4E8:
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8243B710) {
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
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,2340(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 2340);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-16508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -16508);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lwz r10,1096(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 1096);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8243B750;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8243b858
	if (ctx.cr0.eq) goto loc_8243B858;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,588(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 588);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8243B76C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8243b808
	if (ctx.cr0.eq) goto loc_8243B808;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,2344(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 2344);
	// lwz r11,-12844(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12844);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8243b7b0
	if (ctx.cr6.eq) goto loc_8243B7B0;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,36
	ctx.r8.s64 = 36;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r8
	ctx.r11.u64 = uint32_t((ctx.r8.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r8.s32 == -1)) ? ctx.r11.s32 / ctx.r8.s32 : 0);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8243b7b0
	if (!ctx.cr6.gt) goto loc_8243B7B0;
	// mulli r11,r9,36
	ctx.r11.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(36));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8243b7b4
	goto loc_8243B7B4;
loc_8243B7B0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8243B7B4:
	// addi r10,r1,79
	ctx.r10.s64 = ctx.r1.s64 + 79;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_8243B7BC:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bne 0x8243b7bc
	if (!ctx.cr0.eq) goto loc_8243B7BC;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,4824
	ctx.r10.s64 = ctx.r10.s64 + 4824;
loc_8243B7D8:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8243b7d8
	if (!ctx.cr6.eq) goto loc_8243B7D8;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_8243B7EC:
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
	// bne cr6,0x8243b7ec
	if (!ctx.cr6.eq) goto loc_8243B7EC;
	// b 0x8243b81c
	goto loc_8243B81C;
loc_8243B808:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-30428
	ctx.r4.s64 = ctx.r11.s64 + -30428;
	// li r5,6
	ctx.r5.s64 = 6;
	// bl 0x8273a030
	ctx.lr = 0x8243B81C;
	sub_8273A030(ctx, base);
loc_8243B81C:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_8243B824:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8243b824
	if (!ctx.cr6.eq) goto loc_8243B824;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_8243B838:
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
	// bne cr6,0x8243b838
	if (!ctx.cr6.eq) goto loc_8243B838;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82575df0
	ctx.lr = 0x8243B858;
	sub_82575DF0(ctx, base);
loc_8243B858:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
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

DEFINE_REX_FUNC(sub_82446898) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82446980
	if (ctx.cr6.eq) goto loc_82446980;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,16(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
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
	// bne cr6,0x82446980
	if (!ctx.cr6.eq) goto loc_82446980;
	// lwz r31,4(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82446980
	if (ctx.cr6.eq) goto loc_82446980;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm. r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82446980
	if (ctx.cr0.eq) goto loc_82446980;
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244690c
	if (ctx.cr0.eq) goto loc_8244690C;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82446980
	if (ctx.cr0.eq) goto loc_82446980;
	// b 0x82446918
	goto loc_82446918;
loc_8244690C:
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x824443c8
	ctx.lr = 0x82446914;
	sub_824443C8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_82446918:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82446980
	if (ctx.cr6.eq) goto loc_82446980;
	// lwz r11,2352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2352);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82446980
	if (!ctx.cr6.eq) goto loc_82446980;
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
	ctx.lr = 0x82446944;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82446978
	if (ctx.cr0.eq) goto loc_82446978;
	// li r9,276
	ctx.r9.s64 = 276;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,20580
	ctx.r11.s64 = ctx.r11.s64 + 20580;
	// stw r9,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// b 0x8244697c
	goto loc_8244697C;
loc_82446978:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244697C:
	// bl 0x825a2ef8
	ctx.lr = 0x82446980;
	sub_825A2EF8(ctx, base);
loc_82446980:
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

DEFINE_REX_FUNC(sub_8244C900) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8244C908;
	__savegprlr_28(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8244ca9c
	if (ctx.cr6.eq) goto loc_8244CA9C;
	// lwz r3,2340(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1024(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1024);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244C930;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// clrlwi. r11,r3,31
	ctx.r11.u64 = ctx.r3.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244c944
	if (ctx.cr0.eq) goto loc_8244C944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244ced8
	ctx.lr = 0x8244C944;
	sub_8244CED8(ctx, base);
loc_8244C944:
	// rlwinm. r11,r30,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244c954
	if (ctx.cr0.eq) goto loc_8244C954;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244ce00
	ctx.lr = 0x8244C954;
	sub_8244CE00(ctx, base);
loc_8244C954:
	// rlwinm. r11,r30,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244c964
	if (ctx.cr0.eq) goto loc_8244C964;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244d078
	ctx.lr = 0x8244C964;
	sub_8244D078(ctx, base);
loc_8244C964:
	// rlwinm. r11,r30,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244c974
	if (ctx.cr0.eq) goto loc_8244C974;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244cfa8
	ctx.lr = 0x8244C974;
	sub_8244CFA8(ctx, base);
loc_8244C974:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f13,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-24428(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24428);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8244c9cc
	if (!ctx.cr6.lt) goto loc_8244C9CC;
	// li r29,1
	ctx.r29.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x8244ca9c
	if (!ctx.cr6.gt) goto loc_8244CA9C;
	// addi r30,r31,108
	ctx.r30.s64 = ctx.r31.s64 + 108;
loc_8244C99C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8244c9b4
	if (ctx.cr6.eq) goto loc_8244C9B4;
	// addi r5,r30,-20
	ctx.r5.s64 = ctx.r30.s64 + -20;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244caa8
	ctx.lr = 0x8244C9B4;
	sub_8244CAA8(ctx, base);
loc_8244C9B4:
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,20
	ctx.r30.s64 = ctx.r30.s64 + 20;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8244c99c
	if (ctx.cr6.lt) goto loc_8244C99C;
	// b 0x8244ca9c
	goto loc_8244CA9C;
loc_8244C9CC:
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x8244ca9c
	if (!ctx.cr6.gt) goto loc_8244CA9C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r4,r31,92
	ctx.r4.s64 = ctx.r31.s64 + 92;
	// addi r30,r11,32720
	ctx.r30.s64 = ctx.r11.s64 + 32720;
	// addi r29,r10,32688
	ctx.r29.s64 = ctx.r10.s64 + 32688;
loc_8244C9EC:
	// addic. r11,r4,16
	ctx.xer.ca = ctx.r4.u32 > 4294967279;
	ctx.r11.s64 = ctx.r4.s64 + 16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244ca88
	if (ctx.cr0.eq) goto loc_8244CA88;
	// addic. r11,r4,-4
	ctx.xer.ca = ctx.r4.u32 > 3;
	ctx.r11.s64 = ctx.r4.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244ca88
	if (ctx.cr0.eq) goto loc_8244CA88;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// vor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,28(r4)
	REX_STORE_U64(ctx.r4.u32 + 28, ctx.r10.u64);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,84(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 84);
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
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x8244CA78;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,20(r4)
	REX_STORE_U32(ctx.r4.u32 + 20, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,24(r4)
	REX_STORE_U32(ctx.r4.u32 + 24, ctx.r11.u32);
loc_8244CA88:
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r4,r4,20
	ctx.r4.s64 = ctx.r4.s64 + 20;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8244c9ec
	if (ctx.cr6.lt) goto loc_8244C9EC;
loc_8244CA9C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8245AFD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x8245AFE0;
	__savegprlr_19(ctx, base);
	// stfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.f29.u64);
	// stfd f30,-128(r1)
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.f30.u64);
	// stfd f31,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f31.u64);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r26,r1,144
	ctx.r26.s64 = ctx.r1.s64 + 144;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r11,r11,32608
	ctx.r11.s64 = ctx.r11.s64 + 32608;
	// lfs f0,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r27,r9
	ctx.r27.u64 = ctx.r9.u64;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r25,r1,128
	ctx.r25.s64 = ctx.r1.s64 + 128;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r24,-32112
	ctx.r24.s64 = -2104492032;
	// lvx128 v59,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r1,128
	ctx.r23.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f12,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r22,r1,128
	ctx.r22.s64 = ctx.r1.s64 + 128;
	// stfs f12,188(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r31,r11,32256
	ctx.r31.s64 = ctx.r11.s64 + 32256;
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lwz r11,-12872(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -12872);
	// stfs f12,180(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f11,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v60,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
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
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f11,152(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f11,148(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// vmulfp128 v60,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f11,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v61,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v59,v61
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
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
	// stvx128 v61,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stvx128 v60,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lvx128 v58,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v59,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v59,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vaddfp128 v60,v60,v58
	simde_mm_store_ps(ctx.v60.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v58.f32)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,12468
	ctx.r10.s64 = ctx.r10.s64 + 12468;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,-232(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8245b1dc
	if (ctx.cr6.eq) goto loc_8245B1DC;
	// lfs f0,664(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8245b1e0
	goto loc_8245B1E0;
loc_8245B1DC:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_8245B1E0:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// fdivs f10,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r11,-15444(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15444);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r9,-15432(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + -15432);
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1908(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1908);
	ctx.f12.f64 = double(temp.f32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// addi r26,r1,256
	ctx.r26.s64 = ctx.r1.s64 + 256;
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
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
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r30,r1,160
	ctx.r30.s64 = ctx.r1.s64 + 160;
	// cmplwi cr6,r28,7
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 7, ctx.xer);
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// vpermwi128 v60,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// lvx128 v58,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfd f11,144(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r9,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// lfd f9,144(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f9,f10
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fmuls f10,f11,f10
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// lvx128 v57,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f9,f9,f12
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f9,108(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmuls f10,f10,f12
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f10,92(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v56,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v56,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v57.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v57.f32)));
	// lvx128 v56,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v58,v56
	simde_mm_store_ps(ctx.v58.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v56.f32)));
	// stvx128 v58,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8245b3b0
	if (ctx.cr6.lt) goto loc_8245B3B0;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f30,0(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// stfs f30,88(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v54,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vpermwi128 v0,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vpermwi128 v13,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
loc_8245B324:
	// vmulfp128 v11,v57,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmulfp128 v9,v56,v58
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v10,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vmulfp128 v7,v55,v58
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v8,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vmulfp128 v5,v54,v58
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v2,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// vspltw128 v3,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// stfs f13,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vspltw128 v4,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vspltw128 v6,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// vspltw128 v1,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vspltw128 v31,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vspltw128 v30,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vspltw128 v29,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vspltw128 v28,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v12,v12,v0,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v11,v10,v0,v9
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v10,v8,v0,v7
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v9,v6,v0,v5
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v12,v4,v13,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v11,v3,v13,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v10,v2,v13,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v13,v1,v13,v9
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v12,v31,v0,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v11,v30,v0,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// stvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v10,v29,v0,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v0,v28,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8245b4d4
	goto loc_8245B4D4;
loc_8245B3B0:
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-6040
	ctx.r12.s64 = ctx.r12.s64 + -6040;
	// lbzx r0,r12,r28
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r28.u32);
	// lis r12,-32186
	ctx.r12.s64 = -2109341696;
	// nop 
	// addi r12,r12,-19496
	ctx.r12.s64 = ctx.r12.s64 + -19496;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r28.u32) {
	case 0:
		goto loc_8245B3E0;
	case 1:
		goto loc_8245B3D8;
	case 2:
		goto loc_8245B3E0;
	case 3:
		goto loc_8245B3E0;
	case 4:
		goto loc_8245B3D8;
	case 5:
		goto loc_8245B3E0;
	case 6:
		goto loc_8245B3D8;
	case 7:
		goto loc_8245B3E0;
	case 8:
		goto loc_8245B3E0;
	case 9:
		goto loc_8245B3D8;
	case 10:
		goto loc_8245B3E0;
	case 11:
		goto loc_8245B3D8;
	case 12:
		goto loc_8245B3D8;
	case 13:
		goto loc_8245B3D8;
	case 14:
		goto loc_8245B3D8;
	case 15:
		goto loc_8245B3D8;
	case 16:
		goto loc_8245B3D8;
	case 17:
		goto loc_8245B3DC;
	case 18:
		goto loc_8245B3D8;
	case 19:
		goto loc_8245B3D8;
	case 20:
		goto loc_8245B3DC;
	case 21:
		goto loc_8245B3D8;
	case 22:
		goto loc_8245B3DC;
	case 23:
		goto loc_8245B3D8;
	case 24:
		goto loc_8245B3D8;
	case 25:
		goto loc_8245B3DC;
	case 26:
		goto loc_8245B3D8;
	case 27:
		goto loc_8245B3D8;
	case 28:
		goto loc_8245B3D8;
	case 29:
		goto loc_8245B3D8;
	case 30:
		goto loc_8245B3D8;
	case 31:
		goto loc_8245B3D8;
	case 32:
		goto loc_8245B3D8;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8245B3D8:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8245B3DC:
	// b 0x8245b3e4
	goto loc_8245B3E4;
loc_8245B3E0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8245B3E4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f30,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f30,88(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v54,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vpermwi128 v0,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vpermwi128 v13,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// bne 0x8245b434
	if (!ctx.cr0.eq) goto loc_8245B434;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8245b324
	goto loc_8245B324;
loc_8245B434:
	// vmulfp128 v29,v57,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v30,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmulfp128 v31,v56,v58
	simde_mm_store_ps(ctx.v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v28,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vmulfp128 v2,v55,v58
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v1,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vmulfp128 v4,v54,v58
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v58.f32)));
	// fmuls f0,f11,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// vspltw128 v3,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// vspltw128 v5,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// vspltw128 v6,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vspltw128 v7,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// vspltw128 v8,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vspltw128 v9,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vspltw128 v10,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vspltw128 v11,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vmaddfp v30,v30,v0,v29
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vspltw128 v12,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v31,v28,v0,v31
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// fdivs f0,f31,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// vmaddfp v2,v1,v0,v2
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v0,v3,v0,v4
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// fmuls f13,f0,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmaddfp v5,v5,v13,v30
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// fmuls f0,f0,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// vmaddfp v6,v6,v13,v31
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vmaddfp v7,v7,v13,v2
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v8,v8,v13,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v9,v9,v0,v5
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v10,v10,v0,v6
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v9,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
loc_8245B4D4:
	// stvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi. r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// beq 0x8245b790
	if (ctx.cr0.eq) goto loc_8245B790;
	// bl 0x825f8d38
	ctx.lr = 0x8245B4EC;
	sub_825F8D38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8245b514
	if (ctx.cr0.eq) goto loc_8245B514;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8b88
	ctx.lr = 0x8245B4FC;
	sub_825F8B88(ctx, base);
	// li r6,64
	ctx.r6.s64 = 64;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x8245B510;
	sub_825F8BF8(ctx, base);
	// b 0x8245b518
	goto loc_8245B518;
loc_8245B514:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8245B518:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r26,r1,96
	ctx.r26.s64 = ctx.r1.s64 + 96;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v54,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r25,r1,144
	ctx.r25.s64 = ctx.r1.s64 + 144;
	// lvx128 v52,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// vslw128 v61,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// vslw128 v60,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r24,r1,160
	ctx.r24.s64 = ctx.r1.s64 + 160;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lwz r11,424(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 424);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r23,r1,128
	ctx.r23.s64 = ctx.r1.s64 + 128;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r22,r11,40
	ctx.r22.s64 = ctx.r11.s64 + 40;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v56,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v56,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// lvx128 v59,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v61,v54,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// vor128 v57,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// vmulfp128 v62,v62,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v55,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// stfs f13,184(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// vor128 v58,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// vor128 v53,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// lvx128 v51,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v57.f32)));
	// stvx128 v61,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v60,v51,v60
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// stfs f30,168(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// vmulfp128 v60,v60,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v55.f32)));
	// stfs f31,172(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// vmulfp128 v58,v52,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v58.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v52.f32), simde_mm_load_ps(ctx.v58.f32)));
	// lvx128 v50,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// vmulfp128 v53,v50,v53
	simde_mm_store_ps(ctx.v53.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v50.f32), simde_mm_load_ps(ctx.v53.f32)));
	// lfs f12,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lfs f10,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f10.f64 = double(temp.f32);
	// stfs f30,136(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stvx128 v60,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v58,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lwz r10,0(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r9,4(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// stvx128 v53,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,8(r24)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// lwz r7,12(r24)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r24.u32 + 12);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vor128 v62,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// vor128 v61,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r25,r1,128
	ctx.r25.s64 = ctx.r1.s64 + 128;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r21,0(r23)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r20,4(r23)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r23.u32 + 4);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lwz r19,8(r23)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r23.u32 + 8);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lwz r23,12(r23)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r23.u32 + 12);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// addi r26,r1,80
	ctx.r26.s64 = ctx.r1.s64 + 80;
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r24,r1,96
	ctx.r24.s64 = ctx.r1.s64 + 96;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r22,r1,112
	ctx.r22.s64 = ctx.r1.s64 + 112;
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r7,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// stw r21,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r21.u32);
	// stw r20,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r20.u32);
	// stw r19,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r19.u32);
	// stw r23,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r23.u32);
	// stw r29,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r29.u32);
	// lvx128 v60,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r29,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r29.u32);
	// vmulfp128 v62,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v59,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v59,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// lvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f30,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r29,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r29.u32);
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r29,148(r11)
	REX_STORE_U32(ctx.r11.u32 + 148, ctx.r29.u32);
	// vmulfp128 v62,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v62,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r8,8(r24)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,4(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r10.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r9,0(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r4,0(r22)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// lwz r3,4(r22)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + 4);
	// lwz r7,12(r24)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r24.u32 + 12);
	// stw r8,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r8.u32);
	// stw r9,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r9.u32);
	// stw r7,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r7.u32);
	// lwz r5,12(r22)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r22.u32 + 12);
	// lwz r6,8(r22)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r22.u32 + 8);
	// stw r3,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r3.u32);
	// stw r4,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r4.u32);
	// stw r6,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r6.u32);
	// stw r5,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r5.u32);
	// b 0x8245ba44
	goto loc_8245BA44;
loc_8245B790:
	// bl 0x825f8d38
	ctx.lr = 0x8245B794;
	sub_825F8D38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8245b7bc
	if (ctx.cr0.eq) goto loc_8245B7BC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8b88
	ctx.lr = 0x8245B7A4;
	sub_825F8B88(ctx, base);
	// li r6,64
	ctx.r6.s64 = 64;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x8245B7B8;
	sub_825F8BF8(ctx, base);
	// b 0x8245b7c0
	goto loc_8245B7C0;
loc_8245B7BC:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8245B7C0:
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// vslw128 v61,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// addi r26,r1,160
	ctx.r26.s64 = ctx.r1.s64 + 160;
	// lvx128 v59,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v60,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vor128 v57,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vor128 v55,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vor128 v58,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r25,r1,192
	ctx.r25.s64 = ctx.r1.s64 + 192;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r24,r1,176
	ctx.r24.s64 = ctx.r1.s64 + 176;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r4,424(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 424);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r23,r1,144
	ctx.r23.s64 = ctx.r1.s64 + 144;
	// stfs f30,184(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r22,r4,40
	ctx.r22.s64 = ctx.r4.s64 + 40;
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v54,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f30,152(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v56,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v61,v56,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// vmulfp128 v61,v61,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v57.f32)));
	// lvx128 v56,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// vxor128 v60,v56,v60
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// lvx128 v53,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v53,v58
	simde_mm_store_ps(ctx.v58.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v53.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vxor128 v62,v54,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvx128 v61,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v60,v55
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v55.f32)));
	// stvx128 v58,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v54,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// stfs f13,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// vmulfp128 v62,v62,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v59.f32)));
	// lvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v59,v54
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v54.f32)));
	// lfs f11,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v60,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,180(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lfs f10,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,176(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lwz r11,8(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,12(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 12);
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stvx128 v62,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r8,4(r24)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r25,r1,80
	ctx.r25.s64 = ctx.r1.s64 + 80;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// vor128 v62,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v54.u8));
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// vor128 v60,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v54.u8));
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r26,r1,192
	ctx.r26.s64 = ctx.r1.s64 + 192;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r22,r1,128
	ctx.r22.s64 = ctx.r1.s64 + 128;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vor128 v61,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v54.u8));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// addi r21,r1,96
	ctx.r21.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r24,r1,192
	ctx.r24.s64 = ctx.r1.s64 + 192;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r10,12(r4)
	REX_STORE_U32(ctx.r4.u32 + 12, ctx.r10.u32);
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r11,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r8,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r8.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stw r29,28(r4)
	REX_STORE_U32(ctx.r4.u32 + 28, ctx.r29.u32);
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r19,r1,112
	ctx.r19.s64 = ctx.r1.s64 + 112;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r5,0(r23)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r3,4(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 4);
	// addi r31,r4,160
	ctx.r31.s64 = ctx.r4.s64 + 160;
	// lwz r20,8(r23)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r23.u32 + 8);
	// lwz r23,12(r23)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r23.u32 + 12);
	// stw r29,68(r4)
	REX_STORE_U32(ctx.r4.u32 + 68, ctx.r29.u32);
	// stw r5,40(r4)
	REX_STORE_U32(ctx.r4.u32 + 40, ctx.r5.u32);
	// li r5,40
	ctx.r5.s64 = 40;
	// lvx128 v59,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r3,44(r4)
	REX_STORE_U32(ctx.r4.u32 + 44, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r20,48(r4)
	REX_STORE_U32(ctx.r4.u32 + 48, ctx.r20.u32);
	// stw r23,52(r4)
	REX_STORE_U32(ctx.r4.u32 + 52, ctx.r23.u32);
	// stw r29,108(r4)
	REX_STORE_U32(ctx.r4.u32 + 108, ctx.r29.u32);
	// lvx128 v58,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r29,148(r4)
	REX_STORE_U32(ctx.r4.u32 + 148, ctx.r29.u32);
	// vmulfp128 v62,v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v58,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v58,v60
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vxor128 v63,v59,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v62,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r10,12(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 12);
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,8(r21)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r21.u32 + 8);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// stw r11,80(r4)
	REX_STORE_U32(ctx.r4.u32 + 80, ctx.r11.u32);
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,4(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stw r9,88(r4)
	REX_STORE_U32(ctx.r4.u32 + 88, ctx.r9.u32);
	// stw r10,92(r4)
	REX_STORE_U32(ctx.r4.u32 + 92, ctx.r10.u32);
	// lwz r10,4(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 4);
	// lwz r9,8(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 8);
	// stw r11,84(r4)
	REX_STORE_U32(ctx.r4.u32 + 84, ctx.r11.u32);
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// lwz r8,12(r19)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r19.u32 + 12);
	// stw r11,120(r4)
	REX_STORE_U32(ctx.r4.u32 + 120, ctx.r11.u32);
	// stw r10,124(r4)
	REX_STORE_U32(ctx.r4.u32 + 124, ctx.r10.u32);
	// stw r9,128(r4)
	REX_STORE_U32(ctx.r4.u32 + 128, ctx.r9.u32);
	// stw r8,132(r4)
	REX_STORE_U32(ctx.r4.u32 + 132, ctx.r8.u32);
	// bl 0x8273a030
	ctx.lr = 0x8245BA44;
	sub_8273A030(ctx, base);
loc_8245BA44:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8245ba70
	if (!ctx.cr6.eq) goto loc_8245BA70;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r4,19
	ctx.r4.s64 = 19;
	// addi r3,r10,7524
	ctx.r3.s64 = ctx.r10.s64 + 7524;
	// lwz r11,-15508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15508);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8245BA68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x8245BA6C;
	sub_8245A220(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_8245BA70:
	// lwz r11,408(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stfs f29,412(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r30.u32 + 412, temp.u32);
	// stw r27,76(r30)
	REX_STORE_U32(ctx.r30.u32 + 76, ctx.r27.u32);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// stw r11,408(r30)
	REX_STORE_U32(ctx.r30.u32 + 408, ctx.r11.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// lwz r11,3596(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 3596);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,368(r30)
	REX_STORE_U32(ctx.r30.u32 + 368, ctx.r11.u32);
	// lwz r11,408(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// ori r11,r11,448
	ctx.r11.u64 = ctx.r11.u64 | 448;
	// stw r11,408(r30)
	REX_STORE_U32(ctx.r30.u32 + 408, ctx.r11.u32);
	// bl 0x8273a030
	ctx.lr = 0x8245BAAC;
	sub_8273A030(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82459d08
	ctx.lr = 0x8245BABC;
	sub_82459D08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
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

DEFINE_REX_FUNC(sub_824E56D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x824E56E0;
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
	// lbz r11,304(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 304);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824e5798
	if (ctx.cr0.eq) goto loc_824E5798;
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
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
	ctx.lr = 0x824E571C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,316(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f13,320(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-32080
	ctx.r11.s64 = ctx.r11.s64 + -32080;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stb r6,304(r31)
	REX_STORE_U8(ctx.r31.u32 + 304, ctx.r6.u8);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
loc_824E5798:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-6412
	ctx.r11.s64 = ctx.r11.s64 + -6412;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x824e58f0
	if (!ctx.cr6.lt) goto loc_824E58F0;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f13,26756(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26756);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// addi r29,r10,-4080
	ctx.r29.s64 = ctx.r10.s64 + -4080;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stfs f0,280(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 280, temp.u32);
	// addi r9,r9,12468
	ctx.r9.s64 = ctx.r9.s64 + 12468;
	// addi r30,r11,-30128
	ctx.r30.s64 = ctx.r11.s64 + -30128;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x824e5808
	if (!ctx.cr6.lt) goto loc_824E5808;
	// lfs f13,848(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 848);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f31,f0,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f13,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,1908(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1908);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// fmuls f13,f31,f13
	ctx.f13.f64 = double(float(ctx.f31.f64 * ctx.f13.f64));
	// fmadds f1,f0,f12,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f12.f64, ctx.f13.f64)));
	// b 0x824e5810
	goto loc_824E5810;
loc_824E5808:
	// lfs f1,-30128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,-232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
loc_824E5810:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E5820;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f12,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 280);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-896(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -896);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f30,f0,f13
	ctx.f30.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x824E5840;
	sub_822EA1A8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r9,r9,32720
	ctx.r9.s64 = ctx.r9.s64 + 32720;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f0,-29492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
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
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E58B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,236(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f30,f0
	ctx.f1.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x822ea1a8
	ctx.lr = 0x824E58C8;
	sub_822EA1A8(ctx, base);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r10,100(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// lfs f13,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 288);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-848(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -848);
	ctx.f0.f64 = double(temp.f32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// bctrl 
	ctx.lr = 0x824E58EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x824e5944
	goto loc_824E5944;
loc_824E58F0:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f1,-30128(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E5910;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// lwz r10,300(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// addi r11,r11,22872
	ctx.r11.s64 = ctx.r11.s64 + 22872;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x824e5944
	if (ctx.cr6.eq) goto loc_824E5944;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32178
	ctx.r10.s64 = -2108817408;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r10,r10,22872
	ctx.r10.s64 = ctx.r10.s64 + 22872;
	// stb r9,304(r31)
	REX_STORE_U8(ctx.r31.u32 + 304, ctx.r9.u8);
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r10.u32);
	// stfs f0,280(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 280, temp.u32);
loc_824E5944:
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

DEFINE_REX_FUNC(sub_824F9A58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x824F9A60;
	__savegprlr_23(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
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
	// li r23,24
	ctx.r23.s64 = 24;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824f9a88
	if (!ctx.cr6.eq) goto loc_824F9A88;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x824f9a94
	goto loc_824F9A94;
loc_824F9A88:
	// lwz r10,12(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// divw r9,r10,r23
	ctx.r9.u64 = uint32_t((ctx.r23.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r10.s32 / ctx.r23.s32 : 0);
loc_824F9A94:
	// lwz r31,8(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lis r10,2730
	ctx.r10.s64 = 178913280;
	// subf r11,r11,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r11.u64;
	// ori r10,r10,43690
	ctx.r10.u64 = ctx.r10.u64 | 43690;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// subf r8,r11,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bge cr6,0x824f9afc
	if (!ctx.cr6.lt) goto loc_824F9AFC;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,56
	ctx.r4.s64 = ctx.r11.s64 + 56;
	// bl 0x822167f8
	ctx.lr = 0x824F9AC4;
	sub_822167F8(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82216678
	ctx.lr = 0x824F9AD0;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x824F9AD4;
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
	ctx.lr = 0x824F9AE8;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235ec48
	ctx.lr = 0x824F9AF8;
	sub_8235EC48(ctx, base);
	// b 0x824f9dac
	goto loc_824F9DAC;
loc_824F9AFC:
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x824f9c34
	if (!ctx.cr6.lt) goto loc_824F9C34;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x824f9b20
	if (!ctx.cr6.lt) goto loc_824F9B20;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x824f9b24
	goto loc_824F9B24;
loc_824F9B20:
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_824F9B24:
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x824f9b30
	if (!ctx.cr6.lt) goto loc_824F9B30;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_824F9B30:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mulli r24,r11,24
	ctx.r24.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824F9B4C;
	sub_825E02A0(ctx, base);
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// divw r26,r11,r23
	ctx.r26.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// mulli r25,r26,24
	ctx.r25.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(24));
	// add. r3,r25,r3
	ctx.r3.u64 = ctx.r25.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x824f9b74
	if (ctx.cr0.eq) goto loc_824F9B74;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x824F9B74;
	sub_8273A030(ctx, base);
loc_824F9B74:
	// lwz r29,4(r28)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mr r27,r31
	ctx.r27.u64 = ctx.r31.u64;
	// b 0x824f9ba0
	goto loc_824F9BA0;
loc_824F9B80:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x824f9b98
	if (ctx.cr6.eq) goto loc_824F9B98;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273a030
	ctx.lr = 0x824F9B98;
	sub_8273A030(ctx, base);
loc_824F9B98:
	// addi r29,r29,24
	ctx.r29.s64 = ctx.r29.s64 + 24;
	// addi r27,r27,24
	ctx.r27.s64 = ctx.r27.s64 + 24;
loc_824F9BA0:
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x824f9b80
	if (!ctx.cr6.eq) goto loc_824F9B80;
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// lwz r27,8(r28)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// add r29,r11,r31
	ctx.r29.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x824f9bf8
	if (ctx.cr6.eq) goto loc_824F9BF8;
	// subf r11,r25,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r25.u64;
	// subf r11,r31,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r31.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r30,r11,-24
	ctx.r30.s64 = ctx.r11.s64 + -24;
loc_824F9BD0:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x824f9be8
	if (ctx.cr6.eq) goto loc_824F9BE8;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x824F9BE8;
	sub_8273A030(ctx, base);
loc_824F9BE8:
	// addi r30,r30,24
	ctx.r30.s64 = ctx.r30.s64 + 24;
	// addi r29,r29,24
	ctx.r29.s64 = ctx.r29.s64 + 24;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x824f9bd0
	if (!ctx.cr6.eq) goto loc_824F9BD0;
loc_824F9BF8:
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
	// beq cr6,0x824f9c18
	if (ctx.cr6.eq) goto loc_824F9C18;
	// bl 0x825e0378
	ctx.lr = 0x824F9C18;
	sub_825E0378(ctx, base);
loc_824F9C18:
	// mulli r11,r30,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(24));
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
	// b 0x824f9dac
	goto loc_824F9DAC;
loc_824F9C34:
	// subf r11,r30,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// divw r11,r11,r23
	ctx.r11.u64 = uint32_t((ctx.r23.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r11.s32 / ctx.r23.s32 : 0);
	// li r5,24
	ctx.r5.s64 = 24;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bge cr6,0x824f9d0c
	if (!ctx.cr6.lt) goto loc_824F9D0C;
	// bl 0x8273a030
	ctx.lr = 0x824F9C54;
	sub_8273A030(ctx, base);
	// addi r29,r30,24
	ctx.r29.s64 = ctx.r30.s64 + 24;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x824f9c8c
	if (ctx.cr6.eq) goto loc_824F9C8C;
	// addi r27,r29,-24
	ctx.r27.s64 = ctx.r29.s64 + -24;
loc_824F9C64:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x824f9c7c
	if (ctx.cr6.eq) goto loc_824F9C7C;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x824F9C7C;
	sub_8273A030(ctx, base);
loc_824F9C7C:
	// addi r27,r27,24
	ctx.r27.s64 = ctx.r27.s64 + 24;
	// addi r29,r29,24
	ctx.r29.s64 = ctx.r29.s64 + 24;
	// cmplw cr6,r27,r31
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x824f9c64
	if (!ctx.cr6.eq) goto loc_824F9C64;
loc_824F9C8C:
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
	// beq cr6,0x824f9cd0
	if (ctx.cr6.eq) goto loc_824F9CD0;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_824F9CAC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824f9cc4
	if (ctx.cr6.eq) goto loc_824F9CC4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x824F9CC4;
	sub_8273A030(ctx, base);
loc_824F9CC4:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// bne 0x824f9cac
	if (!ctx.cr0.eq) goto loc_824F9CAC;
loc_824F9CD0:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// addi r29,r11,-24
	ctx.r29.s64 = ctx.r11.s64 + -24;
	// stw r11,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r11.u32);
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x824f9dac
	if (ctx.cr6.eq) goto loc_824F9DAC;
loc_824F9CEC:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x824F9CFC;
	sub_8273A030(ctx, base);
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x824f9cec
	if (!ctx.cr6.eq) goto loc_824F9CEC;
	// b 0x824f9dac
	goto loc_824F9DAC;
loc_824F9D0C:
	// bl 0x8273a030
	ctx.lr = 0x824F9D10;
	sub_8273A030(ctx, base);
	// addi r27,r31,-24
	ctx.r27.s64 = ctx.r31.s64 + -24;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
	// cmplw cr6,r27,r31
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x824f9d4c
	if (ctx.cr6.eq) goto loc_824F9D4C;
loc_824F9D24:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x824f9d3c
	if (ctx.cr6.eq) goto loc_824F9D3C;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x824F9D3C;
	sub_8273A030(ctx, base);
loc_824F9D3C:
	// addi r26,r26,24
	ctx.r26.s64 = ctx.r26.s64 + 24;
	// addi r29,r29,24
	ctx.r29.s64 = ctx.r29.s64 + 24;
	// cmplw cr6,r26,r31
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x824f9d24
	if (!ctx.cr6.eq) goto loc_824F9D24;
loc_824F9D4C:
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x824f9d80
	if (ctx.cr6.eq) goto loc_824F9D80;
	// addi r29,r27,24
	ctx.r29.s64 = ctx.r27.s64 + 24;
loc_824F9D60:
	// addi r31,r31,-24
	ctx.r31.s64 = ctx.r31.s64 + -24;
	// addi r29,r29,-24
	ctx.r29.s64 = ctx.r29.s64 + -24;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x824F9D78;
	sub_8273A030(ctx, base);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x824f9d60
	if (!ctx.cr6.eq) goto loc_824F9D60;
loc_824F9D80:
	// addi r29,r30,24
	ctx.r29.s64 = ctx.r30.s64 + 24;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x824f9dac
	if (ctx.cr6.eq) goto loc_824F9DAC;
loc_824F9D90:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x824F9DA0;
	sub_8273A030(ctx, base);
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x824f9d90
	if (!ctx.cr6.eq) goto loc_824F9D90;
loc_824F9DAC:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8250BE78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8250BE80;
	__savegprlr_28(ctx, base);
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f29.u64);
	// stfd f30,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8250c050
	if (!ctx.cr0.eq) goto loc_8250C050;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r30,r11,12236
	ctx.r30.s64 = ctx.r11.s64 + 12236;
	// lwz r11,320(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 320);
	// lis r29,-32228
	ctx.r29.s64 = -2112094208;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// lfs f29,236(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 236);
	ctx.f29.f64 = double(temp.f32);
	// lfs f31,232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// bge cr6,0x8250bf04
	if (!ctx.cr6.lt) goto loc_8250BF04;
	// lfs f0,300(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// stfs f0,300(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 300, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8250bf44
	if (!ctx.cr6.lt) goto loc_8250BF44;
	// stb r28,116(r3)
	REX_STORE_U8(ctx.r3.u32 + 116, ctx.r28.u8);
	// bl 0x8250c068
	ctx.lr = 0x8250BEE4;
	sub_8250C068(ctx, base);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lfs f0,-1628(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1628);
	ctx.f0.f64 = double(temp.f32);
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// stfs f31,300(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// stw r28,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r28.u32);
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
	// b 0x8250bf44
	goto loc_8250BF44;
loc_8250BF04:
	// lfs f0,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x8250bf44
	if (!ctx.cr6.gt) goto loc_8250BF44;
	// fsubs f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8250bf28
	if (ctx.cr6.eq) goto loc_8250BF28;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8250bf44
	if (ctx.cr6.gt) goto loc_8250BF44;
loc_8250BF28:
	// stfs f29,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,26
	ctx.r3.s64 = 26;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8257d438
	ctx.lr = 0x8250BF44;
	sub_8257D438(ctx, base);
loc_8250BF44:
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8250bfd8
	if (ctx.cr6.lt) goto loc_8250BFD8;
	// beq cr6,0x8250bf64
	if (ctx.cr6.eq) goto loc_8250BF64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8250c050
	if (!ctx.cr6.lt) goto loc_8250C050;
	// stb r28,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r28.u8);
	// b 0x8250c050
	goto loc_8250C050;
loc_8250BF64:
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// lfs f13,-1628(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1628);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8250c050
	if (!ctx.cr6.gt) goto loc_8250C050;
	// lbz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// lwz r10,312(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// addi r11,r11,6
	ctx.r11.s64 = ctx.r11.s64 + 6;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8250bfcc
	if (!ctx.cr6.lt) goto loc_8250BFCC;
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
	ctx.lr = 0x8250BFB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8250c068
	ctx.lr = 0x8250BFB8;
	sub_8250C068(ctx, base);
	// lwz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// stfs f31,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// b 0x8250c050
	goto loc_8250C050;
loc_8250BFCC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r11.u32);
	// b 0x8250c050
	goto loc_8250C050;
loc_8250BFD8:
	// lbz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 316);
	// lfs f31,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8250bff0
	if (ctx.cr0.eq) goto loc_8250BFF0;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8250bff4
	goto loc_8250BFF4;
loc_8250BFF0:
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f29.f64;
loc_8250BFF4:
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f12,304(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f0,944(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 944);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmadds f1,f0,f30,f12
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f30.f64, ctx.f12.f64)));
	// stfs f1,304(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8250C02C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,-28808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28808);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bge cr6,0x8250c050
	if (!ctx.cr6.lt) goto loc_8250C050;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,732(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 732);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f30,f0,f31
	ctx.f0.f64 = double(float(-std::fma(ctx.f30.f64, ctx.f0.f64, -ctx.f31.f64)));
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_8250C050:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

DEFINE_REX_FUNC(sub_82517F98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82517FA0;
	__savegprlr_27(ctx, base);
	// stfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f29.u64);
	// stfd f30,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f30.u64);
	// stfd f31,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r27,r11,14876
	ctx.r27.s64 = ctx.r11.s64 + 14876;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// lfs f29,-2640(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -2640);
	ctx.f29.f64 = double(temp.f32);
	// fmr f31,f29
	ctx.f31.f64 = ctx.f29.f64;
	// bne cr6,0x82518004
	if (!ctx.cr6.eq) goto loc_82518004;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82452e18
	ctx.lr = 0x82517FE0;
	sub_82452E18(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82517ff0
	if (ctx.cr0.eq) goto loc_82517FF0;
	// lha r11,10(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 10));
	// b 0x82517ff4
	goto loc_82517FF4;
loc_82517FF0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82517FF4:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x825181b8
	goto loc_825181B8;
loc_82518004:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x82518024
	if (!ctx.cr6.eq) goto loc_82518024;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82455b48
	ctx.lr = 0x82518014;
	sub_82455B48(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x825181b8
	goto loc_825181B8;
loc_82518024:
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// bne cr6,0x82518058
	if (!ctx.cr6.eq) goto loc_82518058;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x824553e0
	ctx.lr = 0x82518034;
	sub_824553E0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82518044
	if (ctx.cr0.eq) goto loc_82518044;
	// lha r11,28(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 28));
	// b 0x82518048
	goto loc_82518048;
loc_82518044:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82518048:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x825181b8
	goto loc_825181B8;
loc_82518058:
	// cmpwi cr6,r30,3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 3, ctx.xer);
	// bne cr6,0x82518078
	if (!ctx.cr6.eq) goto loc_82518078;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82455468
	ctx.lr = 0x82518068;
	sub_82455468(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x825181b8
	goto loc_825181B8;
loc_82518078:
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// bne cr6,0x825180ac
	if (!ctx.cr6.eq) goto loc_825180AC;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82456128
	ctx.lr = 0x82518088;
	sub_82456128(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82518098
	if (ctx.cr0.eq) goto loc_82518098;
	// lha r11,28(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 28));
	// b 0x8251809c
	goto loc_8251809C;
loc_82518098:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8251809C:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x825181b8
	goto loc_825181B8;
loc_825180AC:
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// bne cr6,0x825180e0
	if (!ctx.cr6.eq) goto loc_825180E0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82455910
	ctx.lr = 0x825180BC;
	sub_82455910(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825180cc
	if (ctx.cr0.eq) goto loc_825180CC;
	// lha r11,28(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 28));
	// b 0x825180d0
	goto loc_825180D0;
loc_825180CC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_825180D0:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x825181b8
	goto loc_825181B8;
loc_825180E0:
	// cmpwi cr6,r30,6
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 6, ctx.xer);
	// bne cr6,0x82518114
	if (!ctx.cr6.eq) goto loc_82518114;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82455e60
	ctx.lr = 0x825180F0;
	sub_82455E60(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82518100
	if (ctx.cr0.eq) goto loc_82518100;
	// lha r11,28(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 28));
	// b 0x82518104
	goto loc_82518104;
loc_82518100:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82518104:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x825181b8
	goto loc_825181B8;
loc_82518114:
	// cmpwi cr6,r30,7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 7, ctx.xer);
	// bne cr6,0x82518148
	if (!ctx.cr6.eq) goto loc_82518148;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82455358
	ctx.lr = 0x82518124;
	sub_82455358(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82518134
	if (ctx.cr0.eq) goto loc_82518134;
	// lha r11,28(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 28));
	// b 0x82518138
	goto loc_82518138;
loc_82518134:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82518138:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x825181b8
	goto loc_825181B8;
loc_82518148:
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// bne cr6,0x82518168
	if (!ctx.cr6.eq) goto loc_82518168;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x824557c8
	ctx.lr = 0x82518158;
	sub_824557C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x825181b8
	goto loc_825181B8;
loc_82518168:
	// cmpwi cr6,r30,9
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 9, ctx.xer);
	// bne cr6,0x8251819c
	if (!ctx.cr6.eq) goto loc_8251819C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82455f90
	ctx.lr = 0x82518178;
	sub_82455F90(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82518188
	if (ctx.cr0.eq) goto loc_82518188;
	// lha r11,14(r3)
	ctx.r11.s64 = int16_t(REX_LOAD_U16(ctx.r3.u32 + 14));
	// b 0x8251818c
	goto loc_8251818C;
loc_82518188:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8251818C:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x825181b8
	goto loc_825181B8;
loc_8251819C:
	// cmpwi cr6,r30,10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 10, ctx.xer);
	// bne cr6,0x825181c0
	if (!ctx.cr6.eq) goto loc_825181C0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x824538e8
	ctx.lr = 0x825181AC;
	sub_824538E8(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
loc_825181B8:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f31,f0
	ctx.f31.f64 = double(float(ctx.f0.f64));
loc_825181C0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8251836c
	if (ctx.cr6.eq) goto loc_8251836C;
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
	// bne cr6,0x82518208
	if (!ctx.cr6.eq) goto loc_82518208;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82518208
	if (ctx.cr6.eq) goto loc_82518208;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r10,r10,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82518208
	if (ctx.cr0.eq) goto loc_82518208;
	// lfs f31,168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 168);
	ctx.f31.f64 = double(temp.f32);
	// b 0x8251836c
	goto loc_8251836C;
loc_82518208:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824443c8
	ctx.lr = 0x82518210;
	sub_824443C8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8251836c
	if (ctx.cr0.eq) goto loc_8251836C;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// beq cr6,0x82518360
	if (ctx.cr6.eq) goto loc_82518360;
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// beq cr6,0x82518360
	if (ctx.cr6.eq) goto loc_82518360;
	// cmpwi cr6,r30,10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 10, ctx.xer);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bne cr6,0x82518240
	if (!ctx.cr6.eq) goto loc_82518240;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82439948
	ctx.lr = 0x8251823C;
	sub_82439948(ctx, base);
	// b 0x82518368
	goto loc_82518368;
loc_82518240:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82517d48
	ctx.lr = 0x82518248;
	sub_82517D48(ctx, base);
	// clrlwi r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	// fsubs f13,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 - ctx.f31.f64));
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lfs f0,-16684(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16684);
	ctx.f0.f64 = double(temp.f32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmuls f30,f0,f12
	ctx.f30.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// beq cr6,0x82518288
	if (ctx.cr6.eq) goto loc_82518288;
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// beq cr6,0x82518288
	if (ctx.cr6.eq) goto loc_82518288;
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// bne cr6,0x825182cc
	if (!ctx.cr6.eq) goto loc_825182CC;
loc_82518288:
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8251829C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825182ac
	if (ctx.cr0.eq) goto loc_825182AC;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// b 0x825182c8
	goto loc_825182C8;
loc_825182AC:
	// lwz r11,2352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2352);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x825182c4
	if (!ctx.cr6.eq) goto loc_825182C4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82439b28
	ctx.lr = 0x825182C0;
	sub_82439B28(ctx, base);
	// b 0x825182c8
	goto loc_825182C8;
loc_825182C4:
	// lfs f1,2652(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2652);
	ctx.f1.f64 = double(temp.f32);
loc_825182C8:
	// fmuls f30,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
loc_825182CC:
	// fadds f31,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f30.f64 + ctx.f31.f64));
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// bne cr6,0x82518310
	if (!ctx.cr6.eq) goto loc_82518310;
	// li r4,33
	ctx.r4.s64 = 33;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243ae28
	ctx.lr = 0x825182E4;
	sub_8243AE28(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// cmpwi cr6,r29,3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 3, ctx.xer);
	// lfs f30,-30652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30652);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f0,f1,f30,f29
	ctx.f0.f64 = double(float(std::fma(ctx.f1.f64, ctx.f30.f64, ctx.f29.f64)));
	// fmuls f31,f0,f31
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bne cr6,0x82518310
	if (!ctx.cr6.eq) goto loc_82518310;
	// li r4,26
	ctx.r4.s64 = 26;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243ae28
	ctx.lr = 0x82518308;
	sub_8243AE28(ctx, base);
	// fmadds f0,f1,f30,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(std::fma(ctx.f1.f64, ctx.f30.f64, ctx.f29.f64)));
	// fmuls f31,f0,f31
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
loc_82518310:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243a628
	ctx.lr = 0x82518318;
	sub_8243A628(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// cmpwi cr6,r30,9
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 9, ctx.xer);
	// bne cr6,0x82518344
	if (!ctx.cr6.eq) goto loc_82518344;
	// lwz r3,2672(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2672);
	// bl 0x824443c8
	ctx.lr = 0x8251832C;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82518344
	if (ctx.cr0.eq) goto loc_82518344;
	// bl 0x8243a628
	ctx.lr = 0x82518338;
	sub_8243A628(ctx, base);
	// fadds f13,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f30.f64));
	// lfs f0,-500(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -500);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_82518344:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,224(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f31,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f0.f64, ctx.f13.f64)));
	// fmadds f31,f0,f30,f31
	ctx.f31.f64 = double(float(std::fma(ctx.f0.f64, ctx.f30.f64, ctx.f31.f64)));
	// b 0x8251836c
	goto loc_8251836C;
loc_82518360:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82439648
	ctx.lr = 0x82518368;
	sub_82439648(ctx, base);
loc_82518368:
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
loc_8251836C:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f29,-72(r1)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f30,-64(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82531D18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82531D20;
	__savegprlr_25(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8273af1c
	ctx.lr = 0x82531D28;
	__savefpr_25(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82532434
	if (!ctx.cr0.eq) goto loc_82532434;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,304(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,372(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 372);
	ctx.f13.f64 = double(temp.f32);
	// fadds f10,f0,f1
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// lfs f11,376(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 376);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,296(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 296);
	ctx.f12.f64 = double(temp.f32);
	// lbz r10,424(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 424);
	// fmadds f0,f11,f1,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f1.f64, ctx.f13.f64)));
	// stfs f10,304(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 304, temp.u32);
	// fadds f13,f12,f1
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f1.f64));
	// stfs f13,296(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// stfs f0,372(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 372, temp.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f31,384(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 384);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,388(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 388);
	ctx.f30.f64 = double(temp.f32);
	// lfs f29,400(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 400);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f28.f64 = double(temp.f32);
	// bne 0x82531ff0
	if (!ctx.cr0.eq) goto loc_82531FF0;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8249d788
	ctx.lr = 0x82531DAC;
	sub_8249D788(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stfs f30,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stfs f30,88(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// stfs f30,84(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r10,r10,-31744
	ctx.r10.s64 = ctx.r10.s64 + -31744;
	// stfs f29,108(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stfs f29,104(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stfs f29,100(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f30,80(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v62,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,4
	ctx.r11.s64 = 4;
	// stfs f29,96(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// vmrghw128 v63,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,8
	ctx.r8.s64 = 8;
	// li r6,8
	ctx.r6.s64 = 8;
	// lfs f0,292(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// lvsl v0,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lis r5,-32225
	ctx.r5.s64 = -2111897600;
	// vmrghw128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// lvsl v6,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvsl v7,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r8,r5,32256
	ctx.r8.s64 = ctx.r5.s64 + 32256;
	// lvsl v5,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// vmsum3fp128 v62,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32), 0xEF));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// vmsum3fp128 v61,v60,v63
	simde_mm_store_ps(ctx.v61.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32), 0xEF));
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v63,v59,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32), 0xEF));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v58,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v57,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vmrghw128 v61,v61,v62
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vmrghw128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vmrghw128 v63,v63,v61
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// vperm128 v62,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v61,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v56,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v55,v63,v63,v5
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v61,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v56,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0xFF));
	// vspltw128 v55,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.u32), 0xFF));
	// vaddfp128 v62,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v12,v61,v59
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vaddfp128 v13,v57,v56
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v56.f32)));
	// vsubfp128 v61,v58,v55
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v55.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// vmaddfp v0,v0,v12,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,8
	ctx.r10.s64 = 8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r11,r11,-29248
	ctx.r11.s64 = ctx.r11.s64 + -29248;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vperm128 v62,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,412(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// lfs f0,416(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f13,1908(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// std r10,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r10.u64);
	// stfs f0,416(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// ble cr6,0x82531f94
	if (!ctx.cr6.gt) goto loc_82531F94;
	// stfs f28,416(r31)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
	// b 0x82531fa0
	goto loc_82531FA0;
loc_82531F94:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82531fa0
	if (!ctx.cr6.lt) goto loc_82531FA0;
	// stfs f13,416(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
loc_82531FA0:
	// li r10,8
	ctx.r10.s64 = 8;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,420(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 420);
	ctx.f0.f64 = double(temp.f32);
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// stfs f0,420(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 420, temp.u32);
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// ble cr6,0x82531fe0
	if (!ctx.cr6.gt) goto loc_82531FE0;
	// stfs f28,420(r31)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 420, temp.u32);
	// b 0x82531fec
	goto loc_82531FEC;
loc_82531FE0:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82531fec
	if (!ctx.cr6.lt) goto loc_82531FEC;
	// stfs f13,420(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 420, temp.u32);
loc_82531FEC:
	// stfs f28,420(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 420, temp.u32);
loc_82531FF0:
	// lbz r11,468(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 468);
	// lfs f31,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82532034
	if (ctx.cr0.eq) goto loc_82532034;
	// lfs f0,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f25
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f25.f64));
	// lfs f13,416(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 416);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f0,416(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82532028
	if (!ctx.cr6.lt) goto loc_82532028;
	// stfs f31,416(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
	// b 0x82532034
	goto loc_82532034;
loc_82532028:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// ble cr6,0x82532034
	if (!ctx.cr6.gt) goto loc_82532034;
	// stfs f28,416(r31)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
loc_82532034:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82532448
	ctx.lr = 0x8253203C;
	sub_82532448(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f13,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r11,19212
	ctx.r29.s64 = ctx.r11.s64 + 19212;
	// addi r26,r10,22072
	ctx.r26.s64 = ctx.r10.s64 + 22072;
	// lfs f0,4636(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4636);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x825320c0
	if (!ctx.cr6.gt) goto loc_825320C0;
	// lbz r11,368(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 368);
	// stfs f31,296(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825320c0
	if (ctx.cr0.eq) goto loc_825320C0;
	// lbz r11,369(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 369);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825320b0
	if (!ctx.cr0.eq) goto loc_825320B0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// li r4,348
	ctx.r4.s64 = 348;
	// bl 0x825e02a0
	ctx.lr = 0x82532088;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825320a4
	if (ctx.cr0.eq) goto loc_825320A4;
	// addi r5,r31,328
	ctx.r5.s64 = ctx.r31.s64 + 328;
	// lbz r6,81(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x82533af8
	ctx.lr = 0x825320A0;
	sub_82533AF8(ctx, base);
	// b 0x825320a8
	goto loc_825320A8;
loc_825320A4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825320A8:
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// stw r11,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
loc_825320B0:
	// lbz r11,369(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 369);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stb r11,369(r31)
	REX_STORE_U8(ctx.r31.u32 + 369, ctx.r11.u8);
loc_825320C0:
	// lfs f30,-28880(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -28880);
	ctx.f30.f64 = double(temp.f32);
	// li r28,118
	ctx.r28.s64 = 118;
	// lfs f29,-1924(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1924);
	ctx.f29.f64 = double(temp.f32);
	// addi r30,r31,524
	ctx.r30.s64 = ctx.r31.s64 + 524;
	// lfs f27,-23744(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -23744);
	ctx.f27.f64 = double(temp.f32);
	// addi r27,r31,496
	ctx.r27.s64 = ctx.r31.s64 + 496;
	// lfs f26,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
loc_825320DC:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f25
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f25.f64));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x8253218c
	if (ctx.cr6.gt) goto loc_8253218C;
	// li r29,0
	ctx.r29.s64 = 0;
loc_825320F4:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82532124
	if (!ctx.cr6.eq) goto loc_82532124;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,-24(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + -24, temp.u32);
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82532114;
	sub_825A4A40(ctx, base);
	// lfs f0,-24(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -24);
	ctx.f0.f64 = double(temp.f32);
	// stfs f1,0(r27)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// stfs f0,-12(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + -12, temp.u32);
	// b 0x82532164
	goto loc_82532164;
loc_82532124:
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// beq cr6,0x82532164
	if (ctx.cr6.eq) goto loc_82532164;
	// add r10,r28,r29
	ctx.r10.u64 = ctx.r28.u64 + ctx.r29.u64;
	// lfs f0,-52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -52);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r28,6
	ctx.r11.s64 = ctx.r28.s64 + 6;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r10,r10,-3
	ctx.r10.s64 = ctx.r10.s64 + -3;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r31
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, temp.u32);
	// lfs f0,-40(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -40);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r10,r31
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, temp.u32);
	// lfs f0,-28(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -28);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r11,r31
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
loc_82532164:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r29,3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 3, ctx.xer);
	// blt cr6,0x825320f4
	if (ctx.cr6.lt) goto loc_825320F4;
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f2,f26
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f26.f64;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82532180;
	sub_825A4A40(ctx, base);
	// stfs f1,-4(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + -4, temp.u32);
	// stfs f1,0(r30)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// b 0x82532200
	goto loc_82532200;
loc_8253218C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82532190:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x825321dc
	if (!ctx.cr6.eq) goto loc_825321DC;
	// lfs f0,-4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// ble cr6,0x825321b4
	if (!ctx.cr6.gt) goto loc_825321B4;
	// fmr f0,f28
	ctx.f0.f64 = ctx.f28.f64;
loc_825321B4:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x825321c0
	if (!ctx.cr6.lt) goto loc_825321C0;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
loc_825321C0:
	// lfs f13,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f28,f0
	ctx.f12.f64 = double(float(ctx.f28.f64 - ctx.f0.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f13,-12(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -12);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f13,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f0.f64)));
	// stfs f0,-24(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + -24, temp.u32);
	// b 0x825321f4
	goto loc_825321F4;
loc_825321DC:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x825321f4
	if (ctx.cr6.eq) goto loc_825321F4;
	// add r10,r28,r11
	ctx.r10.u64 = ctx.r28.u64 + ctx.r11.u64;
	// lfs f0,-52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -52);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r10,r31
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, temp.u32);
loc_825321F4:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x82532190
	if (ctx.cr6.lt) goto loc_82532190;
loc_82532200:
	// addi r28,r28,15
	ctx.r28.s64 = ctx.r28.s64 + 15;
	// addi r30,r30,60
	ctx.r30.s64 = ctx.r30.s64 + 60;
	// addi r27,r27,60
	ctx.r27.s64 = ctx.r27.s64 + 60;
	// cmpwi cr6,r28,2473
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2473, ctx.xer);
	// blt cr6,0x825320dc
	if (ctx.cr6.lt) goto loc_825320DC;
	// lwz r11,9900(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 9900);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// ble cr6,0x825322e8
	if (!ctx.cr6.gt) goto loc_825322E8;
	// lwz r11,9896(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 9896);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82532434
	if (ctx.cr6.eq) goto loc_82532434;
	// li r10,157
	ctx.r10.s64 = 157;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// addi r8,r31,420
	ctx.r8.s64 = ctx.r31.s64 + 420;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82532244:
	// lfsu f0,4(r9)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r9.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r9.u32 = ea;
	// stfsu f0,60(r8)
	ea = 60 + ctx.r8.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x82532244
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82532244;
	// lwz r10,628(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 628);
	// lwz r9,9896(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 9896);
	// stw r10,9904(r31)
	REX_STORE_U32(ctx.r31.u32 + 9904, ctx.r10.u32);
	// lwz r10,632(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 632);
	// stw r10,9908(r31)
	REX_STORE_U32(ctx.r31.u32 + 9908, ctx.r10.u32);
	// lwz r10,636(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 636);
	// stw r10,9912(r31)
	REX_STORE_U32(ctx.r31.u32 + 9912, ctx.r10.u32);
	// lwz r10,640(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 640);
	// stw r10,9916(r31)
	REX_STORE_U32(ctx.r31.u32 + 9916, ctx.r10.u32);
	// lfs f0,644(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 644);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,9920(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 9920, temp.u32);
	// lfs f0,648(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 648);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,9924(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 9924, temp.u32);
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82532298
	if (ctx.cr6.eq) goto loc_82532298;
	// bl 0x825e0378
	ctx.lr = 0x82532298;
	sub_825E0378(ctx, base);
loc_82532298:
	// lwz r11,9896(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 9896);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r31,r31,9892
	ctx.r31.s64 = ctx.r31.s64 + 9892;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82532434
	if (ctx.cr6.eq) goto loc_82532434;
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
	ctx.lr = 0x825322D8;
	sub_825E0378(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x82532434
	goto loc_82532434;
loc_825322E8:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// li r4,652
	ctx.r4.s64 = 652;
	// bl 0x825e02a0
	ctx.lr = 0x825322F8;
	sub_825E02A0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82532434
	if (ctx.cr6.eq) goto loc_82532434;
	// li r11,157
	ctx.r11.s64 = 157;
	// addi r9,r3,-4
	ctx.r9.s64 = ctx.r3.s64 + -4;
	// addi r10,r31,412
	ctx.r10.s64 = ctx.r31.s64 + 412;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82532314:
	// lfsu f0,60(r10)
	ctx.fpscr.disableFlushMode();
	ea = 60 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// stfsu f0,4(r9)
	ea = 4 + ctx.r9.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82532314
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82532314;
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r28,r31,9892
	ctx.r28.s64 = ctx.r31.s64 + 9892;
	// stw r11,628(r30)
	REX_STORE_U32(ctx.r30.u32 + 628, ctx.r11.u32);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// stw r11,632(r30)
	REX_STORE_U32(ctx.r30.u32 + 632, ctx.r11.u32);
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// stw r11,636(r30)
	REX_STORE_U32(ctx.r30.u32 + 636, ctx.r11.u32);
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// stw r11,640(r30)
	REX_STORE_U32(ctx.r30.u32 + 640, ctx.r11.u32);
	// lfs f0,416(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 416);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,644(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 644, temp.u32);
	// lfs f0,412(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 412);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,648(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 648, temp.u32);
	// lwz r27,9896(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 9896);
	// lwz r3,44(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 44);
	// lwz r25,4(r27)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x8253236C;
	sub_825E02A0(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x82532378
	if (ctx.cr0.eq) goto loc_82532378;
	// stw r27,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r27.u32);
loc_82532378:
	// addic. r26,r29,4
	ctx.xer.ca = ctx.r29.u32 > 4294967291;
	ctx.r26.s64 = ctx.r29.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq 0x82532384
	if (ctx.cr0.eq) goto loc_82532384;
	// stw r25,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r25.u32);
loc_82532384:
	// addic. r11,r29,8
	ctx.xer.ca = ctx.r29.u32 > 4294967287;
	ctx.r11.s64 = ctx.r29.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82532390
	if (ctx.cr0.eq) goto loc_82532390;
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_82532390:
	// lis r11,16383
	ctx.r11.s64 = 1073676288;
	// lwz r10,8(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x825323ec
	if (!ctx.cr6.lt) goto loc_825323EC;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,712
	ctx.r4.s64 = ctx.r11.s64 + 712;
	// bl 0x822167f8
	ctx.lr = 0x825323B8;
	sub_822167F8(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82216678
	ctx.lr = 0x825323C4;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x825323C8;
	sub_82216E60(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r11,r11,112
	ctx.r11.s64 = ctx.r11.s64 + 112;
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// bl 0x82216d98
	ctx.lr = 0x825323DC;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8235ec48
	ctx.lr = 0x825323EC;
	sub_8235EC48(ctx, base);
loc_825323EC:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r11.u32);
	// stw r29,4(r27)
	REX_STORE_U32(ctx.r27.u32 + 4, ctx.r29.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// lwz r11,628(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 628);
	// stw r11,9904(r31)
	REX_STORE_U32(ctx.r31.u32 + 9904, ctx.r11.u32);
	// lwz r11,632(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 632);
	// stw r11,9908(r31)
	REX_STORE_U32(ctx.r31.u32 + 9908, ctx.r11.u32);
	// lwz r11,636(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 636);
	// stw r11,9912(r31)
	REX_STORE_U32(ctx.r31.u32 + 9912, ctx.r11.u32);
	// lwz r11,640(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 640);
	// stw r11,9916(r31)
	REX_STORE_U32(ctx.r31.u32 + 9916, ctx.r11.u32);
	// lfs f0,644(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 644);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,9920(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 9920, temp.u32);
	// lfs f0,648(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 648);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,9924(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 9924, temp.u32);
loc_82532434:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8273af68
	ctx.lr = 0x82532440;
	__restfpr_25(ctx, base);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8256D808) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8256D810;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r7,77
	ctx.r7.s64 = 77;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x8256D83C;
	sub_825190E8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r11,32720
	ctx.r9.s64 = ctx.r11.s64 + 32720;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r28,-32225
	ctx.r28.s64 = -2111897600;
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r28,10920
	ctx.r8.s64 = ctx.r28.s64 + 10920;
	// lfs f10,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lfs f8,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f6.f64 = double(temp.f32);
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f6,300(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stfs f13,304(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// lfs f9,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// stfs f12,312(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// stfs f11,308(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// stvx128 v61,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// stfs f10,320(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// stfs f9,316(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stfs f8,328(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 328, temp.u32);
	// stfs f7,324(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// stb r29,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r29.u8);
	// stfs f0,332(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 332, temp.u32);
	// bne cr6,0x8256d90c
	if (!ctx.cr6.eq) goto loc_8256D90C;
	// lfs f0,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8256d910
	goto loc_8256D910;
loc_8256D90C:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
loc_8256D910:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r28,1
	ctx.r28.s64 = 1;
	// lwz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r27,0
	ctx.r27.s64 = 0;
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
	// stfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// rlwimi r10,r28,0,30,31
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x3) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFC);
	// stw r27,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r27.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// stw r10,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x824443c8
	ctx.lr = 0x8256D944;
	sub_824443C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8256d9e0
	if (ctx.cr0.eq) goto loc_8256D9E0;
	// lwz r11,2340(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8256d978
	if (ctx.cr6.eq) goto loc_8256D978;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8256D96C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x8256d978
	if (!ctx.cr6.eq) goto loc_8256D978;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_8256D978:
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8256d98c
	if (ctx.cr0.eq) goto loc_8256D98C;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,-8956(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8956);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,332(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 332, temp.u32);
loc_8256D98C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82430cf0
	ctx.lr = 0x8256D998;
	sub_82430CF0(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-31712
	ctx.r11.s64 = ctx.r11.s64 + -31712;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
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
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// b 0x8256d9ec
	goto loc_8256D9EC;
loc_8256D9E0:
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r28,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r28.u8);
	// stw r11,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
loc_8256D9EC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r27,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r27.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8257C0B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8257c2e8
	ctx.lr = 0x8257C0C8;
	sub_8257C2E8(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r10,r11,14376
	ctx.r10.s64 = ctx.r11.s64 + 14376;
	// lwz r11,-12872(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -12872);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8257c0e8
	if (ctx.cr6.eq) goto loc_8257C0E8;
	// lfs f0,664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8257c0ec
	goto loc_8257C0EC;
loc_8257C0E8:
	// lfs f0,-2140(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2140);
	ctx.f0.f64 = double(temp.f32);
loc_8257C0EC:
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lis r6,-32242
	ctx.r6.s64 = -2113011712;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,432
	ctx.r4.s64 = 432;
	// lwz r3,-15444(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -15444);
	// addi r6,r6,31600
	ctx.r6.s64 = ctx.r6.s64 + 31600;
	// lwz r11,-15432(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -15432);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// std r3,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrefp128 v12,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v62.f32)));
	// vrefp128 v0,v63
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v63.f32)));
	// vor128 v7,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lvx128 v13,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v5,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vcmpeqfp128 v8,v63,v61
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfd f11,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// vcmpeqfp128 v9,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// vcmpeqfp128 v11,v12,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfd f10,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// vnmsubfp v2,v5,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// vnmsubfp v3,v7,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v3.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vcmpeqfp128 v10,v0,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v61.f32)));
	// fcfid f13,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(ctx.f10.s64);
	// lfs f12,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
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
	// frsp f12,f11
	ctx.f12.f64 = double(float(ctx.f11.f64));
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// vmaddfp v7,v0,v3,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v6,v8,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vmaddfp v10,v12,v2,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vsel v8,v9,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vor v9,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// fmuls f13,f13,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// vor v11,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vnmsubfp128 v9,v63,v11,v9
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor v11,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v60,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vnmsubfp128 v13,v62,v11,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// vmaddfp v11,v7,v9,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v13,v10,v13,v10
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vsel v10,v11,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v63,v63,v10
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v10.f32)));
	// vsel v0,v13,v12,v8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vmulfp128 v62,v62,v0
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825903B8) {
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
	// lbz r11,128(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 128);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82590418
	if (ctx.cr0.eq) goto loc_82590418;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12972(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12972);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82590408
	if (ctx.cr6.eq) goto loc_82590408;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,916(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 916);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82590408
	if (ctx.cr6.lt) goto loc_82590408;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// ble cr6,0x8259040c
	if (!ctx.cr6.gt) goto loc_8259040C;
loc_82590408:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8259040C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825904b0
	if (!ctx.cr0.eq) goto loc_825904B0;
	// b 0x82590490
	goto loc_82590490;
loc_82590418:
	// bl 0x82444358
	ctx.lr = 0x8259041C;
	sub_82444358(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82590430
	if (!ctx.cr0.eq) goto loc_82590430;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82590448
	goto loc_82590448;
loc_82590430:
	// bl 0x824443c8
	ctx.lr = 0x82590434;
	sub_824443C8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82590440
	if (ctx.cr0.eq) goto loc_82590440;
	// lwz r8,2380(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 2380);
loc_82590440:
	// addic r11,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r11.s64 = ctx.r8.s64 + -1;
	// subfe r11,r11,r8
	temp.u8 = (~ctx.r11.u32 + ctx.r8.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_82590448:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825904b0
	if (!ctx.cr0.eq) goto loc_825904B0;
	// bl 0x82444358
	ctx.lr = 0x82590454;
	sub_82444358(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82590488
	if (ctx.cr0.eq) goto loc_82590488;
	// bl 0x824443c8
	ctx.lr = 0x82590464;
	sub_824443C8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82590488
	if (ctx.cr0.eq) goto loc_82590488;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8245da68
	ctx.lr = 0x82590478;
	sub_8245DA68(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824304b8
	ctx.lr = 0x82590484;
	sub_824304B8(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
loc_82590488:
	// clrlwi. r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825904b0
	if (ctx.cr0.eq) goto loc_825904B0;
loc_82590490:
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// stb r10,120(r30)
	REX_STORE_U8(ctx.r30.u32 + 120, ctx.r10.u8);
	// li r3,7
	ctx.r3.s64 = 7;
	// stb r9,121(r30)
	REX_STORE_U8(ctx.r30.u32 + 121, ctx.r9.u8);
	// bl 0x823c7bd8
	ctx.lr = 0x825904B0;
	sub_823C7BD8(ctx, base);
loc_825904B0:
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

DEFINE_REX_FUNC(sub_825991B8) {
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
	// lwz r31,-12824(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -12824);
loc_825991D0:
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825991e8
	if (!ctx.cr6.eq) goto loc_825991E8;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82599208
	if (ctx.cr6.eq) goto loc_82599208;
loc_825991E8:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8263a258
	ctx.lr = 0x825991F0;
	sub_8263A258(ctx, base);
	// bl 0x8259bc68
	ctx.lr = 0x825991F4;
	sub_8259BC68(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82598aa8
	ctx.lr = 0x825991FC;
	sub_82598AA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82598ff8
	ctx.lr = 0x82599204;
	sub_82598FF8(ctx, base);
	// b 0x825991d0
	goto loc_825991D0;
loc_82599208:
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

DEFINE_REX_FUNC(sub_8259B4C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8259B4D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r30,4(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,15856
	ctx.r11.s64 = ctx.r11.s64 + 15856;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x8259b528
	if (ctx.cr6.eq) goto loc_8259B528;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r29,r11,-15376
	ctx.r29.s64 = ctx.r11.s64 + -15376;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825f8cb0
	ctx.lr = 0x8259B500;
	sub_825F8CB0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826052e8
	ctx.lr = 0x8259B508;
	sub_826052E8(ctx, base);
	// lwsync 
	// li r10,0
	ctx.r10.s64 = 0;
loc_8259B510:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r29
	ea = ctx.r29.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r10,0,r29
	ea = ctx.r29.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8259b510
	if (!ctx.cr0.eq) goto loc_8259B510;
loc_8259B528:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,20580
	ctx.r11.s64 = ctx.r11.s64 + 20580;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8259E2E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r3,r11,13728
	ctx.r3.s64 = ctx.r11.s64 + 13728;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8259E7D0) {
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
	// bl 0x8259e828
	ctx.lr = 0x8259E7F0;
	sub_8259E828(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8259e808
	if (ctx.cr0.eq) goto loc_8259E808;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8259e808
	if (ctx.cr6.eq) goto loc_8259E808;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8259E808;
	sub_825E0378(ctx, base);
loc_8259E808:
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

DEFINE_REX_FUNC(sub_825A11F8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r3,r11,13712
	ctx.r3.s64 = ctx.r11.s64 + 13712;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825A12D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r3,r11,13704
	ctx.r3.s64 = ctx.r11.s64 + 13704;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825A16B8) {
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
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mulli r10,r4,144
	ctx.r10.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(144));
	// lwz r11,-12824(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12824);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
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
	ctx.lr = 0x825A16F0;
	sub_8235EAD8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b6dd0
	ctx.lr = 0x825A16F8;
	sub_823B6DD0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235ec48
	ctx.lr = 0x825A170C;
	sub_8235EC48(ctx, base);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235f0f0
	ctx.lr = 0x825A1720;
	sub_8235F0F0(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235f0f0
	ctx.lr = 0x825A1734;
	sub_8235F0F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235ec48
	ctx.lr = 0x825A1744;
	sub_8235EC48(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x825a1758
	if (!ctx.cr6.lt) goto loc_825A1758;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_825A1758:
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_825A175C:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825a175c
	if (!ctx.cr6.eq) goto loc_825A175C;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lwz r10,-15508(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -15508);
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825A1788;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x825fad98
	ctx.lr = 0x825A178C;
	sub_825FAD98(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825a1798
	if (ctx.cr0.eq) goto loc_825A1798;
	// bl 0x825fabf0
	ctx.lr = 0x825A1798;
	sub_825FABF0(ctx, base);
loc_825A1798:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x825A17A8;
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

DEFINE_REX_FUNC(sub_825A7C80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,32640
	ctx.r11.s64 = 2139095040;
	// stfs f2,-12(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f1,-16(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// fabs f0,f1
	ctx.f0.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// fabs f13,f2
	ctx.f13.u64 = ctx.f2.u64 & ~0x8000000000000000;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// lwz r11,-12(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// lwz r10,-16(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -16);
	// clrlwi r7,r10,1
	ctx.r7.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// clrlwi r6,r11,1
	ctx.r6.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// subf r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	// subf r9,r6,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r6.u64;
	// cntlzw r8,r8
	ctx.r8.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r11,0,0,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	// rlwinm r6,r10,0,0,0
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rlwinm r8,r8,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// li r11,1
	ctx.r11.s64 = 1;
	// bgt cr6,0x825a7cdc
	if (ctx.cr6.gt) goto loc_825A7CDC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825A7CDC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825a7cec
	if (ctx.cr0.eq) goto loc_825A7CEC;
	// fdivs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// b 0x825a7cf0
	goto loc_825A7CF0;
loc_825A7CEC:
	// fdivs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
loc_825A7CF0:
	// fmuls f9,f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f0.f64));
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r11,r10,-4080
	ctx.r11.s64 = ctx.r10.s64 + -4080;
	// lfs f13,348(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 348);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,352(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 352);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,368(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 368);
	ctx.f11.f64 = double(temp.f32);
	// fmsubs f8,f9,f13,f12
	ctx.f8.f64 = double(float(std::fma(ctx.f9.f64, ctx.f13.f64, -ctx.f12.f64)));
	// lfs f13,372(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 372);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,356(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 356);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f7,f9,f11,f13
	ctx.f7.f64 = double(float(-std::fma(ctx.f9.f64, ctx.f11.f64, -ctx.f13.f64)));
	// fmuls f6,f9,f9
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// lfs f13,376(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 376);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,360(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 360);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f5,f9,f0
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// lfs f10,364(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 364);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f12,f8,f9,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f8.f64, ctx.f9.f64, ctx.f12.f64)));
	// fmsubs f13,f7,f9,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f7.f64, ctx.f9.f64, -ctx.f13.f64)));
	// fmuls f8,f6,f6
	ctx.f8.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fmsubs f12,f12,f9,f11
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f9.f64, -ctx.f11.f64)));
	// fmadds f13,f13,f5,f0
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f5.f64, ctx.f0.f64)));
	// fmuls f0,f8,f0
	ctx.f0.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmadds f12,f12,f9,f10
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f9.f64, ctx.f10.f64)));
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// beq cr6,0x825a7d5c
	if (ctx.cr6.eq) goto loc_825A7D5C;
	// lfs f13,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
loc_825A7D5C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f2,f13
	ctx.cr6.compare(ctx.f2.f64, ctx.f13.f64);
	// bne cr6,0x825a7d7c
	if (!ctx.cr6.eq) goto loc_825A7D7C;
	// fcmpu cr6,f1,f13
	ctx.cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// bne cr6,0x825a7d7c
	if (!ctx.cr6.eq) goto loc_825A7D7C;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_825A7D7C:
	// clrlwi. r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825a7d94
	if (ctx.cr0.eq) goto loc_825A7D94;
	// clrlwi. r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x825a7d94
	if (ctx.cr0.eq) goto loc_825A7D94;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lfs f0,20200(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 20200);
	ctx.f0.f64 = double(temp.f32);
loc_825A7D94:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x825a7db8
	if (ctx.cr6.eq) goto loc_825A7DB8;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x825a7db0
	if (ctx.cr6.eq) goto loc_825A7DB0;
	// lfs f13,1132(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1132);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// b 0x825a7dc8
	goto loc_825A7DC8;
loc_825A7DB0:
	// fneg f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// b 0x825a7dc8
	goto loc_825A7DC8;
loc_825A7DB8:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x825a7dc8
	if (ctx.cr6.eq) goto loc_825A7DC8;
	// lfs f13,1132(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1132);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
loc_825A7DC8:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825B32D0) {
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
	// lwz r11,20344(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20344);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825b3338
	if (ctx.cr6.eq) goto loc_825B3338;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82748800
	ctx.lr = 0x825B32F4;
	sub_82748800(ctx, base);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mulli r9,r10,1000
	ctx.r9.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(1000));
	// rotldi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u64, 1);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// ld r11,-12696(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + -12696);
	// divd r8,r9,r11
	ctx.r8.s64 = (ctx.r11.s64 && !(ctx.r9.s64 == INT64_MIN && ctx.r11.s64 == -1)) ? ctx.r9.s64 / ctx.r11.s64 : 0;
	// andc r6,r11,r7
	ctx.r6.u64 = ctx.r11.u64 & ~ctx.r7.u64;
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// tdllei r11,0
	if (ctx.r11.s64 == 0ll || ctx.r11.u64 < 0ull) ppc_trap(ctx, base, 0);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r3,r5,1
	ctx.r3.u64 = ctx.r5.u32 & 0x7FFFFFFF;
	// tdlgei r6,-1
	if (ctx.r6.s64 == -1ll || ctx.r6.u64 > 18446744073709551615ull) ppc_trap(ctx, base, 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_825B3338:
	// bl 0x82748820
	ctx.lr = 0x825B333C;
	sub_82748820(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825B62C0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x825b6098
	sub_825B6098(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B63A0) {
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
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// lwz r9,332(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 332);
	// rlwinm r11,r5,1,15,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1FFFE;
	// li r5,24
	ctx.r5.s64 = 24;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x8273a030
	ctx.lr = 0x825B63D4;
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

DEFINE_REX_FUNC(sub_825B8558) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x825b7e68
	sub_825B7E68(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B87E0) {
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
	// bl 0x825b8838
	ctx.lr = 0x825B8800;
	sub_825B8838(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825b8820
	if (ctx.cr6.eq) goto loc_825B8820;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32815
	ctx.r4.u64 = ctx.r4.u64 | 32815;
	// bl 0x8263b710
	ctx.lr = 0x825B881C;
	sub_8263B710(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825B8820:
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

DEFINE_REX_FUNC(sub_825BA910) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x825BA918;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r20,r11,204
	ctx.r20.s64 = ctx.r11.s64 + 204;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r21,r7
	ctx.r21.u64 = ctx.r7.u64;
	// bl 0x82855b44
	ctx.lr = 0x825BA940;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,360(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 360);
	// li r24,0
	ctx.r24.s64 = 0;
	// addi r27,r28,356
	ctx.r27.s64 = ctx.r28.s64 + 356;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x825ba968
	if (!ctx.cr6.eq) goto loc_825BA968;
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x825ba998
	if (ctx.cr6.eq) goto loc_825BA998;
loc_825BA968:
	// lwz r11,360(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 360);
loc_825BA96C:
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x825ba998
	if (ctx.cr6.eq) goto loc_825BA998;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r30
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x825ba988
	if (!ctx.cr6.eq) goto loc_825BA988;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
loc_825BA988:
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x825ba96c
	if (!ctx.cr6.eq) goto loc_825BA96C;
loc_825BA998:
	// clrlwi r22,r10,24
	ctx.r22.u64 = ctx.r10.u32 & 0xFF;
	// lis r11,8324
	ctx.r11.s64 = 545521664;
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// ori r23,r11,1
	ctx.r23.u64 = ctx.r11.u64 | 1;
	// beq cr6,0x825ba9f8
	if (ctx.cr6.eq) goto loc_825BA9F8;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,28
	ctx.r3.s64 = 28;
	// ori r4,r4,32769
	ctx.r4.u64 = ctx.r4.u64 | 32769;
	// bl 0x8263b678
	ctx.lr = 0x825BA9BC;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825baa38
	if (ctx.cr6.eq) goto loc_825BAA38;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,18808
	ctx.r10.s64 = ctx.r11.s64 + 18808;
	// stw r24,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r24.u32);
	// stw r24,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r24.u32);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r24,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r24.u32);
	// stw r24,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r24.u32);
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// bne cr6,0x825baa10
	if (!ctx.cr6.eq) goto loc_825BAA10;
loc_825BA9F8:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mullw r30,r26,r25
	ctx.r30.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r25.s32);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// cmplw cr6,r9,r30
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x825baa68
	if (ctx.cr6.eq) goto loc_825BAA68;
loc_825BAA10:
	// mullw r30,r26,r25
	ctx.r30.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r25.s32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8263b678
	ctx.lr = 0x825BAA20;
	sub_8263B678(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825baa48
	if (!ctx.cr6.eq) goto loc_825BAA48;
	// lis r24,-32761
	ctx.r24.s64 = -2147024896;
	// ori r24,r24,14
	ctx.r24.u64 = ctx.r24.u64 | 14;
	// b 0x825baa9c
	goto loc_825BAA9C;
loc_825BAA38:
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// lis r24,-32761
	ctx.r24.s64 = -2147024896;
	// ori r24,r24,14
	ctx.r24.u64 = ctx.r24.u64 | 14;
	// b 0x825baa9c
	goto loc_825BAA9C;
loc_825BAA48:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825baa5c
	if (ctx.cr6.eq) goto loc_825BAA5C;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x8263b710
	ctx.lr = 0x825BAA5C;
	sub_8263B710(ctx, base);
loc_825BAA5C:
	// stw r29,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// stw r26,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r26.u32);
	// stw r25,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r25.u32);
loc_825BAA68:
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// bl 0x8273a030
	ctx.lr = 0x825BAA78;
	sub_8273A030(ctx, base);
	// lwz r3,56(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 56);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825baa9c
	if (ctx.cr6.eq) goto loc_825BAA9C;
	// lwz r7,24(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r6,20(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r5,16(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x825c6cf0
	ctx.lr = 0x825BAA98;
	sub_825C6CF0(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
loc_825BAA9C:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x825bab04
	if (ctx.cr6.eq) goto loc_825BAB04;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// blt cr6,0x825baad8
	if (ctx.cr6.lt) goto loc_825BAAD8;
	// stw r27,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r10,8(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// stw r31,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r31.u32);
	// stw r31,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r31.u32);
	// bl 0x82855b34
	ctx.lr = 0x825BAACC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
loc_825BAAD8:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825baaec
	if (ctx.cr6.eq) goto loc_825BAAEC;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// bl 0x8263b710
	ctx.lr = 0x825BAAEC;
	sub_8263B710(ctx, base);
loc_825BAAEC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825BAB04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825BAB04:
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x82855b34
	ctx.lr = 0x825BAB0C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C8120) {
	REX_FUNC_PROLOGUE();
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_825C812C:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x825c8148
	if (ctx.cr6.eq) goto loc_825C8148;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825c812c
	if (!ctx.cr6.eq) goto loc_825C812C;
	// blr 
	return;
loc_825C8148:
	// lwz r9,228(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// addi r10,r3,24
	ctx.r10.s64 = ctx.r3.s64 + 24;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x825c8164
	if (!ctx.cr6.eq) goto loc_825C8164;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,204(r10)
	REX_STORE_U32(ctx.r10.u32 + 204, ctx.r9.u32);
	// b 0x825c8170
	goto loc_825C8170;
loc_825C8164:
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
loc_825C8170:
	// lwz r9,208(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 208);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x825c8188
	if (!ctx.cr6.eq) goto loc_825C8188;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,208(r10)
	REX_STORE_U32(ctx.r10.u32 + 208, ctx.r9.u32);
	// b 0x825c8194
	goto loc_825C8194;
loc_825C8188:
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r8,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
loc_825C8194:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lwz r9,212(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 212);
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r8,212(r10)
	REX_STORE_U32(ctx.r10.u32 + 212, ctx.r8.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825CCE48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addic r11,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// lbz r10,40(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 40);
	// subfe r9,r11,r4
	temp.u8 = (~ctx.r11.u32 + ctx.r4.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r10,r9,5,26,26
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0x20) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r10,40(r3)
	REX_STORE_U8(ctx.r3.u32 + 40, ctx.r10.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825CDA40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x825CDA48;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,20
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 20, ctx.xer);
	// bgt cr6,0x825ce10c
	if (ctx.cr6.gt) goto loc_825CE10C;
	// lis r12,-32163
	ctx.r12.s64 = -2107834368;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-9592
	ctx.r12.s64 = ctx.r12.s64 + -9592;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_825CDADC;
	case 1:
		goto loc_825CDB60;
	case 2:
		goto loc_825CDBD8;
	case 3:
		goto loc_825CDC54;
	case 4:
		goto loc_825CDB60;
	case 5:
		goto loc_825CDBD8;
	case 6:
		goto loc_825CDC54;
	case 7:
		goto loc_825CDE90;
	case 8:
		goto loc_825CDEC8;
	case 9:
		goto loc_825CDF00;
	case 10:
		goto loc_825CDCF8;
	case 11:
		goto loc_825CDD5C;
	case 12:
		goto loc_825CDDC4;
	case 13:
		goto loc_825CDE24;
	case 14:
		goto loc_825CDF74;
	case 15:
		goto loc_825CDFD0;
	case 16:
		goto loc_825CE008;
	case 17:
		goto loc_825CE040;
	case 18:
		goto loc_825CE078;
	case 19:
		goto loc_825CDC94;
	case 20:
		goto loc_825CDB40;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_825CDADC:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,48
	ctx.r3.s64 = 48;
	// ori r4,r4,32791
	ctx.r4.u64 = ctx.r4.u64 | 32791;
	// bl 0x8263b678
	ctx.lr = 0x825CDAEC;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdb38
	if (ctx.cr6.eq) goto loc_825CDB38;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// addi r9,r10,21264
	ctx.r9.s64 = ctx.r10.s64 + 21264;
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r28,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// stw r29,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r29.u32);
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
	// b 0x825cdb3c
	goto loc_825CDB3C;
loc_825CDB38:
	// li r10,0
	ctx.r10.s64 = 0;
loc_825CDB3C:
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
loc_825CDB40:
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// ori r7,r10,14
	ctx.r7.u64 = ctx.r10.u64 | 14;
	// subfe r6,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 & ctx.r7.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_825CDB60:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,72
	ctx.r3.s64 = 72;
	// ori r4,r4,32785
	ctx.r4.u64 = ctx.r4.u64 | 32785;
	// bl 0x8263b678
	ctx.lr = 0x825CDB70;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdb38
	if (ctx.cr6.eq) goto loc_825CDB38;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// addi r9,r10,21040
	ctx.r9.s64 = ctx.r10.s64 + 21040;
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r28,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// stw r29,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r29.u32);
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
	// stw r11,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lbz r8,11(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 11);
	// stb r8,52(r3)
	REX_STORE_U8(ctx.r3.u32 + 52, ctx.r8.u8);
	// stw r11,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r11.u32);
	// stw r11,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// stw r11,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// stw r11,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// b 0x825cdb3c
	goto loc_825CDB3C;
loc_825CDBD8:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,72
	ctx.r3.s64 = 72;
	// ori r4,r4,32785
	ctx.r4.u64 = ctx.r4.u64 | 32785;
	// bl 0x8263b678
	ctx.lr = 0x825CDBE8;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdb38
	if (ctx.cr6.eq) goto loc_825CDB38;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stw r29,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r29.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// addi r8,r10,21040
	ctx.r8.s64 = ctx.r10.s64 + 21040;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r11,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stb r11,40(r3)
	REX_STORE_U8(ctx.r3.u32 + 40, ctx.r11.u8);
	// stw r11,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stw r28,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// lbz r7,11(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 11);
	// stb r7,52(r3)
	REX_STORE_U8(ctx.r3.u32 + 52, ctx.r7.u8);
	// stw r9,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r9.u32);
	// stw r11,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// stw r11,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// stw r11,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// b 0x825cdb3c
	goto loc_825CDB3C;
loc_825CDC54:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,188
	ctx.r3.s64 = 188;
	// ori r4,r4,32786
	ctx.r4.u64 = ctx.r4.u64 | 32786;
	// bl 0x8263b678
	ctx.lr = 0x825CDC64;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdc88
	if (ctx.cr6.eq) goto loc_825CDC88;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x825cfed8
	ctx.lr = 0x825CDC80;
	sub_825CFED8(ctx, base);
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// b 0x825cdb40
	goto loc_825CDB40;
loc_825CDC88:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// b 0x825cdb40
	goto loc_825CDB40;
loc_825CDC94:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,56
	ctx.r3.s64 = 56;
	// ori r4,r4,32784
	ctx.r4.u64 = ctx.r4.u64 | 32784;
	// bl 0x8263b678
	ctx.lr = 0x825CDCA4;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdb38
	if (ctx.cr6.eq) goto loc_825CDB38;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// addi r9,r10,21544
	ctx.r9.s64 = ctx.r10.s64 + 21544;
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r28,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// stw r29,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r29.u32);
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
	// stw r11,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// b 0x825cdb3c
	goto loc_825CDB3C;
loc_825CDCF8:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,56
	ctx.r3.s64 = 56;
	// ori r4,r4,32782
	ctx.r4.u64 = ctx.r4.u64 | 32782;
	// bl 0x8263b678
	ctx.lr = 0x825CDD08;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdb38
	if (ctx.cr6.eq) goto loc_825CDB38;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// addi r9,r10,21208
	ctx.r9.s64 = ctx.r10.s64 + 21208;
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r28,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// stw r29,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r29.u32);
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
	// stw r11,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r11,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// b 0x825cdb3c
	goto loc_825CDB3C;
loc_825CDD5C:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,56
	ctx.r3.s64 = 56;
	// ori r4,r4,32782
	ctx.r4.u64 = ctx.r4.u64 | 32782;
	// bl 0x8263b678
	ctx.lr = 0x825CDD6C;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdb38
	if (ctx.cr6.eq) goto loc_825CDB38;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// addi r9,r10,21208
	ctx.r9.s64 = ctx.r10.s64 + 21208;
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stw r28,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r29,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r29.u32);
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
	// stw r11,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r8,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r8.u32);
	// b 0x825cdb3c
	goto loc_825CDB3C;
loc_825CDDC4:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,52
	ctx.r3.s64 = 52;
	// ori r4,r4,32792
	ctx.r4.u64 = ctx.r4.u64 | 32792;
	// bl 0x8263b678
	ctx.lr = 0x825CDDD4;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdb38
	if (ctx.cr6.eq) goto loc_825CDB38;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// addi r9,r10,21496
	ctx.r9.s64 = ctx.r10.s64 + 21496;
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r28,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// stw r29,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r29.u32);
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
	// stw r11,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// b 0x825cdb3c
	goto loc_825CDB3C;
loc_825CDE24:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,64
	ctx.r3.s64 = 64;
	// ori r4,r4,32789
	ctx.r4.u64 = ctx.r4.u64 | 32789;
	// bl 0x8263b678
	ctx.lr = 0x825CDE34;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdb38
	if (ctx.cr6.eq) goto loc_825CDB38;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// addi r9,r10,21520
	ctx.r9.s64 = ctx.r10.s64 + 21520;
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r28,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// stw r29,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r29.u32);
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
	// sth r11,48(r3)
	REX_STORE_U16(ctx.r3.u32 + 48, ctx.r11.u16);
	// stw r11,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// sth r11,56(r3)
	REX_STORE_U16(ctx.r3.u32 + 56, ctx.r11.u16);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// b 0x825cdb3c
	goto loc_825CDB3C;
loc_825CDE90:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,88
	ctx.r3.s64 = 88;
	// ori r4,r4,32788
	ctx.r4.u64 = ctx.r4.u64 | 32788;
	// bl 0x8263b678
	ctx.lr = 0x825CDEA0;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdc88
	if (ctx.cr6.eq) goto loc_825CDC88;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x825d1830
	ctx.lr = 0x825CDEC0;
	sub_825D1830(ctx, base);
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// b 0x825cdb40
	goto loc_825CDB40;
loc_825CDEC8:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,88
	ctx.r3.s64 = 88;
	// ori r4,r4,32790
	ctx.r4.u64 = ctx.r4.u64 | 32790;
	// bl 0x8263b678
	ctx.lr = 0x825CDED8;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdc88
	if (ctx.cr6.eq) goto loc_825CDC88;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x825cf708
	ctx.lr = 0x825CDEF8;
	sub_825CF708(ctx, base);
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// b 0x825cdb40
	goto loc_825CDB40;
loc_825CDF00:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,72
	ctx.r3.s64 = 72;
	// ori r4,r4,32783
	ctx.r4.u64 = ctx.r4.u64 | 32783;
	// bl 0x8263b678
	ctx.lr = 0x825CDF10;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdb38
	if (ctx.cr6.eq) goto loc_825CDB38;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// addi r9,r10,21472
	ctx.r9.s64 = ctx.r10.s64 + 21472;
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r28,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// stw r29,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r29.u32);
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
	// sth r11,48(r3)
	REX_STORE_U16(ctx.r3.u32 + 48, ctx.r11.u16);
	// stw r11,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// sth r11,56(r3)
	REX_STORE_U16(ctx.r3.u32 + 56, ctx.r11.u16);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// stw r11,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// stw r11,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// b 0x825cdb3c
	goto loc_825CDB3C;
loc_825CDF74:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,48
	ctx.r3.s64 = 48;
	// ori r4,r4,32787
	ctx.r4.u64 = ctx.r4.u64 | 32787;
	// bl 0x8263b678
	ctx.lr = 0x825CDF84;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdb38
	if (ctx.cr6.eq) goto loc_825CDB38;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// addi r9,r10,21716
	ctx.r9.s64 = ctx.r10.s64 + 21716;
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r28,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// stw r29,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r29.u32);
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
	// b 0x825cdb3c
	goto loc_825CDB3C;
loc_825CDFD0:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,64
	ctx.r3.s64 = 64;
	// ori r4,r4,32789
	ctx.r4.u64 = ctx.r4.u64 | 32789;
	// bl 0x8263b678
	ctx.lr = 0x825CDFE0;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdc88
	if (ctx.cr6.eq) goto loc_825CDC88;
	// addi r8,r31,18
	ctx.r8.s64 = ctx.r31.s64 + 18;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x825d1230
	ctx.lr = 0x825CE000;
	sub_825D1230(ctx, base);
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// b 0x825cdb40
	goto loc_825CDB40;
loc_825CE008:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,88
	ctx.r3.s64 = 88;
	// ori r4,r4,32788
	ctx.r4.u64 = ctx.r4.u64 | 32788;
	// bl 0x8263b678
	ctx.lr = 0x825CE018;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdc88
	if (ctx.cr6.eq) goto loc_825CDC88;
	// addi r8,r31,22
	ctx.r8.s64 = ctx.r31.s64 + 22;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x825d1830
	ctx.lr = 0x825CE038;
	sub_825D1830(ctx, base);
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// b 0x825cdb40
	goto loc_825CDB40;
loc_825CE040:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,88
	ctx.r3.s64 = 88;
	// ori r4,r4,32790
	ctx.r4.u64 = ctx.r4.u64 | 32790;
	// bl 0x8263b678
	ctx.lr = 0x825CE050;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdc88
	if (ctx.cr6.eq) goto loc_825CDC88;
	// addi r8,r31,22
	ctx.r8.s64 = ctx.r31.s64 + 22;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x825cf708
	ctx.lr = 0x825CE070;
	sub_825CF708(ctx, base);
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// b 0x825cdb40
	goto loc_825CDB40;
loc_825CE078:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r3,72
	ctx.r3.s64 = 72;
	// ori r4,r4,32783
	ctx.r4.u64 = ctx.r4.u64 | 32783;
	// bl 0x8263b678
	ctx.lr = 0x825CE088;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cdb38
	if (ctx.cr6.eq) goto loc_825CDB38;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// addic. r10,r31,11
	ctx.xer.ca = ctx.r31.u32 > 4294967284;
	ctx.r10.s64 = ctx.r31.s64 + 11;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r30,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// addi r8,r9,21744
	ctx.r8.s64 = ctx.r9.s64 + 21744;
	// stw r31,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stw r28,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// stw r29,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r29.u32);
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
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// sth r11,48(r3)
	REX_STORE_U16(ctx.r3.u32 + 48, ctx.r11.u16);
	// stw r10,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// beq 0x825ce0e4
	if (ctx.cr0.eq) goto loc_825CE0E4;
	// lhz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// b 0x825ce0e8
	goto loc_825CE0E8;
loc_825CE0E4:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_825CE0E8:
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// sth r10,56(r3)
	REX_STORE_U16(ctx.r3.u32 + 56, ctx.r10.u16);
	// stw r11,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r7,r9,21472
	ctx.r7.s64 = ctx.r9.s64 + 21472;
	// stw r11,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// stw r11,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// stw r7,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// b 0x825cdb3c
	goto loc_825CDB3C;
loc_825CE10C:
	// lis r3,-30009
	ctx.r3.s64 = -1966669824;
	// ori r3,r3,17
	ctx.r3.u64 = ctx.r3.u64 | 17;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F9C60) {
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
	// addi r30,r11,-15480
	ctx.r30.s64 = ctx.r11.s64 + -15480;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x825F9C88;
	sub_825F8ED0(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825f9cb0
	if (ctx.cr6.eq) goto loc_825F9CB0;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// clrlwi r10,r31,17
	ctx.r10.u64 = ctx.r31.u32 & 0x7FFF;
	// mulli r10,r10,116
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(116));
	// lwz r11,-15484(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15484);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x825f9cec
	if (ctx.cr6.eq) goto loc_825F9CEC;
loc_825F9CB0:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_825F9CB4:
	// lwsync 
	// li r11,0
	ctx.r11.s64 = 0;
loc_825F9CBC:
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
	// bne 0x825f9cbc
	if (!ctx.cr0.eq) goto loc_825F9CBC;
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
loc_825F9CEC:
	// addi r3,r11,112
	ctx.r3.s64 = ctx.r11.s64 + 112;
	// bl 0x825f8f28
	ctx.lr = 0x825F9CF4;
	sub_825F8F28(ctx, base);
	// b 0x825f9cb4
	goto loc_825F9CB4;
}

DEFINE_REX_FUNC(sub_825FE730) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825FE738;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r29,r11,-15400
	ctx.r29.s64 = ctx.r11.s64 + -15400;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x825FE750;
	sub_825F8ED0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825fe778
	if (ctx.cr6.eq) goto loc_825FE778;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwinm r10,r30,5,12,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 5) & 0xFFFE0;
	// lwz r11,-15412(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15412);
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x825fe7a0
	if (ctx.cr6.eq) goto loc_825FE7A0;
loc_825FE778:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_825FE77C:
	// lwsync 
loc_825FE780:
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
	// bne 0x825fe780
	if (!ctx.cr0.eq) goto loc_825FE780;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
loc_825FE7A0:
	// addi r3,r31,28
	ctx.r3.s64 = ctx.r31.s64 + 28;
	// bl 0x825f8fb0
	ctx.lr = 0x825FE7A8;
	sub_825F8FB0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x825fe77c
	if (!ctx.cr0.eq) goto loc_825FE77C;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lwz r7,12(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r31,12
	ctx.r11.s64 = ctx.r31.s64 + 12;
	// addi r8,r8,-15384
	ctx.r8.s64 = ctx.r8.s64 + -15384;
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r7,16(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stw r7,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// stw r9,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r10,r10,0,17,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFF0007FFF;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r8,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// stw r10,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
	// b 0x825fe77c
	goto loc_825FE77C;
}

DEFINE_REX_FUNC(sub_82608AA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82608AB0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r30,r11,-15220
	ctx.r30.s64 = ctx.r11.s64 + -15220;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x82608AC8;
	sub_825F8ED0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r29,r11,-11592
	ctx.r29.s64 = ctx.r11.s64 + -11592;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
loc_82608AD8:
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
	// add r9,r31,r10
	ctx.r9.u64 = ctx.r31.u64 + ctx.r10.u64;
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
	// bne 0x82608ad8
	if (!ctx.cr0.eq) goto loc_82608AD8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// b 0x82608b4c
	goto loc_82608B4C;
loc_82608AFC:
	// lwsync 
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
loc_82608B04:
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
	// stwcx. r31,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r31.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82608b04
	if (!ctx.cr0.eq) goto loc_82608B04;
	// db16cyc 
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x82608B28;
	sub_825F8ED0(ctx, base);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
loc_82608B2C:
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
	// add r10,r31,r11
	ctx.r10.u64 = ctx.r31.u64 + ctx.r11.u64;
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
	// bne 0x82608b2c
	if (!ctx.cr0.eq) goto loc_82608B2C;
	// mr r11,r11
	ctx.r11.u64 = ctx.r11.u64;
loc_82608B4C:
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bge cr6,0x82608afc
	if (!ctx.cr6.lt) goto loc_82608AFC;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r28,r11,-14928
	ctx.r28.s64 = ctx.r11.s64 + -14928;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x82608B64;
	sub_825F8ED0(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,-14924(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -14924);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,31
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 31, ctx.xer);
	// bge cr6,0x82608b80
	if (!ctx.cr6.lt) goto loc_82608B80;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// b 0x82608b88
	goto loc_82608B88;
loc_82608B80:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-14932(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -14932);
loc_82608B88:
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stw r11,-14924(r10)
	REX_STORE_U32(ctx.r10.u32 + -14924, ctx.r11.u32);
	// lis r10,255
	ctx.r10.s64 = 16711680;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// lwz r10,-14936(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + -14936);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82608bac
	if (!ctx.cr6.eq) goto loc_82608BAC;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x82608bb0
	goto loc_82608BB0;
loc_82608BAC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82608BB0:
	// stw r10,-14936(r9)
	REX_STORE_U32(ctx.r9.u32 + -14936, ctx.r10.u32);
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r9,7(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r31,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r31.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stb r8,7(r11)
	REX_STORE_U8(ctx.r11.u32 + 7, ctx.r8.u8);
	// lwz r26,4(r11)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwsync 
loc_82608BD8:
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
	// bne 0x82608bd8
	if (!ctx.cr0.eq) goto loc_82608BD8;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// addi r11,r11,-15216
	ctx.r11.s64 = ctx.r11.s64 + -15216;
	// lwz r7,-11588(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + -11588);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,-11588(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + -11588);
	// lwz r10,-11588(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + -11588);
	// rlwinm r7,r7,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r5,r5,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// srawi r4,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 4;
	// stwx r27,r7,r11
	REX_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r27.u32);
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r11.s64 = temp.s64;
	// stwx r26,r5,r6
	REX_STORE_U32(ctx.r5.u32 + ctx.r6.u32, ctx.r26.u32);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r11,-11588(r9)
	REX_STORE_U32(ctx.r9.u32 + -11588, ctx.r11.u32);
	// stw r26,-11576(r8)
	REX_STORE_U32(ctx.r8.u32 + -11576, ctx.r26.u32);
	// lwsync 
loc_82608C40:
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
	// bne 0x82608c40
	if (!ctx.cr0.eq) goto loc_82608C40;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-11580(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -11580);
	// bl 0x82748970
	ctx.lr = 0x82608C70;
	sub_82748970(ctx, base);
	// lwsync 
loc_82608C74:
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
	// bne 0x82608c74
	if (!ctx.cr0.eq) goto loc_82608C74;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8261A198) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x8261A1A0;
	__savegprlr_14(ctx, base);
	// li r12,-176
	ctx.r12.s64 = -176;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-560(r1)
	ea = -560 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lbz r11,45(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 45);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8261a6d4
	if (ctx.cr0.eq) goto loc_8261A6D4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lwz r19,0(r10)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8261A1DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82615e10
	ctx.lr = 0x8261A1E0;
	sub_82615E10(ctx, base);
	// mr. r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq 0x8261a6d4
	if (ctx.cr0.eq) goto loc_8261A6D4;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r24,0
	ctx.r24.s64 = 0;
	// mr r17,r24
	ctx.r17.u64 = ctx.r24.u64;
	// lbz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 44);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8261a21c
	if (ctx.cr0.eq) goto loc_8261A21C;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8261A214;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82615e10
	ctx.lr = 0x8261A218;
	sub_82615E10(ctx, base);
	// mr r17,r3
	ctx.r17.u64 = ctx.r3.u64;
loc_8261A21C:
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82617948
	ctx.lr = 0x8261A22C;
	sub_82617948(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// addi r10,r1,252
	ctx.r10.s64 = ctx.r1.s64 + 252;
	// addi r9,r3,-4
	ctx.r9.s64 = ctx.r3.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8261A23C:
	// lwzu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8261a23c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8261A23C;
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r20,116(r9)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r9.u32 + 116);
	// lbz r10,-12742(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -12742);
	// cmpwi cr6,r20,8
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 8, ctx.xer);
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// beq cr6,0x8261a268
	if (ctx.cr6.eq) goto loc_8261A268;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8261A268:
	// clrlwi r31,r11,24
	ctx.r31.u64 = ctx.r11.u32 & 0xFF;
	// cmpwi cr6,r20,8
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 8, ctx.xer);
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// beq cr6,0x8261a27c
	if (ctx.cr6.eq) goto loc_8261A27C;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8261A27C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmpwi cr6,r20,8
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 8, ctx.xer);
	// xori r14,r11,13
	ctx.r14.u64 = ctx.r11.u64 ^ 13;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// beq cr6,0x8261a294
	if (ctx.cr6.eq) goto loc_8261A294;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8261A294:
	// lbz r10,44(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 44);
	// li r15,2
	ctx.r15.s64 = 2;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// stw r29,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, ctx.r29.u32);
	// stw r24,324(r1)
	REX_STORE_U32(ctx.r1.u32 + 324, ctx.r24.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r24,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r24.u32);
	// xori r16,r11,10
	ctx.r16.u64 = ctx.r11.u64 ^ 10;
	// stw r15,360(r1)
	REX_STORE_U32(ctx.r1.u32 + 360, ctx.r15.u32);
	// stw r24,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r24.u32);
	// bne 0x8261a2c8
	if (!ctx.cr0.eq) goto loc_8261A2C8;
loc_8261A2C0:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// b 0x8261a2fc
	goto loc_8261A2FC;
loc_8261A2C8:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8261A2DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82615e10
	ctx.lr = 0x8261A2E0;
	sub_82615E10(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8261a2c0
	if (ctx.cr0.eq) goto loc_8261A2C0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8261A2F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsb r11,r3
	ctx.r11.s64 = ctx.r3.s8;
loc_8261A2FC:
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lfs f0,260(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 260);
	ctx.f0.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// lfs f13,64(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,56(r19)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r19.u32 + 56, temp.u32);
	// stfs f13,60(r19)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r19.u32 + 60, temp.u32);
	// bl 0x82618030
	ctx.lr = 0x8261A320;
	sub_82618030(ctx, base);
	// lwz r11,272(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 272);
	// mr r26,r24
	ctx.r26.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8261a678
	if (ctx.cr6.eq) goto loc_8261A678;
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// clrlwi r21,r31,24
	ctx.r21.u64 = ctx.r31.u32 & 0xFF;
	// li r22,16
	ctx.r22.s64 = 16;
	// addi r29,r11,31600
	ctx.r29.s64 = ctx.r11.s64 + 31600;
loc_8261A340:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8261A35C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,164(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// lwz r5,196(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r7,r26,r11
	ctx.r7.u64 = ctx.r26.u64 + ctx.r11.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// bl 0x82617d20
	ctx.lr = 0x8261A380;
	sub_82617D20(ctx, base);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lbz r9,0(r25)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r25.u32 + 0);
	// lfs f0,208(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,212(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 212);
	ctx.f13.f64 = double(temp.f32);
	// stw r24,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r24.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stw r24,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r24.u32);
	// cmplw cr6,r9,r21
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r21.u32, ctx.xer);
	// lvx128 v127,r10,r22
	ea = (ctx.r10.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8261a64c
	if (ctx.cr6.eq) goto loc_8261A64C;
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// li r10,64
	ctx.r10.s64 = 64;
	// clrlwi r23,r14,24
	ctx.r23.u64 = ctx.r14.u32 & 0xFF;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r29,r10
	ea = (ctx.r29.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8261A3CC:
	// lbzx r11,r31,r25
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r25.u32);
	// cmplw cr6,r11,r23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r23.u32, ctx.xer);
	// beq cr6,0x8261a64c
	if (ctx.cr6.eq) goto loc_8261A64C;
	// clrlwi r10,r16,24
	ctx.r10.u64 = ctx.r16.u32 & 0xFF;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8261a64c
	if (ctx.cr6.eq) goto loc_8261A64C;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8261a3fc
	if (!ctx.cr6.eq) goto loc_8261A3FC;
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// b 0x8261a424
	goto loc_8261A424;
loc_8261A3FC:
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// add r3,r31,r27
	ctx.r3.u64 = ctx.r31.u64 + ctx.r27.u64;
	// bctrl 
	ctx.lr = 0x8261A410;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// li r10,64
	ctx.r10.s64 = 64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r29,r10
	ea = (ctx.r29.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8261A424:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lbz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 44);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8261a468
	if (ctx.cr0.eq) goto loc_8261A468;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8261a468
	if (ctx.cr6.eq) goto loc_8261A468;
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// add r3,r31,r27
	ctx.r3.u64 = ctx.r31.u64 + ctx.r27.u64;
	// bctrl 
	ctx.lr = 0x8261A454;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// li r10,64
	ctx.r10.s64 = 64;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r29,r10
	ea = (ctx.r29.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8261a46c
	goto loc_8261A46C;
loc_8261A468:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
loc_8261A46C:
	// clrlwi. r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8261a59c
	if (ctx.cr0.eq) goto loc_8261A59C;
	// lbz r11,244(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 244);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8261a49c
	if (ctx.cr0.eq) goto loc_8261A49C;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r9.u32);
	// lvx128 v127,r11,r22
	ea = (ctx.r11.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8261a590
	goto loc_8261A590;
loc_8261A49C:
	// lbz r11,245(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 245);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8261a4d8
	if (ctx.cr0.eq) goto loc_8261A4D8;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// vor128 v0,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvsl v7,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lvsr v6,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vperm128 v61,v62,v62,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v12,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vspltw128 v13,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vor128 v127,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vsel128 v127,v0,v13,v127
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v127,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8261A4D8:
	// lbz r11,246(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 246);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8261a514
	if (ctx.cr0.eq) goto loc_8261A514;
	// li r11,4
	ctx.r11.s64 = 4;
	// vor128 v0,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvsl v7,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lvsr v6,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vperm128 v61,v62,v62,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v12,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vspltw128 v13,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vor128 v127,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vsel128 v127,v0,v13,v127
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v127,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8261A514:
	// lbz r11,247(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 247);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8261a550
	if (ctx.cr0.eq) goto loc_8261A550;
	// li r11,8
	ctx.r11.s64 = 8;
	// vor128 v13,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvsl v0,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lvsr v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vperm128 v61,v62,v62,v0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v12,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vspltw128 v0,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vor128 v127,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vsel128 v127,v13,v0,v127
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v127,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8261A550:
	// lbz r11,248(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 248);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8261a58c
	if (ctx.cr0.eq) goto loc_8261A58C;
	// li r11,12
	ctx.r11.s64 = 12;
	// vor128 v13,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// li r10,12
	ctx.r10.s64 = 12;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvsl v0,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lvsr v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vperm128 v61,v62,v62,v0
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v12,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vspltw128 v0,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vor128 v127,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vsel128 v127,v13,v0,v127
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v127,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8261A58C:
	// stw r15,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r15.u32);
loc_8261A590:
	// lwz r11,240(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 240);
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// b 0x8261a5f8
	goto loc_8261A5F8;
loc_8261A59C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// mr r9,r17
	ctx.r9.u64 = ctx.r17.u64;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// beq 0x8261a600
	if (ctx.cr0.eq) goto loc_8261A600;
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// stw r19,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r19.u32);
	// mr r8,r18
	ctx.r8.u64 = ctx.r18.u64;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// bl 0x82619b28
	ctx.lr = 0x8261A5D4;
	sub_82619B28(ctx, base);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r11,288(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 288);
	// li r8,64
	ctx.r8.s64 = 64;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r29,r8
	ea = (ctx.r29.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lvx128 v127,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r31,r11,r9
	ctx.r31.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_8261A5F8:
	// stw r31,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r31.u32);
	// b 0x8261a640
	goto loc_8261A640;
loc_8261A600:
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// stw r19,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r19.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r24,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r24.u8);
	// stw r8,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mr r8,r18
	ctx.r8.u64 = ctx.r18.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// bl 0x82618ef0
	ctx.lr = 0x8261A624;
	sub_82618EF0(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// li r9,64
	ctx.r9.s64 = 64;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r29,r9
	ea = (ctx.r29.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,144(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8261A640:
	// lbzx r11,r31,r25
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r25.u32);
	// cmplw cr6,r11,r21
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r21.u32, ctx.xer);
	// bne cr6,0x8261a3cc
	if (!ctx.cr6.eq) goto loc_8261A3CC;
loc_8261A64C:
	// lwz r3,196(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8261a65c
	if (ctx.cr6.eq) goto loc_8261A65C;
	// bl 0x825e0378
	ctx.lr = 0x8261A65C;
	sub_825E0378(ctx, base);
loc_8261A65C:
	// lwz r11,272(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 272);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// stw r24,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r24.u32);
	// stw r24,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r24.u32);
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// stw r24,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r24.u32);
	// blt cr6,0x8261a340
	if (ctx.cr6.lt) goto loc_8261A340;
loc_8261A678:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r3,r9,15708
	ctx.r3.s64 = ctx.r9.s64 + 15708;
	// li r4,24
	ctx.r4.s64 = 24;
	// lwz r9,-15508(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + -15508);
	// lwz r31,-12736(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + -12736);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8261A69C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x825fad98
	ctx.lr = 0x8261A6A0;
	sub_825FAD98(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// li r9,20
	ctx.r9.s64 = 20;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// lwz r8,16(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r7,12
	ctx.r7.s64 = 12;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r10,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// stw r3,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r3.u32);
	// sth r9,0(r8)
	REX_STORE_U16(ctx.r8.u32 + 0, ctx.r9.u16);
	// sth r7,2(r8)
	REX_STORE_U16(ctx.r8.u32 + 2, ctx.r7.u16);
	// stw r24,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r24.u32);
loc_8261A6D4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// li r0,-176
	ctx.r0.s64 = -176;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264B8C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lhz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,357
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 357, ctx.xer);
	// bne cr6,0x8264b904
	if (!ctx.cr6.eq) goto loc_8264B904;
	// lhz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blelr 
	if (!ctx.cr0.gt) return;
	// addi r9,r11,10
	ctx.r9.s64 = ctx.r11.s64 + 10;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8264B8E8:
	// lhzu r11,20(r9)
	ea = 20 + ctx.r9.u32;
	ctx.r11.u64 = REX_LOAD_U16(ea);
	ctx.r9.u32 = ea;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r11,r11,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFFFFFF;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 | ctx.r3.u64;
	// bdnz 0x8264b8e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8264B8E8;
	// blr 
	return;
loc_8264B904:
	// cmplwi cr6,r10,358
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 358, ctx.xer);
	// beq cr6,0x8264b914
	if (ctx.cr6.eq) goto loc_8264B914;
	// cmplwi cr6,r10,65534
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65534, ctx.xer);
	// bne cr6,0x8264b91c
	if (!ctx.cr6.eq) goto loc_8264B91C;
loc_8264B914:
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// blr 
	return;
loc_8264B91C:
	// lhz r11,2(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8264b930
	if (!ctx.cr6.eq) goto loc_8264B930;
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_8264B930:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8264b940
	if (!ctx.cr6.eq) goto loc_8264B940;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8264B940:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// lis r10,-32116
	ctx.r10.s64 = -2104754176;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,13388
	ctx.r10.s64 = ctx.r10.s64 + 13388;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,-4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8264E7C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r9,56(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r10,72(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 72);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mullw r7,r10,r4
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// lfs f0,5864(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 5864);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r9.u32);
	// lfs f13,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// stw r7,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r7.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x8264e884
	if (ctx.cr6.eq) goto loc_8264E884;
	// clrldi r9,r4,32
	ctx.r9.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lfs f12,92(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// std r9,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// bne cr6,0x8264e840
	if (!ctx.cr6.eq) goto loc_8264E840;
	// lfs f12,96(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bne cr6,0x8264e840
	if (!ctx.cr6.eq) goto loc_8264E840;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfd f0,6296(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 6296);
	// fadd f0,f13,f0
	ctx.f0.f64 = ctx.f13.f64 + ctx.f0.f64;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// b 0x8264e8a4
	goto loc_8264E8A4;
loc_8264E840:
	// lwz r7,52(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// lwz r8,76(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// rotlwi r9,r8,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r8,r8,r10
	ctx.r8.u64 = uint32_t((ctx.r10.s32 && !(ctx.r8.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r8.s32 / ctx.r10.s32 : 0);
	// stw r7,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r7.u32);
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// fadd f0,f0,f13
	ctx.f0.f64 = ctx.f0.f64 + ctx.f13.f64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// andc r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 & ~ctx.r9.u64;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// twlgei r9,-1
	if (ctx.r9.s32 == -1 || ctx.r9.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// lwz r9,-12(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// b 0x8264e8a4
	goto loc_8264E8A4;
loc_8264E884:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r8,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r8.u32);
	// lfs f0,2524(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2524);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r9,-16(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -16);
	// stw r9,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r9.u32);
loc_8264E8A4:
	// mullw r10,r10,r3
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// stw r10,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8265B2E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8265B2F0;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,356(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 356);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// lwz r28,360(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 360);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8265b388
	if (ctx.cr6.eq) goto loc_8265B388;
	// lhz r11,110(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 110);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// addi r25,r11,-16
	ctx.r25.s64 = ctx.r11.s64 + -16;
	// ble cr6,0x8265b388
	if (!ctx.cr6.gt) goto loc_8265B388;
	// rlwinm r23,r28,1,0,30
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
loc_8265B328:
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x8265b370
	if (!ctx.cr6.gt) goto loc_8265B370;
	// addi r29,r24,-2
	ctx.r29.s64 = ctx.r24.s64 + -2;
loc_8265B338:
	// lwz r11,524(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 524);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lhz r5,110(r30)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r30.u32 + 110);
	// lwz r4,88(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8265B354;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// sraw r10,r3,r25
	temp.u32 = ctx.r25.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r3.s32 < 0) & (((ctx.r3.s32 >> temp.u32) << temp.u32) != ctx.r3.s32);
	ctx.r10.s64 = ctx.r3.s32 >> temp.u32;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lhz r9,82(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 82);
	// cmpw cr6,r31,r28
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r28.s32, ctx.xer);
	// sthu r9,2(r29)
	ea = 2 + ctx.r29.u32;
	REX_STORE_U16(ea, ctx.r9.u16);
	ctx.r29.u32 = ea;
	// blt cr6,0x8265b338
	if (ctx.cr6.lt) goto loc_8265B338;
loc_8265B370:
	// lwz r11,88(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// add r24,r23,r24
	ctx.r24.u64 = ctx.r23.u64 + ctx.r24.u64;
	// mullw r11,r28,r11
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r11.s32);
	// add r27,r11,r27
	ctx.r27.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bne 0x8265b328
	if (!ctx.cr0.eq) goto loc_8265B328;
loc_8265B388:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8265FA10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8265FA18;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,13120
	ctx.r3.s64 = ctx.r11.s64 + 13120;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// bl 0x82641ff8
	ctx.lr = 0x8265FA54;
	sub_82641FF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8265fa78
	if (ctx.cr0.eq) goto loc_8265FA78;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8265f948
	ctx.lr = 0x8265FA70;
	sub_8265F948(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8265fa7c
	goto loc_8265FA7C;
loc_8265FA78:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8265FA7C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8265fa90
	if (!ctx.cr6.eq) goto loc_8265FA90;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x8265fae0
	goto loc_8265FAE0;
loc_8265FA90:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8265FAB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8265fac4
	if (ctx.cr0.lt) goto loc_8265FAC4;
	// stw r30,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r30.u32);
	// b 0x8265fae0
	goto loc_8265FAE0;
loc_8265FAC4:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8265FADC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8264cf40
	ctx.lr = 0x8265FAE0;
	sub_8264CF40(ctx, base);
loc_8265FAE0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82663B48) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lis r9,-30569
	ctx.r9.s64 = -2003369984;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// ori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 | 1;
	// lwz r11,1048(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1048);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82663b8c
	if (ctx.cr0.eq) goto loc_82663B8C;
	// lhz r11,2(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 2);
	// lhz r8,2(r5)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r5.u32 + 2);
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82663b8c
	if (ctx.cr6.eq) goto loc_82663B8C;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x82663b8c
	if (ctx.cr6.eq) goto loc_82663B8C;
	// sth r11,2(r5)
	REX_STORE_U16(ctx.r5.u32 + 2, ctx.r11.u16);
loc_82663B8C:
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,1048(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1048);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82663bbc
	if (ctx.cr0.eq) goto loc_82663BBC;
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r8,4(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82663bbc
	if (ctx.cr6.eq) goto loc_82663BBC;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x82663bbc
	if (ctx.cr6.eq) goto loc_82663BBC;
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
loc_82663BBC:
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,1048(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1048);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// lhz r11,14(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 14);
	// lhz r10,14(r5)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r5.u32 + 14);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82663bf0
	if (ctx.cr6.eq) goto loc_82663BF0;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x82663bf0
	if (ctx.cr6.eq) goto loc_82663BF0;
	// sth r11,14(r5)
	REX_STORE_U16(ctx.r5.u32 + 14, ctx.r11.u16);
loc_82663BF0:
	// lhz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,65534
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65534, ctx.xer);
	// lhz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r5.u32 + 0);
	// bne cr6,0x82663c28
	if (!ctx.cr6.eq) goto loc_82663C28;
	// cmplwi cr6,r11,65534
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65534, ctx.xer);
	// bne cr6,0x82663c10
	if (!ctx.cr6.eq) goto loc_82663C10;
	// lhz r11,18(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 18);
	// b 0x82663c34
	goto loc_82663C34;
loc_82663C10:
	// lhz r11,18(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 18);
	// lhz r10,14(r5)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r5.u32 + 14);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// blr 
	return;
loc_82663C28:
	// cmplwi cr6,r11,65534
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65534, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lhz r11,14(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 14);
loc_82663C34:
	// lhz r10,18(r5)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r5.u32 + 18);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// sth r11,18(r5)
	REX_STORE_U16(ctx.r5.u32 + 18, ctx.r11.u16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826749B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,444(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 444);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82674a34
	if (ctx.cr6.eq) goto loc_82674A34;
	// lwz r11,456(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// lhz r10,118(r4)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r4.u32 + 118);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lhz r8,122(r4)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r4.u32 + 122);
	// extsh r7,r10
	ctx.r7.s64 = ctx.r10.s16;
	// lhz r6,124(r4)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r4.u32 + 124);
	// extsh r5,r10
	ctx.r5.s64 = ctx.r10.s16;
	// lhz r11,126(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 126);
	// sraw r10,r7,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r7.s32 < 0) & (((ctx.r7.s32 >> temp.u32) << temp.u32) != ctx.r7.s32);
	ctx.r10.s64 = ctx.r7.s32 >> temp.u32;
	// sth r10,120(r4)
	REX_STORE_U16(ctx.r4.u32 + 120, ctx.r10.u16);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// lwz r8,456(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// sraw r7,r5,r10
	temp.u32 = ctx.r10.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r5.s32 < 0) & (((ctx.r5.s32 >> temp.u32) << temp.u32) != ctx.r5.s32);
	ctx.r7.s64 = ctx.r5.s32 >> temp.u32;
	// stw r7,140(r4)
	REX_STORE_U32(ctx.r4.u32 + 140, ctx.r7.u32);
	// extsh r8,r6
	ctx.r8.s64 = ctx.r6.s16;
	// lwz r5,456(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// sraw r10,r9,r11
	temp.u32 = ctx.r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r9.s32 < 0) & (((ctx.r9.s32 >> temp.u32) << temp.u32) != ctx.r9.s32);
	ctx.r10.s64 = ctx.r9.s32 >> temp.u32;
	// sth r10,122(r4)
	REX_STORE_U16(ctx.r4.u32 + 122, ctx.r10.u16);
	// lwz r9,456(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// sraw r5,r8,r7
	temp.u32 = ctx.r7.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r5.s64 = ctx.r8.s32 >> temp.u32;
	// sth r5,124(r4)
	REX_STORE_U16(ctx.r4.u32 + 124, ctx.r5.u16);
	// lwz r3,456(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// sraw r10,r6,r11
	temp.u32 = ctx.r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r6.s32 < 0) & (((ctx.r6.s32 >> temp.u32) << temp.u32) != ctx.r6.s32);
	ctx.r10.s64 = ctx.r6.s32 >> temp.u32;
	// sth r10,126(r4)
	REX_STORE_U16(ctx.r4.u32 + 126, ctx.r10.u16);
	// blr 
	return;
loc_82674A34:
	// lwz r11,448(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 448);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhz r11,118(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 118);
	// beq cr6,0x82674aac
	if (ctx.cr6.eq) goto loc_82674AAC;
	// lwz r10,456(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lhz r8,122(r4)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r4.u32 + 122);
	// slw r6,r9,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// sth r6,120(r4)
	REX_STORE_U16(ctx.r4.u32 + 120, ctx.r6.u16);
	// lhz r7,124(r4)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r4.u32 + 124);
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// lhz r5,126(r4)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r4.u32 + 126);
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// lwz r7,456(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// slw r6,r9,r7
	ctx.r6.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// stw r6,140(r4)
	REX_STORE_U32(ctx.r4.u32 + 140, ctx.r6.u32);
	// lwz r11,456(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// slw r7,r10,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// sth r7,122(r4)
	REX_STORE_U16(ctx.r4.u32 + 122, ctx.r7.u16);
	// lwz r11,456(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// slw r9,r8,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// sth r9,124(r4)
	REX_STORE_U16(ctx.r4.u32 + 124, ctx.r9.u16);
	// lwz r7,456(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 456);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// slw r5,r5,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r6.u8 & 0x3F));
	// sth r5,126(r4)
	REX_STORE_U16(ctx.r4.u32 + 126, ctx.r5.u16);
	// blr 
	return;
loc_82674AAC:
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// sth r11,120(r4)
	REX_STORE_U16(ctx.r4.u32 + 120, ctx.r11.u16);
	// stw r10,140(r4)
	REX_STORE_U32(ctx.r4.u32 + 140, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8267A128) {
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
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,14592
	ctx.r30.s64 = ctx.r11.s64 + 14592;
	// lwz r11,160(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8267a158
	if (!ctx.cr6.eq) goto loc_8267A158;
	// bl 0x8267a058
	ctx.lr = 0x8267A158;
	sub_8267A058(ctx, base);
loc_8267A158:
	// cmpwi cr6,r31,20
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 20, ctx.xer);
	// blt cr6,0x8267a1c4
	if (ctx.cr6.lt) goto loc_8267A1C4;
	// cmpwi cr6,r31,320
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 320, ctx.xer);
	// bge cr6,0x8267a1c4
	if (!ctx.cr6.lt) goto loc_8267A1C4;
	// lis r11,26214
	ctx.r11.s64 = 1717960704;
	// li r10,20
	ctx.r10.s64 = 20;
	// ori r9,r11,26215
	ctx.r9.u64 = ctx.r11.u64 | 26215;
	// divw r10,r31,r10
	ctx.r10.u64 = uint32_t((ctx.r10.s32 && !(ctx.r31.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r31.s32 / ctx.r10.s32 : 0);
	// mulhw r8,r31,r9
	ctx.r8.s64 = (int64_t(ctx.r31.s32) * int64_t(ctx.r9.s32)) >> 32;
	// srawi r11,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 3;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf. r11,r6,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x8267a1a4
	if (!ctx.cr0.lt) goto loc_8267A1A4;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_8267A1A4:
	// addi r9,r30,80
	ctx.r9.s64 = ctx.r30.s64 + 80;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r30,20
	ctx.r6.s64 = ctx.r30.s64 + 20;
	// lfsx f0,r8,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r7,r6
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// b 0x8267a1f4
	goto loc_8267A1F4;
loc_8267A1C4:
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,24128(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24128);
	ctx.f0.f64 = double(temp.f32);
	// lfd f1,8696(r10)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r10.u32 + 8696);
	// fmuls f2,f12,f0
	ctx.f2.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// bl 0x82738fd8
	ctx.lr = 0x8267A1F0;
	sub_82738FD8(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
loc_8267A1F4:
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

DEFINE_REX_FUNC(sub_82683A20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82683A28;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x8268f118
	ctx.lr = 0x82683A40;
	sub_8268F118(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r30,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r29,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r29.u32);
	// addi r10,r10,-4828
	ctx.r10.s64 = ctx.r10.s64 + -4828;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// stw r11,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
	// stw r9,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r9.u32);
	// stw r11,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82684678) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r4,r9,7644
	ctx.r4.s64 = ctx.r9.s64 + 7644;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826846BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// blt 0x826846fc
	if (ctx.cr0.lt) goto loc_826846FC;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826846DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826846F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82684714
	goto loc_82684714;
loc_826846FC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82684710;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_82684714:
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

DEFINE_REX_FUNC(sub_8268BF88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8268BF90;
	__savegprlr_23(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lhz r11,34(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 34);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// addi r7,r10,544
	ctx.r7.s64 = ctx.r10.s64 + 544;
	// addi r4,r8,27472
	ctx.r4.s64 = ctx.r8.s64 + 27472;
	// addi r28,r3,34
	ctx.r28.s64 = ctx.r3.s64 + 34;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8268c27c
	if (ctx.cr6.eq) goto loc_8268C27C;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x8268c0ac
	if (ctx.cr6.eq) goto loc_8268C0AC;
	// clrlwi r4,r5,16
	ctx.r4.u64 = ctx.r5.u32 & 0xFFFF;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x8268c45c
	if (!ctx.cr6.gt) goto loc_8268C45C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,1
	ctx.r30.s64 = 1;
	// lfs f13,7996(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7996);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2524(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2524);
	ctx.f12.f64 = double(temp.f32);
loc_8268BFEC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8268c094
	if (!ctx.cr6.gt) goto loc_8268C094;
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r31,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r11,-2
	ctx.r7.s64 = ctx.r11.s64 + -2;
loc_8268C008:
	// lwz r11,320(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 320);
	// mulli r10,r8,1776
	ctx.r10.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(1776));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lhz r11,110(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 110);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lfsx f0,r10,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x8268c054
	if (!ctx.cr6.lt) goto loc_8268C054;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// slw r11,r30,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// fctiwz f11,f0
	ctx.f11.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f11,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f11.u64);
	// lwz r11,-108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -108);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8268c078
	if (!ctx.cr6.lt) goto loc_8268C078;
	// b 0x8268c074
	goto loc_8268C074;
loc_8268C054:
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// slw r10,r30,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// fctiwz f11,f0
	ctx.f11.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stfd f11,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f11.u64);
	// lwz r11,-108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -108);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8268c078
	if (!ctx.cr6.gt) goto loc_8268C078;
loc_8268C074:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8268C078:
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// sthu r11,2(r7)
	ea = 2 + ctx.r7.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r7.u32 = ea;
	// lhz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8268c008
	if (ctx.cr6.lt) goto loc_8268C008;
loc_8268C094:
	// addi r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 1;
	// extsh r31,r10
	ctx.r31.s64 = ctx.r10.s16;
	// cmpw cr6,r31,r4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x8268bfec
	if (ctx.cr6.lt) goto loc_8268BFEC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
loc_8268C0AC:
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// extsh r30,r10
	ctx.r30.s64 = ctx.r10.s16;
	// subf r7,r30,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r30.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// extsh r29,r7
	ctx.r29.s64 = ctx.r7.s16;
	// ble cr6,0x8268c19c
	if (!ctx.cr6.gt) goto loc_8268C19C;
	// addi r31,r3,320
	ctx.r31.s64 = ctx.r3.s64 + 320;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
loc_8268C0D8:
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r6,r11,3
	ctx.r6.s64 = ctx.r11.s64 + 3;
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// rlwinm r27,r6,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,60(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 60);
	// addi r25,r1,-96
	ctx.r25.s64 = ctx.r1.s64 + -96;
	// lwz r8,1836(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 1836);
	// addi r23,r1,-96
	ctx.r23.s64 = ctx.r1.s64 + -96;
	// add r7,r6,r10
	ctx.r7.u64 = ctx.r6.u64 + ctx.r10.u64;
	// addi r26,r1,-112
	ctx.r26.s64 = ctx.r1.s64 + -112;
	// addi r24,r1,-112
	ctx.r24.s64 = ctx.r1.s64 + -112;
	// lfsx f0,r5,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lfsx f13,r27,r10
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f10,r6,r10
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// add r10,r6,r8
	ctx.r10.u64 = ctx.r6.u64 + ctx.r8.u64;
	// lfs f9,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfsx f8,r6,r8
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	ctx.f8.f64 = double(temp.f32);
	// stfs f10,-96(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// stfs f9,-88(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// lfs f7,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// stfs f8,-92(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// stfs f7,-84(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// lvx128 v60,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f12,r5,r8
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// extsh r5,r11
	ctx.r5.s64 = ctx.r11.s16;
	// lfsx f11,r27,r8
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + ctx.r8.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,-112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// stfs f13,-104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// cmpw cr6,r5,r30
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r30.s32, ctx.xer);
	// stfs f12,-108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// stfs f11,-100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -100, temp.u32);
	// lvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaxfp128 v58,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v58.f32, simde_mm_max_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vmaxfp128 v59,v63,v60
	simde_mm_store_ps(ctx.v59.f32, simde_mm_max_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vminfp128 v56,v62,v58
	simde_mm_store_ps(ctx.v56.f32, simde_mm_min_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vminfp128 v57,v62,v59
	simde_mm_store_ps(ctx.v57.f32, simde_mm_min_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vcfpsxws128 v61,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v56.f32)));
	// vcfpsxws128 v60,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v57.f32)));
	// stvx128 v61,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkswss128 v55,v60,v61
	simde_mm_store_si128((simde__m128i*)ctx.v55.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.s32), simde_mm_load_si128((simde__m128i*)ctx.v60.s32)));
	// stvx128 v60,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvlx128 v55,r0,r9
	ea = ctx.r9.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v55.u8[15 - i]);
	// stvrx128 v55,r9,r4
	ea = ctx.r9.u32 + ctx.r4.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v55.u8[i]);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// blt cr6,0x8268c0d8
	if (ctx.cr6.lt) goto loc_8268C0D8;
loc_8268C19C:
	// extsh r11,r29
	ctx.r11.s64 = ctx.r29.s16;
	// extsh r6,r5
	ctx.r6.s64 = ctx.r5.s16;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmpw cr6,r6,r5
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x8268c45c
	if (!ctx.cr6.lt) goto loc_8268C45C;
	// addi r8,r9,-2
	ctx.r8.s64 = ctx.r9.s64 + -2;
	// lhz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r30,1
	ctx.r30.s64 = 1;
	// lfs f13,7996(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7996);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2524);
	ctx.f12.f64 = double(temp.f32);
loc_8268C1CC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8268c264
	if (!ctx.cr6.gt) goto loc_8268C264;
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
loc_8268C1DC:
	// lwz r11,320(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 320);
	// mulli r10,r9,1776
	ctx.r10.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(1776));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lhz r11,110(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 110);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lfsx f0,r10,r7
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x8268c228
	if (!ctx.cr6.lt) goto loc_8268C228;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// slw r11,r30,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// fctiwz f11,f0
	ctx.f11.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f11,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f11.u64);
	// lwz r11,-108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -108);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8268c24c
	if (!ctx.cr6.lt) goto loc_8268C24C;
	// b 0x8268c248
	goto loc_8268C248;
loc_8268C228:
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// slw r10,r30,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// fctiwz f11,f0
	ctx.f11.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stfd f11,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f11.u64);
	// lwz r11,-108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -108);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8268c24c
	if (!ctx.cr6.gt) goto loc_8268C24C;
loc_8268C248:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8268C24C:
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// sthu r11,2(r8)
	ea = 2 + ctx.r8.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r8.u32 = ea;
	// lhz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8268c1dc
	if (ctx.cr6.lt) goto loc_8268C1DC;
loc_8268C264:
	// addi r10,r6,1
	ctx.r10.s64 = ctx.r6.s64 + 1;
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// cmpw cr6,r6,r5
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x8268c1cc
	if (ctx.cr6.lt) goto loc_8268C1CC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
loc_8268C27C:
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwinm r10,r11,0,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// subf r5,r6,r11
	ctx.r5.u64 = ctx.r11.u64 - ctx.r6.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// ble cr6,0x8268c384
	if (!ctx.cr6.gt) goto loc_8268C384;
	// addi r7,r3,320
	ctx.r7.s64 = ctx.r3.s64 + 320;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
loc_8268C2A8:
	// lwz r10,0(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// addi r30,r11,6
	ctx.r30.s64 = ctx.r11.s64 + 6;
	// rlwinm r27,r8,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,5
	ctx.r31.s64 = ctx.r11.s64 + 5;
	// addi r29,r11,7
	ctx.r29.s64 = ctx.r11.s64 + 7;
	// lwz r10,60(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r31,r31,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r29,r29,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r26,r1,-112
	ctx.r26.s64 = ctx.r1.s64 + -112;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r27,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r27,r11,2
	ctx.r27.s64 = ctx.r11.s64 + 2;
	// lfsx f12,r30,r10
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	ctx.f12.f64 = double(temp.f32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r30,r27,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r31,r10
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f11,r29,r10
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r10.u32);
	ctx.f11.f64 = double(temp.f32);
	// addi r27,r1,-112
	ctx.r27.s64 = ctx.r1.s64 + -112;
	// stfs f0,-112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// addi r31,r11,3
	ctx.r31.s64 = ctx.r11.s64 + 3;
	// stfs f13,-108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// addi r29,r1,-96
	ctx.r29.s64 = ctx.r1.s64 + -96;
	// stfs f12,-104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// rlwinm r31,r31,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f11,-100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + -100, temp.u32);
	// addi r25,r1,-96
	ctx.r25.s64 = ctx.r1.s64 + -96;
	// lvx128 v52,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// lfs f10,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// extsh r8,r11
	ctx.r8.s64 = ctx.r11.s16;
	// lfsx f8,r30,r10
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	ctx.f8.f64 = double(temp.f32);
	// lfsx f7,r31,r10
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	ctx.f7.f64 = double(temp.f32);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// stfs f10,-96(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// cmpw cr6,r8,r6
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, ctx.xer);
	// stfs f9,-92(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// stfs f8,-88(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// stfs f7,-84(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// lvx128 v54,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaxfp128 v53,v63,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v53.f32, simde_mm_max_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v54.f32)));
	// vmaxfp128 v50,v63,v52
	simde_mm_store_ps(ctx.v50.f32, simde_mm_max_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v52.f32)));
	// vminfp128 v51,v62,v53
	simde_mm_store_ps(ctx.v51.f32, simde_mm_min_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v53.f32)));
	// vminfp128 v49,v62,v50
	simde_mm_store_ps(ctx.v49.f32, simde_mm_min_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v50.f32)));
	// vcfpsxws128 v61,v51,0
	simde_mm_store_si128((simde__m128i*)ctx.v61.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v51.f32)));
	// vcfpsxws128 v60,v49,0
	simde_mm_store_si128((simde__m128i*)ctx.v60.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v49.f32)));
	// stvx128 v61,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkswss128 v48,v61,v60
	simde_mm_store_si128((simde__m128i*)ctx.v48.s16, simde_mm_packs_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.s32), simde_mm_load_si128((simde__m128i*)ctx.v61.s32)));
	// stvx128 v60,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvlx128 v48,r0,r9
	ea = ctx.r9.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v48.u8[15 - i]);
	// stvrx128 v48,r9,r4
	ea = ctx.r9.u32 + ctx.r4.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v48.u8[i]);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// blt cr6,0x8268c2a8
	if (ctx.cr6.lt) goto loc_8268C2A8;
loc_8268C384:
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// extsh r5,r8
	ctx.r5.s64 = ctx.r8.s16;
	// add r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 + ctx.r6.u64;
	// cmpw cr6,r5,r6
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x8268c45c
	if (!ctx.cr6.lt) goto loc_8268C45C;
	// addi r8,r9,-2
	ctx.r8.s64 = ctx.r9.s64 + -2;
	// lhz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r30,1
	ctx.r30.s64 = 1;
	// lfs f13,7996(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7996);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2524);
	ctx.f12.f64 = double(temp.f32);
loc_8268C3B4:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8268c44c
	if (!ctx.cr6.gt) goto loc_8268C44C;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
loc_8268C3C4:
	// lwz r11,320(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 320);
	// mulli r10,r9,1776
	ctx.r10.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(1776));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lhz r11,110(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 110);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lfsx f0,r10,r7
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x8268c410
	if (!ctx.cr6.lt) goto loc_8268C410;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// slw r11,r30,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// fctiwz f11,f0
	ctx.f11.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f11,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f11.u64);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r11,-108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -108);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8268c434
	if (!ctx.cr6.lt) goto loc_8268C434;
	// b 0x8268c430
	goto loc_8268C430;
loc_8268C410:
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// slw r10,r30,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// fctiwz f11,f0
	ctx.f11.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stfd f11,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f11.u64);
	// lwz r11,-108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -108);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8268c434
	if (!ctx.cr6.gt) goto loc_8268C434;
loc_8268C430:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8268C434:
	// sthu r11,2(r8)
	ea = 2 + ctx.r8.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r8.u32 = ea;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// lhz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8268c3c4
	if (ctx.cr6.lt) goto loc_8268C3C4;
loc_8268C44C:
	// addi r10,r5,1
	ctx.r10.s64 = ctx.r5.s64 + 1;
	// extsh r5,r10
	ctx.r5.s64 = ctx.r10.s16;
	// cmpw cr6,r5,r6
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x8268c3b4
	if (ctx.cr6.lt) goto loc_8268C3B4;
loc_8268C45C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826CB528) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x826CB530;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af18
	ctx.lr = 0x826CB538;
	__savefpr_24(ctx, base);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r16,r3
	ctx.r16.u64 = ctx.r3.u64;
	// stw r3,484(r1)
	REX_STORE_U32(ctx.r1.u32 + 484, ctx.r3.u32);
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = ctx.f1.f64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// fmr f24,f2
	ctx.f24.f64 = ctx.f2.f64;
	// fmr f27,f3
	ctx.f27.f64 = ctx.f3.f64;
	// fmr f26,f4
	ctx.f26.f64 = ctx.f4.f64;
	// bne cr6,0x826cb570
	if (!ctx.cr6.eq) goto loc_826CB570;
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af64
	ctx.lr = 0x826CB56C;
	__restfpr_24(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_826CB570:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r25,20(r16)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r16.u32 + 20);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lwz r9,15360(r16)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lwz r18,15376(r16)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r16.u32 + 15376);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r17,15380(r16)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r16.u32 + 15380);
	// srawi r29,r25,1
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x1) != 0);
	ctx.r29.s64 = ctx.r25.s32 >> 1;
	// lfs f0,5864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5864);
	ctx.f0.f64 = double(temp.f32);
	// srawi r26,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r26.s64 = ctx.r9.s32 >> 1;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// srawi r23,r25,5
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x1F) != 0);
	ctx.r23.s64 = ctx.r25.s32 >> 5;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// srawi r21,r25,6
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3F) != 0);
	ctx.r21.s64 = ctx.r25.s32 >> 6;
	// lfd f29,24136(r7)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r7.u32 + 24136);
	// stw r18,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r18.u32);
	// fcmpu cr6,f25,f29
	ctx.cr6.compare(ctx.f25.f64, ctx.f29.f64);
	// stw r17,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r17.u32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r26,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r26.u32);
	// stw r23,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r23.u32);
	// stw r21,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r21.u32);
	// beq cr6,0x826cc820
	if (ctx.cr6.eq) goto loc_826CC820;
	// fcmpu cr6,f27,f29
	ctx.cr6.compare(ctx.f27.f64, ctx.f29.f64);
	// beq cr6,0x826cc820
	if (ctx.cr6.eq) goto loc_826CC820;
	// rotlwi r11,r25,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r25.u32, 0);
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
	// lfd f28,24232(r10)
	ctx.f28.u64 = REX_LOAD_U64(ctx.r10.u32 + 24232);
	// fsub f11,f13,f24
	ctx.f11.f64 = ctx.f13.f64 - ctx.f24.f64;
	// fdiv f12,f28,f25
	ctx.f12.f64 = ctx.f28.f64 / ctx.f25.f64;
	// fdiv f30,f11,f25
	ctx.f30.f64 = ctx.f11.f64 / ctx.f25.f64;
	// fmul f0,f12,f24
	ctx.f0.f64 = ctx.f12.f64 * ctx.f24.f64;
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x826cb61c
	if (!ctx.cr6.gt) goto loc_826CB61C;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
	// fmr f30,f13
	ctx.f30.f64 = ctx.f13.f64;
loc_826CB61C:
	// fsel f1,f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64 >= 0.0 ? ctx.f0.f64 : ctx.f29.f64;
	// bl 0x827389a8
	ctx.lr = 0x826CB624;
	sub_827389A8(ctx, base);
	// lwz r11,15360(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
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
	// bge cr6,0x826cb644
	if (!ctx.cr6.lt) goto loc_826CB644;
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
loc_826CB644:
	// bl 0x827389e8
	ctx.lr = 0x826CB648;
	sub_827389E8(ctx, base);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,15360(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
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
	// bge cr6,0x826cb680
	if (!ctx.cr6.lt) goto loc_826CB680;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_826CB680:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x827389e8
	ctx.lr = 0x826CB688;
	sub_827389E8(ctx, base);
	// lwz r11,15360(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
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
	// blt cr6,0x826cb6ac
	if (ctx.cr6.lt) goto loc_826CB6AC;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
loc_826CB6AC:
	// bl 0x827389e8
	ctx.lr = 0x826CB6B0;
	sub_827389E8(ctx, base);
	// fsel f1,f1,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : ctx.f29.f64;
	// bl 0x827389a8
	ctx.lr = 0x826CB6B8;
	sub_827389A8(ctx, base);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r30,84(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fsel f1,f31,f31,f29
	ctx.f1.f64 = ctx.f31.f64 >= 0.0 ? ctx.f31.f64 : ctx.f29.f64;
	// bl 0x827389a8
	ctx.lr = 0x826CB6CC;
	sub_827389A8(ctx, base);
	// lwz r11,15356(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15356);
	// fctiwz f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r28,84(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// fdiv f12,f28,f27
	ctx.f12.f64 = ctx.f28.f64 / ctx.f27.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// fsub f8,f9,f26
	ctx.f8.f64 = ctx.f9.f64 - ctx.f26.f64;
	// lfd f13,6304(r10)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r10.u32 + 6304);
	// fmul f0,f12,f26
	ctx.f0.f64 = ctx.f12.f64 * ctx.f26.f64;
	// fdiv f7,f8,f27
	ctx.f7.f64 = ctx.f8.f64 / ctx.f27.f64;
	// fadd f31,f7,f13
	ctx.f31.f64 = ctx.f7.f64 + ctx.f13.f64;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x826cb71c
	if (!ctx.cr6.gt) goto loc_826CB71C;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
	// fmr f31,f13
	ctx.f31.f64 = ctx.f13.f64;
loc_826CB71C:
	// fsel f1,f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64 >= 0.0 ? ctx.f0.f64 : ctx.f29.f64;
	// bl 0x827389a8
	ctx.lr = 0x826CB724;
	sub_827389A8(ctx, base);
	// lwz r11,15364(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15364);
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
	// bge cr6,0x826cb744
	if (!ctx.cr6.lt) goto loc_826CB744;
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
loc_826CB744:
	// bl 0x827389e8
	ctx.lr = 0x826CB748;
	sub_827389E8(ctx, base);
	// lwz r11,15364(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15364);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.f0.u64);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// lwz r31,212(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 212);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f13
	ctx.f0.f64 = double(ctx.f13.s64);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x826cb774
	if (ctx.cr6.lt) goto loc_826CB774;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
loc_826CB774:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x827389e8
	ctx.lr = 0x826CB77C;
	sub_827389E8(ctx, base);
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// fsel f1,f1,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : ctx.f29.f64;
	// addi r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 1;
	// rlwinm r31,r11,0,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// rlwinm r15,r10,0,0,30
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// rlwinm r30,r30,0,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r31,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// rlwinm r27,r28,0,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r15,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r15.u32);
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// stw r27,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r27.u32);
	// bl 0x827389a8
	ctx.lr = 0x826CB7AC;
	sub_827389A8(ctx, base);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r22,r9,0,0,30
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r22,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r22.u32);
	// cmpwi cr6,r22,2
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 2, ctx.xer);
	// bge cr6,0x826cb7d0
	if (!ctx.cr6.lt) goto loc_826CB7D0;
	// li r22,2
	ctx.r22.s64 = 2;
	// stw r22,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r22.u32);
loc_826CB7D0:
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lwz r28,15384(r16)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r16.u32 + 15384);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r5,15388(r16)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r16.u32 + 15388);
	// srawi r8,r31,1
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r31.s32 >> 1;
	// lwz r6,15392(r16)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r16.u32 + 15392);
	// srawi r7,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r30.s32 >> 1;
	// stw r8,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfd f13,13088(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r11.u32 + 13088);
	// srawi r11,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r27.s32 >> 1;
	// fmul f11,f25,f13
	ctx.f11.f64 = ctx.f25.f64 * ctx.f13.f64;
	// lfd f0,13080(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 13080);
	// fmul f10,f26,f0
	ctx.f10.f64 = ctx.f26.f64 * ctx.f0.f64;
	// stw r11,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r11.u32);
	// fmul f9,f24,f0
	ctx.f9.f64 = ctx.f24.f64 * ctx.f0.f64;
	// stw r7,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r7.u32);
	// fmul f8,f27,f13
	ctx.f8.f64 = ctx.f27.f64 * ctx.f13.f64;
	// lfd f12,24264(r9)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r9.u32 + 24264);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// stw r5,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// stw r6,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// fctiwz f7,f11
	ctx.f7.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f7,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r24,84(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f6,f10
	ctx.f6.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x80000000U) : (ctx.f10.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// fctiwz f5,f9
	ctx.f5.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x80000000U) : (ctx.f9.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// stfd f5,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.f5.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r8,164(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// fctiwz f4,f8
	ctx.f4.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x80000000U) : (ctx.f8.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mullw r7,r11,r15
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r15.s32);
	// fmul f3,f11,f12
	ctx.f3.f64 = ctx.f11.f64 * ctx.f12.f64;
	// mullw r11,r24,r31
	ctx.r11.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r31.s32);
	// fctiwz f2,f3
	ctx.f2.s64 = std::isnan(ctx.f3.f64) ? int64_t(0x80000000U) : (ctx.f3.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.f2.u64);
	// lwz r20,164(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// subf r7,r10,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r10.u64;
	// subf r8,r8,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r8.u64;
	// rlwinm r11,r7,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// rlwinm r10,r8,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r19,r11,r7
	ctx.r19.u64 = ctx.r11.u64 & ctx.r7.u64;
	// and r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
	// stw r19,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r19.u32);
	// stw r10,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// ble cr6,0x826cb94c
	if (!ctx.cr6.gt) goto loc_826CB94C;
loc_826CB8AC:
	// lwz r10,15360(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826cb8d4
	if (!ctx.cr6.gt) goto loc_826CB8D4;
	// addi r10,r28,-1
	ctx.r10.s64 = ctx.r28.s64 + -1;
loc_826CB8C0:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stbu r4,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r4.u8);
	ctx.r10.u32 = ea;
	// lwz r8,15360(r16)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x826cb8c0
	if (ctx.cr6.lt) goto loc_826CB8C0;
loc_826CB8D4:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x826cb8f8
	if (!ctx.cr6.gt) goto loc_826CB8F8;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// mtctr r26
	ctx.ctr.u64 = ctx.r26.u64;
	// subf r10,r6,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r6.u64;
loc_826CB8E8:
	// stbx r3,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r3.u8);
	// stb r3,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r3.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x826cb8e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CB8E8;
loc_826CB8F8:
	// lwz r11,15360(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// add r5,r5,r26
	ctx.r5.u64 = ctx.r5.u64 + ctx.r26.u64;
	// add r6,r6,r26
	ctx.r6.u64 = ctx.r6.u64 + ctx.r26.u64;
	// add r8,r28,r11
	ctx.r8.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826cb930
	if (!ctx.cr6.gt) goto loc_826CB930;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
loc_826CB91C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbu r4,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r4.u8);
	ctx.r9.u32 = ea;
	// lwz r11,15360(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826cb91c
	if (ctx.cr6.lt) goto loc_826CB91C;
loc_826CB930:
	// addi r9,r7,1
	ctx.r9.s64 = ctx.r7.s64 + 1;
	// add r28,r8,r11
	ctx.r28.u64 = ctx.r8.u64 + ctx.r11.u64;
	// cmpw cr6,r9,r15
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r15.s32, ctx.xer);
	// blt cr6,0x826cb8ac
	if (ctx.cr6.lt) goto loc_826CB8AC;
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// stw r6,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// stw r5,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
loc_826CB94C:
	// lwz r10,20(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 20);
	// srawi r8,r19,11
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FF) != 0);
	ctx.r8.s64 = ctx.r19.s32 >> 11;
	// lwz r9,15372(r16)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r16.u32 + 15372);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mullw r8,r8,r10
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// ble cr6,0x826cb984
	if (!ctx.cr6.gt) goto loc_826CB984;
	// mtctr r23
	ctx.ctr.u64 = ctx.r23.u64;
loc_826CB974:
	// dcbt r11,r9
	// dcbt r11,r10
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x826cb974
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CB974;
loc_826CB984:
	// srawi r11,r19,12
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0xFFF) != 0);
	ctx.r11.s64 = ctx.r19.s32 >> 12;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// ble cr6,0x826cb9a8
	if (!ctx.cr6.gt) goto loc_826CB9A8;
	// mtctr r21
	ctx.ctr.u64 = ctx.r21.u64;
loc_826CB998:
	// dcbt r11,r18
	// dcbt r11,r17
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x826cb998
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CB998;
loc_826CB9A8:
	// addi r5,r22,-2
	ctx.r5.s64 = ctx.r22.s64 + -2;
	// stw r15,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r15.u32);
	// cmpw cr6,r15,r5
	ctx.cr6.compare<int32_t>(ctx.r15.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x826cc4ec
	if (!ctx.cr6.lt) goto loc_826CC4EC;
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// li r14,16
	ctx.r14.s64 = 16;
	// lwz r10,148(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32113
	ctx.r11.s64 = -2104557568;
	// stw r7,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r7.u32);
	// subf r6,r9,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r9.u64;
	// addi r9,r11,-12752
	ctx.r9.s64 = ctx.r11.s64 + -12752;
	// stw r6,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r6.u32);
	// lfs f0,24248(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24248);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
loc_826CB9F0:
	// clrlwi r26,r19,21
	ctx.r26.u64 = ctx.r19.u32 & 0x7FF;
	// lwz r11,20(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 20);
	// srawi r9,r19,11
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FF) != 0);
	ctx.r9.s64 = ctx.r19.s32 >> 11;
	// lwz r10,15372(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 15372);
	// extsw r8,r26
	ctx.r8.s64 = ctx.r26.s32;
	// lwz r31,124(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// std r8,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r8.u64);
	// lfd f13,216(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 216);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// add r30,r9,r10
	ctx.r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,196(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// fmuls f13,f11,f0
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// ble cr6,0x826cba44
	if (!ctx.cr6.gt) goto loc_826CBA44;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826CBA38:
	// dcbt r11,r30
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x826cba38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CBA38;
loc_826CBA44:
	// lwz r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826cba70
	if (!ctx.cr6.gt) goto loc_826CBA70;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x826cba6c
	if (ctx.cr6.eq) goto loc_826CBA6C;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CBA64:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x826cba64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CBA64;
loc_826CBA6C:
	// add r3,r28,r9
	ctx.r3.u64 = ctx.r28.u64 + ctx.r9.u64;
loc_826CBA70:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
	// mtctr r14
	ctx.ctr.u64 = ctx.r14.u64;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
loc_826CBA80:
	// stwu r26,16(r11)
	ea = 16 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r26.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826cba80
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CBA80;
	// lwz r10,168(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// subfic r27,r26,2048
	ctx.xer.ca = ctx.r26.u32 <= 2048;
	ctx.r27.u64 = static_cast<uint64_t>(2048) - ctx.r26.u64;
	// stfs f13,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// srawi. r11,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r22,r9,r10
	ctx.r22.u64 = ctx.r10.u64 - ctx.r9.u64;
	// ble 0x826cbc34
	if (!ctx.cr0.gt) goto loc_826CBC34;
	// mr r23,r11
	ctx.r23.u64 = ctx.r11.u64;
	// lwz r21,88(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r28,r25,1
	ctx.r28.s64 = ctx.r25.s64 + 1;
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826CBAB8:
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r11,r21,256
	ctx.r11.s64 = ctx.r21.s64 + 256;
	// addi r10,r21,-4
	ctx.r10.s64 = ctx.r21.s64 + -4;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CBACC:
	// srawi r9,r31,11
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FF) != 0);
	ctx.r9.s64 = ctx.r31.s32 >> 11;
	// add r8,r31,r24
	ctx.r8.u64 = ctx.r31.u64 + ctx.r24.u64;
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
	// srawi r6,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 11;
	// clrlwi r4,r31,21
	ctx.r4.u64 = ctx.r31.u32 & 0x7FF;
	// clrlwi r21,r8,21
	ctx.r21.u64 = ctx.r8.u32 & 0x7FF;
	// subf r31,r4,r27
	ctx.r31.u64 = ctx.r27.u64 - ctx.r4.u64;
	// lbzx r19,r9,r25
	ctx.r19.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r25.u32);
	// add r8,r8,r24
	ctx.r8.u64 = ctx.r8.u64 + ctx.r24.u64;
	// lbzx r18,r28,r9
	ctx.r18.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r9.u32);
	// subf r17,r21,r27
	ctx.r17.u64 = ctx.r27.u64 - ctx.r21.u64;
	// lbz r15,1(r9)
	ctx.r15.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// srawi r5,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 11;
	// lbz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// subf r18,r19,r18
	ctx.r18.u64 = ctx.r18.u64 - ctx.r19.u64;
	// add r9,r6,r30
	ctx.r9.u64 = ctx.r6.u64 + ctx.r30.u64;
	// stw r4,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// subf r6,r15,r18
	ctx.r6.u64 = ctx.r18.u64 - ctx.r15.u64;
	// stw r4,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r4.u32);
	// stw r19,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r19.u32);
	// clrlwi r19,r8,21
	ctx.r19.u64 = ctx.r8.u32 & 0x7FF;
	// add r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 + ctx.r7.u64;
	// stw r15,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r15.u32);
	// stw r7,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// add r8,r8,r24
	ctx.r8.u64 = ctx.r8.u64 + ctx.r24.u64;
	// stw r6,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r6.u32);
	// subf r18,r19,r27
	ctx.r18.u64 = ctx.r27.u64 - ctx.r19.u64;
	// stw r31,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r31.u32);
	// clrlwi r14,r8,21
	ctx.r14.u64 = ctx.r8.u32 & 0x7FF;
	// lbzx r15,r9,r25
	ctx.r15.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r25.u32);
	// srawi r4,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 11;
	// lbzx r7,r28,r9
	ctx.r7.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r9.u32);
	// subf r6,r15,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r15.u64;
	// lbz r7,1(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// subf r6,r7,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r7.u64;
	// stw r7,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r7.u32);
	// add r31,r8,r24
	ctx.r31.u64 = ctx.r8.u64 + ctx.r24.u64;
	// lbz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// add r9,r5,r30
	ctx.r9.u64 = ctx.r5.u64 + ctx.r30.u64;
	// add r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 + ctx.r7.u64;
	// stw r15,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r15.u32);
	// lwz r15,140(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// stw r7,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// stw r21,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r21.u32);
	// stw r21,32(r10)
	REX_STORE_U32(ctx.r10.u32 + 32, ctx.r21.u32);
	// subf r21,r14,r27
	ctx.r21.u64 = ctx.r27.u64 - ctx.r14.u64;
	// stw r15,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r15.u32);
	// stw r6,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// stw r17,20(r10)
	REX_STORE_U32(ctx.r10.u32 + 20, ctx.r17.u32);
	// lbz r17,1(r9)
	ctx.r17.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r6,r9,r25
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r25.u32);
	// lbzx r8,r28,r9
	ctx.r8.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r9.u32);
	// subf r7,r6,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r6.u64;
	// subf r7,r17,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r17.u64;
	// lbzx r8,r5,r30
	ctx.r8.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r30.u32);
	// add r9,r4,r30
	ctx.r9.u64 = ctx.r4.u64 + ctx.r30.u64;
	// stw r8,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r8.u32);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r19,40(r10)
	REX_STORE_U32(ctx.r10.u32 + 40, ctx.r19.u32);
	// stw r19,48(r10)
	REX_STORE_U32(ctx.r10.u32 + 48, ctx.r19.u32);
	// stw r6,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r6.u32);
	// stw r17,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r17.u32);
	// stw r7,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r7.u32);
	// stw r18,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r18.u32);
	// lbzx r6,r9,r25
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r25.u32);
	// lbzx r5,r28,r9
	ctx.r5.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r9.u32);
	// subf r8,r6,r5
	ctx.r8.u64 = ctx.r5.u64 - ctx.r6.u64;
	// lbz r7,1(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// subf r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	// lbzx r9,r4,r30
	ctx.r9.u64 = REX_LOAD_U8(ctx.r4.u32 + ctx.r30.u32);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r21,52(r10)
	REX_STORE_U32(ctx.r10.u32 + 52, ctx.r21.u32);
	// stw r6,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r6.u32);
	// stw r14,56(r10)
	REX_STORE_U32(ctx.r10.u32 + 56, ctx.r14.u32);
	// stw r7,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r7.u32);
	// stw r9,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r9.u32);
	// stwu r8,64(r11)
	ea = 64 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// stwu r14,64(r10)
	ea = 64 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r14.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x826cbacc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CBACC;
	// lwz r21,88(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// addi r4,r21,256
	ctx.r4.s64 = ctx.r21.s64 + 256;
	// bl 0x826ca818
	ctx.lr = 0x826CBC18;
	sub_826CA818(ctx, base);
	// addic. r23,r23,-1
	ctx.xer.ca = ctx.r23.u32 > 0;
	ctx.r23.s64 = ctx.r23.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bne 0x826cbab8
	if (!ctx.cr0.eq) goto loc_826CBAB8;
	// lwz r15,120(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// li r14,16
	ctx.r14.s64 = 16;
	// lwz r19,144(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r28,100(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_826CBC34:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// ble cr6,0x826cbcac
	if (!ctx.cr6.gt) goto loc_826CBCAC;
	// addi r7,r25,1
	ctx.r7.s64 = ctx.r25.s64 + 1;
	// mtctr r22
	ctx.ctr.u64 = ctx.r22.u64;
loc_826CBC44:
	// srawi r11,r31,11
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FF) != 0);
	ctx.r11.s64 = ctx.r31.s32 >> 11;
	// clrlwi r6,r31,21
	ctx.r6.u64 = ctx.r31.u32 & 0x7FF;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r31,r31,r24
	ctx.r31.u64 = ctx.r31.u64 + ctx.r24.u64;
	// lbzx r5,r11,r25
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r25.u32);
	// lbzx r4,r7,r11
	ctx.r4.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r11.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// mullw r8,r5,r26
	ctx.r8.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r26.s32);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// subf r5,r5,r4
	ctx.r5.u64 = ctx.r4.u64 - ctx.r5.u64;
	// mullw r9,r10,r6
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r6.s32);
	// subf r10,r10,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r10.u64;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mullw r10,r4,r6
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// mullw r5,r10,r26
	ctx.r5.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r26.s32);
	// srawi r10,r5,11
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 11;
	// subfic r4,r6,2048
	ctx.xer.ca = ctx.r6.u32 <= 2048;
	ctx.r4.u64 = static_cast<uint64_t>(2048) - ctx.r6.u64;
	// subf r6,r26,r4
	ctx.r6.u64 = ctx.r4.u64 - ctx.r26.u64;
	// mullw r11,r6,r11
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// srawi r4,r5,11
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FF) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 11;
	// stb r4,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r4.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bdnz 0x826cbc44
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CBC44;
loc_826CBCAC:
	// lwz r10,116(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x826cbcdc
	if (!ctx.cr6.lt) goto loc_826CBCDC;
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826CBCC4:
	// srawi r10,r31,11
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FF) != 0);
	ctx.r10.s64 = ctx.r31.s32 >> 11;
	// add r31,r31,r24
	ctx.r31.u64 = ctx.r31.u64 + ctx.r24.u64;
	// lbzx r9,r10,r30
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r30.u32);
	// stb r9,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r9.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bdnz 0x826cbcc4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CBCC4;
loc_826CBCDC:
	// lwz r10,15360(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x826cbd00
	if (!ctx.cr6.lt) goto loc_826CBD00;
	// addi r10,r3,-1
	ctx.r10.s64 = ctx.r3.s64 + -1;
loc_826CBCEC:
	// stbu r14,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r14.u8);
	ctx.r10.u32 = ea;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r9,15360(r16)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x826cbcec
	if (ctx.cr6.lt) goto loc_826CBCEC;
loc_826CBD00:
	// srawi r11,r19,12
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0xFFF) != 0);
	ctx.r11.s64 = ctx.r19.s32 >> 12;
	// lwz r10,192(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// srawi r9,r19,1
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r19.s32 >> 1;
	// lwz r30,124(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// mullw r17,r11,r29
	ctx.r17.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// lwz r22,92(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r21,96(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// clrlwi r23,r9,21
	ctx.r23.u64 = ctx.r9.u32 & 0x7FF;
	// add r11,r17,r29
	ctx.r11.u64 = ctx.r17.u64 + ctx.r29.u64;
	// extsw r8,r23
	ctx.r8.s64 = ctx.r23.s32;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// std r8,232(r1)
	REX_STORE_U64(ctx.r1.u32 + 232, ctx.r8.u64);
	// lfd f13,232(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 232);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f13,f11,f0
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// ble cr6,0x826cbd60
	if (!ctx.cr6.gt) goto loc_826CBD60;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r9,104(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
loc_826CBD50:
	// dcbt r11,r10
	// dcbt r11,r9
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x826cbd50
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CBD50;
loc_826CBD60:
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826cbd88
	if (!ctx.cr6.gt) goto loc_826CBD88;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r11,128
	ctx.r11.s64 = 128;
loc_826CBD74:
	// stb r11,0(r22)
	REX_STORE_U8(ctx.r22.u32 + 0, ctx.r11.u8);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// stb r11,0(r21)
	REX_STORE_U8(ctx.r21.u32 + 0, ctx.r11.u8);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// bdnz 0x826cbd74
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CBD74;
loc_826CBD88:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
	// mtctr r14
	ctx.ctr.u64 = ctx.r14.u64;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
loc_826CBD98:
	// stwu r23,16(r11)
	ea = 16 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r23.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826cbd98
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CBD98;
	// lwz r10,160(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// subfic r26,r23,2048
	ctx.xer.ca = ctx.r23.u32 <= 2048;
	ctx.r26.u64 = static_cast<uint64_t>(2048) - ctx.r23.u64;
	// stfs f13,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// srawi. r11,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r18,r9,r10
	ctx.r18.u64 = ctx.r10.u64 - ctx.r9.u64;
	// ble 0x826cc02c
	if (!ctx.cr0.gt) goto loc_826CC02C;
	// mr r19,r11
	ctx.r19.u64 = ctx.r11.u64;
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lwz r9,104(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r14,88(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 1;
	// add r28,r17,r10
	ctx.r28.u64 = ctx.r17.u64 + ctx.r10.u64;
	// add r27,r17,r9
	ctx.r27.u64 = ctx.r17.u64 + ctx.r9.u64;
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826CBDE0:
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r11,r14,256
	ctx.r11.s64 = ctx.r14.s64 + 256;
	// addi r10,r14,-4
	ctx.r10.s64 = ctx.r14.s64 + -4;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CBDF4:
	// srawi r7,r30,12
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xFFF) != 0);
	ctx.r7.s64 = ctx.r30.s32 >> 12;
	// srawi r8,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r30.s32 >> 1;
	// add r9,r28,r7
	ctx.r9.u64 = ctx.r28.u64 + ctx.r7.u64;
	// clrlwi r4,r8,21
	ctx.r4.u64 = ctx.r8.u32 & 0x7FF;
	// add r8,r30,r20
	ctx.r8.u64 = ctx.r30.u64 + ctx.r20.u64;
	// lbzx r6,r28,r7
	ctx.r6.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r7.u32);
	// subf r3,r4,r26
	ctx.r3.u64 = ctx.r26.u64 - ctx.r4.u64;
	// lbzx r30,r9,r29
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r29.u32);
	// lbz r14,1(r9)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r5,r31,r9
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r9.u32);
	// add r9,r27,r7
	ctx.r9.u64 = ctx.r27.u64 + ctx.r7.u64;
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// srawi r7,r8,12
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 12;
	// stw r4,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// subf r5,r30,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r30.u64;
	// stw r30,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r30.u32);
	// subf r5,r14,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r14.u64;
	// stw r4,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r4.u32);
	// stw r3,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// srawi r4,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 1;
	// add r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stw r14,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r14.u32);
	// clrlwi r3,r4,21
	ctx.r3.u64 = ctx.r4.u32 & 0x7FF;
	// stw r5,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r5.u32);
	// add r8,r8,r20
	ctx.r8.u64 = ctx.r8.u64 + ctx.r20.u64;
	// lbzx r4,r9,r29
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r29.u32);
	// subf r30,r3,r26
	ctx.r30.u64 = ctx.r26.u64 - ctx.r3.u64;
	// lbz r14,1(r9)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r6,r31,r9
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r9.u32);
	// subf r5,r4,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r4.u64;
	// subf r5,r14,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r14.u64;
	// lbz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// stw r4,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r4.u32);
	// add r9,r28,r7
	ctx.r9.u64 = ctx.r28.u64 + ctx.r7.u64;
	// add r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stw r14,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r14.u32);
	// stw r6,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// stw r5,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r5.u32);
	// lbzx r4,r9,r29
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r29.u32);
	// lbzx r6,r31,r9
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r9.u32);
	// subf r5,r4,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r4.u64;
	// lbz r14,1(r9)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// subf r5,r14,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r14.u64;
	// lbzx r6,r28,r7
	ctx.r6.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r7.u32);
	// add r9,r27,r7
	ctx.r9.u64 = ctx.r27.u64 + ctx.r7.u64;
	// stw r6,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stw r6,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r6.u32);
	// srawi r7,r8,12
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 12;
	// stw r3,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r3.u32);
	// srawi r6,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 1;
	// stw r3,32(r10)
	REX_STORE_U32(ctx.r10.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r4.u32);
	// clrlwi r3,r6,21
	ctx.r3.u64 = ctx.r6.u32 & 0x7FF;
	// stw r14,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r14.u32);
	// stw r30,20(r10)
	REX_STORE_U32(ctx.r10.u32 + 20, ctx.r30.u32);
	// subf r4,r3,r26
	ctx.r4.u64 = ctx.r26.u64 - ctx.r3.u64;
	// lbzx r30,r9,r29
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r29.u32);
	// lbz r14,1(r9)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lbzx r9,r31,r9
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r9.u32);
	// subf r5,r30,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r30.u64;
	// subf r5,r14,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r14.u64;
	// stw r6,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r6.u32);
	// add r9,r28,r7
	ctx.r9.u64 = ctx.r28.u64 + ctx.r7.u64;
	// stw r14,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r14.u32);
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stw r30,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r30.u32);
	// stw r6,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r6.u32);
	// lbzx r5,r9,r29
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r29.u32);
	// lbzx r6,r31,r9
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r9.u32);
	// subf r6,r5,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r5.u64;
	// lbz r30,1(r9)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// subf r6,r30,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r30.u64;
	// lbzx r9,r28,r7
	ctx.r9.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r7.u32);
	// add r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 + ctx.r9.u64;
	// stw r4,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r4.u32);
	// stw r5,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r5.u32);
	// stw r30,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r30.u32);
	// stw r9,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r9.u32);
	// stw r6,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r6.u32);
	// add r9,r27,r7
	ctx.r9.u64 = ctx.r27.u64 + ctx.r7.u64;
	// stw r3,40(r10)
	REX_STORE_U32(ctx.r10.u32 + 40, ctx.r3.u32);
	// stw r3,48(r10)
	REX_STORE_U32(ctx.r10.u32 + 48, ctx.r3.u32);
	// add r8,r8,r20
	ctx.r8.u64 = ctx.r8.u64 + ctx.r20.u64;
	// srawi r7,r8,12
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 12;
	// srawi r5,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 1;
	// lbz r14,1(r9)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// add r30,r8,r20
	ctx.r30.u64 = ctx.r8.u64 + ctx.r20.u64;
	// clrlwi r4,r5,21
	ctx.r4.u64 = ctx.r5.u32 & 0x7FF;
	// lbzx r5,r9,r29
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r29.u32);
	// subf r3,r4,r26
	ctx.r3.u64 = ctx.r26.u64 - ctx.r4.u64;
	// lbzx r8,r31,r9
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r9.u32);
	// subf r6,r5,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r5.u64;
	// subf r6,r14,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r14.u64;
	// lbz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// stw r8,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r8.u32);
	// add r9,r28,r7
	ctx.r9.u64 = ctx.r28.u64 + ctx.r7.u64;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// stw r5,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r5.u32);
	// stw r14,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r14.u32);
	// stw r6,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r6.u32);
	// lbz r5,1(r9)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r6,r9,r29
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r29.u32);
	// lbzx r14,r31,r9
	ctx.r14.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r9.u32);
	// add r9,r27,r7
	ctx.r9.u64 = ctx.r27.u64 + ctx.r7.u64;
	// lbzx r8,r28,r7
	ctx.r8.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r7.u32);
	// subf r7,r6,r14
	ctx.r7.u64 = ctx.r14.u64 - ctx.r6.u64;
	// stw r8,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r8.u32);
	// subf r7,r5,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r5.u64;
	// stw r3,52(r10)
	REX_STORE_U32(ctx.r10.u32 + 52, ctx.r3.u32);
	// stw r4,56(r10)
	REX_STORE_U32(ctx.r10.u32 + 56, ctx.r4.u32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r6,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r6.u32);
	// stw r5,104(r11)
	REX_STORE_U32(ctx.r11.u32 + 104, ctx.r5.u32);
	// stw r8,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r8.u32);
	// stwu r4,64(r10)
	ea = 64 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r4.u32);
	ctx.r10.u32 = ea;
	// lbzx r5,r9,r29
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r29.u32);
	// lbz r6,1(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lbzx r4,r31,r9
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r9.u32);
	// stw r6,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r6.u32);
	// subf r3,r5,r4
	ctx.r3.u64 = ctx.r4.u64 - ctx.r5.u64;
	// stw r8,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r8.u32);
	// stw r5,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r5.u32);
	// subf r9,r6,r3
	ctx.r9.u64 = ctx.r3.u64 - ctx.r6.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stwu r9,128(r11)
	ea = 128 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826cbdf4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CBDF4;
	// lwz r14,88(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// mr r6,r14
	ctx.r6.u64 = ctx.r14.u64;
	// addi r5,r14,256
	ctx.r5.s64 = ctx.r14.s64 + 256;
	// bl 0x826cad18
	ctx.lr = 0x826CC010;
	sub_826CAD18(ctx, base);
	// addic. r19,r19,-1
	ctx.xer.ca = ctx.r19.u32 > 0;
	ctx.r19.s64 = ctx.r19.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// addi r22,r22,16
	ctx.r22.s64 = ctx.r22.s64 + 16;
	// addi r21,r21,16
	ctx.r21.s64 = ctx.r21.s64 + 16;
	// bne 0x826cbde0
	if (!ctx.cr0.eq) goto loc_826CBDE0;
	// lwz r28,100(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r14,16
	ctx.r14.s64 = 16;
	// lwz r19,144(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
loc_826CC02C:
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// ble cr6,0x826cc108
	if (!ctx.cr6.gt) goto loc_826CC108;
	// lwz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// mtctr r18
	ctx.ctr.u64 = ctx.r18.u64;
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// addi r9,r29,1
	ctx.r9.s64 = ctx.r29.s64 + 1;
	// add r4,r17,r11
	ctx.r4.u64 = ctx.r17.u64 + ctx.r11.u64;
	// add r3,r17,r10
	ctx.r3.u64 = ctx.r17.u64 + ctx.r10.u64;
loc_826CC04C:
	// srawi r10,r30,12
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xFFF) != 0);
	ctx.r10.s64 = ctx.r30.s32 >> 12;
	// srawi r8,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r30.s32 >> 1;
	// add r11,r4,r10
	ctx.r11.u64 = ctx.r4.u64 + ctx.r10.u64;
	// clrlwi r31,r8,21
	ctx.r31.u64 = ctx.r8.u32 & 0x7FF;
	// add r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 + ctx.r20.u64;
	// subfic r7,r31,2048
	ctx.xer.ca = ctx.r31.u32 <= 2048;
	ctx.r7.u64 = static_cast<uint64_t>(2048) - ctx.r31.u64;
	// lbzx r5,r11,r29
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// subf r27,r23,r7
	ctx.r27.u64 = ctx.r7.u64 - ctx.r23.u64;
	// lbzx r8,r9,r11
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// lbz r7,1(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// mullw r6,r5,r23
	ctx.r6.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r23.s32);
	// lbzx r11,r4,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// subf r8,r5,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r5.u64;
	// mullw r5,r27,r11
	ctx.r5.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r11.s32);
	// subf r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	// mullw r7,r7,r31
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r31.s32);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r11,r3,r10
	ctx.r11.u64 = ctx.r3.u64 + ctx.r10.u64;
	// mullw r10,r8,r31
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r31.s32);
	// mullw r8,r10,r23
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r23.s32);
	// srawi r10,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 11;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r7,r10,r5
	ctx.r7.u64 = ctx.r10.u64 + ctx.r5.u64;
	// srawi r6,r7,11
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FF) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 11;
	// stb r6,0(r22)
	REX_STORE_U8(ctx.r22.u32 + 0, ctx.r6.u8);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// lbzx r10,r11,r29
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// lbzx r8,r9,r11
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// mullw r7,r10,r23
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r23.s32);
	// lbz r5,1(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// subf r10,r10,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r10.u64;
	// mullw r8,r5,r31
	ctx.r8.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r31.s32);
	// subf r10,r5,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r5.u64;
	// mullw r6,r27,r11
	ctx.r6.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r11.s32);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mullw r11,r5,r31
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r31.s32);
	// mullw r10,r11,r23
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r23.s32);
	// srawi r11,r10,11
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FF) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 11;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r8,r11,r6
	ctx.r8.u64 = ctx.r11.u64 + ctx.r6.u64;
	// srawi r7,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 11;
	// stb r7,0(r21)
	REX_STORE_U8(ctx.r21.u32 + 0, ctx.r7.u8);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// bdnz 0x826cc04c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC04C;
loc_826CC108:
	// lwz r11,148(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r8,200(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x826cc154
	if (!ctx.cr6.lt) goto loc_826CC154;
	// subf r11,r11,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r11.u64;
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r9,104(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// add r10,r17,r10
	ctx.r10.u64 = ctx.r17.u64 + ctx.r10.u64;
	// add r9,r17,r9
	ctx.r9.u64 = ctx.r17.u64 + ctx.r9.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826CC130:
	// srawi r11,r30,12
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xFFF) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 12;
	// add r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 + ctx.r20.u64;
	// lbzx r7,r10,r11
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// stb r7,0(r22)
	REX_STORE_U8(ctx.r22.u32 + 0, ctx.r7.u8);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// lbzx r6,r9,r11
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// stb r6,0(r21)
	REX_STORE_U8(ctx.r21.u32 + 0, ctx.r6.u8);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// bdnz 0x826cc130
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC130;
loc_826CC154:
	// lwz r7,132(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x826cc180
	if (!ctx.cr6.lt) goto loc_826CC180;
	// subf r9,r8,r7
	ctx.r9.u64 = ctx.r7.u64 - ctx.r8.u64;
	// addi r10,r21,-1
	ctx.r10.s64 = ctx.r21.s64 + -1;
	// addi r11,r22,-1
	ctx.r11.s64 = ctx.r22.s64 + -1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// li r9,128
	ctx.r9.s64 = 128;
loc_826CC174:
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x826cc174
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC174;
loc_826CC180:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r5,r15,1
	ctx.r5.s64 = ctx.r15.s64 + 1;
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// add r11,r19,r11
	ctx.r11.u64 = ctx.r19.u64 + ctx.r11.u64;
	// lwz r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// add r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 + ctx.r7.u64;
	// lwz r10,15360(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// lwz r8,15372(r16)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r16.u32 + 15372);
	// add r7,r3,r7
	ctx.r7.u64 = ctx.r3.u64 + ctx.r7.u64;
	// stw r4,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// addi r31,r9,-1
	ctx.r31.s64 = ctx.r9.s64 + -1;
	// lwz r9,112(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stw r7,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// add r6,r28,r10
	ctx.r6.u64 = ctx.r28.u64 + ctx.r10.u64;
	// and r21,r31,r11
	ctx.r21.u64 = ctx.r31.u64 & ctx.r11.u64;
	// lwz r10,20(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 20);
	// lwz r31,124(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// clrlwi r26,r21,21
	ctx.r26.u64 = ctx.r21.u32 & 0x7FF;
	// stw r6,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// srawi r4,r21,11
	ctx.xer.ca = (ctx.r21.s32 < 0) & ((ctx.r21.u32 & 0x7FF) != 0);
	ctx.r4.s64 = ctx.r21.s32 >> 11;
	// stw r5,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r5.u32);
	// extsw r7,r26
	ctx.r7.s64 = ctx.r26.s32;
	// mullw r11,r4,r10
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// std r7,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r7.u64);
	// lfd f13,224(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 224);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// add r30,r11,r8
	ctx.r30.u64 = ctx.r11.u64 + ctx.r8.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// fmuls f13,f11,f0
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// ble cr6,0x826cc224
	if (!ctx.cr6.gt) goto loc_826CC224;
	// addi r11,r6,-1
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x826cc220
	if (ctx.cr6.eq) goto loc_826CC220;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CC218:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x826cc218
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC218;
loc_826CC220:
	// add r3,r6,r9
	ctx.r3.u64 = ctx.r6.u64 + ctx.r9.u64;
loc_826CC224:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
	// mtctr r14
	ctx.ctr.u64 = ctx.r14.u64;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
loc_826CC234:
	// stwu r26,16(r11)
	ea = 16 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r26.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x826cc234
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC234;
	// lwz r10,168(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// subfic r27,r26,2048
	ctx.xer.ca = ctx.r26.u32 <= 2048;
	ctx.r27.u64 = static_cast<uint64_t>(2048) - ctx.r26.u64;
	// stfs f13,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// srawi. r11,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r22,r9,r10
	ctx.r22.u64 = ctx.r10.u64 - ctx.r9.u64;
	// ble 0x826cc3e4
	if (!ctx.cr0.gt) goto loc_826CC3E4;
	// mr r23,r11
	ctx.r23.u64 = ctx.r11.u64;
	// lwz r19,88(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r28,r25,1
	ctx.r28.s64 = ctx.r25.s64 + 1;
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826CC26C:
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r11,r19,256
	ctx.r11.s64 = ctx.r19.s64 + 256;
	// addi r10,r19,-4
	ctx.r10.s64 = ctx.r19.s64 + -4;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CC280:
	// srawi r9,r31,11
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FF) != 0);
	ctx.r9.s64 = ctx.r31.s32 >> 11;
	// add r8,r31,r24
	ctx.r8.u64 = ctx.r31.u64 + ctx.r24.u64;
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
	// srawi r6,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 11;
	// clrlwi r5,r31,21
	ctx.r5.u64 = ctx.r31.u32 & 0x7FF;
	// clrlwi r4,r8,21
	ctx.r4.u64 = ctx.r8.u32 & 0x7FF;
	// subf r31,r5,r27
	ctx.r31.u64 = ctx.r27.u64 - ctx.r5.u64;
	// lbzx r19,r9,r25
	ctx.r19.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r25.u32);
	// add r8,r8,r24
	ctx.r8.u64 = ctx.r8.u64 + ctx.r24.u64;
	// lbzx r18,r28,r9
	ctx.r18.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r9.u32);
	// subf r17,r4,r27
	ctx.r17.u64 = ctx.r27.u64 - ctx.r4.u64;
	// lbz r16,1(r9)
	ctx.r16.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// clrlwi r15,r8,21
	ctx.r15.u64 = ctx.r8.u32 & 0x7FF;
	// lbz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// subf r18,r19,r18
	ctx.r18.u64 = ctx.r18.u64 - ctx.r19.u64;
	// add r9,r6,r30
	ctx.r9.u64 = ctx.r6.u64 + ctx.r30.u64;
	// stw r5,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
	// subf r6,r16,r18
	ctx.r6.u64 = ctx.r18.u64 - ctx.r16.u64;
	// stw r5,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r5.u32);
	// stw r19,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r19.u32);
	// srawi r5,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 11;
	// add r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 + ctx.r7.u64;
	// stw r16,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r16.u32);
	// stw r7,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// add r8,r8,r24
	ctx.r8.u64 = ctx.r8.u64 + ctx.r24.u64;
	// stw r6,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r6.u32);
	// subf r19,r15,r27
	ctx.r19.u64 = ctx.r27.u64 - ctx.r15.u64;
	// stw r31,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r31.u32);
	// clrlwi r18,r8,21
	ctx.r18.u64 = ctx.r8.u32 & 0x7FF;
	// srawi r6,r8,11
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 11;
	// add r31,r8,r24
	ctx.r31.u64 = ctx.r8.u64 + ctx.r24.u64;
	// subf r16,r18,r27
	ctx.r16.u64 = ctx.r27.u64 - ctx.r18.u64;
	// lbz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lbzx r7,r28,r9
	ctx.r7.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r9.u32);
	// lbzx r14,r9,r25
	ctx.r14.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r25.u32);
	// lbz r9,1(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// stw r9,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// subf r7,r14,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r14.u64;
	// stw r4,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r4.u32);
	// subf r7,r9,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r9.u64;
	// stw r4,32(r10)
	REX_STORE_U32(ctx.r10.u32 + 32, ctx.r4.u32);
	// add r9,r5,r30
	ctx.r9.u64 = ctx.r5.u64 + ctx.r30.u64;
	// lwz r4,140(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r8,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// stw r7,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r7.u32);
	// stw r14,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r14.u32);
	// stw r17,20(r10)
	REX_STORE_U32(ctx.r10.u32 + 20, ctx.r17.u32);
	// stw r4,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r4.u32);
	// lbz r17,1(r9)
	ctx.r17.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r4,r9,r25
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r25.u32);
	// lbzx r8,r28,r9
	ctx.r8.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r9.u32);
	// add r9,r6,r30
	ctx.r9.u64 = ctx.r6.u64 + ctx.r30.u64;
	// subf r7,r4,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r4.u64;
	// lbzx r8,r5,r30
	ctx.r8.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r30.u32);
	// subf r7,r17,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r17.u64;
	// stw r8,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r8.u32);
	// stw r15,40(r10)
	REX_STORE_U32(ctx.r10.u32 + 40, ctx.r15.u32);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r15,48(r10)
	REX_STORE_U32(ctx.r10.u32 + 48, ctx.r15.u32);
	// stw r4,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r4.u32);
	// stw r17,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r17.u32);
	// stw r7,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r7.u32);
	// stw r19,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r19.u32);
	// lbz r7,1(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbzx r5,r9,r25
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r25.u32);
	// lbzx r4,r28,r9
	ctx.r4.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r9.u32);
	// subf r8,r5,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r5.u64;
	// subf r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	// lbzx r9,r6,r30
	ctx.r9.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r30.u32);
	// stw r16,52(r10)
	REX_STORE_U32(ctx.r10.u32 + 52, ctx.r16.u32);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r5,60(r11)
	REX_STORE_U32(ctx.r11.u32 + 60, ctx.r5.u32);
	// stw r18,56(r10)
	REX_STORE_U32(ctx.r10.u32 + 56, ctx.r18.u32);
	// stw r7,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r7.u32);
	// stw r9,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r9.u32);
	// stwu r8,64(r11)
	ea = 64 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// stwu r18,64(r10)
	ea = 64 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r18.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x826cc280
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC280;
	// lwz r19,88(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// mr r5,r19
	ctx.r5.u64 = ctx.r19.u64;
	// addi r4,r19,256
	ctx.r4.s64 = ctx.r19.s64 + 256;
	// bl 0x826ca818
	ctx.lr = 0x826CC3CC;
	sub_826CA818(ctx, base);
	// addic. r23,r23,-1
	ctx.xer.ca = ctx.r23.u32 > 0;
	ctx.r23.s64 = ctx.r23.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bne 0x826cc26c
	if (!ctx.cr0.eq) goto loc_826CC26C;
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r14,16
	ctx.r14.s64 = 16;
	// lwz r16,484(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 484);
loc_826CC3E4:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// ble cr6,0x826cc45c
	if (!ctx.cr6.gt) goto loc_826CC45C;
	// addi r7,r25,1
	ctx.r7.s64 = ctx.r25.s64 + 1;
	// mtctr r22
	ctx.ctr.u64 = ctx.r22.u64;
loc_826CC3F4:
	// srawi r11,r31,11
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FF) != 0);
	ctx.r11.s64 = ctx.r31.s32 >> 11;
	// clrlwi r5,r31,21
	ctx.r5.u64 = ctx.r31.u32 & 0x7FF;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r31,r31,r24
	ctx.r31.u64 = ctx.r31.u64 + ctx.r24.u64;
	// lbzx r4,r11,r25
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r25.u32);
	// lbzx r10,r7,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r11.u32);
	// mullw r8,r4,r26
	ctx.r8.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r26.s32);
	// lbz r28,1(r11)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// subf r4,r4,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r4.u64;
	// mullw r9,r28,r5
	ctx.r9.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r5.s32);
	// subf r10,r28,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r28.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mullw r4,r10,r5
	ctx.r4.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// mullw r10,r4,r26
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r26.s32);
	// srawi r10,r10,11
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 11;
	// subfic r5,r5,2048
	ctx.xer.ca = ctx.r5.u32 <= 2048;
	ctx.r5.u64 = static_cast<uint64_t>(2048) - ctx.r5.u64;
	// subf r4,r26,r5
	ctx.r4.u64 = ctx.r5.u64 - ctx.r26.u64;
	// mullw r11,r4,r11
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r11.s32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// srawi r10,r11,11
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 11;
	// stb r10,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bdnz 0x826cc3f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC3F4;
loc_826CC45C:
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r10,152(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x826cc48c
	if (!ctx.cr6.lt) goto loc_826CC48C;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_826CC474:
	// srawi r11,r31,11
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FF) != 0);
	ctx.r11.s64 = ctx.r31.s32 >> 11;
	// add r31,r31,r24
	ctx.r31.u64 = ctx.r31.u64 + ctx.r24.u64;
	// lbzx r9,r11,r30
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// stb r9,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r9.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bdnz 0x826cc474
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC474;
loc_826CC48C:
	// lwz r11,15360(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x826cc4b0
	if (!ctx.cr6.lt) goto loc_826CC4B0;
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
loc_826CC49C:
	// stbu r14,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r14.u8);
	ctx.r9.u32 = ea;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r11,15360(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826cc49c
	if (ctx.cr6.lt) goto loc_826CC49C;
loc_826CC4B0:
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r28,r6,r11
	ctx.r28.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// add r10,r21,r10
	ctx.r10.u64 = ctx.r21.u64 + ctx.r10.u64;
	// lwz r8,136(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// addi r15,r11,1
	ctx.r15.s64 = ctx.r11.s64 + 1;
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// addi r5,r8,-2
	ctx.r5.s64 = ctx.r8.s64 + -2;
	// stw r15,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r15.u32);
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// cmpw cr6,r15,r5
	ctx.cr6.compare<int32_t>(ctx.r15.s32, ctx.r5.s32, ctx.xer);
	// and r19,r7,r10
	ctx.r19.u64 = ctx.r7.u64 & ctx.r10.u64;
	// stw r19,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r19.u32);
	// blt cr6,0x826cb9f0
	if (ctx.cr6.lt) goto loc_826CB9F0;
loc_826CC4EC:
	// lwz r11,15356(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15356);
	// srawi r8,r19,11
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FF) != 0);
	ctx.r8.s64 = ctx.r19.s32 >> 11;
	// lwz r26,124(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// blt cr6,0x826cc508
	if (ctx.cr6.lt) goto loc_826CC508;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
loc_826CC508:
	// lwz r11,208(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 208);
	// lwz r17,136(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// cmpw cr6,r17,r10
	ctx.cr6.compare<int32_t>(ctx.r17.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826cc764
	if (ctx.cr6.lt) goto loc_826CC764;
	// cmpw cr6,r5,r17
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r17.s32, ctx.xer);
	// bge cr6,0x826cc764
	if (!ctx.cr6.lt) goto loc_826CC764;
	// lwz r23,148(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// li r15,128
	ctx.r15.s64 = 128;
	// lwz r27,92(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// li r25,0
	ctx.r25.s64 = 0;
	// lwz r30,96(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r22,128(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r3,132(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// lwz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r31,116(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r21,108(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r18,104(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_826CC550:
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x826cc57c
	if (!ctx.cr6.gt) goto loc_826CC57C;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x826cc578
	if (ctx.cr6.eq) goto loc_826CC578;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
loc_826CC570:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x826cc570
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC570;
loc_826CC578:
	// add r10,r28,r4
	ctx.r10.u64 = ctx.r28.u64 + ctx.r4.u64;
loc_826CC57C:
	// lwz r9,20(r16)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r16.u32 + 20);
	// cmpw cr6,r4,r31
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r31.s32, ctx.xer);
	// lwz r11,15372(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15372);
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bge cr6,0x826cc5b4
	if (!ctx.cr6.lt) goto loc_826CC5B4;
	// subf r9,r4,r31
	ctx.r9.u64 = ctx.r31.u64 - ctx.r4.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CC59C:
	// srawi r9,r6,11
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FF) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 11;
	// add r6,r6,r24
	ctx.r6.u64 = ctx.r6.u64 + ctx.r24.u64;
	// lbzx r8,r9,r11
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// stb r8,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x826cc59c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC59C;
loc_826CC5B4:
	// lwz r9,15360(r16)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmpw cr6,r31,r9
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x826cc5dc
	if (!ctx.cr6.lt) goto loc_826CC5DC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_826CC5C8:
	// stbu r25,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r25.u8);
	ctx.r10.u32 = ea;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r9,15360(r16)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x826cc5c8
	if (ctx.cr6.lt) goto loc_826CC5C8;
loc_826CC5DC:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// ble cr6,0x826cc604
	if (!ctx.cr6.gt) goto loc_826CC604;
	// mtctr r22
	ctx.ctr.u64 = ctx.r22.u64;
loc_826CC5F0:
	// stb r15,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r15.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r15,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r15.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x826cc5f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC5F0;
loc_826CC604:
	// lwz r7,15356(r16)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r16.u32 + 15356);
	// srawi r9,r19,12
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0xFFF) != 0);
	ctx.r9.s64 = ctx.r19.s32 >> 12;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// srawi r7,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 1;
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x826cc620
	if (ctx.cr6.lt) goto loc_826CC620;
	// addi r9,r7,-1
	ctx.r9.s64 = ctx.r7.s64 + -1;
loc_826CC620:
	// mullw r9,r9,r29
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r29.s32);
	// cmpw cr6,r22,r23
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r23.s32, ctx.xer);
	// bge cr6,0x826cc660
	if (!ctx.cr6.lt) goto loc_826CC660;
	// subf r14,r22,r23
	ctx.r14.u64 = ctx.r23.u64 - ctx.r22.u64;
	// add r7,r9,r21
	ctx.r7.u64 = ctx.r9.u64 + ctx.r21.u64;
	// add r6,r9,r18
	ctx.r6.u64 = ctx.r9.u64 + ctx.r18.u64;
	// mtctr r14
	ctx.ctr.u64 = ctx.r14.u64;
loc_826CC63C:
	// srawi r9,r8,12
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 12;
	// add r8,r8,r20
	ctx.r8.u64 = ctx.r8.u64 + ctx.r20.u64;
	// lbzx r14,r7,r9
	ctx.r14.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// stb r14,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r14.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbzx r9,r6,r9
	ctx.r9.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r9.u32);
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x826cc63c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC63C;
loc_826CC660:
	// cmpw cr6,r23,r3
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x826cc684
	if (!ctx.cr6.lt) goto loc_826CC684;
	// subf r9,r23,r3
	ctx.r9.u64 = ctx.r3.u64 - ctx.r23.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826CC678:
	// stbu r15,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r15.u8);
	ctx.r11.u32 = ea;
	// stbu r15,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r15.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x826cc678
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC678;
loc_826CC684:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r27,r27,r3
	ctx.r27.u64 = ctx.r27.u64 + ctx.r3.u64;
	// lwz r9,15360(r16)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// add r30,r30,r3
	ctx.r30.u64 = ctx.r30.u64 + ctx.r3.u64;
	// add r11,r19,r11
	ctx.r11.u64 = ctx.r19.u64 + ctx.r11.u64;
	// lwz r10,15356(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 15356);
	// add r7,r28,r9
	ctx.r7.u64 = ctx.r28.u64 + ctx.r9.u64;
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// and r19,r8,r11
	ctx.r19.u64 = ctx.r8.u64 & ctx.r11.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// srawi r8,r19,11
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FF) != 0);
	ctx.r8.s64 = ctx.r19.s32 >> 11;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826cc6c8
	if (ctx.cr6.lt) goto loc_826CC6C8;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
loc_826CC6C8:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x826cc6f0
	if (!ctx.cr6.gt) goto loc_826CC6F0;
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x826cc6ec
	if (ctx.cr6.eq) goto loc_826CC6EC;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
loc_826CC6E4:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x826cc6e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC6E4;
loc_826CC6EC:
	// add r9,r7,r4
	ctx.r9.u64 = ctx.r7.u64 + ctx.r4.u64;
loc_826CC6F0:
	// lwz r10,20(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 20);
	// cmpw cr6,r4,r31
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r31.s32, ctx.xer);
	// lwz r11,15372(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15372);
	// mullw r10,r10,r8
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bge cr6,0x826cc728
	if (!ctx.cr6.lt) goto loc_826CC728;
	// subf r10,r4,r31
	ctx.r10.u64 = ctx.r31.u64 - ctx.r4.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826CC710:
	// srawi r10,r6,11
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FF) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 11;
	// add r6,r6,r24
	ctx.r6.u64 = ctx.r6.u64 + ctx.r24.u64;
	// lbzx r10,r10,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// stb r10,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x826cc710
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC710;
loc_826CC728:
	// lwz r11,15360(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x826cc750
	if (!ctx.cr6.lt) goto loc_826CC750;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
loc_826CC73C:
	// stbu r25,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r25.u8);
	ctx.r9.u32 = ea;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r11,15360(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826cc73c
	if (ctx.cr6.lt) goto loc_826CC73C;
loc_826CC750:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// add r28,r7,r11
	ctx.r28.u64 = ctx.r7.u64 + ctx.r11.u64;
	// cmpw cr6,r5,r17
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r17.s32, ctx.xer);
	// blt cr6,0x826cc550
	if (ctx.cr6.lt) goto loc_826CC550;
	// b 0x826cc778
	goto loc_826CC778;
loc_826CC764:
	// lwz r27,92(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// li r15,128
	ctx.r15.s64 = 128;
	// lwz r30,96(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// li r25,0
	ctx.r25.s64 = 0;
	// lwz r3,132(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
loc_826CC778:
	// lwz r11,15364(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15364);
	// mr r9,r17
	ctx.r9.u64 = ctx.r17.u64;
	// cmpw cr6,r17,r11
	ctx.cr6.compare<int32_t>(ctx.r17.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x826cc820
	if (!ctx.cr6.lt) goto loc_826CC820;
loc_826CC788:
	// lwz r10,15360(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826cc7b0
	if (!ctx.cr6.gt) goto loc_826CC7B0;
	// addi r10,r28,-1
	ctx.r10.s64 = ctx.r28.s64 + -1;
loc_826CC79C:
	// stbu r25,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r25.u8);
	ctx.r10.u32 = ea;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r8,15360(r16)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x826cc79c
	if (ctx.cr6.lt) goto loc_826CC79C;
loc_826CC7B0:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x826cc7d4
	if (!ctx.cr6.gt) goto loc_826CC7D4;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
	// subf r10,r30,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r30.u64;
loc_826CC7C4:
	// stbx r15,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r15.u8);
	// stb r15,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r15.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x826cc7c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826CC7C4;
loc_826CC7D4:
	// lwz r11,15360(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// add r27,r27,r3
	ctx.r27.u64 = ctx.r27.u64 + ctx.r3.u64;
	// add r30,r30,r3
	ctx.r30.u64 = ctx.r30.u64 + ctx.r3.u64;
	// add r8,r28,r11
	ctx.r8.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826cc80c
	if (!ctx.cr6.gt) goto loc_826CC80C;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
loc_826CC7F8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbu r25,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r25.u8);
	ctx.r9.u32 = ea;
	// lwz r11,15360(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 15360);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826cc7f8
	if (ctx.cr6.lt) goto loc_826CC7F8;
loc_826CC80C:
	// lwz r10,15364(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 15364);
	// addi r9,r7,1
	ctx.r9.s64 = ctx.r7.s64 + 1;
	// add r28,r8,r11
	ctx.r28.u64 = ctx.r8.u64 + ctx.r11.u64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826cc788
	if (ctx.cr6.lt) goto loc_826CC788;
loc_826CC820:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af64
	ctx.lr = 0x826CC830;
	__restfpr_24(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(__restvmx_115) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(sub_8273C8B0) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x82741868
	ctx.lr = 0x8273C8CC;
	sub_82741868(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r1,0(r1)
	ctx.r1.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8273CFF4) {
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

DEFINE_REX_FUNC(sub_8273EE10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8273EE18;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r3.u32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// rlwinm. r4,r5,0,27,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// lwz r10,180(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// lwz r10,180(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// stw r11,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r11.u32);
	// beq 0x8273ee70
	if (ctx.cr0.eq) goto loc_8273EE70;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	ctx.r27.s64 = -1073741824;
	// ori r27,r27,143
	ctx.r27.u64 = ctx.r27.u64 | 143;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// b 0x8273ee74
	goto loc_8273EE74;
loc_8273EE70:
	// lwz r27,80(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8273EE74:
	// rlwinm. r11,r5,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273ee94
	if (ctx.cr0.eq) goto loc_8273EE94;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	ctx.r27.s64 = -1073741824;
	// ori r27,r27,147
	ctx.r27.u64 = ctx.r27.u64 | 147;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// oris r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 1073741824;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8273EE94:
	// clrlwi. r11,r5,31
	ctx.r11.u64 = ctx.r5.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273eeb4
	if (ctx.cr0.eq) goto loc_8273EEB4;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	ctx.r27.s64 = -1073741824;
	// ori r27,r27,145
	ctx.r27.u64 = ctx.r27.u64 | 145;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// oris r10,r10,8192
	ctx.r10.u64 = ctx.r10.u64 | 536870912;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8273EEB4:
	// rlwinm. r11,r5,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273eed4
	if (ctx.cr0.eq) goto loc_8273EED4;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	ctx.r27.s64 = -1073741824;
	// ori r27,r27,142
	ctx.r27.u64 = ctx.r27.u64 | 142;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// oris r10,r10,4096
	ctx.r10.u64 = ctx.r10.u64 | 268435456;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8273EED4:
	// rlwinm. r11,r5,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273eef4
	if (ctx.cr0.eq) goto loc_8273EEF4;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	ctx.r27.s64 = -1073741824;
	// ori r27,r27,144
	ctx.r27.u64 = ctx.r27.u64 | 144;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8273EEF4:
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwimi r9,r10,20,4,4
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0x8000000) | (ctx.r9.u64 & 0xFFFFFFFFF7FFFFFF);
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwimi r9,r10,24,3,3
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x10000000) | (ctx.r9.u64 & 0xFFFFFFFFEFFFFFFF);
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwimi r9,r10,23,2,2
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x20000000) | (ctx.r9.u64 & 0xFFFFFFFFDFFFFFFF);
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwimi r9,r10,25,1,1
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x40000000) | (ctx.r9.u64 & 0xFFFFFFFFBFFFFFFF);
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwimi r9,r10,28,0,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x80000000) | (ctx.r9.u64 & 0xFFFFFFFF7FFFFFFF);
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// bl 0x8273f7a0
	ctx.lr = 0x8273EF70;
	sub_8273F7A0(ctx, base);
	// rlwinm. r11,r3,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273ef88
	if (ctx.cr0.eq) goto loc_8273EF88;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_8273EF88:
	// rlwinm. r11,r3,0,5,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273efa0
	if (ctx.cr0.eq) goto loc_8273EFA0;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// oris r10,r10,4096
	ctx.r10.u64 = ctx.r10.u64 | 268435456;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_8273EFA0:
	// rlwinm. r11,r3,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273efb8
	if (ctx.cr0.eq) goto loc_8273EFB8;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// oris r10,r10,8192
	ctx.r10.u64 = ctx.r10.u64 | 536870912;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_8273EFB8:
	// rlwinm. r11,r3,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273efd0
	if (ctx.cr0.eq) goto loc_8273EFD0;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// oris r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 1073741824;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_8273EFD0:
	// rlwinm. r11,r3,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273efe8
	if (ctx.cr0.eq) goto loc_8273EFE8;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_8273EFE8:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r30,1
	ctx.r30.s64 = 1;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8273f03c
	if (ctx.cr6.lt) goto loc_8273F03C;
	// beq cr6,0x8273f02c
	if (ctx.cr6.eq) goto loc_8273F02C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8273f01c
	if (ctx.cr6.lt) goto loc_8273F01C;
	// bne cr6,0x8273f04c
	if (!ctx.cr6.eq) goto loc_8273F04C;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwimi r10,r30,30,0,1
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 30) & 0xC0000000) | (ctx.r10.u64 & 0xFFFFFFFF3FFFFFFF);
	// b 0x8273f048
	goto loc_8273F048;
loc_8273F01C:
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwimi r10,r30,31,0,1
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0xC0000000) | (ctx.r10.u64 & 0xFFFFFFFF3FFFFFFF);
	// b 0x8273f048
	goto loc_8273F048;
loc_8273F02C:
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// oris r10,r10,49152
	ctx.r10.u64 = ctx.r10.u64 | 3221225472;
	// b 0x8273f048
	goto loc_8273F048;
loc_8273F03C:
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r10,r10,2
	ctx.r10.u64 = ctx.r10.u32 & 0x3FFFFFFF;
loc_8273F048:
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8273F04C:
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwimi r10,r30,27,2,4
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 27) & 0x38000000) | (ctx.r10.u64 & 0xFFFFFFFFC7FFFFFF);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwimi r10,r28,15,5,16
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 15) & 0x7FF8000) | (ctx.r10.u64 & 0xFFFFFFFFF8007FFF);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// beq cr6,0x8273f0d0
	if (ctx.cr6.eq) goto loc_8273F0D0;
	// rlwinm r10,r10,0,5,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFF87FFFFFF;
	// stw r10,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// stfs f0,16(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// rlwinm r10,r10,0,5,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFF87FFFFFF;
	// stw r10,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lfs f0,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 80, temp.u32);
	// b 0x8273f110
	goto loc_8273F110;
loc_8273F0D0:
	// rlwimi r10,r30,27,1,4
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 27) & 0x78000000) | (ctx.r10.u64 & 0xFFFFFFFF87FFFFFF);
	// stw r10,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lfd f0,0(r29)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// stfd f0,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.f0.u64);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// rlwimi r10,r30,27,1,4
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 27) & 0x78000000) | (ctx.r10.u64 & 0xFFFFFFFF87FFFFFF);
	// stw r10,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lfd f0,0(r26)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// stfd f0,80(r11)
	REX_STORE_U64(ctx.r11.u32 + 80, ctx.f0.u64);
loc_8273F110:
	// bl 0x82744f90
	ctx.lr = 0x8273F114;
	sub_82744F90(ctx, base);
	// addi r6,r1,180
	ctx.r6.s64 = ctx.r1.s64 + 180;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82749178
	ctx.lr = 0x8273F128;
	sub_82749178(ctx, base);
	// lwz r10,180(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f144
	if (ctx.cr0.eq) goto loc_8273F144;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,25,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8273F144:
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f15c
	if (ctx.cr0.eq) goto loc_8273F15C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,28,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8273F15C:
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f174
	if (ctx.cr0.eq) goto loc_8273F174;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,26,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8273F174:
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f18c
	if (ctx.cr0.eq) goto loc_8273F18C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,27,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8273F18C:
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8273f1a4
	if (ctx.cr0.eq) goto loc_8273F1A4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,29,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8273F1A4:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r11,r11,2,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x3;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8273f1e8
	if (ctx.cr6.lt) goto loc_8273F1E8;
	// beq cr6,0x8273f1dc
	if (ctx.cr6.eq) goto loc_8273F1DC;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8273f1d0
	if (ctx.cr6.lt) goto loc_8273F1D0;
	// bne cr6,0x8273f1f4
	if (!ctx.cr6.eq) goto loc_8273F1F4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwimi r11,r30,0,30,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x3) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFFC);
	// b 0x8273f1f0
	goto loc_8273F1F0;
loc_8273F1D0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwimi r11,r30,1,30,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0x3) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFFC);
	// b 0x8273f1f0
	goto loc_8273F1F0;
loc_8273F1DC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// ori r11,r11,3
	ctx.r11.u64 = ctx.r11.u64 | 3;
	// b 0x8273f1f0
	goto loc_8273F1F0;
loc_8273F1E8:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
loc_8273F1F0:
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8273F1F4:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8273f208
	if (ctx.cr6.eq) goto loc_8273F208;
	// lfs f0,80(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r26)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// b 0x8273f210
	goto loc_8273F210;
loc_8273F208:
	// lfd f0,80(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 80);
	// stfd f0,0(r26)
	REX_STORE_U64(ctx.r26.u32 + 0, ctx.f0.u64);
loc_8273F210:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82763E38) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82763e6c
	if (ctx.cr6.eq) goto loc_82763E6C;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82763e6c
	if (ctx.cr6.eq) goto loc_82763E6C;
	// bl 0x8263a978
	ctx.lr = 0x82763E64;
	sub_8263A978(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_82763E6C:
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

DEFINE_REX_FUNC(sub_82764920) {
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
	// li r30,4
	ctx.r30.s64 = 4;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82771fe8
	ctx.lr = 0x8276495C;
	sub_82771FE8(ctx, base);
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// addi r7,r31,4
	ctx.r7.s64 = ctx.r31.s64 + 4;
	// li r6,17
	ctx.r6.s64 = 17;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82771fe8
	ctx.lr = 0x8276497C;
	sub_82771FE8(ctx, base);
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// addi r7,r31,8
	ctx.r7.s64 = ctx.r31.s64 + 8;
	// li r6,28
	ctx.r6.s64 = 28;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82771fe8
	ctx.lr = 0x8276499C;
	sub_82771FE8(ctx, base);
	// li r30,2
	ctx.r30.s64 = 2;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// ori r6,r6,6
	ctx.r6.u64 = ctx.r6.u64 | 6;
	// addi r7,r31,12
	ctx.r7.s64 = ctx.r31.s64 + 12;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82771fe8
	ctx.lr = 0x827649C4;
	sub_82771FE8(ctx, base);
	// li r11,13
	ctx.r11.s64 = 13;
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82771fc8
	ctx.lr = 0x827649E8;
	sub_82771FC8(ctx, base);
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// li r6,17
	ctx.r6.s64 = 17;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82771fc8
	ctx.lr = 0x82764A04;
	sub_82771FC8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r7,r1,92
	ctx.r7.s64 = ctx.r1.s64 + 92;
	// li r6,28
	ctx.r6.s64 = 28;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82771fc8
	ctx.lr = 0x82764A28;
	sub_82771FC8(ctx, base);
	// li r11,1536
	ctx.r11.s64 = 1536;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// ori r6,r6,6
	ctx.r6.u64 = ctx.r6.u64 | 6;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82771fc8
	ctx.lr = 0x82764A54;
	sub_82771FC8(ctx, base);
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

DEFINE_REX_FUNC(sub_82769610) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82769618;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,420(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 420);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8276964c
	if (ctx.cr6.eq) goto loc_8276964C;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,183
	ctx.r31.u64 = ctx.r31.u64 | 183;
	// b 0x827696c0
	goto loc_827696C0;
loc_8276964C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82774fb0
	ctx.lr = 0x82769654;
	sub_82774FB0(ctx, base);
	// mr. r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x82769668
	if (!ctx.cr0.eq) goto loc_82769668;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x827696a8
	goto loc_827696A8;
loc_82769668:
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82774670
	ctx.lr = 0x82769680;
	sub_82774670(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x827696a8
	if (ctx.cr0.lt) goto loc_827696A8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82768bc0
	ctx.lr = 0x82769690;
	sub_82768BC0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x827696a8
	if (ctx.cr0.lt) goto loc_827696A8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82768cf0
	ctx.lr = 0x827696A0;
	sub_82768CF0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x827696bc
	if (!ctx.cr0.lt) goto loc_827696BC;
loc_827696A8:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x827696c0
	if (ctx.cr6.eq) goto loc_827696C0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82775008
	ctx.lr = 0x827696B8;
	sub_82775008(ctx, base);
	// b 0x827696c0
	goto loc_827696C0;
loc_827696BC:
	// stw r26,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r26.u32);
loc_827696C0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8276DD50) {
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
	// lwz r11,740(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 740);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8276dd80
	if (!ctx.cr0.eq) goto loc_8276DD80;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1314
	ctx.r3.u64 = ctx.r3.u64 | 1314;
	// b 0x8276de74
	goto loc_8276DE74;
loc_8276DD80:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8276dd98
	if (ctx.cr6.eq) goto loc_8276DD98;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1609
	ctx.r3.u64 = ctx.r3.u64 | 1609;
	// b 0x8276de74
	goto loc_8276DE74;
loc_8276DD98:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8276de3c
	if (!ctx.cr6.eq) goto loc_8276DE3C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82768ab0
	ctx.lr = 0x8276DDBC;
	sub_82768AB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8276de74
	if (ctx.cr0.lt) goto loc_8276DE74;
	// stw r30,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r30.u32);
	// addi r5,r31,188
	ctx.r5.s64 = ctx.r31.s64 + 188;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,400(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82771f60
	ctx.lr = 0x8276DDDC;
	sub_82771F60(ctx, base);
	// lwz r11,188(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r10,404(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// stw r11,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
	// bl 0x82764b98
	ctx.lr = 0x8276DDF8;
	sub_82764B98(ctx, base);
	// li r11,4
	ctx.r11.s64 = 4;
	// lwz r4,20(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8276DE24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,188(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8276de70
	if (!ctx.cr6.eq) goto loc_8276DE70;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8276d998
	ctx.lr = 0x8276DE38;
	sub_8276D998(ctx, base);
	// b 0x8276de68
	goto loc_8276DE68;
loc_8276DE3C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8276de60
	if (ctx.cr6.eq) goto loc_8276DE60;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,47
	ctx.r4.s64 = 47;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82768ab0
	ctx.lr = 0x8276DE58;
	sub_82768AB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8276de74
	if (ctx.cr0.lt) goto loc_8276DE74;
loc_8276DE60:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8276c470
	ctx.lr = 0x8276DE68;
	sub_8276C470(ctx, base);
loc_8276DE68:
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8276de74
	if (ctx.cr0.lt) goto loc_8276DE74;
loc_8276DE70:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8276DE74:
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

DEFINE_REX_FUNC(sub_827727F0) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// ori r10,r10,996
	ctx.r10.u64 = ctx.r10.u64 | 996;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82772810
	if (ctx.cr6.eq) goto loc_82772810;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82772834
	if (ctx.cr6.lt) goto loc_82772834;
	// b 0x8277281c
	goto loc_8277281C;
loc_82772810:
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82772834
	if (ctx.cr6.eq) goto loc_82772834;
loc_8277281C:
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// mulli r11,r11,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(12));
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8277283c
	if (ctx.cr6.lt) goto loc_8277283C;
loc_82772834:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8277283C:
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// mulli r10,r4,24
	ctx.r10.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(24));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82774120) {
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
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8276b420
	ctx.lr = 0x8277413C;
	sub_8276B420(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,260
	ctx.r3.s64 = 260;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82772060
	ctx.lr = 0x82774150;
	sub_82772060(ctx, base);
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

DEFINE_REX_FUNC(sub_82775990) {
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
	// bl 0x82748820
	ctx.lr = 0x827759B0;
	sub_82748820(ctx, base);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// subf. r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x827759d0
	if (ctx.cr0.eq) goto loc_827759D0;
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm r9,r10,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_827759D0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,32
	ctx.r3.s64 = ctx.r31.s64 + 32;
	// bl 0x827843d8
	ctx.lr = 0x827759DC;
	sub_827843D8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82748820
	ctx.lr = 0x827759E4;
	sub_82748820(ctx, base);
	// stw r3,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
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

DEFINE_REX_FUNC(sub_82778530) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82778538;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,108
	ctx.r30.s64 = ctx.r3.s64 + 108;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x82855b44
	ctx.lr = 0x82778558;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82775cb0
	ctx.lr = 0x82778564;
	sub_82775CB0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82778588
	if (!ctx.cr0.eq) goto loc_82778588;
	// lis r29,-32646
	ctx.r29.s64 = -2139488256;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ori r29,r29,4105
	ctx.r29.u64 = ctx.r29.u64 | 4105;
	// bl 0x82855b34
	ctx.lr = 0x8277857C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// b 0x82778664
	goto loc_82778664;
loc_82778588:
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x827785bc
	if (!ctx.cr6.eq) goto loc_827785BC;
	// lwz r31,188(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x827785e4
	if (ctx.cr6.eq) goto loc_827785E4;
loc_8277859C:
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
	// bne 0x8277859c
	if (!ctx.cr0.eq) goto loc_8277859C;
	// b 0x827785e4
	goto loc_827785E4;
loc_827785BC:
	// lwz r31,88(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x827785e4
	if (ctx.cr6.eq) goto loc_827785E4;
loc_827785C8:
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
	// bne 0x827785c8
	if (!ctx.cr0.eq) goto loc_827785C8;
loc_827785E4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x827785EC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82778658
	if (ctx.cr6.eq) goto loc_82778658;
	// lwz r30,8(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x82778610
	if (!ctx.cr6.lt) goto loc_82778610;
	// lis r29,-32646
	ctx.r29.s64 = -2139488256;
	// ori r29,r29,4097
	ctx.r29.u64 = ctx.r29.u64 | 4097;
	// b 0x82778624
	goto loc_82778624;
loc_82778610:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x82778620;
	sub_8273A030(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
loc_82778624:
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
	// bne 0x82778624
	if (!ctx.cr0.eq) goto loc_82778624;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82778660
	if (!ctx.cr6.eq) goto loc_82778660;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82772060
	ctx.lr = 0x82778654;
	sub_82772060(ctx, base);
	// b 0x82778660
	goto loc_82778660;
loc_82778658:
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82778660:
	// stw r30,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
loc_82778664:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827844CC) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827844D0) {
	REX_FUNC_PROLOGUE();
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_827844EC:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8278450c
	if (ctx.cr6.eq) goto loc_8278450C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x827844ec
	if (ctx.cr6.lt) goto loc_827844EC;
	// blr 
	return;
loc_8278450C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82785048) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r5,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r6,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// stw r7,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// stw r7,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82785C68) {
	REX_FUNC_PROLOGUE();
	// clrlwi. r11,r5,31
	ctx.r11.u64 = ctx.r5.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82785c9c
	if (ctx.cr0.eq) goto loc_82785C9C;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// oris r11,r11,12288
	ctx.r11.u64 = ctx.r11.u64 | 805306368;
	// rlwinm. r10,r11,0,8,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// bne 0x82785c94
	if (!ctx.cr0.eq) goto loc_82785C94;
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// b 0x82785cb4
	goto loc_82785CB4;
loc_82785C94:
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// b 0x82785cb4
	goto loc_82785CB4;
loc_82785C9C:
	// rlwinm. r10,r5,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq 0x82785cb4
	if (ctx.cr0.eq) goto loc_82785CB4;
	// lwz r10,40(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// oris r10,r10,4096
	ctx.r10.u64 = ctx.r10.u64 | 268435456;
	// stw r10,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
loc_82785CB4:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x82785ce0
	if (ctx.cr6.lt) goto loc_82785CE0;
	// lwz r10,8(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// lbz r9,15(r6)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r6.u32 + 15);
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r8,40(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// stw r11,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// oris r11,r8,32768
	ctx.r11.u64 = ctx.r8.u64 | 2147483648;
	// stw r10,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// b 0x82785ce8
	goto loc_82785CE8;
loc_82785CE0:
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// oris r11,r11,18432
	ctx.r11.u64 = ctx.r11.u64 | 1207959552;
loc_82785CE8:
	// stw r11,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// stw r4,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r4.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82788AE0) {
	REX_FUNC_PROLOGUE();
	// b 0x8278ce30
	sub_8278CE30(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82788C68) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-1100
	ctx.r3.s64 = ctx.r3.s64 + -1100;
	// b 0x8278d018
	sub_8278D018(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82788DE0) {
	REX_FUNC_PROLOGUE();
	// addi r11,r3,36
	ctx.r11.s64 = ctx.r3.s64 + 36;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// lwz r10,32(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// ori r11,r11,65534
	ctx.r11.u64 = ctx.r11.u64 | 65534;
	// stw r10,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// stw r11,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// lbz r11,68(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 68);
	// addi r11,r11,-6
	ctx.r11.s64 = ctx.r11.s64 + -6;
	// lis r12,-32249
	ctx.r12.s64 = -2113470464;
	// addi r12,r12,-28824
	ctx.r12.s64 = ctx.r12.s64 + -28824;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// lis r12,-32135
	ctx.r12.s64 = -2105999360;
	// nop 
	// addi r12,r12,-29140
	ctx.r12.s64 = ctx.r12.s64 + -29140;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82788E2C;
	case 1:
		goto loc_82788E38;
	case 2:
		goto loc_82788E38;
	case 3:
		goto loc_82788E2C;
	case 4:
		goto loc_82788E2C;
	case 5:
		goto loc_82788E2C;
	case 6:
		goto loc_82788E40;
	case 7:
		goto loc_82788E48;
	case 8:
		goto loc_82788E38;
	case 9:
		goto loc_82788E38;
	case 10:
		sub_82788E50(ctx, base);
		return;
	case 11:
		goto loc_82788E2C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82788E2C:
	// li r11,131
	ctx.r11.s64 = 131;
loc_82788E30:
	// stw r11,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// blr 
	return;
loc_82788E38:
	// li r11,1155
	ctx.r11.s64 = 1155;
	// b 0x82788e30
	goto loc_82788E30;
loc_82788E40:
	// li r11,129
	ctx.r11.s64 = 129;
	// b 0x82788e30
	goto loc_82788E30;
loc_82788E48:
	// li r11,1153
	ctx.r11.s64 = 1153;
	// b 0x82788e30
	goto loc_82788E30;
}

DEFINE_REX_FUNC(sub_8278B190) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x8278B198;
	__savegprlr_19(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r20,0
	ctx.r20.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// stw r20,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r20.u32);
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r21,r7
	ctx.r21.u64 = ctx.r7.u64;
	// mr r22,r8
	ctx.r22.u64 = ctx.r8.u64;
	// mr r19,r9
	ctx.r19.u64 = ctx.r9.u64;
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x8278b1dc
	if (!ctx.cr6.eq) goto loc_8278B1DC;
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
	// addi r27,r1,84
	ctx.r27.s64 = ctx.r1.s64 + 84;
	// sth r30,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r30.u16);
	// sth r30,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r30.u16);
loc_8278B1DC:
	// addi r28,r31,244
	ctx.r28.s64 = ctx.r31.s64 + 244;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b44
	ctx.lr = 0x8278B1E8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r8,296(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// addi r29,r31,312
	ctx.r29.s64 = ctx.r31.s64 + 312;
	// mr r25,r30
	ctx.r25.u64 = ctx.r30.u64;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r11,20(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 20);
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lhz r9,18(r8)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r8.u32 + 18);
	// rldimi r7,r9,32,16
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFF00000000) | (ctx.r7.u64 & 0xFFFF0000FFFFFFFF);
	// clrlwi r11,r7,30
	ctx.r11.u64 = ctx.r7.u32 & 0x3;
	// sth r9,92(r1)
	REX_STORE_U16(ctx.r1.u32 + 92, ctx.r9.u16);
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r11,r29
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// b 0x8278b250
	goto loc_8278B250;
loc_8278B22C:
	// lwzx r10,r11,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// ld r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// cmpld cr6,r11,r26
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r26.u64, ctx.xer);
	// beq cr6,0x8278b25c
	if (ctx.cr6.eq) goto loc_8278B25C;
	// rldicl r9,r9,62,2
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 62) & 0x3FFFFFFFFFFFFFFF;
	// clrlwi r11,r9,30
	ctx.r11.u64 = ctx.r9.u32 & 0x3;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r11,r10
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
loc_8278B250:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8278b22c
	if (!ctx.cr6.eq) goto loc_8278B22C;
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
loc_8278B25C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8278b270
	if (ctx.cr6.eq) goto loc_8278B270;
	// lis r30,-32646
	ctx.r30.s64 = -2139488256;
	// ori r30,r30,4100
	ctx.r30.u64 = ctx.r30.u64 | 4100;
	// b 0x8278b300
	goto loc_8278B300;
loc_8278B270:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82792a60
	ctx.lr = 0x8278B290;
	sub_82792A60(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8278b300
	if (ctx.cr0.lt) goto loc_8278B300;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r5,r11,144
	ctx.r5.s64 = ctx.r11.s64 + 144;
	// bl 0x82789b60
	ctx.lr = 0x8278B2AC;
	sub_82789B60(ctx, base);
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_8278B2C0:
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
	// bne 0x8278b2c0
	if (!ctx.cr0.eq) goto loc_8278B2C0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b34
	ctx.lr = 0x8278B2E4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r25,r20
	ctx.r25.u64 = ctx.r20.u64;
	// bl 0x827900e0
	ctx.lr = 0x8278B2F8;
	sub_827900E0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x8278b32c
	if (!ctx.cr0.lt) goto loc_8278B32C;
loc_8278B300:
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8278b314
	if (ctx.cr6.eq) goto loc_8278B314;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8278a480
	ctx.lr = 0x8278B314;
	sub_8278A480(ctx, base);
loc_8278B314:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8278b324
	if (ctx.cr6.eq) goto loc_8278B324;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b34
	ctx.lr = 0x8278B324;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8278B324:
	// stw r20,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r20.u32);
	// b 0x8278b338
	goto loc_8278B338;
loc_8278B32C:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// stw r11,0(r19)
	REX_STORE_U32(ctx.r19.u32 + 0, ctx.r11.u32);
loc_8278B338:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827956B0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r10,r4,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x80000000;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x827956f8
	if (!ctx.cr6.eq) goto loc_827956F8;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r11,r4,3,5,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0x7FFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827956f8
	if (ctx.cr6.lt) goto loc_827956F8;
	// lwz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x827956f8
	if (!ctx.cr6.lt) goto loc_827956F8;
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm r9,r4,8,25,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0x7F;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x827956f8
	if (!ctx.cr6.eq) goto loc_827956F8;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// blr 
	return;
loc_827956F8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82796D18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82796D20;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82796d50
	if (ctx.cr0.eq) goto loc_82796D50;
loc_82796D40:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x827946d0
	ctx.lr = 0x82796D4C;
	sub_827946D0(ctx, base);
	// b 0x82796dcc
	goto loc_82796DCC;
loc_82796D50:
	// lbz r11,15(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 15);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82796ebc
	if (ctx.cr6.eq) goto loc_82796EBC;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lbz r11,14(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 14);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82796d78
	if (ctx.cr6.eq) goto loc_82796D78;
	// beq 0x82796d7c
	if (ctx.cr0.eq) goto loc_82796D7C;
	// b 0x82796ebc
	goto loc_82796EBC;
loc_82796D78:
	// beq 0x82796ebc
	if (ctx.cr0.eq) goto loc_82796EBC;
loc_82796D7C:
	// subf r10,r3,r30
	ctx.r10.u64 = ctx.r30.u64 - ctx.r3.u64;
	// ld r9,816(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 816);
	// li r8,24
	ctx.r8.s64 = 24;
	// addi r7,r10,-48
	ctx.r7.s64 = ctx.r10.s64 + -48;
	// rldicr r10,r9,5,58
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u64, 5) & 0xFFFFFFFFFFFFFFE0;
	// divw r9,r7,r8
	ctx.r9.u64 = uint32_t((ctx.r8.s32 && !(ctx.r7.s32 == INT32_MIN && ctx.r8.s32 == -1)) ? ctx.r7.s32 / ctx.r8.s32 : 0);
	// rlwinm. r8,r11,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bne 0x82796dd8
	if (!ctx.cr0.eq) goto loc_82796DD8;
	// addi r11,r31,60
	ctx.r11.s64 = ctx.r31.s64 + 60;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x8279a4c8
	ctx.lr = 0x82796DB8;
	sub_8279A4C8(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82796dcc
	if (!ctx.cr6.eq) goto loc_82796DCC;
loc_82796DC4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82796850
	ctx.lr = 0x82796DCC;
	sub_82796850(ctx, base);
loc_82796DCC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82796DD0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_82796DD8:
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82796e00
	if (!ctx.cr0.eq) goto loc_82796E00;
	// ld r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 72);
	// li r9,1
	ctx.r9.s64 = 1;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cmpld cr6,r11,r9
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r9.u64, ctx.xer);
	// bge cr6,0x82796d40
	if (!ctx.cr6.lt) goto loc_82796D40;
	// lhz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 80);
	// b 0x82796e0c
	goto loc_82796E0C;
loc_82796E00:
	// lhz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 80);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
loc_82796E0C:
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// clrlwi r27,r11,16
	ctx.r27.u64 = ctx.r11.u32 & 0xFFFF;
	// lhz r11,10(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 10);
	// subf r11,r27,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r27.u64;
	// lhz r10,1074(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 1074);
	// rotlwi r10,r10,5
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 5);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82796ebc
	if (ctx.cr6.gt) goto loc_82796EBC;
	// addi r29,r31,48
	ctx.r29.s64 = ctx.r31.s64 + 48;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8279a4c8
	ctx.lr = 0x82796E40;
	sub_8279A4C8(ctx, base);
	// lbz r11,15(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 15);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82796e5c
	if (!ctx.cr6.eq) goto loc_82796E5C;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// oris r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 536870912;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// b 0x82796e70
	goto loc_82796E70;
loc_82796E5C:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82796e70
	if (!ctx.cr6.eq) goto loc_82796E70;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
loc_82796E70:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82796dcc
	if (!ctx.cr6.eq) goto loc_82796DCC;
	// lhz r11,10(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 10);
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x82796dcc
	if (!ctx.cr6.eq) goto loc_82796DCC;
	// lwz r6,100(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x82796ea0
	if (!ctx.cr6.eq) goto loc_82796EA0;
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82796dc4
	if (!ctx.cr6.gt) goto loc_82796DC4;
loc_82796EA0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lhz r7,80(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,96(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// bl 0x827960c8
	ctx.lr = 0x82796EB4;
	sub_827960C8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82796dc4
	if (!ctx.cr0.eq) goto loc_82796DC4;
loc_82796EBC:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4109
	ctx.r3.u64 = ctx.r3.u64 | 4109;
	// b 0x82796dd0
	goto loc_82796DD0;
}

DEFINE_REX_FUNC(sub_827A2898) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x827A28A0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,0(r4)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// lwz r3,380(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 380);
	// bl 0x827a1b20
	ctx.lr = 0x827A28D8;
	sub_827A1B20(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x827a28fc
	if (!ctx.cr0.lt) goto loc_827A28FC;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// b 0x827a2924
	goto loc_827A2924;
loc_827A28FC:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r29,368
	ctx.r11.s64 = ctx.r29.s64 + 368;
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// lwz r10,372(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 372);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827a291c
	if (ctx.cr6.eq) goto loc_827A291C;
	// stw r30,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// b 0x827a2920
	goto loc_827A2920;
loc_827A291C:
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_827A2920:
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
loc_827A2924:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A8130) {
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
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-27584(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -27584);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827A815C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bne 0x827a8170
	if (!ctx.cr0.eq) goto loc_827A8170;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827a8190
	goto loc_827A8190;
loc_827A8170:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f0,2520(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2520);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,2524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2524);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
loc_827A8190:
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

DEFINE_REX_FUNC(sub_827ABF10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// rlwinm. r9,r3,29,27,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1F;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lfsx f0,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,5864(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 5864);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfs f13,-9140(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -9140);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfsx f0,r10,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lfsx f0,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// ble 0x827abf70
	if (!ctx.cr0.gt) goto loc_827ABF70;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_827ABF50:
	// lfsx f11,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfsx f11,r10,r11
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lfsx f11,r10,r11
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x827abf50
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827ABF50;
loc_827ABF70:
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r10,32
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 32, ctx.xer);
	// bgt cr6,0x827abfa8
	if (ctx.cr6.gt) goto loc_827ABFA8;
	// subfic r9,r10,33
	ctx.xer.ca = ctx.r10.u32 <= 33;
	ctx.r9.u64 = static_cast<uint64_t>(33) - ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_827ABF88:
	// lfsx f11,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfsx f11,r10,r11
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lfsx f11,r10,r11
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x827abf88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827ABF88;
loc_827ABFA8:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fdivs f13,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// li r9,33
	ctx.r9.s64 = 33;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// lfs f0,2524(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2524);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_827ABFC8:
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// lfsu f0,4(r11)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// lfs f12,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// std r9,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// bdnz 0x827abfc8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827ABFC8;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,8(r4)
	REX_STORE_U16(ctx.r4.u32 + 8, ctx.r10.u16);
	// lfs f0,24240(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24240);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,4(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AF160) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9508(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AF9B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9264);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9260(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9260, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B04E8) {
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
	// lfs f0,22904(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22904);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9056(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9056);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8936(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1188) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8556(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8556);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8552(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8552, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1DB0) {
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
	// lfs f0,23288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8248);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8184(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8184, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2C10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23500);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7756(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7756, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B3A10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7344(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B4670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6988);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6984(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6984, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5370) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B60E0) {
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
	// lfs f0,24072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6268);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6200(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B71C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-5700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5700);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-5696(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -5696, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7A08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
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

DEFINE_REX_FUNC(sub_827B86E0) {
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
	// lfs f0,24504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5156(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5156);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5100(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5100, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9640) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4768(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4768);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4652(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BA7E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-4136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4132(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4132, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB638) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-3692(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3692);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3688(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC4E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-3356(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -3356);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3252(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3252, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD170) {
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
	// lfs f12,-2984(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2984);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2884(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BE418) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,25848
	ctx.r9.s64 = ctx.r11.s64 + 25848;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,25848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2336(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BF658) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-1800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1796(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C05B0) {
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
	// lfs f13,-1440(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1440);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1332(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1390) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1008(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1008);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-920(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -920, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C26A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-380(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -380);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-376(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3648) {
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
	// lfs f0,27144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,88(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 88, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C4648) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 560);
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

DEFINE_REX_FUNC(sub_827C5620) {
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
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,920(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 920);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1036(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C69B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1636(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1636);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1640(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7950) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2120(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2120, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8850) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,2560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2564(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2564, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9530) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,2936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2936);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2940(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2940, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CA2F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,3340(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3340);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3344(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CB1C0) {
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
	// lfs f0,29032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3744(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3744);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3800(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3800, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CC480) {
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
	// lfs f0,29224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4300(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4300);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4348(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD710) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,4884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4884);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4888(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4888, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CE7F8) {
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
	// lfs f0,29544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5260(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5260);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5376(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CFA78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,5812(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5812);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5916(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D08C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6332);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6336(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D16A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6740(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6740);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6744(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2798) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30252(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30252);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7232(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7232, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D3518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30392(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30392);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7628(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D43D8) {
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
	// lfs f0,30504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7992(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7992);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8060(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D5670) {
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
	// lfs f12,8548(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8548);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8604(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6940) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,9100(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 9100);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9152(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9152, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D79E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,9628(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9628);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9632(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9632, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D8768) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10028(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D9608) {
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
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10388(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10388);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10456(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10456, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA898) {
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
	// lfs f0,31560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10944(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10944);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11000(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DBB80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,11544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11548(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11548, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DCC98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,12064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12064);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,12068(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 12068, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DD508) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12192(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12192);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12312(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12312, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE850) {
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
	// lfs f0,32152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12780(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12780);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12880(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DFBE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,13448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13448);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,13452(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 13452, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0548) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13724(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1358) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14156(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E23F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14656(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E34B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15124);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15128(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15128, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E4320) {
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
	// lfs f0,-32088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,15428(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15428);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,15540(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 15540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E5698) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-31136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16080(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16080, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6660) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,16540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16540);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16544(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E76E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-27480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16936(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 16936);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16988(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16988, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8680) {
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
	// lfs f0,-25912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17372(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17372);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17428(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9858) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17940);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17944(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EA928) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,18396(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18396);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,18400(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 18400, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB1D8) {
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
	// lfs f0,-22792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18544(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18544);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18652(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18652, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EC6C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-21812(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21812);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ED610) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,-21368
	ctx.r11.s64 = ctx.r11.s64 + -21368;
	// lfs f0,19516(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 19516);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// stfs f0,16(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EE2B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,19988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19988);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19992(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19992, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EF1F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-19652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20412(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0320) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20824(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20824);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20888(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20888, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F14B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-18360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,21272(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 21272);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21376(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F24B8) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r8,21832
	ctx.r6.s64 = ctx.r8.s64 + 21832;
	// li r10,7
	ctx.r10.s64 = 7;
	// li r5,97
	ctx.r5.s64 = 97;
	// lwz r11,21832(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 21832);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwimi r11,r7,1,24,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF00);
	// stw r11,21832(r8)
	REX_STORE_U32(ctx.r8.u32 + 21832, ctx.r11.u32);
	// stb r10,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r10.u8);
	// lwz r11,21832(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 21832);
	// rlwimi r11,r5,16,8,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFF0000) | (ctx.r11.u64 & 0xFFFFFFFFFF00FFFF);
	// stw r11,21832(r8)
	REX_STORE_U32(ctx.r8.u32 + 21832, ctx.r11.u32);
	// stb r9,21832(r8)
	REX_STORE_U8(ctx.r8.u32 + 21832, ctx.r9.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F3D18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-16840
	ctx.r9.s64 = ctx.r11.s64 + -16840;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-16840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,22508(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 22508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F50C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-16000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23244(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23244, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F61A0) {
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
	// lfs f0,-15592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,23720(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23720);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,23780(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 23780, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F73C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-14040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14040);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24232);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24284(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F86E0) {
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
	// lfs f0,-12344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24708(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24708);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,24780(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 24780, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9948) {
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
	// lfs f0,-10248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25232);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25296(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25296, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FAC98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25844(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25844);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25848(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FBCB8) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26196(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26196);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26316(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26316, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FCF58) {
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
	// lfs f0,-9368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26748(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26748);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26860(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26860, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FE358) {
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
	// lfs f0,-9176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27324(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27324);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27440(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27440, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FF6B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28004(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828004B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28412);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28416(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801418) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,28860(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28860);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,28864(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 28864, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801DE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29152(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29152, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802CB0) {
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
	// lfs f0,-8408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8408);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29504(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29504);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29584(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29584, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804058) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-8216
	ctx.r9.s64 = ctx.r11.s64 + -8216;
	// lfs f0,-8216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30156(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 30156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804FC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805DE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31020(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82806F38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7692(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7692);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31520(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31520, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807D58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31932);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31936(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808C38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,32364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32364);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,32368(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 32368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809618) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,32656(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 32656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A4F0) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32536);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-32448(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -32448, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280B940) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-31972(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31972);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31856(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280CC78) {
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
	// lfs f0,-6744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-31388(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31388);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31276(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31276, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280DF80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30724(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280F030) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-30236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-30232(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -30232, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280FA60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29936(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828107E0) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29612(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29612);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-29528(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -29528, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811B80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28948(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812BB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-28584(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28584);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28480(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828139C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28052(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28052);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28048(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814988) {
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
	// lfs f0,-4808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-27576(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -27576);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-27528(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -27528, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815D38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26956(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26956);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26952(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26952, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82816EE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-26540(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -26540);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26436(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26436, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817CC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26012(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26012, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818CD0) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25644(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25644);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25528(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25528, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281A228) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24892(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281AF48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24492(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24492, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281BF40) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24112(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24112);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-24024(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -24024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281D200) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-23456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23456);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23452(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23452, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281E320) {
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
	// lfs f0,-2440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23012(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23012);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22944(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281F670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-22380(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22380);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22376(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828205F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-21920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21916(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828217A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21404(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21404, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82822600) {
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
	// lfs f0,-1560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21028(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21028);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20980(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20980, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828238F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-20416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20412(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82824A58) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20016(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20016);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19904(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19904, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825C70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19348(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19348);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19344(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826E20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-452(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -452);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18832(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82827C40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-18420(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18420);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18416(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828CD0) {
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
	// lfs f0,-152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18044(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18044);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17928(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829F98) {
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
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17460(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17460);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17380(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282B268) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282C310) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,592(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 592);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16328(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D220) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-15896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15896);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-15892(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -15892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282DC98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-15588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15588);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15584(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15584, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282ED20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,1008
	ctx.r9.s64 = ctx.r11.s64 + 1008;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,1008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15096(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15096, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830008) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-14540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14540);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14536(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14536, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828310E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14032(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14032, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832008) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1780(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1780);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13584(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13584, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832E48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-13260(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -13260);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13156(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833D60) {
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
	// lfs f0,2136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12820(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12820);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12704(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828351F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-12200(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12200);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12096(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12096, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836160) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-11644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11640(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837238) {
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
	// lfs f0,2808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11204(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11204);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11140(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11140, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838498) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
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

DEFINE_REX_FUNC(sub_82839638) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-10096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10092(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283A4B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9664(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9664, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283B4C8) {
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
	// lfs f12,-9300(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9300);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9196(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9196, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283C928) {
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
	// lfs f0,3776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8704(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8704);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8604(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283DD20) {
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
	// lfs f0,4016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8136(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8136);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8020(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283F140) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4308);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7436(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7436, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283FEB8) {
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
	// lfs f12,-7072(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7072);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7024(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828412D8) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6496(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6496);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6436(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6436, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828426C0) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5928(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5928);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5856(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82843A80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5276(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5276);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5272(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5272, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82844BA8) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4832(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4832);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4760(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4760, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845D90) {
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
	// lfs f0,5744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4304(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4304);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4220(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847278) {
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
	// lfs f0,5968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3728(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3728);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3612(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848730) {
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
	// lfs f0,-3000(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -3000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2100(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2100);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2996(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2548(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2548, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284A7B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2048(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284B668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1616(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284C598) {
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
	// lfs f0,6928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1244(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1244);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1172(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1172, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284D9C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
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
	// stfs f0,-576(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -576, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284EB30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -44);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-40(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -40, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284FB48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,7752(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7752);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,432(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850E30) {
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
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,892(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 892);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1012(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1012, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828523E0) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1516(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1516);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1628(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853970) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2268(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2268);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2272(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2272, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82855358) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,-28248(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -28248);
	// stw r11,-27844(r10)
	REX_STORE_U32(ctx.r10.u32 + -27844, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828715E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// vspltish v13,8
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x8)));
	// vspltish v12,-1
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_set1_epi16(short(0xFFFF)));
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// vspltish v11,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_set1_epi16(short(0x3)));
	// li r8,0
	ctx.r8.s64 = 0;
	// lvsl v7,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// vslh v31,v12,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vor128 v63,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// li r10,16
	ctx.r10.s64 = 16;
	// lvsl v6,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// bne cr6,0x82871708
	if (!ctx.cr6.eq) goto loc_82871708;
	// lvx128 v59,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lvx128 v61,r3,r4
	ea = (ctx.r3.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v10,v61,v59,v6
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v12,v62,v60,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v58,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v5,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v10,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v4,v57,v58,v5
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vmrghb v7,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmrghb v13,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// ble cr6,0x828717ec
	if (!ctx.cr6.gt) goto loc_828717EC;
	// li r6,48
	ctx.r6.s64 = 48;
loc_82871664:
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// vadduhm v9,v10,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// vslh v12,v9,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// lvx128 v61,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v6,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// vperm128 v8,v62,v61,v6
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vadduhm v6,v9,v12
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vmrghb v12,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v56,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vadduhm v5,v6,v2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// lvsl v4,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v3,v55,v56,v4
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vadduhm v9,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vadduhm v30,v7,v12
	simde_mm_store_si128((simde__m128i*)ctx.v30.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// vor v7,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vmrghb v8,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vslh v29,v9,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubshs v28,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vadduhm v27,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vadduhm v26,v9,v29
	simde_mm_store_si128((simde__m128i*)ctx.v26.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// vor v10,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vadduhm v12,v5,v28
	simde_mm_store_si128((simde__m128i*)ctx.v12.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vsubshs v25,v0,v27
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// vadduhm v24,v26,v2
	simde_mm_store_si128((simde__m128i*)ctx.v24.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vor v13,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vsrah v23,v12,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vadduhm v12,v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v12.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.u16), simde_mm_load_si128((simde__m128i*)ctx.v25.u16)));
	// vor128 v54,v63,v23
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v23.u8)));
	// stvx128 v23,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v22,v12,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v22,r9,r6
	ea = (ctx.r9.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v63,v54,v22
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v22.u8)));
	// addi r9,r9,96
	ctx.r9.s64 = ctx.r9.s64 + 96;
	// blt cr6,0x82871664
	if (ctx.cr6.lt) goto loc_82871664;
	// b 0x828717ec
	goto loc_828717EC;
loc_82871708:
	// lvx128 v50,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lvx128 v53,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lvx128 v51,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r3,r4
	ea = (ctx.r3.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v10,v53,v51,v7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v12,v52,v50,v6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvx128 v49,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
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
	// ble cr6,0x828717ec
	if (!ctx.cr6.gt) goto loc_828717EC;
loc_82871754:
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// vadduhm v8,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vadduhm v7,v12,v9
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// vslh v3,v8,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v47,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v30,v7,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v46,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// lvsl v6,r0,r11
	temp.u32 = ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v6,v46,v47,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vadduhm v3,v8,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vadduhm v30,v7,v30
	simde_mm_store_si128((simde__m128i*)ctx.v30.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	// vmrghb v8,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vadduhm v29,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v29.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vmrglb v7,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vadduhm v28,v30,v2
	simde_mm_store_si128((simde__m128i*)ctx.v28.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.u16), simde_mm_load_si128((simde__m128i*)ctx.v2.u16)));
	// vadduhm v27,v5,v8
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v8.u16)));
	// vadduhm v26,v4,v7
	simde_mm_store_si128((simde__m128i*)ctx.v26.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v7.u16)));
	// vor v5,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vor v4,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vsubshs v25,v0,v27
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// vsubshs v24,v0,v26
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v26.s16)));
	// vor v13,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vor v12,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vadduhm v6,v29,v25
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), simde_mm_load_si128((simde__m128i*)ctx.v25.u16)));
	// vadduhm v3,v28,v24
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.u16), simde_mm_load_si128((simde__m128i*)ctx.v24.u16)));
	// vor v10,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vor v9,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// vsrah v23,v6,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v22,v3,v1
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vor128 v45,v63,v23
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v23.u8)));
	// stvx128 v23,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r9,r10
	ea = (ctx.r9.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// vor128 v63,v45,v22
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)ctx.v22.u8)));
	// blt cr6,0x82871754
	if (ctx.cr6.lt) goto loc_82871754;
loc_828717EC:
	// vand128 v13,v63,v31
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vcmpgtuh. v12,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v12.u16), 0xFFFF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// not r10,r11
	ctx.r10.u64 = ~ctx.r11.u64;
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

