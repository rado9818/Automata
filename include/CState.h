#ifndef CSTATE_H
#define CSTATE_H
#include <iostream>

class CState
{
    public:
        CState(unsigned);
        virtual ~CState();
        CState(const CState& other);
        CState& operator=(const CState& other);
        unsigned getId() const;
        int setId(unsigned);
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
        unsigned id;
        char *name;
        bool isInitial;
        bool isFinal;
};

#endif // CSTATE_H
