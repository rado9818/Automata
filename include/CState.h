#ifndef CSTATE_H
#define CSTATE_H
#include <iostream>
#include "AutomatonException.h"
class CState
{
    public:
        CState(unsigned);
        CState(unsigned, char*);
        virtual ~CState();
        CState(const CState& other);
        CState& operator=(const CState& other);
        unsigned getId() const;
        int setId(unsigned);
        char* getName() const;
        bool getIsInitial() const;
        int setIsInitial(bool, CState**, unsigned, unsigned) throw (AutomatonException);
        bool getIsFinal() const;
        int setIsFinal(bool);
        friend std::istream& operator >>(std::istream&, CState&);
        virtual std::istream& inserter(std::istream&);
        friend std::ostream& operator <<(std::ostream&, CState&);
        virtual std::ostream& extractor(std::ostream&);
    protected:
    private:
        unsigned id;
        char *name;
        bool isInitial;
        bool isFinal;
};

#endif // CSTATE_H
