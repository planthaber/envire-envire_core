#pragma once
#include <envire_core/items/ItemBase.hpp>
#include <envire_core/events/GraphEvent.hpp>

namespace envire { namespace core
{
    class ItemRemovedEvent : public GraphEvent
    {
    public:
      ItemRemovedEvent(const FrameId& frame, const ItemBase::Ptr item) :
          GraphEvent(GraphEvent::ITEM_REMOVED_FROM_FRAME), frame(frame), item(item){}

        GraphEvent* clone() const
        {
            return new ItemRemovedEvent(frame, item);
        }

      FrameId frame;/**<frame that the no longer contains the item.*/
      /**The item that has been removed.
       * @note Since the item has already been removed, item->getFrame() will
       *       not return a valid value.*/
      ItemBase::Ptr item; 
    };
    
    //a type safe version of the above event
    template <class T>
    struct TypedItemRemovedEvent 
    {
      TypedItemRemovedEvent(const FrameId& frame, const ItemBase::PtrType<T> item) : frame(frame), item(item) {}

        GraphEvent* clone() const
        {
            return new TypedItemRemovedEvent(frame, item);
        }

      FrameId frame;
      ItemBase::PtrType<T> item;
    };
}}
