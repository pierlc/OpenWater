#include "mesh.hpp"
#include "lorawandef.h"

 void Mesh::MeshInitialize(char* MeshName, int MeshID, int DeviceID, int* DevicesList, int MeshPwd) {
    this->MeshName = MeshName;
    this->MeshID = MeshID;
    this->DeviceID = DeviceID;
    this->DevicesList = DevicesList;
    this->MeshPwd = MeshPwd;
}