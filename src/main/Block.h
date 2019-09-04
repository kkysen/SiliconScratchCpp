//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "llvm/ADT/iterator.h"
#include "llvm/ADT/SmallVector.h"

namespace scratch {
    
    class Instruction;
    
    class Block final {

    private:
        
        static constexpr auto defaultNumInstructions = 0;
        llvm::SmallVector<const Instruction*, defaultNumInstructions> _instructions;

    public:
        
        auto instructions() const noexcept {
            return llvm::make_pointee_range(_instructions);
        }
        
    };
    
}
