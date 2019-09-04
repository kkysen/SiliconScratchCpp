//
// Created by Khyber on 8/3/2019.
//

#pragma once

#include "src/main/Instruction.h"
#include "src/main/Block.h"

namespace scratch {
    
    template <ComputeKind _computeKind, size_t _numArgs>
    class InstructionWithArgs : public Instruction {
    
    protected:
        
        using ArgsImpl = std::array<Value*, _numArgs>;
    
    private:
        
        ArgsImpl argsImpl;
    
    protected:
        
        InstructionWithArgs(ArgsImpl args, std::optional<Block>&& body)
                : Instruction(_computeKind, staticArrayView(args), std::move(body)), argsImpl(args) {}
        
    };
    
    template <ComputeKind _computeKind, size_t _numArgs, bool _hasBody>
    class InstructionImpl;
    
    template <ComputeKind _computeKind, size_t _numArgs>
    class InstructionImpl<_computeKind, _numArgs, true> : public InstructionWithArgs<_computeKind, _numArgs> {
    
    protected:
        
        using Super = InstructionWithArgs<_computeKind, _numArgs>;
        using ArgsImpl = typename Super::ArgsImpl;
        
        InstructionImpl(ArgsImpl args, Block&& body)
                : Super(args, std::make_optional(body)) {}
        
    };
    
    template <ComputeKind _computeKind, size_t _numArgs>
    class InstructionImpl<_computeKind, _numArgs, false> : public InstructionWithArgs<_computeKind, _numArgs> {
    
    protected:
    
        using Super = InstructionWithArgs<_computeKind, _numArgs>;
        using ArgsImpl = typename Super::ArgsImpl;
        
        explicit InstructionImpl(ArgsImpl args)
                : Super(args, std::nullopt) {}
        
    };
    
}
