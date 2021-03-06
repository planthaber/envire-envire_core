/*
 * GraphEventPublisher.hpp
 *
 *  Created on: Sep 16, 2015
 *      Author: aboeckmann
 */

#pragma once
#include <vector>
#include <envire_core/events/GraphEvent.hpp>

namespace envire { namespace core
{
    class GraphEvent;
    class GraphEventSubscriber;

    /**
     * Base class for frame-event publishers.
     * Handles the subscription and notification of subscribers.
     */
    class GraphEventPublisher
    {
    private:
      std::vector<GraphEventSubscriber*> subscribers;

    public:
        /**Subscribes the @param handler to all events by this event source */
        void subscribe(GraphEventSubscriber* pSubscriber, bool publish_current_state = false);
        void unsubscribe(GraphEventSubscriber* pSubscriber, bool unpublish_current_state = false);

    protected:
        /**Notify all subscribers about a certain graph event */
        void notify(const GraphEvent& e);

        /**Notify the given subscriber about a certain graph event */
        void notifySubscriber(GraphEventSubscriber* pSubscriber, const GraphEvent& e);

        /**
         * @brief Publishes the current state of the graph.
         */
        virtual void publishCurrentState(GraphEventSubscriber* pSubscriber) = 0;

        /**
         * @brief Unpublishes the current state of the graph.
         *        Basically the reverse process of publishCurrentState
         */
        virtual void unpublishCurrentState(GraphEventSubscriber* pSubscriber) = 0;

        //there is no use in creating an instance of the publisher
        //on its own.
        GraphEventPublisher() {}
        virtual ~GraphEventPublisher() {}

    };
}}

