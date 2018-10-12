/******************************************************************************
 * Copyright (c) 2018 McAfee, LLC - All Rights Reserved.
 *****************************************************************************/

#include "include/SimpleLog.h"
#include "brokerregistry/include/brokerregistry.h"
#include "message/handler/include/DumpBrokerStateEventHandler.h"
#include <sstream>

using namespace std;
using namespace dxl::broker;
using namespace dxl::broker::message::handler;

/** {@inheritDoc} */
bool DumpBrokerStateEventHandler::onPublishMessage(
    const char* /*sourceId*/, const char* /*canonicalSourceId*/, bool /*isBridge*/, 
    uint8_t /*contextFlags*/, const char* /*topic*/, struct cert_hashes* /*certHashes*/ ) const
{
    if( SL_LOG.isInfoEnabled() )
    {
        stringstream dumpstr;
        dumpstr << BrokerRegistry::getInstance();        
        SL_START << "\nBroker state:\n" << dumpstr.str() << SL_INFO_END;
    }

    // propagate event
    return true;
}
