#ifndef CSTATE_H
#define CSTATE_H
#include <iostream>

class CState
{
    public:
        CState();
        virtual ~CState();
        CState(const CState& other);
        CState& operator=(const CState& other);
        char* getName() const;
        bool getisInitial() const;
        int setIsInitial(bool) const;;
        bool getIsFinal();
        int setIsFinal(bool);
        friend std::istream& operator >>(std::istream&, CState&);
        virtual std::istream& inserter(std::istream&);
    protected:
    private:
        char *name;
        bool isInitial;
        bool isFinal;
};

#endif // CSTATE_H
