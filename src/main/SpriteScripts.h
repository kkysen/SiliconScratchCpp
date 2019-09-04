//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/Script.h"
#include "src/main/Sprite.h"
#include "src/main/Scope.h"

namespace scratch {
    
    class SpriteScripts final {

    private:
        
        static constexpr auto defaultNumScripts = 0;
        llvm::SmallVector<const Script*, defaultNumScripts> _scripts;

    public:
        Sprite sprite;

        Scope locals;
        
        auto scripts() const noexcept {
            return llvm::make_pointee_range(_scripts);
        }
        
    };
    
}
