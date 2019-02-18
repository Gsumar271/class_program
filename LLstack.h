//
//  LLstack.h
//  irvine class 
//
//  Created by Eugene Sumaryev on 2/13/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef LLstack_h
#define LLstack_h

#include <cstdlib>   // Provides NULL and size_t
#include "nodeclass.h"   // Node class 

namespace class_program_stack
{
    class LLstack
    {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;
        typedef double value_type;
        // CONSTRUCTORS and DESTRUCTOR
        LLstack( ) { top_ptr = NULL; }
        LLstack(const LLstack& source);
        ~LLstack( ) { list_clear(top_ptr); }
        // MODIFICATION MEMBER FUNCTIONS
        void push(const value_type& entry);
        double pop( );
        void operator =(const LLstack& source);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const
        { return list_length(top_ptr); }
        bool empty( ) const { return (top_ptr == NULL); }
       // double top( ) const;
    private:
        class_program::nodeclass *top_ptr;  // Points to top of stack
    };
}

#endif /* LLstack_h */
