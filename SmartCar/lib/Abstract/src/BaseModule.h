#pragma once
#ifndef __BASEMODULE_H__
#define __BASEMODULE_H__

namespace Modules
{
    class BaseModule
    {
    public:
        BaseModule() { return; };
        virtual ~BaseModule() { return; };
        virtual bool init() { return false; };
        virtual void test() { return; };
    };
} // namespace Modules
#endif