#include <utility>

//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/Value.h"

namespace scratch {
    
    // LValues in Scratch are only Variable and List
    class LValue : public Value {

    private:
    
        const std::string name;
        
        static constexpr auto defaultNumWrites = 0;
        llvm::SmallVector<const Instruction*, defaultNumWrites> _writes;

    public:
        
        auto writes() const noexcept {
            return llvm::make_pointee_range(_writes);
        }
        
    protected:
        
        LValue(ValueKind kind, std::string name) : Value(kind), name(std::move(name)) {}
        
    };
    
}
