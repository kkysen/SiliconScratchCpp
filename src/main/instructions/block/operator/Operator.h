//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/instructions/ScratchBlock.h"

namespace scratch::block {
    
    template <size_t _numArgs>
    class Operator : public ScratchBlock<ComputeKind::computational, _numArgs, false> {
    
    private:
        
        using Super = ScratchBlock<ComputeKind::computational, _numArgs, false>;
    
    protected:
        
        Operator(std::string_view name, typename Super::ArgsImpl args)
                : Super("operator", name, args) {}
        
    };
    
}
