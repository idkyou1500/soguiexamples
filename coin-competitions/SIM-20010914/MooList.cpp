/**************************************************************************\
 *
 *  This file is part of a set of demo programs for the Coin library.
 *  Copyright (C) 2000-2001 by Systems in Motion. All rights reserved.
 *
 *  This sourcecode can be redistributed and/or modified under the
 *  terms of the GNU General Public License version 2 as published by
 *  the Free Software Foundation. See the file COPYING at the root
 *  directory of the distribution for more details.
 *
 *  As a special exception, all sourcecode of the demo examples can be
 *  used for any purpose for licensees of the Coin Professional
 *  Edition License, without the restrictions of the GNU GPL. See our
 *  web pages for information about how to acquire a Professional Edition
 *  License.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  http://www.sim.no support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
\**************************************************************************/
// File: MooList.cpp

#ifndef MOO_LIST_CPP
#define MOO_LIST_CPP

#include "MooList.h"

template <class generic> MooList<generic>::MooList( void )
{
	
  this->first = new MooListItem<generic>;
  this->first->next = this->first;
  this->first->prev = this->first;

  this->current = this->first;
  this->count = 0;
  this->currentIndex = -1;
}

template <class generic> MooList<generic>::~MooList( void )
{
  this->empty( );
  delete this->first;
}

template <class generic> inline bool MooList<generic>::start( void )
{
  this->current = this->first->next;

  this->currentIndex = ( this->count > 0 ) ? 0 : -1;

  return ( this->current != this->first );
}

template <class generic> inline bool MooList<generic>::end( void )
{
	
  this->current = this->first->prev;
  this->currentIndex = this->count - 1;
  return ( this->current != this->first );

}

template <class generic> bool MooList<generic>::remove( void )
{
  if ( this->current == this->first )
    return false;

  MooListItem<generic> * del = this->current;

  del->next->prev = del->prev;
  del->prev->next = del->next;
  this->current = del->prev;

  delete del;

  this->count--;
  this->currentIndex--;

  return true;

}

template <class generic> bool MooList<generic>::remove( generic item )
{
	
  if ( this->search( item ) )
    return this->remove( );

  return false;

}

template <class generic> bool MooList<generic>::insert( generic item )
{
	
  MooListItem<generic> * ins = 0L;
  ins = new MooListItem<generic>;

  if ( ins ) {
	
    ins->item = item;

    ins->prev = this->current;
    ins->next = this->current->next;
    ins->next->prev = ins;
    ins->prev->next = ins;
    
    this->count++;
    this->current = ins;
    this->currentIndex++;

    return true;

  }

  return false;

}

template<class generic> bool MooList<generic>::append( generic item )
{

  this->end( );
  return this->insert( item );

}

template<class generic> inline bool MooList<generic>::next( void )
{
	
  if ( this->current->next == this->first )
    return false;

  this->current = this->current->next;
  this->currentIndex++;

  return true;

}

template<class generic> inline bool MooList<generic>::prev( void )
{
	
  if ( this->current->prev == this->first )
    return false;

  this->current = this->current->prev;
  this->currentIndex--;

  return true;

}

template<class generic> bool MooList<generic>::search( generic item )
{

  this->start( );

  do {

    if ( this->current->item == item )
      return true;
   
  } while( this->next( ) );
  
  return false;

}

template<class generic> bool MooList<generic>::search( find * function, void * data )
{
	
  this->start( );

  if ( this->current == this->first )
    return false;

  do {

    if ( function( this->current->item, data ) )
      return true;

  } while ( this->next( ) );

  return false;

}

template<class generic> void MooList<generic>::empty( void )
{
  this->end( );
  while ( this->remove( ) );
}

template<class generic> inline unsigned int MooList<generic>::length( void )
{
  return this->count;
}

template<class generic> inline generic MooList<generic>::get( void )
{
  return this->current->item;
}

template<class generic> generic MooList<generic>::get( unsigned int index )
{

  if ( this->currentIndex > index ) {

    while( ( this->currentIndex > index ) && this->prev( ) );

  } else if ( this->currentIndex < index ) {

    while( ( this->currentIndex < index ) && this->next( ) );

  }

  return this->current->item;

}

template<class generic> unsigned int MooList<generic>::index( void )
{
  return this->currentIndex;
}

#endif // !MOO_LIST_CPP