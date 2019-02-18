//
//  LLstack.cpp
//  irvine class
//
//  Created by Eugene Sumaryev on 2/13/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#include <stdio.h>
#include <cassert>  // Provides assert
#include "nodeclass.h"  // Node template class
#include "LLstack.h" //header class

namespace class_program_stack
{
 
    //constructor
    LLstack::LLstack(const LLstack& source)
    {
        class_program::nodeclass *tail_ptr; // Needed for argument of list_copy
        
        list_copy(source.top_ptr, top_ptr, tail_ptr);
    }
    
    //method for push operation
    void LLstack::push(const value_type& entry)
    {
        list_head_insert(top_ptr, entry);
    }

    //method for pop operation
    double LLstack::pop( )
    {
        assert(!empty( ));
        
        double item = top_ptr->data( );
        list_head_remove(top_ptr);
        return item;
    }

    //override of = operator to compare the list
    void LLstack::operator =(const LLstack& source)
    {
        class_program::nodeclass *tail_ptr; // Needed for argument of list_copy
        
        if (this == &source) // Handle self-assignment
            return;
        
        list_clear(top_ptr);
        list_copy(source.top_ptr, top_ptr, tail_ptr);
    }
}

