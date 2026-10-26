#pragma once

class LoRaWANMesh {
    public:
        void begin(char* MeshName, int MeshID, int DeviceID, int* DevicesList, int MeshPwd);
        void connect();
        void get(char* objname);
        void send(char* data, int dataSize, int targetDeviceID);
    private:
        char* MeshName;
        int MeshID;
        int DeviceID;
        int* DevicesList;
        int MeshPwd;
}