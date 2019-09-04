//
// Created by Khyber on 8/23/2019.
//

#pragma once

#include "src/share/common/math.h"

#include <memory>

namespace {
    
    template <class T>
    struct MinStorage {
        
        bool isInline;
        std::unique_ptr<T> ptr;
        
        static constexpr size_t minFullSize() {
            // this includes padding
            return sizeof(MinStorage);
        }
        
        static constexpr size_t usedStorageSize() {
            return sizeof(isInline);
        }
        
        static constexpr size_t unusedStorageSize() {
            return minFullSize() - usedStorageSize();
        }
        
    };
    
}

namespace stde {
    
    template <typename T, size_t minSizeInBytes = MinStorage<T>::minFullSize()>
    class SmallPtr {
    
    private:
        
        using MinStorage = MinStorage<T>;
        
        struct size {
            static constexpr size_t full = math::max(minSizeInBytes, MinStorage::minFullSize());
            static constexpr size_t storage = full - MinStorage::usedStorageSize();
        };
        
        bool isInline;
        
        union {
            
            std::unique_ptr<T> ptr;
            
            struct {
                
                std::array<u8, size::storage> storage;
                
                const T& cast() const noexcept {
                    return reinterpret_cast<T&>(*this);
                }
                
            } obj;
            
        };
        
        static constexpr bool isSmall = sizeof(T) <= size::storage;
    
    public:
        
        #define _args std::forward<Args>(args)...
        
        template <class... Args>
        explicit SmallPtr(Args&& ...args) : isInline(isSmall) {
            if constexpr (isSmall) {
                new(&obj) T(_args);
            } else {
                ptr = std::make_unique<T>(_args);
            }
        }
        
        template <typename U = T>
        /*implicit*/ constexpr SmallPtr(SmallPtr&& other) noexcept : isInline(other.isInline) {
            if (isInline) {
                obj = other.obj;
                other.isInline = false;
                new(&other.ptr) std::unique_ptr<T>(nullptr);
            } else {
                ptr = std::move(other.ptr);
            }
        }
        
        template <typename U = T>
        /*implicit*/ constexpr SmallPtr(SmallPtr<U, minSizeInBytes>&& other) noexcept : isInline(other.isInline) {
            if (isInline) {
                obj = other.obj;
                other.isInline = false;
                other.ptr.release();
            } else {
                ptr = std::move(other.ptr);
            }
        }
        
        /*implicit*/ constexpr SmallPtr(T* newedPointer = nullptr) noexcept : isInline(false), ptr(newedPointer) {}
        
        /*implicit*/ constexpr SmallPtr(std::nullptr_t) noexcept : isInline(false), ptr(nullptr) {}
        
        SmallPtr(const SmallPtr&) = delete;
        
        ~SmallPtr() {
            if (isInline) {
                obj.template as<T>().~T();
            } else {
                ptr.~SmartPointer();
            }
        }
        
        // TODO operator=
        
        const T& ref() const noexcept {
            if (isInline) {
                return obj.template as<T>();
            } else {
                return *ptr;
            }
        }
        
        T& ref() noexcept {
            return const_cast<T&>(ref());
        }
        
        const T* get() const noexcept {
            return &ref();
        }
        
        T* get() noexcept {
            return &ref();
        }
        
        const T& operator*() const noexcept {
            return ref();
        }
        
        T& operator*() noexcept {
            return ref();
        }
        
        const T* operator->() const noexcept {
            return get();
        }
        
        T* operator->() noexcept {
            return get();
        }
        
    };
    
    template <typename T, class... Args>
    SmallPtr<T> makeSmallPtr(Args&& ...args) noexcept {
        return SmallPtr<T>(_args);
    }
    
    #undef _args
    
}
