#ifndef CSTATE_H
#define CSTATE_H


class CState
{
    public:
        CState();
        virtual ~CState();
        CState(const CState& other);
        CState& operator=(const CState& other);
        bool GetisInitial() { return isInitial; }
        void SetisInitial(bool val) { isInitial = val; }
        bool GetisFinal();
        void setIsFinal(bool val);
    protected:
    private:
        char *name;
        bool isInitial;
        bool isFinal;
};

#endif // CSTATE_H
