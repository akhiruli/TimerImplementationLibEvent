/*
 * Copyright (C) Verizon, 2013
 *
 * This unpublished material is proprietary to Verizon.  All rights reserved.
 * The methods and techniques described herein are considered trade secrets
 * and/or confidential. Reproduction or distribution, in whole or in part,
 * is forbidden except by express written permission of Verizon.
 */

//! @file   EventImpl.h 
//! @brief  
//! @author Akhirul Islam
//! @date   Jan, 2017
//!
//! 
#ifndef _EVENT_H_
#define _EVENT_H_
#include <event2/event.h>
#include <event2/event_struct.h>
typedef void(* event_callback_fn) (int, short, void *);
class EventImpl {
   public:
      static EventImpl* getInstance();
      virtual ~EventImpl();
      void attachFdtoEv(struct event *, int, event_callback_fn, void *);
      void dispatchEvloop();
      bool initEv();
      void addToEv(struct event *ev);
      void addToEv(struct event *ev, struct timeval *t_intvl);
      struct event* getNewPersistentEvent(event_callback_fn cb, void *cookie);
   private:
      EventImpl();
      EventImpl(const EventImpl& );
   private:
      static EventImpl        *m_pevObj;
      struct event_base       *m_pevbase;
};
#endif
