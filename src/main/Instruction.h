//
// Created by Khyber on 8/3/2019.
//

#pragma once

#include "src/main/ComputeKind.h"
#include "src/main/Value.h"
#include "src/main/Block.h"

#include "src/share/common/numbers.h"

#include "src/share/lib/corrade/CorradeArrayView.h"

#include <optional>

namespace scratch {
    
    using namespace Corrade::Containers;
    
    class Instruction : public Value {

    protected:
    
        using ConstArgs = ArrayView<const Value*>;
        using Args = ArrayView<Value*>;
    
    private:
        
        ComputeKind ownComputeKind;
        Args _args;
        std::optional<Block> _body;

    private:
        
        constexpr ConstArgs __args() const noexcept {
            return ConstArgs(const_cast<const Value**>(_args.data()), _args.size());
        }
    
        constexpr Args __args() noexcept {
            return _args;
        }
        
    public:
        
        auto args() const noexcept {
            return llvm::make_pointee_range(__args());
        }
    
        auto args() noexcept {
            return llvm::make_pointee_range(__args());
        }
        
        constexpr bool hasBody() const noexcept {
            return _body.has_value();
        }
        
        constexpr const Block& body() const noexcept {
            return _body.value();
        }
        
        Lazy<ComputeKind> computeKind = {};
    
    protected:
        
        Instruction(ComputeKind computeKind, Args _args, std::optional<Block>&& body)
                : Value(ValueKind::instruction), ownComputeKind(computeKind), _args(_args), _body(body) {
            for (Value& arg : args()) {
                arg.addRead(*this);
            }
        }

    private:
        
        ComputeKind doComputeKind() const noexcept {
            // note important that ComputeKinds are ordered, lower can cast to higher
            auto max = ownComputeKind;
            for (const auto& arg : args()) {
                if (arg.kind.isInstruction()) {
                    const auto subComputeKind = arg.as<Instruction>().doComputeKind();
                    if (subComputeKind > max) {
                        max = subComputeKind;
                    }
                }
            }
            return max;
        }
        
    };
    
}
