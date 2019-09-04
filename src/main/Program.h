//
// Created by Khyber on 8/14/2019.
//

#pragma once

#include "src/main/SpriteScripts.h"

namespace scratch {
    
    class Program final {
    
    private:
        
        static constexpr auto defaultNumSpriteScripts = 0;
        llvm::SmallVector<const SpriteScripts*, defaultNumSpriteScripts> _spriteScripts;
        
        Scope globals;
    
    public:
        
        auto spriteScripts() const noexcept {
            return llvm::make_pointee_range(_spriteScripts);
        }
        
    };
    
}
