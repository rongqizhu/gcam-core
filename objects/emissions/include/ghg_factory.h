#ifndef _GHG_FACTORY_H_
#define _GHG_FACTORY_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*
 * This software, which is provided in confidence, was prepared by employees of
 * Pacific Northwest National Labratory operated by Battelle Memorial Institute.
 * Battelle has certain unperfected rights in the software which should not be
 * copied or otherwise disseminated outside your organization without the express
 * written authorization from Battelle. All rights to the software are reserved
 * by Battelle. Battelle makes no warranty, express or implied, and assumes no
 * liability or responsibility for the use of this software.
 */

/*!
 * \file ghg_factory.h
 * \ingroup Objects
 * \brief GHGFactory header file.
 * \author Jim Naslund
 */

class AGHG;

/*! 
 * \ingroup Objects
 * \brief A factory which is used to create the various types of GHG objects.
 * \details The factory encapsulates the creation of various types of GHGs.
 *          This simplifies adding new types and also minimizes recompilation.
 * \author Jim Naslund
 */
class GHGFactory{

public:
    static std::auto_ptr<AGHG> create( const std::string& aType );
    static const bool isGHGNode( const std::string& aType );

};


#endif // _GHG_FACTORY_H_

