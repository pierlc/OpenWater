#pragma once

class Perifeal {
    public:
        Perifeal(int* faddr, char** fname, int** fpin, char* pname);
        void act(char* cname);
        void get(char* objname);
    private:
        int* FunctionAddresses;
        char** FunctionNames;
        int** FunctionPins;
        char* PerifealName;
        int GetFunctionAddress(char* FunctionName);
        int* GetFunctionPins(char* FunctionName);
        int GetFunctionIndex(char* FunctionName);
};