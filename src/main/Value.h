//
// Created by Khyber on 8/3/2019.
//

#pragma once

#include "src/main/ValueKind.h"
#include "src/main/Lazy.h"
#include "src/main/type/TypeBase.h"

#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/STLExtras.h"

namespace scratch {
    
    class Instruction;
    
    class Value {

    public:
        
        const ValueKind kind;
        Lazy<TypeBase> type;

    private:
        
        static constexpr auto defaultNumReads = 1;
        llvm::SmallVector<const Instruction*, defaultNumReads> _reads;

    public:
        
        auto reads() const noexcept {
            return llvm::make_pointee_range(_reads);
        }
    
        void addRead(const Instruction& instruction) {
            _reads.emplace_back(instruction);
        }
        
    protected:
        
        explicit Value(ValueKind kind) : kind(kind) {}

    public:
        
        template <typename T>
        const T& as() const noexcept {
            return reinterpret_cast<const T&>(*this);
        }
        
    };
    
}
