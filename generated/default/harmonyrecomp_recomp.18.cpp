#include "harmonyrecomp_funcs.18.h"

DEFINE_REX_FUNC(sub_82210E60) {
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
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// addi r31,r11,22072
	ctx.r31.s64 = ctx.r11.s64 + 22072;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82210e94
	if (ctx.cr0.eq) goto loc_82210E94;
	// bl 0x825e0218
	ctx.lr = 0x82210E94;
	sub_825E0218(ctx, base);
loc_82210E94:
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82210eac
	if (ctx.cr0.eq) goto loc_82210EAC;
	// bl 0x825e0218
	ctx.lr = 0x82210EAC;
	sub_825E0218(ctx, base);
loc_82210EAC:
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82210ec4
	if (ctx.cr0.eq) goto loc_82210EC4;
	// bl 0x825e0218
	ctx.lr = 0x82210EC4;
	sub_825E0218(ctx, base);
loc_82210EC4:
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82210edc
	if (ctx.cr0.eq) goto loc_82210EDC;
	// bl 0x825e0218
	ctx.lr = 0x82210EDC;
	sub_825E0218(ctx, base);
loc_82210EDC:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,-15568
	ctx.r11.s64 = ctx.r11.s64 + -15568;
	// addi r31,r10,-15584
	ctx.r31.s64 = ctx.r10.s64 + -15584;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82210f28
	if (!ctx.cr6.eq) goto loc_82210F28;
	// lwz r11,-12672(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12672);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82210f68
	if (ctx.cr6.eq) goto loc_82210F68;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lis r3,-16381
	ctx.r3.s64 = -1073545216;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,3
	ctx.r3.u64 = ctx.r3.u64 | 3;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82210F24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82210f68
	goto loc_82210F68;
loc_82210F28:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_82210F2C:
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
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
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
	// bne 0x82210f2c
	if (!ctx.cr0.eq) goto loc_82210F2C;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82210f68
	if (!ctx.cr6.eq) goto loc_82210F68;
	// lwz r11,-36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -36);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// stw r11,-36(r31)
	REX_STORE_U32(ctx.r31.u32 + -36, ctx.r11.u32);
loc_82210F68:
	// bl 0x825e0c30
	ctx.lr = 0x82210F6C;
	sub_825E0C30(ctx, base);
	// bl 0x825e0b18
	ctx.lr = 0x82210F70;
	sub_825E0B18(ctx, base);
	// bl 0x825e08c8
	ctx.lr = 0x82210F74;
	sub_825E08C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82210fac
	if (!ctx.cr6.eq) goto loc_82210FAC;
	// lwz r11,-12672(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12672);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82210fc8
	if (ctx.cr6.eq) goto loc_82210FC8;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lis r3,-16381
	ctx.r3.s64 = -1073545216;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,3
	ctx.r3.u64 = ctx.r3.u64 | 3;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82210FA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82210fc8
	goto loc_82210FC8;
loc_82210FAC:
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
	// bne 0x82210fac
	if (!ctx.cr0.eq) goto loc_82210FAC;
loc_82210FC8:
	// bl 0x825e0828
	ctx.lr = 0x82210FCC;
	sub_825E0828(ctx, base);
	// bl 0x825e05e0
	ctx.lr = 0x82210FD0;
	sub_825E05E0(ctx, base);
	// bl 0x825e0550
	ctx.lr = 0x82210FD4;
	sub_825E0550(ctx, base);
	// bl 0x825e04c0
	ctx.lr = 0x82210FD8;
	sub_825E04C0(ctx, base);
	// bl 0x825e0430
	ctx.lr = 0x82210FDC;
	sub_825E0430(ctx, base);
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

DEFINE_REX_FUNC(sub_82227ED8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82227EE0;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82227f04
	if (!ctx.cr6.eq) goto loc_82227F04;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x82227f10
	goto loc_82227F10;
loc_82227F04:
	// lwz r11,12(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r8,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 3;
loc_82227F10:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lis r9,8191
	ctx.r9.s64 = 536805376;
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// ori r9,r9,65535
	ctx.r9.u64 = ctx.r9.u64 | 65535;
	// srawi r10,r10,3
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 3;
	// subf r7,r10,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// bge cr6,0x82227f78
	if (!ctx.cr6.lt) goto loc_82227F78;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,56
	ctx.r4.s64 = ctx.r11.s64 + 56;
	// bl 0x822167f8
	ctx.lr = 0x82227F40;
	sub_822167F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82216678
	ctx.lr = 0x82227F4C;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x82227F50;
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
	ctx.lr = 0x82227F64;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x82227F74;
	sub_8235EC48(ctx, base);
	// b 0x822281ec
	goto loc_822281EC;
loc_82227F78:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x822280b4
	if (!ctx.cr6.lt) goto loc_822280B4;
	// rlwinm r11,r8,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82227f9c
	if (!ctx.cr6.lt) goto loc_82227F9C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82227fa0
	goto loc_82227FA0;
loc_82227F9C:
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
loc_82227FA0:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82227fac
	if (!ctx.cr6.lt) goto loc_82227FAC;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_82227FAC:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// rlwinm r28,r11,3,0,28
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82227FC8;
	sub_825E02A0(ctx, base);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subf r11,r11,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srawi r9,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 3;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add. r11,r8,r3
	ctx.r11.u64 = ctx.r8.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82227ff4
	if (ctx.cr0.eq) goto loc_82227FF4;
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_82227FF4:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// b 0x82228020
	goto loc_82228020;
loc_82228000:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82228018
	if (ctx.cr6.eq) goto loc_82228018;
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
loc_82228018:
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
loc_82228020:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82228000
	if (!ctx.cr6.eq) goto loc_82228000;
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// lwz r9,8(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r30,r9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r9.u32, ctx.xer);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// beq cr6,0x82228078
	if (ctx.cr6.eq) goto loc_82228078;
	// subf r10,r8,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r8.u64;
	// subf r10,r31,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r31.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// addi r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -8;
loc_82228050:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82228068
	if (ctx.cr6.eq) goto loc_82228068;
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
loc_82228068:
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82228050
	if (!ctx.cr6.eq) goto loc_82228050;
loc_82228078:
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r11,r3,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r3.u64;
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x82228098
	if (ctx.cr6.eq) goto loc_82228098;
	// bl 0x825e0378
	ctx.lr = 0x82228098;
	sub_825E0378(ctx, base);
loc_82228098:
	// rlwinm r11,r30,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
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
	// b 0x822281ec
	goto loc_822281EC;
loc_822280B4:
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// srawi r10,r10,3
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 3;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bge cr6,0x82228160
	if (!ctx.cr6.lt) goto loc_82228160;
	// ld r8,0(r27)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r27.u32 + 0);
	// addi r10,r30,8
	ctx.r10.s64 = ctx.r30.s64 + 8;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82228100
	if (ctx.cr6.eq) goto loc_82228100;
	// addi r9,r10,-8
	ctx.r9.s64 = ctx.r10.s64 + -8;
loc_822280D8:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822280f0
	if (ctx.cr6.eq) goto loc_822280F0;
	// lwz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r7,4(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r7,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
loc_822280F0:
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x822280d8
	if (!ctx.cr6.eq) goto loc_822280D8;
loc_82228100:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// subf r10,r30,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r30.u64;
	// srawi r10,r10,3
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 3;
	// subfic r10,r10,1
	ctx.xer.ca = ctx.r10.u32 <= 1;
	ctx.r10.u64 = static_cast<uint64_t>(1) - ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82228130
	if (ctx.cr6.eq) goto loc_82228130;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8222811C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82228128
	if (ctx.cr6.eq) goto loc_82228128;
	// std r8,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r8.u64);
loc_82228128:
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bdnz 0x8222811c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8222811C;
loc_82228130:
	// lwz r10,8(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r9,r10,-8
	ctx.r9.s64 = ctx.r10.s64 + -8;
	// stw r10,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r10.u32);
	// cmplw cr6,r30,r9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x822281ec
	if (ctx.cr6.eq) goto loc_822281EC;
loc_8222814C:
	// std r8,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r8.u64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8222814c
	if (!ctx.cr6.eq) goto loc_8222814C;
	// b 0x822281ec
	goto loc_822281EC;
loc_82228160:
	// addi r9,r11,-8
	ctx.r9.s64 = ctx.r11.s64 + -8;
	// ld r7,0(r27)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r27.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x822281a0
	if (ctx.cr6.eq) goto loc_822281A0;
loc_82228178:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82228190
	if (ctx.cr6.eq) goto loc_82228190;
	// lwz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r6,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// lwz r6,4(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r6,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
loc_82228190:
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82228178
	if (!ctx.cr6.eq) goto loc_82228178;
loc_822281A0:
	// stw r10,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r10.u32);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// cmplw cr6,r30,r9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x822281cc
	if (ctx.cr6.eq) goto loc_822281CC;
	// addi r10,r9,8
	ctx.r10.s64 = ctx.r9.s64 + 8;
loc_822281B4:
	// lwzu r9,-8(r11)
	ea = -8 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// stwu r9,-8(r10)
	ea = -8 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// bne cr6,0x822281b4
	if (!ctx.cr6.eq) goto loc_822281B4;
loc_822281CC:
	// addi r10,r30,8
	ctx.r10.s64 = ctx.r30.s64 + 8;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x822281ec
	if (ctx.cr6.eq) goto loc_822281EC;
loc_822281DC:
	// std r7,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r7.u64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x822281dc
	if (!ctx.cr6.eq) goto loc_822281DC;
loc_822281EC:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82246710) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82246718;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 65536;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// addi r31,r31,-3100
	ctx.r31.s64 = ctx.r31.s64 + -3100;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,412(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 412);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82246740;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,40
	ctx.r11.s64 = 40;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// divw. r11,r10,r11
	ctx.r11.u64 = uint32_t((ctx.r11.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r10.s32 / ctx.r11.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822468e0
	if (ctx.cr0.eq) goto loc_822468E0;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,412(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 412);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224676C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,412(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 412);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224678C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r25,8(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r30,r25
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x822468e0
	if (ctx.cr6.eq) goto loc_822468E0;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r29,-32226
	ctx.r29.s64 = -2111963136;
	// lis r27,-32115
	ctx.r27.s64 = -2104688640;
	// lis r26,-32112
	ctx.r26.s64 = -2104492032;
	// lfs f31,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// addi r28,r11,22072
	ctx.r28.s64 = ctx.r11.s64 + 22072;
loc_822467B4:
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822468d4
	if (!ctx.cr6.eq) goto loc_822468D4;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 48);
	// li r4,92
	ctx.r4.s64 = 92;
	// bl 0x825e02a0
	ctx.lr = 0x822467D0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82246820
	if (ctx.cr0.eq) goto loc_82246820;
	// lfs f0,24(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x822467f0
	if (!ctx.cr6.lt) goto loc_822467F0;
	// lfs f0,-6772(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -6772);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,23848(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 23848);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
loc_822467F0:
	// lhz r11,6(r24)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r24.u32 + 6);
	// lfs f13,-8644(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -8644);
	ctx.f13.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x82225640
	ctx.lr = 0x82246818;
	sub_82225640(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82246824
	goto loc_82246824;
loc_82246820:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82246824:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822468d4
	if (ctx.cr6.eq) goto loc_822468D4;
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82246840
	if (!ctx.cr6.eq) goto loc_82246840;
	// rlwinm r11,r10,0,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
loc_82246840:
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// lfs f13,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,20(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,76(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ld r4,88(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82225838
	ctx.lr = 0x82246874;
	sub_82225838(ctx, base);
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82246884
	if (!ctx.cr6.lt) goto loc_82246884;
	// li r11,3
	ctx.r11.s64 = 3;
loc_82246884:
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
	ctx.lr = 0x8224689C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x822468A8;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822468d0
	if (!ctx.cr6.eq) goto loc_822468D0;
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
	ctx.lr = 0x822468CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x822468d4
	goto loc_822468D4;
loc_822468D0:
	// stw r11,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r11.u32);
loc_822468D4:
	// addi r30,r30,40
	ctx.r30.s64 = ctx.r30.s64 + 40;
	// cmplw cr6,r30,r25
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r25.u32, ctx.xer);
	// bne cr6,0x822467b4
	if (!ctx.cr6.eq) goto loc_822467B4;
loc_822468E0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82253100) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82253108;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
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
	// addi r30,r30,-3032
	ctx.r30.s64 = ctx.r30.s64 + -3032;
	// li r29,1
	ctx.r29.s64 = 1;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82253160
	if (ctx.cr0.eq) goto loc_82253160;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ld r10,88(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 88);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// ori r11,r11,62582
	ctx.r11.u64 = ctx.r11.u64 | 62582;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r9,5708
	ctx.r3.s64 = ctx.r9.s64 + 5708;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// stbx r29,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r29.u8);
	// bl 0x8257d4d8
	ctx.lr = 0x82253158;
	sub_8257D4D8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r11.u8);
loc_82253160:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,12468
	ctx.r10.s64 = ctx.r10.s64 + 12468;
	// addi r11,r11,-3060
	ctx.r11.s64 = ctx.r11.s64 + -3060;
	// lfs f13,-232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8225318c
	if (!ctx.cr6.lt) goto loc_8225318C;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x822531bc
	goto loc_822531BC;
loc_8225318C:
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r9,r9,-3040
	ctx.r9.s64 = ctx.r9.s64 + -3040;
	// stb r29,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r29.u8);
	// lis r11,-32219
	ctx.r11.s64 = -2111504384;
	// ori r10,r10,62500
	ctx.r10.u64 = ctx.r10.u64 | 62500;
	// addi r11,r11,12744
	ctx.r11.s64 = ctx.r11.s64 + 12744;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stw r11,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stwx r8,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u32);
loc_822531BC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8225F630) {
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
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f0,88(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r31,r1,96
	ctx.r31.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
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
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
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
	// lvx128 v62,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,92(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 92);
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
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
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
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8222ff08
	ctx.lr = 0x8225F6F0;
	sub_8222FF08(ctx, base);
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

DEFINE_REX_FUNC(sub_8226EC58) {
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
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f2,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f2,108(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f2,104(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f1,84(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f1,92(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f1,88(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8222ff08
	ctx.lr = 0x8226ECC4;
	sub_8222FF08(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82273630) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82273638;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r24,r3,1
	ctx.r24.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r24,r24,-3160
	ctx.r24.s64 = ctx.r24.s64 + -3160;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82273d34
	if (ctx.cr6.lt) goto loc_82273D34;
	// beq cr6,0x822739f8
	if (ctx.cr6.eq) goto loc_822739F8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8227392c
	if (ctx.cr6.lt) goto loc_8227392C;
	// beq cr6,0x822738ac
	if (ctx.cr6.eq) goto loc_822738AC;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x82273788
	if (ctx.cr6.lt) goto loc_82273788;
	// beq cr6,0x82273744
	if (ctx.cr6.eq) goto loc_82273744;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bge cr6,0x82273d58
	if (!ctx.cr6.lt) goto loc_82273D58;
	// li r5,0
	ctx.r5.s64 = 0;
	// addis r7,r3,1
	ctx.r7.s64 = ctx.r3.s64 + 65536;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// addi r7,r7,-3116
	ctx.r7.s64 = ctx.r7.s64 + -3116;
loc_82273694:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x8227bb60
	ctx.lr = 0x8227369C;
	sub_8227BB60(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822736b8
	if (!ctx.cr0.eq) goto loc_822736B8;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,40
	ctx.r7.s64 = ctx.r7.s64 + 40;
	// cmplwi cr6,r8,3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 3, ctx.xer);
	// blt cr6,0x82273694
	if (ctx.cr6.lt) goto loc_82273694;
	// b 0x822736bc
	goto loc_822736BC;
loc_822736B8:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
loc_822736BC:
	// clrlwi. r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82273d58
	if (ctx.cr0.eq) goto loc_82273D58;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// ori r11,r11,63096
	ctx.r11.u64 = ctx.r11.u64 | 63096;
	// addi r30,r10,15180
	ctx.r30.s64 = ctx.r10.s64 + 15180;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stbx r5,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r5.u8);
	// lfs f1,-2944(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2944);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8226f4b8
	ctx.lr = 0x822736EC;
	sub_8226F4B8(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f1,-2712(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2712);
	ctx.f1.f64 = double(temp.f32);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,40(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// bl 0x8224a2a0
	ctx.lr = 0x8227370C;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x8224a2a0
	ctx.lr = 0x82273718;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x8224a2a0
	ctx.lr = 0x82273724;
	sub_8224A2A0(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,-3144
	ctx.r10.s64 = ctx.r10.s64 + -3144;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82273734:
	// lfs f0,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// stfsu f0,40(r10)
	ea = 40 + ctx.r10.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82273734
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82273734;
	// b 0x82273d58
	goto loc_82273D58;
loc_82273744:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// li r30,0
	ctx.r30.s64 = 0;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// cmplwi cr6,r30,3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 3, ctx.xer);
	// addi r29,r29,-3140
	ctx.r29.s64 = ctx.r29.s64 + -3140;
	// lfs f1,11948(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11948);
	ctx.f1.f64 = double(temp.f32);
	// bge cr6,0x82273770
	if (!ctx.cr6.lt) goto loc_82273770;
loc_82273760:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82276370
	ctx.lr = 0x82273770;
	sub_82276370(ctx, base);
loc_82273770:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,40
	ctx.r29.s64 = ctx.r29.s64 + 40;
	// cmplwi cr6,r30,3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 3, ctx.xer);
	// blt cr6,0x82273760
	if (ctx.cr6.lt) goto loc_82273760;
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x822739f0
	goto loc_822739F0;
loc_82273788:
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r7,r7,-2448
	ctx.r7.s64 = ctx.r7.s64 + -2448;
	// addi r8,r11,15180
	ctx.r8.s64 = ctx.r11.s64 + 15180;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,63172
	ctx.r11.u64 = ctx.r11.u64 | 63172;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lfs f0,-2944(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -2944);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,-12816(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
	// stfs f13,0(r7)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x822737f0
	if (!ctx.cr6.gt) goto loc_822737F0;
	// lwzx r6,r31,r11
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// lwz r10,172(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 172);
	// rlwinm r8,r6,4,12,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFF0;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x822737f0
	if (!ctx.cr6.eq) goto loc_822737F0;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822737f0
	if (ctx.cr6.eq) goto loc_822737F0;
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r8,412(r10)
	REX_STORE_U8(ctx.r10.u32 + 412, ctx.r8.u8);
loc_822737F0:
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f13,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r10,-30128
	ctx.r10.s64 = ctx.r10.s64 + -30128;
	// lfs f0,-2088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2088);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82273d58
	if (!ctx.cr6.gt) goto loc_82273D58;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lwz r10,172(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 172);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r9,r8,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8227383c
	if (!ctx.cr6.eq) goto loc_8227383C;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8227383c
	if (ctx.cr6.eq) goto loc_8227383C;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,384(r10)
	REX_STORE_U32(ctx.r10.u32 + 384, ctx.r9.u32);
loc_8227383C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// stw r9,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r9.u32);
	// addi r11,r11,-3023
	ctx.r11.s64 = ctx.r11.s64 + -3023;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8227385C:
	// stb r5,11(r11)
	REX_STORE_U8(ctx.r11.u32 + 11, ctx.r5.u8);
	// stbu r5,12(r11)
	ea = 12 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r5.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8227385c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8227385C;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r11,r11,-18424
	ctx.r11.s64 = ctx.r11.s64 + -18424;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,40(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// lfs f1,-21084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21084);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8224a2a0
	ctx.lr = 0x82273890;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x8224a2a0
	ctx.lr = 0x8227389C;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x8224a2a0
	ctx.lr = 0x822738A8;
	sub_8224A2A0(ctx, base);
	// b 0x82273d58
	goto loc_82273D58;
loc_822738AC:
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r8,r8,-2364
	ctx.r8.s64 = ctx.r8.s64 + -2364;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,15180
	ctx.r9.s64 = ctx.r11.s64 + 15180;
	// ori r10,r10,63088
	ctx.r10.u64 = ctx.r10.u64 | 63088;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r7,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r7.u32);
	// lfs f0,-2712(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2712);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// beq cr6,0x8227391c
	if (ctx.cr6.eq) goto loc_8227391C;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,-12816(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82273914
	if (!ctx.cr6.eq) goto loc_82273914;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82273914
	if (ctx.cr6.eq) goto loc_82273914;
	// stb r28,23(r11)
	REX_STORE_U8(ctx.r11.u32 + 23, ctx.r28.u8);
loc_82273914:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
loc_8227391C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,63280
	ctx.r11.u64 = ctx.r11.u64 | 63280;
	// stbx r28,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r28.u8);
	// b 0x82273d58
	goto loc_82273D58;
loc_8227392C:
	// li r28,1
	ctx.r28.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// addi r7,r7,-3116
	ctx.r7.s64 = ctx.r7.s64 + -3116;
loc_82273944:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x8227bb60
	ctx.lr = 0x8227394C;
	sub_8227BB60(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82273968
	if (!ctx.cr0.eq) goto loc_82273968;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,40
	ctx.r7.s64 = ctx.r7.s64 + 40;
	// cmplwi cr6,r8,3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 3, ctx.xer);
	// blt cr6,0x82273944
	if (ctx.cr6.lt) goto loc_82273944;
	// b 0x8227396c
	goto loc_8227396C;
loc_82273968:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
loc_8227396C:
	// clrlwi. r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82273d58
	if (ctx.cr0.eq) goto loc_82273D58;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r11,r11,32432
	ctx.r11.s64 = ctx.r11.s64 + 32432;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r9,32720
	ctx.r9.s64 = ctx.r9.s64 + 32720;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r30,-3032
	ctx.r30.s64 = ctx.r30.s64 + -3032;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r4,-3132
	ctx.r4.s64 = ctx.r4.s64 + -3132;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,3
	ctx.r29.s64 = 3;
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
loc_822739C0:
	// stb r28,20(r30)
	REX_STORE_U8(ctx.r30.u32 + 20, ctx.r28.u8);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8255f918
	ctx.lr = 0x822739D0;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r4,r4,40
	ctx.r4.s64 = ctx.r4.s64 + 40;
	// stwu r11,12(r30)
	ea = 12 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r30.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// bne 0x822739c0
	if (!ctx.cr0.eq) goto loc_822739C0;
	// li r11,3
	ctx.r11.s64 = 3;
loc_822739F0:
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// b 0x82273d58
	goto loc_82273D58;
loc_822739F8:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r27,r11,-29492
	ctx.r27.s64 = ctx.r11.s64 + -29492;
	// addi r26,r10,15180
	ctx.r26.s64 = ctx.r10.s64 + 15180;
	// lfs f2,-15976(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -15976);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-2712(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -2712);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82273A18;
	sub_825A4A40(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r25,r31,88
	ctx.r25.s64 = ctx.r31.s64 + 88;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lfs f0,-18424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18424);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// addi r30,r11,32720
	ctx.r30.s64 = ctx.r11.s64 + 32720;
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bge cr6,0x82273b50
	if (!ctx.cr6.lt) goto loc_82273B50;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r29,r11,32464
	ctx.r29.s64 = ctx.r11.s64 + 32464;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
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
	// bl 0x8255f918
	ctx.lr = 0x82273A74;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r10,r10,-29776
	ctx.r10.s64 = ctx.r10.s64 + -29776;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// bl 0x8221ada0
	ctx.lr = 0x82273A94;
	sub_8221ADA0(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,232
	ctx.r3.s64 = ctx.r1.s64 + 232;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x823bcf40
	ctx.lr = 0x82273ACC;
	sub_823BCF40(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,248
	ctx.r3.s64 = ctx.r1.s64 + 248;
	// bl 0x8255f918
	ctx.lr = 0x82273ADC;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// addi r10,r10,-29792
	ctx.r10.s64 = ctx.r10.s64 + -29792;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r11.u64);
	// bl 0x8221ada0
	ctx.lr = 0x82273AFC;
	sub_8221ADA0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r5,24
	ctx.r5.s64 = 24;
	// bl 0x8273a030
	ctx.lr = 0x82273B0C;
	sub_8273A030(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x823bcf40
	ctx.lr = 0x82273B44;
	sub_823BCF40(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// b 0x82273c5c
	goto loc_82273C5C;
loc_82273B50:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r29,r10,-31456
	ctx.r29.s64 = ctx.r10.s64 + -31456;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,264
	ctx.r3.s64 = ctx.r1.s64 + 264;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82273B84;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r10,r10,-29792
	ctx.r10.s64 = ctx.r10.s64 + -29792;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r11.u64);
	// bl 0x8221ada0
	ctx.lr = 0x82273BA4;
	sub_8221ADA0(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x823bcf40
	ctx.lr = 0x82273BDC;
	sub_823BCF40(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x8255f918
	ctx.lr = 0x82273BEC;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// addi r10,r10,-29776
	ctx.r10.s64 = ctx.r10.s64 + -29776;
	// ld r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// bl 0x8221ada0
	ctx.lr = 0x82273C0C;
	sub_8221ADA0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// li r5,24
	ctx.r5.s64 = 24;
	// bl 0x8273a030
	ctx.lr = 0x82273C1C;
	sub_8273A030(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x823bcf40
	ctx.lr = 0x82273C54;
	sub_823BCF40(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
loc_82273C5C:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// bl 0x8255f918
	ctx.lr = 0x82273C64;
	sub_8255F918(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lfs f8,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// lfs f1,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// addi r29,r1,128
	ctx.r29.s64 = ctx.r1.s64 + 128;
	// addi r28,r28,-3144
	ctx.r28.s64 = ctx.r28.s64 + -3144;
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// cmplwi cr6,r30,3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 3, ctx.xer);
	// addi r27,r11,-30128
	ctx.r27.s64 = ctx.r11.s64 + -30128;
	// lfs f9,21484(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 21484);
	ctx.f9.f64 = double(temp.f32);
	// bge cr6,0x82273ca8
	if (!ctx.cr6.lt) goto loc_82273CA8;
loc_82273C98:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82276370
	ctx.lr = 0x82273CA8;
	sub_82276370(ctx, base);
loc_82273CA8:
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lfs f0,40(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// cmplwi cr6,r30,3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 3, ctx.xer);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmadds f13,f13,f9,f8
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f9.f64, ctx.f8.f64)));
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfsu f0,40(r28)
	ea = 40 + ctx.r28.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r28.u32 = ea;
	// blt cr6,0x82273c98
	if (ctx.cr6.lt) goto loc_82273C98;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f1,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,40(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// bl 0x8224a2a0
	ctx.lr = 0x82273D00;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x8224a2a0
	ctx.lr = 0x82273D0C;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x8224a2a0
	ctx.lr = 0x82273D18;
	sub_8224A2A0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r10,7564
	ctx.r3.s64 = ctx.r10.s64 + 7564;
	// bl 0x8257d4d8
	ctx.lr = 0x82273D30;
	sub_8257D4D8(ctx, base);
	// b 0x82273d58
	goto loc_82273D58;
loc_82273D34:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,15180
	ctx.r11.s64 = ctx.r11.s64 + 15180;
	// ori r10,r10,63096
	ctx.r10.u64 = ctx.r10.u64 | 63096;
	// li r28,1
	ctx.r28.s64 = 1;
	// lfs f0,-2712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2712);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// stw r28,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r28.u32);
	// stbx r28,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r28.u8);
loc_82273D58:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82276778
	ctx.lr = 0x82273D64;
	sub_82276778(ctx, base);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822B62C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x822B62D0;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// li r29,-1
	ctx.r29.s64 = -1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r29,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r29.u32);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822B62FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,-17036(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17036);
	ctx.f0.f64 = double(temp.f32);
	// lbz r11,99(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 99);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x822b64e8
	if (ctx.cr6.lt) goto loc_822B64E8;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x822b6340
	if (!ctx.cr6.eq) goto loc_822B6340;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82235988
	ctx.lr = 0x822B633C;
	sub_82235988(ctx, base);
	// b 0x822b64e8
	goto loc_822B64E8;
loc_822B6340:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8222ff78
	ctx.lr = 0x822B6354;
	sub_8222FF78(ctx, base);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r9,32544
	ctx.r9.s64 = ctx.r9.s64 + 32544;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f13,104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32225
	ctx.r6.s64 = -2111897600;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r6,32496
	ctx.r10.s64 = ctx.r6.s64 + 32496;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r28,r1,128
	ctx.r28.s64 = ctx.r1.s64 + 128;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r27,-32226
	ctx.r27.s64 = -2111963136;
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stw r26,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r26.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r27,2688
	ctx.r11.s64 = ctx.r27.s64 + 2688;
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-13032(r5)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r5.u32 + -13032);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// vor128 v60,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// vor128 v58,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// vaddfp128 v63,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v59,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v60.u8));
	// stfs f13,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// vsubfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f13,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v57,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v58.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vaddfp128 v63,v63,v59
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stvx128 v58,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// vaddfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f11,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// std r11,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r11.u64);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// beq cr6,0x822b6498
	if (ctx.cr6.eq) goto loc_822B6498;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r5,108(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x823aefa8
	ctx.lr = 0x822B6494;
	sub_823AEFA8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_822B6498:
	// lfs f0,168(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,4(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lfs f1,520(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 520);
	ctx.f1.f64 = double(temp.f32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// beq cr6,0x822b64e4
	if (ctx.cr6.eq) goto loc_822B64E4;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r4,16384
	ctx.r4.s64 = 1073741824;
	// addi r10,r11,2880
	ctx.r10.s64 = ctx.r11.s64 + 2880;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823b0938
	ctx.lr = 0x822B64E0;
	sub_823B0938(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_822B64E4:
	// stw r11,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
loc_822B64E8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822C9D98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x822C9DA0;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,4440
	ctx.r4.s64 = ctx.r11.s64 + 4440;
	// bl 0x8222fa58
	ctx.lr = 0x822C9DB4;
	sub_8222FA58(ctx, base);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r28,r28,-3120
	ctx.r28.s64 = ctx.r28.s64 + -3120;
	// addi r11,r11,11480
	ctx.r11.s64 = ctx.r11.s64 + 11480;
	// li r29,-1
	ctx.r29.s64 = -1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// stw r29,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r29.u32);
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r30,r30,-3084
	ctx.r30.s64 = ctx.r30.s64 + -3084;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x822C9DF0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822c9dfc
	if (ctx.cr0.eq) goto loc_822C9DFC;
	// stw r3,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r3.u32);
loc_822C9DFC:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822c9e08
	if (ctx.cr0.eq) goto loc_822C9E08;
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_822C9E08:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r3,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r3.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// ori r10,r10,62372
	ctx.r10.u64 = ctx.r10.u64 | 62372;
	// ori r4,r4,62428
	ctx.r4.u64 = ctx.r4.u64 | 62428;
	// lfs f12,12472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lfs f0,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r9,r9,62376
	ctx.r9.u64 = ctx.r9.u64 | 62376;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// ori r8,r8,62380
	ctx.r8.u64 = ctx.r8.u64 | 62380;
	// stfsx f0,r31,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// ori r7,r7,62384
	ctx.r7.u64 = ctx.r7.u64 | 62384;
	// stwx r11,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u32);
	// ori r6,r6,62472
	ctx.r6.u64 = ctx.r6.u64 | 62472;
	// ori r5,r5,62388
	ctx.r5.u64 = ctx.r5.u64 | 62388;
	// lis r27,0
	ctx.r27.s64 = 0;
	// stwx r11,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u32);
	// lis r26,0
	ctx.r26.s64 = 0;
	// lis r25,-32226
	ctx.r25.s64 = -2111963136;
	// stbx r11,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u8);
	// ori r24,r3,62424
	ctx.r24.u64 = ctx.r3.u64 | 62424;
	// stbx r11,r31,r6
	REX_STORE_U8(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u8);
	// li r3,-1
	ctx.r3.s64 = -1;
	// ori r4,r27,62408
	ctx.r4.u64 = ctx.r27.u64 | 62408;
	// ori r10,r26,62412
	ctx.r10.u64 = ctx.r26.u64 | 62412;
	// stwx r3,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// li r23,1
	ctx.r23.s64 = 1;
	// lfs f13,-23056(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -23056);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stwx r23,r31,r5
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r23.u32);
	// stw r29,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r29.u32);
	// stfsx f13,r31,r24
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r24.u32, temp.u32);
	// stfsx f12,r31,r4
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// bl 0x82524ba8
	ctx.lr = 0x822C9EB8;
	sub_82524BA8(ctx, base);
	// bl 0x824ac198
	ctx.lr = 0x822C9EBC;
	sub_824AC198(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822CF788) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x822CF790;
	__savegprlr_26(ctx, base);
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r26,r3,1
	ctx.r26.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r26,r26,-3164
	ctx.r26.s64 = ctx.r26.s64 + -3164;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x822cfb60
	if (ctx.cr6.lt) goto loc_822CFB60;
	// beq cr6,0x822cfb54
	if (ctx.cr6.eq) goto loc_822CFB54;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x822cfb48
	if (ctx.cr6.lt) goto loc_822CFB48;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// blt cr6,0x822cfae0
	if (ctx.cr6.lt) goto loc_822CFAE0;
	// bne cr6,0x822cfb68
	if (!ctx.cr6.eq) goto loc_822CFB68;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addis r28,r3,1
	ctx.r28.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,-3128
	ctx.r11.s64 = ctx.r11.s64 + -3128;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r28,r28,-3156
	ctx.r28.s64 = ctx.r28.s64 + -3156;
	// addi r30,r30,-3152
	ctx.r30.s64 = ctx.r30.s64 + -3152;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r10,17092
	ctx.r29.s64 = ctx.r10.s64 + 17092;
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f1
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// lfs f0,2120(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2120);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f12,f1
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f1.f64));
	// lfs f30,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f30.f64 = double(temp.f32);
	// stfs f11,0(r28)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// stfs f12,0(r30)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x822cf84c
	if (!ctx.cr6.gt) goto loc_822CF84C;
	// stfs f30,0(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8222ff78
	ctx.lr = 0x822CF83C;
	sub_8222FF78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,56
	ctx.r3.s64 = 56;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8257d438
	ctx.lr = 0x822CF84C;
	sub_8257D438(ctx, base);
loc_822CF84C:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-5976(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -5976);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// addi r27,r11,-23084
	ctx.r27.s64 = ctx.r11.s64 + -23084;
	// ble cr6,0x822cfa38
	if (!ctx.cr6.gt) goto loc_822CFA38;
	// stfs f30,0(r30)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
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
	ctx.lr = 0x822CF880;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822cf8ac
	if (ctx.cr0.eq) goto loc_822CF8AC;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,25624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-3004(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -3004);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x8221d610
	ctx.lr = 0x822CF8A4;
	sub_8221D610(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x822cf8b0
	goto loc_822CF8B0;
loc_822CF8AC:
	// li r30,0
	ctx.r30.s64 = 0;
loc_822CF8B0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x822cfa38
	if (ctx.cr6.eq) goto loc_822CFA38;
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
	ctx.lr = 0x822CF8D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x822cf8e0
	if (!ctx.cr0.eq) goto loc_822CF8E0;
	// lfs f31,492(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 492);
	ctx.f31.f64 = double(temp.f32);
	// b 0x822cf8e4
	goto loc_822CF8E4;
loc_822CF8E0:
	// lfs f31,-27940(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -27940);
	ctx.f31.f64 = double(temp.f32);
loc_822CF8E4:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x8222ff78
	ctx.lr = 0x822CF8F8;
	sub_8222FF78(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
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
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
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
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x8222ff78
	ctx.lr = 0x822CF954;
	sub_8222FF78(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f2,-19276(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -19276);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-7616(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -7616);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822CF96C;
	sub_825A4A40(ctx, base);
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f2,29900(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 29900);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f1,-18372(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -18372);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822CF988;
	sub_825A4A40(ctx, base);
	// lfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822CF9AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,-7016(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -7016);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822CF9D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stfs f30,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f1,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f2,-20940(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20940);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822CF9E8;
	sub_825A4A40(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822CFA08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82222ad8
	ctx.lr = 0x822CFA14;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822cfa38
	if (!ctx.cr6.eq) goto loc_822CFA38;
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
	ctx.lr = 0x822CFA38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822CFA38:
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x822cfa8c
	if (!ctx.cr6.lt) goto loc_822CFA8C;
	// li r11,7
	ctx.r11.s64 = 7;
	// stfs f30,0(r28)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822CFA6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r11.u8);
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
	ctx.lr = 0x822CFA8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822CFA8C:
	// lfs f13,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,257
	ctx.r10.s64 = 16842752;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// ori r10,r10,256
	ctx.r10.u64 = ctx.r10.u64 | 256;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r7,r11,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,140(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 140);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r4,0(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// bctrl 
	ctx.lr = 0x822CFADC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x822cfb68
	goto loc_822CFB68;
loc_822CFAE0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822d0700
	ctx.lr = 0x822CFAE8;
	sub_822D0700(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62404
	ctx.r11.u64 = ctx.r11.u64 | 62404;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822cfb68
	if (ctx.cr0.eq) goto loc_822CFB68;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x822cfb18
	if (!ctx.cr6.eq) goto loc_822CFB18;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822d0158
	ctx.lr = 0x822CFB14;
	sub_822D0158(ctx, base);
	// b 0x822cfb68
	goto loc_822CFB68;
loc_822CFB18:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x822cfb30
	if (!ctx.cr6.eq) goto loc_822CFB30;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822d02b8
	ctx.lr = 0x822CFB2C;
	sub_822D02B8(ctx, base);
	// b 0x822cfb68
	goto loc_822CFB68;
loc_822CFB30:
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x822cfb68
	if (!ctx.cr6.eq) goto loc_822CFB68;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822d0438
	ctx.lr = 0x822CFB44;
	sub_822D0438(ctx, base);
	// b 0x822cfb68
	goto loc_822CFB68;
loc_822CFB48:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822cff60
	ctx.lr = 0x822CFB50;
	sub_822CFF60(ctx, base);
	// b 0x822cfb68
	goto loc_822CFB68;
loc_822CFB54:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822cfd78
	ctx.lr = 0x822CFB5C;
	sub_822CFD78(ctx, base);
	// b 0x822cfb68
	goto loc_822CFB68;
loc_822CFB60:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822cfb78
	ctx.lr = 0x822CFB68;
	sub_822CFB78(ctx, base);
loc_822CFB68:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822EFB00) {
	REX_FUNC_PROLOGUE();
	// clrlwi. r11,r4,31
	ctx.r11.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822efb3c
	if (ctx.cr0.eq) goto loc_822EFB3C;
	// lwz r11,4(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r10,452(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 452);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x822efb3c
	if (!ctx.cr6.eq) goto loc_822EFB3C;
	// addis r6,r3,1
	ctx.r6.s64 = ctx.r3.s64 + 65536;
	// addic. r6,r6,-2928
	ctx.xer.ca = ctx.r6.u32 > 2927;
	ctx.r6.s64 = ctx.r6.s64 + -2928;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// addi r7,r3,500
	ctx.r7.s64 = ctx.r3.s64 + 500;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// b 0x82236c80
	sub_82236C80(ctx, base);
	return;
loc_822EFB3C:
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

DEFINE_REX_FUNC(sub_822F22C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x822F22C8;
	__savegprlr_20(ctx, base);
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r22,r3,1
	ctx.r22.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r22,r22,-3148
	ctx.r22.s64 = ctx.r22.s64 + -3148;
	// ori r21,r11,62656
	ctx.r21.u64 = ctx.r11.u64 | 62656;
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r20,r10,62768
	ctx.r20.u64 = ctx.r10.u64 | 62768;
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x822f26e0
	if (ctx.cr6.lt) goto loc_822F26E0;
	// beq cr6,0x822f25f4
	if (ctx.cr6.eq) goto loc_822F25F4;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x822f23bc
	if (ctx.cr6.lt) goto loc_822F23BC;
	// bne cr6,0x822f2728
	if (!ctx.cr6.eq) goto loc_822F2728;
	// addis r28,r3,1
	ctx.r28.s64 = ctx.r3.s64 + 65536;
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r28,r28,-2668
	ctx.r28.s64 = ctx.r28.s64 + -2668;
	// li r27,20
	ctx.r27.s64 = 20;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_822F2320:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822f2348
	if (ctx.cr6.eq) goto loc_822F2348;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x822f70a8
	ctx.lr = 0x822F2334;
	sub_822F70A8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lbz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 40);
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 & ctx.r29.u64;
loc_822F2348:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x822f2320
	if (!ctx.cr0.eq) goto loc_822F2320;
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822f2728
	if (ctx.cr0.eq) goto loc_822F2728;
	// addi r30,r28,-4
	ctx.r30.s64 = ctx.r28.s64 + -4;
	// li r29,20
	ctx.r29.s64 = 20;
	// li r24,0
	ctx.r24.s64 = 0;
loc_822F2368:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822f2388
	if (ctx.cr6.eq) goto loc_822F2388;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822F2388;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822F2388:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stwu r24,4(r30)
	ea = 4 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r24.u32);
	ctx.r30.u32 = ea;
	// bne 0x822f2368
	if (!ctx.cr0.eq) goto loc_822F2368;
	// stb r24,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r24.u8);
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
	ctx.lr = 0x822F23B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,4
	ctx.r11.s64 = 4;
loc_822F23B4:
	// stw r11,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// b 0x822f2728
	goto loc_822F2728;
loc_822F23BC:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwzx r10,r31,r21
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r21.u32);
	// add r23,r31,r21
	ctx.r23.u64 = ctx.r31.u64 + ctx.r21.u64;
	// addi r11,r11,-3140
	ctx.r11.s64 = ctx.r11.s64 + -3140;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwz r10,72(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 72);
	// rlwinm. r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x822f25b0
	if (ctx.cr0.eq) goto loc_822F25B0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,62392
	ctx.r10.u64 = ctx.r10.u64 | 62392;
	// lwzx r10,r31,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r10,21
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 21, ctx.xer);
	// bne cr6,0x822f25b0
	if (!ctx.cr6.eq) goto loc_822F25B0;
	// li r24,0
	ctx.r24.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
loc_822F2400:
	// lwz r3,0(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x822f242c
	if (!ctx.cr6.eq) goto loc_822F242C;
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// lbz r11,38(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 38);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x822f242c
	if (!ctx.cr6.lt) goto loc_822F242C;
	// bl 0x823bae28
	ctx.lr = 0x822F2424;
	sub_823BAE28(ctx, base);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x822f2400
	goto loc_822F2400;
loc_822F242C:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r11,r11,-22920
	ctx.r11.s64 = ctx.r11.s64 + -22920;
	// addi r8,r10,12468
	ctx.r8.s64 = ctx.r10.s64 + 12468;
	// addi r30,r11,-4
	ctx.r30.s64 = ctx.r11.s64 + -4;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lfs f31,3188(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 3188);
	ctx.f31.f64 = double(temp.f32);
	// addi r28,r28,-2672
	ctx.r28.s64 = ctx.r28.s64 + -2672;
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
	// addi r26,r11,-31776
	ctx.r26.s64 = ctx.r11.s64 + -31776;
	// addi r29,r10,32720
	ctx.r29.s64 = ctx.r10.s64 + 32720;
	// addi r25,r9,22072
	ctx.r25.s64 = ctx.r9.s64 + 22072;
loc_822F2468:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 44);
	// li r4,60
	ctx.r4.s64 = 60;
	// bl 0x825e02a0
	ctx.lr = 0x822F2478;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822f24a8
	if (ctx.cr0.eq) goto loc_822F24A8;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r5,8(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,204(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 204);
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// bl 0x822f6f08
	ctx.lr = 0x822F24A4;
	sub_822F6F08(ctx, base);
	// b 0x822f24ac
	goto loc_822F24AC;
loc_822F24A8:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
loc_822F24AC:
	// stw r3,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822f2588
	if (ctx.cr6.eq) goto loc_822F2588;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lvx128 v62,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// addi r27,r27,12
	ctx.r27.s64 = ctx.r27.s64 + 12;
	// stvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f11.f64 = double(temp.f32);
	// cmplwi cr6,r27,240
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 240, ctx.xer);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,20(r3)
	REX_STORE_U64(ctx.r3.u32 + 20, ctx.r11.u64);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,28(r11)
	REX_STORE_U64(ctx.r11.u32 + 28, ctx.r10.u64);
	// lwzu r10,4(r28)
	ea = 4 + ctx.r28.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r28.u32 = ea;
	// lbzu r11,12(r30)
	ea = 12 + ctx.r30.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r30.u32 = ea;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f0,48(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 48, temp.u32);
	// blt cr6,0x822f2468
	if (ctx.cr6.lt) goto loc_822F2468;
	// ld r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 88);
	// li r3,167
	ctx.r3.s64 = 167;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f13,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82240a58
	ctx.lr = 0x822F2580;
	sub_82240A58(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x822f23b4
	goto loc_822F23B4;
loc_822F2588:
	// stb r24,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r24.u8);
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
	ctx.lr = 0x822F25A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// b 0x822f27d0
	goto loc_822F27D0;
loc_822F25B0:
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r10,r10,12468
	ctx.r10.s64 = ctx.r10.s64 + 12468;
	// lfs f13,1812(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1812);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x822f2728
	if (!ctx.cr6.gt) goto loc_822F2728;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8222ff78
	ctx.lr = 0x822F25E0;
	sub_8222FF78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,171
	ctx.r3.s64 = 171;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8257d438
	ctx.lr = 0x822F25F0;
	sub_8257D438(ctx, base);
	// b 0x822f2728
	goto loc_822F2728;
loc_822F25F4:
	// lwzx r30,r31,r21
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r21.u32);
	// lwz r11,88(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x822f2608
	if (ctx.cr6.gt) goto loc_822F2608;
	// lwz r11,136(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
loc_822F2608:
	// lwz r10,72(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 72);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm. r10,r10,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x822f2624
	if (ctx.cr0.eq) goto loc_822F2624;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x822f2628
	if (ctx.cr6.eq) goto loc_822F2628;
loc_822F2624:
	// li r11,0
	ctx.r11.s64 = 0;
loc_822F2628:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822f2728
	if (ctx.cr0.eq) goto loc_822F2728;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823babd0
	ctx.lr = 0x822F2640;
	sub_823BABD0(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lfs f0,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,204(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,4(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// lwz r7,24(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 24);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f1,56(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 56);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f6900
	ctx.lr = 0x822F26B8;
	sub_822F6900(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// ori r11,r11,62396
	ctx.r11.u64 = ctx.r11.u64 | 62396;
	// li r8,2
	ctx.r8.s64 = 2;
	// lfs f0,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stwx r10,r31,r20
	REX_STORE_U32(ctx.r31.u32 + ctx.r20.u32, ctx.r10.u32);
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stw r8,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r8.u32);
	// b 0x822f2728
	goto loc_822F2728;
loc_822F26E0:
	// lwzx r11,r31,r21
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r21.u32);
	// li r24,0
	ctx.r24.s64 = 0;
	// li r9,96
	ctx.r9.s64 = 96;
	// li r8,7
	ctx.r8.s64 = 7;
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
	// stw r24,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r24.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r9.u32);
	// stb r24,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r24.u8);
	// stw r8,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
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
	// stw r7,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r7.u32);
loc_822F2728:
	// lwzx r11,r31,r20
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r20.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x822f27d0
	if (ctx.cr6.eq) goto loc_822F27D0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x822F2740;
	sub_82222D88(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x822f27d0
	if (ctx.cr0.eq) goto loc_822F27D0;
	// lwzx r31,r31,r21
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r21.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823babd0
	ctx.lr = 0x822F275C;
	sub_823BABD0(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lwz r7,204(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f0,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r7,4(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r7,24(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 24);
	// lfs f1,56(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 56);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x822f6d80
	ctx.lr = 0x822F27D0;
	sub_822F6D80(ctx, base);
loc_822F27D0:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82314210) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82314218;
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
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// ori r11,r11,62392
	ctx.r11.u64 = ctx.r11.u64 | 62392;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x823143ac
	if (!ctx.cr6.eq) goto loc_823143AC;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,-3124
	ctx.r11.s64 = ctx.r11.s64 + -3124;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x823143ac
	if (ctx.cr0.eq) goto loc_823143AC;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// stb r28,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82314270;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r29,r11,12468
	ctx.r29.s64 = ctx.r11.s64 + 12468;
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lfs f30,-232(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -232);
	ctx.f30.f64 = double(temp.f32);
	// bne 0x8231428c
	if (!ctx.cr0.eq) goto loc_8231428C;
	// lfs f31,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// b 0x82314290
	goto loc_82314290;
loc_8231428C:
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f30.f64;
loc_82314290:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,308
	ctx.r4.s64 = 308;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x823142A8;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82314300
	if (ctx.cr0.eq) goto loc_82314300;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r5,4(r27)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,4188
	ctx.r4.s64 = ctx.r11.s64 + 4188;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824689b0
	ctx.lr = 0x823142C8;
	sub_824689B0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-17656
	ctx.r11.s64 = ctx.r11.s64 + -17656;
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stw r28,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r28.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r30,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r30.u32);
	// stw r30,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r30.u32);
	// stw r10,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r10.u32);
	// stfs f30,304(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stb r28,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r28.u8);
	// b 0x82314304
	goto loc_82314304;
loc_82314300:
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
loc_82314304:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823143ac
	if (ctx.cr6.eq) goto loc_823143AC;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,-29492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r10,-29680
	ctx.r10.s64 = ctx.r10.s64 + -29680;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
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
	// bl 0x8222ff78
	ctx.lr = 0x82314370;
	sub_8222FF78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x82314380;
	sub_8255F918(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,16384
	ctx.r10.s64 = 1073741824;
	// ori r10,r10,257
	ctx.r10.u64 = ctx.r10.u64 | 257;
	// stw r9,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// lfs f0,-32216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32216);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f0,196(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 196, temp.u32);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// stb r28,186(r31)
	REX_STORE_U8(ctx.r31.u32 + 186, ctx.r28.u8);
	// stw r10,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
loc_823143AC:
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

DEFINE_REX_FUNC(sub_82324F00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x82324F08;
	__savegprlr_18(ctx, base);
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8273af28
	ctx.lr = 0x82324F10;
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
	// bl 0x822301e0
	ctx.lr = 0x82324F28;
	sub_822301E0(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r20,r11,11948
	ctx.r20.s64 = ctx.r11.s64 + 11948;
	// beq 0x82324ff0
	if (ctx.cr0.eq) goto loc_82324FF0;
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// lfs f0,5336(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5336);
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_82324FF0:
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
	ctx.lr = 0x82325020;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addis r21,r31,1
	ctx.r21.s64 = ctx.r31.s64 + 65536;
	// addi r25,r11,15180
	ctx.r25.s64 = ctx.r11.s64 + 15180;
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
	// bne 0x82325048
	if (!ctx.cr0.eq) goto loc_82325048;
	// lfs f0,-2708(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2708);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r21)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r21.u32 + 0, temp.u32);
loc_82325048:
	// addis r18,r31,1
	ctx.r18.s64 = ctx.r31.s64 + 65536;
	// addi r18,r18,-3164
	ctx.r18.s64 = ctx.r18.s64 + -3164;
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x82326c14
	if (ctx.cr6.gt) goto loc_82326C14;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// rlwinm r0,r11,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r12,r12,-5208
	ctx.r12.s64 = ctx.r12.s64 + -5208;
	// lhzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32206
	ctx.r12.s64 = -2110652416;
	// addi r12,r12,20612
	ctx.r12.s64 = ctx.r12.s64 + 20612;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82325084;
	case 1:
		goto loc_8232512C;
	case 2:
		goto loc_823251A0;
	case 3:
		goto loc_82325890;
	case 4:
		goto loc_82326188;
	case 5:
		goto loc_82326578;
	case 6:
		goto loc_823266E0;
	case 7:
		goto loc_82326788;
	case 8:
		goto loc_82326C14;
	case 9:
		goto loc_82326888;
	case 10:
		goto loc_82326AE8;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82325084:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stw r11,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r4,124
	ctx.r4.s64 = 124;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x823250A4;
	sub_825E02A0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x823250dc
	if (ctx.cr0.eq) goto loc_823250DC;
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
	ctx.lr = 0x823250C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lfs f1,-23068(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -23068);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822409f8
	ctx.lr = 0x823250D4;
	sub_822409F8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x823250e0
	goto loc_823250E0;
loc_823250DC:
	// li r30,0
	ctx.r30.s64 = 0;
loc_823250E0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82326c14
	if (ctx.cr6.eq) goto loc_82326C14;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// bl 0x82222ad8
	ctx.lr = 0x823250F4;
	sub_82222AD8(ctx, base);
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
	// bne cr6,0x82326c14
	if (!ctx.cr6.eq) goto loc_82326C14;
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
	ctx.lr = 0x82325128;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82326c14
	goto loc_82326C14;
loc_8232512C:
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
	// bl 0x8222ff78
	ctx.lr = 0x82325148;
	sub_8222FF78(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f2,-10460(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -10460);
	ctx.f2.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// addi r11,r11,-9856
	ctx.r11.s64 = ctx.r11.s64 + -9856;
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f4,-25496(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25496);
	ctx.f4.f64 = double(temp.f32);
	// fmr f3,f4
	ctx.f3.f64 = ctx.f4.f64;
	// bl 0x8223ef20
	ctx.lr = 0x8232516C;
	sub_8223EF20(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82326c14
	if (ctx.cr0.eq) goto loc_82326C14;
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
	// bl 0x8224a2a0
	ctx.lr = 0x8232519C;
	sub_8224A2A0(ctx, base);
	// b 0x82326c14
	goto loc_82326C14;
loc_823251A0:
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
	// bl 0x8222ff78
	ctx.lr = 0x823251D4;
	sub_8222FF78(ctx, base);
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
	// addi r10,r10,-31664
	ctx.r10.s64 = ctx.r10.s64 + -31664;
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x82325254
	if (ctx.cr0.eq) goto loc_82325254;
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// b 0x82325258
	goto loc_82325258;
loc_82325254:
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
loc_82325258:
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// bl 0x8222ff78
	ctx.lr = 0x82325278;
	sub_8222FF78(ctx, base);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,536
	ctx.r3.s64 = ctx.r1.s64 + 536;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// bl 0x8222ff78
	ctx.lr = 0x823252C0;
	sub_8222FF78(ctx, base);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// bl 0x822301e0
	ctx.lr = 0x8232537C;
	sub_822301E0(ctx, base);
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
	// bne 0x82325524
	if (!ctx.cr0.eq) goto loc_82325524;
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-92(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -92);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fsqrts f0,f0
	ctx.f0.f64 = double(float(sqrt(ctx.f0.f64)));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82325474
	if (!ctx.cr6.gt) goto loc_82325474;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// b 0x82325514
	goto loc_82325514;
loc_82325474:
	// lfs f13,-2944(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2944);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82325520
	if (!ctx.cr6.gt) goto loc_82325520;
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
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_82325514:
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// b 0x82325524
	goto loc_82325524;
loc_82325520:
	// stfs f28,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
loc_82325524:
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
	// ble cr6,0x82325544
	if (!ctx.cr6.gt) goto loc_82325544;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// ble cr6,0x82325554
	if (!ctx.cr6.gt) goto loc_82325554;
loc_82325544:
	// cmpwi cr6,r11,43
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 43, ctx.xer);
	// ble cr6,0x8232555c
	if (!ctx.cr6.gt) goto loc_8232555C;
	// cmpwi cr6,r11,60
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 60, ctx.xer);
	// bgt cr6,0x8232555c
	if (ctx.cr6.gt) goto loc_8232555C;
loc_82325554:
	// stfsx f28,r31,r27
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
	// b 0x8232556c
	goto loc_8232556C;
loc_8232555C:
	// lfsx f13,r31,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,268(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 268);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f29,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfsx f0,r31,r27
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
loc_8232556C:
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
	// bne 0x8232558c
	if (!ctx.cr0.eq) goto loc_8232558C;
	// stbx r28,r31,r30
	REX_STORE_U8(ctx.r31.u32 + ctx.r30.u32, ctx.r28.u8);
loc_8232558C:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// ble cr6,0x82325868
	if (!ctx.cr6.gt) goto loc_82325868;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x82325868
	if (ctx.cr6.gt) goto loc_82325868;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232918
	ctx.lr = 0x823255A8;
	sub_82232918(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8231e0d8
	ctx.lr = 0x823255B4;
	sub_8231E0D8(ctx, base);
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
	// bne 0x82325868
	if (!ctx.cr0.eq) goto loc_82325868;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,552
	ctx.r3.s64 = ctx.r1.s64 + 552;
	// bl 0x8222ff78
	ctx.lr = 0x823255EC;
	sub_8222FF78(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f2,-10460(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -10460);
	ctx.f2.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// addi r30,r11,-9856
	ctx.r30.s64 = ctx.r11.s64 + -9856;
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f4,-25496(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -25496);
	ctx.f4.f64 = double(temp.f32);
	// fmr f3,f4
	ctx.f3.f64 = ctx.f4.f64;
	// bl 0x8223ef20
	ctx.lr = 0x82325610;
	sub_8223EF20(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82325868
	if (ctx.cr0.eq) goto loc_82325868;
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
	// ble cr6,0x82325630
	if (!ctx.cr6.gt) goto loc_82325630;
	// fmr f30,f13
	ctx.f30.f64 = ctx.f13.f64;
loc_82325630:
	// fmr f31,f28
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f28.f64;
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bge cr6,0x82325640
	if (!ctx.cr6.lt) goto loc_82325640;
	// fmr f31,f13
	ctx.f31.f64 = ctx.f13.f64;
loc_82325640:
	// li r4,10000
	ctx.r4.s64 = 10000;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x82325650;
	sub_825A49B0(ctx, base);
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
	// bl 0x825a49b0
	ctx.lr = 0x82325674;
	sub_825A49B0(ctx, base);
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
	// bne cr6,0x823256e8
	if (!ctx.cr6.eq) goto loc_823256E8;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne cr6,0x823256e8
	if (!ctx.cr6.eq) goto loc_823256E8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x8222ff78
	ctx.lr = 0x823256A8;
	sub_8222FF78(ctx, base);
	// lfs f0,-22232(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -22232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,5144(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5144);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,5112(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5112);
	ctx.f2.f64 = double(temp.f32);
	// lfs f4,5336(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5336);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fmuls f3,f30,f13
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// bl 0x8223ef20
	ctx.lr = 0x823256CC;
	sub_8223EF20(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823256e8
	if (ctx.cr0.eq) goto loc_823256E8;
	// li r9,4
	ctx.r9.s64 = 4;
loc_823256D8:
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r9,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r9.u32);
	// stb r8,0(r24)
	REX_STORE_U8(ctx.r24.u32 + 0, ctx.r8.u8);
	// b 0x8232584c
	goto loc_8232584C;
loc_823256E8:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822301e0
	ctx.lr = 0x823256F8;
	sub_822301E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82325868
	if (!ctx.cr6.eq) goto loc_82325868;
	// bne 0x82325754
	if (!ctx.cr0.eq) goto loc_82325754;
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// bne cr6,0x82325754
	if (!ctx.cr6.eq) goto loc_82325754;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// bl 0x8222ff78
	ctx.lr = 0x82325724;
	sub_8222FF78(ctx, base);
	// lfs f4,5144(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5144);
	ctx.f4.f64 = double(temp.f32);
	// lfs f0,-22232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -22232);
	ctx.f0.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,-10460(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -10460);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f3,f30,f4
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f4.f64));
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// bl 0x8223ef20
	ctx.lr = 0x82325744;
	sub_8223EF20(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82325868
	if (ctx.cr0.eq) goto loc_82325868;
	// stw r26,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r26.u32);
	// b 0x82325844
	goto loc_82325844;
loc_82325754:
	// cmpwi cr6,r27,2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 2, ctx.xer);
	// bne cr6,0x823257a4
	if (!ctx.cr6.eq) goto loc_823257A4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x8222ff78
	ctx.lr = 0x82325770;
	sub_8222FF78(ctx, base);
	// lfs f0,24276(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 24276);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24232(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 24232);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,-22232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -22232);
	ctx.f2.f64 = double(temp.f32);
	// lfs f4,5144(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5144);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fmuls f3,f30,f13
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// bl 0x8223ef20
	ctx.lr = 0x82325794;
	sub_8223EF20(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82325868
	if (ctx.cr0.eq) goto loc_82325868;
	// li r9,6
	ctx.r9.s64 = 6;
	// b 0x823256d8
	goto loc_823256D8;
loc_823257A4:
	// cmpwi cr6,r27,3
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 3, ctx.xer);
	// bne cr6,0x823257f8
	if (!ctx.cr6.eq) goto loc_823257F8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x8222ff78
	ctx.lr = 0x823257C0;
	sub_8222FF78(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f13,5316(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5316);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,-22232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -22232);
	ctx.f2.f64 = double(temp.f32);
	// lfs f4,5144(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5144);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f30,f13
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// lfs f0,8492(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8492);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// bl 0x8223ef20
	ctx.lr = 0x823257E8;
	sub_8223EF20(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82325868
	if (ctx.cr0.eq) goto loc_82325868;
	// li r9,7
	ctx.r9.s64 = 7;
	// b 0x823256d8
	goto loc_823256D8;
loc_823257F8:
	// cmpwi cr6,r27,4
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4, ctx.xer);
	// bne cr6,0x82325868
	if (!ctx.cr6.eq) goto loc_82325868;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x8222ff78
	ctx.lr = 0x82325814;
	sub_8222FF78(ctx, base);
	// lfs f0,24204(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 24204);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-13228(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -13228);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f2,-22232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -22232);
	ctx.f2.f64 = double(temp.f32);
	// lfs f4,5144(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5144);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fmuls f3,f30,f13
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// bl 0x8223ef20
	ctx.lr = 0x82325838;
	sub_8223EF20(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82325868
	if (ctx.cr0.eq) goto loc_82325868;
	// stw r21,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r21.u32);
loc_82325844:
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,0(r24)
	REX_STORE_U8(ctx.r24.u32 + 0, ctx.r9.u8);
loc_8232584C:
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
loc_82325868:
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
	// bl 0x82328450
	ctx.lr = 0x8232587C;
	sub_82328450(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82326c14
	if (!ctx.cr0.eq) goto loc_82326C14;
	// stfs f28,0(r19)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r19.u32 + 0, temp.u32);
	// stfs f28,0(r23)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r23.u32 + 0, temp.u32);
	// b 0x82326c14
	goto loc_82326C14;
loc_82325890:
	// addis r23,r31,1
	ctx.r23.s64 = ctx.r31.s64 + 65536;
	// addi r23,r23,-3096
	ctx.r23.s64 = ctx.r23.s64 + -3096;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82326148
	if (ctx.cr6.lt) goto loc_82326148;
	// beq cr6,0x82325f54
	if (ctx.cr6.eq) goto loc_82325F54;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82325dc4
	if (ctx.cr6.lt) goto loc_82325DC4;
	// bne cr6,0x82326c14
	if (!ctx.cr6.eq) goto loc_82326C14;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,544
	ctx.r3.s64 = ctx.r1.s64 + 544;
	// bl 0x8222ff78
	ctx.lr = 0x823258C8;
	sub_8222FF78(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x823258E4;
	sub_8222FF78(ctx, base);
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
	// beq cr6,0x8232592c
	if (ctx.cr6.eq) goto loc_8232592C;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82222d88
	ctx.lr = 0x82325910;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8232592c
	if (ctx.cr0.eq) goto loc_8232592C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,216
	ctx.r4.s64 = ctx.r1.s64 + 216;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8232592C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8232592C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822301e0
	ctx.lr = 0x8232593C;
	sub_822301E0(ctx, base);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
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
	// addi r29,r11,2880
	ctx.r29.s64 = ctx.r11.s64 + 2880;
	// bne 0x82325a00
	if (!ctx.cr0.eq) goto loc_82325A00;
	// lbzx r11,r31,r26
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r26.u32);
	// add r30,r31,r26
	ctx.r30.u64 = ctx.r31.u64 + ctx.r26.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823259cc
	if (!ctx.cr0.eq) goto loc_823259CC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x8222ff78
	ctx.lr = 0x82325984;
	sub_8222FF78(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x823259A0;
	sub_8222FF78(ctx, base);
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
	// bl 0x82240a58
	ctx.lr = 0x823259C8;
	sub_82240A58(ctx, base);
	// stb r24,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r24.u8);
loc_823259CC:
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
	// beq cr6,0x82325a00
	if (ctx.cr6.eq) goto loc_82325A00;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82222d88
	ctx.lr = 0x823259F0;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82325a00
	if (ctx.cr0.eq) goto loc_82325A00;
	// stb r28,84(r3)
	REX_STORE_U8(ctx.r3.u32 + 84, ctx.r28.u8);
	// stb r28,85(r3)
	REX_STORE_U8(ctx.r3.u32 + 85, ctx.r28.u8);
loc_82325A00:
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bgt cr6,0x82325a14
	if (ctx.cr6.gt) goto loc_82325A14;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x82325a1c
	goto loc_82325A1C;
loc_82325A14:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82230278
	ctx.lr = 0x82325A1C;
	sub_82230278(ctx, base);
loc_82325A1C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82325a7c
	if (ctx.cr0.eq) goto loc_82325A7C;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// ld r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r8,r8,32720
	ctx.r8.s64 = ctx.r8.s64 + 32720;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_82325A7C:
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82325b18
	if (ctx.cr0.eq) goto loc_82325B18;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// bne 0x82325b1c
	if (!ctx.cr0.eq) goto loc_82325B1C;
loc_82325B18:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_82325B1C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ori r29,r10,62460
	ctx.r29.u64 = ctx.r10.u64 | 62460;
	// beq 0x82325d44
	if (ctx.cr0.eq) goto loc_82325D44;
	// lwzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// add r30,r31,r29
	ctx.r30.u64 = ctx.r31.u64 + ctx.r29.u64;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bge cr6,0x82325d44
	if (!ctx.cr6.lt) goto loc_82325D44;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r11,-9856
	ctx.r11.s64 = ctx.r11.s64 + -9856;
	// lfs f31,-22360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22360);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,-20244(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20244);
	ctx.f30.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82325B5C;
	sub_825A4A40(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x82325B74;
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
	// addi r25,r10,-29200
	ctx.r25.s64 = ctx.r10.s64 + -29200;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x82325BBC;
	sub_8222FF78(ctx, base);
	// lfs f12,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,-3880(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -3880);
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lfs f29,-7508(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -7508);
	ctx.f29.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// bl 0x82326ce8
	ctx.lr = 0x82325C48;
	sub_82326CE8(ctx, base);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82325C58;
	sub_825A4A40(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x82325C70;
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
	// li r6,0
	ctx.r6.s64 = 0;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x82325CB0;
	sub_8222FF78(ctx, base);
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
	// lfs f0,-20904(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -20904);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vaddfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// bl 0x82326ce8
	ctx.lr = 0x82325D38;
	sub_82326CE8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_82325D44:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r10,74(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 74);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82326c14
	if (!ctx.cr0.eq) goto loc_82326C14;
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
	// bl 0x8224a2a0
	ctx.lr = 0x82325D7C;
	sub_8224A2A0(ctx, base);
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
	// beq cr6,0x82326c14
	if (ctx.cr6.eq) goto loc_82326C14;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82222d88
	ctx.lr = 0x82325DB0;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82326c14
	if (ctx.cr0.eq) goto loc_82326C14;
	// stb r28,84(r3)
	REX_STORE_U8(ctx.r3.u32 + 84, ctx.r28.u8);
	// stb r28,85(r3)
	REX_STORE_U8(ctx.r3.u32 + 85, ctx.r28.u8);
	// b 0x82326c14
	goto loc_82326C14;
loc_82325DC4:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822301e0
	ctx.lr = 0x82325DD4;
	sub_822301E0(ctx, base);
	// lfs f31,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f31.f64 = double(temp.f32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r21,3
	ctx.r21.s64 = 3;
	// bne 0x82325e40
	if (!ctx.cr0.eq) goto loc_82325E40;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82325e24
	if (!ctx.cr6.lt) goto loc_82325E24;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82325E24:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82325e40
	if (ctx.cr0.eq) goto loc_82325E40;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// stfs f31,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// stw r21,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r21.u32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
loc_82325E40:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x8222ff78
	ctx.lr = 0x82325E54;
	sub_8222FF78(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x82325E70;
	sub_8222FF78(ctx, base);
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
	// beq cr6,0x82325eb0
	if (ctx.cr6.eq) goto loc_82325EB0;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82222d88
	ctx.lr = 0x82325E9C;
	sub_82222D88(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82325EB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82325EB0:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,74(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82326c14
	if (!ctx.cr0.eq) goto loc_82326C14;
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
	// bl 0x8224a2a0
	ctx.lr = 0x82325EDC;
	sub_8224A2A0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// bl 0x8222ff78
	ctx.lr = 0x82325EEC;
	sub_8222FF78(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x82325F08;
	sub_8222FF78(ctx, base);
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
	// bl 0x82240a58
	ctx.lr = 0x82325F30;
	sub_82240A58(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82325f4c
	if (ctx.cr6.eq) goto loc_82325F4C;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82222d88
	ctx.lr = 0x82325F48;
	sub_82222D88(ctx, base);
	// stw r21,112(r3)
	REX_STORE_U32(ctx.r3.u32 + 112, ctx.r21.u32);
loc_82325F4C:
	// stw r21,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r21.u32);
	// b 0x82326c14
	goto loc_82326C14;
loc_82325F54:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// bl 0x8222ff78
	ctx.lr = 0x82325F68;
	sub_8222FF78(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x8222ff78
	ctx.lr = 0x82325F7C;
	sub_8222FF78(ctx, base);
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
	// ble cr6,0x82326c14
	if (!ctx.cr6.gt) goto loc_82326C14;
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
	// bl 0x8222ff78
	ctx.lr = 0x82325FB8;
	sub_8222FF78(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x82325FD4;
	sub_8222FF78(ctx, base);
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
	// beq cr6,0x82326090
	if (ctx.cr6.eq) goto loc_82326090;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82222d88
	ctx.lr = 0x82326004;
	sub_82222D88(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82326090
	if (ctx.cr0.eq) goto loc_82326090;
	// stw r29,112(r30)
	REX_STORE_U32(ctx.r30.u32 + 112, ctx.r29.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 412);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f13,27288(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27288);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82326038;
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
	ctx.lr = 0x8232605C;
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
	// lfs f1,-10412(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -10412);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82224038
	ctx.lr = 0x82326070;
	sub_82224038(ctx, base);
	// lfs f0,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82326088
	if (!ctx.cr6.gt) goto loc_82326088;
	// stb r29,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r29.u8);
	// b 0x82326090
	goto loc_82326090;
loc_82326088:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r11.u8);
loc_82326090:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,280
	ctx.r3.s64 = ctx.r1.s64 + 280;
	// bl 0x8222ff78
	ctx.lr = 0x823260A4;
	sub_8222FF78(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x823260C0;
	sub_8222FF78(ctx, base);
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
	// bl 0x82240a58
	ctx.lr = 0x823260E8;
	sub_82240A58(ctx, base);
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
	// addi r11,r11,-29168
	ctx.r11.s64 = ctx.r11.s64 + -29168;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// b 0x82326c14
	goto loc_82326C14;
loc_82326148:
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
	// bl 0x8224a2a0
	ctx.lr = 0x8232616C;
	sub_8224A2A0(ctx, base);
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
	// b 0x82326c14
	goto loc_82326C14;
loc_82326188:
	// addis r23,r31,1
	ctx.r23.s64 = ctx.r31.s64 + 65536;
	// addi r23,r23,-3096
	ctx.r23.s64 = ctx.r23.s64 + -3096;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8232652c
	if (ctx.cr6.lt) goto loc_8232652C;
	// bne cr6,0x82326c14
	if (!ctx.cr6.eq) goto loc_82326C14;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lfs f0,5144(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5144);
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
	// ble cr6,0x823264c4
	if (!ctx.cr6.gt) goto loc_823264C4;
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
	// bne 0x82326264
	if (!ctx.cr0.eq) goto loc_82326264;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,312
	ctx.r3.s64 = ctx.r1.s64 + 312;
	// bl 0x8222ff78
	ctx.lr = 0x8232621C;
	sub_8222FF78(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x82326238;
	sub_8222FF78(ctx, base);
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
	// bl 0x82240a58
	ctx.lr = 0x82326260;
	sub_82240A58(ctx, base);
	// stb r24,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r24.u8);
loc_82326264:
	// lfsx f13,r31,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	ctx.f13.f64 = double(temp.f32);
	// add r30,r31,r27
	ctx.r30.u64 = ctx.r31.u64 + ctx.r27.u64;
	// lfs f0,268(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 268);
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
	// ble cr6,0x8232628c
	if (!ctx.cr6.gt) goto loc_8232628C;
	// stfs f31,0(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// b 0x82326444
	goto loc_82326444;
loc_8232628C:
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x825a49b0
	ctx.lr = 0x8232629C;
	sub_825A49B0(ctx, base);
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
	// bne cr6,0x82326444
	if (!ctx.cr6.eq) goto loc_82326444;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,344
	ctx.r3.s64 = ctx.r1.s64 + 344;
	// bl 0x8222ff78
	ctx.lr = 0x823262CC;
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
	// addi r28,r10,-29200
	ctx.r28.s64 = ctx.r10.s64 + -29200;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x82326314;
	sub_8222FF78(ctx, base);
	// lfs f13,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,-3880(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -3880);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// bl 0x82326ce8
	ctx.lr = 0x82326380;
	sub_82326CE8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,376
	ctx.r3.s64 = ctx.r1.s64 + 376;
	// bl 0x8222ff78
	ctx.lr = 0x82326394;
	sub_8222FF78(ctx, base);
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8222ff78
	ctx.lr = 0x823263D4;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lfs f13,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-20904(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + -20904);
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
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// bl 0x82326ce8
	ctx.lr = 0x82326444;
	sub_82326CE8(ctx, base);
loc_82326444:
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_823264C4:
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
	// bne 0x8232651c
	if (!ctx.cr0.eq) goto loc_8232651C;
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
	// bl 0x8224a2a0
	ctx.lr = 0x82326504;
	sub_8224A2A0(ctx, base);
	// stfsx f30,r31,r27
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
	// stw r28,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r28.u32);
	// stfsx f30,r31,r30
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, temp.u32);
loc_82326510:
	// li r11,2
	ctx.r11.s64 = 2;
	// stwx r28,r31,r29
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, ctx.r28.u32);
	// stw r11,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r11.u32);
loc_8232651C:
	// lfsx f0,r31,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// stfsx f0,r31,r30
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, temp.u32);
	// b 0x82326c14
	goto loc_82326C14;
loc_8232652C:
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
	// bl 0x8224a2a0
	ctx.lr = 0x82326550;
	sub_8224A2A0(ctx, base);
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
	// b 0x82326c14
	goto loc_82326C14;
loc_82326578:
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// addi r27,r27,-3096
	ctx.r27.s64 = ctx.r27.s64 + -3096;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x823266a0
	if (ctx.cr6.lt) goto loc_823266A0;
	// bne cr6,0x82326c14
	if (!ctx.cr6.eq) goto loc_82326C14;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lfs f0,5144(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 5144);
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
	// ble cr6,0x82326654
	if (!ctx.cr6.gt) goto loc_82326654;
	// lwzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bge cr6,0x82326654
	if (!ctx.cr6.lt) goto loc_82326654;
	// lbzx r11,r31,r26
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r26.u32);
	// li r24,1
	ctx.r24.s64 = 1;
	// add r30,r31,r26
	ctx.r30.u64 = ctx.r31.u64 + ctx.r26.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82326648
	if (!ctx.cr0.eq) goto loc_82326648;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,408
	ctx.r3.s64 = ctx.r1.s64 + 408;
	// bl 0x8222ff78
	ctx.lr = 0x82326600;
	sub_8222FF78(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x8232661C;
	sub_8222FF78(ctx, base);
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
	// bl 0x82240a58
	ctx.lr = 0x82326644;
	sub_82240A58(ctx, base);
	// stb r24,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r24.u8);
loc_82326648:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62473
	ctx.r11.u64 = ctx.r11.u64 | 62473;
	// stbx r24,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r24.u8);
loc_82326654:
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
	// bne 0x8232651c
	if (!ctx.cr0.eq) goto loc_8232651C;
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
	// bl 0x8224a2a0
	ctx.lr = 0x82326694;
	sub_8224A2A0(ctx, base);
	// stfsx f1,r31,r30
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, temp.u32);
	// stw r28,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r28.u32);
	// b 0x82326510
	goto loc_82326510;
loc_823266A0:
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
	// bl 0x8224a2a0
	ctx.lr = 0x823266C4;
	sub_8224A2A0(ctx, base);
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
	// b 0x82326c14
	goto loc_82326C14;
loc_823266E0:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3096
	ctx.r30.s64 = ctx.r30.s64 + -3096;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8232674c
	if (ctx.cr6.eq) goto loc_8232674C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82326c14
	if (!ctx.cr6.eq) goto loc_82326C14;
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
	// bge cr6,0x82326738
	if (!ctx.cr6.lt) goto loc_82326738;
	// lfs f13,268(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82326c14
	if (ctx.cr6.lt) goto loc_82326C14;
loc_82326738:
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
	// b 0x82326c14
	goto loc_82326C14;
loc_8232674C:
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
	// bl 0x8224a2a0
	ctx.lr = 0x8232677C;
	sub_8224A2A0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x82326c14
	goto loc_82326C14;
loc_82326788:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r29,r29,-3096
	ctx.r29.s64 = ctx.r29.s64 + -3096;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82326858
	if (ctx.cr6.lt) goto loc_82326858;
	// bne cr6,0x82326c14
	if (!ctx.cr6.eq) goto loc_82326C14;
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
	// ble cr6,0x823267e4
	if (!ctx.cr6.gt) goto loc_823267E4;
	// stb r24,545(r31)
	REX_STORE_U8(ctx.r31.u32 + 545, ctx.r24.u8);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r28,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r28.u32);
loc_823267E4:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-9856
	ctx.r11.s64 = ctx.r11.s64 + -9856;
	// addi r30,r30,-3084
	ctx.r30.s64 = ctx.r30.s64 + -3084;
	// lfs f0,-20272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82326814
	if (!ctx.cr6.gt) goto loc_82326814;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r24,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r24.u32);
	// stb r28,545(r31)
	REX_STORE_U8(ctx.r31.u32 + 545, ctx.r28.u8);
loc_82326814:
	// cmpwi cr6,r10,34
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 34, ctx.xer);
	// blt cr6,0x8232684c
	if (ctx.cr6.lt) goto loc_8232684C;
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
	// bl 0x8224a2a0
	ctx.lr = 0x8232683C;
	sub_8224A2A0(ctx, base);
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
loc_8232684C:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// b 0x82326c10
	goto loc_82326C10;
loc_82326858:
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
	// bl 0x8224a2a0
	ctx.lr = 0x8232687C;
	sub_8224A2A0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x82326c14
	goto loc_82326C14;
loc_82326888:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-3096
	ctx.r30.s64 = ctx.r30.s64 + -3096;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82326a00
	if (ctx.cr6.lt) goto loc_82326A00;
	// bne cr6,0x82326c14
	if (!ctx.cr6.eq) goto loc_82326C14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82328950
	ctx.lr = 0x823268A8;
	sub_82328950(ctx, base);
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
	// bne 0x8232692c
	if (!ctx.cr0.eq) goto loc_8232692C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,440
	ctx.r3.s64 = ctx.r1.s64 + 440;
	// bl 0x8222ff78
	ctx.lr = 0x823268E8;
	sub_8222FF78(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x82326904;
	sub_8222FF78(ctx, base);
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
	// bl 0x82240a58
	ctx.lr = 0x8232692C;
	sub_82240A58(ctx, base);
loc_8232692C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822301e0
	ctx.lr = 0x8232693C;
	sub_822301E0(ctx, base);
	// lfs f31,-2712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -2712);
	ctx.f31.f64 = double(temp.f32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r28,0
	ctx.r28.s64 = 0;
	// bne 0x82326998
	if (!ctx.cr0.eq) goto loc_82326998;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8232698c
	if (!ctx.cr6.lt) goto loc_8232698C;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8232698C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82326998
	if (ctx.cr0.eq) goto loc_82326998;
	// stfs f31,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
loc_82326998:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823269B0;
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
	// bge cr6,0x823269ec
	if (!ctx.cr6.lt) goto loc_823269EC;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// lfs f13,2780(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2780);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82326c14
	if (ctx.cr6.lt) goto loc_82326C14;
loc_823269EC:
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
	// b 0x82326c14
	goto loc_82326C14;
loc_82326A00:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,472
	ctx.r3.s64 = ctx.r1.s64 + 472;
	// bl 0x8222ff78
	ctx.lr = 0x82326A14;
	sub_8222FF78(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x82326A30;
	sub_8222FF78(ctx, base);
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
	// bl 0x82240a58
	ctx.lr = 0x82326A58;
	sub_82240A58(ctx, base);
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
	// bl 0x8224a2a0
	ctx.lr = 0x82326A90;
	sub_8224A2A0(ctx, base);
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
	// beq cr6,0x82326ae0
	if (ctx.cr6.eq) goto loc_82326AE0;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82222d88
	ctx.lr = 0x82326AD0;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82326ae0
	if (ctx.cr0.eq) goto loc_82326AE0;
	// stb r28,84(r3)
	REX_STORE_U8(ctx.r3.u32 + 84, ctx.r28.u8);
	// stb r28,85(r3)
	REX_STORE_U8(ctx.r3.u32 + 85, ctx.r28.u8);
loc_82326AE0:
	// stw r24,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r24.u32);
	// b 0x82326c14
	goto loc_82326C14;
loc_82326AE8:
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
	// bne 0x82326b74
	if (!ctx.cr0.eq) goto loc_82326B74;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82326b74
	if (!ctx.cr6.gt) goto loc_82326B74;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x8222ff78
	ctx.lr = 0x82326B30;
	sub_8222FF78(ctx, base);
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
	// bl 0x8222ff78
	ctx.lr = 0x82326B4C;
	sub_8222FF78(ctx, base);
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
	// bl 0x82240a58
	ctx.lr = 0x82326B74;
	sub_82240A58(ctx, base);
loc_82326B74:
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
	// lfs f0,-9856(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82326bd4
	if (!ctx.cr6.gt) goto loc_82326BD4;
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
	ctx.lr = 0x82326BD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82326bf4
	goto loc_82326BF4;
loc_82326BD4:
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
	ctx.lr = 0x82326BF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82326BF4:
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
loc_82326C10:
	// stfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
loc_82326C14:
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8273af74
	ctx.lr = 0x82326C20;
	__restfpr_28(ctx, base);
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823FD4F8) {
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
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lwz r10,292(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 292);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,2092
	ctx.r8.s64 = ctx.r11.s64 + 2092;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// addi r11,r11,-19544
	ctx.r11.s64 = ctx.r11.s64 + -19544;
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lis r5,-32228
	ctx.r5.s64 = -2112094208;
	// lwzx r30,r9,r8
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r9,r7,-4080
	ctx.r9.s64 = ctx.r7.s64 + -4080;
	// rlwinm r8,r30,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f13,17288(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 17288);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1052(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1052);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f12,r8,r11
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
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
	// std r11,0(r6)
	REX_STORE_U64(ctx.r6.u32 + 0, ctx.r11.u64);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x823c82a8
	ctx.lr = 0x823FD56C;
	sub_823C82A8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,-19936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19936);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwzx r11,r30,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r31.u32);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
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
	ctx.lr = 0x823FD5AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
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
	ctx.lr = 0x823FD5E0;
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

DEFINE_REX_FUNC(sub_82405678) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x82405680;
	__savegprlr_19(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r21,184
	ctx.r21.s64 = 184;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw. r11,r11,r21
	ctx.r11.u64 = uint32_t((ctx.r21.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r21.s32 == -1)) ? ctx.r11.s32 / ctx.r21.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82405960
	if (ctx.cr0.eq) goto loc_82405960;
	// li r22,0
	ctx.r22.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824058c0
	if (ctx.cr6.eq) goto loc_824058C0;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r20,11
	ctx.r20.s64 = 11;
	// addi r19,r11,-31424
	ctx.r19.s64 = ctx.r11.s64 + -31424;
loc_824056B8:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mulli r23,r22,184
	ctx.r23.s64 = static_cast<int64_t>(ctx.r22.u64 * static_cast<uint64_t>(184));
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// add r26,r23,r11
	ctx.r26.u64 = ctx.r23.u64 + ctx.r11.u64;
	// divw. r11,r10,r21
	ctx.r11.u64 = uint32_t((ctx.r21.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r21.s32 == -1)) ? ctx.r10.s32 / ctx.r21.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r24,1
	ctx.r24.s64 = 1;
	// bne 0x824056e0
	if (!ctx.cr0.eq) goto loc_824056E0;
loc_824056D8:
	// li r27,0
	ctx.r27.s64 = 0;
	// b 0x824056f4
	goto loc_824056F4;
loc_824056E0:
	// cmplw cr6,r22,r11
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x824056d8
	if (!ctx.cr6.lt) goto loc_824056D8;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82405450
	ctx.lr = 0x824056F0;
	sub_82405450(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_824056F4:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r28,r22,1
	ctx.r28.s64 = ctx.r22.s64 + 1;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r21
	ctx.r11.u64 = uint32_t((ctx.r21.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r21.s32 == -1)) ? ctx.r11.s32 / ctx.r21.s32 : 0);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82405764
	if (!ctx.cr6.lt) goto loc_82405764;
	// mulli r29,r28,184
	ctx.r29.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(184));
loc_82405718:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,8(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// add r3,r29,r11
	ctx.r3.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8240575c
	if (!ctx.cr6.eq) goto loc_8240575C;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// bl 0x82405450
	ctx.lr = 0x82405738;
	sub_82405450(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// add r27,r3,r27
	ctx.r27.u64 = ctx.r3.u64 + ctx.r27.u64;
	// addi r29,r29,184
	ctx.r29.s64 = ctx.r29.s64 + 184;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r21
	ctx.r11.u64 = uint32_t((ctx.r21.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r21.s32 == -1)) ? ctx.r11.s32 / ctx.r21.s32 : 0);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82405718
	if (ctx.cr6.lt) goto loc_82405718;
loc_8240575C:
	// cmplwi cr6,r24,1
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 1, ctx.xer);
	// bne cr6,0x8240576c
	if (!ctx.cr6.eq) goto loc_8240576C;
loc_82405764:
	// mr r22,r28
	ctx.r22.u64 = ctx.r28.u64;
	// b 0x824058a8
	goto loc_824058A8;
loc_8240576C:
	// divwu r11,r27,r20
	ctx.r11.u64 = uint32_t(ctx.r20.u32 ? ctx.r27.u32 / ctx.r20.u32 : 0);
	// divwu r28,r27,r20
	ctx.r28.u64 = uint32_t(ctx.r20.u32 ? ctx.r27.u32 / ctx.r20.u32 : 0);
	// mulli r11,r11,11
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(11));
	// subf. r11,r11,r27
	ctx.r11.u64 = ctx.r27.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82405784
	if (ctx.cr0.eq) goto loc_82405784;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_82405784:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// divwu r25,r27,r28
	ctx.r25.u64 = uint32_t(ctx.r28.u32 ? ctx.r27.u32 / ctx.r28.u32 : 0);
	// twllei r28,0
	if (ctx.r28.s32 == 0 || ctx.r28.u32 < 0u) ppc_trap(ctx, base, 0);
	// bl 0x8235ec48
	ctx.lr = 0x8240579C;
	sub_8235EC48(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw. r11,r11,r21
	ctx.r11.u64 = uint32_t((ctx.r21.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r21.s32 == -1)) ? ctx.r11.s32 / ctx.r21.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82405810
	if (ctx.cr0.eq) goto loc_82405810;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823d8ce8
	ctx.lr = 0x824057B8;
	sub_823D8CE8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x82405810
	if (ctx.cr6.eq) goto loc_82405810;
	// addi r26,r24,-1
	ctx.r26.s64 = ctx.r24.s64 + -1;
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
loc_824057CC:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,44
	ctx.r4.s64 = ctx.r11.s64 + 44;
	// bl 0x822392f0
	ctx.lr = 0x824057E8;
	sub_822392F0(ctx, base);
	// cmplw cr6,r29,r26
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x82405800
	if (ctx.cr6.eq) goto loc_82405800;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822390c0
	ctx.lr = 0x82405800;
	sub_822390C0(ctx, base);
loc_82405800:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,184
	ctx.r30.s64 = ctx.r30.s64 + 184;
	// cmplw cr6,r29,r24
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r24.u32, ctx.xer);
	// blt cr6,0x824057cc
	if (ctx.cr6.lt) goto loc_824057CC;
loc_82405810:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82405864
	if (ctx.cr6.eq) goto loc_82405864;
	// divwu r11,r27,r28
	ctx.r11.u64 = uint32_t(ctx.r28.u32 ? ctx.r27.u32 / ctx.r28.u32 : 0);
	// twllei r28,0
	if (ctx.r28.s32 == 0 || ctx.r28.u32 < 0u) ppc_trap(ctx, base, 0);
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// subf r27,r11,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r11.u64;
loc_82405830:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// bge cr6,0x82405848
	if (!ctx.cr6.lt) goto loc_82405848;
	// addi r5,r25,1
	ctx.r5.s64 = ctx.r25.s64 + 1;
loc_82405848:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// bl 0x824054e8
	ctx.lr = 0x82405854;
	sub_824054E8(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,184
	ctx.r30.s64 = ctx.r30.s64 + 184;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x82405830
	if (ctx.cr6.lt) goto loc_82405830;
loc_82405864:
	// cmplw cr6,r28,r24
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r24.u32, ctx.xer);
	// bge cr6,0x82405894
	if (!ctx.cr6.lt) goto loc_82405894;
	// subf r10,r28,r24
	ctx.r10.u64 = ctx.r24.u64 - ctx.r28.u64;
	// add r11,r28,r22
	ctx.r11.u64 = ctx.r28.u64 + ctx.r22.u64;
	// mulli r11,r11,184
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(184));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8240587C:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,184
	ctx.r11.s64 = ctx.r11.s64 + 184;
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// bdnz 0x8240587c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8240587C;
loc_82405894:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// add r22,r24,r22
	ctx.r22.u64 = ctx.r24.u64 + ctx.r22.u64;
	// bl 0x8235ec48
	ctx.lr = 0x824058A8;
	sub_8235EC48(ctx, base);
loc_824058A8:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r21
	ctx.r11.u64 = uint32_t((ctx.r21.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r21.s32 == -1)) ? ctx.r11.s32 / ctx.r21.s32 : 0);
	// cmplw cr6,r22,r11
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x824056b8
	if (ctx.cr6.lt) goto loc_824056B8;
loc_824058C0:
	// lwz r26,4(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82405960
	if (ctx.cr6.eq) goto loc_82405960;
	// addi r27,r26,184
	ctx.r27.s64 = ctx.r26.s64 + 184;
loc_824058D4:
	// lwz r11,-176(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -176);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8240594c
	if (!ctx.cr6.eq) goto loc_8240594C;
	// lwz r29,8(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// cmplw cr6,r27,r29
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8240590c
	if (ctx.cr6.eq) goto loc_8240590C;
	// subf r28,r27,r26
	ctx.r28.u64 = ctx.r26.u64 - ctx.r27.u64;
loc_824058F4:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r3,r28,r30
	ctx.r3.u64 = ctx.r28.u64 + ctx.r30.u64;
	// bl 0x82405e88
	ctx.lr = 0x82405900;
	sub_82405E88(ctx, base);
	// addi r30,r30,184
	ctx.r30.s64 = ctx.r30.s64 + 184;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x824058f4
	if (!ctx.cr6.eq) goto loc_824058F4;
loc_8240590C:
	// lwz r29,8(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r29,-184
	ctx.r30.s64 = ctx.r29.s64 + -184;
	// b 0x82405924
	goto loc_82405924;
loc_82405918:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82404f28
	ctx.lr = 0x82405920;
	sub_82404F28(ctx, base);
	// addi r30,r30,184
	ctx.r30.s64 = ctx.r30.s64 + 184;
loc_82405924:
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82405918
	if (!ctx.cr6.eq) goto loc_82405918;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r11,-184
	ctx.r11.s64 = ctx.r11.s64 + -184;
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// divw. r11,r10,r21
	ctx.r11.u64 = uint32_t((ctx.r21.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r21.s32 == -1)) ? ctx.r10.s32 / ctx.r21.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82405960
	if (ctx.cr0.eq) goto loc_82405960;
	// b 0x82405954
	goto loc_82405954;
loc_8240594C:
	// addi r26,r26,184
	ctx.r26.s64 = ctx.r26.s64 + 184;
	// addi r27,r27,184
	ctx.r27.s64 = ctx.r27.s64 + 184;
loc_82405954:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824058d4
	if (!ctx.cr6.eq) goto loc_824058D4;
loc_82405960:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82420970) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82420978;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af28
	ctx.lr = 0x82420980;
	__savefpr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,14
	ctx.r11.s64 = 14;
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// li r11,10
	ctx.r11.s64 = 10;
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// li r10,11
	ctx.r10.s64 = 11;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r9,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r10,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stw r9,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// addi r9,r11,24624
	ctx.r9.s64 = ctx.r11.s64 + 24624;
	// addi r8,r10,12472
	ctx.r8.s64 = ctx.r10.s64 + 12472;
	// li r27,0
	ctx.r27.s64 = 0;
	// lfs f30,24624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24624);
	ctx.f30.f64 = double(temp.f32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lfs f28,12472(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f28.f64 = double(temp.f32);
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// lfs f31,-7580(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7580);
	ctx.f31.f64 = double(temp.f32);
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// lfs f29,-236(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -236);
	ctx.f29.f64 = double(temp.f32);
	// addi r29,r1,96
	ctx.r29.s64 = ctx.r1.s64 + 96;
	// addi r31,r3,100
	ctx.r31.s64 = ctx.r3.s64 + 100;
loc_824209F4:
	// lbz r11,192(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 192);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82420a08
	if (!ctx.cr0.eq) goto loc_82420A08;
	// cmplwi cr6,r28,7
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 7, ctx.xer);
	// beq cr6,0x82420a8c
	if (ctx.cr6.eq) goto loc_82420A8C;
loc_82420A08:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// cmplwi cr6,r11,14
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 14, ctx.xer);
	// bgt cr6,0x82420a5c
	if (ctx.cr6.gt) goto loc_82420A5C;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-4104
	ctx.r12.s64 = ctx.r12.s64 + -4104;
	// lbzx r0,r12,r11
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r11.u32);
	// lis r12,-32190
	ctx.r12.s64 = -2109603840;
	// nop 
	// addi r12,r12,2624
	ctx.r12.s64 = ctx.r12.s64 + 2624;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82420A40;
	case 1:
		goto loc_82420A40;
	case 2:
		goto loc_82420A48;
	case 3:
		goto loc_82420A48;
	case 4:
		goto loc_82420A48;
	case 5:
		goto loc_82420A48;
	case 6:
		goto loc_82420A48;
	case 7:
		goto loc_82420A48;
	case 8:
		goto loc_82420A50;
	case 9:
		goto loc_82420A50;
	case 10:
		goto loc_82420A50;
	case 11:
		goto loc_82420A50;
	case 12:
		goto loc_82420A58;
	case 13:
		goto loc_82420A58;
	case 14:
		goto loc_82420A50;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82420A40:
	// li r4,161
	ctx.r4.s64 = 161;
	// b 0x82420a5c
	goto loc_82420A5C;
loc_82420A48:
	// li r4,163
	ctx.r4.s64 = 163;
	// b 0x82420a5c
	goto loc_82420A5C;
loc_82420A50:
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// b 0x82420a5c
	goto loc_82420A5C;
loc_82420A58:
	// li r4,165
	ctx.r4.s64 = 165;
loc_82420A5C:
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f13,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r6,164(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 164);
	// fmr f4,f28
	ctx.f4.f64 = ctx.f28.f64;
	// lwz r3,76(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// fsubs f3,f13,f31
	ctx.f3.f64 = double(float(ctx.f13.f64 - ctx.f31.f64));
	// stb r27,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r27.u8);
	// fsubs f2,f0,f30
	ctx.f2.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x823c67c0
	ctx.lr = 0x82420A8C;
	sub_823C67C0(ctx, base);
loc_82420A8C:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// cmplwi cr6,r28,8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 8, ctx.xer);
	// blt cr6,0x824209f4
	if (ctx.cr6.lt) goto loc_824209F4;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af74
	ctx.lr = 0x82420AAC;
	__restfpr_28(ctx, base);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8242AFC8) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stb r10,12(r3)
	REX_STORE_U8(ctx.r3.u32 + 12, ctx.r10.u8);
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// std r11,32(r3)
	REX_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// stw r11,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// stb r11,68(r3)
	REX_STORE_U8(ctx.r3.u32 + 68, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8242C3E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8242C3F0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8242c564
	if (ctx.cr0.eq) goto loc_8242C564;
	// bl 0x82213210
	ctx.lr = 0x8242C40C;
	sub_82213210(ctx, base);
	// lwz r29,4(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r27,2
	ctx.r27.s64 = 2;
	// cmpwi cr6,r29,254
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 254, ctx.xer);
	// beq cr6,0x8242c490
	if (ctx.cr6.eq) goto loc_8242C490;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826399f0
	ctx.lr = 0x8242C424;
	sub_826399F0(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8242c43c
	if (ctx.cr6.eq) goto loc_8242C43C;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r11,r11,1245
	ctx.r11.u64 = ctx.r11.u64 | 1245;
loc_8242C434:
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// stw r27,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
loc_8242C43C:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8242c4f0
	if (ctx.cr6.lt) goto loc_8242C4F0;
	// beq cr6,0x8242c49c
	if (ctx.cr6.eq) goto loc_8242C49C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8242c564
	if (!ctx.cr6.lt) goto loc_8242C564;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// bne cr6,0x8242c468
	if (!ctx.cr6.eq) goto loc_8242C468;
	// bl 0x82639e58
	ctx.lr = 0x8242C468;
	sub_82639E58(ctx, base);
loc_8242C468:
	// lwz r3,1096(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1096);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8242c478
	if (ctx.cr6.eq) goto loc_8242C478;
	// bl 0x825e0378
	ctx.lr = 0x8242C478;
	sub_825E0378(ctx, base);
loc_8242C478:
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r30,1096(r31)
	REX_STORE_U32(ctx.r31.u32 + 1096, ctx.r30.u32);
	// stw r30,1100(r31)
	REX_STORE_U32(ctx.r31.u32 + 1100, ctx.r30.u32);
	// stb r30,0(r28)
	REX_STORE_U8(ctx.r28.u32 + 0, ctx.r30.u8);
	// stb r30,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r30.u8);
	// b 0x8242c564
	goto loc_8242C564;
loc_8242C490:
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r11,r11,1253
	ctx.r11.u64 = ctx.r11.u64 | 1253;
	// b 0x8242c434
	goto loc_8242C434;
loc_8242C49C:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r29,r31,16
	ctx.r29.s64 = ctx.r31.s64 + 16;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x8242c564
	if (ctx.cr6.eq) goto loc_8242C564;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82639e80
	ctx.lr = 0x8242C4C4;
	sub_82639E80(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8242c4dc
	if (!ctx.cr0.eq) goto loc_8242C4DC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,68(r31)
	REX_STORE_U8(ctx.r31.u32 + 68, ctx.r11.u8);
	// stw r30,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r30.u32);
	// b 0x8242c554
	goto loc_8242C554;
loc_8242C4DC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82639f18
	ctx.lr = 0x8242C4E4;
	sub_82639F18(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble 0x8242c550
	if (!ctx.cr0.gt) goto loc_8242C550;
	// b 0x8242c548
	goto loc_8242C548;
loc_8242C4F0:
	// addi r30,r31,48
	ctx.r30.s64 = ctx.r31.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82639c40
	ctx.lr = 0x8242C500;
	sub_82639C40(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8242c540
	if (!ctx.cr0.eq) goto loc_8242C540;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// ld r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,56(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// bl 0x8242c348
	ctx.lr = 0x8242C51C;
	sub_8242C348(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x8242c554
	if (ctx.cr0.eq) goto loc_8242C554;
	// addi r7,r31,16
	ctx.r7.s64 = ctx.r31.s64 + 16;
	// lwz r6,60(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,64(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// bl 0x827352d8
	ctx.lr = 0x8242C538;
	sub_827352D8(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8242c55c
	if (ctx.cr6.eq) goto loc_8242C55C;
loc_8242C540:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8242c550
	if (!ctx.cr6.gt) goto loc_8242C550;
loc_8242C548:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r3,r11,32775
	ctx.r3.u64 = ctx.r11.u64 | 2147942400;
loc_8242C550:
	// stw r3,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r3.u32);
loc_8242C554:
	// stw r27,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
	// b 0x8242c564
	goto loc_8242C564;
loc_8242C55C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_8242C564:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82437FA0) {
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
	// lwz r3,2340(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 2340);
	// li r4,128
	ctx.r4.s64 = 128;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1060);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82437FD8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82438158
	if (ctx.cr0.eq) goto loc_82438158;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82437FF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82438118
	if (!ctx.cr0.eq) goto loc_82438118;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82438010;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82438118
	if (!ctx.cr0.eq) goto loc_82438118;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,948(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 948);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8243802C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82438118
	if (!ctx.cr0.eq) goto loc_82438118;
	// lwz r6,2688(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 2688);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne 0x8243804c
	if (!ctx.cr0.eq) goto loc_8243804C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x82438054
	goto loc_82438054;
loc_8243804C:
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x824353a0
	ctx.lr = 0x82438054;
	sub_824353A0(ctx, base);
loc_82438054:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824380c8
	if (ctx.cr0.eq) goto loc_824380C8;
	// lwz r11,2504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2504);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82438088
	if (ctx.cr6.eq) goto loc_82438088;
	// bl 0x823b47e8
	ctx.lr = 0x82438074;
	sub_823B47E8(ctx, base);
	// lwz r11,2696(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2696);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8243808c
	if (ctx.cr6.eq) goto loc_8243808C;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8243808c
	if (ctx.cr6.eq) goto loc_8243808C;
loc_82438088:
	// li r7,1
	ctx.r7.s64 = 1;
loc_8243808C:
	// lbz r11,2364(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 2364);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824380a8
	if (ctx.cr0.eq) goto loc_824380A8;
	// lbz r11,2365(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 2365);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq 0x824380ac
	if (ctx.cr0.eq) goto loc_824380AC;
loc_824380A8:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_824380AC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824380b8
	if (ctx.cr0.eq) goto loc_824380B8;
	// li r7,1
	ctx.r7.s64 = 1;
loc_824380B8:
	// clrlwi. r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824380d8
	if (ctx.cr0.eq) goto loc_824380D8;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x8246ecc0
	ctx.lr = 0x824380C8;
	sub_8246ECC0(ctx, base);
loc_824380C8:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r30,2700(r31)
	REX_STORE_U32(ctx.r31.u32 + 2700, ctx.r30.u32);
	// stw r30,2688(r31)
	REX_STORE_U32(ctx.r31.u32 + 2688, ctx.r30.u32);
	// stw r11,2696(r31)
	REX_STORE_U32(ctx.r31.u32 + 2696, ctx.r11.u32);
loc_824380D8:
	// lwz r3,2692(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2692);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x824380ec
	if (!ctx.cr6.eq) goto loc_824380EC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x824380f0
	goto loc_824380F0;
loc_824380EC:
	// bl 0x824353a0
	ctx.lr = 0x824380F0;
	sub_824353A0(ctx, base);
loc_824380F0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824380fc
	if (!ctx.cr0.eq) goto loc_824380FC;
	// stw r30,2692(r31)
	REX_STORE_U32(ctx.r31.u32 + 2692, ctx.r30.u32);
loc_824380FC:
	// lwz r11,2352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2352);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82438158
	if (!ctx.cr6.eq) goto loc_82438158;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82438178
	ctx.lr = 0x82438114;
	sub_82438178(ctx, base);
	// b 0x82438158
	goto loc_82438158;
loc_82438118:
	// lwz r7,2688(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 2688);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne 0x82438130
	if (!ctx.cr0.eq) goto loc_82438130;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x82438138
	goto loc_82438138;
loc_82438130:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x824353a0
	ctx.lr = 0x82438138;
	sub_824353A0(ctx, base);
loc_82438138:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82438158
	if (ctx.cr0.eq) goto loc_82438158;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x8246ecc0
	ctx.lr = 0x82438148;
	sub_8246ECC0(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r30,2688(r31)
	REX_STORE_U32(ctx.r31.u32 + 2688, ctx.r30.u32);
	// stw r11,2696(r31)
	REX_STORE_U32(ctx.r31.u32 + 2696, ctx.r11.u32);
	// stw r30,2700(r31)
	REX_STORE_U32(ctx.r31.u32 + 2700, ctx.r30.u32);
loc_82438158:
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

DEFINE_REX_FUNC(sub_82444678) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82444680;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r11,-12952(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824447dc
	if (ctx.cr6.eq) goto loc_824447DC;
	// bl 0x824443c8
	ctx.lr = 0x8244469C;
	sub_824443C8(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x824447dc
	if (ctx.cr0.eq) goto loc_824447DC;
	// lwz r11,2352(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 2352);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x824447dc
	if (!ctx.cr6.eq) goto loc_824447DC;
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// beq cr6,0x824446e8
	if (ctx.cr6.eq) goto loc_824446E8;
	// cmpwi cr6,r4,3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 3, ctx.xer);
	// beq cr6,0x824446e0
	if (ctx.cr6.eq) goto loc_824446E0;
	// cmpwi cr6,r4,6
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 6, ctx.xer);
	// beq cr6,0x824446d8
	if (ctx.cr6.eq) goto loc_824446D8;
	// cmpwi cr6,r4,7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 7, ctx.xer);
	// bne cr6,0x824447dc
	if (!ctx.cr6.eq) goto loc_824447DC;
	// li r31,11
	ctx.r31.s64 = 11;
	// b 0x824446ec
	goto loc_824446EC;
loc_824446D8:
	// li r31,10
	ctx.r31.s64 = 10;
	// b 0x824446ec
	goto loc_824446EC;
loc_824446E0:
	// li r31,9
	ctx.r31.s64 = 9;
	// b 0x824446ec
	goto loc_824446EC;
loc_824446E8:
	// li r31,5
	ctx.r31.s64 = 5;
loc_824446EC:
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8243ae28
	ctx.lr = 0x824446F8;
	sub_8243AE28(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f0,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwa r28,84(r1)
	ctx.r28.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 84));
	// bl 0x825772f8
	ctx.lr = 0x82444718;
	sub_825772F8(ctx, base);
	// std r28,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r28.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r28,84(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r28,1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 1, ctx.xer);
	// bge cr6,0x82444748
	if (!ctx.cr6.lt) goto loc_82444748;
	// li r28,1
	ctx.r28.s64 = 1;
loc_82444748:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lwz r10,2340(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,17432
	ctx.r11.s64 = ctx.r11.s64 + 17432;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwzx r11,r9,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bne cr6,0x82444770
	if (!ctx.cr6.eq) goto loc_82444770;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x82444788
	goto loc_82444788;
loc_82444770:
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,576(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 576);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82444784;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_82444788:
	// bl 0x82213210
	ctx.lr = 0x8244478C;
	sub_82213210(ctx, base);
	// addi r6,r3,4120
	ctx.r6.s64 = ctx.r3.s64 + 4120;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r7,r31,-1
	ctx.r7.s64 = ctx.r31.s64 + -1;
	// bl 0x823b47e8
	ctx.lr = 0x8244479C;
	sub_823B47E8(ctx, base);
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// bge cr6,0x824447dc
	if (!ctx.cr6.lt) goto loc_824447DC;
	// cmplwi cr6,r3,50
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 50, ctx.xer);
	// bge cr6,0x824447dc
	if (!ctx.cr6.lt) goto loc_824447DC;
	// mulli r11,r7,50
	ctx.r11.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(50));
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// addi r11,r11,2446
	ctx.r11.s64 = ctx.r11.s64 + 2446;
	// ori r10,r10,34463
	ctx.r10.u64 = ctx.r10.u64 | 34463;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r6
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x824447d8
	if (!ctx.cr6.gt) goto loc_824447D8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_824447D8:
	// stwx r11,r9,r6
	REX_STORE_U32(ctx.r9.u32 + ctx.r6.u32, ctx.r11.u32);
loc_824447DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8244DFF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8244DFF8;
	__savegprlr_26(ctx, base);
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x8273af14
	ctx.lr = 0x8244E000;
	__savefpr_23(ctx, base);
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
	// beq cr6,0x8244e2dc
	if (ctx.cr6.eq) goto loc_8244E2DC;
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8244e2dc
	if (ctx.cr6.eq) goto loc_8244E2DC;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244E034;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8244e2dc
	if (!ctx.cr0.eq) goto loc_8244E2DC;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8244e2dc
	if (ctx.cr6.eq) goto loc_8244E2DC;
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r4,76(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244E060;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// addi r4,r31,80
	ctx.r4.s64 = ctx.r31.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244E078;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r30,r11,14280
	ctx.r30.s64 = ctx.r11.s64 + 14280;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f31,-2044(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2044);
	ctx.f31.f64 = double(temp.f32);
	// lwz r10,120(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 120);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lfs f0,96(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x8244E0A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244E0C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f6,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f6.f64 = double(temp.f32);
	// lis r27,-32114
	ctx.r27.s64 = -2104623104;
	// addi r28,r11,18380
	ctx.r28.s64 = ctx.r11.s64 + 18380;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r7,r11,-4080
	ctx.r7.s64 = ctx.r11.s64 + -4080;
	// lfs f9,-8860(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -8860);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,-1248(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1248);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f6
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f6.f64));
	// lfs f8,740(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 740);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,236(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 236);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f0,f0,f9
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// fmadds f1,f0,f8,f7
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f8.f64, ctx.f7.f64)));
	// bl 0x822ea1a8
	ctx.lr = 0x8244E0F8;
	sub_822EA1A8(ctx, base);
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f5,f31,f1
	ctx.f5.f64 = double(float(ctx.f31.f64 - ctx.f1.f64));
	// fmuls f0,f0,f9
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// fmuls f1,f0,f8
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x8244E10C;
	sub_822EA1A8(ctx, base);
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f28,f5,f1
	ctx.f28.f64 = double(float(ctx.f5.f64 * ctx.f1.f64));
	// fmuls f0,f0,f9
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// lfs f30,408(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 408);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f1,f0,f30,f7
	ctx.f1.f64 = double(float(std::fma(ctx.f0.f64, ctx.f30.f64, ctx.f7.f64)));
	// bl 0x822ea1a8
	ctx.lr = 0x8244E124;
	sub_822EA1A8(ctx, base);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f1.f64));
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// fmuls f12,f6,f9
	ctx.f12.f64 = double(float(ctx.f6.f64 * ctx.f9.f64));
	// lfs f0,19192(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19192);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f7,f13,f0,f31
	ctx.f7.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f31.f64)));
	// fmuls f1,f12,f8
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f8.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x8244E140;
	sub_822EA1A8(ctx, base);
	// lfs f29,96(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 96);
	ctx.f29.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmadds f0,f1,f29,f31
	ctx.f0.f64 = double(float(std::fma(ctx.f1.f64, ctx.f29.f64, ctx.f31.f64)));
	// li r29,255
	ctx.r29.s64 = 255;
	// lfs f24,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// li r26,0
	ctx.r26.s64 = 0;
	// lfs f26,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// stb r29,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r29.u8);
	// lfs f25,744(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 744);
	ctx.f25.f64 = double(temp.f32);
	// stb r29,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r29.u8);
	// lfs f27,-9856(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9856);
	ctx.f27.f64 = double(temp.f32);
	// stb r29,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r29.u8);
	// fmuls f31,f7,f0
	ctx.f31.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// b 0x8244e17c
	goto loc_8244E17C;
loc_8244E178:
	// lfs f9,-8860(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -8860);
	ctx.f9.f64 = double(temp.f32);
loc_8244E17C:
	// clrldi r11,r26,32
	ctx.r11.u64 = ctx.r26.u64 & 0xFFFFFFFF;
	// lfs f13,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-13940(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -13940);
	ctx.f0.f64 = double(temp.f32);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f8,f12,f24,f13
	ctx.f8.f64 = double(float(std::fma(ctx.f12.f64, ctx.f24.f64, ctx.f13.f64)));
	// fcmpu cr6,f8,f0
	ctx.cr6.compare(ctx.f8.f64, ctx.f0.f64);
	// ble cr6,0x8244e1a8
	if (!ctx.cr6.gt) goto loc_8244E1A8;
	// fsubs f8,f8,f0
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f0.f64));
loc_8244E1A8:
	// fmuls f0,f9,f8
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f8.f64));
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x8244E1B4;
	sub_822EA1A8(ctx, base);
	// fmadds f23,f1,f26,f29
	ctx.fpscr.disableFlushMode();
	ctx.f23.f64 = double(float(std::fma(ctx.f1.f64, ctx.f26.f64, ctx.f29.f64)));
	// fmuls f1,f8,f25
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f25.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x8244E1C0;
	sub_822EA1A8(ctx, base);
	// fmuls f0,f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f28.f64));
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmuls f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f27.f64));
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lbz r11,103(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x8244E1F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// fmuls f1,f23,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f23.f64 * ctx.f31.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244E208;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r30,0
	ctx.r30.s64 = 0;
loc_8244E20C:
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// clrlwi r4,r30,16
	ctx.r4.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244E224;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244E238;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x8244e20c
	if (ctx.cr6.lt) goto loc_8244E20C;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmplwi cr6,r26,3
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 3, ctx.xer);
	// blt cr6,0x8244e178
	if (ctx.cr6.lt) goto loc_8244E178;
	// fmuls f0,f28,f27
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 * ctx.f27.f64));
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// stb r29,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r29.u8);
	// stb r29,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r29.u8);
	// stb r29,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r29.u8);
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
	ctx.lr = 0x8244E288;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
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
	ctx.lr = 0x8244E2A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r30,0
	ctx.r30.s64 = 0;
loc_8244E2A4:
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// clrlwi r4,r30,16
	ctx.r4.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244E2BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244E2D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x8244e2a4
	if (ctx.cr6.lt) goto loc_8244E2A4;
loc_8244E2DC:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x8273af60
	ctx.lr = 0x8244E2E8;
	__restfpr_23(ctx, base);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82466F00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82466F08;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,92
	ctx.r31.s64 = ctx.r3.s64 + 92;
	// li r30,2
	ctx.r30.s64 = 2;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
loc_82466F18:
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x82466f34
	if (ctx.cr6.eq) goto loc_82466F34;
	// lwz r3,-12824(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x82466F2C;
	sub_82599798(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82466F34:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x82466f18
	if (!ctx.cr0.eq) goto loc_82466F18;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8246A2C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8246A2C8;
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
	// li r4,84
	ctx.r4.s64 = 84;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8246A2F0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8246a304
	if (ctx.cr0.eq) goto loc_8246A304;
	// bl 0x8222f918
	ctx.lr = 0x8246A2FC;
	sub_8222F918(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8246a308
	goto loc_8246A308;
loc_8246A304:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8246A308:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8246a31c
	if (!ctx.cr6.eq) goto loc_8246A31C;
loc_8246A314:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8246a460
	goto loc_8246A460;
loc_8246A31C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r3,-12860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -12860);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8246a344
	if (ctx.cr6.eq) goto loc_8246A344;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8246cfe0
	ctx.lr = 0x8246A33C;
	sub_8246CFE0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8246a348
	goto loc_8246A348;
loc_8246A344:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8246A348:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bne cr6,0x8246a36c
	if (!ctx.cr6.eq) goto loc_8246A36C;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246A368;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8246a314
	goto loc_8246A314;
loc_8246A36C:
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246A380;
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
	ctx.lr = 0x8246A398;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,268(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 268);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8246a3d4
	if (ctx.cr0.eq) goto loc_8246A3D4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,260(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 260);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246A3BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,264(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 264);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8246A3D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8246A3D4:
	// lwz r11,140(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 140);
	// addi r3,r29,136
	ctx.r3.s64 = ctx.r29.s64 + 136;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8246a3ec
	if (!ctx.cr6.eq) goto loc_8246A3EC;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8246a3f8
	goto loc_8246A3F8;
loc_8246A3EC:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_8246A3F8:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8246a41c
	if (!ctx.cr6.lt) goto loc_8246A41C;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r31,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r31.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x8246a428
	goto loc_8246A428;
loc_8246A41C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823849b0
	ctx.lr = 0x8246A424;
	sub_823849B0(ctx, base);
	// lwz r31,80(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8246A428:
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r29,168
	ctx.r3.s64 = ctx.r29.s64 + 168;
	// bl 0x82396cc8
	ctx.lr = 0x8246A434;
	sub_82396CC8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stb r11,253(r29)
	REX_STORE_U8(ctx.r29.u32 + 253, ctx.r11.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8224a2a0
	ctx.lr = 0x8246A45C;
	sub_8224A2A0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_8246A460:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824747E0) {
	REX_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,280(r3)
	REX_STORE_U8(ctx.r3.u32 + 280, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824749E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x824749F0;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r6,12
	ctx.r6.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x824689b0
	ctx.lr = 0x82474A0C;
	sub_824689B0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-26568
	ctx.r11.s64 = ctx.r11.s64 + -26568;
	// addi r24,r31,312
	ctx.r24.s64 = ctx.r31.s64 + 312;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r27,r31,328
	ctx.r27.s64 = ctx.r31.s64 + 328;
	// stw r30,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r30.u32);
	// stw r30,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r30.u32);
	// stw r30,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r30.u32);
	// stw r30,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r30.u32);
	// stw r30,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r30.u32);
	// stw r30,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r30.u32);
	// stb r30,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r30.u8);
	// lwz r11,316(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// lwz r29,320(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82474a84
	if (ctx.cr6.eq) goto loc_82474A84;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
	// mr r26,r29
	ctx.r26.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r29
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82474a80
	if (ctx.cr6.eq) goto loc_82474A80;
loc_82474A60:
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8273a030
	ctx.lr = 0x82474A70;
	sub_8273A030(ctx, base);
	// addi r26,r26,40
	ctx.r26.s64 = ctx.r26.s64 + 40;
	// addi r25,r25,40
	ctx.r25.s64 = ctx.r25.s64 + 40;
	// cmplw cr6,r26,r29
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82474a60
	if (!ctx.cr6.eq) goto loc_82474A60;
loc_82474A80:
	// stw r25,8(r24)
	REX_STORE_U32(ctx.r24.u32 + 8, ctx.r25.u32);
loc_82474A84:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82217698
	ctx.lr = 0x82474A8C;
	sub_82217698(ctx, base);
	// stw r30,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r30.u32);
	// stw r30,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r30.u32);
	// stw r30,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r30.u32);
	// lwz r4,20(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// lwz r3,16(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// bl 0x8246d448
	ctx.lr = 0x82474AA4;
	sub_8246D448(ctx, base);
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// lwz r11,-12860(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12860);
	// li r27,424
	ctx.r27.s64 = 424;
	// stw r3,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82474ae8
	if (ctx.cr6.eq) goto loc_82474AE8;
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
	// bge cr6,0x82474ae8
	if (!ctx.cr6.lt) goto loc_82474AE8;
	// mulli r10,r3,424
	ctx.r10.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(424));
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,85
	ctx.r3.s64 = ctx.r11.s64 + 85;
	// b 0x82474aec
	goto loc_82474AEC;
loc_82474AE8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82474AEC:
	// stw r3,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82474d84
	if (ctx.cr6.eq) goto loc_82474D84;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8263a178
	ctx.lr = 0x82474B00;
	sub_8263A178(ctx, base);
	// stw r3,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82474d84
	if (ctx.cr0.eq) goto loc_82474D84;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8263a0f0
	ctx.lr = 0x82474B14;
	sub_8263A0F0(ctx, base);
	// stw r3,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r3.u32);
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
	ctx.lr = 0x82474B34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82474d84
	if (ctx.cr0.eq) goto loc_82474D84;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32166
	ctx.r10.s64 = -2108030976;
	// addi r4,r10,19008
	ctx.r4.s64 = ctx.r10.s64 + 19008;
	// lwz r11,1088(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1088);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82474B58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lis r11,-32166
	ctx.r11.s64 = -2108030976;
	// addi r4,r11,18864
	ctx.r4.s64 = ctx.r11.s64 + 18864;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1084(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1084);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82474B74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lis r11,-32166
	ctx.r11.s64 = -2108030976;
	// addi r4,r11,18688
	ctx.r4.s64 = ctx.r11.s64 + 18688;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1080(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1080);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82474B90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-12860(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12860);
	// lwz r10,288(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82474bc8
	if (ctx.cr6.eq) goto loc_82474BC8;
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
	// bge cr6,0x82474bc8
	if (!ctx.cr6.lt) goto loc_82474BC8;
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// mulli r10,r10,424
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(424));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x82474bcc
	goto loc_82474BCC;
loc_82474BC8:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82474BCC:
	// stw r11,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r11.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f13,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r3,-32240
	ctx.r3.s64 = -2112880640;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
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
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// lfs f0,12468(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,8(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
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
	// lfs f13,12(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// stb r30,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r30.u8);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r11.u64);
	// lwz r11,24(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// stw r11,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
	// lfs f1,52(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 52);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x82474cb8
	if (!ctx.cr6.gt) goto loc_82474CB8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246ca70
	ctx.lr = 0x82474CB8;
	sub_8246CA70(ctx, base);
loc_82474CB8:
	// lwz r4,56(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 56);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x82474ccc
	if (!ctx.cr6.gt) goto loc_82474CCC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246c998
	ctx.lr = 0x82474CCC;
	sub_8246C998(ctx, base);
loc_82474CCC:
	// lwz r11,40(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 40);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// lfs f0,36(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,196(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 196, temp.u32);
	// lfs f0,44(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,200(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 200, temp.u32);
	// lwz r4,28(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 28);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,304(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 304);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82474CFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r4,32(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,308(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 308);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82474D14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r4,40(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 40);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,312(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 312);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82474D2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lfs f1,36(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 36);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,316(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 316);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82474D44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lfs f1,44(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,320(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 320);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82474D5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,344(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 344);
	// stb r30,281(r31)
	REX_STORE_U8(ctx.r31.u32 + 281, ctx.r30.u8);
	// stb r30,280(r31)
	REX_STORE_U8(ctx.r31.u32 + 280, ctx.r30.u8);
	// lbz r10,412(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 412);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82474d8c
	if (ctx.cr0.eq) goto loc_82474D8C;
	// lwz r11,416(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 416);
	// addi r11,r11,1861
	ctx.r11.s64 = ctx.r11.s64 + 1861;
	// stw r11,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
	// b 0x82474d8c
	goto loc_82474D8C;
loc_82474D84:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_82474D8C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8249DA20) {
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
	// bl 0x8249da78
	ctx.lr = 0x8249DA40;
	sub_8249DA78(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8249da58
	if (ctx.cr0.eq) goto loc_8249DA58;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8249da58
	if (ctx.cr6.eq) goto loc_8249DA58;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8249DA58;
	sub_825E0378(ctx, base);
loc_8249DA58:
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

DEFINE_REX_FUNC(sub_8249F2B8) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8249F2D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8249F2E0;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,296(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 296);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8249f538
	if (!ctx.cr6.eq) goto loc_8249F538;
	// rlwinm. r10,r4,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stb r11,416(r3)
	REX_STORE_U8(ctx.r3.u32 + 416, ctx.r11.u8);
	// beq 0x8249f308
	if (ctx.cr0.eq) goto loc_8249F308;
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// b 0x8249f3f8
	goto loc_8249F3F8;
loc_8249F308:
	// li r11,3
	ctx.r11.s64 = 3;
	// addi r27,r29,44
	ctx.r27.s64 = ctx.r29.s64 + 44;
	// stw r11,296(r29)
	REX_STORE_U32(ctx.r29.u32 + 296, ctx.r11.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8249f758
	ctx.lr = 0x8249F31C;
	sub_8249F758(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f0,44(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,48(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r31,84(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r30,100(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r28,-13032(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8249f408
	if (ctx.cr6.eq) goto loc_8249F408;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823aebd8
	ctx.lr = 0x8249F360;
	sub_823AEBD8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8249f408
	if (ctx.cr0.eq) goto loc_8249F408;
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// extsw r10,r31
	ctx.r10.s64 = ctx.r31.s32;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// cmpwi cr6,r3,-16
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -16, ctx.xer);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// std r11,280(r29)
	REX_STORE_U64(ctx.r29.u32 + 280, ctx.r11.u64);
	// bgt cr6,0x8249f538
	if (ctx.cr6.gt) goto loc_8249F538;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_8249F3F8:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,296(r29)
	REX_STORE_U32(ctx.r29.u32 + 296, ctx.r11.u32);
	// bl 0x8249f758
	ctx.lr = 0x8249F404;
	sub_8249F758(ctx, base);
	// b 0x8249f538
	goto loc_8249F538;
loc_8249F408:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,23536
	ctx.r9.s64 = ctx.r11.s64 + 23536;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r27,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r27.u32);
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stw r27,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r27.u32);
	// stw r27,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r27.u32);
	// std r11,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r11.u64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8249f46c
	if (ctx.cr6.eq) goto loc_8249F46C;
	// li r8,3
	ctx.r8.s64 = 3;
	// addi r7,r30,64
	ctx.r7.s64 = ctx.r30.s64 + 64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823af5b0
	ctx.lr = 0x8249F46C;
	sub_823AF5B0(ctx, base);
loc_8249F46C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8249f538
	if (ctx.cr0.eq) goto loc_8249F538;
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f13,124(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r30,84(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r31,100(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// beq cr6,0x8249f4b4
	if (ctx.cr6.eq) goto loc_8249F4B4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823aebd8
	ctx.lr = 0x8249F4B4;
	sub_823AEBD8(ctx, base);
loc_8249F4B4:
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// extsw r9,r31
	ctx.r9.s64 = ctx.r31.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
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
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,280(r29)
	REX_STORE_U64(ctx.r29.u32 + 280, ctx.r11.u64);
loc_8249F538:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824B34C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x824B34D0;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	ctx.lr = 0x824B34F0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824b3514
	if (ctx.cr0.eq) goto loc_824B3514;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r4,r10,1340
	ctx.r4.s64 = ctx.r10.s64 + 1340;
	// lfs f1,-24784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24784);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82223b50
	ctx.lr = 0x824B350C;
	sub_82223B50(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x824b3518
	goto loc_824B3518;
loc_824B3514:
	// li r31,0
	ctx.r31.s64 = 0;
loc_824B3518:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824b368c
	if (ctx.cr6.eq) goto loc_824B368C;
	// li r11,15
	ctx.r11.s64 = 15;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// sth r11,102(r31)
	REX_STORE_U16(ctx.r31.u32 + 102, ctx.r11.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,56(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B3540;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// addi r28,r10,-4080
	ctx.r28.s64 = ctx.r10.s64 + -4080;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,1132(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1132);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,284(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 284);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x824B3560;
	sub_825A4A40(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r29,r11,-1560
	ctx.r29.s64 = ctx.r11.s64 + -1560;
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// lfs f2,-1560(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1560);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x824B3580;
	sub_825A4A40(ctx, base);
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x824B358C;
	sub_822EA1A8(ctx, base);
	// lfs f0,236(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f1,f9
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fadds f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x824B35A0;
	sub_822EA1A8(ctx, base);
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
	ctx.lr = 0x824B35C4;
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
	ctx.lr = 0x824B35DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,91(r31)
	REX_STORE_U8(ctx.r31.u32 + 91, ctx.r10.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824b35f4
	if (ctx.cr6.eq) goto loc_824B35F4;
	// stb r10,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r10.u8);
loc_824B35F4:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x825a4a90
	ctx.lr = 0x824B3604;
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
	ctx.lr = 0x824B3618;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,255
	ctx.r11.s64 = 255;
	// lwz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lfs f1,700(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 700);
	ctx.f1.f64 = double(temp.f32);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// li r9,5
	ctx.r9.s64 = 5;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// divwu r11,r3,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r3.u32 / ctx.r11.u32 : 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mulli r11,r11,255
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(255));
	// lwz r8,40(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 40);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// divw r10,r11,r9
	ctx.r10.u64 = uint32_t((ctx.r9.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r11.s32 / ctx.r9.s32 : 0);
	// subfic r11,r11,255
	ctx.xer.ca = ctx.r11.u32 <= 255;
	ctx.r11.u64 = static_cast<uint64_t>(255) - ctx.r11.u64;
	// subfic r10,r10,255
	ctx.xer.ca = ctx.r10.u32 <= 255;
	ctx.r10.u64 = static_cast<uint64_t>(255) - ctx.r10.u64;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r10,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r10.u8);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x824B3670;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f1,19940(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 19940);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82223bf0
	ctx.lr = 0x824B3684;
	sub_82223BF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x824b3690
	goto loc_824B3690;
loc_824B368C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824B3690:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824BD068) {
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
	// std r4,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.r4.u64);
	// lfs f13,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f0,168(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r4,100
	ctx.r4.s64 = 100;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x824BD0AC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824bd108
	if (ctx.cr0.eq) goto loc_824BD108;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,324(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 324);
	ctx.f13.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r11,14280
	ctx.r8.s64 = ctx.r11.s64 + 14280;
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// lfs f0,14280(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14280);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfs f0,808(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 808);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f0,-2840(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-23744(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -23744);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x82218490
	ctx.lr = 0x824BD100;
	sub_82218490(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x824bd10c
	goto loc_824BD10C;
loc_824BD108:
	// li r31,0
	ctx.r31.s64 = 0;
loc_824BD10C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824bd168
	if (ctx.cr6.eq) goto loc_824BD168;
	// lwz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x824bd12c
	if (!ctx.cr6.eq) goto loc_824BD12C;
	// lis r11,-32180
	ctx.r11.s64 = -2108948480;
	// addi r11,r11,-11904
	ctx.r11.s64 = ctx.r11.s64 + -11904;
	// b 0x824bd134
	goto loc_824BD134;
loc_824BD12C:
	// lis r11,-32180
	ctx.r11.s64 = -2108948480;
	// addi r11,r11,-11560
	ctx.r11.s64 = ctx.r11.s64 + -11560;
loc_824BD134:
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x824BD144;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x824bd168
	if (!ctx.cr6.eq) goto loc_824BD168;
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
	ctx.lr = 0x824BD168;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824BD168:
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

DEFINE_REX_FUNC(sub_824C3EC8) {
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
	// ld r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 44);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// addi r10,r10,32496
	ctx.r10.s64 = ctx.r10.s64 + 32496;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,22072
	ctx.r11.s64 = ctx.r8.s64 + 22072;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,100
	ctx.r4.s64 = 100;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x824C3F3C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824c3f80
	if (ctx.cr0.eq) goto loc_824C3F80;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r9,6
	ctx.r9.s64 = 6;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r9,r8,-4080
	ctx.r9.s64 = ctx.r8.s64 + -4080;
	// lfs f0,-30652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30652);
	ctx.f0.f64 = double(temp.f32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lfs f1,244(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 244);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82218490
	ctx.lr = 0x824C3F78;
	sub_82218490(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x824c3f84
	goto loc_824C3F84;
loc_824C3F80:
	// li r31,0
	ctx.r31.s64 = 0;
loc_824C3F84:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824c3fc8
	if (ctx.cr6.eq) goto loc_824C3FC8;
	// lis r11,-32180
	ctx.r11.s64 = -2108948480;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r11,r11,15800
	ctx.r11.s64 = ctx.r11.s64 + 15800;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// bl 0x82222ad8
	ctx.lr = 0x824C3FA4;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x824c3fc8
	if (!ctx.cr6.eq) goto loc_824C3FC8;
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
	ctx.lr = 0x824C3FC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824C3FC8:
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

DEFINE_REX_FUNC(sub_824D2398) {
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
	// lwz r5,4(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x824D23C0;
	sub_825A49B0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r4,r11,-18884
	ctx.r4.s64 = ctx.r11.s64 + -18884;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822167f8
	ctx.lr = 0x824D23D4;
	sub_822167F8(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x824d23e8
	if (!ctx.cr6.lt) goto loc_824D23E8;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
loc_824D23E8:
	// addi r11,r30,3
	ctx.r11.s64 = ctx.r30.s64 + 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x8246a4b8
	ctx.lr = 0x824D23F8;
	sub_8246A4B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r30,1
	ctx.r30.s64 = 1;
	// bne 0x824d2408
	if (!ctx.cr0.eq) goto loc_824D2408;
	// stb r30,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r30.u8);
loc_824D2408:
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
	ctx.lr = 0x824D2424;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r30,186(r31)
	REX_STORE_U8(ctx.r31.u32 + 186, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,274(r31)
	REX_STORE_U8(ctx.r31.u32 + 274, ctx.r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x824D243C;
	sub_8235EC48(ctx, base);
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

DEFINE_REX_FUNC(sub_824D4C40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x824D4C48;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x82213210
	ctx.lr = 0x824D4C5C;
	sub_82213210(ctx, base);
	// lwz r11,4024(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4024);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x824d4c8c
	if (!ctx.cr6.eq) goto loc_824D4C8C;
	// lwz r11,288(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 288);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bgt cr6,0x824d4c8c
	if (ctx.cr6.gt) goto loc_824D4C8C;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r10,20(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x824d4c9c
	if (ctx.cr6.eq) goto loc_824D4C9C;
loc_824D4C8C:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8246b4b8
	ctx.lr = 0x824D4C9C;
	sub_8246B4B8(ctx, base);
loc_824D4C9C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824D60B0) {
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
	// li r5,29
	ctx.r5.s64 = 29;
	// addi r4,r11,-14572
	ctx.r4.s64 = ctx.r11.s64 + -14572;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x824D60D4;
	sub_8246A4B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824d60e8
	if (!ctx.cr0.eq) goto loc_824D60E8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x824d6114
	goto loc_824D6114;
loc_824D60E8:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r3,r10,3204
	ctx.r3.s64 = ctx.r10.s64 + 3204;
	// lwz r11,-15508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15508);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824D6104;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x824D6108;
	sub_8245A220(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r3.u32);
	// stb r11,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r11.u8);
loc_824D6114:
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

DEFINE_REX_FUNC(sub_824D97A0) {
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
	// lbz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 80);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824d97d8
	if (ctx.cr0.eq) goto loc_824D97D8;
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// addi r3,r3,84
	ctx.r3.s64 = ctx.r3.s64 + 84;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824D97D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r3,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r3.u8);
loc_824D97D8:
	// lbz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824d98c8
	if (!ctx.cr0.eq) goto loc_824D98C8;
	// lfs f13,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,76(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// lfs f13,4440(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4440);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x824d980c
	if (!ctx.cr6.gt) goto loc_824D980C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824d98cc
	goto loc_824D98CC;
loc_824D980C:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f12,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f13,732(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 732);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// fnmsubs f0,f0,f13,f12
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lfs f0,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f13,60(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
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
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,60(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
	// lfs f0,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,72(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
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
	// stfs f0,64(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
loc_824D98C8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_824D98CC:
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

DEFINE_REX_FUNC(sub_824E1808) {
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
	// addi r11,r11,-12720
	ctx.r11.s64 = ctx.r11.s64 + -12720;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x824E1834;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824e1844
	if (ctx.cr0.eq) goto loc_824E1844;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x824E1844;
	sub_825E0378(ctx, base);
loc_824E1844:
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

DEFINE_REX_FUNC(sub_824E4180) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x824E4188;
	__savegprlr_18(ctx, base);
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8273af1c
	ctx.lr = 0x824E4190;
	__savefpr_25(ctx, base);
	// addi r12,r1,-176
	ctx.r12.s64 = ctx.r1.s64 + -176;
	// bl 0x8273b374
	ctx.lr = 0x824E4198;
	__savevmx_124(ctx, base);
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1132(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1132);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x824e4804
	if (!ctx.cr6.eq) goto loc_824E4804;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f13,1160(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 1160);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-17036(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17036);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x824e4804
	if (!ctx.cr6.gt) goto loc_824E4804;
	// lwz r7,1152(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 1152);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x824e4804
	if (!ctx.cr6.gt) goto loc_824E4804;
	// lis r8,-32227
	ctx.r8.s64 = -2112028672;
	// lis r6,-32240
	ctx.r6.s64 = -2112880640;
	// addi r5,r8,24772
	ctx.r5.s64 = ctx.r8.s64 + 24772;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lfs f27,24772(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 24772);
	ctx.f27.f64 = double(temp.f32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lfs f25,15088(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 15088);
	ctx.f25.f64 = double(temp.f32);
	// lfs f26,8548(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8548);
	ctx.f26.f64 = double(temp.f32);
	// addi r19,r3,44
	ctx.r19.s64 = ctx.r3.s64 + 44;
	// addi r28,r3,284
	ctx.r28.s64 = ctx.r3.s64 + 284;
	// li r21,1
	ctx.r21.s64 = 1;
	// lis r25,-32112
	ctx.r25.s64 = -2104492032;
	// addi r27,r11,32544
	ctx.r27.s64 = ctx.r11.s64 + 32544;
	// addi r20,r10,32256
	ctx.r20.s64 = ctx.r10.s64 + 32256;
	// addi r22,r9,2668
	ctx.r22.s64 = ctx.r9.s64 + 2668;
	// addi r23,r8,2688
	ctx.r23.s64 = ctx.r8.s64 + 2688;
loc_824E4218:
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// lfs f13,0(r19)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,416
	ctx.r8.s64 = ctx.r1.s64 + 416;
	// lfs f12,4(r19)
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,480
	ctx.r10.s64 = ctx.r1.s64 + 480;
	// stfs f13,492(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// stfs f13,488(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// stfs f13,484(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// ld r6,1140(r31)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r31.u32 + 1140);
	// stfs f13,480(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// addi r5,r1,896
	ctx.r5.s64 = ctx.r1.s64 + 896;
	// lfs f13,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,864
	ctx.r4.s64 = ctx.r1.s64 + 864;
	// stfs f13,268(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// stfs f13,264(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f13,260(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// std r6,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// stfs f13,256(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f12,428(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 428, temp.u32);
	// stfs f12,424(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 424, temp.u32);
	// stfs f12,420(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 420, temp.u32);
	// stfs f12,416(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4);
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
	// fmr f0,f26
	ctx.f0.f64 = ctx.f26.f64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vaddfp128 v61,v60,v61
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824e42c0
	if (ctx.cr6.eq) goto loc_824E42C0;
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
	// cmpw cr6,r24,r11
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x824e42c4
	if (!ctx.cr6.eq) goto loc_824E42C4;
loc_824E42C0:
	// fmr f0,f25
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f25.f64;
loc_824E42C4:
	// lfs f31,864(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 864);
	ctx.f31.f64 = double(temp.f32);
	// addi r11,r1,288
	ctx.r11.s64 = ctx.r1.s64 + 288;
	// addi r10,r1,544
	ctx.r10.s64 = ctx.r1.s64 + 544;
	// stfs f0,556(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 556, temp.u32);
	// stfs f0,552(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 552, temp.u32);
	// addi r7,r1,352
	ctx.r7.s64 = ctx.r1.s64 + 352;
	// stfs f0,548(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 548, temp.u32);
	// addi r5,r1,512
	ctx.r5.s64 = ctx.r1.s64 + 512;
	// stfs f0,544(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 544, temp.u32);
	// addi r6,r1,848
	ctx.r6.s64 = ctx.r1.s64 + 848;
	// stfs f31,300(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// addi r8,r1,448
	ctx.r8.s64 = ctx.r1.s64 + 448;
	// stfs f31,296(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stfs f31,292(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// stfs f31,288(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// addi r30,r1,816
	ctx.r30.s64 = ctx.r1.s64 + 816;
	// stfs f0,364(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stfs f0,360(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// addi r29,r1,688
	ctx.r29.s64 = ctx.r1.s64 + 688;
	// stfs f0,352(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// lwz r18,-13032(r25)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r25.u32 + -13032);
	// stfs f0,356(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// stw r23,592(r1)
	REX_STORE_U32(ctx.r1.u32 + 592, ctx.r23.u32);
	// stfs f31,524(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 524, temp.u32);
	// stw r21,596(r1)
	REX_STORE_U32(ctx.r1.u32 + 596, ctx.r21.u32);
	// stfs f31,520(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 520, temp.u32);
	// li r26,0
	ctx.r26.s64 = 0;
	// stfs f31,512(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 512, temp.u32);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// stfs f31,516(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 516, temp.u32);
	// stfs f0,460(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 460, temp.u32);
	// stfs f0,456(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// lfs f30,896(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 896);
	ctx.f30.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,720
	ctx.r10.s64 = ctx.r1.s64 + 720;
	// lvx128 v57,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,452(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stfs f0,448(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,332(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// lvx128 v59,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,328(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f30,324(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f30,320(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,204(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f30,200(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v59
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v59.f32)));
	// lfs f13,848(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 848);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,720(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 720);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,816(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 816);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// ld r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// stfs f30,196(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f30,192(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lvx128 v58,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v58,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v58.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v57.f32)));
	// stvx128 v58,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,688(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 688);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// ld r10,136(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// std r10,608(r1)
	REX_STORE_U64(ctx.r1.u32 + 608, ctx.r10.u64);
	// std r11,600(r1)
	REX_STORE_U64(ctx.r1.u32 + 600, ctx.r11.u64);
	// beq cr6,0x824e4460
	if (ctx.cr6.eq) goto loc_824E4460;
	// fctiwz f0,f31
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// fctiwz f0,f30
	ctx.f0.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// rotlwi r3,r18,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r18.u32, 0);
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r5,108(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823aefa8
	ctx.lr = 0x824E4424;
	sub_823AEFA8(ctx, base);
	// lfs f0,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lbz r11,81(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r1,592
	ctx.r3.s64 = ctx.r1.s64 + 592;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x823b0938
	ctx.lr = 0x824E4460;
	sub_823B0938(ctx, base);
loc_824E4460:
	// lwz r11,1152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1152);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmpw cr6,r24,r11
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x824e47ec
	if (!ctx.cr6.lt) goto loc_824E47EC;
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// lfs f12,24(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,252(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f12,248(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r11,r1,272
	ctx.r11.s64 = ctx.r1.s64 + 272;
	// stfs f12,240(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// stfs f12,244(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// addi r7,r1,656
	ctx.r7.s64 = ctx.r1.s64 + 656;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,752
	ctx.r6.s64 = ctx.r1.s64 + 752;
	// lfs f11,-4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f11,172(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r3,r1,880
	ctx.r3.s64 = ctx.r1.s64 + 880;
	// stfs f11,164(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f11,160(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,28(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f13,316(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f13,312(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f0,280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f13,304(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f13,308(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v61,v60
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,752(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 752);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,124(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f10,656(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 656);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// ld r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x8231e0d8
	ctx.lr = 0x824E451C;
	sub_8231E0D8(ctx, base);
	// addi r10,r1,368
	ctx.r10.s64 = ctx.r1.s64 + 368;
	// stfs f10,376(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// addi r11,r1,336
	ctx.r11.s64 = ctx.r1.s64 + 336;
	// stfs f9,348(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// stfs f9,344(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f9,340(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// addi r8,r1,784
	ctx.r8.s64 = ctx.r1.s64 + 784;
	// stfs f9,336(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// ld r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// stfs f10,380(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f10,372(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// std r9,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// stfs f10,368(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vrsqrtefp v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// lvx128 v7,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v12,v0,v7
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vcmpeqfp128 v10,v0,v62
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vcmpeqfp128 v8,v0,v62
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v11,v13,v13
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vor v9,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vcmpeqfp128 v6,v13,v62
	simde_mm_store_ps(ctx.v6.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vnmsubfp v7,v12,v11,v7
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v7.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v11,v10,v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// vmaddfp v13,v13,v7,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vsel v12,v13,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8))));
	// vor128 v63,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vcmpeqfp128 v12,v63,v62
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v13,v0,v63
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsel v11,v8,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vsel v11,v13,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v11,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,784(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 784);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f0,f27
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f27.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x824e45cc
	if (!ctx.cr6.eq) goto loc_824E45CC;
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
loc_824E45CC:
	// extsw r11,r5
	ctx.r11.s64 = ctx.r5.s32;
	// lfs f2,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,108(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f1.f64 = double(temp.f32);
	// std r11,584(r1)
	REX_STORE_U64(ctx.r1.u32 + 584, ctx.r11.u64);
	// lfd f13,584(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 584);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f28,f0,f13
	ctx.f28.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// bl 0x825a7c80
	ctx.lr = 0x824E45F0;
	sub_825A7C80(ctx, base);
	// addic. r11,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r11.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x824e47ec
	if (!ctx.cr0.gt) goto loc_824E47EC;
	// lvx128 v127,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
	// stfs f30,412(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// vor128 v126,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// stfs f30,408(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// stfs f30,404(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// vor128 v125,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// stfs f30,400(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// vor128 v124,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// stfs f31,184(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f31,180(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f31,176(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
loc_824E4634:
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// std r11,576(r1)
	REX_STORE_U64(ctx.r1.u32 + 576, ctx.r11.u64);
	// lfd f0,576(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 576);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f31,f0
	ctx.f31.f64 = double(float(ctx.f0.f64));
	// bl 0x82738cc0
	ctx.lr = 0x824E4650;
	sub_82738CC0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// addi r11,r1,400
	ctx.r11.s64 = ctx.r1.s64 + 400;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// addi r9,r1,672
	ctx.r9.s64 = ctx.r1.s64 + 672;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmuls f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82738be0
	ctx.lr = 0x824E4690;
	sub_82738BE0(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lfs f0,672(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 672);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,464
	ctx.r9.s64 = ctx.r1.s64 + 464;
	// stfs f0,468(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 468, temp.u32);
	// addi r11,r1,528
	ctx.r11.s64 = ctx.r1.s64 + 528;
	// stfs f0,464(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// addi r8,r1,736
	ctx.r8.s64 = ctx.r1.s64 + 736;
	// stfs f0,476(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 476, temp.u32);
	// addi r6,r1,560
	ctx.r6.s64 = ctx.r1.s64 + 560;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,496
	ctx.r10.s64 = ctx.r1.s64 + 496;
	// stfs f0,472(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 472, temp.u32);
	// addi r7,r1,704
	ctx.r7.s64 = ctx.r1.s64 + 704;
	// stfs f0,500(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// addi r5,r1,768
	ctx.r5.s64 = ctx.r1.s64 + 768;
	// stfs f0,496(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 496, temp.u32);
	// addi r4,r1,800
	ctx.r4.s64 = ctx.r1.s64 + 800;
	// stfs f0,508(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 508, temp.u32);
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// stfs f0,504(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// stw r23,624(r1)
	REX_STORE_U32(ctx.r1.u32 + 624, ctx.r23.u32);
	// stw r21,628(r1)
	REX_STORE_U32(ctx.r1.u32 + 628, ctx.r21.u32);
	// fmuls f0,f13,f28
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f28.f64));
	// stfs f0,536(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 536, temp.u32);
	// stfs f0,532(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// stfs f0,540(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// stfs f0,528(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v62,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v126.f32)));
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,-13032(r25)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r25.u32 + -13032);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v124
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v124.f32)));
	// vaddfp128 v63,v63,v61
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,704(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 704);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,736(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 736);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,572(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 572, temp.u32);
	// stfs f0,568(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 568, temp.u32);
	// stfs f0,560(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 560, temp.u32);
	// stfs f0,564(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 564, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,396(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// stfs f0,392(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// stfs f0,388(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// stfs f0,384(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v61,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v127.f32)));
	// lfs f0,768(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 768);
	ctx.f0.f64 = double(temp.f32);
	// vaddfp128 v63,v63,v125
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v125.f32)));
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,800(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 800);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,832(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 832);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ld r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r11,632(r1)
	REX_STORE_U64(ctx.r1.u32 + 632, ctx.r11.u64);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,640(r1)
	REX_STORE_U64(ctx.r1.u32 + 640, ctx.r11.u64);
	// beq cr6,0x824e47dc
	if (ctx.cr6.eq) goto loc_824E47DC;
	// lfs f0,196(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lbz r11,81(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addi r3,r1,624
	ctx.r3.s64 = ctx.r1.s64 + 624;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823b0938
	ctx.lr = 0x824E47DC;
	sub_823B0938(ctx, base);
loc_824E47DC:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r22,624(r1)
	REX_STORE_U32(ctx.r1.u32 + 624, ctx.r22.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// bne 0x824e4634
	if (!ctx.cr0.eq) goto loc_824E4634;
loc_824E47EC:
	// lwz r7,1152(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 1152);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// stw r22,592(r1)
	REX_STORE_U32(ctx.r1.u32 + 592, ctx.r22.u32);
	// addi r28,r28,28
	ctx.r28.s64 = ctx.r28.s64 + 28;
	// cmpw cr6,r24,r7
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x824e4218
	if (ctx.cr6.lt) goto loc_824E4218;
loc_824E4804:
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// addi r12,r1,-176
	ctx.r12.s64 = ctx.r1.s64 + -176;
	// bl 0x8273b60c
	ctx.lr = 0x824E4810;
	__restvmx_124(ctx, base);
	// addi r12,r1,-120
	ctx.r12.s64 = ctx.r1.s64 + -120;
	// bl 0x8273af68
	ctx.lr = 0x824E4818;
	__restfpr_25(ctx, base);
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82522320) {
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
	// lwz r11,344(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 344);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stb r10,269(r3)
	REX_STORE_U8(ctx.r3.u32 + 269, ctx.r10.u8);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x825223bc
	if (!ctx.cr6.eq) goto loc_825223BC;
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
	ctx.lr = 0x82522364;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82522378
	if (ctx.cr0.eq) goto loc_82522378;
	// bl 0x82524158
	ctx.lr = 0x82522370;
	sub_82524158(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8252237c
	goto loc_8252237C;
loc_82522378:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8252237C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825223bc
	if (ctx.cr6.eq) goto loc_825223BC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82522390;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,344(r30)
	REX_STORE_U32(ctx.r30.u32 + 344, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x825223bc
	if (!ctx.cr6.eq) goto loc_825223BC;
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
	ctx.lr = 0x825223BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825223BC:
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

DEFINE_REX_FUNC(sub_82527750) {
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
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,88(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
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
	// bne cr6,0x82527794
	if (!ctx.cr6.eq) goto loc_82527794;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825277a4
	if (!ctx.cr6.eq) goto loc_825277A4;
loc_82527794:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// ld r11,3456(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// b 0x82527890
	goto loc_82527890;
loc_825277A4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x825277AC;
	sub_82430A88(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r7,r11,3456
	ctx.r7.s64 = ctx.r11.s64 + 3456;
	// lfs f12,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// lfs f0,3456(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3456);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r4,-32592
	ctx.r4.s64 = ctx.r4.s64 + -32592;
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
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
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
	// lfs f0,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
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
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
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
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
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
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
loc_82527890:
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

DEFINE_REX_FUNC(sub_82533C70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82533C78;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r11,r11,-440
	ctx.r11.s64 = ctx.r11.s64 + -440;
	// addi r31,r3,296
	ctx.r31.s64 = ctx.r3.s64 + 296;
	// li r30,2
	ctx.r30.s64 = 2;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
loc_82533C98:
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x82533cbc
	if (ctx.cr6.eq) goto loc_82533CBC;
	// lwz r3,-12824(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x82533CAC;
	sub_82599798(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
loc_82533CBC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x82533c98
	if (!ctx.cr0.eq) goto loc_82533C98;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r11,r11,-4968
	ctx.r11.s64 = ctx.r11.s64 + -4968;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x82533CDC;
	sub_82469EE8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82535688) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82535690;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// addi r11,r11,296
	ctx.r11.s64 = ctx.r11.s64 + 296;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r3,384
	ctx.r31.s64 = ctx.r3.s64 + 384;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r28,2
	ctx.r28.s64 = 2;
	// lwz r3,-12860(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -12860);
loc_825356B4:
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x825356e4
	if (ctx.cr6.eq) goto loc_825356E4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825356d4
	if (ctx.cr6.eq) goto loc_825356D4;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8246d2e8
	ctx.lr = 0x825356D0;
	sub_8246D2E8(ctx, base);
	// lwz r3,-12860(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -12860);
loc_825356D4:
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,-8(r31)
	REX_STORE_U32(ctx.r31.u32 + -8, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_825356E4:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x825356b4
	if (!ctx.cr0.eq) goto loc_825356B4;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x825a4750
	ctx.lr = 0x825356F8;
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
	ctx.lr = 0x8253570C;
	sub_82469EE8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82537DC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82537DD0;
	__savegprlr_23(ctx, base);
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f30.u64);
	// stfd f31,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-608(r1)
	ea = -608 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,340(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 340);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82538378
	if (!ctx.cr6.eq) goto loc_82538378;
	// lbz r11,330(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 330);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82538378
	if (ctx.cr0.eq) goto loc_82538378;
	// lwz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82537E10;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// clrlwi. r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// li r24,1
	ctx.r24.s64 = 1;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
	// addi r23,r11,2668
	ctx.r23.s64 = ctx.r11.s64 + 2668;
	// addi r25,r10,2688
	ctx.r25.s64 = ctx.r10.s64 + 2688;
	// beq 0x825380a4
	if (ctx.cr0.eq) goto loc_825380A4;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,136(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82537E48;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r26,r3,16
	ctx.r26.u64 = ctx.r3.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq 0x825380a4
	if (ctx.cr0.eq) goto loc_825380A4;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x825380a4
	if (ctx.cr6.eq) goto loc_825380A4;
loc_82537E5C:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r6,0
	ctx.r6.s64 = 0;
	// clrlwi r5,r28,16
	ctx.r5.u64 = ctx.r28.u32 & 0xFFFF;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82537E80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82538098
	if (ctx.cr0.eq) goto loc_82538098;
	// lwz r3,-13032(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -13032);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r31,352
	ctx.r30.s64 = ctx.r31.s64 + 352;
loc_82537E94:
	// clrlwi. r11,r29,31
	ctx.r11.u64 = ctx.r29.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82538088
	if (ctx.cr0.eq) goto loc_82538088;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lwa r11,160(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 160));
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lwa r7,172(r1)
	ctx.r7.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 172));
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// std r11,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.r11.u64);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// std r7,312(r1)
	REX_STORE_U64(ctx.r1.u32 + 312, ctx.r7.u64);
	// lwa r11,168(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 168));
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// std r11,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r11.u64);
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// lwa r7,164(r1)
	ctx.r7.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 164));
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// lfd f10,288(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 288);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// std r9,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.r9.u64);
	// lfd f11,296(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 296);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lfd f9,312(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 312);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// stfs f13,284(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// stfs f11,252(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f11,248(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// stfs f11,244(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f11,240(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// stfs f13,280(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// stfs f13,276(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// stfs f13,272(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stw r24,420(r1)
	REX_STORE_U32(ctx.r1.u32 + 420, ctx.r24.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// frsp f11,f10
	ctx.f11.f64 = double(float(ctx.f10.f64));
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// frsp f10,f9
	ctx.f10.f64 = double(float(ctx.f9.f64));
	// stfs f10,268(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f10,264(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stw r25,416(r1)
	REX_STORE_U32(ctx.r1.u32 + 416, ctx.r25.u32);
	// stfs f10,260(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stfs f10,256(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// lvx128 v59,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfd f12,192(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 192);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
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
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f11,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// vaddfp128 v63,v63,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stfs f11,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,352
	ctx.r10.s64 = ctx.r1.s64 + 352;
	// stfs f12,236(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f12,232(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f12,228(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f12,224(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,368(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,320(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f11.f64 = double(temp.f32);
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,336(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 336);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// lfs f10,352(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// std r11,424(r1)
	REX_STORE_U64(ctx.r1.u32 + 424, ctx.r11.u64);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,432(r1)
	REX_STORE_U64(ctx.r1.u32 + 432, ctx.r11.u64);
	// beq cr6,0x82538084
	if (ctx.cr6.eq) goto loc_82538084;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.f0.u64);
	// lwz r4,308(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823aefa8
	ctx.lr = 0x82538048;
	sub_823AEFA8(ctx, base);
	// lfs f0,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lbz r11,81(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r10,r31,68
	ctx.r10.s64 = ctx.r31.s64 + 68;
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x823b0938
	ctx.lr = 0x82538080;
	sub_823B0938(ctx, base);
	// lwz r3,-13032(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -13032);
loc_82538084:
	// stw r23,416(r1)
	REX_STORE_U32(ctx.r1.u32 + 416, ctx.r23.u32);
loc_82538088:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmplwi cr6,r29,16
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 16, ctx.xer);
	// blt cr6,0x82537e94
	if (ctx.cr6.lt) goto loc_82537E94;
loc_82538098:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplw cr6,r28,r26
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r26.u32, ctx.xer);
	// blt cr6,0x82537e5c
	if (ctx.cr6.lt) goto loc_82537E5C;
loc_825380A4:
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
	ctx.lr = 0x825380BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82538378
	if (ctx.cr0.eq) goto loc_82538378;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,136(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825380DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r28,r3,16
	ctx.r28.u64 = ctx.r3.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x82538378
	if (ctx.cr0.eq) goto loc_82538378;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82538378
	if (ctx.cr6.eq) goto loc_82538378;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r9,r10,12472
	ctx.r9.s64 = ctx.r10.s64 + 12472;
	// addi r30,r11,32720
	ctx.r30.s64 = ctx.r11.s64 + 32720;
	// lfs f30,12472(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,-236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -236);
	ctx.f31.f64 = double(temp.f32);
loc_82538108:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r6,0
	ctx.r6.s64 = 0;
	// clrlwi r5,r29,16
	ctx.r5.u64 = ctx.r29.u32 & 0xFFFF;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253812C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8253836c
	if (ctx.cr0.eq) goto loc_8253836C;
	// lbz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 308);
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82538148
	if (ctx.cr0.eq) goto loc_82538148;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
loc_82538148:
	// lwa r11,164(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 164));
	// stfs f0,236(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// lwa r10,160(r1)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 160));
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwa r9,172(r1)
	ctx.r9.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 172));
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwa r10,168(r1)
	ctx.r10.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 168));
	// lfd f12,112(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.r11.u64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// std r9,312(r1)
	REX_STORE_U64(ctx.r1.u32 + 312, ctx.r9.u64);
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// std r10,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.r10.u64);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// addi r10,r1,368
	ctx.r10.s64 = ctx.r1.s64 + 368;
	// lfs f0,348(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,344(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,496
	ctx.r6.s64 = ctx.r1.s64 + 496;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r10,r1,480
	ctx.r10.s64 = ctx.r1.s64 + 480;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stfs f12,268(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f12,264(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stw r24,388(r1)
	REX_STORE_U32(ctx.r1.u32 + 388, ctx.r24.u32);
	// stfs f12,260(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stw r25,384(r1)
	REX_STORE_U32(ctx.r1.u32 + 384, ctx.r25.u32);
	// stfs f12,256(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
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
	// lfd f11,304(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 304);
	// lfd f10,312(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 312);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lfd f9,288(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 288);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// stfs f13,220(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f13,216(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lfs f8,352(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f8.f64 = double(temp.f32);
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f0,332(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f0,328(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f0,324(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// stfs f11,188(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f11,184(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// stfs f11,180(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// frsp f12,f9
	ctx.f12.f64 = double(float(ctx.f9.f64));
	// stfs f11,176(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lfs f11,368(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f10,348(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// stfs f10,344(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// stfs f10,340(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f10,336(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
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
	// stfs f11,192(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f8,196(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,336
	ctx.r11.s64 = ctx.r1.s64 + 336;
	// vaddfp128 v62,v61,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// addi r7,r1,320
	ctx.r7.s64 = ctx.r1.s64 + 320;
	// lwz r3,-13032(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -13032);
	// addi r5,r1,464
	ctx.r5.s64 = ctx.r1.s64 + 464;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,448
	ctx.r9.s64 = ctx.r1.s64 + 448;
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// vaddfp128 v61,v61,v60
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v59,v60
	simde_mm_store_ps(ctx.v60.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,496(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 496);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,464(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 464);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// lfs f11,448(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 448);
	ctx.f11.f64 = double(temp.f32);
	// std r10,392(r1)
	REX_STORE_U64(ctx.r1.u32 + 392, ctx.r10.u64);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f11,480(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 480);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,400(r1)
	REX_STORE_U64(ctx.r1.u32 + 400, ctx.r11.u64);
	// beq cr6,0x82538368
	if (ctx.cr6.eq) goto loc_82538368;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.f0.u64);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.f13.u64);
	// lwz r4,276(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r5,300(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 300);
	// bl 0x823aefa8
	ctx.lr = 0x82538330;
	sub_823AEFA8(ctx, base);
	// lfs f0,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.f0.u64);
	// lwz r8,276(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x823b0938
	ctx.lr = 0x82538368;
	sub_823B0938(ctx, base);
loc_82538368:
	// stw r23,384(r1)
	REX_STORE_U32(ctx.r1.u32 + 384, ctx.r23.u32);
loc_8253836C:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x82538108
	if (ctx.cr6.lt) goto loc_82538108;
loc_82538378:
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82565DB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x82565DB8;
	__savegprlr_20(ctx, base);
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r7,110
	ctx.r7.s64 = 110;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x82565DF4;
	sub_825190E8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r8,r11,32720
	ctx.r8.s64 = ctx.r11.s64 + 32720;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r27,0
	ctx.r27.s64 = 0;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r9,9608
	ctx.r10.s64 = ctx.r9.s64 + 9608;
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi r9,r26,24
	ctx.r9.u64 = ctx.r26.u32 & 0xFF;
	// lfs f0,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r31,300
	ctx.r26.s64 = ctx.r31.s64 + 300;
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stfs f12,300(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stfs f13,304(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stw r30,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r30.u32);
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// stb r27,324(r31)
	REX_STORE_U8(ctx.r31.u32 + 324, ctx.r27.u8);
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stb r27,336(r31)
	REX_STORE_U8(ctx.r31.u32 + 336, ctx.r27.u8);
	// stfs f0,320(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// stb r9,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r9.u8);
	// stfs f31,328(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 328, temp.u32);
	// stfs f0,332(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 332, temp.u32);
	// bne cr6,0x82565e80
	if (!ctx.cr6.eq) goto loc_82565E80;
	// lfs f0,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82565e84
	goto loc_82565E84;
loc_82565E80:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
loc_82565E84:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lwz r7,100(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// ori r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 | 32;
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f13,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// addi r11,r11,-6828
	ctx.r11.s64 = ctx.r11.s64 + -6828;
	// li r25,1
	ctx.r25.s64 = 1;
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// addi r10,r11,44
	ctx.r10.s64 = ctx.r11.s64 + 44;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// rlwinm r8,r30,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// stfs f13,312(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r27,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r27.u32);
	// rlwimi r7,r25,0,30,31
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x3) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFFC);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r7,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r7.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r6,r11,44
	ctx.r6.s64 = ctx.r11.s64 + 44;
	// lfs f10,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r24,r1,96
	ctx.r24.s64 = ctx.r1.s64 + 96;
	// addi r22,r1,96
	ctx.r22.s64 = ctx.r1.s64 + 96;
	// addi r20,r1,96
	ctx.r20.s64 = ctx.r1.s64 + 96;
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfsx f11,r8,r10
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	ctx.f11.f64 = double(temp.f32);
	// addi r23,r1,128
	ctx.r23.s64 = ctx.r1.s64 + 128;
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r21,r1,128
	ctx.r21.s64 = ctx.r1.s64 + 128;
	// lfsx f12,r8,r6
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// lvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
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
	// stvx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
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
	// lvx128 v63,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r10.u64);
	// bge cr6,0x82566000
	if (!ctx.cr6.lt) goto loc_82566000;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// ble cr6,0x82566000
	if (!ctx.cr6.gt) goto loc_82566000;
	// fsubs f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// stfs f1,328(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 328, temp.u32);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addi r6,r30,1
	ctx.r6.s64 = ctx.r30.s64 + 1;
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x82565d28
	ctx.lr = 0x82565FFC;
	sub_82565D28(ctx, base);
	// stb r25,324(r31)
	REX_STORE_U8(ctx.r31.u32 + 324, ctx.r25.u8);
loc_82566000:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,88(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
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
	// bne cr6,0x82566080
	if (!ctx.cr6.eq) goto loc_82566080;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82566080
	if (ctx.cr6.eq) goto loc_82566080;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82566080
	if (ctx.cr0.eq) goto loc_82566080;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82430a88
	ctx.lr = 0x8256604C;
	sub_82430A88(ctx, base);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lwz r10,2340(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// beq cr6,0x82566080
	if (ctx.cr6.eq) goto loc_82566080;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82566074;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82566080
	if (!ctx.cr6.eq) goto loc_82566080;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
loc_82566080:
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82566234
	if (!ctx.cr6.eq) goto loc_82566234;
	// lfs f13,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f12,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82566170
	if (!ctx.cr0.eq) goto loc_82566170;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// addi r11,r11,-31872
	ctx.r11.s64 = ctx.r11.s64 + -31872;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,-32216(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32216);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// fmuls f13,f13,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
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
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
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
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
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
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
loc_82566164:
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// b 0x82566284
	goto loc_82566284;
loc_82566170:
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f12,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r30,r1,128
	ctx.r30.s64 = ctx.r1.s64 + 128;
	// lfs f0,-32216(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32216);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r11,r11,-30944
	ctx.r11.s64 = ctx.r11.s64 + -30944;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82566164
	goto loc_82566164;
loc_82566234:
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
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
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
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
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
loc_82566284:
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stb r27,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r27.u8);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
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
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,0(r26)
	REX_STORE_U64(ctx.r26.u32 + 0, ctx.r11.u64);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-112(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8259CDB8) {
	REX_FUNC_PROLOGUE();
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r9,33(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 33);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x8259cdf8
	if (!ctx.cr0.eq) goto loc_8259CDF8;
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
loc_8259CDD0:
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8259cde4
	if (!ctx.cr6.lt) goto loc_8259CDE4;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8259cdec
	goto loc_8259CDEC;
loc_8259CDE4:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_8259CDEC:
	// lbz r8,33(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 33);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x8259cdd0
	if (ctx.cr0.eq) goto loc_8259CDD0;
loc_8259CDF8:
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r10.u32);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8259ce20
	if (ctx.cr6.eq) goto loc_8259CE20;
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8259ce20
	if (ctx.cr6.lt) goto loc_8259CE20;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// b 0x8259ce28
	goto loc_8259CE28;
loc_8259CE20:
	// stw r11,-12(r1)
	REX_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// addi r11,r1,-12
	ctx.r11.s64 = ctx.r1.s64 + -12;
loc_8259CE28:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8259FBD8) {
	REX_FUNC_PROLOGUE();
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// b 0x8259fc0c
	goto loc_8259FC0C;
loc_8259FBE4:
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// blt cr6,0x8259fc14
	if (ctx.cr6.lt) goto loc_8259FC14;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// ble cr6,0x8259fc08
	if (!ctx.cr6.gt) goto loc_8259FC08;
	// cmplwi cr6,r11,13
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 13, ctx.xer);
	// beq cr6,0x8259fc08
	if (ctx.cr6.eq) goto loc_8259FC08;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// bne cr6,0x8259fc14
	if (!ctx.cr6.eq) goto loc_8259FC14;
loc_8259FC08:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_8259FC0C:
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x8259fbe4
	if (ctx.cr6.lt) goto loc_8259FBE4;
loc_8259FC14:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
loc_8259FC20:
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8259fc44
	if (ctx.cr6.eq) goto loc_8259FC44;
	// cmpwi cr6,r11,13
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 13, ctx.xer);
	// beq cr6,0x8259fc44
	if (ctx.cr6.eq) goto loc_8259FC44;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x8259fc20
	if (ctx.cr6.lt) goto loc_8259FC20;
loc_8259FC44:
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// bge cr6,0x8259fc8c
	if (!ctx.cr6.lt) goto loc_8259FC8C;
loc_8259FC54:
	// lbz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// blt cr6,0x8259fc80
	if (ctx.cr6.lt) goto loc_8259FC80;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// ble cr6,0x8259fc8c
	if (!ctx.cr6.gt) goto loc_8259FC8C;
	// cmplwi cr6,r11,13
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 13, ctx.xer);
	// beq cr6,0x8259fc8c
	if (ctx.cr6.eq) goto loc_8259FC8C;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// beq cr6,0x8259fc8c
	if (ctx.cr6.eq) goto loc_8259FC8C;
	// cmplwi cr6,r11,35
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 35, ctx.xer);
	// beq cr6,0x8259fc8c
	if (ctx.cr6.eq) goto loc_8259FC8C;
loc_8259FC80:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x8259fc54
	if (ctx.cr6.lt) goto loc_8259FC54;
loc_8259FC8C:
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// subf r9,r10,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r8,r11,126
	ctx.r8.s64 = ctx.r11.s64 + 126;
	// stb r9,0(r7)
	REX_STORE_U8(ctx.r7.u32 + 0, ctx.r9.u8);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8259fce0
	if (!ctx.cr6.lt) goto loc_8259FCE0;
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
loc_8259FCB4:
	// add r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 + ctx.r11.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8259fcdc
	if (!ctx.cr6.lt) goto loc_8259FCDC;
	// lbz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8259fcdc
	if (ctx.cr0.eq) goto loc_8259FCDC;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8259fcb4
	if (ctx.cr6.lt) goto loc_8259FCB4;
loc_8259FCDC:
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
loc_8259FCE0:
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825A71B0) {
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
	ctx.lr = 0x825A71E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,40(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825a71fc
	if (ctx.cr6.eq) goto loc_825A71FC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A71FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825A71FC:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825a7214
	if (!ctx.cr6.eq) goto loc_825A7214;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x825a7228
	goto loc_825A7228;
loc_825A7214:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r11,52(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A7228;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825A7228:
	// stw r3,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x825A723C;
	sub_8273A030(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A7250;
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

DEFINE_REX_FUNC(sub_825AC960) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// b 0x825e02a0
	sub_825E02A0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825ACB78) {
	REX_FUNC_PROLOGUE();
	// stb r4,68(r3)
	REX_STORE_U8(ctx.r3.u32 + 68, ctx.r4.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825ACCA0) {
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
	// bl 0x825accf8
	ctx.lr = 0x825ACCC0;
	sub_825ACCF8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825accd8
	if (ctx.cr0.eq) goto loc_825ACCD8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x825accd8
	if (ctx.cr6.eq) goto loc_825ACCD8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x825ACCD8;
	sub_825E0378(ctx, base);
loc_825ACCD8:
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

DEFINE_REX_FUNC(sub_825AF0C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r9,3(r4)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lbz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// lbz r7,1(r4)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// lbz r8,2(r4)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f12,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f0
	ctx.f10.f64 = double(ctx.f0.s64);
	// lwz r9,16(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lfs f0,24(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f3,f10,f0
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fmuls f2,f11,f0
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmuls f4,f12,f0
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x8261b6c8
	ctx.lr = 0x825AF148;
	sub_8261B6C8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825B3350) {
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
	// bl 0x827484a0
	ctx.lr = 0x825B3368;
	sub_827484A0(ctx, base);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
loc_825B3378:
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
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x825b339c
	if (!ctx.cr6.eq) goto loc_825B339C;
	// stwcx. r7,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r7.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825b3378
	if (!ctx.cr0.eq) goto loc_825B3378;
	// b 0x825b33a4
	goto loc_825B33A4;
loc_825B339C:
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
loc_825B33A4:
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,-1
	ctx.r5.s64 = -1;
	// lis r4,-30009
	ctx.r4.s64 = -1966669824;
	// subf r3,r6,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r6.u64;
	// ori r4,r4,18
	ctx.r4.u64 = ctx.r4.u64 | 18;
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r9,r4
	ctx.r3.u64 = ctx.r9.u64 & ctx.r4.u64;
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

DEFINE_REX_FUNC(sub_825B7E00) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,488
	ctx.r3.s64 = ctx.r3.s64 + 488;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825B7F60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x825B7F68;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,496
	ctx.r3.s64 = 496;
	// ori r4,r4,32802
	ctx.r4.u64 = ctx.r4.u64 | 32802;
	// bl 0x8263b678
	ctx.lr = 0x825B7F84;
	sub_8263B678(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825b8040
	if (ctx.cr6.eq) goto loc_825B8040;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x825c0368
	ctx.lr = 0x825B7F9C;
	sub_825C0368(ctx, base);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// stw r30,264(r3)
	REX_STORE_U32(ctx.r3.u32 + 264, ctx.r30.u32);
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// addi r11,r3,268
	ctx.r11.s64 = ctx.r3.s64 + 268;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r6,r10,18440
	ctx.r6.s64 = ctx.r10.s64 + 18440;
	// addi r5,r8,18356
	ctx.r5.s64 = ctx.r8.s64 + 18356;
	// addi r4,r7,18564
	ctx.r4.s64 = ctx.r7.s64 + 18564;
	// stw r6,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r10,r11,8
	ctx.r10.s64 = ctx.r11.s64 + 8;
	// stw r5,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// stw r4,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// addi r28,r3,8
	ctx.r28.s64 = ctx.r3.s64 + 8;
	// stw r10,272(r3)
	REX_STORE_U32(ctx.r3.u32 + 272, ctx.r10.u32);
	// addi r3,r3,264
	ctx.r3.s64 = ctx.r3.s64 + 264;
	// stw r30,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r30.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r30,472(r31)
	REX_STORE_U32(ctx.r31.u32 + 472, ctx.r30.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r30,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r30.u32);
	// stw r30,480(r31)
	REX_STORE_U32(ctx.r31.u32 + 480, ctx.r30.u32);
	// stw r9,484(r31)
	REX_STORE_U32(ctx.r31.u32 + 484, ctx.r9.u32);
	// stw r30,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r30.u32);
loc_825B7FFC:
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// addi r8,r9,4
	ctx.r8.s64 = ctx.r9.s64 + 4;
	// stw r7,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// bdnz 0x825b7ffc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825B7FFC;
	// stw r30,488(r31)
	REX_STORE_U32(ctx.r31.u32 + 488, ctx.r30.u32);
	// stw r30,492(r31)
	REX_STORE_U32(ctx.r31.u32 + 492, ctx.r30.u32);
	// bl 0x825c1538
	ctx.lr = 0x825B8028;
	sub_825C1538(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825b8058
	if (ctx.cr6.lt) goto loc_825B8058;
	// stw r31,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_825B8040:
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// stw r30,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r30.u32);
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_825B8058:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825B8070;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825BDAC0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-24
	ctx.r3.s64 = ctx.r3.s64 + -24;
	// b 0x825bc7a8
	sub_825BC7A8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825BDF38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825BDF40;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825BDF5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,72(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825BDF74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r29,1,15,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0x1FFFE;
	// lwz r9,66(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 66);
	// clrlwi r10,r29,16
	ctx.r10.u64 = ctx.r29.u32 & 0xFFFF;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r3,r11,r31
	ctx.r3.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C0DA0) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// lis r3,32767
	ctx.r3.s64 = 2147418112;
	// cmplwi cr6,r8,255
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 255, ctx.xer);
	// ori r3,r3,65535
	ctx.r3.u64 = ctx.r3.u64 | 65535;
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825c0dcc
	if (ctx.cr6.eq) goto loc_825C0DCC;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// b 0x825c0dd4
	goto loc_825C0DD4;
loc_825C0DCC:
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r9,r9,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
loc_825C0DD4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825c0de4
	if (ctx.cr6.eq) goto loc_825C0DE4;
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// b 0x825c0de8
	goto loc_825C0DE8;
loc_825C0DE4:
	// li r10,0
	ctx.r10.s64 = 0;
loc_825C0DE8:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r7,16(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mullw r11,r8,r9
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rldicl r5,r7,59,46
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u64, 59) & 0x3FFFF;
	// clrldi r4,r6,32
	ctx.r4.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// tdllei r5,0
	if (ctx.r5.s64 == 0ll || ctx.r5.u64 < 0ull) ppc_trap(ctx, base, 0);
	// mulli r3,r4,1000
	ctx.r3.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(1000));
	// rotldi r11,r3,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u64, 1);
	// divd r10,r3,r5
	ctx.r10.s64 = (ctx.r5.s64 && !(ctx.r3.s64 == INT64_MIN && ctx.r5.s64 == -1)) ? ctx.r3.s64 / ctx.r5.s64 : 0;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// extsw r3,r10
	ctx.r3.s64 = ctx.r10.s32;
	// andc r8,r5,r9
	ctx.r8.u64 = ctx.r5.u64 & ~ctx.r9.u64;
	// tdlgei r8,-1
	if (ctx.r8.s64 == -1ll || ctx.r8.u64 > 18446744073709551615ull) ppc_trap(ctx, base, 0);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825C4618) {
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
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x825c46cc
	if (!ctx.cr6.eq) goto loc_825C46CC;
	// bl 0x825b32d0
	ctx.lr = 0x825C4640;
	sub_825B32D0(ctx, base);
	// lbz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 24);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r3,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
	// stb r11,44(r31)
	REX_STORE_U8(ctx.r31.u32 + 44, ctx.r11.u8);
	// beq cr6,0x825c46d8
	if (ctx.cr6.eq) goto loc_825C46D8;
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
loc_825C4664:
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r7,r8,0,2,2
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20000000;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x825c4688
	if (ctx.cr6.eq) goto loc_825C4688;
	// bl 0x825ce120
	ctx.lr = 0x825C4684;
	sub_825CE120(ctx, base);
	// b 0x825c46ac
	goto loc_825C46AC;
loc_825C4688:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// addi r11,r11,76
	ctx.r11.s64 = ctx.r11.s64 + 76;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r3,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r3.u32);
	// stw r3,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
loc_825C46AC:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lbz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 24);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// blt cr6,0x825c4664
	if (ctx.cr6.lt) goto loc_825C4664;
	// b 0x825c46d8
	goto loc_825C46D8;
loc_825C46CC:
	// lbz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 32);
	// ori r10,r11,64
	ctx.r10.u64 = ctx.r11.u64 | 64;
	// stb r10,32(r31)
	REX_STORE_U8(ctx.r31.u32 + 32, ctx.r10.u8);
loc_825C46D8:
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

DEFINE_REX_FUNC(sub_825CB338) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825CB340;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,216(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 216);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r7,r10,20892
	ctx.r7.s64 = ctx.r10.s64 + 20892;
	// addi r6,r9,20948
	ctx.r6.s64 = ctx.r9.s64 + 20948;
	// addi r5,r8,21036
	ctx.r5.s64 = ctx.r8.s64 + 21036;
	// stw r7,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// ori r4,r11,128
	ctx.r4.u64 = ctx.r11.u64 | 128;
	// stw r6,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// stw r5,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r4,216(r3)
	REX_STORE_U8(ctx.r3.u32 + 216, ctx.r4.u8);
	// bl 0x825c3e88
	ctx.lr = 0x825CB37C;
	sub_825C3E88(ctx, base);
	// lwz r3,108(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// beq cr6,0x825cb3ec
	if (ctx.cr6.eq) goto loc_825CB3EC;
	// bl 0x825cb258
	ctx.lr = 0x825CB394;
	sub_825CB258(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825cb3c8
	if (ctx.cr6.eq) goto loc_825CB3C8;
	// lwz r10,108(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r11,116(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 116);
	// addi r11,r11,296
	ctx.r11.s64 = ctx.r11.s64 + 296;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// b 0x825cb3e8
	goto loc_825CB3E8;
loc_825CB3C8:
	// lwz r3,108(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cb3e8
	if (ctx.cr6.eq) goto loc_825CB3E8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CB3E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825CB3E8:
	// stw r29,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r29.u32);
loc_825CB3EC:
	// lwz r3,112(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825cb454
	if (ctx.cr6.eq) goto loc_825CB454;
	// bl 0x825cb258
	ctx.lr = 0x825CB3FC;
	sub_825CB258(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825cb430
	if (ctx.cr6.eq) goto loc_825CB430;
	// lwz r10,112(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r11,116(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 116);
	// addi r11,r11,296
	ctx.r11.s64 = ctx.r11.s64 + 296;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// b 0x825cb450
	goto loc_825CB450;
loc_825CB430:
	// lwz r3,112(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cb450
	if (ctx.cr6.eq) goto loc_825CB450;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CB450;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825CB450:
	// stw r29,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r29.u32);
loc_825CB454:
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825cb4ac
	if (ctx.cr6.eq) goto loc_825CB4AC;
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lhz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 28);
	// addi r10,r11,284
	ctx.r10.s64 = ctx.r11.s64 + 284;
	// lwz r11,288(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x825cb494
	if (ctx.cr6.eq) goto loc_825CB494;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
loc_825CB47C:
	// lhz r8,20(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 20);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x825cb498
	if (ctx.cr6.eq) goto loc_825CB498;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x825cb47c
	if (!ctx.cr6.eq) goto loc_825CB47C;
loc_825CB494:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_825CB498:
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825CB4AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825CB4AC:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x825cb4e8
	if (!ctx.cr6.eq) goto loc_825CB4E8;
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CB4C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825cb4e8
	if (ctx.cr6.eq) goto loc_825CB4E8;
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lhz r4,28(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 28);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,160(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CB4E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825CB4E8:
	// lhz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825cb500
	if (!ctx.cr6.eq) goto loc_825CB500;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825c3e88
	ctx.lr = 0x825CB500;
	sub_825C3E88(ctx, base);
loc_825CB500:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r11,18140
	ctx.r10.s64 = ctx.r11.s64 + 18140;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825E02A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825E02A8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E02C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E02DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x825e02e8
	if (!ctx.cr6.lt) goto loc_825E02E8;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_825E02E8:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// add r11,r28,r30
	ctx.r11.u64 = ctx.r28.u64 + ctx.r30.u64;
	// addi r9,r30,-1
	ctx.r9.s64 = ctx.r30.s64 + -1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// not r9,r9
	ctx.r9.u64 = ~ctx.r9.u64;
	// addi r8,r30,15
	ctx.r8.s64 = ctx.r30.s64 + 15;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// and r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ctx.r9.u64;
	// and r29,r8,r9
	ctx.r29.u64 = ctx.r8.u64 & ctx.r9.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825E0324;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x825e0350
	if (!ctx.cr0.eq) goto loc_825E0350;
	// li r30,0
	ctx.r30.s64 = 0;
loc_825E0330:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E0344;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
loc_825E0350:
	// add r11,r3,r29
	ctx.r11.u64 = ctx.r3.u64 + ctx.r29.u64;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// stw r31,-16(r11)
	REX_STORE_U32(ctx.r11.u32 + -16, ctx.r31.u32);
	// stw r3,-12(r11)
	REX_STORE_U32(ctx.r11.u32 + -12, ctx.r3.u32);
	// stw r28,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r28.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x825e0330
	goto loc_825E0330;
}

DEFINE_REX_FUNC(sub_825E53B8) {
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
	ctx.lr = 0x825E53D8;
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

DEFINE_REX_FUNC(sub_825E6078) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x825E6080;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E609C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825e60d8
	if (ctx.cr0.eq) goto loc_825E60D8;
	// lwz r3,60(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// addi r30,r31,60
	ctx.r30.s64 = ctx.r31.s64 + 60;
	// bl 0x8273c660
	ctx.lr = 0x825E60B0;
	sub_8273C660(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r11,-16379
	ctx.r11.s64 = -1073414144;
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// ori r3,r11,3
	ctx.r3.u64 = ctx.r11.u64 | 3;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lbz r10,66(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 66);
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// stb r10,66(r31)
	REX_STORE_U8(ctx.r31.u32 + 66, ctx.r10.u8);
	// stw r3,44(r28)
	REX_STORE_U32(ctx.r28.u32 + 44, ctx.r3.u32);
	// b 0x825e633c
	goto loc_825E633C;
loc_825E60D8:
	// lwz r8,24(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r8,9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 9, ctx.xer);
	// bgt cr6,0x825e6310
	if (ctx.cr6.gt) goto loc_825E6310;
	// lis r12,-32226
	ctx.r12.s64 = -2111963136;
	// addi r12,r12,-6848
	ctx.r12.s64 = ctx.r12.s64 + -6848;
	// lbzx r0,r12,r8
	ctx.r0.u64 = REX_LOAD_U8(ctx.r12.u32 + ctx.r8.u32);
	// rlwinm r0,r0,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r0.u32 | (ctx.r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32162
	ctx.r12.s64 = -2107768832;
	// nop 
	// addi r12,r12,24848
	ctx.r12.s64 = ctx.r12.s64 + 24848;
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r8.u32) {
	case 0:
		goto loc_825E6110;
	case 1:
		goto loc_825E6118;
	case 2:
		goto loc_825E6118;
	case 3:
		goto loc_825E61E0;
	case 4:
		goto loc_825E61E0;
	case 5:
		goto loc_825E6284;
	case 6:
		goto loc_825E62AC;
	case 7:
		goto loc_825E62C8;
	case 8:
		goto loc_825E62D8;
	case 9:
		goto loc_825E62F0;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_825E6110:
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// b 0x825e6318
	goto loc_825E6318;
loc_825E6118:
	// lwz r26,40(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r30,44(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r11,88(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 88);
	// subf r5,r30,r26
	ctx.r5.u64 = ctx.r26.u64 - ctx.r30.u64;
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// ld r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 48);
	// lwz r27,36(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x825e6140
	if (!ctx.cr6.gt) goto loc_825E6140;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
loc_825E6140:
	// lwz r3,60(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 60);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// stw r25,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// add r4,r30,r10
	ctx.r4.u64 = ctx.r30.u64 + ctx.r10.u64;
	// bne cr6,0x825e616c
	if (!ctx.cr6.eq) goto loc_825E616C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E6168;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825e6188
	goto loc_825E6188;
loc_825E616C:
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E6188;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E6188:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// beq cr6,0x825e61b8
	if (ctx.cr6.eq) goto loc_825E61B8;
loc_825E61A0:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r27
	ea = ctx.r27.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r11,0,r27
	ea = ctx.r27.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825e61a0
	if (!ctx.cr0.eq) goto loc_825E61A0;
loc_825E61B8:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x825e6318
	if (!ctx.cr6.eq) goto loc_825E6318;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825e6318
	if (ctx.cr6.eq) goto loc_825E6318;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x825e6318
	if (!ctx.cr6.gt) goto loc_825E6318;
	// lis r29,-16379
	ctx.r29.s64 = -1073414144;
	// ori r29,r29,257
	ctx.r29.u64 = ctx.r29.u64 | 257;
	// b 0x825e6318
	goto loc_825E6318;
loc_825E61E0:
	// lwz r26,40(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r30,44(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r11,88(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 88);
	// subf r5,r30,r26
	ctx.r5.u64 = ctx.r26.u64 - ctx.r30.u64;
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// ld r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 48);
	// lwz r27,36(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x825e6208
	if (!ctx.cr6.gt) goto loc_825E6208;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
loc_825E6208:
	// lwz r3,60(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 60);
	// cmplwi cr6,r8,3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 3, ctx.xer);
	// stw r25,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// add r4,r30,r10
	ctx.r4.u64 = ctx.r30.u64 + ctx.r10.u64;
	// bne cr6,0x825e6234
	if (!ctx.cr6.eq) goto loc_825E6234;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E6230;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825e6250
	goto loc_825E6250;
loc_825E6234:
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E6250;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E6250:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// beq cr6,0x825e61b8
	if (ctx.cr6.eq) goto loc_825E61B8;
loc_825E6268:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r27
	ea = ctx.r27.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r11,0,r27
	ea = ctx.r27.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825e6268
	if (!ctx.cr0.eq) goto loc_825E6268;
	// b 0x825e61b8
	goto loc_825E61B8;
loc_825E6284:
	// lwz r3,60(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 60);
	// lwz r6,44(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r5,40(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// ld r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E62A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E62A4:
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x825e6318
	goto loc_825E6318;
loc_825E62AC:
	// lwz r3,60(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 60);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
loc_825E62B8:
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E62C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825e62a4
	goto loc_825E62A4;
loc_825E62C8:
	// lwz r3,60(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 60);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// b 0x825e62b8
	goto loc_825E62B8;
loc_825E62D8:
	// lwz r3,60(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 60);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E62EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825e62a4
	goto loc_825E62A4;
loc_825E62F0:
	// lwz r3,60(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 60);
	// addi r4,r31,60
	ctx.r4.s64 = ctx.r31.s64 + 60;
	// lwz r5,32(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E630C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825e62a4
	goto loc_825E62A4;
loc_825E6310:
	// lis r29,-16379
	ctx.r29.s64 = -1073414144;
	// ori r29,r29,1
	ctx.r29.u64 = ctx.r29.u64 | 1;
loc_825E6318:
	// lwz r3,60(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// addi r30,r31,60
	ctx.r30.s64 = ctx.r31.s64 + 60;
	// bl 0x8273c660
	ctx.lr = 0x825E6324;
	sub_8273C660(ctx, base);
	// lbz r11,66(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 66);
	// stw r25,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r25.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// stb r11,66(r31)
	REX_STORE_U8(ctx.r31.u32 + 66, ctx.r11.u8);
	// stw r29,44(r28)
	REX_STORE_U32(ctx.r28.u32 + 44, ctx.r29.u32);
loc_825E633C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F7AB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825F7AB8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// bl 0x825f80b8
	ctx.lr = 0x825F7AC8;
	sub_825F80B8(ctx, base);
	// addi r29,r31,40
	ctx.r29.s64 = ctx.r31.s64 + 40;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82644a08
	ctx.lr = 0x825F7ADC;
	sub_82644A08(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x825f7afc
	if (!ctx.cr0.lt) goto loc_825F7AFC;
	// li r11,7
	ctx.r11.s64 = 7;
loc_825F7AE8:
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r10,r10,10304
	ctx.r10.s64 = ctx.r10.s64 + 10304;
	// stw r11,136(r10)
	REX_STORE_U32(ctx.r10.u32 + 136, ctx.r11.u32);
	// stw r3,140(r10)
	REX_STORE_U32(ctx.r10.u32 + 140, ctx.r3.u32);
	// b 0x825f7c74
	goto loc_825F7C74;
loc_825F7AFC:
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r31,44
	ctx.r4.s64 = ctx.r31.s64 + 44;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F7B28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x825f7b38
	if (!ctx.cr0.lt) goto loc_825F7B38;
	// li r11,8
	ctx.r11.s64 = 8;
	// b 0x825f7ae8
	goto loc_825F7AE8;
loc_825F7B38:
	// addi r30,r31,32
	ctx.r30.s64 = ctx.r31.s64 + 32;
	// lwz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8276dd48
	ctx.lr = 0x825F7B54;
	sub_8276DD48(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x825f7b64
	if (!ctx.cr0.lt) goto loc_825F7B64;
	// li r11,10
	ctx.r11.s64 = 10;
	// b 0x825f7ae8
	goto loc_825F7AE8;
loc_825F7B64:
	// stw r28,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8168
	ctx.lr = 0x825F7B70;
	sub_825F8168(ctx, base);
	// lbz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,254
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 254, ctx.xer);
	// bne cr6,0x825f7b98
	if (!ctx.cr6.eq) goto loc_825F7B98;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// li r11,2
	ctx.r11.s64 = 2;
	// addi r9,r10,10304
	ctx.r9.s64 = ctx.r10.s64 + 10304;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,136(r9)
	REX_STORE_U32(ctx.r9.u32 + 136, ctx.r11.u32);
	// stw r10,140(r9)
	REX_STORE_U32(ctx.r9.u32 + 140, ctx.r10.u32);
	// b 0x825f7c6c
	goto loc_825F7C6C;
loc_825F7B98:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825f7c38
	if (ctx.cr6.eq) goto loc_825F7C38;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F7BC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F7BF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F7C14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,14
	ctx.r4.s64 = 14;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825F7C38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825F7C38:
	// lis r11,-32160
	ctx.r11.s64 = -2107637760;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r5,r11,-30496
	ctx.r5.s64 = ctx.r11.s64 + -30496;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82639f40
	ctx.lr = 0x825F7C58;
	sub_82639F40(ctx, base);
	// stw r3,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x825f7c6c
	if (ctx.cr0.eq) goto loc_825F7C6C;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x825f7c74
	if (!ctx.cr6.eq) goto loc_825F7C74;
loc_825F7C6C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f87c8
	ctx.lr = 0x825F7C74;
	sub_825F87C8(ctx, base);
loc_825F7C74:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82603AD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82603AD8;
	__savegprlr_25(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// subf r26,r3,r4
	ctx.r26.u64 = ctx.r4.u64 - ctx.r3.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// srawi r30,r26,5
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x1F) != 0);
	ctx.r30.s64 = ctx.r26.s32 >> 5;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// ble cr6,0x82603c60
	if (!ctx.cr6.gt) goto loc_82603C60;
loc_82603B00:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x82603b90
	if (!ctx.cr6.gt) goto loc_82603B90;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82603e30
	ctx.lr = 0x82603B1C;
	sub_82603E30(ctx, base);
	// srawi r11,r28,1
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r28.s32 >> 1;
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
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r30,100(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r27,96(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// subf r11,r30,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r30.u64;
	// subf r10,r31,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r31.u64;
	// rlwinm r11,r11,0,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFE0;
	// rlwinm r10,r10,0,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFE0;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x82603b6c
	if (!ctx.cr6.lt) goto loc_82603B6C;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82603ad0
	ctx.lr = 0x82603B64;
	sub_82603AD0(ctx, base);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// b 0x82603b7c
	goto loc_82603B7C;
loc_82603B6C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82603ad0
	ctx.lr = 0x82603B78;
	sub_82603AD0(ctx, base);
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
loc_82603B7C:
	// subf r26,r31,r29
	ctx.r26.u64 = ctx.r29.u64 - ctx.r31.u64;
	// srawi r30,r26,5
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x1F) != 0);
	ctx.r30.s64 = ctx.r26.s32 >> 5;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// bgt cr6,0x82603b00
	if (ctx.cr6.gt) goto loc_82603B00;
loc_82603B90:
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// ble cr6,0x82603c60
	if (!ctx.cr6.gt) goto loc_82603C60;
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// ble cr6,0x82603c78
	if (!ctx.cr6.gt) goto loc_82603C78;
	// srawi r11,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 1;
	// addze. r27,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r27.s64 = temp.s64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble 0x82603be8
	if (!ctx.cr0.gt) goto loc_82603BE8;
	// rlwinm r11,r27,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 5) & 0xFFFFFFE0;
	// add r28,r11,r31
	ctx.r28.u64 = ctx.r11.u64 + ctx.r31.u64;
loc_82603BB4:
	// addi r28,r28,-32
	ctx.r28.s64 = ctx.r28.s64 + -32;
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r6,0(r28)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r28.u32 + 0);
	// ld r7,8(r28)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r28.u32 + 8);
	// ld r8,16(r28)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r28.u32 + 16);
	// ld r9,24(r28)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r28.u32 + 24);
	// bl 0x82604688
	ctx.lr = 0x82603BE0;
	sub_82604688(ctx, base);
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bgt cr6,0x82603bb4
	if (ctx.cr6.gt) goto loc_82603BB4;
loc_82603BE8:
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// ble cr6,0x82603c78
	if (!ctx.cr6.gt) goto loc_82603C78;
	// subf r11,r31,r29
	ctx.r11.u64 = ctx.r29.u64 - ctx.r31.u64;
	// addi r29,r29,-32
	ctx.r29.s64 = ctx.r29.s64 + -32;
	// addi r28,r11,-32
	ctx.r28.s64 = ctx.r11.s64 + -32;
	// subfic r27,r31,32
	ctx.xer.ca = ctx.r31.u32 <= 32;
	ctx.r27.u64 = static_cast<uint64_t>(32) - ctx.r31.u64;
loc_82603C00:
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x82603C10;
	sub_8273A030(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x82603C20;
	sub_8273A030(ctx, base);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// srawi r5,r28,5
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x1F) != 0);
	ctx.r5.s64 = ctx.r28.s32 >> 5;
	// ld r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r7,120(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r8,128(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// ld r9,136(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// bl 0x82604688
	ctx.lr = 0x82603C44;
	sub_82604688(ctx, base);
	// addi r29,r29,-32
	ctx.r29.s64 = ctx.r29.s64 + -32;
	// addi r28,r28,-32
	ctx.r28.s64 = ctx.r28.s64 + -32;
	// add r11,r27,r29
	ctx.r11.u64 = ctx.r27.u64 + ctx.r29.u64;
	// srawi r30,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r30.s64 = ctx.r11.s32 >> 5;
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// bgt cr6,0x82603c00
	if (ctx.cr6.gt) goto loc_82603C00;
	// b 0x82603c78
	goto loc_82603C78;
loc_82603C60:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x82603c78
	if (!ctx.cr6.gt) goto loc_82603C78;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826040d8
	ctx.lr = 0x82603C78;
	sub_826040D8(ctx, base);
loc_82603C78:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82610A08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82610A10;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r11,-11548(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -11548);
	// lwz r11,68(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r9,20(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// rlwinm. r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82610a8c
	if (!ctx.cr0.eq) goto loc_82610A8C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r30,r11,-14760
	ctx.r30.s64 = ctx.r11.s64 + -14760;
loc_82610A40:
	// lwsync 
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
loc_82610A4C:
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
	// bne 0x82610a4c
	if (!ctx.cr0.eq) goto loc_82610A4C;
	// bl 0x82749140
	ctx.lr = 0x82610A68;
	sub_82749140(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8cb0
	ctx.lr = 0x82610A70;
	sub_825F8CB0(ctx, base);
	// lwz r11,-11548(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -11548);
	// lwz r11,68(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r9,20(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// rlwinm. r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82610a40
	if (ctx.cr0.eq) goto loc_82610A40;
loc_82610A8C:
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,20
	ctx.r8.s64 = 20;
	// lwz r6,24(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r5,20(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// subf r7,r7,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r7.u64;
	// rotlwi r9,r6,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// subf r11,r5,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r5.u64;
	// divw r8,r7,r8
	ctx.r8.u64 = uint32_t((ctx.r8.s32 && !(ctx.r7.s32 == INT32_MIN && ctx.r8.s32 == -1)) ? ctx.r7.s32 / ctx.r8.s32 : 0);
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// lwz r9,-4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + -4);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x82610ae8
	if (!ctx.cr6.eq) goto loc_82610AE8;
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// addi r8,r29,15
	ctx.r8.s64 = ctx.r29.s64 + 15;
	// lwz r7,16(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// rlwinm r8,r8,0,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82610ae8
	if (!ctx.cr6.lt) goto loc_82610AE8;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x82610b04
	goto loc_82610B04;
loc_82610AE8:
	// lwz r8,4(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// subf r8,r8,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r8.u64;
	// rlwinm. r8,r8,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82610b04
	if (ctx.cr0.eq) goto loc_82610B04;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
loc_82610B04:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82617D20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82617D28;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfs f0,0(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// addi r30,r11,14376
	ctx.r30.s64 = ctx.r11.s64 + 14376;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,-1908(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -1908);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// bl 0x82617180
	ctx.lr = 0x82617D6C;
	sub_82617180(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lwz r9,4(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lwz r10,136(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 136);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// blt cr6,0x82617db0
	if (ctx.cr6.lt) goto loc_82617DB0;
	// beq cr6,0x82617da8
	if (ctx.cr6.eq) goto loc_82617DA8;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// blt cr6,0x82617db0
	if (ctx.cr6.lt) goto loc_82617DB0;
	// bne cr6,0x82617db8
	if (!ctx.cr6.eq) goto loc_82617DB8;
loc_82617DA8:
	// lfs f13,12(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82617db4
	goto loc_82617DB4;
loc_82617DB0:
	// lfs f13,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
loc_82617DB4:
	// stfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
loc_82617DB8:
	// lwz r11,120(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 120);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82617e04
	if (ctx.cr6.eq) goto loc_82617E04;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82617e34
	if (!ctx.cr6.eq) goto loc_82617E34;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// blt cr6,0x82617df0
	if (ctx.cr6.lt) goto loc_82617DF0;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x82617e34
	if (!ctx.cr6.lt) goto loc_82617E34;
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f0,-2140(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2140);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// b 0x82617e30
	goto loc_82617E30;
loc_82617DF0:
	// lfs f13,-2140(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2140);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// b 0x82617e30
	goto loc_82617E30;
loc_82617E04:
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// blt cr6,0x82617e24
	if (ctx.cr6.lt) goto loc_82617E24;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x82617e34
	if (!ctx.cr6.lt) goto loc_82617E34;
	// lfs f12,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// b 0x82617e30
	goto loc_82617E30;
loc_82617E24:
	// lfs f12,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f0,f13,f12
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
loc_82617E30:
	// stfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
loc_82617E34:
	// lwz r11,132(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 132);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x82617e4c
	if (ctx.cr6.lt) goto loc_82617E4C;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// ble cr6,0x82617e50
	if (!ctx.cr6.gt) goto loc_82617E50;
loc_82617E4C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82617E50:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82617e6c
	if (ctx.cr0.eq) goto loc_82617E6C;
	// lfs f0,76(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82617e6c
	if (!ctx.cr6.lt) goto loc_82617E6C;
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
loc_82617E6C:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// blt cr6,0x82617e8c
	if (ctx.cr6.lt) goto loc_82617E8C;
	// beq cr6,0x82617e84
	if (ctx.cr6.eq) goto loc_82617E84;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// blt cr6,0x82617e8c
	if (ctx.cr6.lt) goto loc_82617E8C;
	// bne cr6,0x82617e94
	if (!ctx.cr6.eq) goto loc_82617E94;
loc_82617E84:
	// lfs f0,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82617e90
	goto loc_82617E90;
loc_82617E8C:
	// lfs f0,12(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
loc_82617E90:
	// stfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
loc_82617E94:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// blt cr6,0x82617ea8
	if (ctx.cr6.lt) goto loc_82617EA8;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// blt cr6,0x82617f08
	if (ctx.cr6.lt) goto loc_82617F08;
	// bne cr6,0x82617ef8
	if (!ctx.cr6.eq) goto loc_82617EF8;
loc_82617EA8:
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lfs f31,64(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f31.f64 = double(temp.f32);
	// lwz r30,72(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// bl 0x82617618
	ctx.lr = 0x82617EBC;
	sub_82617618(ctx, base);
	// clrldi r11,r27,32
	ctx.r11.u64 = ctx.r27.u64 & 0xFFFFFFFF;
	// add r10,r3,r30
	ctx.r10.u64 = ctx.r3.u64 + ctx.r30.u64;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// extsw r11,r10
	ctx.r11.s64 = ctx.r10.s32;
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmadds f0,f13,f31,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f31.f64, ctx.f0.f64)));
loc_82617EF4:
	// stfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
loc_82617EF8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_82617F08:
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lfs f31,64(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f31.f64 = double(temp.f32);
	// lwz r30,72(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// bl 0x82617618
	ctx.lr = 0x82617F1C;
	sub_82617618(ctx, base);
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// clrldi r10,r27,32
	ctx.r10.u64 = ctx.r27.u64 & 0xFFFFFFFF;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fnmsubs f0,f13,f31,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f13.f64, ctx.f31.f64, -ctx.f0.f64)));
	// b 0x82617ef4
	goto loc_82617EF4;
}

DEFINE_REX_FUNC(sub_8262DC58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8262DC60;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8262dd90
	if (ctx.cr6.eq) goto loc_8262DD90;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r26,r11,20
	ctx.r26.s64 = ctx.r11.s64 + 20;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// add r25,r11,r26
	ctx.r25.u64 = ctx.r11.u64 + ctx.r26.u64;
	// b 0x8262dd88
	goto loc_8262DD88;
loc_8262DC8C:
	// lhz r28,2(r26)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r26.u32 + 2);
	// addi r11,r26,4
	ctx.r11.s64 = ctx.r26.s64 + 4;
	// lhz r30,0(r26)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r26.u32 + 0);
	// cmplwi r28,0
	ctx.cr0.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq 0x8262dd90
	if (ctx.cr0.eq) goto loc_8262DD90;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r26,r11,4
	ctx.r26.s64 = ctx.r11.s64 + 4;
	// lbz r9,10940(r27)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r27.u32 + 10940);
	// add r31,r10,r24
	ctx.r31.u64 = ctx.r10.u64 + ctx.r24.u64;
	// rlwinm. r11,r9,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8262dd3c
	if (ctx.cr0.eq) goto loc_8262DD3C;
	// bl 0x82855964
	ctx.lr = 0x8262DCBC;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x8262dd3c
	if (!ctx.cr6.eq) goto loc_8262DD3C;
	// addi r4,r28,1
	ctx.r4.s64 = ctx.r28.s64 + 1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82626250
	ctx.lr = 0x8262DCD0;
	sub_82626250(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8262dd88
	if (ctx.cr0.eq) goto loc_8262DD88;
	// sync 
	// rlwinm r11,r31,12,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 12) & 0xFFF;
	// addi r10,r30,4096
	ctx.r10.s64 = ctx.r30.s64 + 4096;
	// addi r9,r28,-1
	ctx.r9.s64 = ctx.r28.s64 + -1;
	// addi r8,r11,512
	ctx.r8.s64 = ctx.r11.s64 + 512;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// clrlwi r11,r31,3
	ctx.r11.u64 = ctx.r31.u32 & 0x1FFFFFFF;
	// rlwinm r10,r8,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// rlwinm r31,r28,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addis r30,r11,-16384
	ctx.r30.s64 = ctx.r11.s64 + -1073741824;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bl 0x8273a030
	ctx.lr = 0x8262DD24;
	sub_8273A030(ctx, base);
	// add r4,r31,r30
	ctx.r4.u64 = ctx.r31.u64 + ctx.r30.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826323d0
	ctx.lr = 0x8262DD30;
	sub_826323D0(ctx, base);
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// stw r11,48(r27)
	REX_STORE_U32(ctx.r27.u32 + 48, ctx.r11.u32);
	// b 0x8262dd88
	goto loc_8262DD88;
loc_8262DD3C:
	// lwz r11,56(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 56);
	// lwz r3,48(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8262dd54
	if (!ctx.cr6.gt) goto loc_8262DD54;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x826274c0
	ctx.lr = 0x8262DD54;
	sub_826274C0(ctx, base);
loc_8262DD54:
	// lis r10,-16382
	ctx.r10.s64 = -1073610752;
	// rlwinm r11,r31,12,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 12) & 0xFFF;
	// ori r10,r10,12032
	ctx.r10.u64 = ctx.r10.u64 | 12032;
	// addi r11,r11,512
	ctx.r11.s64 = ctx.r11.s64 + 512;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// clrlwi r10,r31,3
	ctx.r10.u64 = ctx.r31.u32 & 0x1FFFFFFF;
	// rlwinm r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r28,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r27)
	REX_STORE_U32(ctx.r27.u32 + 48, ctx.r3.u32);
loc_8262DD88:
	// cmplw cr6,r26,r25
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x8262dc8c
	if (ctx.cr6.lt) goto loc_8262DC8C;
loc_8262DD90:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82638A30) {
	REX_FUNC_PROLOGUE();
	// b 0x82627970
	sub_82627970(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82638C40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82638C48;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,2252(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2252);
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82638e10
	if (ctx.cr6.eq) goto loc_82638E10;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82638e10
	if (ctx.cr6.eq) goto loc_82638E10;
	// ld r11,10880(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 10880);
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82638e10
	if (ctx.cr6.eq) goto loc_82638E10;
	// cmplwi cr6,r3,224
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 224, ctx.xer);
	// bgt cr6,0x82638d24
	if (ctx.cr6.gt) goto loc_82638D24;
	// beq cr6,0x82638dd8
	if (ctx.cr6.eq) goto loc_82638DD8;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x82638d10
	if (ctx.cr6.lt) goto loc_82638D10;
	// beq cr6,0x82638d10
	if (ctx.cr6.eq) goto loc_82638D10;
	// cmplwi cr6,r3,16
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 16, ctx.xer);
	// beq cr6,0x82638ce4
	if (ctx.cr6.eq) goto loc_82638CE4;
	// cmplwi cr6,r3,17
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 17, ctx.xer);
	// beq cr6,0x82638cb0
	if (ctx.cr6.eq) goto loc_82638CB0;
	// cmplwi cr6,r3,34
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 34, ctx.xer);
	// bne cr6,0x82638e10
	if (!ctx.cr6.eq) goto loc_82638E10;
	// stw r4,23568(r31)
	REX_STORE_U32(ctx.r31.u32 + 23568, ctx.r4.u32);
	// b 0x82638e10
	goto loc_82638E10;
loc_82638CB0:
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r4,6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 6, ctx.xer);
	// slw r8,r10,r4
	ctx.r8.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r4.u8 & 0x3F));
	// lwz r11,-11440(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -11440);
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
	// stw r11,-11440(r9)
	REX_STORE_U32(ctx.r9.u32 + -11440, ctx.r11.u32);
	// bne cr6,0x82638e10
	if (!ctx.cr6.eq) goto loc_82638E10;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,21840(r31)
	REX_STORE_U32(ctx.r31.u32 + 21840, ctx.r10.u32);
	// stw r11,21832(r31)
	REX_STORE_U32(ctx.r31.u32 + 21832, ctx.r11.u32);
	// stw r11,21836(r31)
	REX_STORE_U32(ctx.r31.u32 + 21836, ctx.r11.u32);
	// b 0x82638e10
	goto loc_82638E10;
loc_82638CE4:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,1
	ctx.r11.s64 = 1;
	// cmplwi cr6,r4,6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 6, ctx.xer);
	// slw r9,r11,r4
	ctx.r9.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r4.u8 & 0x3F));
	// lwz r11,-11440(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -11440);
	// andc r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ~ctx.r9.u64;
	// stw r11,-11440(r10)
	REX_STORE_U32(ctx.r10.u32 + -11440, ctx.r11.u32);
	// bne cr6,0x82638e10
	if (!ctx.cr6.eq) goto loc_82638E10;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,21840(r31)
	REX_STORE_U32(ctx.r31.u32 + 21840, ctx.r11.u32);
	// b 0x82638e10
	goto loc_82638E10;
loc_82638D10:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,21840(r31)
	REX_STORE_U32(ctx.r31.u32 + 21840, ctx.r11.u32);
	// stw r11,-11440(r10)
	REX_STORE_U32(ctx.r10.u32 + -11440, ctx.r11.u32);
	// b 0x82638e10
	goto loc_82638E10;
loc_82638D24:
	// cmplwi cr6,r3,225
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 225, ctx.xer);
	// beq cr6,0x82638dd8
	if (ctx.cr6.eq) goto loc_82638DD8;
	// cmplwi cr6,r3,226
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 226, ctx.xer);
	// beq cr6,0x82638dd8
	if (ctx.cr6.eq) goto loc_82638DD8;
	// cmplwi cr6,r3,227
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 227, ctx.xer);
	// beq cr6,0x82638dcc
	if (ctx.cr6.eq) goto loc_82638DCC;
	// cmplwi cr6,r3,255
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 255, ctx.xer);
	// bne cr6,0x82638e10
	if (!ctx.cr6.eq) goto loc_82638E10;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// lwz r11,-11440(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -11440);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82638d84
	if (ctx.cr0.eq) goto loc_82638D84;
	// lwz r11,21784(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21784);
	// lfs f13,21800(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 21800);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32241
	ctx.r10.s64 = -2112946176;
	// lis r3,2
	ctx.r3.s64 = 131072;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lfs f0,20068(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 20068);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x82748528
	ctx.lr = 0x82638D84;
	sub_82748528(ctx, base);
loc_82638D84:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r29,17
	ctx.r29.s64 = 17;
	// addi r11,r11,3488
	ctx.r11.s64 = ctx.r11.s64 + 3488;
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
loc_82638D94:
	// lwz r11,-8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -8);
	// lwz r10,-11440(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + -11440);
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82638dbc
	if (ctx.cr0.eq) goto loc_82638DBC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r27,-4(r30)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r30.u32 + -4);
	// bl 0x82638530
	ctx.lr = 0x82638DB4;
	sub_82638530(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82748528
	ctx.lr = 0x82638DBC;
	sub_82748528(ctx, base);
loc_82638DBC:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,12
	ctx.r30.s64 = ctx.r30.s64 + 12;
	// bne 0x82638d94
	if (!ctx.cr0.eq) goto loc_82638D94;
	// b 0x82638e10
	goto loc_82638E10;
loc_82638DCC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826374d8
	ctx.lr = 0x82638DD4;
	sub_826374D8(ctx, base);
	// b 0x82638e10
	goto loc_82638E10;
loc_82638DD8:
	// lwz r11,21740(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21740);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82638e10
	if (ctx.cr6.eq) goto loc_82638E10;
	// bl 0x827484a0
	ctx.lr = 0x82638DE8;
	sub_827484A0(ctx, base);
	// lwz r11,10888(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10888);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x82638e10
	if (!ctx.cr6.eq) goto loc_82638E10;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82638e0c
	if (!ctx.cr6.gt) goto loc_82638E0C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826274c0
	ctx.lr = 0x82638E0C;
	sub_826274C0(ctx, base);
loc_82638E0C:
	// stw r3,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
loc_82638E10:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82643600) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82643608;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,116(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 116);
	// addi r30,r3,116
	ctx.r30.s64 = ctx.r3.s64 + 116;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264362C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,536
	ctx.r3.s64 = ctx.r31.s64 + 536;
	// bl 0x82654350
	ctx.lr = 0x82643638;
	sub_82654350(ctx, base);
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// addic r10,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// lis r9,-32761
	ctx.r9.s64 = -2147024896;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// ori r9,r9,14
	ctx.r9.u64 = ctx.r9.u64 | 14;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// and r31,r10,r9
	ctx.r31.u64 = ctx.r10.u64 & ctx.r9.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82643660;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82645E80) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82645E94:
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r11,r11,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// rlwinm r7,r11,20,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0xFF;
	// cmplw cr6,r7,r4
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82645ebc
	if (ctx.cr6.eq) goto loc_82645EBC;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwimi r11,r4,12,12,19
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 12) & 0xFF000) | (ctx.r11.u64 & 0xFFFFFFFFFFF00FFF);
	// stw r7,48(r10)
	REX_STORE_U32(ctx.r10.u32 + 48, ctx.r7.u32);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_82645EBC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,96
	ctx.r9.s64 = ctx.r9.s64 + 96;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82645e94
	if (ctx.cr6.lt) goto loc_82645E94;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82648408) {
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
	// bl 0x82648018
	ctx.lr = 0x82648428;
	sub_82648018(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8264846c
	if (ctx.cr0.eq) goto loc_8264846C;
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
	// beq cr6,0x82648458
	if (ctx.cr6.eq) goto loc_82648458;
	// stw r3,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// b 0x8264845c
	goto loc_8264845C;
loc_82648458:
	// stw r3,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
loc_8264845C:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// stw r3,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_8264846C:
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

DEFINE_REX_FUNC(sub_8264B248) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8264B250;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// addi r31,r1,-224
	ctx.r31.s64 = ctx.r1.s64 + -224;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,2(r6)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r6.u32 + 2);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r25,4(r6)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8264b2b4
	if (!ctx.cr6.eq) goto loc_8264B2B4;
	// clrldi r10,r25,32
	ctx.r10.u64 = ctx.r25.u64 & 0xFFFFFFFF;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r10,96(r31)
	REX_STORE_U64(ctx.r31.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r31)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r31.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,6868(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6868);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8264b2dc
	if (ctx.cr6.gt) goto loc_8264B2DC;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8264b2e8
	if (ctx.cr6.eq) goto loc_8264B2E8;
loc_8264B2B4:
	// clrldi r11,r25,32
	ctx.r11.u64 = ctx.r25.u64 & 0xFFFFFFFF;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,96(r31)
	REX_STORE_U64(ctx.r31.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r31)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r31.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,6864(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6864);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8264b2e8
	if (!ctx.cr6.gt) goto loc_8264B2E8;
loc_8264B2DC:
	// lis r3,-30570
	ctx.r3.s64 = -2003435520;
	// ori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 | 1;
	// b 0x8264b4c0
	goto loc_8264B4C0;
loc_8264B2E8:
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// addi r3,r30,248
	ctx.r3.s64 = ctx.r30.s64 + 248;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264B2FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8264b4c0
	if (ctx.cr0.lt) goto loc_8264B4C0;
	// li r11,128
	ctx.r11.s64 = 128;
	// lwz r10,20(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// li r9,16
	ctx.r9.s64 = 16;
	// lhz r6,2(r29)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r29.u32 + 2);
	// li r8,16
	ctx.r8.s64 = 16;
	// sth r11,86(r1)
	REX_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r3,r31,112
	ctx.r3.s64 = ctx.r31.s64 + 112;
	// bl 0x8264beb0
	ctx.lr = 0x8264B330;
	sub_8264BEB0(ctx, base);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r6,r31,112
	ctx.r6.s64 = ctx.r31.s64 + 112;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82647698
	ctx.lr = 0x8264B34C;
	sub_82647698(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8264b4c0
	if (ctx.cr0.lt) goto loc_8264B4C0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,4(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x82649be0
	ctx.lr = 0x8264B360;
	sub_82649BE0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8264b4c0
	if (ctx.cr0.lt) goto loc_8264B4C0;
	// lwz r8,64(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// li r10,256
	ctx.r10.s64 = 256;
	// li r6,7936
	ctx.r6.s64 = 7936;
	// lwz r7,296(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 296);
	// subfic r11,r8,1
	ctx.xer.ca = ctx.r8.u32 <= 1;
	ctx.r11.u64 = static_cast<uint64_t>(1) - ctx.r8.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r9,512
	ctx.r9.s64 = 512;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// divwu r10,r10,r11
	ctx.r10.u64 = uint32_t(ctx.r11.u32 ? ctx.r10.u32 / ctx.r11.u32 : 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r6,r6,r11
	ctx.r6.u64 = uint32_t(ctx.r11.u32 ? ctx.r6.u32 / ctx.r11.u32 : 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// add r11,r7,r10
	ctx.r11.u64 = ctx.r7.u64 + ctx.r10.u64;
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// divwu r7,r11,r10
	ctx.r7.u64 = uint32_t(ctx.r10.u32 ? ctx.r11.u32 / ctx.r10.u32 : 0);
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
loc_8264B3C0:
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// ble cr6,0x8264b3dc
	if (!ctx.cr6.gt) goto loc_8264B3DC;
	// rlwinm. r5,r5,31,25,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7F;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// bne 0x8264b3c0
	if (!ctx.cr0.eq) goto loc_8264B3C0;
loc_8264B3DC:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r8,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mulli r11,r9,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(12));
	// stw r9,184(r30)
	REX_STORE_U32(ctx.r30.u32 + 184, ctx.r9.u32);
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// rlwinm r12,r11,0,0,27
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x8273adc4
	ctx.lr = 0x8264B400;
	sub_8273ADC4(ctx, base);
	// lwz r11,0(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stwux r11,r1,r12
	ea = ctx.r1.u32 + ctx.r12.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r1.u32 = ea;
	// addi r28,r1,96
	ctx.r28.s64 = ctx.r1.s64 + 96;
	// beq cr6,0x8264b46c
	if (ctx.cr6.eq) goto loc_8264B46C;
	// addi r11,r28,-3
	ctx.r11.s64 = ctx.r28.s64 + -3;
loc_8264B41C:
	// lwz r9,184(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8264b43c
	if (!ctx.cr6.eq) goto loc_8264B43C;
	// lwz r9,64(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// clrlwi. r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// bne 0x8264b440
	if (!ctx.cr0.eq) goto loc_8264B440;
loc_8264B43C:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8264B440:
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stw r25,3(r11)
	REX_STORE_U32(ctx.r11.u32 + 3, ctx.r25.u32);
	// stw r8,7(r11)
	REX_STORE_U32(ctx.r11.u32 + 7, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r9,11(r11)
	REX_STORE_U8(ctx.r11.u32 + 11, ctx.r9.u8);
	// stbu r5,12(r11)
	ea = 12 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r5.u8);
	ctx.r11.u32 = ea;
	// lwz r9,184(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8264b41c
	if (ctx.cr6.lt) goto loc_8264B41C;
loc_8264B46C:
	// bl 0x826456a0
	ctx.lr = 0x8264B470;
	sub_826456A0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,184(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// bl 0x826456b8
	ctx.lr = 0x8264B47C;
	sub_826456B8(ctx, base);
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r3,r11,16040
	ctx.r3.s64 = ctx.r11.s64 + 16040;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8264b128
	ctx.lr = 0x8264B490;
	sub_8264B128(ctx, base);
	// mr. r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r7,188(r30)
	REX_STORE_U32(ctx.r30.u32 + 188, ctx.r7.u32);
	// bne 0x8264b4a8
	if (!ctx.cr0.eq) goto loc_8264B4A8;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8264b4c0
	goto loc_8264B4C0;
loc_8264B4A8:
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// lwz r3,184(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 184);
	// addi r6,r30,284
	ctx.r6.s64 = ctx.r30.s64 + 284;
	// li r5,6
	ctx.r5.s64 = 6;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x826463c0
	ctx.lr = 0x8264B4C0;
	sub_826463C0(ctx, base);
loc_8264B4C0:
	// addi r1,r31,224
	ctx.r1.s64 = ctx.r31.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826607C8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// stw r5,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r5.u32);
	// blt cr6,0x826607f4
	if (ctx.cr6.lt) goto loc_826607F4;
	// beq cr6,0x826607e8
	if (ctx.cr6.eq) goto loc_826607E8;
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_826607E8:
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_826607F4:
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_826614E0) {
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
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82661510;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82660d70
	ctx.lr = 0x82661520;
	sub_82660D70(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8266153C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

DEFINE_REX_FUNC(sub_82664CB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82664CB8;
	__savegprlr_27(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,6
	ctx.r10.s64 = 6;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r1,92
	ctx.r9.s64 = ctx.r1.s64 + 92;
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// lwz r29,20(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r27,32(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82664CE0:
	// lwzu r10,4(r8)
	ea = 4 + ctx.r8.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r8.u32 = ea;
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82664ce0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82664CE0;
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82664d28
	if (!ctx.cr6.eq) goto loc_82664D28;
	// li r9,6
	ctx.r9.s64 = 6;
	// addi r10,r1,116
	ctx.r10.s64 = ctx.r1.s64 + 116;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82664D08:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82664d08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82664D08;
	// li r5,48
	ctx.r5.s64 = 48;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8273a590
	ctx.lr = 0x82664D24;
	sub_8273A590(ctx, base);
	// b 0x82664dc0
	goto loc_82664DC0;
loc_82664D28:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r7,6
	ctx.r7.s64 = 6;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,140
	ctx.r8.s64 = ctx.r1.s64 + 140;
	// lfs f12,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f10,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// addi r9,r10,-4
	ctx.r9.s64 = ctx.r10.s64 + -4;
	// fadds f8,f12,f10
	ctx.f8.f64 = double(float(ctx.f12.f64 + ctx.f10.f64));
	// lfs f9,8(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// lfs f6,12(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f6.f64 = double(temp.f32);
	// fadds f5,f9,f7
	ctx.f5.f64 = double(float(ctx.f9.f64 + ctx.f7.f64));
	// lfs f4,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,16(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// fadds f2,f6,f4
	ctx.f2.f64 = double(float(ctx.f6.f64 + ctx.f4.f64));
	// lfs f1,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,20(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f3,f1
	ctx.f13.f64 = double(float(ctx.f3.f64 + ctx.f1.f64));
	// lfs f12,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fadds f10,f0,f12
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f8,124(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f5,128(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f2,132(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f10,140(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
loc_82664D98:
	// lwzu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r11,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x82664d98
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82664D98;
	// li r8,6
	ctx.r8.s64 = 6;
	// addi r9,r1,164
	ctx.r9.s64 = ctx.r1.s64 + 164;
	// addi r11,r10,-4
	ctx.r11.s64 = ctx.r10.s64 + -4;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82664DB4:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82664db4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82664DB4;
loc_82664DC0:
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvrx128 v63,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvrx128 v60,r11,r8
	temp.u32 = ctx.r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvlx128 v59,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvrx128 v57,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvlx128 v56,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvrx128 v55,r11,r4
	temp.u32 = ctx.r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// rlwinm r6,r31,0,28,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0xC;
	// lvlx128 v54,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v53,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// li r28,4
	ctx.r28.s64 = 4;
	// lvlx128 v52,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v61,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lvrx128 v51,r11,r8
	temp.u32 = ctx.r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v58,v59,v60
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// lvlx128 v50,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v57,v56,v57
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8)));
	// vor128 v12,v54,v55
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8)));
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// vor128 v13,v52,v53
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8)));
	// vor128 v0,v50,v51
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8)));
	// beq cr6,0x82664ec8
	if (ctx.cr6.eq) goto loc_82664EC8;
	// cmplwi cr6,r29,3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 3, ctx.xer);
	// ble cr6,0x82665024
	if (!ctx.cr6.gt) goto loc_82665024;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
loc_82664E58:
	// lvlx128 v49,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vaddfp128 v12,v12,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vspltw128 v63,v49,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v49.u32), 0xFF));
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// vor128 v48,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vmulfp128 v63,v63,v0
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vaddfp128 v0,v0,v57
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v57.f32)));
	// vmulfp128 v62,v48,v13
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v48.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vaddfp128 v13,v13,v58
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v58.f32)));
	// beq cr6,0x82664e98
	if (ctx.cr6.eq) goto loc_82664E98;
	// lvlx128 v47,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v46,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v45,v47,v46
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v46.u8)));
	// lvlx128 v44,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vaddfp128 v62,v62,v44
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v44.f32)));
	// vaddfp128 v63,v63,v45
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v45.f32)));
loc_82664E98:
	// vpermwi128 v43,v62,17
	simde_mm_store_si128((simde__m128i*)ctx.v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xEE));
	// stvlx128 v63,r0,r31
	ea = ctx.r31.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// stvrx128 v63,r31,r11
	ea = ctx.r31.u32 + ctx.r11.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v63.u8[i]);
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// rlwinm r9,r31,0,28,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0xC;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stvewx128 v43,r0,r10
	ea = (ctx.r10.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v43.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v43,r10,r28
	ea = (ctx.r10.u32 + ctx.r28.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v43.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// bne cr6,0x82664e58
	if (!ctx.cr6.eq) goto loc_82664E58;
loc_82664EC8:
	// cmplwi cr6,r29,3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 3, ctx.xer);
	// ble cr6,0x82665024
	if (!ctx.cr6.gt) goto loc_82665024;
	// rlwinm r3,r29,2,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFF0;
	// vaddfp128 v63,v61,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v61.f32)));
	// clrlwi r29,r29,30
	ctx.r29.u64 = ctx.r29.u32 & 0x3;
	// vaddfp128 v62,v58,v58
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v58.f32)));
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// vaddfp128 v61,v57,v57
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v57.f32)));
	// beq cr6,0x82665020
	if (ctx.cr6.eq) goto loc_82665020;
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// rlwinm r9,r9,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// addi r8,r31,864
	ctx.r8.s64 = ctx.r31.s64 + 864;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addi r9,r30,192
	ctx.r9.s64 = ctx.r30.s64 + 192;
	// li r4,32
	ctx.r4.s64 = 32;
	// li r5,48
	ctx.r5.s64 = 48;
	// li r6,64
	ctx.r6.s64 = 64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// li r7,80
	ctx.r7.s64 = 80;
loc_82664F18:
	// lvrx128 v42,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v41,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v60,v41,v42
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)ctx.v42.u8)));
	// dcbt r0,r9
	// dcbt r0,r8
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// vor128 v59,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v60.u8));
	// vmrghw128 v11,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v60.u32)));
	// vmrglw128 v10,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v60.u32)));
	// beq cr6,0x82664fb4
	if (ctx.cr6.eq) goto loc_82664FB4;
	// vspltw128 v9,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// lvx128 v8,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v7,v11,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0x55));
	// lvx128 v6,r31,r4
	ea = (ctx.r31.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v5,v59,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x55));
	// lvx128 v3,r31,r7
	ea = (ctx.r31.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v4,v10,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v10.u32), 0x55));
	// vmaddfp v9,v9,v0,v8
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// lvx128 v8,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v11,v13,v8
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v8,v7,v12,v6
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// lvx128 v6,r31,r6
	ea = (ctx.r31.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v13,v13,v62
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v7,r31,r5
	ea = (ctx.r31.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v0,v0,v61
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vaddfp128 v12,v12,v63
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v9,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v8,r31,r4
	ea = (ctx.r31.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v10,v13,v6
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v9,v5,v0,v7
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v10,v4,v12,v3
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vaddfp128 v0,v0,v61
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vaddfp128 v13,v13,v62
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vaddfp128 v12,v12,v63
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v11,r31,r6
	ea = (ctx.r31.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r31,r5
	ea = (ctx.r31.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r31,r7
	ea = (ctx.r31.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8266500c
	goto loc_8266500C;
loc_82664FB4:
	// vaddfp128 v40,v13,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v40.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vspltw128 v39,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v39.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vaddfp128 v38,v0,v61
	simde_mm_store_ps(ctx.v38.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vspltw128 v35,v59,2
	simde_mm_store_si128((simde__m128i*)ctx.v35.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x55));
	// vaddfp128 v36,v12,v63
	simde_mm_store_ps(ctx.v36.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vspltw128 v37,v11,2
	simde_mm_store_si128((simde__m128i*)ctx.v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0x55));
	// vspltw128 v34,v10,2
	simde_mm_store_si128((simde__m128i*)ctx.v34.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v10.u32), 0x55));
	// vmulfp128 v33,v11,v13
	simde_mm_store_ps(ctx.v33.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v32,v39,v0
	simde_mm_store_ps(ctx.v32.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v39.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v60,v37,v12
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v37.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v59,v10,v40
	simde_mm_store_ps(ctx.v59.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v40.f32)));
	// vmulfp128 v56,v35,v38
	simde_mm_store_ps(ctx.v56.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v35.f32), simde_mm_load_ps(ctx.v38.f32)));
	// vmulfp128 v55,v34,v36
	simde_mm_store_ps(ctx.v55.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v34.f32), simde_mm_load_ps(ctx.v36.f32)));
	// stvx128 v33,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v13,v40,v62
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v40.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v32,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v0,v38,v61
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v38.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vaddfp128 v12,v36,v63
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v36.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v60,r31,r4
	ea = (ctx.r31.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r6
	ea = (ctx.r31.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r5
	ea = (ctx.r31.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r31,r7
	ea = (ctx.r31.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8266500C:
	// addi r31,r31,96
	ctx.r31.s64 = ctx.r31.s64 + 96;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r8,r31,864
	ctx.r8.s64 = ctx.r31.s64 + 864;
	// addi r9,r10,192
	ctx.r9.s64 = ctx.r10.s64 + 192;
	// bdnz 0x82664f18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82664F18;
loc_82665020:
	// add r30,r3,r30
	ctx.r30.u64 = ctx.r3.u64 + ctx.r30.u64;
loc_82665024:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82665094
	if (ctx.cr6.eq) goto loc_82665094;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
loc_82665034:
	// lvlx128 v54,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// vspltw128 v63,v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.u32), 0xFF));
	// vor128 v53,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vmulfp128 v63,v63,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vaddfp128 v0,v0,v57
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v57.f32)));
	// vmulfp128 v62,v53,v13
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v53.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vaddfp128 v13,v13,v58
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v58.f32)));
	// beq cr6,0x82665070
	if (ctx.cr6.eq) goto loc_82665070;
	// lvlx128 v52,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v51,r11,r31
	temp.u32 = ctx.r11.u32 + ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v50,v52,v51
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8)));
	// lvlx128 v49,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vaddfp128 v62,v62,v49
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v49.f32)));
	// vaddfp128 v63,v63,v50
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v50.f32)));
loc_82665070:
	// vpermwi128 v48,v62,17
	simde_mm_store_si128((simde__m128i*)ctx.v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xEE));
	// stvlx128 v63,r0,r31
	ea = ctx.r31.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// stvrx128 v63,r31,r11
	ea = ctx.r31.u32 + ctx.r11.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v63.u8[i]);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// stvewx128 v48,r0,r10
	ea = (ctx.r10.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v48.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v48,r10,r28
	ea = (ctx.r10.u32 + ctx.r28.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v48.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// bdnz 0x82665034
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82665034;
loc_82665094:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8269FEF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8269ff24
	if (!ctx.cr6.eq) goto loc_8269FF24;
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8269FF24:
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,22260(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 22260);
	// slw r8,r10,r4
	ctx.r8.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r4.u8 & 0x3F));
	// and r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8269ff4c
	if (!ctx.cr6.eq) goto loc_8269FF4C;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8269FF4C:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r7,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// lwz r9,22256(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 22256);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ori r8,r10,39848
	ctx.r8.u64 = ctx.r10.u64 | 39848;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r4,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// stw r6,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// stw r5,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwzx r7,r11,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// stw r7,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bl 0x826ba6b8
	ctx.lr = 0x8269FF80;
	sub_826BA6B8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826AFB20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x826AFB28;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,84(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r11,432(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 432);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r25,2
	ctx.r25.s64 = 2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// bne cr6,0x826afc00
	if (!ctx.cr6.eq) goto loc_826AFC00;
	// li r27,1
	ctx.r27.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// bge cr6,0x826afbbc
	if (!ctx.cr6.lt) goto loc_826AFBBC;
loc_826AFB64:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826afbbc
	if (ctx.cr6.eq) goto loc_826AFBBC;
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
	// bge 0x826afbac
	if (!ctx.cr0.lt) goto loc_826AFBAC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFBAC;
	sub_826C8B78(ctx, base);
loc_826AFBAC:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826afb64
	if (ctx.cr6.gt) goto loc_826AFB64;
loc_826AFBBC:
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
	// bge 0x826afbf8
	if (!ctx.cr0.lt) goto loc_826AFBF8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFBF8;
	sub_826C8B78(ctx, base);
loc_826AFBF8:
	// stw r30,448(r28)
	REX_STORE_U32(ctx.r28.u32 + 448, ctx.r30.u32);
	// b 0x826afce4
	goto loc_826AFCE4;
loc_826AFC00:
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x826afc64
	if (!ctx.cr6.lt) goto loc_826AFC64;
loc_826AFC0C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826afc64
	if (ctx.cr6.eq) goto loc_826AFC64;
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
	// bge 0x826afc54
	if (!ctx.cr0.lt) goto loc_826AFC54;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFC54;
	sub_826C8B78(ctx, base);
loc_826AFC54:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826afc0c
	if (ctx.cr6.gt) goto loc_826AFC0C;
loc_826AFC64:
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
	// bge 0x826afca0
	if (!ctx.cr0.lt) goto loc_826AFCA0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFCA0;
	sub_826C8B78(ctx, base);
loc_826AFCA0:
	// li r27,1
	ctx.r27.s64 = 1;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r27,448(r28)
	REX_STORE_U32(ctx.r28.u32 + 448, ctx.r27.u32);
	// bne cr6,0x826afcb8
	if (!ctx.cr6.eq) goto loc_826AFCB8;
	// stw r26,448(r28)
	REX_STORE_U32(ctx.r28.u32 + 448, ctx.r26.u32);
	// b 0x826afce4
	goto loc_826AFCE4;
loc_826AFCB8:
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// bne cr6,0x826afcc8
	if (!ctx.cr6.eq) goto loc_826AFCC8;
	// stw r26,3968(r28)
	REX_STORE_U32(ctx.r28.u32 + 3968, ctx.r26.u32);
	// b 0x826afcdc
	goto loc_826AFCDC;
loc_826AFCC8:
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// bne cr6,0x826afcd8
	if (!ctx.cr6.eq) goto loc_826AFCD8;
	// stw r27,3968(r28)
	REX_STORE_U32(ctx.r28.u32 + 3968, ctx.r27.u32);
	// b 0x826afcdc
	goto loc_826AFCDC;
loc_826AFCD8:
	// stw r25,3968(r28)
	REX_STORE_U32(ctx.r28.u32 + 3968, ctx.r25.u32);
loc_826AFCDC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826aaaa0
	ctx.lr = 0x826AFCE4;
	sub_826AAAA0(ctx, base);
loc_826AFCE4:
	// lwz r11,440(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 440);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826b015c
	if (ctx.cr6.eq) goto loc_826B015C;
	// lwz r31,84(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r11,248(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 248);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bgt cr6,0x826afe74
	if (ctx.cr6.gt) goto loc_826AFE74;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826afd70
	if (!ctx.cr6.lt) goto loc_826AFD70;
loc_826AFD18:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826afd70
	if (ctx.cr6.eq) goto loc_826AFD70;
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
	// bge 0x826afd60
	if (!ctx.cr0.lt) goto loc_826AFD60;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFD60;
	sub_826C8B78(ctx, base);
loc_826AFD60:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826afd18
	if (ctx.cr6.gt) goto loc_826AFD18;
loc_826AFD70:
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
	// bge 0x826afdac
	if (!ctx.cr0.lt) goto loc_826AFDAC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFDAC;
	sub_826C8B78(ctx, base);
loc_826AFDAC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x826b0154
	if (ctx.cr6.eq) goto loc_826B0154;
	// lwz r31,84(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826afe28
	if (!ctx.cr6.lt) goto loc_826AFE28;
loc_826AFDD0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826afe28
	if (ctx.cr6.eq) goto loc_826AFE28;
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
	// bge 0x826afe18
	if (!ctx.cr0.lt) goto loc_826AFE18;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFE18;
	sub_826C8B78(ctx, base);
loc_826AFE18:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826afdd0
	if (ctx.cr6.gt) goto loc_826AFDD0;
loc_826AFE28:
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
	// bge 0x826afe64
	if (!ctx.cr0.lt) goto loc_826AFE64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFE64;
	sub_826C8B78(ctx, base);
loc_826AFE64:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x826aff24
	if (!ctx.cr6.eq) goto loc_826AFF24;
	// addi r11,r28,2192
	ctx.r11.s64 = ctx.r28.s64 + 2192;
	// b 0x826b0158
	goto loc_826B0158;
loc_826AFE74:
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// bgt cr6,0x826affec
	if (ctx.cr6.gt) goto loc_826AFFEC;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826afee0
	if (!ctx.cr6.lt) goto loc_826AFEE0;
loc_826AFE88:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826afee0
	if (ctx.cr6.eq) goto loc_826AFEE0;
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
	// bge 0x826afed0
	if (!ctx.cr0.lt) goto loc_826AFED0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFED0;
	sub_826C8B78(ctx, base);
loc_826AFED0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826afe88
	if (ctx.cr6.gt) goto loc_826AFE88;
loc_826AFEE0:
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
	// bge 0x826aff1c
	if (!ctx.cr0.lt) goto loc_826AFF1C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFF1C;
	sub_826C8B78(ctx, base);
loc_826AFF1C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x826aff2c
	if (!ctx.cr6.eq) goto loc_826AFF2C;
loc_826AFF24:
	// addi r11,r28,2180
	ctx.r11.s64 = ctx.r28.s64 + 2180;
	// b 0x826b0158
	goto loc_826B0158;
loc_826AFF2C:
	// lwz r31,84(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826affa0
	if (!ctx.cr6.lt) goto loc_826AFFA0;
loc_826AFF48:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826affa0
	if (ctx.cr6.eq) goto loc_826AFFA0;
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
	// bge 0x826aff90
	if (!ctx.cr0.lt) goto loc_826AFF90;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFF90;
	sub_826C8B78(ctx, base);
loc_826AFF90:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826aff48
	if (ctx.cr6.gt) goto loc_826AFF48;
loc_826AFFA0:
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
	// bge 0x826affdc
	if (!ctx.cr0.lt) goto loc_826AFFDC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826AFFDC;
	sub_826C8B78(ctx, base);
loc_826AFFDC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x826b0154
	if (ctx.cr6.eq) goto loc_826B0154;
	// addi r11,r28,2192
	ctx.r11.s64 = ctx.r28.s64 + 2192;
	// b 0x826b0158
	goto loc_826B0158;
loc_826AFFEC:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826b004c
	if (!ctx.cr6.lt) goto loc_826B004C;
loc_826AFFF4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826b004c
	if (ctx.cr6.eq) goto loc_826B004C;
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
	// bge 0x826b003c
	if (!ctx.cr0.lt) goto loc_826B003C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826B003C;
	sub_826C8B78(ctx, base);
loc_826B003C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826afff4
	if (ctx.cr6.gt) goto loc_826AFFF4;
loc_826B004C:
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
	// bge 0x826b0088
	if (!ctx.cr0.lt) goto loc_826B0088;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826B0088;
	sub_826C8B78(ctx, base);
loc_826B0088:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x826b0098
	if (!ctx.cr6.eq) goto loc_826B0098;
	// addi r11,r28,2192
	ctx.r11.s64 = ctx.r28.s64 + 2192;
	// b 0x826b0158
	goto loc_826B0158;
loc_826B0098:
	// lwz r31,84(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826b010c
	if (!ctx.cr6.lt) goto loc_826B010C;
loc_826B00B4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826b010c
	if (ctx.cr6.eq) goto loc_826B010C;
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
	// bge 0x826b00fc
	if (!ctx.cr0.lt) goto loc_826B00FC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826B00FC;
	sub_826C8B78(ctx, base);
loc_826B00FC:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826b00b4
	if (ctx.cr6.gt) goto loc_826B00B4;
loc_826B010C:
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
	// bge 0x826b0148
	if (!ctx.cr0.lt) goto loc_826B0148;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826B0148;
	sub_826C8B78(ctx, base);
loc_826B0148:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// addi r11,r28,2180
	ctx.r11.s64 = ctx.r28.s64 + 2180;
	// beq cr6,0x826b0158
	if (ctx.cr6.eq) goto loc_826B0158;
loc_826B0154:
	// addi r11,r28,2168
	ctx.r11.s64 = ctx.r28.s64 + 2168;
loc_826B0158:
	// stw r11,2164(r28)
	REX_STORE_U32(ctx.r28.u32 + 2164, ctx.r11.u32);
loc_826B015C:
	// lwz r11,3912(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 3912);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826b021c
	if (ctx.cr6.eq) goto loc_826B021C;
	// lwz r31,84(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 84);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x826b01dc
	if (!ctx.cr6.lt) goto loc_826B01DC;
loc_826B0184:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826b01dc
	if (ctx.cr6.eq) goto loc_826B01DC;
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
	// bge 0x826b01cc
	if (!ctx.cr0.lt) goto loc_826B01CC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826B01CC;
	sub_826C8B78(ctx, base);
loc_826B01CC:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826b0184
	if (ctx.cr6.gt) goto loc_826B0184;
loc_826B01DC:
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
	// bge 0x826b0218
	if (!ctx.cr0.lt) goto loc_826B0218;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x826B0218;
	sub_826C8B78(ctx, base);
loc_826B0218:
	// stw r30,452(r28)
	REX_STORE_U32(ctx.r28.u32 + 452, ctx.r30.u32);
loc_826B021C:
	// lwz r11,436(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 436);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826b02e4
	if (ctx.cr6.eq) goto loc_826B02E4;
	// lwz r3,84(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 84);
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
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826b0250
	if (!ctx.cr0.lt) goto loc_826B0250;
	// bl 0x826c8b78
	ctx.lr = 0x826B0250;
	sub_826C8B78(ctx, base);
loc_826B0250:
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// bne cr6,0x826b02e0
	if (!ctx.cr6.eq) goto loc_826B02E0;
	// lwz r3,84(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 84);
	// stw r26,328(r28)
	REX_STORE_U32(ctx.r28.u32 + 328, ctx.r26.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// rldicr r9,r10,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826b0284
	if (!ctx.cr0.lt) goto loc_826B0284;
	// bl 0x826c8b78
	ctx.lr = 0x826B0284;
	sub_826C8B78(ctx, base);
loc_826B0284:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x826b0298
	if (!ctx.cr6.eq) goto loc_826B0298;
	// stw r26,336(r28)
	REX_STORE_U32(ctx.r28.u32 + 336, ctx.r26.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_826B0298:
	// lwz r3,84(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 84);
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
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826b02c0
	if (!ctx.cr0.lt) goto loc_826B02C0;
	// bl 0x826c8b78
	ctx.lr = 0x826B02C0;
	sub_826C8B78(ctx, base);
loc_826B02C0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x826b02d4
	if (!ctx.cr6.eq) goto loc_826B02D4;
	// stw r27,336(r28)
	REX_STORE_U32(ctx.r28.u32 + 336, ctx.r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_826B02D4:
	// stw r25,336(r28)
	REX_STORE_U32(ctx.r28.u32 + 336, ctx.r25.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_826B02E0:
	// stw r27,328(r28)
	REX_STORE_U32(ctx.r28.u32 + 328, ctx.r27.u32);
loc_826B02E4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826F9928) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x826F9930;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,3756(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 3756);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826f9950
	if (ctx.cr6.eq) goto loc_826F9950;
	// lwz r26,3780(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 3780);
	// b 0x826f995c
	goto loc_826F995C;
loc_826F9950:
	// lwz r10,3744(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 3744);
	// lwz r11,220(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_826F995C:
	// lwz r9,3760(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3760);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x826f996c
	if (!ctx.cr6.eq) goto loc_826F996C;
	// lwz r9,3748(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3748);
loc_826F996C:
	// lwz r11,3764(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 3764);
	// lwz r10,224(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 224);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// add r27,r10,r9
	ctx.r27.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bne cr6,0x826f9984
	if (!ctx.cr6.eq) goto loc_826F9984;
	// lwz r11,3752(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 3752);
loc_826F9984:
	// lwz r9,3784(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3784);
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x826f999c
	if (ctx.cr6.eq) goto loc_826F999C;
	// lwz r24,3796(r30)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r30.u32 + 3796);
	// b 0x826f99a8
	goto loc_826F99A8;
loc_826F999C:
	// lwz r9,3744(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3744);
	// lwz r11,220(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// add r24,r9,r11
	ctx.r24.u64 = ctx.r9.u64 + ctx.r11.u64;
loc_826F99A8:
	// lwz r9,3788(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3788);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x826f99b8
	if (!ctx.cr6.eq) goto loc_826F99B8;
	// lwz r9,3748(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3748);
loc_826F99B8:
	// lwz r11,3792(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 3792);
	// add r25,r10,r9
	ctx.r25.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826f99cc
	if (!ctx.cr6.eq) goto loc_826F99CC;
	// lwz r11,3752(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 3752);
loc_826F99CC:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x826f9270
	ctx.lr = 0x826F99DC;
	sub_826F9270(ctx, base);
	// lwz r11,20912(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// lwz r9,364(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 364);
	// li r7,0
	ctx.r7.s64 = 0;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r8,r30,2928
	ctx.r8.s64 = ctx.r30.s64 + 2928;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r5,r30,2940
	ctx.r5.s64 = ctx.r30.s64 + 2940;
	// rlwinm r11,r6,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r4,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// lwz r9,368(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 368);
	// lwz r11,20912(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r3,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// lwz r11,372(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 372);
	// lwz r10,20912(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// mulli r10,r10,504
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(504));
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// lwz r6,360(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 360);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// lwz r11,252(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 252);
	// lwz r4,248(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,255
	ctx.r3.s64 = ctx.r11.s64 + 255;
	// stb r3,24(r31)
	REX_STORE_U8(ctx.r31.u32 + 24, ctx.r3.u8);
	// lwz r10,348(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 348);
	// stb r10,25(r31)
	REX_STORE_U8(ctx.r31.u32 + 25, ctx.r10.u8);
	// lwz r6,344(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 344);
	// stb r6,26(r31)
	REX_STORE_U8(ctx.r31.u32 + 26, ctx.r6.u8);
	// lwz r3,2400(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2400);
	// stw r3,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r3.u32);
	// lwz r11,280(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 280);
	// stb r11,27(r31)
	REX_STORE_U8(ctx.r31.u32 + 27, ctx.r11.u8);
	// lwz r9,392(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 392);
	// stb r9,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r9.u8);
	// lwz r4,328(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 328);
	// stb r4,29(r31)
	REX_STORE_U8(ctx.r31.u32 + 29, ctx.r4.u8);
	// lwz r11,3984(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 3984);
	// addi r10,r11,-3
	ctx.r10.s64 = ctx.r11.s64 + -3;
	// addi r9,r11,-2
	ctx.r9.s64 = ctx.r11.s64 + -2;
	// cntlzw r6,r10
	ctx.r6.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r4,r9
	ctx.r4.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r6,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// rlwinm r11,r4,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// or r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 | ctx.r11.u64;
	// stb r10,30(r31)
	REX_STORE_U8(ctx.r31.u32 + 30, ctx.r10.u8);
	// lwz r9,2164(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 2164);
	// stw r9,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r9.u32);
	// lwz r6,2540(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 2540);
	// stw r6,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r6.u32);
	// lwz r4,21192(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 21192);
	// stw r4,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r4.u32);
	// lwz r3,21212(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 21212);
	// stw r3,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r3.u32);
	// sth r7,46(r31)
	REX_STORE_U16(ctx.r31.u32 + 46, ctx.r7.u16);
	// sth r7,44(r31)
	REX_STORE_U16(ctx.r31.u32 + 44, ctx.r7.u16);
	// lwz r11,416(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 416);
	// sth r11,62(r31)
	REX_STORE_U16(ctx.r31.u32 + 62, ctx.r11.u16);
	// lwz r9,420(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 420);
	// sth r9,64(r31)
	REX_STORE_U16(ctx.r31.u32 + 64, ctx.r9.u16);
	// lwz r4,424(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 424);
	// sth r4,66(r31)
	REX_STORE_U16(ctx.r31.u32 + 66, ctx.r4.u16);
	// lwz r11,428(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 428);
	// sth r11,68(r31)
	REX_STORE_U16(ctx.r31.u32 + 68, ctx.r11.u16);
	// lwz r9,408(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// sth r9,70(r31)
	REX_STORE_U16(ctx.r31.u32 + 70, ctx.r9.u16);
	// lwz r4,412(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 412);
	// sth r4,72(r31)
	REX_STORE_U16(ctx.r31.u32 + 72, ctx.r4.u16);
	// lwz r11,14804(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 14804);
	// stb r11,32(r31)
	REX_STORE_U8(ctx.r31.u32 + 32, ctx.r11.u8);
	// lwz r9,1792(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 1792);
	// stb r9,31(r31)
	REX_STORE_U8(ctx.r31.u32 + 31, ctx.r9.u8);
	// lwz r4,336(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 336);
	// stb r4,34(r31)
	REX_STORE_U8(ctx.r31.u32 + 34, ctx.r4.u8);
	// lwz r11,6576(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 6576);
	// stw r11,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r11.u32);
	// lwz r10,14784(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 14784);
	// stw r10,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r10.u32);
	// stw r5,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r5.u32);
	// stw r8,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r8.u32);
	// lwz r9,2904(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 2904);
	// stw r9,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r9.u32);
	// lwz r8,2908(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 2908);
	// stw r8,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r8.u32);
	// lwz r6,2912(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 2912);
	// stw r6,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r6.u32);
	// lwz r5,2916(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 2916);
	// stw r5,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r5.u32);
	// lwz r4,2920(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 2920);
	// stw r4,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r4.u32);
	// lwz r3,2924(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2924);
	// stw r3,424(r31)
	REX_STORE_U32(ctx.r31.u32 + 424, ctx.r3.u32);
	// lwz r11,1940(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1940);
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// lwz r10,2992(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 2992);
	// stb r10,33(r31)
	REX_STORE_U8(ctx.r31.u32 + 33, ctx.r10.u8);
	// lwz r8,1832(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1832);
	// stw r8,444(r31)
	REX_STORE_U32(ctx.r31.u32 + 444, ctx.r8.u32);
	// lwz r6,456(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 456);
	// stb r6,48(r31)
	REX_STORE_U8(ctx.r31.u32 + 48, ctx.r6.u8);
	// stb r7,49(r31)
	REX_STORE_U8(ctx.r31.u32 + 49, ctx.r7.u8);
	// lwz r4,3928(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 3928);
	// stb r4,35(r31)
	REX_STORE_U8(ctx.r31.u32 + 35, ctx.r4.u8);
	// lwz r11,136(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// mulli r10,r11,-6
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(-6));
	// sth r10,368(r31)
	REX_STORE_U16(ctx.r31.u32 + 368, ctx.r10.u16);
	// lwz r8,136(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r6,370(r31)
	REX_STORE_U16(ctx.r31.u32 + 370, ctx.r6.u16);
	// lwz r4,136(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r3,372(r31)
	REX_STORE_U16(ctx.r31.u32 + 372, ctx.r3.u16);
	// lwz r10,136(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r9,374(r31)
	REX_STORE_U16(ctx.r31.u32 + 374, ctx.r9.u16);
	// lwz r6,136(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// neg r5,r6
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r6.u64);
	// sth r5,364(r31)
	REX_STORE_U16(ctx.r31.u32 + 364, ctx.r5.u16);
	// lwz r3,136(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// sth r3,366(r31)
	REX_STORE_U16(ctx.r31.u32 + 366, ctx.r3.u16);
	// stw r28,484(r31)
	REX_STORE_U32(ctx.r31.u32 + 484, ctx.r28.u32);
	// stw r26,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r26.u32);
	// stw r24,468(r31)
	REX_STORE_U32(ctx.r31.u32 + 468, ctx.r24.u32);
	// stw r27,472(r31)
	REX_STORE_U32(ctx.r31.u32 + 472, ctx.r27.u32);
	// stw r25,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r25.u32);
	// stw r29,480(r31)
	REX_STORE_U32(ctx.r31.u32 + 480, ctx.r29.u32);
	// lwz r10,22364(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 22364);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x826f9cbc
	if (!ctx.cr6.eq) goto loc_826F9CBC;
	// lwz r11,15932(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 15932);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826f9c54
	if (ctx.cr6.eq) goto loc_826F9C54;
	// lwz r11,15936(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 15936);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826f9c54
	if (ctx.cr6.eq) goto loc_826F9C54;
	// lwz r11,15940(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 15940);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x826f9c54
	if (!ctx.cr6.eq) goto loc_826F9C54;
	// lwz r11,15944(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 15944);
	// lwz r10,220(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r10,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r10.u32);
	// lwz r9,15944(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 15944);
	// lwz r11,224(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 224);
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r8,472(r31)
	REX_STORE_U32(ctx.r31.u32 + 472, ctx.r8.u32);
	// lwz r6,15944(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 15944);
	// lwz r11,224(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 224);
	// lwz r10,8(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r5,480(r31)
	REX_STORE_U32(ctx.r31.u32 + 480, ctx.r5.u32);
loc_826F9C54:
	// lwz r10,3744(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 3744);
	// lwz r11,220(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,560(r31)
	REX_STORE_U32(ctx.r31.u32 + 560, ctx.r11.u32);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,564(r31)
	REX_STORE_U32(ctx.r31.u32 + 564, ctx.r11.u32);
	// lwz r10,204(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,560(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 560);
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// stw r8,568(r31)
	REX_STORE_U32(ctx.r31.u32 + 568, ctx.r8.u32);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r6,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r5,572(r31)
	REX_STORE_U32(ctx.r31.u32 + 572, ctx.r5.u32);
	// lwz r10,3748(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 3748);
	// lwz r11,224(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 224);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r4,576(r31)
	REX_STORE_U32(ctx.r31.u32 + 576, ctx.r4.u32);
	// lwz r11,224(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 224);
	// lwz r10,3752(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 3752);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r3,580(r31)
	REX_STORE_U32(ctx.r31.u32 + 580, ctx.r3.u32);
	// b 0x826fa0ac
	goto loc_826FA0AC;
loc_826F9CBC:
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// lwz r10,20912(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// mullw r11,r9,r10
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// stw r11,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r11.u32);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r8,468(r31)
	REX_STORE_U32(ctx.r31.u32 + 468, ctx.r8.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r6,204(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// rlwinm r10,r6,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r5,472(r31)
	REX_STORE_U32(ctx.r31.u32 + 472, ctx.r5.u32);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r3,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r3.u32);
	// lwz r11,208(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// lwz r9,20912(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// mullw r11,r10,r9
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r8,r11,r27
	ctx.r8.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r8,480(r31)
	REX_STORE_U32(ctx.r31.u32 + 480, ctx.r8.u32);
	// lwz r6,208(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r5,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 1;
	// lwz r4,20912(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// mullw r11,r5,r4
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// add r3,r11,r29
	ctx.r3.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r3,484(r31)
	REX_STORE_U32(ctx.r31.u32 + 484, ctx.r3.u32);
	// lwz r11,20912(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// lwz r10,204(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// srawi r9,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// stw r11,512(r31)
	REX_STORE_U32(ctx.r31.u32 + 512, ctx.r11.u32);
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r8,516(r31)
	REX_STORE_U32(ctx.r31.u32 + 516, ctx.r8.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r6,204(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// rlwinm r10,r6,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r5,520(r31)
	REX_STORE_U32(ctx.r31.u32 + 520, ctx.r5.u32);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r3,524(r31)
	REX_STORE_U32(ctx.r31.u32 + 524, ctx.r3.u32);
	// lwz r10,20912(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// lwz r11,208(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// mullw r11,r9,r10
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r8,r11,r25
	ctx.r8.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r8,528(r31)
	REX_STORE_U32(ctx.r31.u32 + 528, ctx.r8.u32);
	// lwz r6,208(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r5,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 1;
	// lwz r4,20912(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// mullw r11,r5,r4
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r3,532(r31)
	REX_STORE_U32(ctx.r31.u32 + 532, ctx.r3.u32);
	// lwz r11,21928(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 21928);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826f9e48
	if (!ctx.cr6.eq) goto loc_826F9E48;
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// lwz r10,20912(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// mullw r11,r9,r10
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// stw r11,488(r31)
	REX_STORE_U32(ctx.r31.u32 + 488, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r8,492(r31)
	REX_STORE_U32(ctx.r31.u32 + 492, ctx.r8.u32);
	// lwz r9,488(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 488);
	// lwz r6,204(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// rlwinm r10,r6,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r5,496(r31)
	REX_STORE_U32(ctx.r31.u32 + 496, ctx.r5.u32);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r3,500(r31)
	REX_STORE_U32(ctx.r31.u32 + 500, ctx.r3.u32);
	// lwz r10,20912(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// lwz r11,208(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// xori r8,r10,1
	ctx.r8.u64 = ctx.r10.u64 ^ 1;
	// mullw r11,r9,r8
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// add r6,r11,r27
	ctx.r6.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r6,504(r31)
	REX_STORE_U32(ctx.r31.u32 + 504, ctx.r6.u32);
	// lwz r4,20912(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// lwz r5,208(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r11,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 1;
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r10,508(r31)
	REX_STORE_U32(ctx.r31.u32 + 508, ctx.r10.u32);
	// b 0x826f9f88
	goto loc_826F9F88;
loc_826F9E48:
	// lwz r11,284(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 284);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x826f9ee0
	if (!ctx.cr6.eq) goto loc_826F9EE0;
	// lwz r11,20952(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20952);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826f9ee0
	if (ctx.cr6.eq) goto loc_826F9EE0;
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r11,488(r31)
	REX_STORE_U32(ctx.r31.u32 + 488, ctx.r11.u32);
	// addi r10,r11,8
	ctx.r10.s64 = ctx.r11.s64 + 8;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r10,492(r31)
	REX_STORE_U32(ctx.r31.u32 + 492, ctx.r10.u32);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r8,204(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r6,496(r31)
	REX_STORE_U32(ctx.r31.u32 + 496, ctx.r6.u32);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r5,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r4,500(r31)
	REX_STORE_U32(ctx.r31.u32 + 500, ctx.r4.u32);
	// lwz r3,20912(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// xori r11,r3,1
	ctx.r11.u64 = ctx.r3.u64 ^ 1;
	// lwz r10,208(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r9,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// add r8,r11,r27
	ctx.r8.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r8,504(r31)
	REX_STORE_U32(ctx.r31.u32 + 504, ctx.r8.u32);
	// lwz r4,208(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// lwz r6,20912(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// srawi r3,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 1;
	// mullw r11,r3,r5
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r11,508(r31)
	REX_STORE_U32(ctx.r31.u32 + 508, ctx.r11.u32);
	// b 0x826f9f88
	goto loc_826F9F88;
loc_826F9EE0:
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// lwz r8,20912(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// srawi r6,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r11.s32 >> 1;
	// lwz r9,3744(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3744);
	// lwz r10,220(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// mullw r11,r6,r8
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r5,r11,8
	ctx.r5.s64 = ctx.r11.s64 + 8;
	// stw r11,488(r31)
	REX_STORE_U32(ctx.r31.u32 + 488, ctx.r11.u32);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r5,492(r31)
	REX_STORE_U32(ctx.r31.u32 + 492, ctx.r5.u32);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r4,204(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r3,496(r31)
	REX_STORE_U32(ctx.r31.u32 + 496, ctx.r3.u32);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r10,500(r31)
	REX_STORE_U32(ctx.r31.u32 + 500, ctx.r10.u32);
	// lwz r9,208(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// lwz r8,20912(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// srawi r6,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 1;
	// lwz r9,3748(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3748);
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// lwz r10,224(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 224);
	// mullw r11,r6,r5
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r4,504(r31)
	REX_STORE_U32(ctx.r31.u32 + 504, ctx.r4.u32);
	// lwz r3,20912(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// lwz r9,3752(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3752);
	// lwz r10,208(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r8,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// xori r11,r3,1
	ctx.r11.u64 = ctx.r3.u64 ^ 1;
	// lwz r10,224(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 224);
	// mullw r11,r8,r11
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r6,508(r31)
	REX_STORE_U32(ctx.r31.u32 + 508, ctx.r6.u32);
loc_826F9F88:
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// lwz r10,20912(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// mullw r11,r9,r10
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// stw r11,536(r31)
	REX_STORE_U32(ctx.r31.u32 + 536, ctx.r11.u32);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r8,540(r31)
	REX_STORE_U32(ctx.r31.u32 + 540, ctx.r8.u32);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r6,204(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// rlwinm r11,r6,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r5,544(r31)
	REX_STORE_U32(ctx.r31.u32 + 544, ctx.r5.u32);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r3,548(r31)
	REX_STORE_U32(ctx.r31.u32 + 548, ctx.r3.u32);
	// lwz r10,20912(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// lwz r11,208(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r8,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// mullw r11,r8,r9
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// add r6,r11,r25
	ctx.r6.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r6,552(r31)
	REX_STORE_U32(ctx.r31.u32 + 552, ctx.r6.u32);
	// lwz r4,20912(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
	// lwz r5,208(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r11,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 1;
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r10,556(r31)
	REX_STORE_U32(ctx.r31.u32 + 556, ctx.r10.u32);
	// lwz r10,220(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 220);
	// lwz r9,3744(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3744);
	// lwz r6,204(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// srawi r5,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 1;
	// lwz r8,20912(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// mullw r11,r5,r8
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r4,r11,8
	ctx.r4.s64 = ctx.r11.s64 + 8;
	// stw r11,560(r31)
	REX_STORE_U32(ctx.r31.u32 + 560, ctx.r11.u32);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r4,564(r31)
	REX_STORE_U32(ctx.r31.u32 + 564, ctx.r4.u32);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r3,204(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// rlwinm r11,r3,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r11,568(r31)
	REX_STORE_U32(ctx.r31.u32 + 568, ctx.r11.u32);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r8,572(r31)
	REX_STORE_U32(ctx.r31.u32 + 572, ctx.r8.u32);
	// lwz r10,224(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 224);
	// lwz r5,20912(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// lwz r9,3748(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3748);
	// lwz r6,208(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r4,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 1;
	// mullw r11,r4,r5
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r5.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r3,576(r31)
	REX_STORE_U32(ctx.r31.u32 + 576, ctx.r3.u32);
	// lwz r11,20912(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// lwz r10,224(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 224);
	// lwz r8,208(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// srawi r6,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 1;
	// mullw r11,r6,r11
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// lwz r9,3752(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3752);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r5,580(r31)
	REX_STORE_U32(ctx.r31.u32 + 580, ctx.r5.u32);
loc_826FA0AC:
	// lwz r11,21124(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 21124);
	// stw r11,1404(r31)
	REX_STORE_U32(ctx.r31.u32 + 1404, ctx.r11.u32);
	// lwz r11,3984(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 3984);
	// addi r10,r11,-3
	ctx.r10.s64 = ctx.r11.s64 + -3;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stw r8,2316(r31)
	REX_STORE_U32(ctx.r31.u32 + 2316, ctx.r8.u32);
	// lwz r6,14836(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 14836);
	// stw r6,1824(r31)
	REX_STORE_U32(ctx.r31.u32 + 1824, ctx.r6.u32);
	// lwz r5,14812(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 14812);
	// stw r5,1828(r31)
	REX_STORE_U32(ctx.r31.u32 + 1828, ctx.r5.u32);
	// lwz r4,14816(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 14816);
	// stw r4,1832(r31)
	REX_STORE_U32(ctx.r31.u32 + 1832, ctx.r4.u32);
	// lwz r3,3416(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 3416);
	// lwz r11,14808(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 14808);
	// mullw r10,r11,r3
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// stw r10,1788(r31)
	REX_STORE_U32(ctx.r31.u32 + 1788, ctx.r10.u32);
	// lwz r9,15308(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 15308);
	// stw r9,1836(r31)
	REX_STORE_U32(ctx.r31.u32 + 1836, ctx.r9.u32);
	// lwz r8,15312(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 15312);
	// stw r8,1840(r31)
	REX_STORE_U32(ctx.r31.u32 + 1840, ctx.r8.u32);
	// lwz r6,15316(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 15316);
	// stw r6,1844(r31)
	REX_STORE_U32(ctx.r31.u32 + 1844, ctx.r6.u32);
	// lwz r5,15320(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 15320);
	// stw r5,1848(r31)
	REX_STORE_U32(ctx.r31.u32 + 1848, ctx.r5.u32);
	// lwz r4,21924(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 21924);
	// stw r4,1396(r31)
	REX_STORE_U32(ctx.r31.u32 + 1396, ctx.r4.u32);
	// lwz r3,21920(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 21920);
	// stw r3,1400(r31)
	REX_STORE_U32(ctx.r31.u32 + 1400, ctx.r3.u32);
	// lwz r11,20912(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// stw r11,1368(r31)
	REX_STORE_U32(ctx.r31.u32 + 1368, ctx.r11.u32);
	// lwz r10,21928(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 21928);
	// stw r10,1372(r31)
	REX_STORE_U32(ctx.r31.u32 + 1372, ctx.r10.u32);
	// lwz r9,3988(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3988);
	// stw r9,1752(r31)
	REX_STORE_U32(ctx.r31.u32 + 1752, ctx.r9.u32);
	// lwz r8,20952(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 20952);
	// stw r8,1756(r31)
	REX_STORE_U32(ctx.r31.u32 + 1756, ctx.r8.u32);
	// lwz r6,20956(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 20956);
	// stw r6,1760(r31)
	REX_STORE_U32(ctx.r31.u32 + 1760, ctx.r6.u32);
	// lwz r5,20960(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 20960);
	// stw r5,1764(r31)
	REX_STORE_U32(ctx.r31.u32 + 1764, ctx.r5.u32);
	// lwz r4,20964(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 20964);
	// stw r4,1768(r31)
	REX_STORE_U32(ctx.r31.u32 + 1768, ctx.r4.u32);
	// lwz r3,20968(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 20968);
	// stw r3,1772(r31)
	REX_STORE_U32(ctx.r31.u32 + 1772, ctx.r3.u32);
	// lwz r11,20972(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20972);
	// stw r11,1776(r31)
	REX_STORE_U32(ctx.r31.u32 + 1776, ctx.r11.u32);
	// lwz r10,22364(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 22364);
	// stw r10,1780(r31)
	REX_STORE_U32(ctx.r31.u32 + 1780, ctx.r10.u32);
	// lwz r9,22364(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 22364);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x826fa1f8
	if (!ctx.cr6.eq) goto loc_826FA1F8;
	// lwz r11,22040(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 22040);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r10,40248
	ctx.r8.u64 = ctx.r10.u64 | 40248;
	// ori r6,r9,40252
	ctx.r6.u64 = ctx.r9.u64 | 40252;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// stw r11,1456(r31)
	REX_STORE_U32(ctx.r31.u32 + 1456, ctx.r11.u32);
	// addis r4,r30,2
	ctx.r4.s64 = ctx.r30.s64 + 131072;
	// ori r3,r5,40240
	ctx.r3.u64 = ctx.r5.u64 | 40240;
	// addi r4,r4,-25292
	ctx.r4.s64 = ctx.r4.s64 + -25292;
	// lwz r11,22396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 22396);
	// stw r11,1460(r31)
	REX_STORE_U32(ctx.r31.u32 + 1460, ctx.r11.u32);
	// lwz r10,22068(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 22068);
	// stw r10,1464(r31)
	REX_STORE_U32(ctx.r31.u32 + 1464, ctx.r10.u32);
	// lwzx r9,r30,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r8.u32);
	// stw r9,1484(r31)
	REX_STORE_U32(ctx.r31.u32 + 1484, ctx.r9.u32);
	// lwzx r8,r30,r6
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r6.u32);
	// stw r8,1480(r31)
	REX_STORE_U32(ctx.r31.u32 + 1480, ctx.r8.u32);
	// lwzx r6,r30,r3
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r3.u32);
	// stw r6,1476(r31)
	REX_STORE_U32(ctx.r31.u32 + 1476, ctx.r6.u32);
	// lwz r5,0(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stw r5,1468(r31)
	REX_STORE_U32(ctx.r31.u32 + 1468, ctx.r5.u32);
	// lwz r3,20912(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 20912);
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// subfe r9,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r9,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r6,1472(r31)
	REX_STORE_U32(ctx.r31.u32 + 1472, ctx.r6.u32);
loc_826FA1F8:
	// lwz r10,3004(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 3004);
	// li r11,7
	ctx.r11.s64 = 7;
	// lis r9,32
	ctx.r9.s64 = 2097152;
	// vspltish v13,8
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x8)));
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// ori r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 | 32;
	// lis r5,64
	ctx.r5.s64 = 4194304;
	// stw r10,588(r31)
	REX_STORE_U32(ctx.r31.u32 + 588, ctx.r10.u32);
	// lis r4,8
	ctx.r4.s64 = 524288;
	// stw r10,584(r31)
	REX_STORE_U32(ctx.r31.u32 + 584, ctx.r10.u32);
	// ori r3,r5,64
	ctx.r3.u64 = ctx.r5.u64 | 64;
	// lwz r29,3012(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 3012);
	// ori r9,r4,8
	ctx.r9.u64 = ctx.r4.u64 | 8;
	// stw r29,596(r31)
	REX_STORE_U32(ctx.r31.u32 + 596, ctx.r29.u32);
	// addi r10,r31,1120
	ctx.r10.s64 = ctx.r31.s64 + 1120;
	// stw r29,592(r31)
	REX_STORE_U32(ctx.r31.u32 + 592, ctx.r29.u32);
	// li r5,1104
	ctx.r5.s64 = 1104;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r29,3016(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 3016);
	// stw r29,600(r31)
	REX_STORE_U32(ctx.r31.u32 + 600, ctx.r29.u32);
	// lwz r29,3024(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 3024);
	// stw r29,604(r31)
	REX_STORE_U32(ctx.r31.u32 + 604, ctx.r29.u32);
	// lwz r29,2580(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 2580);
	// stw r29,608(r31)
	REX_STORE_U32(ctx.r31.u32 + 608, ctx.r29.u32);
	// lwz r29,2500(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 2500);
	// stw r29,612(r31)
	REX_STORE_U32(ctx.r31.u32 + 612, ctx.r29.u32);
	// lwz r29,15504(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 15504);
	// stw r29,1168(r31)
	REX_STORE_U32(ctx.r31.u32 + 1168, ctx.r29.u32);
	// lwz r29,15504(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 15504);
	// srawi r28,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r28.s64 = ctx.r29.s32 >> 31;
	// subfc r11,r11,r29
	ctx.xer.ca = ctx.r29.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r29.u64 - ctx.r11.u64;
	// adde r11,r8,r28
	temp.u8 = (ctx.r8.u32 + ctx.r28.u32 < ctx.r8.u32) | (ctx.r8.u32 + ctx.r28.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ctx.r8.u64 + ctx.r28.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r11,2320(r31)
	REX_STORE_U32(ctx.r31.u32 + 2320, ctx.r11.u32);
	// lwz r8,22408(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 22408);
	// stw r8,1172(r31)
	REX_STORE_U32(ctx.r31.u32 + 1172, ctx.r8.u32);
	// lwz r11,1852(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1852);
	// stw r11,620(r31)
	REX_STORE_U32(ctx.r31.u32 + 620, ctx.r11.u32);
	// lwz r8,1856(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1856);
	// stw r8,624(r31)
	REX_STORE_U32(ctx.r31.u32 + 624, ctx.r8.u32);
	// lwz r11,1860(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1860);
	// stw r11,632(r31)
	REX_STORE_U32(ctx.r31.u32 + 632, ctx.r11.u32);
	// lbz r8,35(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// addis r11,r8,31
	ctx.r11.s64 = ctx.r8.s64 + 2031616;
	// addi r11,r11,31
	ctx.r11.s64 = ctx.r11.s64 + 31;
	// stw r11,1136(r31)
	REX_STORE_U32(ctx.r31.u32 + 1136, ctx.r11.u32);
	// lbz r8,35(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// addis r11,r8,15
	ctx.r11.s64 = ctx.r8.s64 + 983040;
	// addi r11,r11,15
	ctx.r11.s64 = ctx.r11.s64 + 15;
	// stw r11,1140(r31)
	REX_STORE_U32(ctx.r31.u32 + 1140, ctx.r11.u32);
	// lbz r8,35(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// addis r11,r8,7
	ctx.r11.s64 = ctx.r8.s64 + 458752;
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// stw r11,1144(r31)
	REX_STORE_U32(ctx.r31.u32 + 1144, ctx.r11.u32);
	// lbz r8,35(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// addis r11,r8,3
	ctx.r11.s64 = ctx.r8.s64 + 196608;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// stw r11,1148(r31)
	REX_STORE_U32(ctx.r31.u32 + 1148, ctx.r11.u32);
	// lbz r8,35(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// subf r6,r8,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r8.u64;
	// stw r6,1152(r31)
	REX_STORE_U32(ctx.r31.u32 + 1152, ctx.r6.u32);
	// lbz r11,35(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// subf r8,r11,r3
	ctx.r8.u64 = ctx.r3.u64 - ctx.r11.u64;
	// stw r8,1156(r31)
	REX_STORE_U32(ctx.r31.u32 + 1156, ctx.r8.u32);
	// lbz r6,35(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// subf r3,r6,r9
	ctx.r3.u64 = ctx.r9.u64 - ctx.r6.u64;
	// stw r3,1160(r31)
	REX_STORE_U32(ctx.r31.u32 + 1160, ctx.r3.u32);
	// lbz r11,35(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// sth r11,1134(r31)
	REX_STORE_U16(ctx.r31.u32 + 1134, ctx.r11.u16);
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsplth v0,v12,7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u16), simde_mm_set1_epi16(short(0x100))));
	// vsubshs v11,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// stvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stvx128 v11,r31,r5
	ea = (ctx.r31.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r4,1176(r31)
	REX_STORE_U16(ctx.r31.u32 + 1176, ctx.r4.u16);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r9,r11,32
	ctx.r9.s64 = ctx.r11.s64 + 32;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,16
	ctx.r11.s64 = 16;
	// srawi r6,r8,6
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 6;
	// sth r6,1178(r31)
	REX_STORE_U16(ctx.r31.u32 + 1178, ctx.r6.u16);
	// lwz r9,204(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r8,r31,1190
	ctx.r8.s64 = ctx.r31.s64 + 1190;
	// addi r4,r9,16
	ctx.r4.s64 = ctx.r9.s64 + 16;
	// rlwinm r3,r4,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// srawi r9,r3,6
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 6;
	// sth r9,1180(r31)
	REX_STORE_U16(ctx.r31.u32 + 1180, ctx.r9.u16);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// srawi r3,r4,6
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3F) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 6;
	// sth r3,1182(r31)
	REX_STORE_U16(ctx.r31.u32 + 1182, ctx.r3.u16);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// rlwinm r6,r9,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// srawi r5,r6,6
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3F) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 6;
	// sth r5,1184(r31)
	REX_STORE_U16(ctx.r31.u32 + 1184, ctx.r5.u16);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// srawi r9,r11,6
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 6;
	// sth r9,1186(r31)
	REX_STORE_U16(ctx.r31.u32 + 1186, ctx.r9.u16);
	// lwz r11,204(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r5,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// srawi r3,r4,6
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3F) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 6;
	// sth r3,1188(r31)
	REX_STORE_U16(ctx.r31.u32 + 1188, ctx.r3.u16);
	// lwz r9,204(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// mulli r11,r9,28
	ctx.r11.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(28));
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// srawi r5,r6,6
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3F) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 6;
	// sth r5,1190(r31)
	REX_STORE_U16(ctx.r31.u32 + 1190, ctx.r5.u16);
loc_826FA3D4:
	// lwz r11,208(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// srawi r6,r9,6
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 6;
	// sthu r6,2(r8)
	ea = 2 + ctx.r8.u32;
	REX_STORE_U16(ea, ctx.r6.u16);
	ctx.r8.u32 = ea;
	// bdnz 0x826fa3d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FA3D4;
	// lwz r11,2116(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2116);
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r30,24192
	ctx.r9.s64 = ctx.r30.s64 + 24192;
	// addi r8,r30,2140
	ctx.r8.s64 = ctx.r30.s64 + 2140;
	// addi r6,r30,24448
	ctx.r6.s64 = ctx.r30.s64 + 24448;
	// stw r11,1224(r31)
	REX_STORE_U32(ctx.r31.u32 + 1224, ctx.r11.u32);
	// lwz r5,2120(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 2120);
	// stw r5,1228(r31)
	REX_STORE_U32(ctx.r31.u32 + 1228, ctx.r5.u32);
	// lwz r4,21936(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 21936);
	// stw r4,1236(r31)
	REX_STORE_U32(ctx.r31.u32 + 1236, ctx.r4.u32);
	// lwz r3,21940(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 21940);
	// stw r3,1240(r31)
	REX_STORE_U32(ctx.r31.u32 + 1240, ctx.r3.u32);
	// lwz r11,20916(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20916);
	// stw r11,1380(r31)
	REX_STORE_U32(ctx.r31.u32 + 1380, ctx.r11.u32);
	// lwz r5,15252(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 15252);
	// stw r5,1384(r31)
	REX_STORE_U32(ctx.r31.u32 + 1384, ctx.r5.u32);
	// lwz r11,15504(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 15504);
	// addi r4,r11,-7
	ctx.r4.s64 = ctx.r11.s64 + -7;
	// addic r3,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r3.s64 = ctx.r4.s64 + -1;
	// subfe r5,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r5,r10
	ctx.r4.u64 = ctx.r5.u64 & ctx.r10.u64;
	// stb r4,1324(r31)
	REX_STORE_U8(ctx.r31.u32 + 1324, ctx.r4.u8);
	// lwz r3,20992(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 20992);
	// stw r3,1388(r31)
	REX_STORE_U32(ctx.r31.u32 + 1388, ctx.r3.u32);
	// lwz r11,3984(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 3984);
	// stw r11,1392(r31)
	REX_STORE_U32(ctx.r31.u32 + 1392, ctx.r11.u32);
	// lwz r10,248(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// stb r10,1244(r31)
	REX_STORE_U8(ctx.r31.u32 + 1244, ctx.r10.u8);
	// lwz r4,4004(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4004);
	// stb r4,1245(r31)
	REX_STORE_U8(ctx.r31.u32 + 1245, ctx.r4.u8);
	// lwz r11,4012(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4012);
	// stb r11,1246(r31)
	REX_STORE_U8(ctx.r31.u32 + 1246, ctx.r11.u8);
	// lwz r5,252(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 252);
	// stb r5,1249(r31)
	REX_STORE_U8(ctx.r31.u32 + 1249, ctx.r5.u8);
	// lwz r3,472(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 472);
	// stb r3,1250(r31)
	REX_STORE_U8(ctx.r31.u32 + 1250, ctx.r3.u8);
	// lwz r10,22192(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 22192);
	// stw r10,1304(r31)
	REX_STORE_U32(ctx.r31.u32 + 1304, ctx.r10.u32);
	// lwz r5,284(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 284);
	// stw r5,1308(r31)
	REX_STORE_U32(ctx.r31.u32 + 1308, ctx.r5.u32);
	// lwz r4,1972(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 1972);
	// stb r4,1247(r31)
	REX_STORE_U8(ctx.r31.u32 + 1247, ctx.r4.u8);
	// lwz r11,1976(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1976);
	// stb r11,1248(r31)
	REX_STORE_U8(ctx.r31.u32 + 1248, ctx.r11.u8);
	// lwz r5,1968(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 1968);
	// stb r5,1251(r31)
	REX_STORE_U8(ctx.r31.u32 + 1251, ctx.r5.u8);
	// lwz r3,22508(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 22508);
	// stw r3,1312(r31)
	REX_STORE_U32(ctx.r31.u32 + 1312, ctx.r3.u32);
	// lwz r11,3940(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 3940);
	// stw r11,1316(r31)
	REX_STORE_U32(ctx.r31.u32 + 1316, ctx.r11.u32);
	// stw r9,1260(r31)
	REX_STORE_U32(ctx.r31.u32 + 1260, ctx.r9.u32);
	// stw r8,1232(r31)
	REX_STORE_U32(ctx.r31.u32 + 1232, ctx.r8.u32);
	// lwz r10,20932(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20932);
	// stb r10,1254(r31)
	REX_STORE_U8(ctx.r31.u32 + 1254, ctx.r10.u8);
	// lwz r8,21868(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 21868);
	// stb r8,1255(r31)
	REX_STORE_U8(ctx.r31.u32 + 1255, ctx.r8.u8);
	// stw r6,1264(r31)
	REX_STORE_U32(ctx.r31.u32 + 1264, ctx.r6.u32);
	// lwz r4,20904(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 20904);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x826fa508
	if (ctx.cr6.eq) goto loc_826FA508;
	// lwz r11,20908(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20908);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826fa508
	if (!ctx.cr6.eq) goto loc_826FA508;
	// lwz r11,1832(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1832);
	// stw r11,1268(r31)
	REX_STORE_U32(ctx.r31.u32 + 1268, ctx.r11.u32);
	// lwz r10,20976(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20976);
	// stw r10,1272(r31)
	REX_STORE_U32(ctx.r31.u32 + 1272, ctx.r10.u32);
	// lwz r9,20980(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 20980);
	// stw r9,1300(r31)
	REX_STORE_U32(ctx.r31.u32 + 1300, ctx.r9.u32);
	// b 0x826fa588
	goto loc_826FA588;
loc_826FA508:
	// lwz r11,15504(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 15504);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x826fa558
	if (!ctx.cr6.eq) goto loc_826FA558;
	// lwz r11,1812(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1812);
	// stw r11,1268(r31)
	REX_STORE_U32(ctx.r31.u32 + 1268, ctx.r11.u32);
	// lwz r10,1812(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 1812);
	// stw r10,1272(r31)
	REX_STORE_U32(ctx.r31.u32 + 1272, ctx.r10.u32);
	// lwz r9,1820(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 1820);
	// stw r9,1276(r31)
	REX_STORE_U32(ctx.r31.u32 + 1276, ctx.r9.u32);
	// lwz r8,1816(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1816);
	// stw r8,1280(r31)
	REX_STORE_U32(ctx.r31.u32 + 1280, ctx.r8.u32);
	// lwz r6,1820(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1820);
	// stw r6,1284(r31)
	REX_STORE_U32(ctx.r31.u32 + 1284, ctx.r6.u32);
	// lwz r5,1816(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 1816);
	// stw r5,1288(r31)
	REX_STORE_U32(ctx.r31.u32 + 1288, ctx.r5.u32);
	// lwz r4,1820(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 1820);
	// stw r4,1292(r31)
	REX_STORE_U32(ctx.r31.u32 + 1292, ctx.r4.u32);
	// lwz r3,1816(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 1816);
	// stw r3,1296(r31)
	REX_STORE_U32(ctx.r31.u32 + 1296, ctx.r3.u32);
	// b 0x826fa588
	goto loc_826FA588;
loc_826FA558:
	// lwz r11,1808(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1808);
	// stw r11,1268(r31)
	REX_STORE_U32(ctx.r31.u32 + 1268, ctx.r11.u32);
	// lwz r10,1820(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 1820);
	// stw r10,1272(r31)
	REX_STORE_U32(ctx.r31.u32 + 1272, ctx.r10.u32);
	// lwz r9,1804(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 1804);
	// stw r9,1276(r31)
	REX_STORE_U32(ctx.r31.u32 + 1276, ctx.r9.u32);
	// lwz r8,1816(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1816);
	// stw r8,1280(r31)
	REX_STORE_U32(ctx.r31.u32 + 1280, ctx.r8.u32);
	// lwz r6,1800(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 1800);
	// stw r6,1284(r31)
	REX_STORE_U32(ctx.r31.u32 + 1284, ctx.r6.u32);
	// lwz r5,1812(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 1812);
	// stw r5,1288(r31)
	REX_STORE_U32(ctx.r31.u32 + 1288, ctx.r5.u32);
loc_826FA588:
	// sth r7,1256(r31)
	REX_STORE_U16(ctx.r31.u32 + 1256, ctx.r7.u16);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r7,1796(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1796);
	// addis r8,r30,2
	ctx.r8.s64 = ctx.r30.s64 + 131072;
	// stb r7,1252(r31)
	REX_STORE_U8(ctx.r31.u32 + 1252, ctx.r7.u8);
	// addi r7,r10,18016
	ctx.r7.s64 = ctx.r10.s64 + 18016;
	// lwz r3,1936(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 1936);
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r8,r8,-25684
	ctx.r8.s64 = ctx.r8.s64 + -25684;
	// addi r5,r30,24512
	ctx.r5.s64 = ctx.r30.s64 + 24512;
	// addi r4,r30,24704
	ctx.r4.s64 = ctx.r30.s64 + 24704;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// stb r3,1253(r31)
	REX_STORE_U8(ctx.r31.u32 + 1253, ctx.r3.u8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r10,22508(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 22508);
	// stw r10,1312(r31)
	REX_STORE_U32(ctx.r31.u32 + 1312, ctx.r10.u32);
	// lwz r6,3940(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 3940);
	// stw r6,1316(r31)
	REX_STORE_U32(ctx.r31.u32 + 1316, ctx.r6.u32);
	// lwz r3,3944(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 3944);
	// stw r3,1320(r31)
	REX_STORE_U32(ctx.r31.u32 + 1320, ctx.r3.u32);
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r11,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r11.u32);
	// lhz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// rlwinm r6,r10,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r8,0(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// rotlwi r11,r6,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r3,r6,r8
	ctx.r3.u64 = uint32_t((ctx.r8.s32 && !(ctx.r6.s32 == INT32_MIN && ctx.r8.s32 == -1)) ? ctx.r6.s32 / ctx.r8.s32 : 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r3,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r3.u32);
	// twllei r8,0
	if (ctx.r8.s32 == 0 || ctx.r8.u32 < 0u) ppc_trap(ctx, base, 0);
	// stw r5,1356(r31)
	REX_STORE_U32(ctx.r31.u32 + 1356, ctx.r5.u32);
	// andc r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 & ~ctx.r11.u64;
	// stw r4,1360(r31)
	REX_STORE_U32(ctx.r31.u32 + 1360, ctx.r4.u32);
	// twlgei r10,-1
	if (ctx.r10.s32 == -1 || ctx.r10.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// lwz r8,1764(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1764);
	// stw r8,616(r31)
	REX_STORE_U32(ctx.r31.u32 + 616, ctx.r8.u32);
	// lwz r6,15872(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 15872);
	// stw r6,960(r31)
	REX_STORE_U32(ctx.r31.u32 + 960, ctx.r6.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r11,1356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1356);
	// lwz r8,204(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 204);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_826FA630:
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stb r6,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r6.u8);
	// rlwinm r5,r10,0,24,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFE;
	// rlwinm r4,r10,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// mullw r3,r5,r8
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// stb r4,-1(r11)
	REX_STORE_U8(ctx.r11.u32 + -1, ctx.r4.u8);
	// stw r3,3(r11)
	REX_STORE_U32(ctx.r11.u32 + 3, ctx.r3.u32);
	// clrlwi r5,r10,31
	ctx.r5.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x826fa670
	if (ctx.cr6.eq) goto loc_826FA670;
	// rlwinm r10,r10,16,16,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF;
	// rlwinm r5,r10,0,24,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFE;
	// rlwinm r4,r10,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// mullw r3,r5,r8
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// stb r4,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r4.u8);
	// stw r3,7(r11)
	REX_STORE_U32(ctx.r11.u32 + 7, ctx.r3.u32);
loc_826FA670:
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// bdnz 0x826fa630
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FA630;
	// li r10,16
	ctx.r10.s64 = 16;
	// lwz r11,1360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1360);
	// lwz r8,208(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 208);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826FA694:
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stb r6,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r6.u8);
	// rlwinm r7,r10,0,24,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFE;
	// rlwinm r5,r10,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// mullw r4,r7,r8
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// stb r5,-1(r11)
	REX_STORE_U8(ctx.r11.u32 + -1, ctx.r5.u8);
	// stw r4,3(r11)
	REX_STORE_U32(ctx.r11.u32 + 3, ctx.r4.u32);
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826fa6d4
	if (ctx.cr6.eq) goto loc_826FA6D4;
	// rlwinm r10,r10,16,16,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF;
	// rlwinm r7,r10,0,24,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFE;
	// rlwinm r5,r10,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// mullw r4,r7,r8
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// stb r5,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r5.u8);
	// stw r4,7(r11)
	REX_STORE_U32(ctx.r11.u32 + 7, ctx.r4.u32);
loc_826FA6D4:
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// bdnz 0x826fa694
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FA694;
	// lwz r11,1792(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1792);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826fa908
	if (ctx.cr6.eq) goto loc_826FA908;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x826fa908
	if (!ctx.cr6.eq) goto loc_826FA908;
	// addis r10,r30,2
	ctx.r10.s64 = ctx.r30.s64 + 131072;
	// lwz r11,620(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 620);
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r10,r10,-25508
	ctx.r10.s64 = ctx.r10.s64 + -25508;
	// stw r10,1796(r31)
	REX_STORE_U32(ctx.r31.u32 + 1796, ctx.r10.u32);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826FA718:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r7,r8,4,26,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0x30;
	// rlwinm r6,r8,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r4,r5,0,25,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x7E;
	// stbx r4,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r4.u8);
	// lbz r3,1(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rlwinm r8,r3,4,26,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0x30;
	// rlwinm r7,r3,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x7FFFFFFF;
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwinm r5,r6,0,25,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x7E;
	// stb r5,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, ctx.r5.u8);
	// lbz r4,2(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r3,r4,4,26,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0x30;
	// rlwinm r8,r4,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// or r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 | ctx.r8.u64;
	// rlwinm r6,r7,0,25,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x7E;
	// stb r6,3(r9)
	REX_STORE_U8(ctx.r9.u32 + 3, ctx.r6.u8);
	// lbz r5,3(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rlwinm r4,r5,4,26,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0x30;
	// rlwinm r3,r5,31,1,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// or r8,r4,r3
	ctx.r8.u64 = ctx.r4.u64 | ctx.r3.u64;
	// rlwinm r7,r8,0,25,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x7E;
	// stbu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r7.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826fa718
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FA718;
	// addis r10,r30,2
	ctx.r10.s64 = ctx.r30.s64 + 131072;
	// lwz r11,624(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r10,r10,-25476
	ctx.r10.s64 = ctx.r10.s64 + -25476;
	// stw r10,1800(r31)
	REX_STORE_U32(ctx.r31.u32 + 1800, ctx.r10.u32);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826FA7A0:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r7,r8,3,24,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xF8;
	// rlwinm r6,r8,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r4,r5,0,26,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x3E;
	// stbx r4,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r4.u8);
	// lbz r3,1(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rlwinm r8,r3,3,24,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xF8;
	// rlwinm r7,r3,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3FFFFFFF;
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwinm r5,r6,0,26,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x3E;
	// stb r5,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, ctx.r5.u8);
	// lbz r4,2(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r3,r4,3,24,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xF8;
	// rlwinm r8,r4,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	// or r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 | ctx.r8.u64;
	// rlwinm r6,r7,0,26,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x3E;
	// stb r6,3(r9)
	REX_STORE_U8(ctx.r9.u32 + 3, ctx.r6.u8);
	// lbz r5,3(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rlwinm r4,r5,3,24,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xF8;
	// rlwinm r3,r5,30,2,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// or r8,r4,r3
	ctx.r8.u64 = ctx.r4.u64 | ctx.r3.u64;
	// rlwinm r7,r8,0,26,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x3E;
	// stbu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r7.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826fa7a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FA7A0;
	// addis r10,r30,2
	ctx.r10.s64 = ctx.r30.s64 + 131072;
	// lwz r11,632(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 632);
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r10,r10,-25444
	ctx.r10.s64 = ctx.r10.s64 + -25444;
	// stw r10,1808(r31)
	REX_STORE_U32(ctx.r31.u32 + 1808, ctx.r10.u32);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826FA828:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r7,r8,3,27,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0x18;
	// rlwinm r6,r8,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r4,r5,0,25,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x7E;
	// stbx r4,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r4.u8);
	// lbz r3,1(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rlwinm r8,r3,3,27,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0x18;
	// rlwinm r7,r3,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x7FFFFFFF;
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwinm r5,r6,0,25,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x7E;
	// stb r5,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, ctx.r5.u8);
	// lbz r4,2(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r3,r4,3,27,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0x18;
	// rlwinm r8,r4,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// or r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 | ctx.r8.u64;
	// rlwinm r6,r7,0,25,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x7E;
	// stb r6,3(r9)
	REX_STORE_U8(ctx.r9.u32 + 3, ctx.r6.u8);
	// lbz r5,3(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rlwinm r4,r5,3,27,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0x18;
	// rlwinm r3,r5,31,1,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// or r8,r4,r3
	ctx.r8.u64 = ctx.r4.u64 | ctx.r3.u64;
	// rlwinm r7,r8,0,25,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x7E;
	// stbu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r7.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826fa828
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FA828;
	// addis r10,r30,2
	ctx.r10.s64 = ctx.r30.s64 + 131072;
	// lwz r11,444(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 444);
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r10,r10,-25572
	ctx.r10.s64 = ctx.r10.s64 + -25572;
	// stw r10,1812(r31)
	REX_STORE_U32(ctx.r31.u32 + 1812, ctx.r10.u32);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826FA8B0:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r7,r8,30,2,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFE;
	// rlwinm r6,r8,4,25,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0x70;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// stbx r5,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r5.u8);
	// lbz r4,1(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rlwinm r3,r4,30,2,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFE;
	// rlwinm r8,r4,4,25,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0x70;
	// or r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 | ctx.r8.u64;
	// stb r7,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, ctx.r7.u8);
	// lbz r6,2(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r5,r6,30,2,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFE;
	// rlwinm r4,r6,4,25,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0x70;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stb r3,3(r9)
	REX_STORE_U8(ctx.r9.u32 + 3, ctx.r3.u8);
	// lbz r8,3(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rlwinm r7,r8,30,2,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFE;
	// rlwinm r6,r8,4,25,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0x70;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// stbu r5,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r5.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x826fa8b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FA8B0;
loc_826FA908:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82751350) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x82751358;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af24
	ctx.lr = 0x82751360;
	__savefpr_27(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r21,0
	ctx.r21.s64 = 0;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// li r22,0
	ctx.r22.s64 = 0;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bne cr6,0x827516d0
	if (!ctx.cr6.eq) goto loc_827516D0;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,112(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 112);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x827516d0
	if (!ctx.cr6.eq) goto loc_827516D0;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,112(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 112);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bne cr6,0x827516d0
	if (!ctx.cr6.eq) goto loc_827516D0;
	// not r8,r11
	ctx.r8.u64 = ~ctx.r11.u64;
	// lwz r4,104(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 104);
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// lwz r3,104(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 104);
	// rlwinm r5,r8,16,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0x1;
	// rlwinm r31,r11,15,31,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0x1;
	// bl 0x82751228
	ctx.lr = 0x827513BC;
	sub_82751228(ctx, base);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// lwz r4,108(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r3,108(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 108);
	// bl 0x82751228
	ctx.lr = 0x827513D8;
	sub_82751228(ctx, base);
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x827516a0
	if (ctx.cr6.eq) goto loc_827516A0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827516a0
	if (ctx.cr6.eq) goto loc_827516A0;
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lis r10,4095
	ctx.r10.s64 = 268369920;
	// li r23,-1
	ctx.r23.s64 = -1;
	// ori r31,r10,65535
	ctx.r31.u64 = ctx.r10.u64 | 65535;
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x82751410
	if (!ctx.cr6.gt) goto loc_82751410;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
loc_82751410:
	// bl 0x825dfbe0
	ctx.lr = 0x82751414;
	sub_825DFBE0(ctx, base);
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827516a0
	if (ctx.cr6.eq) goto loc_827516A0;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x8275143c
	if (!ctx.cr6.gt) goto loc_8275143C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
loc_8275143C:
	// bl 0x825dfbe0
	ctx.lr = 0x82751440;
	sub_825DFBE0(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827516a0
	if (ctx.cr6.eq) goto loc_827516A0;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// li r24,0
	ctx.r24.s64 = 0;
	// mr r25,r23
	ctx.r25.u64 = ctx.r23.u64;
	// mr r26,r23
	ctx.r26.u64 = ctx.r23.u64;
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// lwz r10,108(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 108);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// add r30,r11,r3
	ctx.r30.u64 = ctx.r11.u64 + ctx.r3.u64;
	// ble cr6,0x82751698
	if (!ctx.cr6.gt) goto loc_82751698;
	// addi r28,r19,8
	ctx.r28.s64 = ctx.r19.s64 + 8;
loc_82751480:
	// lwz r4,-8(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + -8);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplw cr6,r4,r25
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x827514d0
	if (ctx.cr6.eq) goto loc_827514D0;
	// cmplw cr6,r4,r26
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x827514bc
	if (ctx.cr6.eq) goto loc_827514BC;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827514B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x827514d0
	goto loc_827514D0;
loc_827514BC:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// mr r26,r23
	ctx.r26.u64 = ctx.r23.u64;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_827514D0:
	// lwz r4,0(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplw cr6,r4,r26
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x827514fc
	if (ctx.cr6.eq) goto loc_827514FC;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827514FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_827514FC:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82751660
	if (!ctx.cr6.gt) goto loc_82751660;
	// addi r10,r20,-16
	ctx.r10.s64 = ctx.r20.s64 + -16;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
loc_82751514:
	// lfs f0,28(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,24(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// lfs f13,20(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lwzu r8,16(r10)
	ea = 16 + ctx.r10.u32;
	ctx.r8.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f12,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r8,r8,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f11,-4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// add r7,r9,r30
	ctx.r7.u64 = ctx.r9.u64 + ctx.r30.u64;
	// add r6,r8,r30
	ctx.r6.u64 = ctx.r8.u64 + ctx.r30.u64;
	// add r5,r9,r31
	ctx.r5.u64 = ctx.r9.u64 + ctx.r31.u64;
	// lfsx f10,r9,r30
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r30.u32);
	ctx.f10.f64 = double(temp.f32);
	// add r4,r8,r31
	ctx.r4.u64 = ctx.r8.u64 + ctx.r31.u64;
	// lfsx f9,r8,r30
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r30.u32);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// lfs f8,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f9,f13,f9
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// lfs f5,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f8,f8,f0
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// lfsx f2,r9,r31
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f5,f5,f13
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// lfs f7,8(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f2,f0,f2
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f2.f64));
	// lfs f6,12(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f7,f7,f0
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// lfs f4,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f6,f6,f0
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// lfs f1,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f4,f4,f13
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// lfs f31,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfs f3,12(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f31,f31,f0
	ctx.f31.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f30,12(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f3,f3,f13
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// lfsx f29,r8,r31
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// lfs f30,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f29,f13,f29
	ctx.f29.f64 = double(float(ctx.f13.f64 * ctx.f29.f64));
	// lfs f28,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f28.f64 = double(temp.f32);
	// fmuls f30,f30,f13
	ctx.f30.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// lfs f27,12(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f27.f64 = double(temp.f32);
	// fmuls f28,f28,f13
	ctx.f28.f64 = double(float(ctx.f28.f64 * ctx.f13.f64));
	// fmuls f13,f27,f13
	ctx.f13.f64 = double(float(ctx.f27.f64 * ctx.f13.f64));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fadds f10,f9,f10
	ctx.f10.f64 = double(float(ctx.f9.f64 + ctx.f10.f64));
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// fadds f9,f5,f8
	ctx.f9.f64 = double(float(ctx.f5.f64 + ctx.f8.f64));
	// fadds f8,f4,f7
	ctx.f8.f64 = double(float(ctx.f4.f64 + ctx.f7.f64));
	// fadds f7,f3,f6
	ctx.f7.f64 = double(float(ctx.f3.f64 + ctx.f6.f64));
	// fadds f6,f29,f2
	ctx.f6.f64 = double(float(ctx.f29.f64 + ctx.f2.f64));
	// fadds f5,f30,f1
	ctx.f5.f64 = double(float(ctx.f30.f64 + ctx.f1.f64));
	// fadds f4,f28,f31
	ctx.f4.f64 = double(float(ctx.f28.f64 + ctx.f31.f64));
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// fmuls f13,f10,f12
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fmuls f10,f9,f12
	ctx.f10.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fmuls f9,f8,f12
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f12,f7,f12
	ctx.f12.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// fmuls f8,f6,f11
	ctx.f8.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fmuls f7,f5,f11
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f11.f64));
	// fmuls f6,f4,f11
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f11.f64));
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// fadds f13,f8,f13
	ctx.f13.f64 = double(float(ctx.f8.f64 + ctx.f13.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fadds f13,f7,f10
	ctx.f13.f64 = double(float(ctx.f7.f64 + ctx.f10.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fadds f13,f6,f9
	ctx.f13.f64 = double(float(ctx.f6.f64 + ctx.f9.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r8,8(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r7,12(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r6,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// stw r7,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// lwz r9,4(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r9,104(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 104);
	// cmplw cr6,r27,r9
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82751514
	if (ctx.cr6.lt) goto loc_82751514;
loc_82751660:
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82751680;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// addi r28,r28,16
	ctx.r28.s64 = ctx.r28.s64 + 16;
	// lwz r11,108(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82751480
	if (ctx.cr6.lt) goto loc_82751480;
loc_82751698:
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x827516a8
	goto loc_827516A8;
loc_827516A0:
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
loc_827516A8:
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x825ac978
	ctx.lr = 0x827516B0;
	sub_825AC978(ctx, base);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x825ac978
	ctx.lr = 0x827516B8;
	sub_825AC978(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x825ac978
	ctx.lr = 0x827516C0;
	sub_825AC978(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x825ac978
	ctx.lr = 0x827516C8;
	sub_825AC978(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x827516d8
	goto loc_827516D8;
loc_827516D0:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
loc_827516D8:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af70
	ctx.lr = 0x827516E4;
	__restfpr_27(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82769038) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82769040;
	__savegprlr_23(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,284(r1)
	REX_STORE_U32(ctx.r1.u32 + 284, ctx.r4.u32);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r24,0
	ctx.r24.s64 = 0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r25,r24
	ctx.r25.u64 = ctx.r24.u64;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82769070;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,284(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// stb r24,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r24.u8);
	// stb r3,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r3.u8);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ld r28,16(r11)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r11.u32 + 16);
	// beq 0x827690c8
	if (ctx.cr0.eq) goto loc_827690C8;
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// b 0x827690a0
	goto loc_827690A0;
loc_82769098:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lwz r10,84(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 84);
loc_827690A0:
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82769098
	if (!ctx.cr0.eq) goto loc_82769098;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_827690AC:
	// lwz r9,396(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 396);
	// rlwinm. r9,r9,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x827690dc
	if (ctx.cr0.eq) goto loc_827690DC;
	// lwz r10,88(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 88);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x827690ac
	if (!ctx.cr6.eq) goto loc_827690AC;
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
loc_827690C8:
	// li r30,1
	ctx.r30.s64 = 1;
	// cmpldi cr6,r28,0
	ctx.cr6.compare<uint64_t>(ctx.r28.u64, 0, ctx.xer);
	// bne cr6,0x827690e4
	if (!ctx.cr6.eq) goto loc_827690E4;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// b 0x82769100
	goto loc_82769100;
loc_827690DC:
	// ld r28,16(r10)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r10.u32 + 16);
	// b 0x827690c8
	goto loc_827690C8;
loc_827690E4:
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// rldicr r9,r28,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u64, 0) & 0xFFFF000000000000;
	// rldicr r10,r10,48,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 48) & 0xFFFF000000000000;
	// cmpld cr6,r9,r10
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, ctx.r10.u64, ctx.xer);
	// beq cr6,0x82769100
	if (ctx.cr6.eq) goto loc_82769100;
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
loc_82769100:
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
loc_82769104:
	// addi r10,r31,95
	ctx.r10.s64 = ctx.r31.s64 + 95;
	// rlwinm r29,r10,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r29,r26
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r26.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82769260
	if (ctx.cr6.eq) goto loc_82769260;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82769260
	if (ctx.cr6.eq) goto loc_82769260;
	// cmpldi cr6,r28,0
	ctx.cr6.compare<uint64_t>(ctx.r28.u64, 0, ctx.xer);
	// beq cr6,0x827691c8
	if (ctx.cr6.eq) goto loc_827691C8;
	// lwz r11,396(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 396);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8276917c
	if (ctx.cr0.eq) goto loc_8276917C;
	// lwz r11,84(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 84);
	// b 0x82769144
	goto loc_82769144;
loc_8276913C:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
loc_82769144:
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8276913c
	if (!ctx.cr0.eq) goto loc_8276913C;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_82769150:
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82769174
	if (ctx.cr0.eq) goto loc_82769174;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82769150
	if (!ctx.cr6.eq) goto loc_82769150;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,1307
	ctx.r3.u64 = ctx.r3.u64 | 1307;
	// b 0x82769388
	goto loc_82769388;
loc_82769174:
	// lwz r3,24(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// b 0x82769180
	goto loc_82769180;
loc_8276917C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82769180:
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x827ac948
	ctx.lr = 0x8276918C;
	sub_827AC948(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x827691c4
	if (ctx.cr0.eq) goto loc_827691C4;
	// cmplwi cr6,r3,1245
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1245, ctx.xer);
	// bne cr6,0x8276931c
	if (!ctx.cr6.eq) goto loc_8276931C;
	// lwz r11,28(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827691c0
	if (ctx.cr6.eq) goto loc_827691C0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x827691c0
	if (ctx.cr6.eq) goto loc_827691C0;
	// lwz r11,284(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// b 0x827691d4
	goto loc_827691D4;
loc_827691C0:
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
loc_827691C4:
	// lwz r11,284(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
loc_827691C8:
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x827691e8
	if (ctx.cr6.eq) goto loc_827691E8;
loc_827691D4:
	// lbz r10,81(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// slw r8,r30,r31
	ctx.r8.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r31.u8 & 0x3F));
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
	// stb r10,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r10.u8);
	// b 0x827691ec
	goto loc_827691EC;
loc_827691E8:
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
loc_827691EC:
	// cmplwi cr6,r31,255
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 255, ctx.xer);
	// bne cr6,0x827691fc
	if (!ctx.cr6.eq) goto loc_827691FC;
	// li r10,15
	ctx.r10.s64 = 15;
	// b 0x82769204
	goto loc_82769204;
loc_827691FC:
	// slw r10,r30,r31
	ctx.r10.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r31.u8 & 0x3F));
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
loc_82769204:
	// lbz r8,392(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 392);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// and r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 & ctx.r10.u64;
	// addic r8,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// subfe r10,r8,r10
	temp.u8 = (~ctx.r8.u32 + ctx.r10.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r8.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addic r8,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// subfe r8,r8,r9
	temp.u8 = (~ctx.r8.u32 + ctx.r9.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r8.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82769288
	if (ctx.cr6.eq) goto loc_82769288;
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// rlwinm. r10,r10,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82769238
	if (!ctx.cr0.eq) goto loc_82769238;
	// lwzx r25,r29,r26
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r26.u32);
loc_82769238:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lbz r10,392(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 392);
	// slw r9,r30,r31
	ctx.r9.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r31.u8 & 0x3F));
	// beq cr6,0x82769250
	if (ctx.cr6.eq) goto loc_82769250;
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// b 0x82769254
	goto loc_82769254;
loc_82769250:
	// andc r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 & ~ctx.r9.u64;
loc_82769254:
	// stb r10,392(r11)
	REX_STORE_U8(ctx.r11.u32 + 392, ctx.r10.u8);
	// lwz r11,284(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// b 0x82769288
	goto loc_82769288;
loc_82769260:
	// lbz r10,392(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 392);
	// slw r9,r30,r31
	ctx.r9.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r31.u8 & 0x3F));
	// andc r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 & ~ctx.r9.u64;
	// stb r10,392(r11)
	REX_STORE_U8(ctx.r11.u32 + 392, ctx.r10.u8);
	// lwz r11,284(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// lwzx r10,r29,r26
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r26.u32);
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// or r27,r10,r27
	ctx.r27.u64 = ctx.r10.u64 | ctx.r27.u64;
loc_82769288:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// blt cr6,0x82769104
	if (ctx.cr6.lt) goto loc_82769104;
	// cntlzw r10,r27
	ctx.r10.u64 = ctx.r27.u32 == 0 ? 32 : __builtin_clz(ctx.r27.u32);
	// lwz r9,396(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwimi r9,r10,17,14,14
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0x20000) | (ctx.r9.u64 & 0xFFFFFFFFFFFDFFFF);
	// stw r9,396(r11)
	REX_STORE_U32(ctx.r11.u32 + 396, ctx.r9.u32);
	// beq cr6,0x82769384
	if (ctx.cr6.eq) goto loc_82769384;
	// addi r11,r1,284
	ctx.r11.s64 = ctx.r1.s64 + 284;
	// stw r25,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stw r25,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r25.u32);
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r24,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r24.u32);
	// li r8,143
	ctx.r8.s64 = 143;
	// stw r30,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r30.u32);
	// stw r24,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r24.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r24,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r24.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r10,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r10.u32);
	// stw r9,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r9.u32);
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// stw r24,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r24.u32);
	// stw r24,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r24.u32);
	// sth r24,160(r1)
	REX_STORE_U16(ctx.r1.u32 + 160, ctx.r24.u16);
	// stb r8,162(r1)
	REX_STORE_U8(ctx.r1.u32 + 162, ctx.r8.u8);
	// bl 0x827673e0
	ctx.lr = 0x82769308;
	sub_827673E0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82769388
	if (ctx.cr0.lt) goto loc_82769388;
	// lwz r11,284(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// b 0x82769338
	goto loc_82769338;
loc_8276931C:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x82769388
	if (!ctx.cr6.gt) goto loc_82769388;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r3,r11,32775
	ctx.r3.u64 = ctx.r11.u64 | 2147942400;
	// b 0x82769388
	goto loc_82769388;
loc_82769330:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r10,84(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 84);
loc_82769338:
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82769330
	if (!ctx.cr0.eq) goto loc_82769330;
	// addi r10,r1,92
	ctx.r10.s64 = ctx.r1.s64 + 92;
	// stw r11,284(r1)
	REX_STORE_U32(ctx.r1.u32 + 284, ctx.r11.u32);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
loc_8276934C:
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,284(r1)
	REX_STORE_U32(ctx.r1.u32 + 284, ctx.r11.u32);
	// bne cr6,0x8276934c
	if (!ctx.cr6.eq) goto loc_8276934C;
	// mr r8,r23
	ctx.r8.u64 = ctx.r23.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x827682d0
	ctx.lr = 0x8276937C;
	sub_827682D0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82769388
	if (ctx.cr0.lt) goto loc_82769388;
loc_82769384:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
loc_82769388:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8277E330) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee8
	ctx.lr = 0x8277E338;
	__savegprlr_16(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// li r3,10
	ctx.r3.s64 = 10;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// bl 0x82788e50
	ctx.lr = 0x8277E358;
	sub_82788E50(ctx, base);
	// mr. r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// bne 0x8277e36c
	if (!ctx.cr0.eq) goto loc_8277E36C;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x8277e63c
	goto loc_8277E63C;
loc_8277E36C:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,36(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// li r17,0
	ctx.r17.s64 = 0;
	// stw r30,73(r18)
	REX_STORE_U32(ctx.r18.u32 + 73, ctx.r30.u32);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// mr r24,r17
	ctx.r24.u64 = ctx.r17.u64;
	// std r17,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r17.u64);
	// std r17,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r17.u64);
	// stw r10,69(r18)
	REX_STORE_U32(ctx.r18.u32 + 69, ctx.r10.u32);
	// beq cr6,0x8277e5f8
	if (ctx.cr6.eq) goto loc_8277E5F8;
	// li r19,1
	ctx.r19.s64 = 1;
	// li r16,-1
	ctx.r16.s64 = -1;
loc_8277E39C:
	// rlwinm r20,r24,29,3,31
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 29) & 0x1FFFFFFF;
	// lwz r30,0(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r21,r1,80
	ctx.r21.s64 = ctx.r1.s64 + 80;
	// clrlwi r11,r24,29
	ctx.r11.u64 = ctx.r24.u32 & 0x7;
	// slw r23,r19,r11
	ctx.r23.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r19.u32 << (ctx.r11.u8 & 0x3F));
	// lbzx r31,r20,r21
	ctx.r31.u64 = REX_LOAD_U8(ctx.r20.u32 + ctx.r21.u32);
	// and. r11,r31,r23
	ctx.r11.u64 = ctx.r31.u64 & ctx.r23.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8277e5e8
	if (!ctx.cr0.eq) goto loc_8277E5E8;
	// li r7,131
	ctx.r7.s64 = 131;
	// lwz r6,32(r18)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r18.u32 + 32);
	// addi r5,r18,36
	ctx.r5.s64 = ctx.r18.s64 + 36;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82785048
	ctx.lr = 0x8277E3D4;
	sub_82785048(ctx, base);
	// lwz r27,232(r30)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r30.u32 + 232);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8277e430
	if (ctx.cr6.eq) goto loc_8277E430;
	// addi r11,r24,1
	ctx.r11.s64 = ctx.r24.s64 + 1;
	// cmplw cr6,r11,r22
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r22.u32, ctx.xer);
	// bge cr6,0x8277e458
	if (!ctx.cr6.lt) goto loc_8277E458;
	// addi r10,r29,4
	ctx.r10.s64 = ctx.r29.s64 + 4;
loc_8277E3F0:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r27
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8277e410
	if (ctx.cr6.eq) goto loc_8277E410;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r11,r22
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r22.u32, ctx.xer);
	// blt cr6,0x8277e3f0
	if (ctx.cr6.lt) goto loc_8277E3F0;
	// b 0x8277e458
	goto loc_8277E458;
loc_8277E410:
	// rlwinm r9,r11,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// slw r11,r19,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r19.u32 << (ctx.r11.u8 & 0x3F));
	// lbzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// or r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 | ctx.r8.u64;
	// stbx r11,r9,r10
	REX_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r11.u8);
	// b 0x8277e43c
	goto loc_8277E43C;
loc_8277E430:
	// or r11,r31,r23
	ctx.r11.u64 = ctx.r31.u64 | ctx.r23.u64;
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// stbx r11,r20,r21
	REX_STORE_U8(ctx.r20.u32 + ctx.r21.u32, ctx.r11.u8);
loc_8277E43C:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r16
	ctx.r5.u64 = ctx.r16.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82785460
	ctx.lr = 0x8277E458;
	sub_82785460(ctx, base);
loc_8277E458:
	// lwz r11,192(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 192);
	// mr r25,r17
	ctx.r25.u64 = ctx.r17.u64;
	// mr r26,r17
	ctx.r26.u64 = ctx.r17.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8277e510
	if (ctx.cr6.eq) goto loc_8277E510;
	// mr r28,r17
	ctx.r28.u64 = ctx.r17.u64;
loc_8277E470:
	// lwz r11,184(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 184);
	// lwzx r4,r28,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// lwz r11,232(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 232);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8277e4fc
	if (ctx.cr0.eq) goto loc_8277E4FC;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8277e4f8
	if (!ctx.cr6.eq) goto loc_8277E4F8;
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// cmplw cr6,r24,r22
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r22.u32, ctx.xer);
	// bge cr6,0x8277e4f8
	if (!ctx.cr6.lt) goto loc_8277E4F8;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8277E49C:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8277e4bc
	if (ctx.cr6.eq) goto loc_8277E4BC;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r31,r22
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r22.u32, ctx.xer);
	// blt cr6,0x8277e49c
	if (ctx.cr6.lt) goto loc_8277E49C;
	// b 0x8277e4f8
	goto loc_8277E4F8;
loc_8277E4BC:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82785460
	ctx.lr = 0x8277E4D4;
	sub_82785460(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8277e5fc
	if (!ctx.cr0.eq) goto loc_8277E5FC;
	// rlwinm r10,r31,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// clrlwi r9,r31,29
	ctx.r9.u64 = ctx.r31.u32 & 0x7;
	// slw r9,r19,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r19.u32 << (ctx.r9.u8 & 0x3F));
	// lbzx r8,r10,r11
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stbx r9,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
loc_8277E4F8:
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
loc_8277E4FC:
	// lwz r11,192(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 192);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8277e470
	if (ctx.cr6.lt) goto loc_8277E470;
loc_8277E510:
	// lwz r11,228(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 228);
	// mr r26,r17
	ctx.r26.u64 = ctx.r17.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8277e5ac
	if (ctx.cr6.eq) goto loc_8277E5AC;
	// mr r28,r17
	ctx.r28.u64 = ctx.r17.u64;
loc_8277E524:
	// lwz r11,220(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 220);
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// cmplw cr6,r24,r22
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r22.u32, ctx.xer);
	// lwzx r4,r28,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// bge cr6,0x8277e598
	if (!ctx.cr6.lt) goto loc_8277E598;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8277E53C:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8277e55c
	if (ctx.cr6.eq) goto loc_8277E55C;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r31,r22
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r22.u32, ctx.xer);
	// blt cr6,0x8277e53c
	if (ctx.cr6.lt) goto loc_8277E53C;
	// b 0x8277e598
	goto loc_8277E598;
loc_8277E55C:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r16
	ctx.r5.u64 = ctx.r16.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82785460
	ctx.lr = 0x8277E574;
	sub_82785460(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8277e5fc
	if (!ctx.cr0.eq) goto loc_8277E5FC;
	// rlwinm r10,r31,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// clrlwi r9,r31,29
	ctx.r9.u64 = ctx.r31.u32 & 0x7;
	// slw r9,r19,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r19.u32 << (ctx.r9.u8 & 0x3F));
	// lbzx r8,r10,r11
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stbx r9,r10,r11
	REX_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
loc_8277E598:
	// lwz r11,228(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 228);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8277e524
	if (ctx.cr6.lt) goto loc_8277E524;
loc_8277E5AC:
	// lbzx r11,r20,r21
	ctx.r11.u64 = REX_LOAD_U8(ctx.r20.u32 + ctx.r21.u32);
	// and. r10,r11,r23
	ctx.r10.u64 = ctx.r11.u64 & ctx.r23.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8277e5cc
	if (!ctx.cr0.eq) goto loc_8277E5CC;
	// lwz r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// or r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 | ctx.r23.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stbx r11,r20,r21
	REX_STORE_U8(ctx.r20.u32 + ctx.r21.u32, ctx.r11.u8);
	// beq cr6,0x8277e5e8
	if (ctx.cr6.eq) goto loc_8277E5E8;
loc_8277E5CC:
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8277e5e8
	if (ctx.cr6.eq) goto loc_8277E5E8;
	// lis r4,32767
	ctx.r4.s64 = 2147418112;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ori r4,r4,65534
	ctx.r4.u64 = ctx.r4.u64 | 65534;
	// bl 0x827850e0
	ctx.lr = 0x8277E5E8;
	sub_827850E0(ctx, base);
loc_8277E5E8:
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplw cr6,r24,r22
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r22.u32, ctx.xer);
	// blt cr6,0x8277e39c
	if (ctx.cr6.lt) goto loc_8277E39C;
loc_8277E5F8:
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
loc_8277E5FC:
	// addi r11,r18,4
	ctx.r11.s64 = ctx.r18.s64 + 4;
loc_8277E600:
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
	// bne 0x8277e600
	if (!ctx.cr0.eq) goto loc_8277E600;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8277e63c
	if (!ctx.cr6.eq) goto loc_8277E63C;
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8277E63C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8277E63C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82739f38
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8278E7A8) {
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
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8278e804
	if (ctx.cr6.eq) goto loc_8278E804;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8278e7f0
	if (!ctx.cr6.eq) goto loc_8278E7F0;
	// lwz r11,1188(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1188);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8278e804
	if (ctx.cr0.eq) goto loc_8278E804;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,3
	ctx.r10.s64 = 3;
	// stb r11,1185(r3)
	REX_STORE_U8(ctx.r3.u32 + 1185, ctx.r11.u8);
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stb r11,1184(r3)
	REX_STORE_U8(ctx.r3.u32 + 1184, ctx.r11.u8);
	// bl 0x8278c7b8
	ctx.lr = 0x8278E7EC;
	sub_8278C7B8(ctx, base);
	// b 0x8278e804
	goto loc_8278E804;
loc_8278E7F0:
	// lis r11,-32646
	ctx.r11.s64 = -2139488256;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r11,r11,4113
	ctx.r11.u64 = ctx.r11.u64 | 4113;
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// bl 0x8278c810
	ctx.lr = 0x8278E804;
	sub_8278C810(ctx, base);
loc_8278E804:
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

DEFINE_REX_FUNC(sub_82791F20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82791F28;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// cmplwi cr6,r5,1200
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1200, ctx.xer);
	// ble cr6,0x82791f4c
	if (!ctx.cr6.gt) goto loc_82791F4C;
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4102
	ctx.r3.u64 = ctx.r3.u64 | 4102;
	// b 0x82792028
	goto loc_82792028;
loc_82791F4C:
	// addi r30,r31,40
	ctx.r30.s64 = ctx.r31.s64 + 40;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x82791F58;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r29,r31,424
	ctx.r29.s64 = ctx.r31.s64 + 424;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827948b0
	ctx.lr = 0x82791F64;
	sub_827948B0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x82791f7c
	if (!ctx.cr0.lt) goto loc_82791F7C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x82791F74;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x82792028
	goto loc_82792028;
loc_82791F7C:
	// lwz r11,1188(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1188);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// lhz r7,1070(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 1070);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// lhz r6,1068(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 1068);
	// lhz r5,1074(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 1074);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// beq 0x82791fe0
	if (ctx.cr0.eq) goto loc_82791FE0;
	// addi r30,r31,28
	ctx.r30.s64 = ctx.r31.s64 + 28;
	// lwz r10,432(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// addi r28,r31,536
	ctx.r28.s64 = ctx.r31.s64 + 536;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// bl 0x82794a18
	ctx.lr = 0x82791FC0;
	sub_82794A18(ctx, base);
	// lis r11,32512
	ctx.r11.s64 = 2130706432;
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82792000
	if (ctx.cr6.eq) goto loc_82792000;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x827364b8
	ctx.lr = 0x82791FDC;
	sub_827364B8(ctx, base);
	// b 0x82792000
	goto loc_82792000;
loc_82791FE0:
	// lwz r28,432(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// addi r30,r31,536
	ctx.r30.s64 = ctx.r31.s64 + 536;
	// addi r4,r31,28
	ctx.r4.s64 = ctx.r31.s64 + 28;
	// lwz r10,436(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// stw r30,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// bl 0x82794a98
	ctx.lr = 0x82792000;
	sub_82794A98(ctx, base);
loc_82792000:
	// lhz r11,1076(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 1076);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r10,1184(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 1184);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r10,1184(r31)
	REX_STORE_U8(ctx.r31.u32 + 1184, ctx.r10.u8);
	// sth r11,1076(r31)
	REX_STORE_U16(ctx.r31.u32 + 1076, ctx.r11.u16);
	// bl 0x8278fb08
	ctx.lr = 0x82792024;
	sub_8278FB08(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82792028:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82797758) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82797760;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,164(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 164);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82797788
	if (ctx.cr6.eq) goto loc_82797788;
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4105
	ctx.r3.u64 = ctx.r3.u64 | 4105;
	// b 0x82797820
	goto loc_82797820;
loc_82797788:
	// ld r11,272(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 272);
	// lwz r8,144(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// cmpld cr6,r11,r8
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r8.u64, ctx.xer);
	// bge cr6,0x827977a8
	if (!ctx.cr6.lt) goto loc_827977A8;
	// ld r11,336(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 336);
	// lwz r8,148(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// cmpld cr6,r11,r8
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r8.u64, ctx.xer);
	// blt cr6,0x827977b4
	if (ctx.cr6.lt) goto loc_827977B4;
loc_827977A8:
	// lis r3,-32646
	ctx.r3.s64 = -2139488256;
	// ori r3,r3,4101
	ctx.r3.u64 = ctx.r3.u64 | 4101;
	// b 0x82797820
	goto loc_82797820;
loc_827977B4:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x827977d0
	if (!ctx.cr6.eq) goto loc_827977D0;
	// addi r11,r1,104
	ctx.r11.s64 = ctx.r1.s64 + 104;
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// std r30,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r30.u64);
	// stw r30,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r30.u32);
loc_827977D0:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// lwz r29,16(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r7,r11,10
	ctx.r7.s64 = ctx.r11.s64 + 10;
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// subfic r5,r7,31
	ctx.xer.ca = ctx.r7.u32 <= 31;
	ctx.r5.u64 = static_cast<uint64_t>(31) - ctx.r7.u64;
	// ld r11,552(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 552);
	// rldicr r5,r5,59,4
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u64, 59) & 0xF800000000000000;
	// lwz r7,100(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 100);
	// clrldi r4,r11,5
	ctx.r4.u64 = ctx.r11.u64 & 0x7FFFFFFFFFFFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// or r4,r4,r5
	ctx.r4.u64 = ctx.r4.u64 | ctx.r5.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// std r11,552(r29)
	REX_STORE_U64(ctx.r29.u32 + 552, ctx.r11.u64);
	// bl 0x8279b8b8
	ctx.lr = 0x82797814;
	sub_8279B8B8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82797820
	if (ctx.cr0.lt) goto loc_82797820;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82797820:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8279C570) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8279C578;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r27,r3,232
	ctx.r27.s64 = ctx.r3.s64 + 232;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x82855b44
	ctx.lr = 0x8279C598;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r30,18
	ctx.r11.s64 = ctx.r30.s64 + 18;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8279c5b8
	if (!ctx.cr6.eq) goto loc_8279C5B8;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,87
	ctx.r31.u64 = ctx.r31.u64 | 87;
	// b 0x8279c5c8
	goto loc_8279C5C8;
loc_8279C5B8:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8279f6b8
	ctx.lr = 0x8279C5C4;
	sub_8279F6B8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8279C5C8:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82855b34
	ctx.lr = 0x8279C5D0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8279EAE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8279EAF0;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8279ec38
	if (ctx.cr6.lt) goto loc_8279EC38;
	// bne cr6,0x8279ece4
	if (!ctx.cr6.eq) goto loc_8279ECE4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r27,0(r5)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r24,0
	ctx.r24.s64 = 0;
	// addi r31,r3,2100
	ctx.r31.s64 = ctx.r3.s64 + 2100;
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// addi r29,r3,40
	ctx.r29.s64 = ctx.r3.s64 + 40;
	// lfs f31,24852(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24852);
	ctx.f31.f64 = double(temp.f32);
	// subfic r26,r3,-2028
	ctx.xer.ca = ctx.r3.u32 <= 4294965268;
	ctx.r26.u64 = static_cast<uint64_t>(-2028) - ctx.r3.u64;
loc_8279EB34:
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// add r10,r26,r31
	ctx.r10.u64 = ctx.r26.u64 + ctx.r31.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8279ec18
	if (ctx.cr6.eq) goto loc_8279EC18;
	// lwz r11,208(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 208);
	// rlwinm r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x8279ec18
	if (!ctx.cr6.eq) goto loc_8279EC18;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,196(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,8(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// mulli r11,r11,172
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(172));
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r11,r11,36
	ctx.r11.s64 = ctx.r11.s64 + 36;
	// ble cr6,0x8279ebd4
	if (!ctx.cr6.gt) goto loc_8279EBD4;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
loc_8279EB84:
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r8,32767
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 32767, ctx.xer);
	// blt cr6,0x8279ebac
	if (ctx.cr6.lt) goto loc_8279EBAC;
	// li r8,32767
	ctx.r8.s64 = 32767;
	// b 0x8279ebb8
	goto loc_8279EBB8;
loc_8279EBAC:
	// cmpwi cr6,r8,-32768
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -32768, ctx.xer);
	// bgt cr6,0x8279ebb8
	if (ctx.cr6.gt) goto loc_8279EBB8;
	// li r8,-32738
	ctx.r8.s64 = -32738;
loc_8279EBB8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r8,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r8.u16);
	// lwz r8,8(r25)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8279eb84
	if (ctx.cr6.lt) goto loc_8279EB84;
loc_8279EBD4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8279ec1c
	if (ctx.cr6.lt) goto loc_8279EC1C;
	// li r11,128
	ctx.r11.s64 = 128;
	// stw r24,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
	// addi r4,r29,-4
	ctx.r4.s64 = ctx.r29.s64 + -4;
	// addi r9,r29,-4
	ctx.r9.s64 = ctx.r29.s64 + -4;
	// addi r10,r29,-4
	ctx.r10.s64 = ctx.r29.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8279EC00:
	// lhzu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U16(ea);
	ctx.r10.u32 = ea;
	// sthu r11,2(r9)
	ea = 2 + ctx.r9.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r9.u32 = ea;
	// bdnz 0x8279ec00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8279EC00;
	// li r5,258
	ctx.r5.s64 = 258;
	// bl 0x8279f1c8
	ctx.lr = 0x8279EC14;
	sub_8279F1C8(ctx, base);
	// b 0x8279ec1c
	goto loc_8279EC1C;
loc_8279EC18:
	// stw r24,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
loc_8279EC1C:
	// addi r28,r28,3
	ctx.r28.s64 = ctx.r28.s64 + 3;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r29,r29,516
	ctx.r29.s64 = ctx.r29.s64 + 516;
	// cmplwi cr6,r28,12
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 12, ctx.xer);
	// blt cr6,0x8279eb34
	if (ctx.cr6.lt) goto loc_8279EB34;
	// b 0x8279ece4
	goto loc_8279ECE4;
loc_8279EC38:
	// li r24,0
	ctx.r24.s64 = 0;
	// addi r31,r30,2100
	ctx.r31.s64 = ctx.r30.s64 + 2100;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// addi r28,r30,36
	ctx.r28.s64 = ctx.r30.s64 + 36;
	// subfic r26,r30,-2028
	ctx.xer.ca = ctx.r30.u32 <= 4294965268;
	ctx.r26.u64 = static_cast<uint64_t>(-2028) - ctx.r30.u64;
loc_8279EC4C:
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// add r10,r31,r26
	ctx.r10.u64 = ctx.r31.u64 + ctx.r26.u64;
	// lwzx r27,r10,r11
	ctx.r27.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8279eccc
	if (ctx.cr6.eq) goto loc_8279ECCC;
	// lwz r11,208(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 208);
	// rlwinm r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x8279eccc
	if (!ctx.cr6.eq) goto loc_8279ECCC;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,172
	ctx.r5.s64 = 172;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// mulli r11,r11,172
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(172));
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r11,36
	ctx.r3.s64 = ctx.r11.s64 + 36;
	// bl 0x82639688
	ctx.lr = 0x8279EC90;
	sub_82639688(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8279ecd0
	if (ctx.cr6.lt) goto loc_8279ECD0;
	// stw r24,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r28,2
	ctx.r3.s64 = ctx.r28.s64 + 2;
	// bl 0x82639688
	ctx.lr = 0x8279ECB8;
	sub_82639688(ctx, base);
	// li r5,258
	ctx.r5.s64 = 258;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8279f1c8
	ctx.lr = 0x8279ECC8;
	sub_8279F1C8(ctx, base);
	// b 0x8279ecd0
	goto loc_8279ECD0;
loc_8279ECCC:
	// stw r24,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
loc_8279ECD0:
	// addi r29,r29,3
	ctx.r29.s64 = ctx.r29.s64 + 3;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r28,r28,516
	ctx.r28.s64 = ctx.r28.s64 + 516;
	// cmplwi cr6,r29,12
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 12, ctx.xer);
	// blt cr6,0x8279ec4c
	if (ctx.cr6.lt) goto loc_8279EC4C;
loc_8279ECE4:
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// stw r11,8(r23)
	REX_STORE_U32(ctx.r23.u32 + 8, ctx.r11.u32);
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// stw r11,4(r23)
	REX_STORE_U32(ctx.r23.u32 + 4, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827AD560) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10348(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ADB30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-10184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10180(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10180, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE160) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-10004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10004);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10000(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE6F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9828(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9828);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AEF90) {
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
	// lfs f0,22648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
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

DEFINE_REX_FUNC(sub_827AFC78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-9184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9184);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-9180(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -9180, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0170) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9092(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9092);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9032(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9032, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0F08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8636(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8636);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8632(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8632, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1A78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8284(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2690) {
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
	// lfs f0,23352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8028(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8028);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7928(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B37A0) {
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
	// lfs f0,23560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7536);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7416(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B48E0) {
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
	// lfs f0,23784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6996(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6996);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6912(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6912, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B57F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6464(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6464, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6658) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24180(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24180);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6036(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7400) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-5736(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -5736);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5632(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5632, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B81A0) {
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
	// lfs f0,24376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5344(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5344);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5224(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5224, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B94E0) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4780(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4780);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4692(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4692, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BA540) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-4220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4220);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4216(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4216, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB200) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3824(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BBE68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-3544(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -3544);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3440(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3440, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BCCE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3016(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3016, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BDC18) {
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
	// lfs f0,25768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2644(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2644);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2572(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2572, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BEDB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2060(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2060);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2056(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2056, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BFCF0) {
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
	// lfs f0,26200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1700(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1700);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1600(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1600, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0F38) {
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
	// lfs f0,26504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1156(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1156);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1048(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C23C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-468(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C32E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3F98) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,356(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C54F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,896(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 896);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1004(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6148) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1372(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1372, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7090) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1840(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7BD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2200(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8C50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,28648
	ctx.r9.s64 = ctx.r11.s64 + 28648;
	// lfs f0,28648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2684(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 2684, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9BA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28852);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3128(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3128, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CABC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,3596(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3596);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,3600(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 3600, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CB560) {
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
	// lfs f0,29032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3780(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3780);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3900(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CC8D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4468(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD690) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29436(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29436);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4872(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4872, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CE4F8) {
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
	// lfs f0,29544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5224(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5224);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5292(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CF810) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5776(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5776);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5848(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0AB8) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6336(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6336);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6396(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6396, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1D38) {
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
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6888(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6888);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6936(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2FC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,7472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7476(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7476, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D40B0) {
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
	// lfs f0,30440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7844(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7844);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7964(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D5328) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8400(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8400);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8504(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8504, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6148) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8916(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6F08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,9316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 9316);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,9320(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 9320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7FF0) {
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
	// lfs f0,31088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9688(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9688);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9808(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D9268) {
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
	// lfs f0,31304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10240(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10240);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10348(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA4B0) {
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
	// lfs f0,31496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10772(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10772);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10884(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB758) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,31688
	ctx.r9.s64 = ctx.r11.s64 + 31688;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11428(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DCA10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,11992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11996(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DD9B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,32008
	ctx.r9.s64 = ctx.r11.s64 + 32008;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,32008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12452(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12452, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DEC38) {
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
	// lfs f0,32216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12928(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12928);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12996(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DFEF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0E78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14000(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1E48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14484);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14488(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14488, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E2F70) {
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
	// lfs f0,14964(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14964);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32368(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32368);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,14980(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 14980, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E4398) {
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
	// lfs f12,15452(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15452);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,15552(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 15552, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E56F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,16088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16092(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E66C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,16552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16556(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16556, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7780) {
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
	// lfs f0,-27480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16936(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16936);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17004(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8960) {
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
	// lfs f0,-25912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17408(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17408);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17508(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17508, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9EC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18108(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EAD48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18516);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18520(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18520, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EBC38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-22460(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22460);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18936(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ECB98) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19244(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19244);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19356(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EDED8) {
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
	// lfs f0,-20776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19768(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19768);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19884(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EF1D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,20404(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20404);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20408(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F02B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-19080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,20824(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 20824);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20876(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20876, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F12E0) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,21236(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 21236);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,21324(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 21324, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F2498) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-18016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2460(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2460);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21828(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21828, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F35A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-17212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17212);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22292(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F47D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-16680
	ctx.r9.s64 = ctx.r11.s64 + -16680;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-16680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,22996(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 22996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5960) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23548(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23548);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23552(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23552, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6A70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24020(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,620(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 620);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24440(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24440, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8810) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-12344
	ctx.r9.s64 = ctx.r11.s64 + -12344;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-12344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,24816(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 24816, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9DD0) {
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
	// lfs f0,25392(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25392);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10216(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10216);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,25416(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 25416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB7D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26172(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26172, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FC598) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26572);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26576(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26576, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FD498) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-9304
	ctx.r9.s64 = ctx.r11.s64 + -9304;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27012(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27012, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FE828) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-9112
	ctx.r9.s64 = ctx.r11.s64 + -9112;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27584(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27584, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FFBD8) {
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
	// lfs f0,-8920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28036(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28036);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28156(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800EF0) {
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
	// lfs f0,-8728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28612(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28612);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28712(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28712, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802238) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,29172(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 29172);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29276(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29276, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803078) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
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
	// stfs f0,29692(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29692, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803E78) {
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
	// lfs f0,-8216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30056(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30056);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30104(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30104, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805190) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8024(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8024);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,30608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 30608);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30660(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30660, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828062B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31156(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828070D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31572(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31572, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808108) {
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
	// lfs f0,-7576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7576);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31932(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31932);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32040(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828094D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,32616(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 32616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A298) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7172(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7172);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32516(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280B128) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-32096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32096);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-32092(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -32092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280BBD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6916(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6916);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31780(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31780, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280C9C8) {
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
	// lfs f0,-6744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-31400(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31400);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31352(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31352, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280DD80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30788(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280EDA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30308(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30308, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280FCA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29864(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29864, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810D60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29364(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29364, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82811CA8) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28988(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28988);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28916(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813000) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28348(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28348);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28344(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813FC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27852);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27848(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814FB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27348(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815E38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26924);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26920(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26920, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82816FE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26408(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817D48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4012(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4012);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25996(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818E08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25496(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82819B48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-25096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25092(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281AC40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-24584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24584);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-24580(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -24580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281B6D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24268(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24268, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281C698) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23800(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23800, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281D790) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2564(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2564);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23292(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281E560) {
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
	// lfs f0,-2440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23000(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23000);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22880(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281FB78) {
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
	// lfs f0,-2136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22352(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22352);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22232(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22232, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82820E38) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21764(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21764);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21676(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21676, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82822048) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21212(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21212);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21148(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828232E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1364);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82824368) {
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
	// lfs f0,-1160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20208(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20208);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20108(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825778) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19508(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19508);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19504(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19504, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826870) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18996(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82827718) {
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
	// lfs f0,-376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18640(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18640);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18568(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18568, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828AE0) {
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
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18056(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18056);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17984(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17984, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829DF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-17432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17428(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282AF00) {
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
	// lfs f0,216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17044(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17044);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16932(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16932, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282C1D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-16372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16372);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16368(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D090) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-15940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15940);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15936(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E0E8) {
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
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15568(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15568);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15456(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15456, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282F578) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-14956(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -14956);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14852(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830418) {
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
	// lfs f0,1352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14468);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14408(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831798) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-13840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13836(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13836, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832718) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-13376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13372(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13372, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833768) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12884(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82834730) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12412(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828357C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-11924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11924);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-11920(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -11920, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836140) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-11648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11644(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828371C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-11204(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -11204);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11152(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11152, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838358) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10644(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10644, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839190) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-10228(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10228);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10224(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10224, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283A060) {
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
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9880(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9880);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9792(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283B440) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,3552
	ctx.r9.s64 = ctx.r11.s64 + 3552;
	// lfs f0,3552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9212(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -9212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283C440) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3788(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3788);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8748(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8748, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283D2B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-8324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8324);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8320(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283E440) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7812(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7812, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283F280) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7396(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7396, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82840148) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-7060(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7060);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6952(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6952, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828410E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6500);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6496(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828421F8) {
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
	// lfs f0,4912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6108(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6108);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5996(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828435F8) {
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
	// lfs f12,-5512(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5512);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5412(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82844940) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4832(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828457E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4396(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4396, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846788) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3936);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3932(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3932, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847818) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-3452(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3452);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-3448(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -3448, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848240) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3136(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3136, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849270) {
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
	// lfs f0,6336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2768(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2768);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2664(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2664, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284A6C8) {
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
	// lfs f0,6576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6576);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2172(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2172);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2072(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2072, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284BB60) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1584(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1584);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1472(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284CF38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7076(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7076);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284DD08) {
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
	// lfs f0,7312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -524);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-460(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284F180) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,144(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 144, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850168) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,620(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851140) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1056(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1056);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1108(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828521E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,8360
	ctx.r9.s64 = ctx.r11.s64 + 8360;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,8360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1572(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1572, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828534C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2132(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2132);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2136(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2136, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828548D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r6,r1,-16
	ctx.r6.s64 = ctx.r1.s64 + -16;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
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
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32111
	ctx.r5.s64 = -2104426496;
	// vor128 v59,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lfs f13,-80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f13.f64 = double(temp.f32);
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r3,r5,3464
	ctx.r3.s64 = ctx.r5.s64 + 3464;
	// stvx128 v59,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f9.f64 = double(temp.f32);
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stfs f9,3464(r5)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r5.u32 + 3464, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8287E4E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8287E4F0;
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
	// bl 0x82873f18
	ctx.lr = 0x8287E53C;
	sub_82873F18(ctx, base);
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
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vsplth v1,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_set1_epi16(short(0xD0C))));
	// bl 0x8287b580
	ctx.lr = 0x8287E560;
	sub_8287B580(ctx, base);
	// addi r1,r1,912
	ctx.r1.s64 = ctx.r1.s64 + 912;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8288BA70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8288BA78;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// add r11,r3,r5
	ctx.r11.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// lbz r25,668(r11)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 668);
	// dcbzl r0,r7
	ea = (ctx.r7.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// addi r26,r3,232
	ctx.r26.s64 = ctx.r3.s64 + 232;
	// lwz r10,24(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 24);
	// clrlwi r27,r25,30
	ctx.r27.u64 = ctx.r25.u32 & 0x3;
	// lwz r7,0(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// lwz r4,632(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 632);
	// lwz r6,4(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r5,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// dcbzl r0,r30
	ea = (ctx.r30.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x8288baf0
	if (ctx.cr6.lt) goto loc_8288BAF0;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// bl 0x826d4738
	ctx.lr = 0x8288BAE8;
	sub_826D4738(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x8288bb48
	goto loc_8288BB48;
loc_8288BAF0:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x8288bb44
	if (!ctx.cr6.gt) goto loc_8288BB44;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8288BAFC:
	// lhz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r5,26
	ctx.r8.u64 = ctx.r5.u32 & 0x3F;
	// rlwinm r3,r5,24,8,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r3,r7
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// lbzx r3,r10,r4
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r23,r3,r26
	ctx.r23.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r26.u32);
	// rlwinm r5,r5,25,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r5,r5
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// rotlwi r3,r3,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// xor r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// or r9,r23,r9
	ctx.r9.u64 = ctx.r23.u64 | ctx.r9.u64;
	// subf r5,r5,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r5.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r5,r3,r30
	REX_STORE_U16(ctx.r3.u32 + ctx.r30.u32, ctx.r5.u16);
	// bdnz 0x8288bafc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8288BAFC;
loc_8288BB44:
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_8288BB48:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8288bbb4
	if (!ctx.cr6.eq) goto loc_8288BBB4;
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// clrlwi r10,r27,31
	ctx.r10.u64 = ctx.r27.u32 & 0x1;
	// rlwinm r9,r27,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
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
	// add r11,r9,r24
	ctx.r11.u64 = ctx.r9.u64 + ctx.r24.u64;
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
	// b 0x8288bbd0
	goto loc_8288BBD0;
loc_8288BBB4:
	// rlwinm r10,r27,2,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// clrlwi r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bl 0x82871330
	ctx.lr = 0x8288BBD0;
	sub_82871330(ctx, base);
loc_8288BBD0:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r25,r25,30,26,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 30) & 0x3F;
	// lwz r4,632(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 632);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r6,4(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// clrlwi r27,r25,30
	ctx.r27.u64 = ctx.r25.u32 & 0x3;
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r5,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// dcbzl r0,r30
	ea = (ctx.r30.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x8288bc2c
	if (ctx.cr6.lt) goto loc_8288BC2C;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826d4738
	ctx.lr = 0x8288BC24;
	sub_826D4738(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x8288bc84
	goto loc_8288BC84;
loc_8288BC2C:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x8288bc80
	if (!ctx.cr6.gt) goto loc_8288BC80;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8288BC38:
	// lhz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r5,26
	ctx.r8.u64 = ctx.r5.u32 & 0x3F;
	// rlwinm r3,r5,24,8,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r3,r7
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// lbzx r3,r10,r4
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r23,r3,r26
	ctx.r23.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r26.u32);
	// rlwinm r5,r5,25,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r5,r5
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// rotlwi r3,r3,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// xor r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// or r9,r23,r9
	ctx.r9.u64 = ctx.r23.u64 | ctx.r9.u64;
	// subf r5,r5,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r5.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r5,r3,r30
	REX_STORE_U16(ctx.r3.u32 + ctx.r30.u32, ctx.r5.u16);
	// bdnz 0x8288bc38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8288BC38;
loc_8288BC80:
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_8288BC84:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8288bcf0
	if (!ctx.cr6.eq) goto loc_8288BCF0;
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// clrlwi r10,r27,31
	ctx.r10.u64 = ctx.r27.u32 & 0x1;
	// rlwinm r9,r27,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
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
	// add r11,r9,r24
	ctx.r11.u64 = ctx.r9.u64 + ctx.r24.u64;
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
	// b 0x8288bd0c
	goto loc_8288BD0C;
loc_8288BCF0:
	// rlwinm r10,r27,2,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// clrlwi r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bl 0x82871330
	ctx.lr = 0x8288BD0C;
	sub_82871330(ctx, base);
loc_8288BD0C:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r9,r25,30,26,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 30) & 0x3F;
	// lwz r4,632(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 632);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r6,4(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// clrlwi r27,r9,30
	ctx.r27.u64 = ctx.r9.u32 & 0x3;
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r5,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// dcbzl r0,r30
	ea = (ctx.r30.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x8288bd68
	if (ctx.cr6.lt) goto loc_8288BD68;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826d4738
	ctx.lr = 0x8288BD60;
	sub_826D4738(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x8288bdc0
	goto loc_8288BDC0;
loc_8288BD68:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x8288bdbc
	if (!ctx.cr6.gt) goto loc_8288BDBC;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8288BD74:
	// lhz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r5,26
	ctx.r8.u64 = ctx.r5.u32 & 0x3F;
	// rlwinm r3,r5,24,8,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r3,r7
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// lbzx r3,r10,r4
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r29,r3,r26
	ctx.r29.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r26.u32);
	// rlwinm r5,r5,25,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r5,r5
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// rotlwi r3,r3,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// xor r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// or r9,r29,r9
	ctx.r9.u64 = ctx.r29.u64 | ctx.r9.u64;
	// subf r5,r5,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r5.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r5,r3,r30
	REX_STORE_U16(ctx.r3.u32 + ctx.r30.u32, ctx.r5.u16);
	// bdnz 0x8288bd74
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8288BD74;
loc_8288BDBC:
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_8288BDC0:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrlwi r10,r27,31
	ctx.r10.u64 = ctx.r27.u32 & 0x1;
	// bne cr6,0x8288be30
	if (!ctx.cr6.eq) goto loc_8288BE30;
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// rlwinm r9,r27,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r10,r24
	ctx.r11.u64 = ctx.r10.u64 + ctx.r24.u64;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// srawi r10,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 3;
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r5,r6,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// or r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 | ctx.r6.u64;
	// rldicr r3,r4,32,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFF00000000;
	// or r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 | ctx.r4.u64;
	// std r10,48(r11)
	REX_STORE_U64(ctx.r11.u32 + 48, ctx.r10.u64);
	// std r10,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r10.u64);
	// std r10,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r10.u64);
	// std r10,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
loc_8288BE30:
	// rlwinm r11,r27,2,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bl 0x82871330
	ctx.lr = 0x8288BE48;
	sub_82871330(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

