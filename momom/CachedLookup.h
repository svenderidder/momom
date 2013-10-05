//
//  CachedLookup.h
//  momom
//
//  Created by Sven de Ridder on 10/5/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_CachedLookup_h
#define momom_CachedLookup_h

#include <functional>

namespace momom {
    
    class SavegameData;
    
    template<typename K, typename V>
    class CachedLookup {
    public:
        typedef K key_type;
        typedef V value_type;
        typedef std::function<V*(SavegameData*, K)> factory_type;
        
        CachedLookup(SavegameData* data, factory_type factory)
        : data{data}, factory{factory} {}
        
        V& get(K key) {
            // Avoid code duplication by casting away the constness of the result of the const
            // method. Not pretty, but safe.
            return const_cast<V&>(static_cast<const CachedLookup<K, V>*>(this)->get(key));
        }
        
        const V& get(K key) const {
            auto it = cache.find(key);
            if(it == cache.end()) {
                std::shared_ptr<V> p(factory(data, key));
                auto r = cache.insert(std::make_pair(key, p));
                assert(r.second); // equivalent key should not already exist.
                it = r.first;
            }
            return *it->second;
        }
        
    private:
        mutable std::map<K, std::shared_ptr<V>> cache;
        SavegameData* const data;
        factory_type factory;
    };
}

#endif
