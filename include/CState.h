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
        bool getIsInitial() const;
        int setIsInitial(bool);
        bool getIsFinal() const;
        int setIsFinal(bool);
        friend std::istream& operator >>(std::istream&, CState&);
        virtual std::istream& inserter(std::istream&);
        friend std::ostream& operator <<(std::ostream&, CState&);
        virtual std::ostream& extractor(std::ostream&);
    protected:
    private:
        char *name;
        bool isInitial;
        bool isFinal;
};

#endif // CSTATE_H
