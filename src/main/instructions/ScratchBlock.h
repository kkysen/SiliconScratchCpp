//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/InstructionImpl.h"

#include "src/share/stde/addStrings.h"

#include "llvm/ADT/Twine.h"

namespace scratch {
    
    template <ComputeKind _computeKind, size_t _numArgs, bool _hasBody>
    class ScratchBlock : public InstructionImpl<_computeKind, _numArgs, _hasBody> {
    
    private:
        
        using Super = InstructionImpl<_computeKind, _numArgs, _hasBody>;
        
        const std::string_view blockTypeName;
        const std::string_view blockName;
        
        std::string opCode() const {
            using namespace std::literals;
            using stde::string::operator+;
            return blockTypeName + "_"s + blockName;
        }
    
    protected:
        
//        template <class ...Args>
//        ScratchBlock(std::string_view blockTypeName, std::string_view blockName, Args&& ...args) noexcept
//                : Super(std::forward<Args>(args)...),
//                  blockTypeName(blockTypeName), blockName(blockName) {}

        ScratchBlock(std::string_view blockTypeName, std::string_view blockName, typename Super::ArgsImpl args)
                : Super(args),
                  blockTypeName(blockTypeName), blockName(blockName) {}
        
    };
    
}
