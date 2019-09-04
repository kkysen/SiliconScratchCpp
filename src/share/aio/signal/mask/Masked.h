//
// Created by Khyber on 5/30/2019.
//

#pragma once

#include "src/share/aio/signal/mask/Mask.h"
#include "src/share/aio/signal/mask/How.h"

namespace aio::signal::mask {
    
    class Masked {
    
    private:
        
        const Mask& mask;
        const Mask old;
        const Apply apply;
    
    public:
        
        // Apply::process only block signals in the current thread,
        // but Apply::thread doesn't block NPTL threading signals;
        // Apply::process block everything, so only
        // an unstoppable (SIGKILL, SIGSTOP) or unrecoverable (SIGSEGV, etc.)
        // signal can stop the current thread
        explicit Masked(const Mask& mask, How how, Apply apply = Apply::process) noexcept;
        
        ~Masked();
        
    };
    
}
