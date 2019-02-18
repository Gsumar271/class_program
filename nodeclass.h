//
//  nodeclass.h
//  irvine class 
//
//  Created by Eugene Sumaryev on 2/13/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef nodeclass_h
#define nodeclass_h

#include <cstdlib>   // Provides NULL and size_t

namespace class_program
{
    class nodeclass
    {
    public:
        // TYPEDEF, used here to make list of doubles
        typedef double value_type;
        
        // CONSTRUCTOR
        nodeclass(
             const value_type& init_data = value_type( ),
             nodeclass* init_link = NULL
             )
        { data_field = init_data; link_field = init_link; }
        
        // Member functions to set the data and link fields:
        void set_data(const value_type& new_data) { data_field = new_data; }
        void set_link(nodeclass* new_link) { link_field = new_link; }
        
        // Constant member function to retrieve the current data:
        value_type data( ) const { return data_field; }
        
        // Two slightly different member functions to retreive
        // the current link, one constant one isn't
        const nodeclass* link( ) const { return link_field; }
        nodeclass* link( )             { return link_field; }
        
    private:
        value_type data_field;
        nodeclass* link_field;
    };
    
    // FUNCTIONS for the linked list
    std::size_t list_length(const nodeclass* head_ptr);
    void list_head_insert(nodeclass*& head_ptr, const nodeclass::value_type& entry);
    void list_insert(nodeclass* previous_ptr, const nodeclass::value_type& entry);
    nodeclass* list_search(nodeclass* head_ptr, const nodeclass::value_type& target);
    const nodeclass* list_search
    (const nodeclass* head_ptr, const nodeclass::value_type& target);
    nodeclass* list_locate(nodeclass* head_ptr, std::size_t position);
    const nodeclass* list_locate(const nodeclass* head_ptr, std::size_t position);
    void list_head_remove(nodeclass*& head_ptr);
    void list_remove(nodeclass* previous_ptr);
    void list_clear(nodeclass*& head_ptr);
    void list_copy(const nodeclass* source_ptr, nodeclass*& head_ptr, nodeclass*& tail_ptr);
}

#endif /* nodeclass_h */
