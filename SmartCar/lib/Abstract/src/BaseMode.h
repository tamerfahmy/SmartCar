#pragma once
#ifndef __BASEMODE_H__
#define __BASEMODE_H__

namespace Mode
{
    class BaseMode
    {
    public:
        BaseMode() { return; };
        virtual ~BaseMode() { return; };
        virtual void run() { return; };
        virtual void stop() { return; };
        virtual void irDataRecieved(uint32_t data) { return; };
    };
} // namespace Mode
#endif