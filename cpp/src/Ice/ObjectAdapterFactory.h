// **********************************************************************
//
// Copyright (c) 2002
// MutableRealms, Inc.
// Huntsville, AL, USA
//
// All Rights Reserved
//
// **********************************************************************

#ifndef ICE_OBJECT_ADAPTER_FACTORY_H
#define ICE_OBJECT_ADAPTER_FACTORY_H

#include <Ice/ObjectAdapterI.h>
#include <IceUtil/RecMutex.h>

namespace IceInternal
{

class ObjectAdapterFactory : public ::IceUtil::Shared, public ::IceUtil::RecMutex
{
public:

    void shutdown();
    ::Ice::ObjectAdapterPtr createObjectAdapter(const std::string&, const std::string&);
    ::Ice::ObjectAdapterPtr findObjectAdapter(const ::Ice::ObjectPrx&);

private:

    ObjectAdapterFactory(const InstancePtr&);
    friend class Instance;

    InstancePtr _instance;
    std::map<std::string, ::Ice::ObjectAdapterIPtr> _adapters;
};

}

#endif
