#pragma once
#ifndef __BASE_CONSOLE_H__
#define __BASE_CONSOLE_H__

class BaseConsole
{
public:
    BaseConsole() { return; };
    virtual ~BaseConsole() { return; };
    virtual void writeMessage(char *msg) { return; };
};
#endif