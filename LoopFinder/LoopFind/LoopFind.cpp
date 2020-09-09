#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/LoopAccessAnalysis.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Transforms/Utils/LoopUtils.h"
#include "llvm/ADT/SetVector.h"
#include "llvm/IR/DebugLoc.h"

using namespace llvm;
struct LoopFind : public FunctionPass {
  static char ID;
  LoopFind() : FunctionPass(ID) {
//     initializeLoopFindPass(*PassRegistry::getPassRegistry());
  }

  bool runOnFunction(Function &F) override {
    errs() << "Function: ";
    errs().write_escaped(F.getName()) << '\n';
    if (F.hasFnAttribute(Attribute::OptimizeNone)) {
        errs() << " Opt none attribute found, skipping!!!!\n";
        return false;
    }

		LoopInfo &LI = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    for (LoopInfo::iterator LIT = LI.begin(), LEND = LI.end(); LIT != LEND; ++LIT) {
			Loop *L = *LIT;
      L->getStartLoc().print(errs());
		//	errs() << "Is empty: " << L->empty() << " backedges " << L->getNumBackEdges() << " exiting block " << L->getExitingBlock() <<  " Latch " << L->getLoopLatch() << "\n";
			if(L->empty()) {
          analyzeInnerLoops(L);
			} else {  
          errs() << " Non empty loop \n";
      }
			

    //  L->dump();
    }
    return false;
  }

  void analyzeInnerLoops(Loop *L) {
     typedef SmallPtrSet<Value*, 16> ValueSet;
     SmallVector<LoadInst *, 16> Loads;
     SmallVector<StoreInst *, 16> Stores;
     bool hasCall =false;
 
     // For each block.
     for (BasicBlock *BB : L->blocks()) {
       // Scan the BB and collect legal loads and stores.
       for (Instruction &I : *BB) {
				 auto *Ld = dyn_cast<LoadInst>(&I);
				 if(Ld) {
//             Ld->dump();
             Loads.push_back(Ld);
         }
         auto *St = dyn_cast<StoreInst>(&I);
         if(St) {
             Stores.push_back(St);
         }
         if(auto* Ci = dyn_cast<CallInst>(&I)) {
            FunctionType *ft =  Ci->getFunctionType();
//            ft->dump();
            for(auto &t : ft->params()) {
                if(t->isPointerTy() || ft->getReturnType()->isPointerTy()) {
                   errs() << " loop with a pointer call\n";
                   return;
                }
            }
            hasCall = true;
          //   errs() << " loop with a call\n";
         //    return;
         }
       }
     }

     if(hasCall)
         errs() << " call ";

     if(Stores.size() > 0) {
         errs() << " A write loop!\n";
         return;
     }

     ValueSet SeenLoadPtrs;
     for (LoadInst *LD : Loads) {
       Value *Ptr = LD->getPointerOperand();
       SeenLoadPtrs.insert(Ptr);
     }

     if(SeenLoadPtrs.size() == 1 ) {
         for(Value *v :SeenLoadPtrs) {
             if(dyn_cast<PointerType>(v->getType())->getElementType()->isIntegerTy(8)) {
                 errs() << " BINGO! ";
             }
             for(auto &u : v->uses()) {
                 if(isa<BitCastInst>(&u)) {
                     errs() << " bitcast ";
                 }
             }
         }
     }

     errs() << " loop reads from " << SeenLoadPtrs.size() << " pointers\n";
  }


	void getAnalysisUsage(AnalysisUsage &AU) const override {
     AU.addRequired<LoopInfoWrapperPass>();
     AU.addPreserved<LoopInfoWrapperPass>();
   }


}; // end of struct Hello
char LoopFind::ID = 0;
//#define LVER_OPTION "loop-find"
//static const char LVer_name[] = "Loop Find";
//INITIALIZE_PASS_BEGIN(LoopFind, LVER_OPTION, LVer_name, false, false)
//INITIALIZE_PASS_DEPENDENCY(LoopInfoWrapperPass)
//INITIALIZE_PASS_DEPENDENCY(LoopAccessLegacyAnalysis)
//INITIALIZE_PASS_END(LoopFind, LVER_OPTION, LVer_name, false, false)

static RegisterPass<LoopFind> X("hello", "Hello World Pass",
                             false /* Only looks at CFG */,
                             true /* Analysis Pass */);

