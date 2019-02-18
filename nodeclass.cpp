//
//  nodeclass.cpp
//  irvine class 
//
//  Created by Eugene Sumaryev on 2/13/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#include <stdio.h>
#include <cassert>    // For using asert
#include <cstdlib>    // Provides NULL and size_t
#include "nodeclass.h"

namespace class_program
{
    //method to get list length
    size_t list_length(const nodeclass* head_ptr)
    // Library facilities used: cstdlib
    {
        const nodeclass *cursor;
        size_t answer;
        
        answer = 0;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            ++answer;
        
        return answer;
    }
    
    //method to insert node at the head of the list
    void list_head_insert(nodeclass*& head_ptr, const nodeclass::value_type& entry)
    {
        head_ptr = new nodeclass(entry, head_ptr);
    }
    
    //method to insert a node
    void list_insert(nodeclass* previous_ptr, const nodeclass::value_type& entry)
    {
        nodeclass *insert_ptr;
        
        insert_ptr = new nodeclass(entry, previous_ptr->link( ));
        previous_ptr->set_link(insert_ptr);
    }
    
    //method to search a node
    nodeclass* list_search(nodeclass* head_ptr, const nodeclass::value_type& target)
    {
        nodeclass *cursor;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            if (target == cursor->data( ))
                return cursor;
        return NULL;
    }
    
    //another method to search a node but keeping head pointer a constant
    const nodeclass* list_search(const nodeclass* head_ptr, const nodeclass::value_type& target)
    // Library facilities used: cstdlib
    {
        const nodeclass *cursor;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            if (target == cursor->data( ))
                return cursor;
        return NULL;
    }
    
    //method to locate a node at a particular position
    nodeclass* list_locate(nodeclass* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
        nodeclass *cursor;
        size_t i;
        
        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != NULL); i++)
            cursor = cursor->link( );
        return cursor;
    }
    
    //another method to locate pointer but using a constant declaration
    const nodeclass* list_locate(const nodeclass* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
        const nodeclass *cursor;
        size_t i;
        
        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != NULL); i++)
            cursor = cursor->link( );
        return cursor;
    }
    
    //method to remove head pointer
    void list_head_remove(nodeclass*& head_ptr)
    {
        nodeclass *remove_ptr;
        
        remove_ptr = head_ptr;
        head_ptr = head_ptr->link( );
        delete remove_ptr;
    }
    
    //method to remove pointer after prev pointer
    void list_remove(nodeclass* previous_ptr)
    {
        nodeclass *remove_ptr;
        
        remove_ptr = previous_ptr->link( );
        previous_ptr->set_link( remove_ptr->link( ) );
        delete remove_ptr;
    }
    
    //method to clear entire list
    void list_clear(nodeclass*& head_ptr)
    // Library facilities used: cstdlib
    {
        while (head_ptr != NULL)
            list_head_remove(head_ptr);
    }
    
    //method to copy a list 
    void list_copy(const nodeclass* source_ptr, nodeclass*& head_ptr, nodeclass*& tail_ptr)
    // Library facilities used: cstdlib
    {
        head_ptr = NULL;
        tail_ptr = NULL;
        
        // Handle the case of the empty list.
        if (source_ptr == NULL)
            return;
        
        // Make the head node for the newly created list, and put data in it.
        list_head_insert(head_ptr, source_ptr->data( ));
        tail_ptr = head_ptr;
        
        // Copy the rest of the nodes one at a time, adding at the tail of new list.
        source_ptr = source_ptr->link( ); 
        while (source_ptr != NULL)
        {
            list_insert(tail_ptr, source_ptr->data( ));
            tail_ptr = tail_ptr->link( );
            source_ptr = source_ptr->link( );
        }
    }
    
}
