#pragma once

class LoRaWANMesh {
    public:
        void MeshInitialize(char* MeshName, int MeshID, int DeviceID, int* DevicesList, int MeshPwd);
        void MeshConnect();
        void MeshGet(char* objname);
        void MeshSend(char* data, int dataSize, int targetDeviceID);
        void MeshIdleReceive();
    private:
        char* MeshName;
        int MeshID;
        int DeviceID;
        int* DevicesList;
        int MeshPwd;
}