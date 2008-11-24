/*
 * LEGAL NOTICE
 * This computer software was prepared by Battelle Memorial Institute,
 * hereinafter the Contractor, under Contract No. DE-AC05-76RL0 1830
 * with the Department of Energy (DOE). NEITHER THE GOVERNMENT NOR THE
 * CONTRACTOR MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY
 * LIABILITY FOR THE USE OF THIS SOFTWARE. This notice including this
 * sentence must appear on any copies of this computer software.
 * 
 * EXPORT CONTROL
 * User agrees that the Software will not be shipped, transferred or
 * exported into any country or used in any manner prohibited by the
 * United States Export Administration Act or any other applicable
 * export laws, restrictions or regulations (collectively the "Export Laws").
 * Export of the Software may require some form of license or other
 * authority from the U.S. Government, and failure to obtain such
 * export control license may result in criminal liability under
 * U.S. laws. In addition, if the Software is identified as export controlled
 * items under the Export Laws, User represents and warrants that User
 * is not a citizen, or otherwise located within, an embargoed nation
 * (including without limitation Iran, Syria, Sudan, Cuba, and North Korea)
 *     and that User is not otherwise prohibited
 * under the Export Laws from receiving the Software.
 * 
 * All rights to use the Software are granted on condition that such
 * rights are forfeited if User fails to comply with the terms of
 * this Agreement.
 * 
 * User agrees to identify, defend and hold harmless BATTELLE,
 * its officers, agents and employees from all liability involving
 * the violation of such Export Laws, either directly or indirectly,
 * by User.
 */

/*! 
* \file emissions_driver_factory.cpp
* \ingroup Objects
* \brief EmissionsDriverFactory source file.
* \author Jim Naslund
*/

#include "util/base/include/definitions.h"

#include <string>

#include "emissions/include/emissions_driver_factory.h"
#include "emissions/include/input_output_driver.h"
#include "emissions/include/input_driver.h"
#include "emissions/include/output_driver.h"

using namespace std;

/*!
 * \brief Return a new instance of a component of the requested type.
 * \return A newly created EmissionsDriver wrapped in an auto_ptr. The pointer
 *         is null if the type is unknown.
 */
auto_ptr<AEmissionsDriver> EmissionsDriverFactory::create( const string& aType ){
    if( aType == InputDriver::getXMLNameStatic() ){
        return auto_ptr<AEmissionsDriver>( new InputDriver );
    }
    if( aType == OutputDriver::getXMLNameStatic() ){
        return auto_ptr<AEmissionsDriver>( new OutputDriver );
    }
    if( aType == InputOutputDriver::getXMLNameStatic() ){
        return auto_ptr<AEmissionsDriver>( new InputOutputDriver );
    }
    return auto_ptr<AEmissionsDriver>();
}

const bool EmissionsDriverFactory::isEmissionsDriverNode( const string& aNodeName ){
    return aNodeName == InputDriver::getXMLNameStatic() 
           || aNodeName == OutputDriver::getXMLNameStatic()
           || aNodeName == InputOutputDriver::getXMLNameStatic();
}
